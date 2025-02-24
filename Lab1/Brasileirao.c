#include <stdio.h>
#include <string.h>

void nomeiaTimes(char v[][100], int n);
int obtemIndiceDoTime(char v[][100], int n, char t[]);

//  ================ TODO ================
// Em caso de empate por pontos entre dois clubes, os critérios de
// desempate foram aplicados na seguinte ordem:
// • Número de vitórias;
// • Saldo de gols;
// • Gols pró (marcados);

int main()
{
    int N;
    scanf("%d", &N);

    char times[N][100];
    int pontos[N];
    int vitorias[N];
    int empates[N];
    int derrotas[N];
    int saldoDeGols[N];
    int golsPro[N];
    int golsContra[N];

    memset(pontos, 0, sizeof(pontos));
    memset(vitorias, 0, sizeof(vitorias));
    memset(empates, 0, sizeof(empates));
    memset(derrotas, 0, sizeof(derrotas));
    memset(saldoDeGols, 0, sizeof(saldoDeGols));
    memset(golsPro, 0, sizeof(golsPro));
    memset(golsContra, 0, sizeof(golsContra));

    nomeiaTimes(times, N);

    int qPartidas = N * (N - 1);
    char timeM[100], timeV[100];
    int golsM, golsV;
    for (int i = 0; i < qPartidas; i++)
    {
        scanf("%s %d x %d %s", timeM, &golsM, &golsV, timeV);

        int iTimeM = obtemIndiceDoTime(times, N, timeM);
        int iTimeV = obtemIndiceDoTime(times, N, timeV);

        if (golsM > golsV)
        {
            pontos[iTimeM] += 3;
            vitorias[iTimeM]++;
            derrotas[iTimeV]++;
        }
        if (golsM < golsV)
        {
            pontos[iTimeV] += 3;
            vitorias[iTimeV]++;
            derrotas[iTimeM]++;
        }
        if (golsM == golsV)
        {
            pontos[iTimeM] += 1;
            pontos[iTimeV] += 1;
            empates[iTimeM]++;
            empates[iTimeV]++;
        }

        saldoDeGols[iTimeM] += golsM - golsV;
        saldoDeGols[iTimeV] += golsV - golsM;

        golsPro[iTimeM] += golsM;
        golsPro[iTimeV] += golsV;

        golsContra[iTimeM] += golsV;
        golsContra[iTimeV] += golsM;
    }

    for (int i = 0; i < N; i++)
    {
        printf("%s: %d %d %d %d %d %d %d\n", times[i],
               pontos[i], vitorias[i], empates[i], derrotas[i],
               saldoDeGols[i], golsPro[i], golsContra[i]);
    }

    return 0;
}

void nomeiaTimes(char v[][100], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s", v[i]);
    }
}

int obtemIndiceDoTime(char v[][100], int n, char t[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(v[i], t) == 0)
            return i;
    }
}

// ================ SAIDA ================
// CAMPEAO: Equipe-A
// VICE-CAMPEAO: Equipe-C
// REBAIXADOS: Equipe-D, Equipe-F, Equipe-B e Equipe-E
// TABELA FINAL:
// Equipe-A 19 6 1 3 9 28 19
// Equipe-C 16 4 4 2 0 20 20
// Equipe-E 13 3 4 3 -1 18 19
// Equipe-B 12 3 3 4 -3 17 20
// Equipe-F 10 2 4 4 -3 18 21
// Equipe-D 9 1 6 3 -2 19 2
