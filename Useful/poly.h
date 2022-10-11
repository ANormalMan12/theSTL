#include<string>
#include<iostream>
int getnum(const std::string& s,int begin,int end){
    int ret=0;
    bool negative=false;
    if(s[begin]=='-'){
        negative=true;
        ++begin;
    }
    while(begin!=end){
        ret*=10;
        ret+=s[begin++]-'0';
    }
    if(negative){ret=-ret;}
    return ret;
}

struct poly{
    struct NODE{
        int coef,val;
        NODE* next;
    };
    NODE head;
    void push(int temcoef,int temval,bool neg){
        auto p=&head;
            while(p->next!=nullptr){
                p=p->next;
            }
            p->next=new NODE;
            p->next->coef=temcoef;
            p->next->val=neg?-temval:temval;
            p->next->next=nullptr;
    }
    poly(){
        head.next=nullptr;
    }
    poly(const std::string& str){
        head.next=nullptr;
        int l=0,r=1;
        if(str.size()==1){
            if(str[0]=='x'){
                push(1,1,false);
            }else if('0'<=str[0]&&str[0]<='9'){
                push(0,str[0]-'0',false);
            }else{
                std::cout<<"ERROR";
            }
        }
        while(r<str.size()){
            bool neg=false;
            if(str[l]=='-'){
                neg=true;
                ++l;
                r=l+1;
            }else if(str[l]=='+'){
                ++l;
                r=l+1;
            }
            
            int xpos=-1,powerpos=-1;
            if(str[l]=='x'){xpos=l;}
            if(str[l]=='^'){powerpos=l;}
            while(str[r]!='+'&&str[r]!='-'&&str[r]!='\0'){
                if(str[r]=='x'){xpos=r;}
                if(str[r]=='^'){powerpos=r;}
                ++r;
            }
            int temcoef,temval;
            if(xpos==-1){
                temcoef=0;
                temval=getnum(str,l,r);
            }else{
                //calculate val
                if(l==xpos){temval=1;}//x^2, x
                else{temval=getnum(str,l,xpos);}//3x^2

                //calculate coef
                if(powerpos==-1){
                    temcoef=1;
                }else{
                    temcoef=getnum(str,powerpos+1,r);
                }
            }
            //add to the linked list
            push(temcoef,temval,neg);
            //when the loop ends,update position variable
            l=r; 
            r=r+1;
        }

    }
    ~poly(){
        auto p=head.next;
        NODE* toDelete;
        while(p!=nullptr){
            toDelete=p;
            p=p->next;
            delete toDelete;
        }
    }
    void print(){
        NODE* p=&head;
        while(p->next!=nullptr){
            p=p->next;
            std::cout<<'('<<p->val<<','<<p->coef<<')';
        }
        std::cout<<std::endl;
    }
    void printAns(){
        NODE* p=&head;
        while(p->next!=nullptr){
            p=p->next;
            if(p->val!=0){
                std::cout<<p->val<<' ';
            }
        }
        std::cout<<std::endl;
    }
    void insert(int newcoef,int newval){
        auto before=&head;
        auto p=head.next;
        if(head.next==nullptr){
            push(newcoef,newval,false);
        }else{
            while(newcoef < p->coef){
                if(p->next!=nullptr){
                    before=p;
                    p=p->next;
                }else{
                    break;
                }
            }
            if(newcoef==p->coef){
                p->val+=newval;
            }else if(newcoef>p->coef){
                before->next=new NODE;
                before->next->coef=newcoef;
                before->next->val=newval;
                before->next->next=p;
            }else{
                if(p->next==nullptr){
                    p->next=new NODE;
                    p->next->coef=newcoef;
                    p->next->val=newval;
                    p->next->next=nullptr;
                }else{
                    before=p;
                    p=p->next;
                    before->next=new NODE;
                    before->next->coef=newcoef;
                    before->next->val=newval;
                    before->next->next=p;
                }
            }
        }
    }
    friend poly operator*(const poly&x,const poly&y){
        poly ret;
        auto xp=x.head.next,yp=y.head.next;
        while(xp!=nullptr){
            auto temyp=yp;
            while(temyp!=nullptr){
                ret.insert(temyp->coef+xp->coef,
                temyp->val*xp->val);
                temyp=temyp->next;
            }
            xp=xp->next;
        }
        return ret;
    }
};

int testPoly(){
    std::string xstr,ystr;
    while(std::cin>>xstr>>ystr){
        poly x{xstr},y{ystr};
        //x.print();
        //y.print();
        (x*y).printAns();
    }   
}