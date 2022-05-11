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

/**
 * @brief Estrutura que representa a lista das máquinas
 *
 */
typedef struct list_machine
{
    int time, id_mac;
    struct list_machine *next, *previous;
} Machine;

/**
 * @brief Estrutura intermedia entre a lista das maquinas e das operações
 *
 */
typedef struct list_macop
{
    int id_op, id_mac;
    struct list_macop *next, *previous;
} MacOp;

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
 * @brief Estrutura intermedia entre a lista das operações e dos jobs
 * 
 */
typedef struct list_opjob
{
    int id_op;
    int id_job;
    struct list_opjob *next, *previous;
} OpJob;

/**
 * @brief Estrutura que representa a lista dos jobs
 * 
 */
typedef struct list_job
{
    int id_job;
    struct list_job *next, *previous;
} Job;
