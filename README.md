# Repositório da matéria Algoritmos e Estruturas de Dados 2

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
