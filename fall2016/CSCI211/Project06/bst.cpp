/*
*       Project06
*       bst.cpp
*       Daniel Rush
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#include "bst.h"
/*
*   copy
*       copys contents of one BST to another.
*
*   Param
*       Tnode pointer cur, is used to set the links of the BST after base case of recursive call
*
*   return
*       returns a Tnode pointer to the function which called it recursively allowing links to be fixed.
*/
    template <typename T>
Tnode<T>* BST<T>::copy(Tnode<T> *cur)
{
    Tnode<T> *ptr;
    if(cur == NULL)
        return NULL;
    ptr = new Tnode<T>(cur->value); 
    ptr->left = copy(cur->left);
    ptr->right = copy(cur->right);
    return ptr;
}
    template <typename T>
Tnode<T*>* BST<T*>::copy(Tnode<T*> *cur)
{
    T *ptr_to_value;
    Tnode<T*> *ptr;
    if(cur == NULL)
        return NULL;
    ptr_to_value =  new T(*(cur->value));
    ptr = new Tnode<T*>(ptr_to_value); 
    ptr->left = copy(cur->left);
    ptr->right = copy(cur->right);
    return ptr;
}
/*
*   clean
*       emptys contents of BST
*   param
*       Tnode pointer which allows traversal of tree to allow deletion in post order.
*
*    return
*       void
*/
    template <typename T>
void BST<T>::clean(Tnode<T> *cur)
{
    if(cur == NULL)
        return;
    clean(cur->left);
    clean(cur->right);
    delete cur;
}
    template <typename T>
void BST<T*>::clean(Tnode<T*> *cur)
{
    if(cur == NULL)
        return;
    clean(cur->left);
    clean(cur->right);
    delete cur->value;
    delete cur;
}
/*
*   insert
*       inserts a variable of type T into the BST
*   param
*       varible to be inserted is passed in.
*   return
*       returns a boolean to determine success
*/
    template <typename T>
bool BST<T>::insert(T val)
{   
    Tnode<T> *ptr = root;
    if(root == NULL)
    {
        root = new Tnode<T>(val);
        return true;
    }
    while(ptr != NULL)
    {
        if(val < ptr->value)
        {
            if(ptr->left == NULL)
            {
                ptr->left = new Tnode<T>(val);
                return true;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        else if(val > ptr->value)
        {
            if(ptr->right == NULL)
            {
                ptr->right = new Tnode<T>(val);
                return true;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        else if(val == ptr->value)
        {
            return false;
        }
    }
    return true;
}
    template <typename T>
bool BST<T*>::insert(T val)
{   
    T *ptr_to_val = new T(val);
    Tnode<T*> *ptr = root;
    if(root == NULL)
    {
        root = new Tnode<T*>(ptr_to_val);
        return true;
    }
    while(ptr != NULL)
    {
        if(val < *(ptr->value))
        {
            if(ptr->left == NULL)
            {
                ptr->left = new Tnode<T*>(ptr_to_val);
                return true;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        else if(val > *(ptr->value))
        {
            if(ptr->right == NULL)
            {
                ptr->right = new Tnode<T*>(ptr_to_val);
                return true;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        else if(val == *(ptr->value))
        {
            return false;
        }
    }
    return true;
}
/*
*   print_inorder   
*       prints tree by traversing in order
*   param
*       Tnode pointer for tree traversal
*   return
*       void
*/
    template <typename T>
void BST<T>::print_inorder(Tnode<T> *cur)
{
    if(cur == NULL)
        return;
    print_inorder(cur->left);
    cout << cur->value << " ";
    print_inorder(cur->right);
}
    template <typename T>
void BST<T*>::print_inorder(Tnode<T*> *cur)
{
    if(cur == NULL)
        return;
    print_inorder(cur->left);
    cout << *(cur->value) << " ";
    print_inorder(cur->right);
}
/*
*  remove
*       removes specified value from tree
*   param
*       variable of type T to be removed
*   return
*       boolean to determine success
*/
    template <typename T>
bool BST<T>::remove(T val)
{
    bool isRemoved = false;
    remove(val, root, isRemoved);
    return isRemoved;
}

    template <typename T>
bool BST<T*>::remove(T val)
{
    bool isRemoved = false;
    remove(val, root, isRemoved);
    return isRemoved;
}
/*
*   remove(recursive)
*       removes specified value from tree.
*   param
*      value to be removed, Tnode pointer for traversal, and boolean to indicate success 
*   return
*       Tnode pointer to correct branches of BST
*/
    template <typename T>
Tnode<T>* BST<T>::remove(T val, Tnode<T> *cur, bool &r)
{
    Tnode<T> *temp;
    if(cur != NULL)
    {   
        if(cur->value == val)
        {
            if(cur->right == NULL)
            {
                if(cur->left == NULL)
                {
                    delete cur;
                    r = true;
                    return NULL;
                }//no children
                else
                {
                    temp = cur->left;
                    delete cur;
                    r = true;
                    return temp;
                }//one left side child
            }
            if(cur->left == NULL)
            {
                if(cur->right != NULL)
                {
                    temp = cur->right;
                    delete cur;
                    r = true;
                    return temp;
                }
            }//one right side child
            else
            {
                temp = get_leftmost(cur->right);
                cur->value = temp->value;
                cur->right = remove_leftmost(cur->right);
                r = true;
                return cur;
            }//two children
        }
        else if(val < cur->value)
        {   
            cur->left = remove(val, cur->left, r);
            return cur;
        }
        else
        {
            cur->right = remove(val, cur->right, r);   
            return cur;
        }
    }
    return NULL;
}

    template <typename T>
Tnode<T*>* BST<T*>::remove(T val, Tnode<T*> *cur, bool &r)
{
    Tnode<T*> *temp;
    if(cur != NULL)
    {   
        if(*(cur->value) == val)
        {
            if(cur->right == NULL)
            {
                if(cur->left == NULL)
                {
                    delete cur->value;
                    delete cur;
                    r = true;
                    return NULL;
                }//no children
                else
                {
                    temp = cur->left;
                    delete cur->value;
                    delete cur;
                    r = true;
                    return temp;
                }//one left side node
            }
            if(cur->left == NULL)
            {
                if(cur->right != NULL)
                {
                    temp = cur->right;
                    delete cur->value;
                    delete cur;
                    r = true;
                    return temp;
                }
            }//one right side node
            else
            {
                temp = get_leftmost(cur->right);
                *(cur->value) = *(temp->value);
                cur->right = remove_leftmost(cur->right);
                r = true;
                return cur;
            }
        }
        else if(val < *(cur->value))
        {
            cur->left = remove(val, cur->left, r);
            return cur;
        }
        else
        {
            cur->right = remove(val, cur->right, r);   
            return cur;
        }
    }
    return NULL;
}
/*
*   get_leftmost
*       returns leftmost node of subtree rooted at cur
*   param
*       Tnode pointer which is root of subtree to be searched
*   return
*       returns Tnode pointer to leftmost node
*/

    template <typename T>
Tnode<T>* BST<T>::get_leftmost(Tnode<T> *cur)
{
    if(cur != NULL)
    {
        if(cur->left != NULL)
        {
            return get_leftmost(cur->left);
        }
        else
            return cur;
    }
    return NULL;
}

    template <typename T>
Tnode<T*>* BST<T*>::get_leftmost(Tnode<T*> *cur)
{
    if(cur != NULL)
    {
        if(cur->left != NULL)
        {
            return get_leftmost(cur->left);
        }
        else
            return cur;
    }
    return NULL;
}
/*
*   remove_leftmost
*       removes leftmost node of tree rooted at r
*   param
*       Tnode pointer to root of subtree whose leftmost node will be removed
*   return
*       returns pointer to the subree
*/
    template <typename T>
Tnode<T>* BST<T>::remove_leftmost(Tnode<T> *r)
{
    if(r != NULL)
    {
        if(r->left != NULL)
        {
            r->left = remove_leftmost(r->left);
            return r;
        }
        else
        {
            if(r->right != NULL)
            {
                Tnode<T> *temp = r->right;
                delete r;
                return temp;
            }
            else
            {
                delete r;
                return NULL;
            }
        }
    }
    return NULL;
}
/*
*
*/

    template <typename T>
Tnode<T*>* BST<T*>::remove_leftmost(Tnode<T*> *r)
{
    if(r != NULL)
    {
        if(r->left != NULL)
        {
            r->left = remove_leftmost(r->left);
            return r;
        }
        else
        {
            if(r->right != NULL)
            {
                Tnode<T*> *temp = r->right;
                delete r->value;
                delete r;
                return temp;
            }
            else
            {
                delete r->value;
                delete r;
                return NULL;
            }
        }
    }
    return NULL;
}
/*
*   find
*       finds value if it is present in tree returns a boolean to indicate success
*   param
*       value to be found
*   return
*       returns boolean that indicates success
*/

    template <typename T>
bool BST<T>::find(T val)
{
    bool found = false;
    find(val, root, found);
    return found;
}

    template <typename T>
bool BST<T*>::find(T val)
{
    bool found = false;
    find(val, root, found);
    return found;
}
/*
*   find(recursive)
*       recursively finds value in tree returns pointer to tree, private member function
*   param
*       value to be found, node for recursive traversal, boolean to deteremine if found
*   return
*       pointer to node whose value is specified
*/
    template <typename T>
Tnode<T>* BST<T>::find(T val, Tnode<T> *cur, bool &found)
{
    if(cur == NULL)
    {
        return NULL;
    }
    if(cur->value == val)
    {
        found = true;
        return cur;
    }
    else if(val< cur->value)
    {
        return find(val, cur->left, found);
    }
    else
    {
        return find(val, cur->right, found);
    }
    return NULL;
}

    template <typename T>
Tnode<T*>* BST<T*>::find(T val, Tnode<T*> *cur, bool &found)
{
    if(cur == NULL)
    {
        return NULL;
    }
    if(*(cur->value) == val)
    {
        found = true;
        return cur;
    }
    else if(val< *(cur->value))
    {
        return find(val, cur->left, found);
    }
    else
    {
        return find(val, cur->right, found);
    }
    return NULL;
}
/*
*   height
*       returns height of tree, public function
*   param
*       void
*   return
*       returns height as an int
*/
    template <typename T>
int BST<T>::height()
{
    return height(root);
}

    template <typename T>
int BST<T*>::height()
{
    return height(root);
}
/*
*   height(recursive)
*       returns height of tree as integer, private function
*   param
*       Tnode pointer for traversal
*   return
*       height of tree as integer
*/

    template <typename T>
int BST<T>::height(Tnode<T> *cur)
{
    if(cur == NULL || (cur->left == NULL && cur->right == NULL))
    {
        return 0;
    }
    int rtree = (height(cur->right));
    int ltree = (height(cur->left));
    if(rtree >= ltree)
        return rtree + 1;
    else
        return ltree + 1;
}

    template <typename T>
int BST<T*>::height(Tnode<T*> *cur)
{
    if(cur == NULL || (cur->left == NULL && cur->right == NULL))
    {
        return 0;
    }
    int rtree = (height(cur->right));
    int ltree = (height(cur->left));
    if(rtree >= ltree)
        return rtree + 1;
    else
        return ltree + 1;
}
/*
*   balanced
*       checks if BST is balanced, public function
*   param
*       void
*   return
*       bool distinguishing whether tree is balanced or not
*/
    template <typename T>
bool BST<T>::balanced()
{
    int height = 0;
    return balanced(root, height);
}

    template <typename T>
bool BST<T*>::balanced()
{   
    int height = 0;
    return balanced(root, height);
}
/*
*   balanced(recursive)
*       checks if subtree rooted at cur is balanced, private function
*   param
*       Tnode pointer for traversal, height to determine balance
*   return
*       returns boolean true if balanced false if unbalanced
*/
    template <typename T>
bool BST<T>::balanced(Tnode<T> *cur, int &cur_height)
{
    int rh = 0;
    int lh = 0;
    if(cur == NULL || (cur->left == NULL && cur->right == NULL))
    {
        cur_height = 0;
        return true;
    }
    bool l = balanced(cur->left, lh);
    bool r = balanced(cur->right, rh);
    int res = abs(lh-rh);
    cur_height = (lh<rh)?(rh+1):(lh+1);
    if(res > 1)
        return false;
    else
        return (r && l);
}

    template <typename T>
bool BST<T*>::balanced(Tnode<T*> *cur, int &cur_height)
{
    int rh = 0;
    int lh = 0;
    if(cur == NULL || (cur->left == NULL && cur->right == NULL))
    {
        cur_height = 0;
        return true;
    }
    bool l = balanced(cur->left, lh);
    bool r = balanced(cur->right, rh);
    int res = abs(lh-rh);
    cur_height = (lh<rh)?(rh+1):(lh+1);
    if(res > 1)
        return false;
    else
        return (r && l);
}
/*
*   size
*       returns size of tree, public function
*   param
*       void
*   return
*       size as an integer
*/
    template <typename T>
int BST<T>::size()
{
    return size(root);
}
    template <typename T>
int BST<T*>::size()
{
    return size(root);
}
/*
*   size(recursive)
*       returns size of tree as int, private function
*   param
*       Tnode pointer for traversal
*   return
*       size as integer
*/
    template <typename T>
int BST<T>::size(Tnode<T> *cur)
{
    if(cur == NULL)
        return 0;
    int l = size(cur->left);
    int r = size(cur->right);
    return l + r + 1;
}

    template <typename T>
int BST<T*>::size(Tnode<T*> *cur)
{
    if(cur == NULL)
        return 0;
    int l = size(cur->left);
    int r = size(cur->right);
    return l + r + 1;
}
/*
*   print_subtree
*       prints subtree rooted at the node whose value is val using find and print_inorder functions, public function
*   param
*       value of type T to be found
*   return
*       void
*/
    template <typename T>
void BST<T>::print_subtree(T val)
{
        bool found = false;
        Tnode<T> *temp = find(val, root, found);
        if(found == true)
            print_inorder(temp);
}
    template <typename T>
void BST<T*>::print_subtree(T val)
{

        bool found = false;
        Tnode<T*> *temp = find(val, root, found);
        if(found == true)
            print_inorder(temp);
}
