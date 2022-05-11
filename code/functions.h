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

Machine *read_machines(Machine *listMachine);
Machine *write_machines(Machine *listMachine);
void free_machines(Machine *list);
Machine *head_insert_machine(Machine *list, Machine *aux);
void show_machines(Machine *list);

MacOp *read_macops(MacOp *listMacOp);
MacOp *write_macops(MacOp *listMacOp);
void free_macops(MacOp *list);
MacOp *head_insert_macop(MacOp *list, MacOp *aux);
void show_macops(MacOp *list);
void remove_macop(MacOp **listMacOp, int id_op);

Operation *read_operations(Operation *listOperation);
Operation *write_operations(Operation *listOperation);
void free_operations(Operation *list);
Operation *head_insert_operation(Operation *list, Operation *aux);
void show_operations(Operation *list);
void insert_operation(Operation **listOperation, MacOp **listMacOp, Machine *listMachine);
void remove_operation(Operation **listOperation, MacOp **listMacOp, int id_op);
void change_operation(MacOp **listMacOp, Machine *listMachine, int id_op);

void interface_job();
void menu_job(Operation **listOperation, MacOp **listMacOp, Machine **listMachine);

int min_time(Operation **listOperation, MacOp **listMacOp, Machine **listMachine);
int max_time(Operation **listOperation, MacOp **listMacOp, Machine **listMachine);
float avg_time(MacOp **listMacOp, Machine **listMachine, int id_op);

int exist_machine(Machine **listMachine, int id);
int exist_operation(Operation **listOperation, int id);
int exist_macop(MacOp **listMacOp, int id_mac, int id_op);
int get_max_time(Machine **listMachine);