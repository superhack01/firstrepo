#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

#define ll long long

using namespace std;

int main () {
    int n;
    cin>>n;
    pair<int,string> * p = new pair<int, string>[n];
    cout<<"Score : "<<"StudentName "<<endl;
    for (int i = 0;i<n;i++){
        int score;
        string name;
        cin>>score;
        cin>>name;
        p[i] = {score,name};
    }
    int totalMarks;
    cout<<"Enter the Total Marks : ";
    cin>>totalMarks;

    sort(p,p+n);
    reverse(p,p+n);
    cout<<endl;

    cout<<"All Student List :- "<<endl;
    cout<<"Score : "<<" StudentName "<<endl;
    for (int i=0;i<n;i++){
        cout<<p[i].first<<" : "<<p[i].second<<endl;
    }
    cout<<endl;
    // cout<<"Qualified Students : - \n";

    // for (int i =0;i<6;i++){
    //     if (p[i].first > 250){
    //         cout<<p[i].first<<" "<<p[i].second<<endl;
    //     }
    // }
     
    cout<<"Congratulations, Rankers !"<<endl;
    cout<<"Score : "<<" StudentName : "<<" Presentage "<<endl;
    if (n<3){
        for (int i=0;i<n;i++){
            cout<<(i+1)<<". ";
            cout<<p[i].first<<" : "<<p[i].second<<" : ";
            float presentage = ((float)p[i].first / (float)totalMarks) * 100;
            cout<<presentage<<"%"<<endl;
        }
        cout<<endl;
    }
    else {
        for (int i=0;i<3;i++){
                cout<<(i+1)<<". ";
                cout<<p[i].first<<" : "<<p[i].second<<" : ";
                float presentage = ((float)p[i].first / (float)totalMarks) * 100;
                cout<<presentage<<"%"<<endl;
        }
    }
    // pair<int,string>p;
    // p = {250,"john"};

    // cout<<p.first<<" "<<p.second<<endl;


    return 0;
}
