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
    MacOp *list_macops = NULL;
    Operation *list_operations = NULL;

    list_machines = read_machines(list_machines);
    list_macops = read_macops(list_macops);
    list_operations = read_operations(list_operations);

    menu_job(&list_operations, &list_macops, &list_machines);

    write_machines(list_machines);
    write_macops(list_macops);
    write_operations(list_operations);


    free_machines(list_machines);
    free_macops(list_macops);
    free_operations(list_operations); 

    return 0;
}
