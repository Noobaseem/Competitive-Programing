#include <iostream>
 
using namespace std;
 
#define square(x) x*x
 
int main() {
	// your code goes here
	while(1){
		int N;
		cin>>N;
		if( N == 0 ){
			break;
		}else{
			long long int count = 0;
			while(N){
				count+=square(N);
				N--;
			}
		cout<<count<<"\n";
		}
	}
	return 0;
} 
