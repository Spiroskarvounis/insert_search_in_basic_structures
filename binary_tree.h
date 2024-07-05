#ifndef binary_tree_h
#define binary_tree_h
using namespace std;

struct node           // struct that represents a tree's node
{
  string word;        // contains the word that is stored in this node    
  int count=1;        // initializes the counter of the word's appearances to 1
  node *left;         // a pointer to the left child-node      
  node *right;        // a pointer to the right child-node
  node *parent;       // a pointer to the parent of the node
};

class btree
{
  protected:
    void insert(string , node *);
    node *search(string , node *);
    void destroy_tree(node *);
    void PreOrder(node *);
    void InOrder(node *);
    void PostOrder(node *);
    node* findMin(node*);	// finds the smaller string of a subtree and returns its pointer
    bool remove(node *);
    node *root;			// node that represents the root of the tree
  public:
    node *getroot();            // returns the memory address of the tree's root
    btree();                    // constructor
    void insert(string );       // inserts the "key" word in the tree
    bool search(string, int&);  // searches for the specific key in the tree
    void destroy_tree();        // deletes all the data that was used by the tree
    void PreOrder ();           // preorder traversal of the tree
    void InOrder ();            // inorder traversal of the tree
    void PostOrder ();          // postorder traversal of the tree
    bool remove(string);        // deletes a specific word from the tree
};

#endif