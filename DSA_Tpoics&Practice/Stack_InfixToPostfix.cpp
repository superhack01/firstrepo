#include<iostream>
#include<string>
#include<cmath>
#include<stack>

#define ll long long

using namespace std;

int precedance(char ch){
	if (ch == '^') return 3;
	else if ((ch == '*') || (ch == '/')) return 2;
	else if ((ch == '+') || (ch == '-')) return 1;
	else return -1;
}

string infixToPostfix(string s){
	stack<char> st;
	string res = "";

	for (int i = 0;i<s.length();i++){
		if ((s[i] >= 'a' && s[i] <='z') || (s[i] >= 'A' && s[i] <= 'Z')){
			res += s[i];
		}
		else if (s[i] == '('){
			st.push(s[i]);
		}
		else if (s[i] == ')'){
			while(!st.empty() && st.top() != '('){
				res += st.top();
				st.pop();
			}
			if (!st.empty()){
				st.pop();
			}
		}
		else {
			while(!st.empty() &&  (precedance(st.top()) > precedance(s[i]))){
				res += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}

	while(!st.empty()){
		res += st.top();
		st.pop();
	}

	return res;
}


int main () {
	string str;
	cin>>str;

	cout<<infixToPostfix(str)<<endl;
	return 0;
}