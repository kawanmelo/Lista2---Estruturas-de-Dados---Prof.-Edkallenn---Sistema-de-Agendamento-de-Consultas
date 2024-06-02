typedef struct {
    int id;
    char nome[30];
    int ativo;
} PacienteE;

typedef struct elemento Elemento;

struct elemento {
    PacienteE paciente;
    Elemento *next;
    Elemento *previous;
};

typedef struct {
    Elemento *inicio;
    Elemento *fim;
    int quantidade;
} FilaDinamica;

PacienteE cria_pacienteE(int id, char nome[]);
FilaDinamica* cria_fila_dinamica();
int is_empty_dinamica(FilaDinamica *fila);
void adiciona_pacienteE(FilaDinamica *fila, PacienteE paciente);
PacienteE proximo_pacienteE(FilaDinamica *fila);
void exibe_fila_pacientesE(FilaDinamica *fila);