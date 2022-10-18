#include"KMP.h"
#include"String.h"

namespace test{
    using namespace std;
    void testKMP(){
        char substr[]="abafabafc";
        printf("The pattern string is \"%s\".\n",substr);
        theSTL::Pattern strP{substr};
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
        theSTL::Pattern pat1{str1};
        pat1.print_next();
        //round 2
        printf("Case %d:\n",caseNUM++);
        theSTL::String str2{"ggcyzxgbiqfitwlwjptzzzzzz"};
        theSTL::Pattern pat2{str2};
        pat2.print_next();
        //round 3
        printf("Case %d:\n",caseNUM++);
        theSTL::String str3{"return"};
        theSTL::Pattern pat3{str3};
        pat3.print_next();
    }
    void testBM(){
        theSTL::String strs[]={"asfdfcasfffdd"
                      ,"sasssfasdfsdf"
                      ,"utotttttoooti"};
        theSTL::PatternBM pat{};
        printf("Pattern is %s\n")
        cout<<pat.match(A)<<endl;
        pat.printBMarr();
    }
}