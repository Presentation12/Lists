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
typedef struct _listMachine
{
    int time, id_mac;
    struct _listMachine *next, *previous;
} Machine;

/**
 * @brief Estrutura intermedia entre a lista das maquinas e das operações
 * 
 */
typedef struct _listMacOp
{
    int id_op, id_mac;
    struct _listMacOp *next, *previous;
} MacOp;

/**
 * @brief Estrutura que representa a lista das operações
 * 
 */
typedef struct _listOperation
{
    int id_op;
    struct _listOperation *next, *previous;
} Operation;
