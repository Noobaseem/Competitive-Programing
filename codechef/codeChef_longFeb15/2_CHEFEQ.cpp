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
#include <map>
 
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

typedef map<int, int>  mii;
typedef pair<int, int> pii;

int main(int argc, char* argv[]){
	/*
	//This code snippet tells map stores in sortd mapnner by keys
	pii x = make_pair(100004,6);
	pii y = make_pair(100003,7);
	mii.insert(x);
	mii.insert(y);
	for(mii::iterator itr = mii.begin(); itr < mii.end(); itr++){
		cout<<itr->first;
	}*/
	int T;
	scanf("%d", &T);
	while(T--){
		mii myMap, it;
		pii X = make_pair(-1,-1);
		myMap.insert(X);
		int N, temp;
		scanf("%d",&N);
		for0(i,N){
			scanf("%d",&temp);
			if(myMap.find(temp) == myMap.end()){
				pii Y = make_pair(temp,1);
				myMap.insert(Y);
			}else{
				int tempValue = myMap.find(temp)->second;
				tempValue += 1;
				myMap.find(temp)->second = tempValue;
			}
		}
		int max = 0;
		myMap.erase(myMap.find(-1));
		for(mii::iterator itr = myMap.begin(); itr != myMap.end(); itr++){
			if(max < itr->second){
				max = itr->second;
			}
		}
		cout<<N-max<<endl;
	}
}