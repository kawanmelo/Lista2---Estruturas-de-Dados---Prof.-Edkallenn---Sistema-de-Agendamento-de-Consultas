#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"
#include "FilaDinamica.h"

/*
** Função : Implementar um sistema de agendamento de consultas usando fila estática e fila dinâmica.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 27.05.2024
** Observações: Null
*/


void limpa_tela() {
    printf("Aperte enter para continuar...");
    getchar();
    system("clear");
}

int main() {
    FilaEstatica filaMedico = cria_fila_estatica();
    FilaDinamica *filaEnfermagem = cria_fila_dinamica();

    int contadorPacientesMedico = 0;
    int opcao;
    int id;
    char nome[30];
    PacienteM paciente;
    PacienteE pacienteE;

    do {
        printf("\n--- Sistema de Agendamento de Consultas ---\n");
        printf("1. Adicionar paciente na fila do Médico\n");
        printf("2. Adicionar paciente na fila da Enfermagem\n");
        printf("3. Chamar próximo paciente da fila do Médico\n");
        printf("4. Chamar próximo paciente da fila da Enfermagem\n");
        printf("5. Exibir fila de pacientes do Médico\n");
        printf("6. Exibir fila de pacientes da Enfermagem\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                if(contadorPacientesMedico>=5){
                    printf("Atendimento com Médicos esgotado!\n");
                    limpa_tela();
                    break;
                }else {
                    printf("ID do paciente: ");
                    scanf("%d", &id);
                    getchar(); // Limpar o buffer do teclado
                    printf("Nome do paciente: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = 0; // Remover o caractere de nova linha
                    paciente = cria_pacienteM(id, nome);
                    adicionar_pacienteM(&filaMedico, paciente);
                    printf("Paciente adicionado na fila do Médico!\n");
                    contadorPacientesMedico++;
                }
                limpa_tela();
                break;
            case 2:
                printf("ID do paciente: ");
                scanf("%d", &id);
                getchar(); // Limpar o buffer do teclado
                printf("Nome do paciente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0; // Remover o caractere de nova linha
                pacienteE = cria_pacienteE(id, nome);
                adiciona_pacienteE(filaEnfermagem, pacienteE);
                printf("Paciente adicionado na fila da Enfermagem!\n");
                limpa_tela();
                break;
            case 3:
              if(filaMedico.quantidade == 0){
                printf("Não há pacientes na fila!\n");
                limpa_tela();
                break;
              }
                paciente = proximo_pacienteM(&filaMedico);
                if (paciente.ativo) {
                    printf("Chamando o próximo paciente do Médico: %d - %s\n", paciente.id, paciente.nome);
                }
                limpa_tela();
                break;
            case 4:
                pacienteE = proximo_pacienteE(filaEnfermagem);
                if (pacienteE.ativo == 1) {
                    printf("Chamando o próximo paciente da Enfermagem: %d - %s\n", pacienteE.id, pacienteE.nome);
                }
                limpa_tela();
                break;
            case 5:
                printf("Fila de pacientes do Médico: \n");
                exibe_fila_pacientesM(&filaMedico);
                limpa_tela();
                break;
            case 6:
                printf("Fila de pacientes da Enfermagem: \n");
                exibe_fila_pacientesE(filaEnfermagem);
                limpa_tela();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                limpa_tela();
                break;
        }
    } while (opcao != 0);
  return 0;
}

