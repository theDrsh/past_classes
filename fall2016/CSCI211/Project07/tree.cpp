/*
 *       Project06
 *       bst.cpp
 *       Daniel Rush
 */
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#include "tree.h"
/*
 *   copy
 *       copys contents of one Tree to another.
 *
 *   Param
 *       Tnode pointer cur, is used to set the links of the Tree after base case of recursive call
 *
 *   return
 *       returns a Tnode pointer to the function which called it recursively allowing links to be fixed.
 */
Tnode<char>* Tree::copy(Tnode<char> *cur)
{
    Tnode<char> *ptr;
    if(cur == NULL)
        return NULL;
    ptr = new Tnode<char>(cur->value); 
    ptr->left = copy(cur->left);
    ptr->right = copy(cur->right);
    return ptr;
}
/*
 *   clean
 *       emptys contents of Tree
 *   param
 *       Tnode pointer which allows traversal of tree to allow deletion in post order.
 *
 *    return
 *       void
 */
void Tree::clean(Tnode<char> *cur)
{
    if(cur == NULL)
        return;
    clean(cur->left);
    clean(cur->right);
    delete cur;
}
/*
*   merge
*       merges two trees, new tree can be referenced by the left-hand-side tree's name
*   param
*       tree passed by reference
*   return
*       void
*/
void Tree::merge(Tree &rhs)
{
    Tnode<char> *mergePtr = new Tnode<char>();
    mergePtr->right = rhs.root;
    mergePtr->left = root;
    root = mergePtr;
    rhs.root = NULL;
}
/*
*   print_encoding
*       prints the string that represents the encoding of each letter in huffman code
*   param
*       Tnode pointer to traverse tree, and huffman code to be printed
*   return
*       void
*/
void Tree::print_encoding(Tnode<char> *cur, string dir)
{
    if(cur == NULL)
        return;
    if((cur->right == NULL) && (cur->left == NULL))
        cout << cur->value << ' ' << dir << endl;
    print_encoding(cur->left, dir+'0');
    print_encoding(cur->right, dir+'1');
}
/*
*   encoded_depth
*       returns encoded depth of a character to the public function
*   param
*       Tnode pointer to traverse tree, char to search tree for, integer for keeping track of depth
*   return
*       integer depth of requested character
*/
int Tree::encoded_depth(Tnode<char> *cur, char curChar, int depth)
{
    if(cur == NULL)
    {
        return 0;
    }
    else if(cur->value == curChar)
    {
        return depth;
    }
    int leftDepth = encoded_depth(cur->left, curChar, depth+1);
    int rightDepth = encoded_depth(cur->right, curChar, depth+1);
    if(rightDepth >= leftDepth)
    {
        return rightDepth;
    }
    else 
    {
        return leftDepth;
    }
}
