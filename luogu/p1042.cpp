#include<bits/stdc++.h>
//40·Ö 
using namespace std;
int main(){
	int flag=1;
	string line;
	char jieguo;
	int jushu=0;
	int hua=0;
	int duisou=0;
	
	int djushu = 0;
	int dhua = 0;
	int dduisou =0;
	queue<pair<int,int> >shiyi;
	queue<pair<int,int> >ershiyi;
	cin>>line;
	while(flag){
		int len=0;
	
		if(line.find('E')!=string::npos){
			len = line.find('E');
			flag=0;
		}else
			len = line.size();
			//	cout<<len<<endl;
		for(int i=0;i<len;i++){
			jieguo = line[i];
		
			
			if(jieguo=='W'){
				hua++;
				dhua++;
				jushu++;
				djushu++;
			}else if(jieguo=='L'){
				duisou++;
				dduisou++;
				jushu++;
				djushu++;
				
			}	
			
			if((jushu>=11&&abs(hua-duisou)>=2)){
				shiyi.push(make_pair(hua,duisou));
				jushu=0;
				hua = 0;
				duisou = 0;				
			}
			if((djushu>=21&&abs(dhua-dduisou)>=2)){
				ershiyi.push(make_pair(dhua,dduisou));
				djushu=0;
				dhua = 0;
				dduisou =0;
			}
			
		}
		if(line.find('E')!=string::npos){
			flag=0;
		}else
			cin>>line;
	}
	if(jushu!=0){
		shiyi.push(make_pair(hua,duisou));
		
	}
	if(djushu!=0){
		ershiyi.push(make_pair(dhua,dduisou));
	}
	while(!shiyi.empty()){
		cout<<shiyi.front().first<<":"<<shiyi.front().second<<endl;
		shiyi.pop();
	}
	cout<<endl;
	while(!ershiyi.empty()){
		cout<<ershiyi.front().first<<":"<<ershiyi.front().second<<endl;
		ershiyi.pop();
	}
	return 0;
}
