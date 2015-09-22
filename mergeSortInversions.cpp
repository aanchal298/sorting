#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long long long
#define ii pair<int,int>

#define mod 1000000007
#define inf 999999999

using namespace std;

inline void inp(long long &n ) {//fast input function
	n=0;
	long long ch=getchar(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
	n=n*sign;
}

long long t,n,A[100001],B[100001];

long long ans(long long i,long long j) {
	if(i==j)
		return 0;
	if(i+1==j) {
		if(A[i]>A[j]) {
			swap(A[i],A[j]);
			return 1;
		}
		return 0;
	}
	long long mid=(i+j)/2;
	long long ret=ans(i,mid)+ans(mid+1,j);
	// cout<<ret<<endl;

	long long a=i,b=mid+1;
	long long ind=a;
	while(a<=mid && b<=j) {
		// cout<<" "<<a<<" "<<b<<" "<<A[a]<<" "<<
		if(A[a]<=A[b]) {
			B[ind++]=A[a++];
		}
		else {
			B[ind++]=A[b++];
			ret+=mid+1-a;
			// cout<<ret<<" "<<a<<" "<<mid<<" "<<b<<endl;
		}
	}
	// cout<<ret<<endl;
	while(b<=j) {
		B[ind++]=A[b++];
	}
	while(a<=mid) {
		B[ind++]=A[a++];
	}
	for(long long a=i;a<=j;a++)
		A[a]=B[a];
	// cout<<i<<" "<<j<<" "<<ret<<endl;
	return ret;
}
 int main() {

	long long n = 100000;
		for(long long i=0;i<n;i++)
			inp(A[i]);
		printf("%lld\n", ans(0,n-1));

	return 0;
}
