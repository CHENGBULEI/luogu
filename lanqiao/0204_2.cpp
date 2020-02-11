#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	long long res=0;
	int tmp;
	priority_queue<int,vector<int>,greater<int> >r;
	for(int i=0;i<n;i++){
		cin>>tmp;
		r.push(tmp);
	}
	int a=0,b=0;
	while(!r.empty()){
		a = r.top();
		r.pop();
		if(!r.empty())
		{
			b = r.top();
			res=res+a+b;
			r.pop();
			r.push(a+b);
		}
		
	}
	cout<<res;
	return 0; 
}
