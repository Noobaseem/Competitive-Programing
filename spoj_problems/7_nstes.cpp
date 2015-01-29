#include <iostream>
using namespace std;
 
int main() {
	int T;
	cin>>T;
	while(T){
		int x, y;
		cin>>x>>y;
			if( x == y ){
				int count = 0;
				count = x/2;
				cout<<x+count*2<<"\n";
			}else if( x-y == 2 ){
				int xcount = 0;
				xcount = (x-2)/2;
				cout<<x+xcount*2<<"\n";
			}else{
				cout<<"No Number"<<"\n";
			}
		T--;
	}
	return 0;
} 
