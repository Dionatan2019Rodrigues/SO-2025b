#include "processo.h"
#include <stdio.h>

processo_t tabela_processos[MAX_PROCESSOS];
int processo_atual = -1;  // -1 = nenhum processo executando

void processos_inicia(void) {
    printf("PROCESSOS: Iniciando tabela...\n");
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        tabela_processos[i].pid = -1;  // Slot vazio
        tabela_processos[i].estado = MORTO;
    }
}

int processo_cria(int pid, int entrada, int saida) {
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        if (tabela_processos[i].pid == -1) {
            // Encontrou slot vazio
            tabela_processos[i].pid = pid;
            tabela_processos[i].estado = PRONTO;
            tabela_processos[i].entrada = entrada;
            tabela_processos[i].saida = saida;
            tabela_processos[i].pc_salvo = 0;
            tabela_processos[i].a_salvo = 0;
            tabela_processos[i].x_salvo = 0;
            
            printf("PROCESSOS: Criado PID=%d (entrada=%d, saida=%d)\n", 
                   pid, entrada, saida);
            return i;  // Retorna índice na tabela
        }
    }
    return -1;  // Não há slots livres
}

void processo_mata(int pid) {
    for (int i = 0; i < MAX_PROCESSOS; i++) {
        if (tabela_processos[i].pid == pid) {
            tabela_processos[i].estado = MORTO;
            tabela_processos[i].pid = -1;
            printf("PROCESSOS: Morto PID=%d\n", pid);
            
            if (processo_atual == i) {
                processo_atual = -1;  // Nenhum processo executando
            }
            return;
        }
    }
}