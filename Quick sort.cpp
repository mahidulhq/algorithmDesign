#include <iostream>
#include <vector>
using namespace std;


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    int n;
    cout << "Enter the number of elements: " <<endl ;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: " << endl ;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: " << endl ;
    for (int x : arr)
    cout << x << " " ;

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: " << endl ;
    for (int x : arr)
    cout << x << " ";

    return 0;
}
