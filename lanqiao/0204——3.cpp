#include<bits/stdc++.h>
using namespace std;
//2��ʾ���ԷŰ׻ʺ�3��ʾ�źڻʺ�0��ʾ�����Էţ�1��ʾ���Է� 
bool check(int board[][8],int row,int col,int yanse,int n){
	if(board[row][col]!=1)return false;
	else{
		for(int i=0;i<n;i++){
			if(board[row][i]==yanse)return false;
		}
		for(int i=0;i<n;i++){
			if(board[i][col]==yanse)return false;
		}
		int i=row,j=col;
		while(i>=0&&j>=0){
			if(board[i][j]==yanse)return false;
			--i;--j;
		}
		i=row;j=col;
		while(i<n&&j<n){
			if(board[i][j]==yanse)return false;
			++i;++j;
		}
		i=row;j=col;
		while(i<n&&j>=0){
			if(board[i][j]==yanse)return false;
			++i;--j;
		}
		i=row;j=col;
		while(i>=0&&j<n){
			if(board[i][j]==yanse)return false;
			--i;++j;
		}
	}
	return true;
} 

//boardΪ������,��ʾ�������̣�xΪ��ǰ��ɫ���ӷŵ��ڼ����ˣ�yanseΪ��ǰ������ɫ,nΪ���̴�С��sumΪ������ 
void dfs(int board[][8],int x,int yanse,int n,int &sum){
	if(x==n){		//�ݹ�������� 
		if(yanse==3)//�ȷŰ��Ӻ�ź���
			sum++;
		x=0;
		dfs(board,x,3,n,sum);
		/*
		for(int i=0;i<n;i++)
		{
			
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;	
		}
		cout<<endl;
		*/
	}else{
		int i=0;
		for(i=0;i<n;i++)//˳��ķ����ӣ����Կ��ǵ��������
		{
			if(check(board,x,i,yanse,n)){
				board[x][i]=yanse;//���Է����ӣ�����
				dfs(board,x+1,yanse,n,sum);//�ݹ�Ĳ�����һ��λ��
				board[x][i]=1;//�ݹ�������������̵���ɫ 
			}
			else continue;//˳����� 
		}
		
	}
}
int main(){
	int board[8][8];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>board[i][j];
		}
	
	int sum = 0;
	dfs(board,0,2,n,sum);
	cout<<sum;

	return 0;
}

