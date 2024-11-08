#include <stdio.h>

typedef struct {
    char estado[30];
    int codigoCarta;
    char nomeCidade[50];
    long int populacao;
    float area;
    double pib;
    int pontosTuristicos;
} Carta;

void cadastrarCarta(Carta *c) {
    printf("\nDigite o código da carta: ");
    scanf("%d", &c->codigoCarta);
    printf("Digite o nome da cidade: ");
    getchar();  // Para limpar o buffer do teclado
    fgets(c->nomeCidade, sizeof(c->nomeCidade), stdin);
    
    printf("Digite o estado: ");
    fgets(c->estado, sizeof(c->estado), stdin);
    c->estado[strcspn(c->estado, "\n")] = '\0';  // Remover o '\n' do final
    printf("Digite a população: ");
    scanf("%ld", &c->populacao);
    printf("Digite a área: ");
    scanf("%f", &c->area);
    printf("Digite o PIB: ");
    scanf("%lf", &c->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);
}

void exibirCarta(Carta c) {
    printf("\nInformações da cidade %s (Código: %d):\n", c.nomeCidade, c.codigoCarta);
    printf("Estado: %s\n", c.estado);
    printf("População: %ld\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
}

void compararCartas(Carta c1, Carta c2, int criterio) {
    printf("\nComparando as cidades %s e %s\n", c1.nomeCidade, c2.nomeCidade);
    if (criterio == 1) {  // Comparar pela população
        if (c1.populacao > c2.populacao) {
            printf("%s venceu a comparação (maior população)\n", c1.nomeCidade);
        } else if (c1.populacao < c2.populacao) {
            printf("%s venceu a comparação (maior população)\n", c2.nomeCidade);
        } else {
            printf("As cidades possuem a mesma população.\n");
        }
    } else if (criterio == 2) {  // Comparar pela área
        if (c1.area > c2.area) {
            printf("%s venceu a comparação (maior área)\n", c1.nomeCidade);
        } else if (c1.area < c2.area) {
            printf("%s venceu a comparação (maior área)\n", c2.nomeCidade);
        } else {
            printf("As cidades possuem a mesma área.\n");
        }
    } else if (criterio == 3) {  // Comparar pelo PIB
        if (c1.pib > c2.pib) {
            printf("%s venceu a comparação (maior PIB)\n", c1.nomeCidade);
        } else if (c1.pib < c2.pib) {
            printf("%s venceu a comparação (maior PIB)\n", c2.nomeCidade);
        } else {
            printf("As cidades possuem o mesmo PIB.\n");
        }
    } else if (criterio == 4) {  // Comparar pela densidade populacional (menor densidade vence)
        float densidadeC1 = (float)c1.populacao / c1.area;
        float densidadeC2 = (float)c2.populacao / c2.area;
        if (densidadeC1 < densidadeC2) {
            printf("%s venceu a comparação (menor densidade populacional)\n", c1.nomeCidade);
        } else if (densidadeC1 > densidadeC2) {
            printf("%s venceu a comparação (menor densidade populacional)\n", c2.nomeCidade);
        } else {
            printf("As cidades possuem a mesma densidade populacional.\n");
        }
    }
}

int main() {
    Carta cidade1, cidade2;
    int criterio;

    printf("Cadastro da primeira carta:\n");
    cadastrarCarta(&cidade1);
    exibirCarta(cidade1);

    printf("\nCadastro da segunda carta:\n");
    cadastrarCarta(&cidade2);
    exibirCarta(cidade2);

    printf("\nEscolha o critério de comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Densidade Populacional\n");
    printf("Digite a opção: ");
    scanf("%d", &criterio);

    compararCartas(cidade1, cidade2, criterio);

    return 0;
}
