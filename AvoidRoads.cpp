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
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class AvoidRoads {
	public:
		long long numWays(int width, int height, vector<string> bad) {
			width++;
			height++;
			long long dp[width][height];
			int b[width][height];
			memset(dp,0,sizeof(long long)*width*height);
			memset(b,0,sizeof(int)*width*height);
			dp[0][0] = 1;
			for(unsigned int i = 0;i<bad.size();++i){
				stringstream ss(bad[i]);
				int x1,y1,x2,y2;
				ss>>x1>>y1>>x2>>y2;
				if(x1==x2){
					if(b[x2][max(y1,y2)]!=1){
						b[x2][max(y1,y2)] += 1;	
					}	
				}
				else{
					if(b[max(x1,x2)][y2]!=2){
						b[max(x1,x2)][y2] += 2;	
					}
				}
			}
			for(int i = 0;i<width;++i){
				for(int j = 0;j<height;++j){
					if(b[i][j]<3){
						if(b[i][j]!=1){
							dp[i][j] += (j>0)?dp[i][j-1]:0;
						}
						if(b[i][j]!=2){
							dp[i][j] += (i>0)?dp[i-1][j]:0;
						}
					}
				}
			}
			return dp[width-1][height-1];
		}
};



double test0() {
	int p0 = 6;
	int p1 = 6;
	string t2[] = {"0 0 0 1","6 6 5 6"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 252LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 1;
	int p1 = 1;
	vector <string> p2;
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 2LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 35;
	int p1 = 31;
	vector <string> p2;
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 6406484391866534976LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 2;
	int p1 = 2;
	string t2[] = {"0 0 1 0", "1 2 2 2", "1 1 2 1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int p0 = 100;
	int p1 = 100;
	string t2[] = {"0 0 1 0", "0 0 0 1", "0 1 0 0"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test5() {
	int p0 = 24;
	int p1 = 24;
	string t2[] = {"5 17 6 17", "13 21 13 20", "8 3 9 3", "7 1 7 2", "15 19 16 19", "24 22 23 22", "16 3 16 4", "21 9 20 9", "21 22 21 21", "18 15 18 16", "24 1 24 2", "11 5 10 5", "21 13 21 14", "2 18 1 18", "13 19 12 19", "20 18 20 19", "13 15 12 15", "15 21 16 21", "15 3 15 2", "18 18 18 19", "21 4 21 5", "5 4 5 3", "10 17 10 16", "19 3 20 3", "16 4 15 4", "3 19 2 19", "16 21 16 20", "21 1 21 0", "10 6 10 5", "15 2 16 2", "23 5 22 5", "16 17 15 17", "7 9 8 9", "22 18 23 18", "3 18 4 18", "6 10 7 10", "14 14 15 14", "1 6 0 6", "5 12 4 12", "11 15 11 14", "19 9 18 9", "9 18 9 19", "21 17 22 17", "14 19 13 19", "23 22 23 21", "21 13 21 12", "9 24 10 24", "19 19 19 20", "22 6 22 7", "18 7 19 7"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	AvoidRoads * obj = new AvoidRoads();
	clock_t start = clock();
	long long my_answer = obj->numWays(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 2892656907907LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}


int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test4();
	if (time < 0){
		errors = true;
	}

	time = test5();
	if (time < 0){
		errors = true;
	}

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

