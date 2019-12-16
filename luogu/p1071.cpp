
#include<bits/stdc++.h>
using namespace std;
int main(){
	char jimi[26]={0};
	int zhanyong[26]={0};
	string yuanwen;
	string yiwen;
	string fanyi;
	string jieguo;
	
	
	cin>>yiwen;//加密信息 
	cin>>yuanwen;//对应的原信息 
	cin>>fanyi;//需要翻译的信息
	//在密文中发现有字母在原文中没有出现过
	//多个字母有相同密文
	int len = yiwen.size();
	int i,j;
	int flag=1;
	
	for(i=0;i<len;i++){
		/*
		for(j=0;j<26;j++)
			cout<<jimi[j];
		cout<<endl;
		*/
		int index = yiwen[i]-'A';//当前密文对应下标 
		int yuanindex = yuanwen[i]-'A';
		if(jimi[index]==0){
			if(yuanwen.find(yiwen[i])==string::npos){
				flag=0;//如果密文中的字母在原文中没有出现过，结束 
				i = len;
			}
			if(zhanyong[yuanindex]==0){
				jimi[index]=yuanwen[i];
				zhanyong[yuanindex]=1;	
			}else{
				flag=0;
				i=len;//结束循环 
			}
		}else{
			if(jimi[index]!=yuanwen[i]){
				flag=0;//如果一个密文对应多个原文，结束 
				i = len;
			}
		} 
	}
		if(flag!=0){
			string s;
			int lenfanyi =fanyi.size();
			for(i=0;i<lenfanyi;i++){
				if(jimi[fanyi[i]-'A']=='0'){
					break;
				}else{
					s+=jimi[fanyi[i]-'A'];
				}
			} 
		 	if(i==lenfanyi&&lenfanyi>0&&len>0)
		 		cout<<s;
		 	else
		 		cout<<"Failed";
		}else
				cout<<"Failed";
	
	
	
	
	return 0;
} 
