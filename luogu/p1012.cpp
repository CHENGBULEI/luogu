#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;
int main(){
	int n;
	int t;
	int i,j; 
	string res;
	priority_queue<string,vector<string>,less<string> >tmp;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t;
		int count=0;
		int a=t;
		while(t!=0){
			t/=10;
			count++;
		}
		string s;
		while(count>0){
			s.insert(s.begin(),a%10+'0');
			a/=10;
			count--;
		}
		//cout<<s<<endl;
		tmp.push(s);
	}
	while(!tmp.empty()){
		res+=tmp.top();
		tmp.pop();
	} 
	cout<<res;
	return 0;
}
