#include <vector>
#include <iostream>

using namespace std;

int longestZigZag(vector<int> a){
	int n = a.size();
	int ans = 0;
	vector<int> dp,dp2;
	dp.resize(n,1);
	dp2.resize(n,0);
	for(int i = 0;i<n;++i){
		for(int j = 0;j<i;++j){
			if(dp[j]==1 || (a[i]-a[j])*dp2[j]<0){
				if(dp[j] + 1 >= dp[i]){
					dp[i] = dp[j] + 1;
					dp2[i] = (a[i]-a[j]<0)?-1:1; 
				} 	
			}
		}	
	}
	for(int i = 0;i<n;++i){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	for(int i = 0;i<n;++i){
		ans = max(ans,dp[i]);
	}
	return ans;
}

int main(){
	vector<int> v = {374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 
	600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 
	67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 
	477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 
	249, 22, 176, 279, 23, 22, 617, 462, 459, 244} ;
	cout<<longestZigZag(v)<<endl;
	return 0;
}
