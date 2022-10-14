#include<iostream>
#include<cstdio>
#include"Sort.h"
#include<cstring>
#include<cstdlib>
namespace test{
    using namespace std;
    const int arrlen=10;
    const int arr[arrlen]={3,4,5,48,8,-2,4,151,65,-54};
    int temarr[arrlen];
    printf("Original array is\n");
    for(int i=0;i<arrlen;++i){
        printf("%d ",arr[i]);
    }
    putchar('\n');
    
    memcpy(temarr,arr,sizeof(arr));

}
