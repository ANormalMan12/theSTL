#include"BStree.h"
#include<iostream>

namespace test{
    using namespace std;
    void testBStree(){
        theSTL::BSTree<int> tr;
        //-----------insert test-------------------
        printf("Insert data:");
        int arr[10]{3,42,5,5,-43,63,2,1,1,5};
        for(int x:arr){
            printf("%d ",x);
            tr.insert(x);
        }
        putchar('\n');
        //-----------search test-------------------
        printf("Search:\n");
    }
}