/* Su dung thuat toan quy hoach dong
	tim do dai xau con chung dai nhat trong 2 chuoi
	B1: gan a[i][j] = {0}
	B2: Lap bang
	B3: chon phan tu a[l1][l2]
*/
#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],i,j;
int main(){
	string s1,s2;
	cin >> s1 >> s2;
	int l1=s1.length(), l2=s2.length();
	for(i=0; i<l1; i++){
		a[i][0]=0;
	}
	for(i=0; i<l2; i++){
		a[0][i]=0;
	}
	for(i=0; i<l1; i++){
		for(j=0; j<l2; j++){
			if(s1[i]==s2[j]){
				a[i+1][j+1]=a[i][j]+1;
			}
			else{
				a[i+1][j+1]=max(a[i+1][j], a[i][j+1]);
			}
		}
	}
	cout << a[l1][l2];
	/*
	for(i=0; i<=l1; i++){
		for(j=0; j<=l2; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}
