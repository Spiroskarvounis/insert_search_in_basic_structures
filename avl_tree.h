#ifndef avl_tree_h
#define avl_tree_h
#include "binary_tree.h"
using namespace std;


class avl : public btree
{
  private:
    bool remove(node *);
    int height(node *);         // returns the height of the tree
    int diff(node *);           // returns the difference between left and right sub-tree
    node *balance(node *);      // brings the tree in avl form
    node *rr_rotation(node *);  // left-left rotation
    node *ll_rotation(node *);  // right-right rotation
    node *lr_rotation(node *);  // left-right rotation
    node *rl_rotation(node *);  // right-left rotation
  public:
    node *getroot();              // returns the memory address of the tree's root
    avl();                        // constructor
    void insert(string);          // inserts the "key" word in the tree
    bool search(string, int&);    // searches for the specific key in the tree
    bool remove(string);          // deletes a specific word from the tree
    void destroy_tree();          // deletes all the data that was used by the tree
    void PreOrder();              // preorder traversal of the tree
    void InOrder();               // inorder traversal of the tree
    void PostOrder();             // postorder traversal of the tree
};


#endif