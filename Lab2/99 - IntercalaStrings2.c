#include <stdio.h>

int main()
{
    char S[20001];
    char R[20001];
    int N, M;

    scanf("%20000s", S);

    scanf("%d %d", &N, &M);

    char *esquerda = S;      
    char *direita = S + N;   

    int iE = 0;
    int iD = 0;
    int iR = 0;

    while (iE < N && iD < M)
    {
        if (esquerda[iE] <= direita[iD])
        {
            R[iR++] = esquerda[iE++];
        }
        else
        {
            R[iR++] = direita[iD++];
        }
    }

    while (iE < N)
    {
        R[iR++] = esquerda[iE++];
    }

    while (iD < M)
    {
        R[iR++] = direita[iD++];
    }

    R[iR] = '\0';
    printf("%s\n", R);

    return 0;
}