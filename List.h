#include<iostream>

namespace mySTL{
    template<typename datatype> class List{
        private:
        struct ListNode{
            ListNode* prior;
            ListNode* next;
            datatype data;
        }head;

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
        bool empty(){
            return head.next==&head;
        }
        int size(){
            int len=0;
            ListNode* p=&head;
            do{
                ++len;
                p=p->next;
            }while(p!=&head);
            return len;
        }
        void print()const{
            const ListNode* p=&head;
            p=p->next;
            while(p!=&head){
                std::cout<<p->data<<' ';
                p=p->next;
            }
            std::cout<<std::endl;
        }
        void insert_all(){
            //
        }
    };
}