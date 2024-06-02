#define MAX 5

typedef struct {
    int id;
    char nome[30];
    int ativo;
} PacienteM;

typedef struct {
    PacienteM vetor[MAX];
    int inicio;
    int fim;
    int quantidade;
} FilaEstatica;

FilaEstatica cria_fila_estatica();
PacienteM cria_pacienteM(int id, char nome[]);
int is_empty(FilaEstatica *fila);
int is_full_estatica(FilaEstatica *fila);
int adicionar_pacienteM(FilaEstatica *fila, PacienteM paciente);
PacienteM proximo_pacienteM(FilaEstatica *fila);
int quantidade_pacientesM(FilaEstatica *fila);
void exibe_fila_pacientesM(FilaEstatica *fila);