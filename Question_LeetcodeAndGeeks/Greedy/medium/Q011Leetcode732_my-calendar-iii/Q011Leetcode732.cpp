// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

static const auto magic = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class MyCalendarThree {
public:
    map<int,int> bst;
     MyCalendarThree() {
        bst.clear();
    }
    
     int book(int start, int end) {
        bst[start]++;
        bst[end]--;
        
        int count=0,res=0;
        for(auto ele: bst){
            count += ele.second;
            res=max(count,res);
        }
        return res;
    }
};


