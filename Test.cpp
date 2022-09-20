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

#define LINEAR_TEST
#define SORT_TEST
#define TREE_TEST
//#define GRAPH_TEST


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

int main(){
#ifdef LOCAL
freopen("C:\\Users\\worke\\Documents\\GitHub\\mySTL\\in.txt","r",stdin);
freopen("C:\\Users\\worke\\Documents\\GitHub\\mySTL\\out.txt","w",stdout);
#endif
    #ifdef LINEAR_TEST
    std::cout<<"Now you are testing Linear List"<<std::endl;
    test::testListPushPop();
    test::testListErase();
    #endif

    #ifdef SORT_TEST
    
    #endif

    #ifdef TREE_TEST
    
    #endif

    #ifdef GRAPH_TEST
    test::testMatrixGraphBasics();
    #endif
}