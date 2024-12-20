#include <iostream>

using namespace std;

int BinarySearch(int *arr, int size, int target){
    int NumofIterations = 0;
    int start, middle = 0;
    int end = size-1;
    while(start<=end){ // start!=end+1 is okk BUT start<= read is better for readability
        middle=(start+end)/2;
        NumofIterations++;
        if(arr[middle]==target){
            return middle;
            cout<<"NumofIterations: "<<NumofIterations<<endl;
        }
        else if(arr[middle]<target){
            start=middle+1; // shift start to the right half
        }
        else if(arr[middle]>target){
            end=middle-1; // shift end to the left half
        }
    }
    cout<<"NumofIterations: "<<NumofIterations<<endl;
    return -1;
}

int main()
{
    int arr[]={10,20,30,40,50};
    int sizeOfArr = sizeof(arr)/sizeof(arr[0]);
    //cout<<sizee<<endl;
    int result = BinarySearch(arr, sizeOfArr, 50);
    result==-1?cout<<"Target not found !!"<<endl:cout<<"Target found"<<endl;
    return 0;
}
