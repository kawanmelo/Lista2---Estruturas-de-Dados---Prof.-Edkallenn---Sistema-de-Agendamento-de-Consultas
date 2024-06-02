#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaEstatica.h"

/*
** Função : Implementar um sistema de agendamento de consultas usando fila estática e fila dinâmica.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 27.05.2024
** Observações: Null
*/


FilaEstatica cria_fila_estatica(){
  FilaEstatica fila;
  fila.inicio = 0;
  fila.fim = -1;
  fila.quantidade = 0;
  return fila;
}

PacienteM cria_pacienteM(int id, char nome[]){
  PacienteM paciente;
  paciente.id = id;
  strcpy(paciente.nome, nome);
  paciente.ativo = 1;
  return paciente;
}

int is_empty(FilaEstatica *fila){
  return (fila->quantidade == 0);
}

int is_full_estatica(FilaEstatica *fila){
  return (fila->quantidade == MAX);
}

int adicionar_pacienteM(FilaEstatica *fila, PacienteM paciente){
  if(is_full_estatica(fila)){
    printf("Fila cheia!\n");
    return 0;
  }
  fila->fim = (fila->fim + 1) % MAX;
  fila->vetor[fila->fim] = paciente;
  fila->quantidade++;
  return 1;
}

PacienteM proximo_pacienteM(FilaEstatica* fila){
  PacienteM paciente;
  if(is_empty(fila)){
    printf("Não há pacientes na fila!\n");
    return paciente;
  }
  paciente = fila->vetor[fila->inicio];
  fila->inicio = (fila->inicio + 1) % MAX;
  fila->quantidade--;
  return paciente;
}

int quantidade_pacientesM(FilaEstatica *fila){
  return fila->quantidade;
}

void exibe_fila_pacientesM(FilaEstatica *fila){
  if(is_empty(fila)){
    printf("Não há pacientes na fila!\n");
    return;
  }
  int i = fila->inicio;
  printf("[ ");
  for(int count = 0; count < fila->quantidade; count++){
    printf("Paciente %d: %s, ", count, fila->vetor[i].nome);
    i = (i + 1) % MAX;
  }
  printf("\b\b ]\n");
}