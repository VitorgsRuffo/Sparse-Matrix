
typedef struct elemento Elemento;

struct elemento{
    int lin;
    int col;
    int valor;
    Elemento* prox_lin;
    Elemento* prox_col;
};

void menu(void);

int Inserir_Elemento(Elemento** vet_lin, int N, Elemento** vet_col, int M, Elemento el);

int Mostrar_Matriz(Elemento** vet_lin, int N, Elemento** vet_col, int M);
