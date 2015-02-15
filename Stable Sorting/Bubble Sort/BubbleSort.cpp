#include <iostream>
#include <vector> 

using namespace std;
 
int data[] = {3, 2, 6, 5, 4, 1, 10, 8, 9, 7};

int data2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//vector<int> dataToSort (data, data + sizeof(data) / sizeof(int));


bool isSorted(int* d)
{
    for (int i = 0; i < sizeof(d) - 1; i++)
    {
        if (d[i] > d[i+1])
            return false;
    }
    return true;
}

int* bubbleSort(int* arrayToSort)
{
    if (isSorted(arrayToSort))
    {
        return arrayToSort;
    }
    else
    {
        for (int i = 0; i < sizeof(arrayToSort); i++)
        {
            if (arrayToSort[i] > arrayToSort[i+1])
            {
                int temp = arrayToSort[i+1];
                arrayToSort[i+1] = arrayToSort[i];
                arrayToSort[i] = temp;
            }
        }
        return bubbleSort(arrayToSort);
    }
}

void printArray(int* array)
{
    for (int i = 0; i < sizeof(array); i++)
        cout << array[i] << " ";
}

int main()
{
    printArray(data);

    bubbleSort(data);

    if (isSorted(data))
        cout << "\nsorted\n";
    else
        cout << "not sorted\n";

    printArray(data);
}