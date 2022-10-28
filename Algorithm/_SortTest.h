#include<iostream>
#include<cstdio>
#include"Sort.h"
#include<cstring>
#include<cstdlib>

namespace test{
    void testSort(){
        using namespace std;
        struct sameInt{
            int val;
            int NO;
            bool operator<(const sameInt& ano)const{
                return val<ano.val;
            }
        };
        const int arrlen=11;
        const sameInt arr[arrlen]={{3,1}, {4,1},{3,2},{13,0}
                                  ,{8,0}, {-2,0},{4,2},{151,0}
                                  ,{65,0},{3,3},{-54,0}};
        sameInt temarr[arrlen];
        printf("Original array is\n");
        for(int i=0;i<arrlen;++i){
            printf("%d",arr[i].val);
            if(arr[i].NO){printf("(%d)",arr[i].NO);}
            putchar(',');
        }
        putchar('\n');
        
        printf("Bubble sort:\n");
        memcpy(temarr,arr,sizeof(arr));
        theSTL::bubble_sort(temarr,0,arrlen-1,theSTL::ascend);
        for(int i=0;i<arrlen;++i){
            printf("%d",temarr[i].val);
            if(temarr[i].NO){printf("(%d)",temarr[i].NO);}
            putchar(',');
        }
        putchar('\n');

        printf("Select sort:\n");
        memcpy(temarr,arr,sizeof(arr));
        theSTL::select_sort(temarr,0,arrlen-1,theSTL::ascend);
        for(int i=0;i<arrlen;++i){
            printf("%d",temarr[i].val);
            if(temarr[i].NO){printf("(%d)",temarr[i].NO);}
            putchar(',');
        }
        putchar('\n');

        printf("Shell sort:\n");
        memcpy(temarr,arr,sizeof(arr));
        theSTL::shell_sort(temarr,0,arrlen-1,theSTL::ascend,theSTL::shellExample,theSTL::shellExampleLen);
        for(int i=0;i<arrlen;++i){
            printf("%d",temarr[i].val);
            if(temarr[i].NO){printf("(%d)",temarr[i].NO);}
            putchar(',');
        }
        putchar('\n');

        printf("Insert sort:\n");
        memcpy(temarr,arr,sizeof(arr));
        theSTL::insert_sort(temarr,0,arrlen-1,theSTL::ascend);
        for(int i=0;i<arrlen;++i){
            printf("%d",temarr[i].val);
            if(temarr[i].NO){printf("(%d)",temarr[i].NO);}
            putchar(',');
        }
        putchar('\n');

        printf("Merge sort:\n");
        memcpy(temarr,arr,sizeof(arr));
        theSTL::merge_sort(temarr,0,arrlen-1,theSTL::ascend);
        for(int i=0;i<arrlen;++i){
            printf("%d",temarr[i].val);
            if(temarr[i].NO){printf("(%d)",temarr[i].NO);}
            putchar(',');
        }
        putchar('\n');

        printf("Quick sort:\n");
        memcpy(temarr,arr,sizeof(arr));
        theSTL::quick_sort(temarr,0,arrlen-1,theSTL::ascend);
        for(int i=0;i<arrlen;++i){
            printf("%d",temarr[i].val);
            if(temarr[i].NO){printf("(%d)",temarr[i].NO);}
            putchar(',');
        }
        putchar('\n');
    }
}
