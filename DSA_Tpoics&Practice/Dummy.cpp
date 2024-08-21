#include<iostream>
#include<string>
#include<cmath>
#include<stack>

#define ll long long

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        stack<char> st;

        for (int i = 0;i<s.length();i++){
            if (s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
            }
            else if (s[i] == ')'){
                while(!st.empty()){
                    if (st.top() != '('){
                        st.pop();
                    }
                    else {
                        st.pop();
                        break;
                    }
                }
            }
        }
    }
}