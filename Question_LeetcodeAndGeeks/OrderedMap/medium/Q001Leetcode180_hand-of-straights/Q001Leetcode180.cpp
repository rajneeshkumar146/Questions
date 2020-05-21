// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

#define vi vector<int>
#define vii vector<vi>

using namespace std;

auto speedUp = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> tree;
        for(int& ele: hand) tree[ele]++;
        
        while(tree.size()>0){
            int val=tree.begin()->first;
            for(int count=1;count<=W;count++){
                if(tree.count(val)){
                    tree[val]--;
                    if(tree[val]==0)tree.erase(val);
                    val++;
                }else return false;
            }
        }
      return true;
    }