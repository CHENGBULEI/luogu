#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int j=0;
	int tmp = 0;
	for(int i=100;i<999;i++){
		j = i;
		tmp=0;
		while(j!=0){
			tmp+=pow(j%10,3);
			j/=10;
		}
		if(tmp==i)
			cout<<i<<endl;
	}
	return 0;
}
