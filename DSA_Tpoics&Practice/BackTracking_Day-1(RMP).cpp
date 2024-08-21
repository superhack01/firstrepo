#include<iostream>
#include<vector>
#include<string>

#define ll long long 

using namespace std;

bool isSafe(vector<vector<int>> &arr, vector<vector<bool>> &visited,int n,int newx, int newy){
    if ((newx>=0 && newx<n) && (newy>=0 && newy<n) && arr[newx][newy] == 1 && visited[newx][newy] == 0){
        return true;
    }
    else return false;
}


void solution(vector<vector<int>> &arr, vector<vector<bool>> &visited,int n,vector<string> &ans, int x, int y, string path){
    //base condition 
    if (x == n-1 && y == n-1){
        ans.push_back(path);
        return ;
    }

    ///four movments - D,L,R,U(sorted order)

    //The very first step in any condition is to mark the visited 
    visited[x][y] = 1;

    //for D 
    if (isSafe(arr,visited,n,x+1,y)){
        solution(arr,visited,n,ans,x+1,y,path+'D');
    }
    //for L 
    if (isSafe(arr,visited,n,x,y-1)){
        solution(arr,visited,n,ans,x,y-1,path+'L');
    }
    //for R 
    if (isSafe(arr,visited,n,x,y+1)){
        solution(arr,visited,n,ans,x,y+1,path+'R');
    }
    //for U
    if (isSafe(arr,visited,n,x-1,y)){
        solution(arr,visited,n,ans,x-1,y,path+'U');
    }

    //Mark unvisited the grid at the backtracking time 
    visited[x][y] = 0;

}


int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr;
    for (int i = 0;i<n;i++){
        vector<int> temp;
        for (int j = 0;j<m;j++){
            int num;
            cin>>num;

            temp.push_back(num);
        }
        arr.push_back(temp);
        temp.clear();
    }

    // for (auto i : arr){
    //     for (auto j : i){
    //         cout<<j<<" ";
    //     }cout<<endl;
    // }

    vector<vector<bool>> visited(n,vector<bool> (n,0));

    vector<string> ans;

    solution(arr,visited,n,ans,0,0,"");

    for (auto i : ans){
        cout<<i<<endl;
    }

    return 0;
}