#include <iostream>
using namespace std;

void Merge(int A[], int l, int mid, int h)
{
    int a = mid - l + 1;
    int b = h - mid;
    int L[a], R[b];

    for (int i = 0; i < a; i++)
    {
        L[i] = A[l + i];
    }

    for (int j = 0; j < b; j++)
    {
        R[j] = A[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < a && j < b)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < a)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < b)
    {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MS(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MS(A, l, mid);
        MS(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    int n;
    cin >> n;

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    MS(A, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;

    return 0;
}
