#include <iostream>

using namespace std;

int linearSearch(int *arr, int size, int target){
        int NumofIterations = 0;
        int f = 0;
        int index=-1;
        for(int i=0; i<size && f ==0; i++){
            if(arr[i]==target){
                f = 1;
                index = i;
                //return i; // returning the index
            }
            NumofIterations++;
        }
        cout<<"Number of iterations: "<<NumofIterations<<endl;
        return index;
}

int main()
{
    int arr[]={10,20,30,40,50,60};
    int result = linearSearch(arr,6,30);
    result==-1?cout<<"Target not found!!"<<endl:cout<<"Target found in index: "<<result<<endl;
    return 0;
}
