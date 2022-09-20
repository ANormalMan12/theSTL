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
#define LINEAR_TEST
#define SORT_TEST
#define TREE_TEST
#define GRAPH_TEST


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
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    #ifdef LINEAR_TEST
    std::cout<<"Now you are testing Linear List"<<std::endl;
    test::testListPushPop();
    #endif
}