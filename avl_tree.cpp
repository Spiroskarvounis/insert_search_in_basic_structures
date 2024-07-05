#include <iostream>
#include <cstring>
#include <string>
#include "avl_tree.h"

using namespace std;

node * avl::getroot()
{
  return root;
}

avl::avl():btree(){}

void avl::insert(string key)
{
  btree::insert(key);
  root=balance(root);
}

bool avl::search(string key, int &ret)
{
  return btree::search(key,ret);
}

void avl::destroy_tree()
{
  btree::destroy_tree();
}

void avl::PreOrder ()
{
  btree::PreOrder();
}

void avl::InOrder ()
{
  btree::InOrder();
}

void avl::PostOrder ()
{
  btree::PostOrder();
}

int avl::height(node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = l_height;
    if (r_height>max_height)
      max_height=r_height;
		h = max_height + 1;
	}
	return h;
}

int avl::diff(node *temp)
{
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	int d = l_height - r_height;
	return d;
}

node *avl::balance(node *temp)
{
	int d = diff(temp);
	if (d > 1)
	{
		if (diff(temp->left) > 0)
			temp = ll_rotation(temp);
		else
			temp = lr_rotation(temp);
	}
	else if (d < -1)
	{
		if (diff(temp->right) > 0)
			temp = rl_rotation(temp);
		else
			temp = rr_rotation(temp);
	}
	return temp;
}

node *avl::rr_rotation(node *parent)
{
	node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

node *avl::ll_rotation(node *parent)
{
	node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

node *avl::lr_rotation(node *parent)
{
	node *temp;
	temp = parent->left;
	parent->left = rr_rotation(temp);
	return ll_rotation(parent);
}

node *avl::rl_rotation(node *parent)
{
	node *temp;
	temp = parent->right;
	parent->right = ll_rotation(temp);
	return rr_rotation(parent);
}

bool avl::remove(string key)
{
    node *child;

    child = btree::search(key,root);
    if (child!=nullptr)
        return remove (child);
    return false;
}

bool avl::remove(node *child)
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

    balance(child);
    return true;
}
