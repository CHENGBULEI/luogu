#include<bits/stdc++.h>
using namespace std;
void quick_sort(int a[],int low,int high);
int partion(int a[],int low,int high); 
int main(){
	//快排
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
int partion(int a[],int low,int high){
	int cor = a[low];//标记位置 
	while(low<high){
		while(low<high&&a[low]<a[high]){
			--high;
		}//high较大，左移 
		if(low<high){
			int tmp = a[low];
			a[low] = a[high];
			a[high] = tmp;
		} //当前low位置的值为标记值，如果当前位置的值比High位置的值大一些并且/
			//low<high则可以交换！
		while(low<high&&a[high]>a[low]){
			++low;
		}//low 交小，右移 
		if(low<high){
			int tmp = a[low];
			a[low]=a[high];
			a[high]=tmp;
		}//当前high位置的值为标记值，如果当前位置的值比low小一些，并且//
		//low<high，交换 
	}
	return low;//返回最后的重合的位置 
	
}
void quick_sort(int a[],int low,int high){
	if(low<high){
		int cor  = partion(a,low,high);//获得一次划分 
		quick_sort(a,low,cor-1);//对左半部分进行快排 
		quick_sort(a,cor+1,high); //对右半部分进行快排 
	}//递归排序 
			
}
 
