#include <iostream>
#include <cstring>
#include <string>
#include "binary_tree.h"

using namespace std;

node *btree::getroot()
{
  return root;
}

btree::btree()
{

  root=NULL;
}

void btree::insert(string key, node *leaf)
{
  if(key.compare(leaf->word) == 0)
  {
    leaf->count++;
  }
  else if(key.compare(leaf->word) < 0)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
      leaf->left=new node;
      leaf->left->word=key;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
      leaf->left->parent=leaf;
    }
  }
  else
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {
      leaf->right=new node;
      leaf->right->word=key;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
      leaf->right->parent=leaf;
    }
  }
}

void btree::insert(string key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
    root=new node;
    root->word=key;
    root->left=NULL;
    root->right=NULL;
    root->parent=NULL;
  }
}

node *btree::search(string key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key.compare(leaf->word)==0)
      return leaf;
    if(key.compare(leaf->word)<0)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}

bool btree::search(string key, int &ret)
{
  node* p=search(key, root);
  if (p == nullptr)
    return false;
  ret = p->count;
  return true;
}

void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::destroy_tree()
{
  destroy_tree(root);
}

void btree::PreOrder()
{
  PreOrder(root);
}

void btree::PreOrder (node *t)
{
 if (t)
 {
    cout<<"\""<<t->word<<"\" is appeared "<<t->count<<" times"<<endl;
    PreOrder(t->left);
    PreOrder(t->right);
 }
}

void btree::InOrder ()
{
  InOrder(root);
}

void btree::InOrder (node *t)
{
  if (t)
  {
    InOrder(t->left);
    cout<<"\""<<t->word<<"\" is appeared "<<t->count<<" times"<<endl;
    InOrder(t->right);
  }
}

void btree::PostOrder ()
{
  PostOrder(root);
}

void btree::PostOrder (node *t)
{
 if (t)
 {
    PostOrder(t->left);
    PostOrder(t->right);
    cout<<"\""<<t->word<<"\" is appeared "<<t->count<<" times"<<endl;
 }
}


node* btree::findMin(node* t)
{
	if (t == NULL) return NULL;
	else if (t->left == NULL) return t; // if element traverse on max left then return
	else return findMin(t->left); // or recursively traverse max left
}

bool btree::remove(string key)
{
    node *child;

    child = search(key,root);
    if (child!=nullptr)
        return remove (child);
    return false;
}

bool btree::remove(node *child)
{
    node *par;

    if (child ==nullptr)
        return false;

    par = child->parent;

    if (child->left == nullptr && child->right==nullptr) //no children
    {
        if (par==nullptr) // deleting root
        {
            delete(child);
            root=nullptr;
        }
        else if (par->left == child)
        {
            delete (par->left);
            par->left=nullptr;
        }
        else
        {
            delete (par->right);
            par->right=nullptr;
        }
    }
    else if (child->left == nullptr ||child->right == nullptr ) //one child
    {
        if (par==nullptr) // deleting root
        {
            if (child->left == nullptr)
                root = child->right;
            else
                root = child->left;
            delete (child);
        }
        else if (par->left==child)
        {
            if (child->left == nullptr)
                par->left=child->right;
            else
                par->left=child->left;
            delete (child);
        }
        else
        {
            if (child->left == nullptr)
                par->right=child->right;
            else
                par->right=child->left;
            delete (child);

        }
    }
    else // two children
    {
        node *mm  = findMin(child->right);
        child->word=mm->word;

        remove(mm);
    }

    return true;
}


