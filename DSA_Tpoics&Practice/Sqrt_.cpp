#include <iostream>
#include <cmath>
// #include<bits/stdc++.h>

#define ll long long

using namespace std;

int Binary(int n)
{

   int i = 1;
   int j = n;
   int result;

   while ((j-i) > 1)
   {
      int mid = i + ((j - i) / 2);

      if ((mid * mid) == n)
      {
         result = mid;
         return result;
      }

      if ((mid * mid) < n)
      {
         result = mid;
         i = mid;
      }
      else
      {
         j = mid;
      }
   }

   return result;
}

int main()
{

   int t;
   cin >> t;

   while (t--)
   {
      int n;
      cin >> n;

      int ans = Binary(n);

      cout << ans << endl;
   }

   return 0;
}
