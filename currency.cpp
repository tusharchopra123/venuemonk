#include<bits/stdc++.h>
using namespace std;
int count( int coins[], int size, int amount) { 
	int dp[amount+1]; 
	memset(dp, 0, sizeof(dp)); 
	dp[0] = 1; 
	for(int i=0; i<size; i++) 
		for(int j = coins[i]; j<=amount ; j++) 
			dp[j] += dp[j-coins[i]]; 
	return dp[amount]; 
} 
int main(){ 
    int n;
    cin>>n;
    int* coins = new int[n];
    for(int i=0;i<n;i++)cin>>coins[i]; 
    int amount;
    cin>>amount;
    cout << count(coins, n, amount); 
    return 0; 
} 
//input 
// 8
// 10 20 50 100 200 500 1000 2000
// 2000
// ==========
// output
// ==========
// 73682
