#include <stdio.h>
#define QUANTUM = 2

struct Processo
{
    int id;
    int tempo_servico;
    int tempo_restante;
    int tempo_espera;
    int tempo_retorno;
    int identificador_IO;
};

void calcular_tempo(struct Processo proc[], int n)
{
}