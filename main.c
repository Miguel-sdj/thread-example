#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sizeArray = 0; // tamanho do array definido globalmente

#define TAM_THREADS 3

void *mediaNumero(int x[]) {

        float mediaTotal = 0.0;

        for (int i = 0; i < sizeArray; i++)
        {
                mediaTotal += x[i];
        }

        mediaTotal = mediaTotal / sizeArray;

        printf("The average value is %.2f\n", mediaTotal);

}

void *menorNumero(int tempArray[]) {

        int menorAtual = 0;
        int isFirst = 0;

        for (int i = 0; i < sizeArray; i++)
        {
                if (isFirst == 0)
                {
                        menorAtual = tempArray[i];
                        isFirst = 1;
                }

                if (tempArray[i] < menorAtual)
                {
                        menorAtual = tempArray[i];
                }
        }

        printf("The minimum value is %d\n", menorAtual);

}

void *maiorNumero(int tempArray[]) {
        int maiorAtual = 0;

        for (int i = 0; i < sizeArray; i++)
        {

                if (tempArray[i] > maiorAtual)
                {
                        maiorAtual = tempArray[i];
                }
        }

        printf("The maximum value is %d\n", maiorAtual);

}

int main()
{
        int i;
        int numberLoop;
        scanf("%d", &numberLoop);

        int arrayNumber[numberLoop];
        for (i = 0; i < numberLoop; i++)
        {
                scanf("%d", &arrayNumber[i]);
        }
        sizeArray = i;

        pthread_t thread1, thread2, thread3;
        pthread_create(&thread1, NULL, mediaNumero, &arrayNumber);
        pthread_create(&thread2, NULL, menorNumero, &arrayNumber);
        pthread_create(&thread3, NULL, maiorNumero, &arrayNumber);

        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        pthread_join(thread3, NULL);

        return 0;
}
