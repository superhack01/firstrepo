#include<iostream>
#include<string>
#include<cmath>
#include<stack>

#define ll long long

using namespace std;

int solve(string s){
    stack<int> st;

    for (int i = s.length()-1;i>=0;i--){
        if (s[i] >= '0' && s[i] <= '9'){
            st.push(s[i]-'0');
        }
        else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
            }
        }
    }

    return st.top();
}

/*
////postfix Evaluation 
int solve(string s){
    stack<int> st;

    for (int i = 0;i<s.length();i++){
        if (s[i] >= '0' && s[i] <= '9'){
            st.push(s[i]-'0');
        }
        else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
            }
        }
    }

    return st.top();
}
*/

int main () {
    string s;
    cin>>s;

    cout<<solve(s)<<endl;
    return 0;
}