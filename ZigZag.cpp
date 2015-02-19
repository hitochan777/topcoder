#include <vector>
#include <iostream>

using namespace std;

class ZigZag{
	public:
		int longestZigZag(vector<int> sequence){
			int n = sequence.size();
			int ans = 0;
			vector<int> dp,dp2;
			dp.resize(n,1);
			dp2.resize(n,0);
			for(int i = 0;i<n;++i){
				for(int j = 0;j<i;++j){
					if(sequence[i]==sequence[j]){
						continue;
					}
					if(dp[j]==1 || (sequence[i]-sequence[j])*dp2[j]<0){
						if(dp[j] + 1 >= dp[i]){
							dp[i] = dp[j] + 1;
							dp2[i] = (sequence[i]-sequence[j]<0)?-1:1; 
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
};

int main(){
	return 0;
}
