#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	int res[102];
	int f=0,s=0,c=0;
	int lena = a.length();
	int lenb = b.length();
	int i=0;
	int tmp = 0;
	for(int i=0;i<102;i++)
		res[i]=0;
	if(lena>lenb){
		for(int i=0;i<lena;++i){
			res[i]=a[lena-i-1]-'0';
		}
		for( i=0;i<lenb;i++){
			res[i]+=b[lenb-i-1]-'0'+c;
			tmp = res[i];
			res[i] = res[i]%10;//����ӷ����㷨�򣬵�ǰ������a+b+c��cλ��λ��
			c = tmp/10; 
		}
	}else{
		for(int i=0;i<lenb;++i){
			res[i]=b[lenb-i-1]-'0';
		}
		for(i=0;i<lena;i++){
			res[i]+=a[lena-i-1]-'0'+c;
			tmp = res[i];
			res[i] = res[i]%10;//����ӷ����㷨�򣬵�ǰ������a+b+c��cλ��λ��
			c = tmp/10; 
		}
	}
		
	int j=0;
	while(c){//���һλ��Ȼ�н�λ����������� 
		res[i] +=c;
		j = res[i]/10;
		res[i] %=10;
		c = j; 
		i++;
	}
	
	int len  = lena>lenb?lena:lenb;
	len = i>len?i:len;	
	for(int i=len-1;i>=0;--i)
		cout<<res[i];
	return 0;
}
