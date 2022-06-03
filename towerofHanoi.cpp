#include <bits/stdc++.h>
using namespace std;

int towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        return 1;
    }
    int count = 0;

    count += towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    count += 1;
    count += towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    return count;
}

int main () 
{
	int n; 
    cin >> n;
	cout << towerOfHanoi(n, 'A', 'B', 'C') ;

	return 0;
}