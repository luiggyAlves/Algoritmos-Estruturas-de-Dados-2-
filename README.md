# Repositório de Algoritmos e Estruturas de Dados 2
Este repositório tem como intuito documentar meus aprendizados e permitir a revisita posterior aos conteúdos referentes à matéria Algoritmos e Estruturas de Dados 2, ministrada pelo Prof. João Marcos no Instituto de Computação (IComp) da Universidade Federal do Amazonas (UFAM), para os discentes do terceiro período do curso de Ciência da Computação.

## Árvore Binária de Pesquisa (ABP)

### Tipo Principal

**`ArvBin`** — Alias para `struct NO*`. Usado como `ArvBin*` nas funções, formando indiretamente um ponteiro duplo (`NO**`) que permite modificar o ponteiro raiz da árvore diretamente.

---

### Funções

#### Criação e Destruição

**`ArvBin* cria_ArvBin()`**
Aloca e retorna um ponteiro para a raiz da árvore, inicializado com `NULL`. Deve ser chamada antes de qualquer outra operação.

**`void libera_ArvBin(ArvBin* raiz)`**
Libera toda a memória da árvore. Percorre recursivamente todos os nós (da folha até a raiz) e os desaloca, liberando por fim a própria raiz.

---

#### Inserção e Remoção

**`int insere_ArvBin(ArvBin* raiz, int valorInserido)`**
Insere um novo nó com o valor informado respeitando as regras da ABP (menores à esquerda, maiores à direita). Valores duplicados são ignorados. Retorna `1` em caso de sucesso e `0` se o valor já existir na árvore.

**`int remove_ArvBin(ArvBin* raiz, int valorRemovido)`**
Remove o nó com o valor informado. Cobre três casos: nó folha, nó raiz e nó interno (neste último, substitui pelo filho mais à direita da subárvore esquerda para manter a estrutura da ABP). Retorna `1` em caso de sucesso e `0` se o valor não for encontrado ou a árvore estiver vazia.

> Função auxiliar interna: **`struct NO* remove_atual(struct NO* atual)`** — realiza a remoção efetiva do nó e retorna o substituto adequado.

---

#### Consulta

**`int consulta_ArvBin(ArvBin* raiz, int valorBuscado)`**
Busca um valor na árvore percorrendo-a pelas regras da ABP. Retorna `1` se o valor for encontrado e `0` caso contrário.

---

#### Informações da Árvore

**`int estaVazia_ArvBin(ArvBin* raiz)`**
Verifica se a árvore está vazia. Retorna `1` se estiver vazia (raiz não inicializada ou apontando para `NULL`) e `0` caso contrário.

**`int totalNO_ArvBin(ArvBin* raiz)`**
Retorna o número total de nós da árvore por meio de percurso recursivo.

**`int altura_ArvBin(ArvBin* raiz)`**
Retorna a altura da árvore, definida como o número de nós no maior caminho da raiz até uma folha.

---

#### Percursos

**`void preOrdem_ArvBin(ArvBin* raiz)`**
Percorre e imprime os nós na ordem: **raiz → esquerda → direita**.

**`void emOrdem_ArvBin(ArvBin* raiz)`**
Percorre e imprime os nós na ordem: **esquerda → raiz → direita**. Produz os valores em ordem crescente.

**`void posOrdem_ArvBin(ArvBin* raiz)`**
Percorre e imprime os nós na ordem: **esquerda → direita → raiz**.

---

## Árvore AVL

A AVL é uma Árvore Binária de Pesquisa **balanceada automaticamente**. Como a busca em ABP depende do balanceamento — uma árvore degenerada tem custo O(N) em vez de O(log N) — a AVL mantém o **fator de balanceamento** de cada nó (diferença entre as alturas da subárvore esquerda e direita) sempre entre `-1` e `1`. Quando uma inserção ou remoção viola esse invariante, a árvore se corrige por meio de **rotações**.

### Tipo Principal

**`ArvAVL`** — Estruturalmente idêntico a `ArvBin`. O nó interno (`struct NO`) possui um campo extra `alt` que armazena a altura da subárvore enraizada naquele nó, evitando recalcular a cada operação.

---

### Funções Auxiliares

Usadas internamente para agilizar o cálculo do balanceamento. Complexidade O(1) em todas elas.

**`int alt_NO(struct NO* no)`**
Retorna a altura armazenada no nó. Se o nó for `NULL`, retorna `-1` (conveniência para calcular alturas em folhas).

**`int fatorBalanceamento_NO(struct NO* no)`**
Retorna o fator de balanceamento do nó: `altura(esq) - altura(dir)`. Valores fora do intervalo `[-1, 1]` indicam que uma rotação é necessária.

**`int maior(int x, int y)`**
Retorna o maior entre dois inteiros. Usada para calcular a nova altura de um nó após uma rotação.

---

### Rotações

As rotações são o mecanismo de balanceamento da AVL. São acionadas sempre que o fator de balanceamento de algum ancestral do nó inserido passa a `-2` ou `+2`. Como todas as rotações apenas atualizam ponteiros, **a complexidade de todas é O(1)**.

Existem dois tipos:

- **Rotações simples** — aplicadas quando o nó desbalanceado (A), seu filho (B) e o neto (C) estão todos inclinados no mesmo sentido (todos à esquerda ou todos à direita).
- **Rotações duplas** — aplicadas quando A e B estão inclinados em sentidos opostos ao neto C (padrão em ziguezague). Equivalem a duas rotações simples encadeadas.

---

#### `void RotacaoLL(ArvAVL* A)` — Rotação simples à direita

Ocorre quando um novo nó C é inserido na **subárvore esquerda do filho esquerdo** de A, que fica desbalanceado. A, B e C formam uma "lista" inclinada para a esquerda.

**Mecânica:** o filho B sobe para a posição de A. A subárvore direita de B (que é menor que B mas maior que A) torna-se a subárvore esquerda de A. A passa a ser a subárvore direita de B.

```
    A                B
   / \              / \
  B   T4    →     C    A
 / \                  / \
C   T3               T3  T4
```

Após a rotação, as alturas de A e de B são recalculadas (da folha para a raiz, usando `maior + 1`).

---

#### `void RotacaoRR(ArvAVL* A)` — Rotação simples à esquerda

Espelho da RotacaoLL. Ocorre quando o novo nó C é inserido na **subárvore direita do filho direito** de A. A, B e C formam uma "lista" inclinada para a direita.

**Mecânica:** B sobe para a posição de A. A subárvore esquerda de B torna-se a subárvore direita de A. A passa a ser a subárvore esquerda de B.

```
  A                  B
 / \                / \
T4   B      →      A   C
    / \            / \
   T3   C         T4  T3
```

Após a rotação, as alturas de A e de B são recalculadas.

---

#### `void RotacaoLR(ArvAVL* A)` — Rotação dupla à direita

Ocorre quando o novo nó C é inserido na **subárvore direita do filho esquerdo** de A — padrão em ziguezague (A inclina à esquerda, B inclina à direita).

**Mecânica:** aplica primeiro uma `RotacaoRR` em B (filho esquerdo de A), fazendo C subir no lugar de B. Em seguida aplica uma `RotacaoLL` em A, fazendo C subir para a raiz. Resultado: C ocupa a posição intermediária, com A como subárvore direita e B como subárvore esquerda.

```
  A              A             C
 /              /             / \
B      →       C     →       B   A
 \            /
  C          B
```

---

#### `void RotacaoRL(ArvAVL* A)` — Rotação dupla à esquerda

Espelho da RotacaoLR. Ocorre quando o novo nó C é inserido na **subárvore esquerda do filho direito** de A — ziguezague invertido.

**Mecânica:** aplica primeiro uma `RotacaoLL` em B (filho direito de A), fazendo C subir no lugar de B. Em seguida aplica uma `RotacaoRR` em A. Resultado: C ocupa a posição intermediária, com A como subárvore esquerda e B como subárvore direita.

```
A                A                C
 \                \              / \
  B      →         C     →      A   B
 /                  \
C                    B
```
