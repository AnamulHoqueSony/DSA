Binary Search Recursive Implementation

   int find(int low,int high,int x){

    int mid = (low + high)/2;
    if(low > high)
        return -1;
    if(A[mid] == x)
        return mid;
   if(A[mid] > x)
       find(low,high-1,x);
   else
       find(mid+1,high,x);
}

Binary search - finding first or last occurrence of a number

#include<stdio.h>
 int A[10] = {1,2,2,3,7,50,};

int fi_find(int x){
    int low = 0;
    int high = 5;
    int mid,result = -1;
    while(low <= high){
        mid = (low+high)/2;


        if(A[mid] == x){
            result = mid;
            high = mid-1;
        }
        else if(A[mid] > x)
               high = mid -1;
        else
            low = mid+1;
    }
    return result;
}
int la_find(int x){
    int low = 0;
    int high = 5;
    int mid;
    int result = -1;
    while(low <= high){
        mid = (low+high)/2;

        if(A[mid] == x){
            result = mid;
            low = mid+1;
        }
        else if(A[mid] > x)
               high = mid -1;
        else
            low = mid+1;
    }
   return result;
}

int main(){
    /// find the how many time 3 have in the list.
    int first_occurance = fi_find(3);
    int last_occurance = la_find(3);

    printf("%d\n",last_occurance - first_occurance+1);
}

