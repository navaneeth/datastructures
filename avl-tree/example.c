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

int main()
{
    struct tree *root = NULL;
    root = insert(root, 'C');
    root = insert(root, 'E');
    root = insert(root, 'J');
    root = insert(root, 'M');
    root = insert(root, 'O');
    root = insert(root, 'S');
    root = insert(root, 'W');

    tree_iterate(root, printtree);

    printf("Finding element : S - ");
    if(lookup(root, 'S')) {
        printf("Found!\n");
    }
    else {
        printf("Not found\n");
    }

    printf("Finding element : Z - ");
    if(lookup(root, 'Z')) {
        printf("Found!\n");
    }
    else {
        printf("Not found\n");
    }

    free_tree(root);
    return 0;
}

