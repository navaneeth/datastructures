/* example.c
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

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

static void printtree(struct tree *t, unsigned int depth)
{
    unsigned int i = 0;
    for(i = 0; i < depth; i++) {
        printf("-");
    }
    printf("%c\n", t->element);
}

void example1(void)
{
    struct tree *root = NULL;
    unsigned int it;
    
    printf("Creating simple tree with 7 elements\n");    
    root = insert(root, 'C');
    root = insert(root, 'E');
    root = insert(root, 'J');
    root = insert(root, 'M');
    root = insert(root, 'O');
    root = insert(root, 'S');
    root = insert(root, 'W');
    tree_iterate(root, printtree);
    printf("Created 7 elements with %lu bytes memory usage\n", memory_allocated());
    printf("Finding element : W\n");
    it = lookup(root, 'W');
    if(it) {
        printf("Found 'W' in %d iterations\n", it);
    }
    free_tree(root);
}

void example2(void)
{
    int limit = 500, i;
    unsigned int it;
    struct tree *root = NULL;

    printf("Creating tree with %d elements\n", limit);
    for(i = 0; i < limit; i++) {
        root = insert(root, i);
    }
    printf("Created %d elements with %lu bytes memory usage\n", i, memory_allocated());

    printf("Finding element : 420 - ");
    it = lookup(root, 420);
    if(it) {
        printf("Found in %d iterations!\n", it);
    }
    else {
        printf("Not found\n");
    }
    free_tree(root);
}

int main()
{
    example1();
    printf("-----------------------\n");
    example2();
    return 0;
}

