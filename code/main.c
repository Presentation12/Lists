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
    Machine *listMachines = NULL;
    MacOp *listMacOp = NULL;
    Operation *listOperations = NULL;

    listMachines = readMachines(listMachines);
    listMacOp = readMacOp(listMacOp);
    listOperations = readOperations(listOperations);

    menu_job(&listOperations, &listMacOp, &listMachines);

    writeMachines(listMachines);
    writeMacOp(listMacOp);
    writeOperations(listOperations);


    freeMachines(listMachines);
    freeMacOp(listMacOp);
    freeOperations(listOperations); 

    return 0;
}
