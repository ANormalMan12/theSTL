/**
 * @file Queue.h
 * @author Weiye Wang (wangweiye1205@outlook.com)
 * @brief The file contains two kinds of definitions of queue
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include"List.h"

namespace theSTL{
    template<typename datatype> class Queue_ring{
        private:
            int rear,front;
            int size;
            datatype* arr;
        public:
            Queue_ring(int);
            ~Queue_ring();
            void enqueue(datatype);
            void dequeue();
            datatype getfront();
            void clear();
            bool empty();
            int len();
            int capacity();
    };
    template<typename datatype> class Queue_link{
        private:
            forwardLinkedNode rear;
            forwardLinkedNode* front;
        public:
            Queue_link();
            ~Queue_link();
            void enqueue(datatype);
            void dequeue();
            datatype getfront();
            void clear();
            bool empty();
            int len();
            int capacity();
    };
}