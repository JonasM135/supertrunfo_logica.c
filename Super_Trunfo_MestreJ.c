#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char Estado1[3], Estado2[3]; //Como "enter" conta como um caractere, usar [3] para aparecer 2 dígitos no "código"
    char Codigo1[4], Codigo2[4]; //Como "enter" conta como um caractere, usar [4] para aparecer 3 dígitos no "código"
    char Cidade1[30], Cidade2[30]; //Espaço suficiente para nomes compostos
    unsigned long int Populacao1, Populacao2; 
    float Area1, Area2;
    float PIB1, PIB2;
    int NPT1, NPT2; //Abreviação de Número de Pontos Turísticos
    float Dp1, Dp2; //Abreviação de Densidade populacional
    float PIBpc1, PIBpc2; //Abreviação de PIB per capita

    int opcao1, opcao2;
    float valor1C1 = 0, valor1C2 = 0, valor2C1 = 0, valor2C2 = 0;

    //inserir dados da primeira carta
    printf("\n***inserir dados da primeira carta***\n");

    // inserir Estado
    printf("Digite o Estado(UF): ");
    scanf("%2s", Estado1); //"%2s" para 2 caracteres (sigla do estado)

    // inserir o Codigo
    printf("Digite o Codigo(Ex: A01, B02): ");
    scanf("%3s", Codigo1); //"%3s" para os 3 dígitos do código

    // inserir o nome da cidade
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", Cidade1); // " %[^\n]" permite nomes com espaço

    // inserir o valor da população
    printf("População: ");
    scanf("%lu", &Populacao1);

    // inserir o valor da Área
    printf("Área: ");
    scanf("%f", &Area1);

    // inserir o valor do PIB
    printf("PIB (em bilhões): ");
    scanf("%f", &PIB1);

    // inserir o Número de Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &NPT1);

    //calcular Densidade Populacional e PIB per capita
    Dp1 = Populacao1 / Area1;
    PIBpc1 = (PIB1 * 1000000000) / (float)Populacao1;

    //inserir dados da segunda carta
    printf("\n***inserir dados da segunda carta***\n");

     // inserir Estado
    printf("Digite o Estado(UF): ");
    scanf("%2s", Estado2);

     // inserir Codigo
    printf("Digite o Codigo(Ex: A01, B02): ");
    scanf("%3s", Codigo2);

     // inserir o nome da cidade
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", Cidade2);

    // inserir o valor da população
    printf("População: ");
    scanf("%lu", &Populacao2);

    // inserir o valor da Área
    printf("Área: ");
    scanf("%f", &Area2);

    // inserir o valor do PIB
    printf("PIB (em bilhões): ");
    scanf("%f", &PIB2);

    // inserir o Número de Pontos Turísticos
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &NPT2);

    //calcular Densidade Populacional e PIB per capita
    Dp2 = Populacao2 / Area2;
    PIBpc2 = (PIB2 * 1000000000) / (float)Populacao2;

    //inserir o printf para aparecer toda a "carta" de forma uniforme, depois de se inserido as informações
    printf("\nCARTA 1:\n");
    printf("Estado: %s\n", Estado1);
    printf("Código: %s\n", Codigo1);
    printf("Cidade: %s\n", Cidade1);
    printf("População: %lu\n", Populacao1);
    printf("Área: %.2f Km²\n", Area1);//o ".2" entre os modificadores são para aparecer somente 2 digitos depois da virgula
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", NPT1);
    printf("Densidade populacional: %.2f hab/km²\n", Dp1);
    printf("PIB per capita: %.2f Reais\n", PIBpc1);

    printf("\nCARTA 2:\n");
    printf("Estado: %s\n", Estado2);
    printf("Código: %s\n", Codigo2);
    printf("Cidade: %s\n", Cidade2);
    printf("População: %lu\n", Populacao2);
    printf("Área: %.2f Km²\n", Area2);//o ".2" entre os modificadores são para aparecer somente 2 digitos depois da virgula
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Número de Pontos Turísticos: %d\n", NPT2);
    printf("Densidade populacional: %.2f hab/km²\n", Dp2);
    printf("PIB per capita: %.2f Reais\n", PIBpc2);

    //escolha dos atributos para comparação
    printf("\nEscolha o primeiro atributo para a comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional (vence o menor valor)\n");
    printf("6. PIB per capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Populacional (vence o menor valor)\n");
    printf("6. PIB per capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao2);

    //verificação se os atributos são iguais
    if (opcao1 == opcao2) {
        printf("Os atributos devem ser diferentes. Tente novamente.\n");
        return 0;
    }

    //associação do primeiro atributo com valores
    if (opcao1 == 1)
        valor1C1 = Populacao1, valor1C2 = Populacao2;
    else if (opcao1 == 2)
        valor1C1 = Area1, valor1C2 = Area2;
    else if (opcao1 == 3)
        valor1C1 = PIB1, valor1C2 = PIB2;
    else if (opcao1 == 4)
        valor1C1 = NPT1, valor1C2 = NPT2;
    else if (opcao1 == 5)
        valor1C1 = 1 / Dp1, valor1C2 = 1 / Dp2;
    else if (opcao1 == 6)
        valor1C1 = PIBpc1, valor1C2 = PIBpc2;

    //associação do segundo atributo com valores
    if (opcao2 == 1)
        valor2C1 = Populacao1, valor2C2 = Populacao2;
    else if (opcao2 == 2)
        valor2C1 = Area1, valor2C2 = Area2;
    else if (opcao2 == 3)
        valor2C1 = PIB1, valor2C2 = PIB2;
    else if (opcao2 == 4)
        valor2C1 = NPT1, valor2C2 = NPT2;
    else if (opcao2 == 5)
        valor2C1 = 1 / Dp1, valor2C2 = 1 / Dp2;
    else if (opcao2 == 6)
        valor2C1 = PIBpc1, valor2C2 = PIBpc2;

    //soma dos dois atributos escolhidos
    float soma1 = valor1C1 + valor2C1;
    float soma2 = valor1C2 + valor2C2;

    //exibição dos resultados
    printf("\n***Resultado***\n");
    printf("Carta 1 (%s): %.2f\n", Cidade1, soma1);
    printf("Carta 2 (%s): %.2f\n", Cidade2, soma2);

    if (soma1 > soma2)
        printf("Vitória da carta 1: %s\n", Cidade1);
    else if (soma2 > soma1)
        printf("Vitória da carta 2: %s\n", Cidade2);
    else
        printf("Empate!\n");

    return 0;
}
