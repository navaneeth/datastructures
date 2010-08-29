/* avl.h
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


#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

struct tree {
    struct tree *left;
    struct tree *right;
    int element;
    int bf;
};

/* inserts the element into the tree. If tree is null, */
/* a new tree will be created. */
struct tree *insert(struct tree *root, int element);

/* iterate the tree and call the function for each node. */
typedef void (*function)(struct tree *t, unsigned int depth);
void tree_iterate(struct tree *root, function fun);

/* free memory allocated for the tree */
void free_tree(struct tree *root);

/* lookup the element in the tree.  */
/* return 0 if element not found. */
/* return non-zero when element found */
int lookup(struct tree *root, int element);

#endif
