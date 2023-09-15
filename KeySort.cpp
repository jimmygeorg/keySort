/*
This is a half-assed sorting algorithm that works by sorting an array relative to a certain element (key) in ascending order.
There is still some work to be done, but for now it can be used in conjunction with a "Divide-and-Conquer" algorithm to fully sort the array

The main drawback is that the array must have at least as many cells as the value of the key element, since it's placed in the corresponding position.
It is quite limiting for now but I'm planning to keep working on it and developing it further in order to eliminate that issue.

**Line 31 is for test purposes, it's obviously meant for the desired key element**
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int KeySort(int A[], int lo, int hi, int key, int ord[]);

int main(){

    //int A[8]={0,6,5,4,7,2,3,1};
    //int A[15]={0,6,5,4,7,2,3,1,13,14,11,12,10,8,9};
    
    int hi, lo=0;

    cout<<"Enter Size: ";
    cin>>hi;
    int *A=new int[hi];
    for (int i=lo; i<hi; i++){
        cout<<"Enter "<< i <<" element: ";
        cin>> A[i];
        
    }
    int *ord = new int[sizeof(A)];
    int key=A[rand()%(lo-hi)+1];    
    
    cout<<"Initial Array:"<<endl;
      for (int i=lo; i<hi; i++){
        cout<<A[i]<<' ';
        
    }
    cout<<endl<<"-----------------"<<endl;
    cout<<"Key="<<key<<endl;
    int k=KeySort(A,lo,hi,key,ord);
    cout<<"Semi Sorted Array:"<<endl;
    for (int i=lo; i<hi; i++){
        cout<<ord[i]<<' ';
        
    }
    cout<<endl<<"Element "<<key<<" is in position "<<k<<endl<<endl;
   
        
    return 0;
}


int KeySort(int A[], int lo, int hi, int key, int ord[]){
   
    int k;
   
   
    for(int i=lo;i<hi;i++){
           
        if (A[i] == key){
                k=key;
               
            ord[k]=key;
                
                
            break;
        }
    }
    int p1=0,p2=k+1; //p1: 0<=key, p2: >key
    while (lo<hi){  
        if(p1<=k && p2<hi){
            for(int i=lo;i<hi;i++){
                
                if(A[i]!=key){
                    if(A[i]<key){
                        ord[p1] = A[i];
                        p1++;
                    }
                    else if(A[i]>key){
                        ord[p2]= A[i];
                        p2++;
                    }
                }
            }
        }
        lo++;
        
    }
    //cout<<"k="<<k<<endl;
    return k;

}
