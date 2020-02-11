#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	int len = 0;
	
		cin>>s;
		len = s.length();
		long long tmp=0;
		for(int j=0;j<len;++j ){
			if(s[j]>=48&&s[j]<65){
				tmp=tmp+pow(16,len-j-1)*(s[j]-48);
			}else if(s[j]>=65){
				tmp = tmp+pow(16,len-j-1)*(s[j]-65+10);
			}
		}
		
		cout<<tmp<<endl;
	
	
	return 0;
}
