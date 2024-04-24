#include <stdio.h>

int tamanhoArray(int x);
void calcularValores(int array[], int array2[], int index[], int valor);

int main(void)
{
    int valor = 0;

    printf("quantos numeros serao digitados: ");
    scanf("%i", &valor);

    int tamanhoTotal =tamanhoArray(valor);

    int array[valor];

    for (int i = 0; i < valor; i++)
    {
        printf("digite um numero: \n");
        scanf("%i",&array[i]);
    }


    int array2[tamanhoTotal];
    int index[] = {0, 0, 0};
    calcularValores(array, array2, index, valor);

    printf("|");
    for (int x = 0; x < tamanhoTotal; x++)
    {
        printf(" %i |",array2[x]);
    }

    printf("\n");
}

int tamanhoArray(int x)
{
    if (x == 1)
    {
        return 1;
    }
    return x + tamanhoArray(x-1);
}

void calcularValores(int array[], int array2[], int index[], int valor)
{

    if (index[2] == valor)
    {
        index[1]++;
        index[2] = index[1];

        if (index[1] == valor)
        {
            return;
        }
    }

    array2[index[0]] = array[index[1]] * array[index[2]];
    index[0]++;
    index[2]++;

    calcularValores(array, array2, index, valor);

    return;
}