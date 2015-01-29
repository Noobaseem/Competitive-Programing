#include <cstdio>
using namespace std;
 
int main()
{
	int t;
 
    scanf("%d",&t);
    while(t--)
    {
        long long unsigned level;
        long long unsigned cum;
        scanf("%llu",&level);
        if(level%2==0)
        cum=(level*(level+2)*((2*level)+1))/8;
        else
        cum=((level*(level+2)*((2*level)+1))-1)/8;
        printf("%llu\n",cum);
    }
    return 0;
} 
