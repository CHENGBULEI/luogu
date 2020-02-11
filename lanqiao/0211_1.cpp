#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
bool IsPrime(int num){//判断是否为素数:采用6x-1和6x+1方法，即所有素数必须被6i-1或者6i+1整除 
	if(num==2 || num==3)return true;
	if((num+1)%6!=0&&(num-1)%6!=0)return false;
	int tmp = sqrt(num);//能够被因式分解，分解得到的因式肯定小于等于num开方
	for(int i=5;i<=tmp;i+=6){//在6i-1,6i,6i+1,6i+2,6i+3,6i+4这个循环中，因为即使能被6i-1,6i+1整除，也可能不是素数
								//所以当能被6i-1或者6i+1整除时，肯定为奇数，所以6i,6i+2,6i+4都不可能整除，6i+3能被
								//3整除，但是6i-1,6i+1肯定不能被3整除，所以num应该不可能被6i+3整除，所以如果num不时
								//素数，只能被6i-1或者6i+1整除 
		if(num%i==0||num%(i+2)==0)return false;
	} 
	return true;
}
string Devide(int num,vector<int>& prime){
	if(!prime.empty()&&find(prime.begin(),prime.end(),num)!=prime.end()){
		string res = "";
		res.append(1,'*');//将数字转换成字符串 
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
