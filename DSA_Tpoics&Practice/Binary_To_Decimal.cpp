#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int binariToDecimal (int n){
  int ans = 0;
  int x = 1;
  while (n>0){
    int y = n % 10;
    ans += x*y;
    x *= 2;
    n /= 10;

  }

  return ans;
}

int OctalTodecimal(int n){
  int ans = 0;
  int x = 1;
  while(n>0){
    int y = n % 10;
    ans += x*y;
    x *=8 ;
    n /= 10;
    
  }

  return ans;
}

int hexaTodecimal (string n){
  int ans = 0;
  int x = 1;

  int s = n.size();
  for (int i=s-1;i>=0;i--){
    if (n[i]>='0' && n[i]<='9'){
      ans += x*(n[i]-'0');
    }
    else if (n[i]>='A' && n[i]<='F'){
      ans += x*(n[i]-'A'+10);
    }
    x *= 16;
  }

  return ans;
}

int decimalToBinary(int n){
  int ans = 0;
  int x = 1;
  while (x<=n){
    x *= 2;

  }
  x /= 2;
  while (x>0){
    int lasdigi = n/x;
    n = n % x ;
    x /= 2;
    ans = ans*10 + lasdigi;
  }

  return ans;
}

int decimalToOctal(int n){
  int ans = 0;
  int x = 1;
  while (x<=n){
    x *= 8;

  }
  x /= 8;
  while (x>0){
    int lasdigi = n/x;
    n = n % x ;
    x /= 8;
    ans = ans*10 + lasdigi;
  }

  return ans;
}

string decimalToHexadecimal (int n){
  int x = 1;
  string ans = "";
  while (x<=n){
    x *= 16;
  }
  x /= 16;

  while (x>0){
    int lasdigi = n/x;
    n = n % x;
    x /= 16;
    if (lasdigi<=9){
      ans = ans + to_string(lasdigi);
    }
    else {
      char c = 'A' + lasdigi - 10;
      ans.push_back(c);
    }
    
  }

  return ans;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    // int n;
    // cin>>n;
    // int n2;
    // cout<<binariToDecimal(n)<<endl;
    // cin>>n2;
    // cout<<OctalTodecimal(n2)<<endl;
    // string n3;
    // cin>>n3;
    // cout<<hexaTodecimal(n3)<<endl;
    // int n4;
    // cin>>n4;
    // cout<<decimalToBinary(n4)<<endl;
    int n5;
    cin>>n5;
    cout<<decimalToHexadecimal(n5)<<endl;
  }

  return 0;
}
