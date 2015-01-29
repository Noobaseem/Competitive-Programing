#include <iostream>
#include <cstdio>
using namespace std;
 
int main() {
	long long int x;
	scanf("%lld", &x);
	while(x > 1){
		if(x%2 == 0){
			x >>= 1;
		}else{
			printf("NIE");
			break;
		}
	}
	if(x == 1){
		printf("TAK");
	}
	return 0;
} 
