#include"KMP.h"
#include"String.h"
#include"BM.h"

namespace test{
    using namespace std;
    void testKMP(){
        char substr[]="abafabafc";
        printf("The pattern string is \"%s\".\n",substr);
        theSTL::PatternKMP strP{substr};
        strP.print_next();

        char str[]="avkbababafabafcuwaf";
        printf("Primary string contains %s\n",str);
        int subPos=strP.find_nextsub(str,0);
        printf("Substr 's position is %d\n",subPos);

        int caseNUM=1;
        printf("Calculate some sub patterns\n");
        
        //round 1
        printf("Case %d:\n",caseNUM++);
        theSTL::String str1{"tobeornottobetobeornottobe"};
        theSTL::PatternKMP pat1{str1};
        pat1.print_next();
        //round 2
        printf("Case %d:\n",caseNUM++);
        theSTL::String str2{"ggcyzxgbiqfitwlwjptzzzzzz"};
        theSTL::PatternKMP pat2{str2};
        pat2.print_next();
        //round 3
        printf("Case %d:\n",caseNUM++);
        theSTL::String str3{"return"};
        theSTL::PatternKMP pat3{str3};
        pat3.print_next();
    }
    void testBM(){
        const int Num=3;
        char* strs[Num]={"asfdfcasfffdd"
                      ,"sasssfasdfsdf"
                      ,"utotttttoooti"};
        char* pats[Num]={"asf","df","too"};
        for(int i=0;i<Num;++i){
            theSTL::PatternBM pat{pats[i]};
            printf("Mainstr is %s\nPattern is %s\nPosition is",strs[i],pats[i]);
            cout<<pat.match(strs[i])<<endl;
            pat.printBMarr();
        }
    }
}