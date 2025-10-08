#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3];         // Estado (Ex: SP, RJ)
    char codigo_carta[5];   // Código da carta (Ex: A01, B02)
    char nome_cidade[50];   // Nome da cidade
    int populacao;          // População (em unidades, não em milhões, para o cálculo)
    float area;             // Área (em km²)
    float pib;              // PIB (em unidades, para o cálculo)
    int num_pontos_turisticos;
    float densidade_populacional; // Atributo calculado
    float pib_per_capita;         // Atributo calculado
} Carta;

// --- Função para calcular atributos derivados ---
void calcular_atributos(Carta *c) {
    // 1. Densidade Populacional: População / Área
    if (c->area > 0) {
        c->densidade_populacional = (float)c->populacao / c->area;
    } else {
        c->densidade_populacional = 0.0;
    }

    // 2. PIB per capita: PIB / População
    if (c->populacao > 0) {
        c->pib_per_capita = c->pib / (float)c->populacao;
    } else {
        c->pib_per_capita = 0.0;
    }
}

int main() {
    // --- 1. RECEBIMENTO DOS DADOS DE DUAS CARTAS (PRÉ-DEFINIDOS) ---

    // Carta 1: São Paulo (Dados Fixos)
    Carta carta1;
    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo_carta, "A01");
    strcpy(carta1.nome_cidade, "Sao Paulo");
    carta1.populacao = 12396372; // Ex: 12.396.372 habitantes
    carta1.area = 1521.1;        // Ex: 1.521,1 km²
    carta1.pib = 806990000000.0; // Ex: 806.99 bilhões de reais (em unidades)
    carta1.num_pontos_turisticos = 250;

    // Carta 2: Rio de Janeiro (Dados Fixos)
    Carta carta2;
    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo_carta, "B02");
    strcpy(carta2.nome_cidade, "Rio de Janeiro");
    carta2.populacao = 6775561;  // Ex: 6.775.561 habitantes
    carta2.area = 1200.3;        // Ex: 1.200,3 km²
    carta2.pib = 359140000000.0; // Ex: 359.14 bilhões de reais (em unidades)
    carta2.num_pontos_turisticos = 180;

    // --- 2. CALCULAR DENSIDADE POPULACIONAL E PIB PER CAPITA ---

    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    // --- Exibição dos Dados Cadastrados e Calculados ---
    printf("--- Dados das Cartas (Valores Calculados) ---\n");
    printf("Carta 1 - %s (%s):\n", carta1.nome_cidade, carta1.estado);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", carta1.pib_per_capita);

    printf("\nCarta 2 - %s (%s):\n", carta2.nome_cidade, carta2.estado);
    printf("  Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("  PIB per capita: R$ %.2f\n", carta2.pib_per_capita);
    printf("\n");

    // --- 3. ESCOLHA DO ATRIBUTO PARA COMPARAÇÃO (NO CÓDIGO) ---

    // **Escolha do atributo que será comparado aqui.**
    // Opções válidas: "Populacao", "Area", "PIB", "Densidade", "PIB per capita"
    const char *ATRIBUTO_ESCOLHIDO = "Densidade";

    float valor1, valor2;
    // 0 = Maior valor vence (padrão)
    // 1 = Menor valor vence (apenas para Densidade Populacional)
    int regra_vitoria_menor_valor = 0;
    
    // Define os valores a serem comparados com base no atributo escolhido
    if (strcmp(ATRIBUTO_ESCOLHIDO, "Populacao") == 0) {
        valor1 = (float)carta1.populacao;
        valor2 = (float)carta2.populacao;
    } else if (strcmp(ATRIBUTO_ESCOLHIDO, "Area") == 0) {
        valor1 = carta1.area;
        valor2 = carta2.area;
    } else if (strcmp(ATRIBUTO_ESCOLHIDO, "PIB") == 0) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
    } else if (strcmp(ATRIBUTO_ESCOLHIDO, "Densidade") == 0) {
        valor1 = carta1.densidade_populacional;
        valor2 = carta2.densidade_populacional;
        regra_vitoria_menor_valor = 1; // REQUISITO: Para Densidade, o MENOR valor vence
    } else if (strcmp(ATRIBUTO_ESCOLHIDO, "PIB per capita") == 0) {
        valor1 = carta1.pib_per_capita;
        valor2 = carta2.pib_per_capita;
    } else {
        printf("ERRO: Atributo de comparacao invalido (%s).\n", ATRIBUTO_ESCOLHIDO);
        return 1;
    }

    // --- 4. DETERMINAR A CARTA VENCEDORA E EXIBIR O RESULTADO ---

    printf("--- COMPARACAO DE CARTAS ---\n");
    printf("Atributo escolhido: %s\n\n", ATRIBUTO_ESCOLHIDO);

    // Exemplo de saída formatada (melhorando a usabilidade)
    printf("Carta 1 - %s (%s): ", carta1.nome_cidade, carta1.estado);
    if (strcmp(ATRIBUTO_ESCOLHIDO, "Populacao") == 0) printf("%.0f\n", valor1);
    else if (strcmp(ATRIBUTO_ESCOLHIDO, "PIB") == 0) printf("R$ %.0f\n", valor1);
    else printf("%.2f\n", valor1);
    
    printf("Carta 2 - %s (%s): ", carta2.nome_cidade, carta2.estado);
    if (strcmp(ATRIBUTO_ESCOLHIDO, "Populacao") == 0) printf("%.0f\n", valor2);
    else if (strcmp(ATRIBUTO_ESCOLHIDO, "PIB") == 0) printf("R$ %.0f\n", valor2);
    else printf("%.2f\n", valor2);
    

    // Lógica de vitória baseada na regra
    if (regra_vitoria_menor_valor == 1) {
        // Regra Especial (Menor valor vence):
        if (valor1 < valor2) {
            printf("\nResultado: Carta 1 (%s) venceu! (Menor Densidade)\n", carta1.nome_cidade);
        } else if (valor2 < valor1) {
            printf("\nResultado: Carta 2 (%s) venceu! (Menor Densidade)\n", carta2.nome_cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    } else {
        // Regra Padrão (Maior valor vence):
        if (valor1 > valor2) {
            printf("\nResultado: Carta 1 (%s) venceu! (Maior valor)\n", carta1.nome_cidade);
        } else if (valor2 > valor1) {
            printf("\nResultado: Carta 2 (%s) venceu! (Maior valor)\n", carta2.nome_cidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    
    printf("----------------------------------------\n");

    return 0;
}
