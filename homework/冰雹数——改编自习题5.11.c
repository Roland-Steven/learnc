#include<stdio.h>
void hai(long long x);
int main()
{
    long long x;
    for (;;)
    {
    if (scanf("%lld",&x) == EOF) break;
    printf("Hailstone generated by %lld:\n",x);
    hai(x);
}
}
void hai(long long x)
{
    int i = 0;
    for(;;)
    {
        printf("%lld ",x);
        i++;
        if (x%2) x = 3*x+1;
        else x = x/2;
        if (x == 1) 
        {
            printf("1");
            i++;
            break;
        }
        
    }
    printf("\nNumber of hailstone generated:%d\n\n",i);
}