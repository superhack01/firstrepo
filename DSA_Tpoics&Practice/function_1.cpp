#include<iostream>
#include<cmath>

using namespace std;

int prime(int i){
  int j,x;
  for (j=2;j<i;j++){
    if ((i%j)==0){
      x = 1;
      break;
    }
    else
      x = 0;
  }
  if (x==0){
    cout<<i<<endl;
  }

  return 0;
}

int main (){
  int n,m;
  cout<<"Enter the numbers n : ";
  cin>>n>>m;
  int i;
  for (i=n;i<m;i++){
    prime(i);
    
  }

  return 0;
}

