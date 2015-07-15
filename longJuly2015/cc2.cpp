/*
*   @author: Aseem Rastogi
*   alumini: National Institute of Technology, Hamirpur
*            Batch of 2014
*   mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
 
using namespace std;
 
/*My personalised flavour of some c++ constructs*/
#define for0(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
 
int main() {
    int N;
    cin>>N;
    int A[N];
    fora(i, 0, N) {
        cin>>A[i];
        unsigned long long int res = A[i];
        int loop = 0;
        while (A[i]%10 == 0){
            A[i] /= 10;
        } 
        while (A[i]%5 == 0) {
            loop++;
            A[i] /= 5;
        }
        int final = ceil(loop/2.0);
        while(final--)
            res *= 4;
        printf("%llu\n", res);
    }
    return 0;
} 