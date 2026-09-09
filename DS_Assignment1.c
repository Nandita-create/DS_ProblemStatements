#include <stdio.h>
#include <stdlib.h>

void Print(int *, int);
void LinearSearch(int *, int);
void InsertionSort(int *, int);
void SelectionSort(int *, int);
void BubbleSort(int *, int);
void QuickSort(int*, int, int);
int partition(int *, int, int);
void MergeSort(int *, int, int);
void merge(int *, int, int, int);
void BinarySearch(int *, int);
void FibonacciSearch(int *, int);

int main()
{
    int *arr, arrSize;
    printf("Enter size of array: ");
    scanf("%d" ,&arrSize);

    arr = (int *)malloc(arrSize*sizeof(int));

    printf("Enter %d elements of the array: " ,arrSize);
    for (int i=0 ; i<arrSize ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    int x=0, choice;
    do
    {
        printf("Enter \n1. Print array \n2. Linear search \n3. Insertion sort \n4. Selection sort \n5. Bubble sort \n6. Quick sort \n7. Merge sort \n8. Binary search \n9. Fibonacci search \n0. Exit \n");
        scanf("%d" ,&choice);
        printf("\n");

        switch(choice)
        {
            case 1: 
            printf("Printing Array \n");
            Print(arr, arrSize);
            break;

            case 2:
            printf("Linear Search \n");
            LinearSearch(arr, arrSize);
            break;

            case 3:
            printf("Insertion Sort \n");
            InsertionSort(arr, arrSize);
            Print(arr, arrSize);
            break;

            case 4:
            printf("Selection Sort \n");
            SelectionSort(arr, arrSize);
            Print(arr, arrSize);
            break;

            case 5:
            printf("Bubble Sort \n");
            BubbleSort(arr, arrSize);
            Print(arr, arrSize);
            break;

            case 6:
            printf("Quick Sort \n");
            QuickSort(arr, 0, arrSize-1);
            Print(arr, arrSize);
            break;

            case 7:
            printf("Merge Sort \n");
            MergeSort(arr, 0, arrSize-1);
            Print(arr, arrSize);
            break;

            case 8:
            printf("Binary Search \n");
            BinarySearch(arr, arrSize);
            break;

            case 9:
            printf("Fibonacci Search \n");
            FibonacciSearch(arr, arrSize);
            break;

            case 0:
            printf("Exiting...");
            x=1;
            break;

            default:
            printf("Invalid Input \n");
        }
    } while (x==0);
    
    return 0;
}

void Print(int *arr, int arrSize)
{
    printf("Array: ");
    for(int i=0 ; i<arrSize ; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void LinearSearch(int *arr, int arrSize)
{
    int value;
    printf("Enter value to be searched: ");
    scanf("%d" ,&value);

    for (int i=0 ; i<arrSize ; i++)
    {
        if (value==arr[i])
        {
            printf("Value found at index %d \n" ,i);
            return;
        }
    }
    printf("Value not found \n");
}

void InsertionSort(int *arr, int arrSize)
{
    int temp;
    for (int i=0 ; i<arrSize ; i++)
    {
        int key = arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void SelectionSort(int *arr, int arrSize)
{
    int temp;
    for (int i=0 ; i<arrSize ; i++)
    {
        int min = i;
        for (int j=i ; j<arrSize ; j++)
        {
            if (arr[min]>arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

void BubbleSort(int *arr, int arrSize)
{
    int temp;
    for (int i=0 ; i<arrSize ; i++)
    {
        for (int j=0 ; j<arrSize-1 ; j++)
        {
            if (arr[j+1]<arr[j])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void QuickSort(int *arr, int low, int high)
{
    if (low<high)
    {
        int pivot = partition(arr, low, high);

        QuickSort(arr, low, pivot-1);
        QuickSort(arr, pivot+1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    int j = low;
    int temp;
    for (j=low ; j<high ; j++)
    {
        if (arr[j]<pivot)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
        }
    }
    temp = arr[high];
    arr[high] = arr[i];
    arr[i] = temp;

    return i;
}

void MergeSort(int *arr, int low, int high)
{
    if (low<high)
    {
        int mid = (low+high)/2;

        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
}

void merge(int *arr, int low, int mid, int high)
{
    int i=low;
    int j=mid+1;
    int temp[high-low + 1];
    int k=0;  //index for temp
    while(i<=mid && j<=high)
    {
        if (arr[i]<arr[j])
        {
            temp[k] = arr[i];
            i++;
        }

        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i<=mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j<=high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i=low, k=0 ; i<=high ; i++, k++)
    {
        arr[i] = temp[k];
    }
}

void BinarySearch(int *arr, int arrSize)
{
    QuickSort(arr, 0, arrSize-1);
    int value;
    printf("Enter value to be serached: ");
    scanf("%d" ,&value);

    int mid;
    int lb = 0;
    int ub = arrSize-1;
    while (lb<ub)
    {
        mid = (lb+ub)/2;

        if (value==arr[mid])
        {
            printf("Value Found \n");
            return;
        }

        else if(value<arr[mid])
        {
            ub = mid-1;
        }

        else
        {
            lb = mid+1;
        }
    }
    printf("Value Not Found \n");
}

void FibonacciSearch(int *arr, int arrSize)
{
    int n = arrSize;

    QuickSort(arr, 0, arrSize-1);
    int key;
    printf("Enter value to be searched: ");
    scanf("%d" ,&key);

    int fib1 = 0;       
    int fib2 = 1;       
    int fib3 = fib1 + fib2;

    while (fib3 < n)
    {
        fib1 = fib2;
        fib2 = fib3;
        fib3 = fib1 + fib2;
    }

    int offset = -1;

    while (fib3 > 1)
    {
        int index;

        if (offset + fib1 < n)
            index = offset + fib1;
        else
            index = n - 1;
        
        if (arr[index] < key)
        {
            fib3 = fib2;
            fib2 = fib1;
            fib1 = fib3 - fib2;
            offset = index;
        }
        else if (arr[index] > key)
        {
            fib3 = fib1;
            fib2 = fib2 - fib1;
            fib1 = fib3 - fib2;
        }
        else
        {
            printf("Value Found \n");
            return;
        }
    }

    if (fib2 && offset + 1 < n && arr[offset + 1] == key)
    {
        printf("Value Found \n");
        return;
    }

    printf("Value Not Found \n");
}