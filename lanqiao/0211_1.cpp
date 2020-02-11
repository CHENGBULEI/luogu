#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
bool IsPrime(int num){//�ж��Ƿ�Ϊ����:����6x-1��6x+1�������������������뱻6i-1����6i+1���� 
	if(num==2 || num==3)return true;
	if((num+1)%6!=0&&(num-1)%6!=0)return false;
	int tmp = sqrt(num);//�ܹ�����ʽ�ֽ⣬�ֽ�õ�����ʽ�϶�С�ڵ���num����
	for(int i=5;i<=tmp;i+=6){//��6i-1,6i,6i+1,6i+2,6i+3,6i+4���ѭ���У���Ϊ��ʹ�ܱ�6i-1,6i+1������Ҳ���ܲ�������
								//���Ե��ܱ�6i-1����6i+1����ʱ���϶�Ϊ����������6i,6i+2,6i+4��������������6i+3�ܱ�
								//3����������6i-1,6i+1�϶����ܱ�3����������numӦ�ò����ܱ�6i+3�������������num��ʱ
								//������ֻ�ܱ�6i-1����6i+1���� 
		if(num%i==0||num%(i+2)==0)return false;
	} 
	return true;
}
string Devide(int num,vector<int>& prime){
	if(!prime.empty()&&find(prime.begin(),prime.end(),num)!=prime.end()){
		string res = "";
		res.append(1,'*');//������ת�����ַ��� 
		stringstream ss;
		ss<<num;
		res+=ss.str();
		return res;
	}else{
		string res="";
		int i=0;
		int len = prime.size();
		while(i<len){
			if(num%prime[i]==0)break;
			++i;
		}
		if(i<len)
		{
				num = num/prime[i];
				res.append(1,'*');
				stringstream ss;
				ss<<prime[i];
				res+=ss.str();		
				res+=Devide(num,prime);
			}
		else{
			res.append(1,'*');
			stringstream ss;
			ss<<num;
			res+=ss.str();
		}
			 
		return res;
	}
}
void DevideNum(int num,vector<int> &prime){
	if(!prime.empty()&&find(prime.begin(),prime.end(),num)!=prime.end()){
		cout<<num<<"="<<num<<endl;
	}else{
		string res = Devide(num,prime);
		//string res = Devide(4,prime);
		if(res[0]=='*')
			res.erase(0,1);
		cout<<num<<"="<<res<<endl;
	}
}
int main(){
	int a,b;
	cin>>a>>b;
	vector<int>prime;
	int i,j; 
	for(i=2;i<b;i++){
		if(IsPrime(i))prime.push_back(i);
	}
	for(i=a;i<=b;++i)
		DevideNum(i,prime);
	return 0;
}
