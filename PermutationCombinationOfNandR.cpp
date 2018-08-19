// Combination ... Permutation ... of N & R

#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::cout;

int arr[100], n, r, per[100][100], count;

void combination(int index, int data[], int i)
{
    if (index == r)
    {
        for (int j=0; j<r; j++)
        {
            per[count][j] = data[j];
            cout << data[j];
        }
        count++;
        cout << "\n";
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

int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

void swap(int index, int x, int y)
{
    int temp;
    temp = per[index][x];
    per[index][x] = per[index][y];
    per[index][y] = temp;
}

void permute(int index, int l, int r, int j)
{
    int i;

    if(l==r)
    {
        for(i=0; i<j; i++)
            cout << per[index][i];
        cout << "\n";
    }
    else
    {
        for(i=l; i<=r; i++)
        {
            swap(index, l, i);
            permute(index, l+1, r, j);
            swap(index, l, i);              // Backtracking
        }
    }
}

int main()
{
    int i, temp, temp2;
    count = 0;

    cin >> n >> r;

    for(i=0; i<n; i++)
        cin >> arr[i];

    temp = fact(n)/(fact(r)*fact(n-r));
    int per[temp][r];

    cout << "\nTotal Number of Combinations : " << temp << "\nCombinations ... \n";
    print();

    temp2 = fact(n)/fact(n-r);
    cout << "\n\nTotal Number of Permutations : " << temp2 << "\nPermutations ... \n";
    for(i=0; i<temp; i++)
    {
        permute(i, 0, r-1, r);
    }

    return 0;
}
