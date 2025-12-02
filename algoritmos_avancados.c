#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -----------------------------------------------------------
// Estrutura da sala (nó da árvore binária)
// -----------------------------------------------------------
typedef struct sala {
    char nome[50];
    struct sala *esq;  // caminho à esquerda
    struct sala *dir;  // caminho à direita
} Sala;

// -----------------------------------------------------------
// Função: criarSala
// Cria dinamicamente uma sala e retorna seu ponteiro.
// -----------------------------------------------------------
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

// -----------------------------------------------------------
// Função: explorarSalas
// Permite ao jogador navegar pela mansão interativamente,
// escolhendo caminhos à esquerda (e) ou direita (d).
// A exploração termina quando o jogador chega em um nó-folha.
// -----------------------------------------------------------
void explorarSalas(Sala* atual) {
    char opcao;

    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Se a sala for um nó-folha, encerra exploração
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Não há mais caminhos. Você chegou ao fim da exploração!\n");
            break;
        }

        printf("\nEscolha um caminho:\n");
        if (atual->esq != NULL) printf("  (e) Ir para a esquerda -> %s\n", atual->esq->nome);
        if (atual->dir != NULL) printf("  (d) Ir para a direita  -> %s\n", atual->dir->nome);
        printf("  (s) Sair da exploração\n");

        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esq != NULL) {
            atual = atual->esq;
        }
        else if (opcao == 'd' && atual->dir != NULL) {
            atual = atual->dir;
        }
        else if (opcao == 's') {
            printf("Você encerrou a exploração.\n");
            break;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

// -----------------------------------------------------------
// Função principal: monta manualmente a árvore da mansão
// e inicia a exploração.
// -----------------------------------------------------------
int main() {

    // Criando as salas da mansão
    Sala* hall        = criarSala("Hall de Entrada");
    Sala* salaEstar   = criarSala("Sala de Estar");
    Sala* escritorio  = criarSala("Escritório");
    Sala* cozinha     = criarSala("Cozinha");
    Sala* corredor    = criarSala("Corredor");
    Sala* biblioteca  = criarSala("Biblioteca");
    Sala* jardim      = criarSala("Jardim");

    // Montando a árvore binária (mapa da mansão)
    //
    //                Hall
    //               /    \
    //        SalaEstar   Escritório
    //         /     \        /     \
    //   Cozinha   Corredor  Biblioteca Jardim

    hall->esq = salaEstar;
    hall->dir = escritorio;

    salaEstar->esq = cozinha;
    salaEstar->dir = corredor;

    escritorio->esq = biblioteca;
    escritorio->dir = jardim;

    // Iniciar exploração
    printf("=== Detective Quest – Exploração da Mansão ===\n");
    explorarSalas(hall);

    return 0;
}
