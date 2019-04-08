// nhap vao mot day khong doi xung 
// mod day do cho 1 so sao cho day do thành doi xung
#include<iostream>
#include<cmath>
using namespace std;

int UCLN (int a, int b) {
	return b == 0?a:UCLN(b,a%b);
}
int main() {
	
	int n;
	int a[100000];
	cin >> n;
	// Nhap mang
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}	
	for (int i=0;i< n/2; i++) {
		a[i] = abs(a[n-i-1] - a[i]);
	}
	int flag = 0;
	for(int i=0; i<n/2; i++) {
		if(a[i] != 0) flag = 1;
	}
	if(flag == 0) {
		cout << "-1";
		return 0;
	}
	// tim ucln cua day
	int k = a[0];

	for (int i = 1; i < n/2; i++) {
		k = UCLN(k, a[i]);
	}
	cout << k;
	return 0;
}
