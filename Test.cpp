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

#ifdef LINEAR_TEST
#include"LinearList/_LinearListTest.h"
#endif

int main(){
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif
    #ifdef LINEAR_TEST
    test::testListPushPop();
    #endif
}