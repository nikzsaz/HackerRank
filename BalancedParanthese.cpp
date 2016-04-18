#include <cmath>
#include <cstdio>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
    stack<char> mystack;
    int valid=1;
    int count1=0;
    int count2=0;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('||str[i]=='{'||str[i]=='['){
            count1++;
            mystack.push(str[i]);
        }else{
            if(!mystack.empty()){
            if(str[i]==')'||str[i]=='}'||str[i]==']'){
                char ch=mystack.top();
                if(ch=='('&& str[i]!=')' || ch=='{'&& str[i]!='}' || ch=='[' && str[i]!=']'){
                    valid=0;
                    break;
                }
            }
            count2++;
            mystack.pop();
        }
    }
    }
      //  cout<<valid<<"   ";
    if(valid==0){
        cout<<"NO"<<endl;
    }else{
        if(mystack.empty() && count1>0 && count2>0 && count1==count2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
   }
    return 0;
}
