#include<stdio.h>
int main(){
    // *
    // **
    // ***
    // ****
    // *****
    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // *****
    // ****
    // ***
    // **
    // *
    // for (int i = 5; i >= 0; i--)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");        
    // }


    //      *
    //     **
    //    ***
    //   ****
    //  *****
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = i; j <=5-1 ; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int k = 0; k <= i; k++)
    //     {
    //         printf("*");
    //     }
        
    //     printf("\n");
    // }

    
    // *****
    //  ****
    //   ***
    //    **
    //     *
        
    // for (int i = 5; i > 0 ; i--)
    // {
    //     for (int j = i; j <=5-1 ; j++)
    //     {
    //         printf(" ");
    //     }
    //     for (int k = 1; k <= i; k++)
    //     {
    //         printf("*");
    //     }
        
    //     printf("\n");
    // }

    // 1
    // 12
    // 123
    // 1234
    // 12345
    
    // for (int i = 1; i <= 5; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         printf("%d",j);
    //     }
    //     printf("\n");
    // }

    // 1
    // 21
    // 321
    // 4321
    // int j;
    // for (int i = 1; i <= 4; i++)
    // {
    //     for (j = i; j >= 1; j--)
    //     {
    //             printf("%d",j);            
    //     }
    //     printf("\n");
    // }
    
    // ABCDE
    // ABCD
    // ABC
    // AB
    // A
    // for (int i = 1; i <= 5 ; i++)
    // {
    //     for (char j = 'A'; j <= 'A' + 5 - i ; j++)
    //     {
    //         printf("%c",j);
    //     }
    //     printf("\n");
    // }

    // 1
    // 23
    // 456
    // 78910
    // 1112131415
    // int k = 1;
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j <= i ; j++)
    //     {
    //         printf("%d",k);
    //         k = k+1;
    //     }
    //     printf("\n");
    // }

    // ABCDE
    //  ABCD
    //   ABC
    //    AB
    //     A
    // char k;
    // for (int i = 5; i > 0 ; i--)
    // {
    //     for (int j = i; j <=5-1 ; j++)
    //     {
    //         printf(" ");
    //     }
    //     for ( k = 'A'; k <= 'A'+ i - 1; k++)
    //     {
    //         printf("%c",k);
    //     }
    //     k = 'A';
    //     printf("\n");
    // }

    // *****
    // *   *
    // *   *
    // *   *
    // *****
    
    // for (int i = 1; i <=5; i++)
    // {
    //     for (int j = 1; j <=5; j++)
    //     {
    //         if (i == 1 || i == 5 || j ==1 || j == 5)
    //         {
    //             printf("*");
    //         }
    //         else{
    //             printf(" ");
    //         }
    //     }
    //     printf("\n");    
    // }

    int i, j;
    char k = 64;
    for ( i = 1; i <=5 ; i++)
    {
        k = 64 + i;
        for ( j = 1; j <= 5; j++)
        {
            if (j >= i)
            {
                printf("%c",k++);
            }
            else{
                printf(" ");
            }
        }

        printf("\n");
        
    }
    
    
    return 0;
}