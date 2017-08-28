/*
*       Project06
*       bst.h
*       Daniel Rush
*/
#include<iostream>
using namespace std;

#include "tnode.h"
#ifndef BST_H
#define BST_H

template <typename T>
class BST{
        public:
                BST():  root(NULL) {};
                ~BST(){ clean(root); root = NULL; };
                BST(const BST &rhs){
                        if(root != NULL){
                                clean(root);
                                root = NULL;
                        }
                        root = copy(rhs.root);
                };
                BST& operator=(const BST &rhs){
                        if(root != NULL){
                                clean(root);
                                root = NULL;
                        }//if
                        root = copy(rhs.root);
                        return *this;
                };
                void print_inorder(){ print_inorder(root);
                    cout << endl;};

                bool insert(T val);
                bool remove(T val);
                bool find(T val);
                int height();
                bool balanced();
                int size();
                void print_subtree(T val);
        private:
                int size(Tnode<T> *cur);
                int height(Tnode<T> *cur);
                bool balanced(Tnode<T> *cur, int &cur_height);
                Tnode<T>* copy(Tnode<T> *cur);
                void clean(Tnode<T> *cur);
                Tnode<T>* root = NULL;
                void print_inorder(Tnode<T> *cur);
                Tnode<T>* remove_leftmost(Tnode<T> *r);
                Tnode<T>* find(T val, Tnode<T> *cur, bool &found);
                Tnode<T>* remove(T val, Tnode<T> *cur, bool &r);
                Tnode<T>* get_leftmost(Tnode<T> *cur);
};
//partial specialization
template <typename T>
class BST<T*>{
        public:
                BST():  root(NULL) {};
                ~BST(){ clean(root); root = NULL; };
                BST(const BST &rhs){ 
                        if(root != NULL){
                                clean(root);
                                root = NULL;
                        }
                        copy(rhs.root);
                };
                BST& operator=(const BST &rhs){ 
                        if(root != NULL){
                                clean(root);
                                root = NULL;
                        }//if
                        copy(rhs.root);
                        return *this;
                };
                bool insert(T val);
                void print_inorder(){ print_inorder(root);
                cout << endl;};

                bool remove(T val);
                bool find(T val);
                int height();
                bool balanced();
                int size();
                void print_subtree(T val);
        private:
                int size(Tnode<T*> *cur);
                int height(Tnode<T*> *cur);
                bool balanced(Tnode<T*> *cur, int &cur_height);
                Tnode<T*>* copy(Tnode<T*> *cur);
                void clean(Tnode<T*> *cur);
                Tnode<T*>* root = NULL;
                void print_inorder(Tnode<T*> *cur);
                Tnode<T*>* remove_leftmost(Tnode<T*> *r);
                 Tnode<T*>* find(T val, Tnode<T*> *cur, bool &found);
                 Tnode<T*>* remove(T val, Tnode<T*> *cur, bool &r);
                 Tnode<T*>* get_leftmost(Tnode<T*> *r);
};

#endif
