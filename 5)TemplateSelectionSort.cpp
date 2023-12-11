//Name:Piyush Manoj Jain||Roll no:36||Div:SE-A
//Problem Statement: Implement a function template for selection sort.Write a program that inputs,
//sorts and outputs an intger array and a float array
#include <iostream>
using namespace std;

template <typename T>
void sort_array(T arr[], int n)
{
    cout<<"The array before selection sort:";
    for(int i=0; i<n; i++)
    {
        cout<<"  "<<arr[i];
    }

    T temp;
    for (int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    cout<<"\nThe array  after selection sort:";
    for(int i=0; i<n; i++)
    {
        cout<<"  "<<arr[i];
    }
}

int main()
{
    int arr_size,value;
    cout<<"\t***Integer array selection sort***\n";
    cout<<"\nEnter the total number in the array: ";
    cin>>arr_size;
    int arr_int[arr_size];

    cout<<"\t---Enter the values one by one---\n";
    for(int i=0; i<arr_size; i++)
    {
        cin>>value;
        arr_int[i]=value;
    }

    sort_array(arr_int, arr_size);


    float f_value;
    cout<<"\t\n\n\n***float array selection sort***\n";
    cout<<"\nEnter the total number in the array: ";
    cin>>arr_size;
    float arr_flt[arr_size];

    cout<<"\t---Enter the values one by one---\n";
    for(int i=0; i<arr_size; i++)
    {
        cin>>f_value;
        arr_flt[i]=f_value;
    }

    sort_array(arr_flt, arr_size);

return 0;
}
