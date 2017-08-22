/**
* @file rbtree.cpp definitions of RBTree class functions
*
* @author Daniel Rush <drush1@mail.csuchico.edu>
*
* @date 04/29/2017
*/
#include <iostream>
#include <iomanip>
#include<vector>
#include<sstream>
#include "rbtree.h"

using std::vector;
using std::string;

using std::cout;
using std::setw;
using std::endl;
/**
* Node Constructor, private subclass of RBTree.
*/
RBTree::Node::Node()
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = 'b';
    key = nullptr;
    value = nullptr;
}

/**
* Overloaded Node Constructor, private subclass of RBTree.
*
* @param A string for the key and the value of the node to be created.
*/
RBTree::Node::Node(const string& key, const string& value)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    color = 'r';
    this->value=new string(value);
    this->key=new string(key);
}

/**
* Node deconstructor, private subclass of RBTree
*/
RBTree::Node::~Node()
{
    delete key;
    delete value;
    color = '0';
}
/**
* Red-Black Tree constructor creates nil and root of tree.
*/
RBTree::RBTree()
{
    nil = new Node();
    nil->parent = nil;
    nil->right = nil;
    nil->left = nil;
    root = nil;
}
/**
* Red-Black Tree deconstructor, recursively deletes all nodes, nil, and root.
*/
RBTree::~RBTree()
{
    rbDeleteTree(root);
    delete nil;
}
/**
* Prints the keys, values, and colors of red-black tree nodes.
*
* @param Node pointer for recursive calls, in helper function it starts at root
*       and depth of tree, starts at 0.
*/
void RBTree::reverseInOrderPrint(Node *x, int depth) 
{
    if ( x != nil ) {
        reverseInOrderPrint(x->right, depth+1);
        cout << setw(depth*4+4) << x->color << " ";
        cout << *(x->key) << " " << *(x->value) << endl;
        reverseInOrderPrint(x->left, depth+1);
    }
}
/**
* Public find function of Red-Black tree class, finds and prints key and value.
*
* @param Key string which is to be found.
*
* @return Vector of strings which contain the keys and the values of keys
*       which were found in the tree.
*/
vector<const string*> RBTree::rbFind(const string& key)
{
    vector<const string*>retStrings;
    vector<Node*>retNodes;
    retNodes = rbFindNodes(key);
    for(int i = 0; i<(int)retNodes.size(); i++)
    {
        std::stringstream ss;
        ss<<*retNodes[i]->key << ' ' << *retNodes[i]->value;
        string* inVal = new string(ss.str());
        retStrings.push_back(inVal);
    }
    return retStrings;
}
/**
* Private function that finds the nodes with give key finds all duplicates.
*
* @param key to be found.
*
* @return Vector of Node object pointers which point to where key was found.
*/
vector<RBTree::Node*> RBTree::rbFindNodes(const string& key)
{
    vector<Node*> retNodes;
    Node* x = rbTreeSearch(root, key);
    Node* y;
    Node* z;
    if(x != nil)
    {
        retNodes.push_back(x);
        y= rbTreeSuccessor(x);
        while(y != nil)
        {
            if(*y->key == key)
            {
                retNodes.push_back(y);
            }
            y = rbTreeSuccessor(y);
        }
        z= rbTreePredecessor(x);
        while(z != nil)
        {
            if(*z->key == key)
            {
                retNodes.push_back(z);
            }
            z = rbTreePredecessor(z);
        }
    }
    return retNodes;
}
/**
* Search function which is used to find the first occurance of given key.
*
* @param The node at which the search starts, and the key which is to be
*       searched for.
* 
* @return Node object pointer to where key was found.
*/
RBTree::Node* RBTree::rbTreeSearch(Node* x, const string& key)
{
    if(x == nil)
    {
        return x;
    }
    if(*x->key == key)
    {
        return x;
    }
    else if(*x->key < key)
    {
        x = rbTreeSearch(x->right, key);
    }
    else
    {
        x = rbTreeSearch(x->left, key);
    }
    return x;
}
/**
* Public print helper function.
*/
void RBTree::rbPrintTree()
{
    reverseInOrderPrint(root,0);
}
/**
* Private minimum mutator function finds minimum node of given subtree.
* 
* @param Node whose subtree is to be searched.
*
* @return Pointer to minimum Node of given subtree.
*/
RBTree::Node* RBTree::rbTreeMinimum(Node* x)
{
    while(x->left != nil)
    {
        x = x->left;
    }
    return x;
}
/**
* Private maximum mutator function finds maximum node of given subtree.
* 
* @param Node whose subtree is to be searched.
*
* @return Pointer to maximum Node of given subtree.
*/
RBTree::Node* RBTree::rbTreeMaximum(Node* x)
{
    while(x->right != nil)
    {
        x = x->right;
    }
    return x;
}
/**
* Private sucessor mutator function finds successor node of the given node.
* 
* @param Node whose successor is to be found.
*
* @return Pointer to successor Node of given Node.
*/
RBTree::Node* RBTree::rbTreeSuccessor(Node* x)
{
    if(root == nil)
        return root;
    if(x->right != nil)
    {
        return  rbTreeMinimum(x->right);
    }
    Node* y = x->parent;
    while((y != nil) && (x == y->right))
    {
        x = y;
        y = y->parent;
    }
    return y;
}
/**
* Private sucessor mutator function finds predecessor node of the given node.
* 
* @param Node whose predecessor is to be found.
*
* @return Pointer to predecessor Node of given Node.
*/
RBTree::Node* RBTree::rbTreePredecessor(Node* x)
{
    if(root == nil)
        return root;
    if(x->left != nil)
    {
        return rbTreeMaximum(x->left);
    }
    Node* y = x->parent;
    while((y != nil) && (x == y->left))
    {
        x = y;
        y = y->parent;
    }
    return y;
}
/**
* Private mutator function which performs left rotate around given Node.
*
* @param Pointer to Node object around which rotate is done.
*/
void RBTree::leftRotate(Node* x)
{
    Node* y = x->right;
    x->right = y->left;
    if(y->left != nil)
    {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil)
    {
        root = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}
/**
* Private mutator function which performs right rotate around given Node.
*
* @param Pointer to Node object around which rotate is done.
*/
void RBTree::rightRotate(Node* x)
{
    Node* y = x->left;
    x->left = y->right;
    if(y->right != nil)
    {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == nil)
    {
        root = y;
    }
    else if(x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;

}
/**
* Public insert function which inserts a given key and value in Node form.
*
* @param Key and value strings to be inserted into node, and into tree.
*/
void RBTree::rbInsert(const string& key, const string& value)
{
    Node* addedNode = new Node(key, value);
    rbInsert(addedNode);
}
/**
* Insert function which places new node into Red-Black Tree..
*
* @param Pointer to Node which is to be inserted.
*/
void RBTree::rbInsert(Node* z)
{
    Node* y = nil;
    Node* x = root;
    while(x != nil)
    {
        y = x;
        if(((*z->key) < (*x->key)))
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }
    z->parent = y;
    if(y == nil)
    {
        root = z;
    }
    else if(*z->key < *y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    z->left = nil;
    z->right = nil;
    z->color = 'r';
    rbInsertFixup(z);
}
/**
* Ensures that properties of Red-Black tree are maintained after Node insertion.
*
* @param Pointer to Node which has been inserted.
*/
void RBTree::rbInsertFixup(Node* z)
{
    Node* y = nil;
    while(z->parent->color == 'r')
    {
        if(z->parent == z->parent->parent->left)
        {
            y = z->parent->parent->right;
            if(y->color == 'r')
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
            }
            else 
            {
                if(z == z->parent->right)
                {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                rightRotate(z->parent->parent);
            }
        }
        else
        {
            y = z->parent->parent->left;
            if(y->color == 'r')
            {
                z->parent->color = 'b';
                y->color = 'b';
                z->parent->parent->color = 'r';
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->left)
                {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = 'b';
                z->parent->parent->color = 'r';
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = 'b';
}
/**
* Transplants tree rooted at v to be rooted at u, u becomes disjoint from tree.
* 
* @param Pointers to Nodes u, and v which are subjects of transplant.
*/
void RBTree::rbTransplant(Node* u, Node* v)
{
    if(u->parent == nil)
    {
        root = v;
    }
    else if(u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    v->parent = u->parent;
}
/**
* Public delete function which takes in a key and a value to be deleted.
*
* @param Key and value strings which correspond to Node which is to be deleted.
*/
void RBTree::rbDelete(const string& key, const string& value)
{
    vector<Node*>foundNodes;
    foundNodes = rbFindNodes(key);
    for(int i = 0; i<(int)foundNodes.size(); i++)
    {
        if(*foundNodes[i]->value == value)
        {
            rbDelete(foundNodes[i]);
        }
    }
}
/**
* Private delete function which handles actual deletion of Node in tree.
*
* @param Pointer to Node which is to be deleted.
*/
void RBTree::rbDelete(Node* z)
{
    Node* x;
    Node* y;
    y = z;
    char originalColor = y->color;
    if(z->left == nil)
    {
        x = z->right;
        rbTransplant(z,z->right);
    }
    else if(z->right == nil)
    {
        x = z->left;
        rbTransplant(z, z->left);
    }
    else
    {
        y = rbTreeMaximum(z->left);
        originalColor = y->color;
        x = y->left;
        if(y->parent== z)
        {
            x->parent = y;
        }
        else
        {
            rbTransplant(y,y->left);
            y->left = z->left;
            y->left->parent = y;
        }
        rbTransplant(z,y);
        y->right=z->right;
        y->right->parent = y;
        y->color = z->color;
    }
    if(originalColor == 'b')
    {
        rbDeleteFixup(x);
    }
    delete z;
}
/**
* Ensures that properties of Red-Black tree are maintained after Node deletion.
*
* @param Pointer to Node where fixup starts near bottom of tree.
*/
void RBTree::rbDeleteFixup(Node* x)
{
    Node* w;
    while(x != root && x->color == 'b')
    {
        if(x == x->parent->left)
        {
            w = x->parent->right;
            if(w->color == 'r')
            {
                w->color = 'b';
                x->parent->color = 'r';
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if((w->left->color == 'b') && (w->right->color == 'b'))
            {
                w->color = 'r';
                x = x->parent;
            }
            else 
            {
                if(w->right->color == 'b')
                {
                    w->left->color = 'b';
                    w->color = 'r';
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = 'b';
                w->right->color = 'b';
                leftRotate(x->parent);
                x = root;
            }
        }
        else
        {
            w = x->parent->left;
            if(w->color == 'r')
            {
                w->color = 'b';
                x->parent->color = 'r';
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if((w->right->color == 'b') && (w->left->color == 'b'))
            {
                w->color = 'r';
                x = x->parent;
            }
            else 
            {
                if(w->left->color == 'b')
                {
                    w->right->color = 'b';
                    w->color = 'r';
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'b';
                w->left->color = 'b';
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = 'b';
}
/**
* Private recursive delete function which deletes all nodes of tree.
*
* @param Pointer to Node where tree deletion begins, should be called on root.
*/
void RBTree::rbDeleteTree(Node*x)
{
    if(x == nil)
    {
        return;
    }
    rbDeleteTree(x->left);
    rbDeleteTree(x->right);
    delete x;
}
