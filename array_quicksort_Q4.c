/*Short the array by
c.	Quick sort*/
#include <stdio.h>

void quicksort(int [], int, int);
int partition(int [], int, int);
void print(int[]);
int n;

int main()
{
    int arr[100];
    printf("Enter no. of elements in the array: ");
    scanf("%d" ,&n);
    printf("Enter the %d elements of the array: " ,n);
    for (int i=0 ; i<n ; i++)
    {
        scanf("%d" ,&arr[i]);
    }

    quicksort(arr, 0, n-1);
    //where arr is array being passed, 0 is starting index, n-1 is ending index

    print(arr);
    return 0;
}

void quicksort(int a[], int start, int end)
{
    if (end<=start)
    {
        return;
        //instead of,
        //printf("The ending index is lesser than or equal to the starting index \n");
    }
    else
    {
        int pivot = partition(a, start, end);
        quicksort (a, start, pivot-1);
        quicksort (a, pivot+1, end);
    }
}

int partition(int b[], int first, int last)
{
    int pivot = b[last];
    int i = first-1;
    int temp;

    for (int j=first ; j<last ; j++)
    {
        if (b[j] < pivot)
        {
            i++;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }

    i++;
    temp = b[i];
    b[i] = b[last];  //to change array, not just value of pivot
    b[last] = temp;

    return i;
}

void print (int x[])
{   
    printf("Sorted array by quick sort: \n");

    for (int i=0 ; i<n ; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");   
}