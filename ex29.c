#include    <stdio.h>

int main(void)
{
    float refrigerantes[5], valor[6], troco;
    float saldo = 0;
    int TROCO [6], indice, moeda, cont;
    int caso = 1;

    refrigerantes[0]=3.50;
    refrigerantes[1]=5.80;
    refrigerantes[2]=2.10;
    refrigerantes[3]=1.90;
    refrigerantes[4]=0.70;
    valor[0] = 0.01;
    valor[1] = 0.05;
    valor[2] = 0.10;
    valor[3] = 0.25;
    valor[4] = 0.50;
    valor[5] = 1.00;

    while(caso)
    {
        printf("\n\nSeu saldo e de: R$%.2f\n\n", saldo);
        printf("Escolha a opcao:\n\n");
        printf("0 - Sair\n");
        printf("1 - Depositar Moeda\n");
        printf("2 - Escolher refrigerante\n\n");
        printf("Opcao:");
        scanf("%i", &caso);

        switch(caso)
        {
            case 1:
                printf("\n\nDeposite a sua moeda\n\n");
                printf("0 - 1 Centavo\n");
                printf("1 - 5 Centavos\n");
                printf("2 - 10 Centavos\n");
                printf("3 - 25 Centavos\n");
                printf("4 - 50 Centavos\n");
                printf("5 - 1 Real\n");
                printf("Moeda:");
                scanf("%i", &moeda);
                saldo = saldo + valor[moeda];
				break;
            case 2:
                printf("\n\nEscolha o Refrigerante\n\n");
                printf("0 - Coca-Cola - R$3.50\n");
                printf("1 - Ice - R$5.80\n");
                printf("2 - Guarana - R$2.10\n");
                printf("3 - Suco - R$1.90\n");
                printf("4 - Cafe - R$0.70\n");
                printf("\nRefrigerante:");
                scanf("%i", &indice);

                if(saldo >= refrigerantes[indice])
                {
                    troco = saldo - refrigerantes[indice];
                    cont = 5;
                    while (cont >= 0)
                    {
                        TROCO[cont] = 0;
                        while(troco >= valor[cont])
                        {
                            TROCO[cont] = TROCO[cont]+1;
                            troco = troco - valor[cont];
						}
                        cont = cont - 1;
                    }
                    cont = 0;
                    printf("\n\nO seu troco e:\n\n");
                    while(cont<6)
                    {
                        printf("Moedas de R$%.2f: %i\n", valor[cont], TROCO[cont]);
                        cont++;
                     }
                     saldo = 0;
                }
                else
                {
                    printf("\n\n====== Saldo Insuficiente ======");
                }
                break;
        }
        if(caso>2)
        {
            printf("Opcao invalida!\n\n");
        }
    }
    if(saldo !=0)
    {
        cont = 5;
        while(cont >= 0)
        {
            TROCO[cont] = 0;
            while(saldo >= valor[cont])
            {
                TROCO[cont] = TROCO[cont]+1;
                saldo = saldo - valor[cont];
            }
            cont = cont - 1;
         }
         cont = 0;
         printf("\n\nO seu troco e\n\n");
         while(cont<6)
         {
             printf("Moedas de R$%.2f: %i\n", valor[cont], TROCO[cont]);
             cont++;
         }
         saldo = 0;
     }
     printf("\n\nObrigado! Volte sempre!\n\n");
     return 0;
}

