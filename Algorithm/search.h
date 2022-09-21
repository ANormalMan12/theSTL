
namespace theSTL{
    template<typename dataType>int binary_search(const dataType* arr,const dataType& aim){//return -1 when nothing has been found
        int l=0,r=len-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(aim==arr[mid]){
                return mid;
            }else if(aim<arr[mid]){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(l==r&&arr[l]==aim){
            return l;
        }else{
            return -1;
        }
    }
}