/*
*	@author: Aseem Rastogi
*	alumini: National Institute of Technology, Hamirpur
*		     Batch of 2014
*	mail_id: aseem.rastogi1992@gmail.com
*/
 
#include <cstdio>
#include <cstring>
#include <cmath>
 
using namespace std;
 
long long lastDig(long long a, long long b)
{
    long long temp = 1;
    while(b){
        if(b%2)
            temp = (temp*a)%10;
        b >>= 1;
        a = (a*a)%10;
    }
    return temp;
}
int main(int argc, char* argv[]){
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long a,b;
        scanf("%lld %lld",&a, &b);
        printf("%lld\n",lastDig(a, b));
    }
    return 0;
}
