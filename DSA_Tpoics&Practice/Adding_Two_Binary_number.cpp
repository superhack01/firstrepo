#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int reverse(int ans){
  int final = 0;
  while (ans>0){
      int i = ans%10;
      final = final*10 + i;
      ans /= 10;
  }

  return final;
}
int addBinary(int a,int b){
  int ans = 0;
  int pastcarry = 0;
  while ((a>0)&&(b>0)){
      int i = a % 10;
      int j = b % 10;
      if ((i==0)&&(j==0)){
          if (pastcarry==0){
            ans = ans*10 + 0;
            pastcarry = 0;
          }
          else {
            ans = ans*10 + 1;
            pastcarry = 0;
          }
      }
      else if (((i==0)&&(j==1))||((i==1)&&(j==0))){
        if (pastcarry==0){
          ans = ans*10 + 1;
          pastcarry = 0;
        }
        else {
          ans = ans*10 + 0;
          pastcarry = 1;
        }

      }
      else {
        if (pastcarry==0){
          ans = ans*10 + 0;
          pastcarry = 1;
        }
        else {
          ans = ans*10 + 1;
          pastcarry = 1;
        }
      }

      a /= 10;
      b /= 10;
  }

  while (a>0){
    if (pastcarry==1){
      if ((a%2)==0){
          ans = ans*10 + 1;
          pastcarry = 0;
      }
      else {
        ans = ans*10 + 0;
        pastcarry = 1;
      }
    }
    else {
      ans = ans*10 + (a%10);
      pastcarry = 0;
    }

    a /= 10;
  }
  while (b>0){
  if (pastcarry==1){
    if ((b%2)==0){
        ans = ans*10 + 1;
        pastcarry = 0;
    }
    else {
      ans = ans*10 + 0;
      pastcarry = 1;
    }
  }
  else {
    ans = ans*10 + (a%10);
    pastcarry = 0;
  }

  b /= 10;
  }
  
  if (pastcarry==1){
    ans = ans*10 + 1;
  }

  ans = reverse(ans);

  return ans;
}

int main (){
  int n,m;
  cin>>n>>m;
  cout<<addBinary(n,m)<<endl;

  return 0;
} 

 