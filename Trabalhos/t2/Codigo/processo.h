#ifndef PROCESSO_H
#define PROCESSO_H

#define MAX_PROCESSOS 10

typedef enum {
    PRONTO = 0,      // Quer executar
    EXECUTANDO = 1,  // Está na CPU
    BLOQUEADO = 2,   // Esperando algo
    MORTO = 3        // Terminou
} estado_processo_t;

typedef struct {
    int pid;                    // ID único
    estado_processo_t estado;   // Estado atual
    int pc_salvo;               // Onde parou
    int a_salvo, x_salvo;       // Valores dos registradores
    int entrada, saida;         // Dispositivos E/S
} processo_t;

// Tabela global de processos
extern processo_t tabela_processos[MAX_PROCESSOS];
extern int processo_atual;  // Índice do processo executando

// Funções básicas
void processos_inicia(void);
int processo_cria(int pid, int entrada, int saida);
void processo_mata(int pid);

#endif