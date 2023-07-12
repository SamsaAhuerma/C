#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}
static bool is_abb(abb tree){
    if (tree == NULL){
        return true;
    }else if(tree->right == NULL && tree->left != NULL){
        return is_abb(tree->left);
    }else if(tree->right != NULL && tree->left == NULL){
        return is_abb(tree->right);
    }else{
        bool is_more = !elem_less(tree->right->elem,tree->elem);
        bool is_less = elem_less(tree->left->elem,tree->elem);
        bool rgt = is_abb(tree->right);
        bool lft = is_abb(tree->left);
        return(is_less && is_more && rgt && lft);
    }
}

static bool invrep(abb tree) {
    return is_abb(tree);
}

abb abb_empty(void) {
    abb tree = NULL;

    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));

    bool no_stop = true;
    
    abb nodo = malloc(sizeof(struct _s_abb));
    nodo->elem = e;
    nodo->left = NULL;
    nodo->right = NULL;

    if (tree == NULL) {
        tree = nodo;
    }
    else {
        abb p = tree;
        while(no_stop) {

            if(elem_less(e, p->elem) && p->left != NULL) {
                p = p->left;
            }
            if(elem_less(p->elem, e) && p->right != NULL) {
                p = p->right;
            }
            else {
                no_stop = false;
            }
        }

        if(elem_less(e, p->elem)) {
            p->left = nodo;
        }
        if(elem_less(p->elem, e)) {
            p->right = nodo;
        }

    }


    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}


bool abb_is_empty(abb tree) {
    assert(invrep(tree));
    return tree == NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (tree == NULL){
        return false;
    }else if(elem_less(e,tree->elem)){
        exists = abb_exists(tree->left,e);
    }else if(elem_less(e,tree->elem)){
        exists = abb_exists(tree->right,e);
    }else if(elem_eq(e, tree->elem)){
        return true;
    }
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    
    if (tree != NULL){
        length = 1 + abb_length(tree->left);
        length = 1 + abb_length(tree->right);
    }

    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
   
    if (abb_exists(tree,e)){
        bool no_stop = true;
        abb p = tree;

        while (no_stop){
             if(elem_less(e,p->elem)){
                p = p->left;
        }else if(elem_less(p->elem,e)){
            p = p->right;
        }else{
            no_stop = false;
        }
    }
    if ((p->left == NULL) && (p->right == NULL)){
    }
    if (p->left != NULL){
        p->elem = abb_max(p->left);
    }else{
        p->elem = abb_min(p->right);
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}

abb_elem abb_root(abb tree){
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    root = tree->elem;

    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    abb p = tree;
    while (p->right){
         p = p->right;
    }
    max_e = p->elem;
    
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    
    abb p = tree;
    while (p->left != NULL){
          p = p->left;
    }
    min_e = p->elem;

    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    
    if (tree != NULL){
        tree->right = abb_destroy(tree->right);
        tree->left = abb_destroy(tree->left);
    
        tree->right = NULL;
        tree->left = NULL;

        free(tree);
        tree = NULL;
    }
    assert(tree == NULL);
    return tree;
}

