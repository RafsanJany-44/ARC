#include<stdio.h>


int BinSearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return BinSearch(arr, l, mid - 1, x); 

        return BinSearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 

int main(){
    int key;
    printf("Search key: ");
    scanf("%d",&key);
    int arr[] = {5,3,10,14,15}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int find = BinSearch(arr, 0, n - 1, key); 
    if (find==-1)
    {
        printf("%d is not found",key);
    }
    else
    {
        printf("%d is found",key);
    }
}