#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class FlowerGarden {
	private:
		vector<bool> used;
		unsigned int count;
		bool isPlaceableAtFront(int index ,vector<int>& height, vector<int>& bloom, vector<int>& wilt){
			for(unsigned int i = 0 ;i<height.size();++i){
				if(i == index || used[i]){
					continue;
				}
				if(((bloom[index] >= bloom[i] && bloom[index] <= wilt[i]) || (wilt[index] >= bloom[i] && bloom[index] <= wilt[i])) && height[index] > height[i]){
					return false;
				}
			}	
			return true;
		}
		int getMaxPlaceableHeight(vector<int>& height, vector<int>& bloom, vector<int>& wilt){
			int maxindex = -1;
			int maxheight = 0;
			for(unsigned int i = 0;i<height.size();++i){
				if(used[i]){
					continue;
				}
				if(isPlaceableAtFront(i,height,bloom,wilt)){
					if(maxheight<height[i]){
						maxheight = height[i];
						maxindex = i;
					}
				}
			}
			used[maxindex] = true;
			count++;
			return height[maxindex];
		}
	public:
		FlowerGarden():count(0){}
		vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) {
			vector<int> ans;
			used.resize(height.size(),false);
			while(count<height.size()){
				int h = getMaxPlaceableHeight(height,bloom,wilt);
				ans.push_back(h);
			}
			return ans;
		}
};
