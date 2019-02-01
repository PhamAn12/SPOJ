/* hoan vi ke tiep
	tìm ra so hoan vi cua input ke tiep 
	sô da cho
	vi du : 123 -> 132
			987 -> BIGGEST
			
*/

#include <bits/stdc++.h>
using namespace std;
 
main(){
	long long t;
	cin>>t;
	while(t>0){
		long long stt;
		cin>>stt;
		string a;
		cin>>a;
		bool kt=false;
		long long i=a.size()-2;
		while(a[i]>=a[i+1]&&i>=0){
			i--;
		}
		if(i>=0){
			long long k=a.size()-1;
			while(a[i]>=a[k]){
				k--;
			}
			swap(a[i],a[k]);
			long long l=i+1;
			long long r=a.size()-1;
			while(l<r){
				swap(a[l],a[r]);
				l++;
				r--;
			}
		}else kt=true;
		if(kt){
			cout<<stt<<" BIGGEST"<<endl;
		}else {
			cout<<stt<<" "<<a<<endl;
		}
		t--;
	}
}
