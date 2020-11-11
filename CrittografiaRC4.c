#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 150

int main()
{
  char f[MAX];
  char c[MAX];
  char fc[MAX];
  char fd[MAX];
  int s = 6;
  int lunf, lunc;
  int i;
  time_t t;

  srand((unsigned) time(&t));
  while(s != 0)
  {
    printf("\nDigita\n");
    printf("1: Per inserire la frase\n");
    printf("2: Per inserire la chiave\n");
    printf("3: Per generare automaticamente la chiave\n");
    printf("4: Per visualizzare la frase cifrata:\n");
    printf("5: Per visualizzare la frase decifrata:\n");
    printf("0: Per terminare il programma\n");
    scanf("%i", &s);
    getchar();
    switch (s) {
      case 1:
      {
        printf("\nInserisci la frase di massimo 128 caratteri:\t");
        fgets(f, MAX, stdin);
        fflush(stdin);
        while(strlen(f) > 128)
        {
          printf("\nFrase troppo lunga, inserirne una di massimo 128 caratteri:\t");
          fgets(f, MAX, stdin);
          fflush(stdin);
        }
        lunf=strlen(f);
        f[lunf] = '\0';
        break;
      }

      case 2:
        printf("Inserisci la chiave di crittografia, che sia maggiore o uguale alla frase:\t");
        fgets(c, MAX, stdin);
        fflush(stdin);
        while(strlen(f) > strlen(c))
        {
          printf("\nChiave di crittografia troppo corta, inseriscila di nuovo:\t");
          fgets(c, MAX, stdin);
          fflush(stdin);
        }
        lunc=strlen(c);
        c[lunc] = '\0';

        break;

      case 3:
        for(i=0; i<lunf; i++)
        {
          c[i] = rand()%128;
        }
        lunc=strlen(c);
        break;

      case 4:

        for(i=0; i<lunc; i++)
        {
          fc[i] = f[i] ^ c[i];
        }
        printf("\nLa frase che hai inserito è:\t");
        puts(f);
        printf("\nLa chiave di crittografia è:\t");
        puts(c);
        printf("\nLa frase cifrata è:\t");
        puts(fc);
        break;

      case 5:

        for(i =0; i<strlen(fc); i++)
        {
          fd[i] = fc[i] ^ c[i];
        }

        printf("\nLa frase cifrata era:\t");
        puts(fc);
        printf("\nLa frase decifrata è:\t");
        puts(fd);
        break;

      case 0:
        break;

    }
  }

}
