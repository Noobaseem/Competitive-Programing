/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		 	 Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*
	lps array is the array containing the lengths of longest proper prefix which is also the
	suffix of the pattern till given index
*/

void fillLpsArray(char* pat, int M, int* lps){
	int len = 0; //length of lps upto previous index
	int i;

	lps[0] = 0;  //length of lps is zero for pattern string of for first character coz we are looking for "proper" prefix
	i = 1; //index in given pattern, starting with 1 coz if we take initial value of i = 0 then we would match the entire string
	
	while(i < M) {
		if(pat[len] == pat[i]){
			len++;
			lps[i] = len;
			i++;
		}else {
			if(len != 0){
				len = lps[len-1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void kmp(char* pat, char* txt){
	int N = strlen(txt); //length of text
	int M = strlen(pat); //length of pattern
	int* lps = (int*)malloc(sizeof(int)*M);
	int j = 0; //index in pattern
	int i = 0; //index in text
	fillLpsArray(pat, M, lps);
	while(i < N){
		if(txt[i] == pat[j]){
			i++;
			j++;
		}
		if(j == M){
			cout<<"match at index : "<<(i-j);
			j = lps[j-1]; //Minimum shift to start new search
		}
		else if(i < N && pat[j] != txt[i]){
			if(j != 0){
				j = lps[j-1]; //Minimum shift the pattern
			}else{
				i++;
			}
		}
	}
}

int main(int argc, char* argv[]){
   char *txt = "ABABDABACDABABCABAB";
   char *pat = "ABABCABAB";
   kmp(pat, txt);
   return 0;
}