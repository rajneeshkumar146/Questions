// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

long long subCount(long long arr[], int N, long long k)
	{
	    unordered_map<long long, long long> map;
	    map[0] = 1;
	    long long  count = 0;
	    long long  sum = 0;
	    for(int i=0;i<N;i++){
	        int ele = arr[i];
	        sum += ele;
	        count += map[(sum % k + k)%k];
	        map[(sum % k + k)%k]++;
	    }
	    
	    return count;
	}