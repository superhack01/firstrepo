#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

void solution(int n, vector<int> &ans){
	int x = sqrt(n);

	for (int i = 1; i <= x;i++){
		if ((n%i) == 0){
			ans.push_back(i);

			if (i != (n/i)){
				ans.push_back(n/i);
			}
		}

	}
}

int main(){
	int n;
	cin>>n;

	vector<int> ans;

	solution(n,ans);

	for (auto i : ans){
		cout<<i<<" ";
	}cout<<endl;

	return 0;
}



/*
//// All Divisor with the prime number hakerrank question is : 

#include<iostream>
#include<cmath>
#include<vector>
#include<set>

using namespace std;

void solution(int n, set<int> &ans){
	int x = sqrt(n);

	for (int i = 1; i <= x;i++){
		if ((n%i) == 0){
			ans.insert(i);

			if (i != (n/i)){
				ans.insert(n/i);
			}
		}

	}
}

bool prime(int x){
	set<int> cheack;
	solution(x,cheack);

	if (cheack.size() == 2){
		return true;
	}
	else return false;
}

int main(){
	int n;
	cin>>n;

	set<int> ans;

	solution(n,ans);

	// for (auto i : ans){
	// 	cout<<i<<" ";
	// }cout<<endl;

	auto it = ans.rbegin();
	for (it = ans.rbegin();it != ans.rend(); it++){
		if (prime((*it))){
			cout<<*it<<endl;
			break;
		}
	}

	return 0;
}
*/