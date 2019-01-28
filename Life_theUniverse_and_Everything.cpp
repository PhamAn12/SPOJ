/* Nhap cac so lien tuc gap 42 thi dung
input: 1 2 3 33 11 42 
output : 1 2 3 33 11
*/
#include<iostream>
#include<vector>
//#include
using namespace std;

int main()
{
	int x=0,i=0;
	vector <int>a;
	while(x!=42)
	{
		cin>>x;
		// dua x vao vector
		a.push_back(x);
	}
	// xoa gia tri 42 khoi vector
	a.pop_back();
	int l=a.size();
	for(i=0;i<l;i++)
	cout<<a[i]<<"\n";
}
