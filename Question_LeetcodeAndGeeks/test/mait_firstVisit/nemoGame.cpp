#include <iostream>
using namespace std;

int binaryToOctal(int num)
{
    int decimalNum = 0;
    int pow=1;
    while (num != 0)
    {
        int rem = num % 10;
        num /= 10;
        
        decimalNum+=rem*pow;
        pow=pow*2;
    }


   int res=0;
   pow=1;
    while(decimalNum!=0){
       int rem=decimalNum%8;
       decimalNum/=8;

       res+=rem*pow;
       pow=pow*10;
    }
    return res;
}

int octalDiff(int num1,int num2){
    bool flag = num2 > num1 ? true:false;
    if(flag) swap(num1,num2);

    int pow=1;
    int res=0;
    int borrow=0;
    while(num1!=0 || num2!=0 || borrow!=0){
        int rem=num1%10-num2%10+borrow;
        num1/=10;
        num2/=10;

        if(rem<0){
            rem+=8;
            borrow=-1;
        }else{
            borrow=0;
        }

        rem%=8;
        res+=rem*pow;
        pow*=10;
    }
    return res;

}

int main(int args, char **argv)
{
    int octal,binary,k;
    cin>>octal>>binary>>k;

    int o2=binaryToOctal(binary);
    bool res=octalDiff(octal,o2)>=k;
    cout<<(res?"john":"ceen")<<endl;
}