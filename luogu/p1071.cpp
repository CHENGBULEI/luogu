
#include<bits/stdc++.h>
using namespace std;
int main(){
	char jimi[26]={0};
	int zhanyong[26]={0};
	string yuanwen;
	string yiwen;
	string fanyi;
	string jieguo;
	
	
	cin>>yiwen;//������Ϣ 
	cin>>yuanwen;//��Ӧ��ԭ��Ϣ 
	cin>>fanyi;//��Ҫ�������Ϣ
	//�������з�������ĸ��ԭ����û�г��ֹ�
	//�����ĸ����ͬ����
	int len = yiwen.size();
	int i,j;
	int flag=1;
	
	for(i=0;i<len;i++){
		/*
		for(j=0;j<26;j++)
			cout<<jimi[j];
		cout<<endl;
		*/
		int index = yiwen[i]-'A';//��ǰ���Ķ�Ӧ�±� 
		int yuanindex = yuanwen[i]-'A';
		if(jimi[index]==0){
			if(yuanwen.find(yiwen[i])==string::npos){
				flag=0;//��������е���ĸ��ԭ����û�г��ֹ������� 
				i = len;
			}
			if(zhanyong[yuanindex]==0){
				jimi[index]=yuanwen[i];
				zhanyong[yuanindex]=1;	
			}else{
				flag=0;
				i=len;//����ѭ�� 
			}
		}else{
			if(jimi[index]!=yuanwen[i]){
				flag=0;//���һ�����Ķ�Ӧ���ԭ�ģ����� 
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
