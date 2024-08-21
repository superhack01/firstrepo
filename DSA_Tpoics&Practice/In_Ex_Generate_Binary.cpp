#include<iostream>
#include<vector>

using namespace std;

#define IN_RANGE(number, start, end) (((number >= start) && (number <= end)) ? (true) : (false))

void solution(int k,string s, vector<string> &ans){
    if (s.length() == k){
        ans.push_back(s);
        return ;
    }

    string a = s + "0";
    solution(k,s+"0",ans);

    string b = s + "1";
    solution(k,s+"1",ans);

    return ;
}

int main (){
    int k;
    cin>>k;

    vector<string>ans;
    solution(k,"",ans);

    for (auto i : ans ){
        // cout<<i<<" ";
        if (IN_RANGE(i.find("11"),0,k)){
            continue;
        }
        else cout<<i<<" ";
        
    }cout<<endl;

    return 0;
}