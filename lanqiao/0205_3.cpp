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
		int c=m,d=n;//�к��е���Ŀ 
		int flag=0;
		while(c>0&&d>0){
		i=j=flag; 
		if(d==1)//����1�ж��е����⣬ֱ��ȫ����ʾ 
			{
					for(i=flag;i<flag+c;i++){//���һ�У�ֱ����ʾ 
						cout<<a[i][j]<<" ";
					}
					break;
				}
				else{
					for(i=flag;i<flag+c-1;i++){//�ʼ���� 
						cout<<a[i][j]<<" ";
					}
				}	

			if(c==1){//����1�ж��е����⣬ 
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
