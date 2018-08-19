// Combination ...

#include<bits/stdc++.h>

using namespace std;

int arr[100], n, r;

void combination(int index, int data[], int i)
{
    if (index == r)
    {
        for (int j=0; j<r; j++)
            cout << data[j];
        cout << endl;
        return;
    }
 
    if (i >= n)
        return;
 
    data[index] = arr[i];

    combination(index+1, data, i+1);
    combination(index, data, i+1);
}

void print()
{
    int data[r];
    combination(0, data, 0);
}

int main()
{
	int i;

    cin >> n >> r;

    for(i=0; i<n; i++)
        cin >> arr[i];

    cout << "\nList of Combinations ..." << endl;
    print();

    return 0;
}
