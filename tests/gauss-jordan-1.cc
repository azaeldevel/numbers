#include <stdio.h>
#include <cstring>

int main(int argc, char *argv[])
{
    bool input_value = false;

    if(argc > 1)
    {
        for(int i = 0; i < argc; i++)
        {
            if(strcmp(argv[i],"input-value") == 0)
            {
                input_value = true;
            }
        }
    }

    int i,j,k,n;
    float A[20][20],c,x[10];

    if(input_value)
    {
        printf("\nEnter the size of matrix: ");
        scanf("%d",&n);
        printf("\nEnter the elements of augmented matrix row-wise:\n");
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=(n+1); j++)
            {
                printf(" A[%d][%d]:", i,j);
                scanf("%f",&A[i][j]);
            }
        }
    }
    else
    {
        //A[][] = {10.0f,-7.0f,5.0f,9.0f,3.0f,6.0f,0.0f,-9.0f,9.0f,3.0f,-2.0f,-1.0f};
        n = 3;
        A[1][1] = 10;
        A[1][2] = -7;
        A[1][3] = 5;
        A[1][4] = 9;
        A[2][1] = 3;
        A[2][2] = 6;
        A[2][3] = 0;
        A[2][4] = -9;
        A[3][1] = 9;
        A[3][2] = 3;
        A[3][3] = -2;
        A[3][4] = -1;
    }

    /* Now finding the elements of diagonal matrix */
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    printf("\nThe solution is:\n");
    for(i=1; i<=n; i++)
    {
        x[i]=A[i][n+1]/A[i][i];
        printf("\n x%d=%f\n",i,x[i]);
    }
    return(0);
}
