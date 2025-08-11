#include <stdio.h>

int main() {
    // --- Variáveis para a Carta 1 ---
    char estado1;
    char codigo_carta1[5];
    char nome_cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    
    // --- Variáveis para a Carta 2 ---
    char estado2;
    char codigo_carta2[5];
    char nome_cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    
    // --- Cadastro da Primeira Carta ---
    printf("--- Cadastro da PRIMEIRA Carta ---\n");

    printf("Estado (A a H): ");
    scanf(" %c", &estado1); 
    // Após ler o caractere, limpamos o buffer
    scanf("%*[^\n]"); // Lê e descarta o resto da linha.
    scanf("%*c");     // Lê e descarta o \n

    printf("Código da Carta (ex: A01): ");
    scanf("%s", codigo_carta1);
    // Após ler o codigo, limpamos o buffer
    scanf("%*[^\n]"); 
    scanf("%*c");

    // Problema resolvido com ajuda da IA, após inserir o Estado (A a H) o código pulava direto para o nome da cidade.

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade1);
    // Para o nome da cidade, o %[^\n] já faz a limpeza

    printf("População em milhões: ");
    scanf("%d", &populacao1);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Área (em km²): ");
    scanf("%f", &area1);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("PIB: ");
    scanf("%f", &pib1);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);
    scanf("%*[^\n]");
    scanf("%*c");


    // --- Cadastro da Segunda Carta ---
    printf("\n--- Cadastro da SEGUNDA Carta ---\n");

    printf("Estado (A a H): ");
    scanf(" %c", &estado2);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Código da Carta (ex: B02): ");
    scanf("%s", codigo_carta2);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade2);

    printf("População em milhões: ");
    scanf("%d", &populacao2);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Área (em km²): ");
    scanf("%f", &area2);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("PIB: ");
    scanf("%f", &pib2);
    scanf("%*[^\n]");
    scanf("%*c");

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    scanf("%*[^\n]");
    scanf("%*c");

    // --- Exibição das Cartas Cadastradas ---
    printf("\n--- Dados das Cartas Cadastradas ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo_carta1);
    printf("Nome da Cidade: %s\n", nome_cidade1);
    printf("População: %d milhões\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo_carta2);
    printf("Nome da Cidade: %s\n", nome_cidade2);
    printf("População: %d milhões\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);


    return 0;
}
