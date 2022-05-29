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
#ifndef FUNCTIONS
#define FUNCTIONS
#include "structs.h"

// Funções machines
Machine *read_machines(Machine *listMachine);
Machine *write_machines(Machine *listMachine);
int free_machines(Machine *list);
Machine *head_insert_machine(Machine *list, Machine *aux);
void show_machines(Machine *list);
int exist_machine(Machine *list_machines, int id_machine);
void show_machines_by_op_id(MacOp *list_macops, int id_operation);

// Funções macops
MacOp *read_macops(MacOp *listMacOp);
MacOp *write_macops(MacOp *listMacOp);
int free_macops(MacOp *list);
MacOp *head_insert_macop(MacOp *list, MacOp *aux);
void show_macops(MacOp *list);
MacOp *remove_macop(MacOp *list_macops, int id_operation);
int exist_macop(MacOp *list_macops, int id_machine, int id_operation);

// Funções operations
Operation *read_operations(Operation *listOperation);
Operation *write_operations(Operation *listOperation);
int free_operations(Operation *list);
Operation *head_insert_operation(Operation *list, Operation *aux);
void show_operations(Operation *list);
Operation *insert_operation(Operation *listOperation, MacOp **listMacOp, Machine *listMachine);
Operation *remove_operation(Operation *list_operations, MacOp **list_macops, int id_operation);
MacOp *change_operation(MacOp *list_macops, int id_operation);
int exist_operation(Operation *list_operations, int id_operation);

// Funções opjobs
int free_opjobs(OpJob *list_opjobs);
OpJob *read_opjobs(OpJob *list_opjobs);
OpJob *write_opjobs(OpJob *list_opjobs);
OpJob *head_insert_opjob(OpJob *list_opjobs, OpJob *aux);

// Funções jobs
int free_jobs(Job *list_job);
Job *read_jobs(Job *list_jobs);
Job *write_jobs(Job *list_jobs);
Job *head_insert_job(Job *list_jobs, Job *aux);

// Funções de interface usuário
void interface_job();
void menu_job(Operation **listOperation, MacOp **listMacOp, Machine **listMachine);

// Funções de cálculo
int min_time(Operation **list_operations, MacOp **list_macops);
int max_time(Operation **list_operations, MacOp **list_macops);
float avg_time(MacOp **list_macops, int id_operation);

// Gets
int get_max_time(MacOp *list_macops);
int get_new_operation_id(Operation *list_operation);

#endif