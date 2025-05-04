#include<cstdio>
#include<cstdlib>

//DISPLAY
void Display()
{
    printf("1.BubbleSort\n2.SelectionSort\n3.InsertionSort\n4.Exit");
}

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

//OUTPUT
void output(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    int size;
    int choice;
    printf("Enter the size of the array: ");
    scanf("%d",&size);

    int arr[size];
    printf("Enter the elements of the array: ");
    for(int index=0;index<size;index++)
    {
        scanf("%d",&arr[index]);
    }

    printf("CHOOSE ANY ONE OF THE FOLLOWING CHOICES: \n");
    printf("---------------------------------------\n\n");
    Display();

    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            BubbleSort(arr,size);
            printf("You have selected Bubble Sorting and your sorted array is: \n");
            output(arr,size);
            break;
        
        case 2:
            SelectionSort(arr,size);
            printf("You have selected Selection Sorting and your sorted array is: \n");
            output(arr,size);
            break;

        case 3:
            InsertionSort(arr,size);
            printf("You have selected Insertion Sorting and your sorted array is: \n");
            output(arr,size);
            break;

        case 4:
            printf("You have decided to exit......exiting the menu........\nCODE EXITED");
            break;

        default:
            printf("Invalid choice....Please start again");
    }
}