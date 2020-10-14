/* PROVA PRATICA DE COMPUTADOR - APROG 2017/2018
TURMA  : 1DB		NUMERO : 1170554          NOME   : Pedro Ivo Carneiro Macieira

*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

void mostrarVetor(int v[], int n)
{
     int i;
     for (i=0;i<n;i++)
         printf("\t%d",v[i]);
     printf("\n");
}

// Lê e retorna um valor compreendido entre li e ls
int lerValorLim(int li,int ls){
    int x;
    do{
        printf("\nDigite um valor entre %d e %d: ",li,ls);
        scanf("%d",&x);
    }while (x < li || x > ls);
    return x;
}
/*a )*/
void lerVetor(int v[],int *n)
{
    int i;
    printf("Quantos valores tera o vetor?");
    //Foi escolhido o numero entre 0 e 20 porque o MAX está definido como 20, e o exercicio pede valor positivo
    *n=lerValorLim(0,20);
    for(i=0;i<*n;i++)
    {
        printf("Introduza o valor correspondente a posição %d\n>:", i+1);
        v[i]=lerValorLim(0,100);
    }
}

/*b )*/
int prodElementosPares(int v[], int n)
{
    int cnt=1, i;
    for(i=0;i<n;i++)
    {
        if(v[i]%2==0)
        {
            cnt*=v[i];
            //Debug: printf("Isto correu: %d", cnt);
        }
    }
    if(cnt==1) return 0;//Para o caso de não haver elementos pares no vetor
    else return cnt;
}

/*c )*/
int copiar(int v1[], int v2[], int n, int val)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        if(v1[i]<val)
        {
            v2[j]=v1[i];
            j++;
        }
    }
    return j;
}

/*d )*/
int main()
{
    int n, val, qtd, prodPares;
    int vector1[MAX];
    int vetor2[MAX];
    lerVetor(vector1, &n);
    printf("Vetor 1:");
    mostrarVetor(vector1, n);
    printf("O produto dos elementos pares no vetor 1:%d", prodElementosPares(vector1, n));
    printf("\nQual o valor de referencia?\n>:");
    scanf("%d", &val);
    qtd=copiar(vector1, vetor2, n, val);
    if(qtd==0) printf("O vetor 1 nao tem valores abaixo do valor de referencia.");
    else printf("Vetor 2:");
    mostrarVetor(vetor2,qtd);
    return 0;
}
