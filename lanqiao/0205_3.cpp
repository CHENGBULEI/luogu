#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>m>>n;
	int a[m][n]={0};
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	if(m==1||n==1){
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				cout<<a[i][j]<<" "; 
	}
	else{
		int i=0,j=0;
		int c=m,d=n;//行和列的数目 
		int flag=0;
		while(c>0&&d>0){
		i=j=flag; 
		if(d==1)//出现1列多行的问题，直接全部显示 
			{
					for(i=flag;i<flag+c;i++){//最后一列，直接显示 
						cout<<a[i][j]<<" ";
					}
					break;
				}
				else{
					for(i=flag;i<flag+c-1;i++){//最开始向下 
						cout<<a[i][j]<<" ";
					}
				}	

			if(c==1){//出现1行多列的问题， 
				for(j=flag;j<flag+d;j++){
					cout<<a[i][j]<<" ";
				}
				break;
			}
			else{
				for(j=flag;j<flag+d-1;j++){
					cout<<a[i][j]<<" ";
				}	
			}
			
			for(;i>flag;i--){
				cout<<a[i][j]<<" ";
			}
			for(;j>flag;j--){
				cout<<a[i][j]<<" ";
			}
			flag++;
			c-=2;d-=2;
		}
	
		
	}
	return 0;
} 
