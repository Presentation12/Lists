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

#pragma region MACHINES

Machine *read_machines(Machine *listMachine);
Machine *write_machines(Machine *listMachine);
int free_machines(Machine *list);
Machine *head_insert_machine(Machine *list, Machine *aux);
void show_machines(Machine *list);
int exist_machine(Machine *list_machines, int id_machine);

#pragma endregion

#pragma region OPERATIONS

Connection *remove_operation(Connection *list_connections, int id_operation, int id_job);
Connection *change_operation(Connection *list_connections, int id_operation, int id_job, int id_machine, int new_time);
Connection *insert_operation(Connection *list_connections, Machine *list_machines, int id_job);

#pragma endregion

#pragma region JOBS

int free_jobs(Job *list_job);
Job *read_jobs(Job *list_jobs);
Job *write_jobs(Job *list_jobs);
Job *head_insert_job(Job *list_jobs, Job *aux);
void show_jobs(Job *list_jobs);
Job *remove_job(Job *list_jobs, Connection **list_connections, int id_job);

#pragma endregion

#pragma region CONNECTIONS

Connection *read_connections(Connection *list_connections);
Connection *write_connections(Connection *list_connections);
int free_connections(Connection *list_connections);
Connection *head_insert_connection(Connection *list_connections, Connection *aux);
void show_connections(Connection *list_connections);
void show_operations_by_job(Connection *list_connections, int id_job);
void show_machines_by_opjob_id(Connection *list_connections, int id_operation, int id_job);
int exist_connection(Connection *list_connections, int id_machine, int id_operation, int id_job);
int exist_operation(Connection *list_connections, int id_operation, int id_job);

#pragma endregion

#pragma region INTERFACE

void interface_principal();
void menu_principal(Job **list_jobs, Machine **list_machines, Connection **list_connections);

#pragma endregion

#pragma region CALCULATIONS

int min_time(Connection *list_connections, int id_job);
int max_time(Connection *list_connections, int id_job);
float avg_time(Connection *list_connections, int id_operation, int id_job);
int count_op_ids(Connection *list_connections, int id_operation, int id_job);

#pragma endregion

#pragma region GET

int get_new_operation_id(Connection *list_connections, int id_job);
int get_new_job_id(Job *list_jobs);

#pragma endregion

#pragma region SIMULATION

int simulation(Connection *list_connections);
int Ocupa(int job, int oper, int maq, int t);

#pragma endregion

#endif