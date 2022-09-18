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