#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string& str){
    if(str.length()==1)
        if(str.compare("x")) return string(1,'1');
        else return string(1,'0');
    
    string ans="";
    int num1=0,pow1=1;
    int i=0;
    while(i<str.length()){
        char ch=str[i];
        if(ch=='x'){
            i+=2;
            char ch1=str[i];
            int num2=0;
            int pow2=1;
            while(i<str.length() && ch1>='0' && ch1<='9'){
                num2=num2*pow2+(ch1-'0');
                pow2*=10;
                i++;
                if(i==str.length()) break;
                ch1=str[i];
                
            }
            if(num2!=0){
                if(num1==0) num1=1;
            num1*=num2;
            num2-=1;
            ans+=to_string(num1)+"x^" + to_string(num2);
            }else{
                ans+=to_string(0);
            }
        }else if(ch=='+' || ch=='-'){
            ans+=ch; i++;
        }else{
            num1=0;
            pow1=1;
            while(i<str.length() && ch!='x'){
                num1=num1*pow1+(ch-'0');
                pow1*=10;
                i++;
                
                if(i==str.length()) break;
                ch=str[i];
            }
        }
    }
    
    return ans;
    
    
}


int main() {
    string str; cin>>str;
    cout<<solution(str);
    return 0;
}