/**
 * @file structs.h
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @brief Estruturas do programa
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef STRUCTS
#define STRUCTS

/**
 * @brief Estrutura que representa a lista das máquinas
 *
 */
typedef struct list_machine
{
    int id_mac;
    struct list_machine *next, *previous;
} Machine;

/**
 * @brief Estrutura que representa a lista das operações
 *
 */
typedef struct list_operation
{
    int id_op;
    struct list_operation *next, *previous;
} Operation;

/**
 * @brief Estrutura que representa a lista dos jobs
 *
 */
typedef struct list_job
{
    int id_job;
    struct list_job *next, *previous;
} Job;

/**
 * @brief Estrutura que contem a conexão das listas jobs,operacoes e maquinas
 * 
 */
typedef struct list_conection
{
    int id_job, id_op, id_mac, time;
    struct list_conection *next, *previous;
} Connection;

/**
 * @brief Estrutura que representa uma celula da tabela de planeamento FJSSP
 * 
 */
typedef struct
{
    int id_job, id_op, id_mac, t;
} CelulaPlano;

#endif