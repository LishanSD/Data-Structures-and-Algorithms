#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int index = 1; index < size; ++index)
    {
        int keyValue = arr[index];
        int j = index - 1;

        // Shift elements to make space for the key
        while (j >= 0 && arr[j] > keyValue)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        // Place key in correct position
        arr[j + 1] = keyValue;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int sz;
    cout << "Enter the size of array::";
    cin >> sz;

    int arr[sz];

    for (int i = 0; i < sz; i++)
    {
        cout << "Enter the value " << i + 1 << " : ";
        cin >> arr[i];
    }

    for (int i = 0; i < sz; i++)
    {
        float m;
        int tempArr[i + 1];
        for (int j = 0; j < i + 1; j++)
        {
            tempArr[j] = arr[j];
        }

        insertionSort(tempArr, i + 1);

        if ((i + 1) % 2 == 0)
        {
            m = float(tempArr[(i + 1) / 2] + tempArr[(i - 1) / 2]) / 2;
        }
        else
        {
            m = tempArr[i / 2];
        }

        printArray(tempArr, i + 1);
        cout << "median : " << fixed << setprecision(1) << m << endl;
        cout << "\n";
    }
    return 0;
}
