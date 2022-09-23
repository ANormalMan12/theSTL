#include"List.h"
#include"Deque.h"
#include"Array.h"
#include"Stack.h"
#include<iostream>

namespace test{
    using namespace std;
    /**
     * @brief test about adding or erasing an item at the beginning or the end
     * 
     * 
     */
    void testListPushPop(){
        cout<<"\nNow test List's push and pop\n";
        theSTL::List<int> myList;
        cout<<"Push back {5,...,10}"<<endl;
        for(int i=5;i<=10;++i){
            myList.push_back(i);
        }
        cout<<myList;
        cout<<"Push front {4,3,2,1,0}"<<endl;
        for(int i=4;i>=0;--i){
            myList.push_front(i);
        }
        cout<<myList;
        cout<<"Pop front 7 integers"<<endl;
        for(int i=0;i<=6;i++){
            myList.pop_front();
        }
        cout<<myList;
        cout<<"Pop back 4 integers"<<endl;
        for(int i=7;i<10;++i){
            myList.pop_back();
        }
        cout<<myList;
    }
    void testListErase(){
        cout<<"\nNow test erase\n";
        theSTL::List<int> myList;
        for(int i=7;i<=16;++i){
            myList.push_back(i);
        }
        for(int i=9;i<=14;++i){
            myList.push_back(i);
        }
        cout<<"Now the list contains:\n";
        cout<<myList;
        cout<<"Now erase 10\n";
        myList.erase(10);
        cout<<myList;
        cout<<"Now erase 10 again\n";
        myList.erase(10);
        cout<<myList;
        
        cout<<"\nTry to erase after pointer\n";
        cout<<"Now erase 13, and save pointer\n";
        auto temp=myList.erase(13);
        cout<<myList;
        cout<<"Now push front 13\n";
        myList.push_front(13);
        cout<<myList;
        cout<<"Now erase 13\n";
        myList.erase(13,temp);
        cout<<myList;
    }

    void testStack(){
        cout<<"\nTest Linked Stack\n";
        theSTL::Stack_Linked<int> stk;
        for(int i=0;i<10;++i){
            cout<<"plan to push "<<i<<endl;
            stk.push(i);
        }
        cout<<"isEmpty: "<<stk.empty()<<endl;
        for(int i=0;i<9;++i){
            try{
                cout<<"Now pop "<<stk.top()<<endl;
                stk.pop();
            }catch(theSTL::Stack_exception error){
                std::cout<<error.message<<std::endl;
            }
        }
        cout<<"isEmpty: "<<stk.empty()<<endl;
        for(int i=0;i<3;++i){
            cout<<"plan to push "<<i<<endl;
            stk.push(i);
        }
        cout<<"isEmpty: "<<stk.empty()<<endl;
        for(int i=0;i<4;++i){
            try{
                cout<<"Now pop "<<stk.top()<<endl;
                stk.pop();
            }catch(theSTL::Stack_exception error){
                std::cout<<error.message<<std::endl;
            }
        }
        cout<<"isEmpty: "<<stk.empty()<<endl;

//Then carry out Array Stack

        cout<<"\nTest Array Stack with size 8\n";
        theSTL::Stack_Array<int> Astk{8};
        for(int i=0;i<10;++i){
            try{
                cout<<"plan to push "<<i<<endl;
                Astk.push(i);
            }catch(theSTL::Stack_exception error){
                std::cout<<error.message<<std::endl;
            }
        }
        cout<<"isEmpty: "<<Astk.empty()<<endl;
        for(int i=0;i<10;++i){
            try{
                cout<<"Now pop "<<Astk.top()<<endl;
                Astk.pop();
            }catch(theSTL::Stack_exception error){
                std::cout<<error.message<<std::endl;
            }
        }
        cout<<"isEmpty: "<<Astk.empty()<<endl;
    }

}
