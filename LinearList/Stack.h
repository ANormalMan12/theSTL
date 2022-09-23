/**
 * @file Stack.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief (Tested)
 * The file contains two kind of stack.
 * One is based on LinkedNode, while another is based on array in the object
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include"List.h"

namespace theSTL{
    struct Stack_exception{std::string message;};
    /**
     * @brief Stack based on linked nodes
     * 
     * @tparam datatype 
     */
    template<typename datatype> class Stack_Linked{
        using Node=forwardLinkedNode<datatype>;
        private:
            Node head;
            Node* _top;
        public:
            Stack_Linked():_top(&head){}
            ~Stack_Linked(){
                Node*temp;
                while(&head!=_top){
                    temp=_top;
                    _top=_top->next;
                    delete temp;
                }
            }
            void push(datatype x){
                Node* addedNode=new Node{_top,x};
                _top=addedNode;
            }
            void pop(){
                if(_top==&head){
                    throw Stack_exception{"Pop from empty stack!"};
                }else{
                    auto temp=_top;
                    _top=_top->next;
                    delete temp;
                }
            }
            datatype top(){
                if(_top==&head){
                    throw Stack_exception{"Top from empty stack!"};
                }
                return _top->data;
            }
            bool empty(){
                return _top==&head;
            }
    };
    template<typename datatype> class Stack_Array{
        private:
            datatype* arr;
            int datapos=-1;
            int maxsize;
        public:
        Stack_Array(int newsize):maxsize(newsize){
            arr=new datatype[maxsize];
        }
        ~Stack_Array(){
            delete[] arr;
        }
        void push(datatype x){
            if(datapos==maxsize-1){
                throw Stack_exception{"Full Stack"};
            }
            arr[++datapos]=x;
        }
        void pop(){
            if(datapos==-1){
                throw Stack_exception{"Pop from empty stack!"};
            }
            --datapos;
        }
        datatype top(){
            if(datapos==-1){
                throw Stack_exception{"Top from empty stack!"};
            }
            return arr[datapos];
        }
        bool empty(){
            return datapos==-1;
        }
    };
}