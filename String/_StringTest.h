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
        cout<<subPos<<endl;
    }
}