#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
 
using namespace std;
 
int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N>0){
			char userString[220];
			cin>>userString;
			int x = strlen(userString)/N;
			int index = 1;
			for( int col = 0; col < N;col++ ){
				int currentPlace = col;
				int count = 1;
				for( int i = 0; i < x; i++ ){
					cout<<userString[currentPlace];
					if( count%2 == 0 ){
						currentPlace+=2*index-1;
					}else{
						currentPlace=currentPlace+N*2-(2*index-1);
					}
					count++;
				}
				index++;
			}
			cout<<"\n";
		}
		if(N == 0){
			break;
		}
	}
	return 0;
} 
