#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
  TreeMap *tree = (TreeMap*)calloc(1,sizeof(TreeMap));
  tree->current = NULL;
  tree->root = NULL;
  tree->lower_than = lower_than;
    return tree;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
  TreeNode *new = createTreeNode(key,value);
  if (tree->root == NULL){
    tree->root = new;
    tree->current = tree->root;
    return ;
  }
 
  TreeNode *auxRecorrido = tree->root;

  while (auxRecorrido != NULL){
    if(tree->lower_than(auxRecorrido->pair->key,key)){
      if(auxRecorrido->right == NULL){
        auxRecorrido = new;
        tree->current = auxRecorrido;
        return ;
      }
      auxRecorrido = auxRecorrido->right;
    }
    if(tree->lower_than(key,auxRecorrido->pair->key)){
      if(auxRecorrido->left == NULL){
        auxRecorrido = new;
        tree->current = auxRecorrido;
        return ;
      }
      auxRecorrido = auxRecorrido->left;
    }
    if(is_equal(tree,key,auxRecorrido->pair->key)){
      return ;
    }
    if(new->left == NULL && new->right == NULL){return ;}
  }
}

TreeNode * minimum(TreeNode * x){

    return NULL;
}


void removeNode(TreeMap * tree, TreeNode* node) {

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) 
puts("der\n");
  if (tree->root == NULL){return NULL;}
  TreeNode *new = tree->root;

  while (new != NULL){
    if(tree->lower_than(new->pair->key,key)){
      if(new->right == NULL){return NULL;}
      new = new->right;
    }
    if(tree->lower_than(key,new->pair->key)){
      if(new->left == NULL){return NULL;}  
      new = new->left;
    }
    if(is_equal(tree,key,new->pair->key)){
      tree->current = new;
      return new->pair;
    }
    if(new->left == NULL && new->right == NULL){return NULL;}
  }

  
    return NULL;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    return NULL;
}

Pair * nextTreeMap(TreeMap * tree) {
    return NULL;
}
