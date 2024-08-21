#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>

using namespace std;

//to make a graph generic we use template typename
template <typename T>

class graph{
    public:
     unordered_map<T,list<T>> adj;//we can use vector also for listing

     void addgraph(T a,T b, bool dir){

        adj[a].push_back(b);

        //for undirectional graph
        if (dir == 0){
            adj[b].push_back(a);
        }
     }

     void displaygraph(){
        for (auto i : adj){
            cout<<i.first<<" ->";
            for (auto j : i.second){
                cout<<j<<",";
            }cout<<endl;
        }
     }
};

int main(){
    //beacause we use template typename so we have to define type of data here 
    //we can define any type of data like char,int,float etc;
    graph <int> g;

    int n,m;
    cin>>n>>m;//number of nodes and number of edges

    for (int i = 0;i<m;i++){
        int x,y;
        cin>>x>>y;

        g.addgraph(x,y,0);//0 for undirectional graph
    }

    g.displaygraph();

    return 0;
}