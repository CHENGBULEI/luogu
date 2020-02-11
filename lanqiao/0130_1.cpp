#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin>>n;
	int len = 0;
	for(int i=0;i<n;i++){
		cin>>s;
		len = s.length();
		string tmp="";
		for(int j=0;j<len;++j ){
			switch(s[j]){
				case '0':tmp+="0000";break;
				case '1':tmp+="0001";break;
				case '2':tmp+="0010";break;
				case '3':tmp+="0011";break;
				case '4':tmp+="0100";break;
				case '5':tmp+="0101";break;
				case '6':tmp+="0110";break;
				case '7':tmp+="0111";break;
				case '8':tmp+="1000";break;
				case '9':tmp+="1001";break;
				case 'A':tmp+="1010";break;
				case 'B':tmp+="1011";break;
				case 'C':tmp+="1100";break;
				case 'D':tmp+="1101";break;
				case 'E':tmp+="1110";break;
				case 'F':tmp+="1111";break;
				default:break; 
			}
		}
		int lenTmp = tmp.length();
		if(lenTmp%3==1){
			tmp.insert(0,"00");
		}else if(lenTmp%3==2){
			tmp.insert(0,"0");
		}
		lenTmp = tmp.length();
		queue<int>res;
		int t = 0;
		for(int j=0;j<lenTmp;j+=3){
			t = 0;
			t=t+(tmp[j]-48)*4+(tmp[j+1]-48)*2+(tmp[j+2]-48);
			res.push(t);
		}
		while(!res.empty()&&res.front()==0){
			res.pop();
		}
		while(!res.empty()){
			cout<<res.front();
			res.pop();
		}
		cout<<endl;
	}
	
	return 0;
}
