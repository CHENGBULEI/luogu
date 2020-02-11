#include<bits/stdc++.h>
using namespace std;
bool check(int a);
int main(){
	int n;
	cin>>n;
	int t=0;
	int i;
	for(int j=10000;j<999999;++j){
		t=0;
		i = j;
		if(check(j)){
			while(i!=0){
				t+=i%10;
				i/=10;	
			}
			if(t==n)
				cout<<j<<endl;
		}
	}
	return 0;
}
bool check(int a){
	int tmp =  a;
	int len = 0;
	int s[6]={0};
	while(tmp!=0){
		s[len]=tmp%10;
		tmp/=10;
		++len;
	}
	int i=0,j=len-1;
	while(i<j){
		if(s[i]!=s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}
