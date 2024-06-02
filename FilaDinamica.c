#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FilaDinamica.h"

/*
** Função : Implementar um sistema de agendamento de consultas usando fila estática e fila dinâmica.
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 27.05.2024
** Observações: Null
*/


PacienteE cria_pacienteE(int id, char nome[]){
  PacienteE paciente;
  paciente.id = id;
  strcpy(paciente.nome, nome);
  paciente.ativo = 1;
  return paciente;
}

FilaDinamica* cria_fila_dinamica(){
  FilaDinamica *fila = malloc(sizeof(FilaDinamica));
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->quantidade = 0;
  return fila;
}

int is_empty_dinamica(FilaDinamica *fila){
  return (fila->quantidade == 0);
}

void adiciona_pacienteE(FilaDinamica *fila, PacienteE paciente) {
    Elemento *elemento = malloc(sizeof(Elemento));
    elemento->paciente = paciente;
    elemento->next = NULL;
    elemento->previous = fila->fim;

    if (fila->fim != NULL) {
        fila->fim->next = elemento;
    }

    fila->fim = elemento;

    if (fila->quantidade == 0) {
        fila->inicio = elemento;
    }

    fila->quantidade++;
}

PacienteE proximo_pacienteE(FilaDinamica *fila){
  Elemento *elemento;
  if(is_empty_dinamica(fila)){
    printf("Não há pacientes na fila!\n");
    return elemento->paciente;
  }
  elemento = fila->inicio;
  Elemento *aux = fila->inicio;
  fila->inicio = fila->inicio->next;
  free(aux);
  fila->quantidade--;
  return elemento->paciente;
}

void exibe_fila_pacientesE(FilaDinamica *fila){
  if(is_empty_dinamica(fila)){
    printf("Não há pacientes na fila!\n");
    return;
  }
  Elemento *aux = fila->inicio;
  int count = 1;
  printf("Pacientes = [ ");
  while(aux != NULL){
    printf("Paciente %d: %s, ", count, aux->paciente.nome);
    aux = aux->next;
    count++;
  }
  printf("\b\b ]\n");
}