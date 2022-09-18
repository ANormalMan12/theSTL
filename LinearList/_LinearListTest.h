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
        for(int i=5;i<=10;++i){
            myList.push_back(i);
        }
        cout<<myList;
        for(int i=4;i>=0;--i){
            myList.push_front(i);
        }
        cout<<myList;
        for(int i=0;i<=6;i++){
            myList.pop_front();
        }
        cout<<myList;
        for(int i=7;i<10;++i){
            myList.pop_back();
        }
        cout<<myList;
    }
}
