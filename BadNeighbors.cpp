#include <iostream>
#include <vector>

using namespace std;

class BadNeighbors{
	public:
		int maxDonations(vector<int> donations){
			int n = donations.size();
			int $max = 0;
			vector<int> dp(n,0);
			dp[0] = donations[0];
			for(int i = 2;i<n-1;++i){
				dp[i] = dp[i-1];
				for(int j = 0;j<i-1;++j){
					dp[i] = max(dp[i],dp[j]+donations[i]);
				}
			}
			$max = dp[n-2];
			dp.clear();
			dp.resize(n,0);
			dp[1] = donations[1];
			for(int i = 2;i<n;++i){
				dp[i] = dp[i-1];
				for(int j = 0;j<i-1;++j){
					dp[i] = max(dp[i],dp[j]+donations[i]);
				}
			}
			$max = max($max,dp[n-1]);
			return $max;
		}
};
