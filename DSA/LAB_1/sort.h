#include<cstdio>
#include<cstdlib>

//BUBBLE SORTING
void BubbleSort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                 arr[j]=arr[j]-arr[j+1];
            }
        }
    }
}

//SELECTION SORTING
void SelectionSort(int arr[],int size)
{
    for (int i=0;i<size-1;i++) 
    {
        int minIndex = i;
        for (int j=i+1;j<size;j++) 
        {
            if (arr[j]<arr[minIndex])
            {
                minIndex=j;
            }
        }
        if (minIndex!=i)
        {
            int temp=arr[i];
            arr[i]=arr[minIndex];
            arr[minIndex]=temp;
        }
    }
}

//INSERTION SORTING
void InsertionSort(int arr[],int size)
{
    int i, key, j;
    for (i=1;i<size;i++) 
    {
        key=arr[i];
        j=i-1;
        while (j>=0&&arr[j]>key) 
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

void output(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
