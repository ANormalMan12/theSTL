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

namespace mySTL{
    template<typename datatype> struct ListNode{
        ListNode* prior;
        ListNode* next;
        datatype data;
    };
    /**
     * @brief A doubly linked list class
     * @details head is a ListNode,rather than ListNode*
     * @tparam datatype 
     */
    template<typename datatype> class List{
        private:
            ListNode<datatype> head;
        public:
        using ListNode=ListNode<datatype>;
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
        int size()const{
            int len=0;
            ListNode* p=&head;
            do{
                ++len;
                p=p->next;
            }while(p!=&head);
            return len;
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
        /* ListNode* insert_after(datatype x,ListNode* begin=&head){
            
        } */
    };
    template<typename datatype>std::ostream& operator<<(std::ostream& out,const List<datatype>&thelist){
            const auto p=&thelist.head;
            p=p->next;
            while(p!=&thelist.head){
                out<<p->data<<' ';
                p=p->next;
            }
            out<<std::endl;
            return out;
        }
}