#include<iostream>
using namespace std;

#include "tnode.h"
#ifndef TREE_H
#define TREE_H

class Tree{
        public:
                Tree():  root(NULL) {};
                Tree(char val){ root = new Tnode<char>(val);};
                ~Tree(){ clean(root); root = NULL; };
                Tree(const Tree &rhs){
                        if(root != NULL){
                                clean(root);
                                root = NULL;
                        }
                        root = copy(rhs.root);
                };
                Tree& operator=(const Tree &rhs){
                        if(root != NULL){
                                clean(root);
                                root = NULL;
                        }//if
                        root = copy(rhs.root);
                        return *this;
                };
                void print_encoding(){ print_encoding(root, "");};
                void merge(Tree &rhs);
                int encoded_depth(char thisChar)
                {
                    int depth = 0;
                    return(encoded_depth(root,thisChar,depth));
                };
        private:
                int encoded_depth(Tnode<char> *cur, char curChar, int depth);
                Tnode<char>* copy(Tnode<char> *cur);
                void clean(Tnode<char> *cur);
                Tnode<char>* root = NULL;
                void print_encoding(Tnode<char> *cur, string dir);
};
#endif
