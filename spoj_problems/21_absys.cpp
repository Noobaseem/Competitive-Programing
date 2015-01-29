/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
/*My utility functions*/
#define pb push_back
#define pf push_front
#define sz size
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
/*Some important programing terms*/
#define MOD 1000000007
 
using namespace std;
 
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int stringtoint(string& s)
{
	int ten=1;
	int b=0;
	int i;
	for(i=s.size()-1;i>=0;i--)
	{
		b += (s[i]-'0')*ten;
		ten=ten*10;
	}
	return b;
}
bool ifnumber(string& s)
{
	bool check = true;
	for(int i = 0; i < (int)s.size(); i++)
		if(s[i]<'0' || s[i]>'9')
			return false;
		
	return true;
}
int main()
{
	int n1,n2,n3,t;
	string s1,s2,s3;
	cin>>t;
	char ch;
	while(t--){
		cin>>s1>>ch>>s2>>ch>>s3;
		if(ifnumber(s1) == false){
			n2=stringtoint(s2);
			n3=stringtoint(s3);
			n1=n3-n2;
			cout<<n1<<" + "<<n2<<" = "<<n3<<endl;
		}else if (ifnumber(s2)==false){
			n1=stringtoint(s1);
			n3=stringtoint(s3);
			n2=n3-n1;
			cout<<n1<<" + "<<n2<<" = "<<n3<<endl;
		}else{
			n1=stringtoint(s1);
			n2=stringtoint(s2);
			n3=n1+n2;
			cout<<n1<<" + "<<n2<<" = "<<n3<<endl;
		}
	}
	return 0;
} 
