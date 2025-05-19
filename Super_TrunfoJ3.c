#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char Estado1[3], Estado2[3];
    char Codigo1[4], Codigo2[4];
    char Cidade1[30], Cidade2[30];
    unsigned long int Populacao1, Populacao2;
    float Area1, Area2;
    float PIB1, PIB2;
    int NPT1, NPT2;
    float Dp1, Dp2;
    float PIBpc1, PIBpc2;

    int opcao1, opcao2;
    float valor1C1 = 0, valor1C2 = 0, valor2C1 = 0, valor2C2 = 0;

    printf("\n--- Carta 1 ---\n");
    printf("Estado: "); scanf("%2s", Estado1);
    printf("Código: "); scanf("%3s", Codigo1);
    printf("Cidade: "); scanf(" %[^\n]", Cidade1);
    printf("População: "); scanf("%lu", &Populacao1);
    printf("Área: "); scanf("%f", &Area1);
    printf("PIB (em bilhões): "); scanf("%f", &PIB1);
    printf("Pontos turísticos: "); scanf("%d", &NPT1);

    Dp1 = Populacao1 / Area1;
    PIBpc1 = (PIB1 * 1000000000) / Populacao1;

    printf("\n--- Carta 2 ---\n");
    printf("Estado: "); scanf("%2s", Estado2);
    printf("Código: "); scanf("%3s", Codigo2);
    printf("Cidade: "); scanf(" %[^\n]", Cidade2);
    printf("População: "); scanf("%lu", &Populacao2);
    printf("Área: "); scanf("%f", &Area2);
    printf("PIB (em bilhões): "); scanf("%f", &PIB2);
    printf("Pontos turísticos: "); scanf("%d", &NPT2);

    Dp2 = Populacao2 / Area2;
    PIBpc2 = (PIB2 * 1000000000) / Populacao2;

    printf("\nEscolha o primeiro atributo:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    printf("6. PIB per capita\n");
    printf("Digite o número: ");
    scanf("%d", &opcao1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    printf("6. PIB per capita\n");
    printf("Digite o número: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("Os atributos devem ser diferentes. Tente novamente.\n");
        return 0;
    }

    // Primeiro atributo
    if (opcao1 == 1) {
        valor1C1 = Populacao1;
        valor1C2 = Populacao2;
    } else if (opcao1 == 2) {
        valor1C1 = Area1;
        valor1C2 = Area2;
    } else if (opcao1 == 3) {
        valor1C1 = PIB1;
        valor1C2 = PIB2;
    } else if (opcao1 == 4) {
        valor1C1 = NPT1;
        valor1C2 = NPT2;
    } else if (opcao1 == 5) {
        valor1C1 = 1 / Dp1;
        valor1C2 = 1 / Dp2;
    } else if (opcao1 == 6) {
        valor1C1 = PIBpc1;
        valor1C2 = PIBpc2;
    }

    // Segundo atributo
    if (opcao2 == 1) {
        valor2C1 = Populacao1;
        valor2C2 = Populacao2;
    } else if (opcao2 == 2) {
        valor2C1 = Area1;
        valor2C2 = Area2;
    } else if (opcao2 == 3) {
        valor2C1 = PIB1;
        valor2C2 = PIB2;
    } else if (opcao2 == 4) {
        valor2C1 = NPT1;
        valor2C2 = NPT2;
    } else if (opcao2 == 5) {
        valor2C1 = 1 / Dp1;
        valor2C2 = 1 / Dp2;
    } else if (opcao2 == 6) {
        valor2C1 = PIBpc1;
        valor2C2 = PIBpc2;
    }

    float soma1 = valor1C1 + valor2C1;
    float soma2 = valor1C2 + valor2C2;

    printf("\n--- Resultado ---\n");
    printf("Carta 1 (%s): %.2f\n", Cidade1, soma1);
    printf("Carta 2 (%s): %.2f\n", Cidade2, soma2);

    if (soma1 > soma2) {
        printf("Vitória da carta 1: %s\n", Cidade1);
    } else if (soma2 > soma1) {
        printf("Vitória da carta 2: %s\n", Cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}