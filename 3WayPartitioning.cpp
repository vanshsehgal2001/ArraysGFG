// void threeWayPartition(vector<int>& array,int a, int b)
    // {
    //     vector<int> less;
    //     vector<int> equal;
    //     vector<int> more;
    //     for(int i=0;i<array.size();i++){
    //         if(array[i]<a){
    //             less.push_back(array[i]);
    //         }
    //         else if(array[i]>b){
    //             more.push_back(array[i]);
    //         }
    //         else if(array[i]>=a && array[i]<=b){
    //             equal.push_back(array[i]);
    //         }
    //     }
    //     array.clear();
    //     for(int i=0;i<less.size();i++){
    //         array.push_back(less[i]);
    //     }
    //     for(int i=0;i<equal.size();i++){
    //         array.push_back(equal[i]);
    //     }
    //     for(int i=0;i<more.size();i++){
    //         array.push_back(more[i]);
    //     }
    // }
    
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int n=array.size();
        int start=0,end=n-1;
        for(int i=0;i<=end;){
            if(array[i]<a){
                swap(array[i++],array[start++]);
            }
            else if(array[i]>b){
                swap(array[i],array[end--]);
            }
            else{
                i++;
            }
        }
        
    }
