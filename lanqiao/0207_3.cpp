#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string zuanD(int n){
	char tmp = n+'0';
	string res=""; 
	switch(tmp){				
				case '1':res+="shi ";break;
				case '2':res+="bai ";break;
				case '3':res+="qian ";break;
				case '4':res+="wan ";break;
				case '5':res+="shi ";break;
				case '6':res+="bai ";break;
				case '7':res+="qian ";break;
				case '8':res+="yi ";break;
				case '9':res+="shi ";break;
				default:break;
			}
	return res;
}
string zuanG(int n){
	char tmp = n+'0';
	string res=""; 
	switch(tmp){
				case '0':res+="ling ";break;
				case '1':res+="yi ";break;
				case '2':res+="er ";break;
				case '3':res+="san ";break;
				case '4':res+="si ";break;
				case '5':res+="wu ";break;
				case '6':res+="liu ";break;
				case '7':res+="qi ";break;
				case '8':res+="ba ";break;
				case '9':res+="jiu ";break;
				default:break;
			}
	return res;
}
string zuanF(string tmp){
	int len = tmp.length();
	string res="";
	for(int i=0;i<len;i++){
		if(tmp[i]=='0'){
			if(i<len-1&&tmp[i+1]!='0'){
				res+=zuanG(0);//�����ǰΪ0������ǰ��һ������0����0����������� 
			}
		}else if(tmp[i]=='1'&&(len-i-1==1||len-i-1==5||len-i-1==9)){//����������⿼�ǣ���n==1,n==4,n=8��Щλ�ϵ���λ1ʱ��ʡ��1���� 
			res+=zuanD(len-i-1);
		}else{
			res+=zuanG(tmp[i]-48)+zuanD(len-i-1);
		}
	}
	return res;
}

int main(){
	string tmp;
	cin>>tmp;
	cout<<zuanF(tmp);
	return 0;
}
