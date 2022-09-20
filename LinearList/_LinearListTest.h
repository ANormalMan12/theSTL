#include"List.h"
#include"Deque.h"
#include"Array.h"
#include<iostream>

using LL=long long;
namespace test{
    using namespace std;
    /**
     * @brief test about adding or erasing an item at the beginning or the end
     * 
     * 
     */
    void testListPushPop(){
        mySTL::List<int> myList;
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
}
