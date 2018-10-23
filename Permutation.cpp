TYPE 1 ...
// Permutation ...
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string word = "anyword";
	sort(word.begin(), word.end());
	
	int i=1;

	do{
			cout << i << ". " << word << "\n";
			i++;
	}while(next_permutation(word.begin(), word.end()));

}




TYPE 2 ...
// Permutation ...
#include<bits/stdc++.h>
using namespace std;

int arr[10];
int n;

void swap(int x, int y)
{
    int temp;
    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void permute(int l, int r)
{
    int i;

    if(l==r)
    {
        for(i=0; i<n; i++)
            cout << arr[i];
        cout << endl;
    }
    else
    {
        for(i=l; i<=r; i++)
        {
            swap(l, i);
            permute(l+1, r);
            swap(l, i);
        }
    }
}

int main()
{
    int i;

    cin >> n;

    for(i=0; i<n; i++)
        cin >> arr[i];

    cout << "\nList of Permutations ..." << endl;
    permute(0, n-1);

    return 0;
}
