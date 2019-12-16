#include<bits/stdc++.h> 
using namespace std;
int main(){
	int first,second,thrid;
	cin>>first>>second>>thrid;
	string s;
	cin>>s;
	
	int len = s.size();
	int i,j;
	string res;
	for(i=0;i<len;i++){
		if(isdigit(s[i])){
			res+=s[i];
		}else if(isalpha(s[i])){
			res+=s[i];
		}else if(s[i]=='-'){
			if(islower(s[i-1])&&islower(s[i+1])){
				if(s[i-1]==s[i+1]||s[i-1]>s[i+1]){
					res+=s[i];
				}else if(s[i-1]+1==s[i+1]){
					continue;
				}else if(s[i-1]<s[i+1]){
					if(thrid==1){
						int num = second;
						int geshu = s[i+1]-s[i-1]-1;
						for(int j=1;j<=geshu;j++){
							if(first==1){
								string tmp(second,s[i-1]+j);
								res+=tmp;
							}else if(first==2){
								string tmp(second,toupper(s[i-1])+j);
								res+=tmp;
							}else if(first==3){
								string tmp(second,'*');
								res+=tmp;
							}
							//res+=tmp;						
						}
					
					}else{
						
						int num = second;
						int geshu = s[i+1]-s[i-1]-1;
						for(int j=geshu;j>=1;j--){
							if(first==1){
								string tmp(second,s[i-1]+j);
								res+=tmp;
							}else if(first==2){
								string tmp(second,toupper(s[i-1])+j);
								res+=tmp;
							}else if(first==3){
								string tmp(second,'*');
								res+=tmp;
							}
							//res+=tmp;						
						}
					
					}
				}
			}else if(isdigit(s[i-1])&&isdigit(s[i+1])){
				if(s[i-1]==s[i+1]||s[i-1]>s[i+1]){
					res+=s[i];
				}else if(s[i-1]+1==s[i+1]){
					continue;
				}else if(s[i-1]<s[i+1]){
					int num = s[i+1]-s[i-1]-1;
					int j;
					if(thrid==1){
						for(j=1;j<=num;j++){
							if(first!=3){
								string tmp(second,s[i-1]+j);
								res+=tmp;	
							}else{
								string tmp(second,'*');
								res+=tmp;
							}
							
						}
					}else{
						for(j=num;j>0;j--){
							if(first!=3){
								string tmp(second,s[i-1]+j);
								res+=tmp;	
							}else{
								string tmp(second,'*');
								res+=tmp;
							}
							
						}
					}
									
				}
			}else{
				res+='-';
			}
	
		}
	}
	cout<<res;
	return 0;
}
