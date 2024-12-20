#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;

}

void BubbleSort(int *arr, int size){
    int NumofIterations = 0;
    int sorted = 0; // unsorted
    for(int outer=0; sorted==0; outer++){ // sorted=0 --> didn't swap anything so they're all sorted NO NEED to go inside the loop again
        sorted = 1;
        for(int i=0; i<size-1-outer; i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
                sorted = 0;
            }
            NumofIterations++;
        }
    }
    cout<<"Num of Iterations: "<<NumofIterations;

}

void display(int *arr, int size){
    for(int j=0; j<size; j++){
        cout<<arr[j]<<" ";
    }
}

int main()
{
    int arr[]={400,10,600,20,50};
    int sizeOfArr = sizeof(arr)/sizeof(arr[0]);
    cout<<"Before Bubble Sort => ";
    display(arr, sizeOfArr);
    cout<<endl;
    BubbleSort(arr, sizeOfArr);
    cout<<endl;
    cout<<"After Bubble Sort => ";
    display(arr, sizeOfArr);
    cout<<endl;
    return 0;
}
