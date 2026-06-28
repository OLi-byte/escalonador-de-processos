#include <stdio.h>
#define QUANTUM 2
#include "fila.c"

typedef enum {
    SEM_IO,
    DISCO,
    FITA,
    IMPRESSORA
} IO;

typedef struct {
    int id;
    int tempo_servico;
    int tempo_restante; //tempo total do processo
    int tempo_espera;
    int tempo_retorno;
    int identificador_IO;
    IO tipo_de_IO;
} Processo;

void escalonador(Fila *prontos) {
    int tempo_atual = 0;
    printf("\n--- INICIANDO ESCALONAMENTO ROUND ROBIN (QUANTUM = %d) ---\n", QUANTUM);

    // Executa enquanto houver processos na fila de prontos
    while (estaVazia(prontos) != 1) {
        exibirFila(prontos);
        
        // Pega o próximo processo da fila
        Processo p = desenfileirar(prontos);
        printf("CPU executando P%d (Tempo restante: %d)\n", p.id, p.tempo_restante);

        // Variável que vai armazenar quanto tempo o processo vai rodar nesta rodada
        int tempo_execucao;

        // VERIFICAÇÃO: O processo termina antes do fim do Quantum?
        if (p.tempo_restante < QUANTUM) {
            // CASO VERDADEIRO: O processo precisa de menos tempo do que a fatia inteira.
            tempo_execucao = p.tempo_restante;
        } else {
            // CASO FALSO: O processo é longo e consome a fatia de tempo inteira.
            tempo_execucao = QUANTUM;
        }
                
        // Simula o passar do tempo
        p.tempo_restante = p.tempo_restante - tempo_execucao; // Reduz o tempo que falta para o processo acabar
        tempo_atual = tempo_atual + tempo_execucao;           // Avança o relógio geral do sistema

        
        // Se o processo terminou
        if (p.tempo_restante == 0) {
            p.tempo_retorno = tempo_atual;
            printf(">> P%d TERMINOU no tempo %d. (Tempo de Retorno: %d)\n\n", p.id, tempo_atual, p.tempo_retorno);
        } 
        // Se não terminou, volta para o fim da fila de prontos
        else {
        // Fazer condicional para a preempeção por IO ou preempeção por execeder o QUANTUM
        // Criar as filas de prioridade e fazer a inserção na fila de prontos por essa prioridade
        }
    }
    printf("--- TODOS OS PROCESSOS FORAM CONCLUIDOS no tempo %d ---\n", tempo_atual);
}