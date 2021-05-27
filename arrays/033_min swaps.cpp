

//author :shreyamalogi

//Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

//2 pointer sliding window technique

#include<bits/stdc++.h>

using namespace std;

int func(int a[], int n, int k){
		//less than or equal to k
		int cnt=0;
		for(int i=0;i<n;i++)
		if (a[i]<=k)
		++cnt;  //count how many elements are less than k
		
		//find unwanted elements in current window of size cnt
		int bad=0;
		for(int i=0;i<cnt;i++)
		if(a[i]>k)
		++bad;
		
		//initialize ans with bad value of current window
		int ans=bad;
		for(int i=0,j=cnt;j<n;i++,j++) {  //i is left side of the window, j is right side
		
		//decrement cnt of prev window
		if(a[i]>k)
			--bad;
		
		//increment the cnt of the current window
		if(a[j]>k)
			++bad;
		
		//update ans if count of bad is less in ciurrent window
		ans=min(ans,bad);
	}
     return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int i,a[n];
		for(i=0;i<n;i++) cin>>a[i];
		cout<<func(a,n,k)<<endl;
	}
}

//2
//5
//3
//2 1 5 6 3
//1
//7
//6
//2 7 9 5 8 7 4
//2


