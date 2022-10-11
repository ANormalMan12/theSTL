/**
 * @file Test.cpp
 * @author Weiye Wang (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief below are trigers of testing modules
 * 
 */
#define LOCAL

//#define LINEAR_TEST
//#define SORT_TEST
//#define TREE_TEST
//#define GRAPH_TEST
#define STRING_TEST

#ifdef LINEAR_TEST
#include"LinearList/_LinearListTest.h"
#endif
#ifdef SORT_TEST
#include"Algorithm/_SortTest.h"
#endif
#ifdef TREE_TEST
#include"Tree_Graph/_TreeTest.h"
#endif
#ifdef GRAPH_TEST
#include"Tree_Graph/_GraphTest.h"
#endif
#ifdef STRING_TEST
#include"String/_StringTest.h"
#endif

int main(){
#ifdef LOCAL
freopen("C:\\Users\\worke\\Documents\\GitHub\\mySTL\\in.txt","r",stdin);
freopen("C:\\Users\\worke\\Documents\\GitHub\\mySTL\\out.txt","w",stdout);
#endif
//--------test linear lists-------------------------------------
    #ifdef LINEAR_TEST
    std::cout<<"Now you are testing Linear List"<<std::endl;
    test::testListPushPop();
    test::testListErase();
    
    test::testStack(); 
    #endif
//--------test sort algorithm---------------------------------------
    #ifdef SORT_TEST
    
    #endif
//--------test tree algorithm--------------------------------
    #ifdef TREE_TEST
    
    #endif
//--------test graph algorithm-------------------------------
    #ifdef GRAPH_TEST
    test::testMatrixGraphBasics();
    #endif
//--------test string algorithm-------------------------------
    #ifdef STRING_TEST
    test::testKMP();
    #endif
}