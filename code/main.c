/**
 * @file main.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @brief Solução para problema de escalonamento (Flexifle job shop problem)
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/**
 * @brief Função main
 *
 * @return int
 */
int main()
{
    Machine *list_machines = NULL;
    Job *list_jobs = NULL;
    Connection *list_connections = NULL;

    list_machines = read_machines(list_machines);
    list_jobs = read_jobs(list_jobs);
    list_connections = read_connections(list_connections);

    menu_principal(&list_jobs, &list_machines, &list_connections);

    write_machines(list_machines);
    write_jobs(list_jobs);
    write_connections(list_connections);

    free_machines(list_machines);
    free_jobs(list_jobs);
    free_connections(list_connections);

    return 0;
}
