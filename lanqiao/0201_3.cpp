#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n][n]={0};
	for(int i=0;i<n;i++)
		{
		
		for(int j=0;j<n;j++)
			a[i][j]=0;
			}
	a[0][0]=1;
	for(int i=0;i<n;++i){
		if(i==0) continue;
		for(int j=0;j<=i;j++){
			if(j==0){
				a[i][j]=a[i-1][j];
			}else if(j==n-1){
				a[i][j]=a[i-1][j-1];
			}else{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			cout<<a[i][j]<<" ";
			cout<<endl;
		}		
	return 0;
}
