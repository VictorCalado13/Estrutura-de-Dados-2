#include <stdio.h>
#include <stdlib.h>

// Estrutura básica do No
typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
    int altura;
} No;

// Encontrar qual maior valor
int maior(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

// Altura do nó 
int altura(No *n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

No* criarNo(int valor) { 

    No* novoNo = (No*) malloc(sizeof(No)); //alocação dinamica na memória
    novoNo->valor = valor;
    novoNo->esq = NULL; //Inicia vazio
    novoNo->dir = NULL; //Inicia vazio
    novoNo->altura = 1; // Novo nó começa com altura 1
    return novoNo;
}

// Lado esquerdo maior que o direito
No* rotacaoDireita(No* y) { 
    // y-> raiz da subarvore onde a rotação será realizada
    
    No* x = y->esq;
    No* T2 = x->dir;

    // Realizando a rotação
    x->dir = y;
    y->esq = T2;

    // Atualizando alturas
    y->altura = maior(altura(y->esq), altura(y->dir)) + 1;
    x->altura = maior(altura(x->esq), altura(x->dir)) + 1;

    printf("Rotação Direita\n");
    return x; // Novo nó raiz
}

// Função para realizar a rotação à esquerda
No* rotacaoEsquerda(No* x) {
    No* y = x->dir;
    No* T2 = y->esq;

    // Realizando a rotação
    y->esq = x;
    x->dir = T2;

    // Atualizando alturas
    x->altura = maior(altura(x->esq), altura(x->dir)) + 1;
    y->altura = maior(altura(y->esq), altura(y->dir)) + 1;

    printf("Rotação Esquerda\n");
    return y; // Novo nó raiz
}

// Função para obter o fator de balanceamento de um nó
int balancear(No* n) {
    if (n == NULL)
        return 0;
    return altura(n->esq) - altura(n->dir);
}

// Função para inserir um novo valor na árvore AVL
No* inserir(No* no, int valor) {

    if (no == NULL)
        return criarNo(valor);

    if (valor < no->valor)
        no->esq = inserir(no->esq, valor);

    else if (valor > no->valor)

        no->dir = inserir(no->dir, valor);

    else // Valores iguais não são permitidos
        return no;

    // Atualizar a altura do nó atual
    no->altura = 1 + maior(altura(no->esq), altura(no->dir));

    // Obter o fator de balanceamento deste nó para verificar se ele está desbalanceado
    int balanceamento = balancear(no);

    // Caso 1: Rotação Direita Simples (Desbalanceamento à esquerda)
    if (balanceamento > 1 && valor < no->esq->valor)
        return rotacaoDireita(no);

    // Caso 2: Rotação Esquerda Simples (Desbalanceamento à direita)
    if (balanceamento < -1 && valor > no->dir->valor)
        return rotacaoEsquerda(no);

    // Caso 3: Rotação Dupla Direita (Esquerda-Direita)
    if (balanceamento > 1 && valor > no->esq->valor) {
        no->esq = rotacaoEsquerda(no->esq);
        return rotacaoDireita(no);
    }

    // Caso 4: Rotação Dupla Esquerda (Direita-Esquerda)
    if (balanceamento < -1 && valor < no->dir->valor) {
        no->dir = rotacaoDireita(no->dir);
        return rotacaoEsquerda(no);
    }

    return no; // Retorna o nó sem modificações se estiver balanceado
}

// Função para fazer o percurso em pré-ordem da árvore
void preOrdem(No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}


int main() {
    No* raiz = NULL;
    int valor;

    printf("Informe os valores (0 para encerrar):\n");
    while (1) {
        scanf("%d", &valor);
        //Se for 0 encerra o programa
        if (valor == 0) 
            break;
        raiz = inserir(raiz, valor);
    }

    printf("Percurso em pré-ordem da árvore AVL:\n");
    preOrdem(raiz);
    printf("\n");

    return 0;
}
