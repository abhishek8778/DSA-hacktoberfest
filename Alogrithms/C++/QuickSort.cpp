#include <iostream>
using namespace std;

// function that swaps elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function that prints the array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// function to rearrange array
int partition(int array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main()
{
    int data[] = {8, 7, 6, 1, 0, 9, 2};
    int n = sizeof(data) / sizeof(data[0]);

    cout << "Unsorted Array: \n";
    printArray(data, n);
    quickSort(data, 0, n - 1);

    cout << "Sorted array in ascending order: \n";
    printArray(data, n);
}