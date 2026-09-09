//Program to implement insertion sort
#include <iostream>
using namespace std;

int main()
{
    int arr[100];
    int n, min, temp;
    printf("Enter length of array: ");
    scanf("%d" ,&n);

    cout<<"Enter "<<n<<" elements of the array: "<<endl;
    for (int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    //sorting by insertion sort
    for (int i=1 ; i<n ; i++)
    {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }

    cout<<"Sorted array: "<<endl;
    for (int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//insertion --> uses key