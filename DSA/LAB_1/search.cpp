#include<cstdio>
#include<cstdlib>
#include"sort.h"

void LinearSearch(int arr[],int size,int target)
{
    for (int i=0;i<size-1;i++)
    {
        if(target==arr[i])
        {
            printf("The target is found at the index: %d",arr[i]);
        }
    }
}

void BinarySearch(int arr[],int size,int target)
{
    int left=0;
    int right=size-1;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(target==arr[mid])
        {
            printf("The target is found at the index: %d",arr[mid]);
            break;
        }
        else if(target<arr[mid])
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of the array: ");
    for(int index=0;index<size;index++)
    {
        scanf("%d",&arr[index]);
    }
    int target;
    printf("Enter the element to be found: ");
    scanf("%d",&target);
    BubbleSort(arr,size);
    printf("The sorted array is: ");
    output(arr,size);
    BinarySearch(arr,size,target);
    
}