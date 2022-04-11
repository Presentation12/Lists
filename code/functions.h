/**
 * @file biblioteca.h
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @brief Assinaturas das funções contidas em funcoes.c
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "structs.h"

Machine *readMachines(Machine *listMachine);
Machine *writeMachines(Machine *listMachine);
void freeMachines(Machine *list);
Machine *head_insert_machine(Machine *list, Machine *aux);
void showMachineList(Machine *list);

MacOp *readMacOp(MacOp *listMacOp);
MacOp *writeMacOp(MacOp *listMacOp);
void freeMacOp(MacOp *list);
MacOp *head_insert_macop(MacOp *list, MacOp *aux);
void showMacOpList(MacOp *list);

Operation *readOperations(Operation *listOperation);
Operation *writeOperations(Operation *listOperation);
void freeOperations(Operation *list);
Operation *head_insert_operation(Operation *list, Operation *aux);
void showOperationList(Operation *list);

void interface_job();
void menu_job(Operation **listOperation, MacOp **listMacOp, Machine **listMachine);

void remove_MacOp(MacOp **listMacOp, int id_op);

void insert_operation(Operation **listOperation, MacOp **listMacOp, Machine *listMachine);
void remove_operation(Operation **listOperation, MacOp **listMacOp, int id_op);
void change_operation(MacOp **listMacOp, Machine *listMachine, int id_op);

int min_time(Operation **listOperation, MacOp **listMacOp, Machine **listMachine);
int max_time(Operation **listOperation, MacOp **listMacOp, Machine **listMachine);
float avg_time(MacOp **listMacOp, Machine **listMachine, int id_op);

int exist_mac(Machine **listMachine, int id);
int exist_op(Operation **listOperation, int id);
int exist_MacOp(MacOp **listMacOp, int id_mac, int id_op);
int get_max_time(Machine **listMachine);