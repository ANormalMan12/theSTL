//#include"BStree.h"
#include"rbTree.h"
#include"orderSearchTree.h"
#include"intervalTree.h"
#include<iostream>
#include"../Help/Rand.h"
namespace test{
    using namespace std;
    /* void testBStree(){
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
    } */
    void testOStree(){
        int T=10;
        for(int iT=0;iT<T;++iT){
            int *arr=RAND::newRandArr(10,-300,300);
            theSTL::oSTree<int> ost;
            for(int i=0;i<10;++i){
                cout<<arr[i]<<' ';
                ost.insert(arr[i]);
            }
            cout<<endl;
            
            cout<<"Preorder"<<endl;
            ost.printPreOrderTraverse();
            cout<<"Inorder"<<endl;
            ost.printInOrderTraverse();
            delete[] arr;
        }
    }
    void testInTree(){
        theSTL::inTree itree;
        theSTL::interval arr[10]={{123,200},{124,553},{56,70},{-54,0},{32,33},
                    {120,190},{-123,-4},{43,50},{132,311},{21,1000}};
        for(int i=0;i<10;++i){
            itree.insert(arr[i]);
        }
        itree.printPreOrderTraverse();
        itree.printInOrderTraverse();
    }
    void testRBtree(){
        theSTL::rbTree<int> tr;
        for(int i=11;i<13;++i){
            tr.insert(i);
            tr.printPreOrderTraverse();
            tr.printInOrderTraverse();
            putchar('\n');
        }
        for(int i=7;i<=10;++i){
            tr.insert(i);
            tr.printPreOrderTraverse();
            tr.printInOrderTraverse();
            putchar('\n');
        }
        for(int i=8;i<=10;++i){
            cout<<"try to erase "<<i<<endl;
            tr.erase(i);
            tr.printPreOrderTraverse();
            tr.printInOrderTraverse();
            putchar('\n');
        }

    }
    void testInt(){
        theSTL::inTree tr;
        theSTL::interval arr[6]={{17,19},{5,11},
        {22,23},{15,18},{4,8},{7,10}};
        for(int i=0;i<6;++i){
            tr.insert(arr[i]);
        }
        tr.printPreOrderTraverse();
        tr.printInOrderTraverse();
        cout<<tr.intervalSumSearch({3,35});//6
        cout<<tr.intervalSumSearch({15,19});//2
        cout<<tr.intervalSumSearch({4,8});//3
        cout<<tr.intervalSumSearch({17.5,22.5});//3
    }
}