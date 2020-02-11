#include<iostream>
#include<algorithm>
using namespace std;
/*
int JONum(int wordS[26],int n){
	int count=0;
	if(n%2){
		for(int i=0;i<26;i++){
			if(wordS[i]!=0&&wordS[i]%2==1){
				++count;
			}
		}
	}else{
		for(int i=0;i<26;i++){
			if(wordS[i]!=0&&wordS[i]%2!=0){//���������ĸΪ���������ֱ�ӷ���-1 
				return -1;
			}
		}	
	}
	return count;
}
void WordStatistics(string str,int wordS[26]){
	int i,len = str.length();
	for(i=0;i<26;i++){
		wordS[i]=0;
	}
	for(i=0;i<len;i++){
		++wordS[str[i]-'a'];
	}
}
//��λ��i����ĸ������λ��jλ���� 
void WordExchange(int i,int j,string &str)
{
	char tmp = str[i];
	while(i<j){
		str[i]=str[i+1];
		++i;
	}
	while(i>j){
		str[i]=str[i-1];
		--i;
	}
	str[i]=tmp;
}

int MinExchange(int n,string str){
	int wordS[26];
	WordStatistics(str,wordS);
	int count = JONum(wordS,n);
	int res=0; 
	if(n%2){
		if(count>=2)return -1;
		else{
			int i=0,j=n-1;
			i=0;j=n-1;
			while(i<n/2){
				for(j = n-1-i;j>i;--j){//Ѱ�Ҷ�Ӧλ�þ���������Ǹ���ĸ 
					if(str[i]==str[j]){
						res+=n-1-i-j;
						WordExchange(j,n-1-i,str);
						break;
					}
				}
				if(j==i&&wordS[n/2]%2==0){
					WordExchange(i,n/2,str);
					res+=n/2-i;
					i--;
				}
				++i;
			}	
		}
	}else{
		if(count==-1)return -1;
		else{
			int i=0,j=n-1;
			while(i<n/2){
				for(j = n-1-i;j>i;--j){//Ѱ�Ҷ�Ӧλ�þ���������Ǹ���ĸ 
					if(str[i]==str[j]){
						res+=n-1-i-j;
						WordExchange(j,n-1-i,str);
						break;
					}
					
				}
				++i;
			}
		}
	}
	return res;
}
*/
int MinExchange(int n,string str){
	int res=0;
	int i,j;
	int end = n-1;
	int oddNum = 0;//��ĸ����Ϊ�����ĸ�������� 
	for(i=0;i<end;i++){
		
		for(j=end;j>=i;--j){
			if(i==j){//������ڳ���Ϊ������������������һ����ĸû��ƥ��������� 
				if(n%2==0||oddNum==1){//�������Ϊż���������Ѿ����ֹ�һ��������������ĸ����� 
					return -1;
				}
				oddNum=1;
				res+=n/2-i;
			}else if(str[i]==str[j]){
				
				while(j<end){
					swap(str[j],str[j+1]);
					++j;
					++res;
				}
				--end;
				break;
			}
		}
		
	}
	return res;
}
int main(){
	int n;
	string str;
	cin>>n>>str;
	int res =MinExchange(n,str); 
	if(res==-1)
		cout<<"Impossible";
	else 
		cout<<res;
	return 0;
} 
