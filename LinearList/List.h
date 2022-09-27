/**
 * @file List.h
 * @author weiyewang (weiyewang1205@qq.com)
 * @brief Definitions of linked list
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#pragma once
namespace theSTL{
    template<typename datatype> struct doubleLinkedNode{
        doubleLinkedNode* prior;
        doubleLinkedNode* next;
        datatype data;
    };
    template<typename datatype> struct forwardLinkedNode{
        forwardLinkedNode* next;
        datatype data;
    };
    /**
     * @brief A doubly linked list class
     * @details head is a ListNode,rather than ListNode*
     * @tparam datatype 
     */
    template<typename datatype> class List{
        using ListNode=doubleLinkedNode<datatype>;
        private:
            ListNode head;
        public:      
        List(){
            head.prior=&head;
            head.next=&head;
        }
        ~List(){
            ListNode* p=&head;
            p=p->next;
            while(p!=&head){
                p=p->next;
                delete p->prior;
            }
        }
        void push_back(datatype x){
            head.prior->next=new ListNode{
                head.prior,&head,x};
            head.prior=head.prior->next;
        }
        void push_front(datatype x){
            head.next->prior
            =new ListNode{&head,head.next,x};
            head.next=head.next->prior;
        }
        void pop_back(){
            head.prior=head.prior->prior;
            delete head.prior->next;
            head.prior->next=&head;
        }
        void pop_front(){
            head.next=head.next->next;
            delete head.next->prior;
            head.next->prior=&head;
        }
        bool empty()const{
            return head.next==&head;
        }
        /**
         * @brief return size by traversing all nodes
         * 
         * @return int 
         */
        int size()const{
            int len=0;
            ListNode* p=&head;
            do{
                ++len;
                p=p->next;
            }while(p!=&head);
            return len;
        }
        /**
         * @brief try to erase one of nodes in the List
         * 
         * @param x Which data is going to be removed 
         * @param ptr Where the search would begin
         * @return ListNode* if found,return the next pointer of removed one,else return nullptr
         */
        ListNode* erase(datatype x,ListNode* ptr=nullptr){
            if(ptr==nullptr){
                ptr=head.next;
            }
            while(ptr!=&head&&x!=ptr->data){
                ptr=ptr->next;
            }
            if(x==ptr->data){
                ptr->prior->next=ptr->next;
                ptr=ptr->next;
                auto temp=ptr->prior;
                ptr->prior=ptr->prior->prior;
                delete temp;
                return ptr;
            }else{
                return nullptr;
            }
        }
        friend std::ostream& operator<<(std::ostream& out,const List&thelist){
            const ListNode* p=&thelist.head;
            p=p->next;
            while(p!=&thelist.head){
                out<<p->data<<' ';
                p=p->next;
            }
            out<<std::endl;
            return out;
        }
    };
    template<typename datatype> class ForwardList{
        using ListNode=forwardLinkedNode<datatype>;
        private:
            ListNode head;
        public:      
        List(){
            head.next=&head;
        }
        ~List(){
            ListNode* p=&head;
            ListNode* buf;
            p=p->next;
            while(p!=&head){
                buf=p;
                p=p->next;
                delete buf;
            }
        }
        void push_back(datatype x){
            ListNode* p=&head;
            while(){
                
            }
        }
        void push_front(datatype x){
            ListNode* temp=head.next;
            head.next=new ListNode{temp,x};
        }
        void pop_back(){
            head.prior=head.prior->prior;
            delete head.prior->next;
            head.prior->next=&head;
        }
        void pop_front(){
            head.next=head.next->next;
            delete head.next->prior;
            head.next->prior=&head;
        }
        bool empty()const{
            return head.next==&head;
        }
        /**
         * @brief return size by traversing all nodes
         * 
         * @return int 
         */
        int size()const{
            int len=0;
            ListNode* p=&head;
            do{
                ++len;
                p=p->next;
            }while(p!=&head);
            return len;
        }
        /**
         * @brief try to erase one of nodes in the List
         * 
         * @param x Which data is going to be removed 
         * @param ptr Where the search would begin
         * @return ListNode* if found,return the next pointer of removed one,else return nullptr
         */
        ListNode* erase(datatype x,ListNode* ptr=nullptr){
            if(ptr==nullptr){
                ptr=head.next;
            }
            while(ptr!=&head&&x!=ptr->data){
                ptr=ptr->next;
            }
            if(x==ptr->data){
                ptr->prior->next=ptr->next;
                ptr=ptr->next;
                auto temp=ptr->prior;
                ptr->prior=ptr->prior->prior;
                delete temp;
                return ptr;
            }else{
                return nullptr;
            }
        }
        friend std::ostream& operator<<(std::ostream& out,const List&thelist){
            const ListNode* p=&thelist.head;
            p=p->next;
            while(p!=&thelist.head){
                out<<p->data<<' ';
                p=p->next;
            }
            out<<std::endl;
            return out;
        }
    };
}