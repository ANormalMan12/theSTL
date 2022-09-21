/**
 * @file Stack.h
 * @author Weiye Wang (you@domain.com)
 * @brief The file contains two kind of stack.
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
    template<typename datatype> class Stack_Linked{
        using Node=forwardLinkedNode<datatype>;
        private:
            Node
        public:

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
            arr[++datapos]=x;
        }
        void pop(){
            --datapos;
        }
        datatype top(){
            return arr[datapos];
        }
        bool empty(){
            return datapos==-1;
        }
    };
}