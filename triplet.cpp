#include <bits/stdc++.h> 
using namespace std; 
void product(int n) { 
	for (long long i = 1; i <= n / 3; i++){ 
		for (long long j = i + 1; j<=n/2 ; j++){ 
			long long k = n - i - j; 
			if (i * i + j * j == k * k){ 
				cout << i*j*k; 
				return; 
			} 
		} 
	} 
	cout << "No Triplet for this sum"; 
} 
int main() { 
	int n;
    cin>>n;
	product(n); 
	return 0; 
}
 
// input 
// 1000
// output
// ==========
// 31875000
