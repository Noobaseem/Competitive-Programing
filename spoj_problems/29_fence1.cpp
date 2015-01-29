#include<stdio.h>
int main()
{
        double a;
        double pie=3.141592653589793238462643383279;
        scanf("%lf",&a);
        while(a!=0)
        {
        double r=a/pie;
        double area=pie*r*r/2.0;
        printf("%.2lf\n",area);
        scanf("%lf",&a);
        }
        return 0;
} 
