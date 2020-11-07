#include <iostream>
#include <algorithm>

using namespace std;

void fun(int *arr1,char *arr2,int n){
    pair<int,char> p1[n];
    for(int i=0;i<n;i++){
        p1[i] = {arr1[i],arr2[i]};
    }
    sort(p1,p1+n);
    for(int i=0;i<n;i++){
        cout<<p1[i].second<<"\t";
    }

}

int main()
{
    pair<int,string> p1;
    int arr[3] = {10,15,5};
    char arr2[3] = {'X','Y','Z'};
    fun(arr,arr2,3);
    return 0;
}
