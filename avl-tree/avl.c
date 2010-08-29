
/* avl.c
 *
 * Copyright (C) Navaneeth.K.N
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA */


#include <assert.h>
#include <stdlib.h>
#include "avl.h"

#define MAX(t1,t2) (t1 > t2 ? t1 : t2)
#define MIN(t1,t2) (t1 < t2 ? t1 : t2)

static unsigned int nodecnt = 0;

static struct tree *left_rotation(struct tree *item)
{
    struct tree *root = NULL;

    assert(item != NULL);
    assert(item->right != NULL);

    root = item->right;
    item->right = root->left;
    root->left = item;

    item->bf -= (1 + MAX(root->bf, 0));
    root->bf -= (1 - MIN(item->bf, 0));
       
    return root;  /* this will be the new root */
}

static struct tree *right_rotation(struct tree *item)
{
    struct tree *root = NULL;

    assert(item != NULL);
    assert(item->left != NULL);

    root = item->left;
    item->left = root->right;
    root->right = item;

    item->bf += (1 - MIN(root->bf, 0));
    root->bf += (1 + MAX(item->bf, 0));

    return root;  /* new root */
}

/* does a left right double rotation */
static struct tree *lr_rotation(struct tree *item)
{
    item->right = right_rotation(item->right);
    return left_rotation(item);
}

/* right left double rotation */
static struct tree *rl_rotation(struct tree *item)
{
    item->left = left_rotation(item->left);
    return right_rotation(item);
}

static int right_heavy(struct tree *t)
{
    if(t == NULL) return 0;    
    return (t->bf == 2);
}

static int left_heavy(struct tree *t)
{
    if(t == NULL) return 0;
    return (t->bf == -2);
}

static struct tree *rotate_if_necessary (struct tree *root)
{
    assert(root != NULL);

    if(right_heavy(root))
    {
        if(root->right->bf == -1)
        {
            root = lr_rotation(root);
        }
        else
        {
            root = left_rotation(root);
        }
    }
    else if(left_heavy(root))
    {
        if(root->left->bf == 1)
        {
            root = rl_rotation(root);
        }
        else
        {
            root = right_rotation(root);
        }
    }
    return root;
}

struct tree *insert(struct tree *root, int element)
{
    if(root == NULL) 
    {
        /* root null. need to create one */
        root = (struct tree*) malloc(sizeof(struct tree));
        ++nodecnt;
        root->bf = 0;
        root->element = element;
        root->left = NULL; root->right = NULL;
        return root;
    }
    else if(element < root->element)
    {
        /* doing left insertion */
        root->left = insert(root->left, element);
        --root->bf;
    }
    else if (element > root->element)
    {
        /* doing right insertion */
        root->right = insert(root->right, element);
        ++root->bf;
    }    
    root = rotate_if_necessary(root);
    return root;
}

static void iterate_recursive(struct tree *root, function fun, unsigned int depth)
{
    if(root == NULL) return;

    fun(root, depth);
    ++depth;
    iterate_recursive(root->left, fun, depth);
    iterate_recursive(root->right, fun, depth);
}

void tree_iterate(struct tree *root, function fun)
{
    if(fun == NULL) return;
    iterate_recursive(root, fun, 0);
}

void free_tree(struct tree *root)
{
    if(root == NULL) return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
    --nodecnt;
}

unsigned long memory_allocated()
{
    return nodecnt * sizeof(struct tree);
}

/* lookup the element in the tree.  */
/* return 0 if element not found. */
/* return number of iterations when element found */
unsigned int lookup(struct tree *root, int element)
{
    unsigned int it = 1, result = 0;

    if(root != NULL)
    {
        if(element == root->element)
            return it;
        else if(element < root->element) 
            result = lookup(root->left, element);    
        else if(element > root->element) 
            result = lookup(root->right, element);
        else
            return 0;
    }

    return result == 0 ? result : (it + result);
}

