#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    char descricao[100];
} Item;

typedef struct {
    char nome[30];
    char descricao[100];
    char mensagemEntrada[150];
} Area;

void adicionarItem(Item inventario[], int *quantidadeItens, const char *nome, const char *descricao) {
    if (*quantidadeItens < 10) {
        strcpy(inventario[*quantidadeItens].nome, nome);
        strcpy(inventario[*quantidadeItens].descricao, descricao);
        (*quantidadeItens)++;
    } else {
        printf("Inventário cheio! Não é possível adicionar mais itens.\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int matriz[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    Area norte = {
        "Área Norte",
        "Bem-vindo ao seu fim...",
        "Onde viverá como brasileiro: pagar impostos, pagar multa."
    };

    Area sul = {
        "Área Sul",
        "Bem-vindo às suas melhores lembranças...",
        "Onde tudo é feliz, onde não existe medo."
    };

    Area leste = {
        "Área Leste",
        "Bem-vindo à sua área favorita.",
        "Onde a comida sempre é a sua favorita."
    };

    Area oeste = {
        "Área Oeste",
        "Onde seus maiores pesadelos se tornam realidade...",
        "Onde seus traumas voltam a te assombrar."
    };

    char comando[50];
    int linha = 0;
    int coluna = 0;
    int reliquiaColetada = 0;

    Item inventario[10];
    int quantidadeItens = 0;

    printf("Digite direcao (norte, sul, leste, oeste), 'verificar item', 'inventario' ou 'sair':\n");
    printf("Posição inicial: [%d][%d], valor = %d\n", linha, coluna, matriz[linha][coluna]);
    printf("Zona Inicial: Onde tudo começa... e tudo termina.\n");
    printf("Saia em sua aventura, guerreiro!!!\n");

    while (1) {
        printf("> ");
        fgets(comando, sizeof(comando), stdin);
        comando[strcspn(comando, "\n")] = 0;

        if (strcmp(comando, "sair") == 0) {
            printf("Saindo do jogo...\n");
            break;
        }
        else if (strcmp(comando, "verificar item") == 0) {
            if (quantidadeItens > 0) {
                printf("Você possui %d item(ns) no inventário.\n", quantidadeItens);
            } else {
                printf("Seu inventário está vazio.\n");
                printf("Vai explorar!\n");
            }
        }
        else if (strcmp(comando, "inventario") == 0) {
            printf("\n--- INVENTÁRIO ---\n");
            if (quantidadeItens == 0) {
                printf("Você não possui nenhum item ainda.\n");
            } else {
                for (int i = 0; i < quantidadeItens; i++) {
                    printf("%d. %s - %s\n", i + 1, inventario[i].nome, inventario[i].descricao);
                }
            }
            printf("------------------\n");
        }
        else if (strcmp(comando, "norte") == 0) {
            if (linha > 0) {
                linha--;
                printf("Foi para o norte.\n");
                printf("%s\n%s\n%s\n", norte.nome, norte.descricao, norte.mensagemEntrada);
            } else {
                printf("Não pode ir para o norte, limite da matriz.\n");
            }
        }
        else if (strcmp(comando, "sul") == 0) {
            if (linha < 2) {
                linha++;
                printf("Foi para o sul.\n");
                printf("%s\n%s\n%s\n", sul.nome, sul.descricao, sul.mensagemEntrada);
            } else {
                printf("Não pode ir para o sul, limite da matriz.\n");
            }
        }
        else if (strcmp(comando, "leste") == 0) {
            if (coluna < 3) {
                coluna++;
                printf("Foi para o leste.\n");
                printf("%s\n%s\n%s\n", leste.nome, leste.descricao, leste.mensagemEntrada);
            } else {
                printf("Não pode ir para o leste, limite da matriz.\n");
            }
        }
        else if (strcmp(comando, "oeste") == 0) {
            if (coluna > 0) {
                coluna--;
                printf("Foi para o oeste.\n");
                printf("%s\n%s\n%s\n", oeste.nome, oeste.descricao, oeste.mensagemEntrada);
            } else {
                printf("Não pode ir para o oeste, limite da matriz.\n");
            }
        }
        else {
            printf("Comando desconhecido.\n");
        }
        if (linha == 2 && coluna == 1 && !reliquiaColetada) {
            adicionarItem(inventario, &quantidadeItens, "Relíquia Antiga", "Brilho dourado misterioso");
            reliquiaColetada = 1;
            printf("\nVocê encontrou a RELÍQUIA ANTIGA!\n");
            printf("Ela foi adicionada ao seu inventário.\n");
        }

        if (linha == 0 && coluna == 0 && reliquiaColetada) {
            printf("\nVocê retornou à Zona Inicial com a RELÍQUIA ANTIGA!\n");   
            printf("Parabéns, você venceu o jogo!\n");
            break; 
        }

        printf("Posição atual: [%d][%d], valor = %d\n", linha, coluna, matriz[linha][coluna]);
    }

    return 0;
}

