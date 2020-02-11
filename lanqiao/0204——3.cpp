#include<bits/stdc++.h>
using namespace std;
//2表示可以放白皇后，3表示放黑皇后，0表示不可以放，1表示可以放 
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

//board为总棋盘,表示最大的棋盘，x为当前颜色棋子放到第几个了，yanse为当前棋子颜色,n为棋盘大小，sum为方案数 
void dfs(int board[][8],int x,int yanse,int n,int &sum){
	if(x==n){		//递归结束条件 
		if(yanse==3)//先放白子后放黑子
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
		for(i=0;i<n;i++)//顺序的放棋子，可以考虑到所有情况
		{
			if(check(board,x,i,yanse,n)){
				board[x][i]=yanse;//可以放棋子，放下
				dfs(board,x+1,yanse,n,sum);//递归的查找下一个位置
				board[x][i]=1;//递归结束后重置棋盘的颜色 
			}
			else continue;//顺序查找 
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

