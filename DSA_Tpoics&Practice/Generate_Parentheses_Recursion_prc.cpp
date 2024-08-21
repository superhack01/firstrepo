#include<iostream>
#include<vector>
#include<stack>

using namespace std;

#define IN_RANGE(number, start, end) (((number >= start) && (number <= end)) ? (true) : (false))

void solution(int k,string s,vector<string> &ans){
    if (s.length() == (2*k)){
        ans.push_back(s);
        return ;
    }

    solution(k,s+"(",ans);

    solution(k,s+")",ans);

    return ;
}

int main (){
    int k;
    cin>>k;

    vector<string>ans;
    solution(k,"(",ans);

    cout<<ans.size()<<endl;
    for (auto i : ans ){
        // cout<<i<<endl;
        stack<char> st;

        bool found = true;
        for (int j = 0;j<i.length();j++){
            if (i[j] == '('){
                st.push(i[j]);
            }
            else if (!st.empty()){
                st.pop();
            }
            else {
                found = false;
                break;
            }
        }
        if (st.empty() && found){
            cout<<i<<endl;
        }
        else continue;   
        
    }cout<<endl;

    return 0;
}