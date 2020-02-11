#include<bits/stdc++.h>
using namespace std;
//0:zero, 1: one, 2:two, 3:three, 4:four, 5:five, 6:six, 7:seven, 8:eight, 9:nine,
// 10:ten, 11:eleven, 12:twelve, 13:thirteen, 14:fourteen, 15:fifteen, 
//16:sixteen, 17:seventeen, 18:eighteen, 19:nineteen, 20:twenty¡£
string zuanhuaG(int n){
	string s = "";
	switch(n){
		case 0:s+="zero";break;
		case 1:s+="one";break;
		case 3:s+="three";break;
		case 2:s+="two";break;
		case 4:s+="four";break;
		case 5:s+="five";break;
		case 6:s+="six";break;
		case 7:s+="seven";break;
		case 8:s+="eight";break;
		case 9:s+="nine";break;
		case 10:s+="ten";break;
		case 11:s+="eleven";break;
		case 12:s+="twelve";break;
		case 13:s+="thirteen";break;
		case 14:s+="fourteen";break;
		case 15:s+="fifteen";break;
		case 16:s+="sixteen";break;
		case 17:s+="seventeen";break;
		case 18:s+="eighteen";break;
		case 19:s+="nineteen";break;
		case 20:s+="twenty";break; 
		default :break;
	}
	return s;
}
//30¶Á×÷thirty£¬40¶Á×÷forty£¬50¶Á×÷fifty¡£
string zuanhuaT(int n){
	string s="";
	if(n>=21){
		int tmp = n%10;
		n = (n/10)*10;
		switch(n){
			case 20:s+="twenty";break;
			case 30:s+="thirty";break;
			case 40:s+="forty";break;
			case 50:s+="fifty";break;
		}
		if(tmp!=0)
		s+=" "+zuanhuaG(tmp);
		else
		s+=" "; 
	}else{
		s+=zuanhuaG(n);
	}
	return s;
	
}

int main()
{
	int a,b;
	cin>>a>>b;
	string res="";
	if(a==b&&a==0)
		res+="zero o'clock";
	else{
		res+=zuanhuaT(a)+" "+zuanhuaT(b);	
	}
	
	cout<<res;
	return 0;
}
