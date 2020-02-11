#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void AN(int n){
	if(n==1){
		cout<<'A'; 
	}else{
		AN(n-1);
		char tmp = 'A'+n-1;
		cout<<tmp;
		AN(n-1);
	}
	
}
int main(){
	int n;
	cin>>n;
	AN(n);
	return 0;
}


