#include<bits/stdc++.h>
#include<utility>
//将pair型元素放入到优先队列中

typedef struct node{
	int x;
	int y;
	int huashen;
};
struct cmp{
	bool operator()(node const &p,node const &q){
		if(p.huashen<q.huashen)return true;
		else return false;
	}
}; 
using namespace std;
int main(){
	int i,j;
	int shuliang=0;
	int n,m,k;
	cin>>n>>m>>k;
	int arc[n][m]={0};
	
	priority_queue<node,vector<node>,cmp>pque;
	node tmp;
	
	
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			cin>>arc[i][j];
			if(arc[i][j]!=0){
				
				tmp.huashen = arc[i][j];
				tmp.x = i;
				tmp.y = j;
				
				pque.push(tmp);
			}
		}
	
	tmp = pque.top();
	pair<int,int> now = make_pair(-1 ,tmp.y);



	int xtime = 0;
	int ytime = 0;
	int zong  = 0;
	int huiqu = 0;
	
	
	while(k>0&&!pque.empty()){
		//cout<<now.first<<" "<<now.second<<endl;
		//cout<<shuliang<<" "<<k<<endl;
		tmp = pque.top();
		xtime = abs(now.first-tmp.x);
		ytime = abs(now.second-tmp.y);
		zong = xtime+ytime;
		huiqu = tmp.x+1;
		
		if(k>zong+huiqu){
			k =k-1-zong;
			shuliang+=tmp.huashen;
			now.first = tmp.x;
			now.second = tmp.y;
			pque.pop();	 
		}else{
			k=0;
		}
	}
	cout<<shuliang;
	return 0;
}
