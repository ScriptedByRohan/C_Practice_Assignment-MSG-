# include<stdio.h>
int main(){
    int a, b, c, d;
    printf("Write three numbers \n");
    scanf("%d%d%d",&a,&b,&c);
    d = (a+b+c)/3;
    printf("The average of three integer is %d \n",d);

    printf("The circumfrence of circle with radius %d is %f \n",a , 2*3.14*a);

    int p , r , t , ans ;
    printf("For simple interset wite the value of p , r, t \n");
    scanf("%d%d%d",&p,&r,&t);
    ans = p * (1 + (r * t));
    printf(" The simple interst is %d \n", ans);

    printf("The size of cuboid is %d , %d , %d and the volume of cuboid is %d \n",a,b,c,a*b*c);

    printf("Selling price and Cost price is %d and %d and the profit is %d",a,b,a-b);

    return 0 ;
}