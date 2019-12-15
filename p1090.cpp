#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int,vector<int>,greater<int> >que;
	int n;
	int t;
	int i,j;
	int jieguo = 0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>t;
		que.push(t);
	}
	
	while(!que.empty()){
		
		int tmp = que.top();
		//cout<<tmp;
		que.pop();
		if(que.empty()){
			//jieguo+=tmp;
			break;
		}else{
			int tmp2 = que.top();
			que.pop();
			que.push(tmp2+tmp);
			jieguo=jieguo+tmp2+tmp;
		}
	}
	cout<<jieguo; 
	return 0;
} 
 
 
