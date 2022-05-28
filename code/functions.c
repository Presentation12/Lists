/**
 * @file functions.c
 * @author João Apresentação (a21152@alunos.ipca.pt)
 * @brief Funções do programa
 * @version 0.1
 * @date 2022-03-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#pragma region FILES

/**
 * @brief Leitura do ficheiro machines.txt e armazenamento em memória
 *
 * @param list_machines Lista que contem todas as máquinas
 * @return Machine*
 */
Machine *read_machines(Machine *list_machines)
{
    FILE *file = fopen("machines.txt", "r");
    Machine *aux = (Machine *)malloc(sizeof(Machine));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_machines;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\n", &aux->id_mac);
        list_machines = head_insert_machine(list_machines, aux);
    }

    free(aux);
    fclose(file);
    return list_machines;
}

/**
 * @brief Escrita do ficheiro machines.txt e armazenamento em memória
 *
 * @param list_machines lista das maquinas
 * @return Machine*
 */
Machine *write_machines(Machine *list_machines)
{
    FILE *file = fopen("machines.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_machines;
    }

    while (list_machines)
    {
        fprintf(file, "%d\n", list_machines->id_mac);
        list_machines = list_machines->next;
    }

    fclose(file);
    return list_machines;
}

/**
 * @brief Leitura do ficheiro macop.txt e armazenamento em memória
 *
 * @param list_macops Lista que contem os ids de todas as operações e suas respetivas máquinas
 * @return MacOp*
 */
MacOp *read_macops(MacOp *list_macops)
{
    FILE *file = fopen("macop.txt", "r");
    MacOp *aux = (MacOp *)malloc(sizeof(MacOp));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_macops;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\t%d\t%d\n", &aux->id_op, &aux->id_mac, &aux->time);
        list_macops = head_insert_macop(list_macops, aux);
    }

    free(aux);
    fclose(file);
    return list_macops;
}

/**
 * @brief Escrita do ficheiro macop.txt e armazenamento em memória
 *
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @return MacOp*
 */
MacOp *write_macops(MacOp *list_macops)
{
    FILE *file = fopen("macop.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_macops;
    }

    while (list_macops)
    {
        fprintf(file, "%d\t%d\t%d\n", list_macops->id_op, list_macops->id_mac, list_macops->time);
        list_macops = list_macops->next;
    }

    fclose(file);
    return list_macops;
}

/**
 * @brief Leitura do ficheiro operations.txt e armazenamento em memória
 *
 * @param list_operations Lista que contem todas as operações
 * @return Operation*
 */
Operation *read_operations(Operation *list_operations)
{
    FILE *file = fopen("operations.txt", "r");
    Operation *aux = (Operation *)malloc(sizeof(Operation));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_operations;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\n", &aux->id_op);
        list_operations = head_insert_operation(list_operations, aux);
    }

    free(aux);
    fclose(file);
    return list_operations;
}

/**
 * @brief Escrita do ficheiro operations.txt e armazenamento em memória
 *
 * @param list_operations lista das operações
 * @return Operation*
 */
Operation *write_operations(Operation *list_operations)
{
    FILE *file = fopen("operations.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_operations;
    }

    while (list_operations)
    {
        fprintf(file, "%d\n", list_operations->id_op);
        list_operations = list_operations->next;
    }

    fclose(file);
    return list_operations;
}

/**
 * @brief Leitura do ficheiro opjobs.txt e armazenamento em memória
 * 
 * @param list_opjobs Lista intermedia que contem id das operações com id dos jobs
 * @return OpJob* 
 */
OpJob *read_opjobs(OpJob *list_opjobs)
{
    FILE *file = fopen("opjobs.txt", "r");
    OpJob *aux = (OpJob *)malloc(sizeof(OpJob));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_opjobs;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\t%d\n", &aux->id_job, &aux->id_op);
        list_opjobs = head_insert_opjob(list_opjobs, aux);
    }

    free(aux);
    fclose(file);
    return list_opjobs;
}

/**
 * @brief Escrita do ficheiro opjobs.txt e armazenamento em memória
 * 
 * @param list_opjobs 
 * @return OpJob* 
 */
OpJob *write_opjobs(OpJob *list_opjobs)
{
    FILE *file = fopen("opjobs.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_opjobs;
    }

    while (list_opjobs)
    {
        fprintf(file, "%d\t%d\n", list_opjobs->id_job, list_opjobs->id_op);
        list_opjobs = list_opjobs->next;
    }

    fclose(file);
    return list_opjobs;
}

/**
 * @brief Leitura do ficheiro jobs.txt e armazenamento em memória
 * 
 * @param list_jobs Lista intermedia que contem jobs
 * @return Job* 
 */
Job *read_jobs(Job *list_jobs)
{
    FILE *file = fopen("jobs.txt", "r");
    Job *aux = (Job *)malloc(sizeof(Job));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_jobs;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\n", &aux->id_job);
        list_jobs = head_insert_job(list_jobs, aux);
    }

    free(aux);
    fclose(file);
    return list_jobs;
}

/**
 * @brief Escrita do ficheiro opjobs.txt e armazenamento em memória
 * 
 * @param list_opjobs 
 * @return OpJob* 
 */
Job *write_jobs(Job *list_jobs)
{
    FILE *file = fopen("jobs.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_jobs;
    }

    while (list_jobs)
    {
        fprintf(file, "%d\n", list_jobs->id_job);
        list_jobs = list_jobs->next;
    }

    fclose(file);
    return list_jobs;
}

#pragma endregion

#pragma region FREE

/**
 * @brief Desalocar memória ocupada pela lista das máquinas
 *
 * @param list_machines lista das máquinas
 */
void free_machines(Machine *list_machines)
{
    Machine *aux = malloc(sizeof(Machine));

    while (list_machines)
    {
        aux = list_machines;
        list_machines = list_machines->next;
        free(aux);
    }
}

/**
 * @brief Desalocar memória ocupada pela lista MacOp
 *
 * @param list_macops lista MacOp
 */
void free_macops(MacOp *list_macops)
{
    MacOp *aux = malloc(sizeof(MacOp));

    while (list_macops)
    {
        aux = list_macops;
        list_macops = list_macops->next;
        free(aux);
    }
}

/**
 * @brief Desalocar memória ocupada pela lista das operações
 *
 * @param list_operations lista das operações
 */
void free_operations(Operation *list_operations)
{
    Operation *aux = malloc(sizeof(Operation));

    while (list_operations)
    {
        aux = list_operations;
        list_operations = list_operations->next;
        free(aux);
    }
}

/**
 * @brief Desalocar memória ocupada pela lista intermedia opjobs
 *
 * @param list_opjobs lista intermedia de operações e jobs
 */
void free_opjobs(OpJob *list_opjobs)
{
    OpJob *aux = malloc(sizeof(OpJob));

    while (list_opjobs)
    {
        aux = list_opjobs;
        list_opjobs = list_opjobs->next;
        free(aux);
    }
}

/**
 * @brief Desalocar memória ocupada pela lista de jobs
 *
 * @param list_job lista de jobs
 */
void free_jobs(Job *list_job)
{
    Job *aux = malloc(sizeof(Job));

    while (list_job)
    {
        aux = list_job;
        list_job = list_job->next;
        free(aux);
    }
}

#pragma endregion

#pragma region HEAD_INSERTS

/**
 * @brief Inserção á cabeça na lista das máquinas
 *
 * @param list_machines Lista das máquinas
 * @param aux Lista auxiliar
 * @return Machine*
 */
Machine *head_insert_machine(Machine *list_machines, Machine *aux)
{
    // Alocagem de memoria para nodo
    Machine *tmp = (Machine *)malloc(sizeof(Machine));

    // Inserição dos valores a armazenar
    tmp->id_mac = aux->id_mac;

    // Novo nodo aponta para início da lista
    tmp->next = list_machines;
    if (tmp->next)
        tmp->next->previous = tmp;
    tmp->previous = NULL;

    // Retorno do tmp, pois este agora é o início da lista
    return tmp;
}

/**
 * @brief Inserção á cabeça na lista MacOp
 *
 * @param list_macops Lista MacOp
 * @param aux Lista auxiliar
 * @return MacOp*
 */
MacOp *head_insert_macop(MacOp *list_macops, MacOp *aux)
{
    // Alocagem de memoria para nodo
    MacOp *tmp = (MacOp *)malloc(sizeof(MacOp));

    // Inserção dos valores a armazenar
    tmp->id_mac = aux->id_mac;
    tmp->id_op = aux->id_op;
    tmp->time = aux->time;

    // Novo nodo aponta para início da lista
    tmp->next = list_macops;
    if (tmp->next)
        tmp->next->previous = tmp;
    tmp->previous = NULL;

    // Retorno do tmp, pois este agora é o início da lista
    return tmp;
}

/**
 * @brief Inserção á cabeça na lista das operações
 *
 * @param list_operations Lista de operações
 * @param aux Lista auxiliar
 * @return Operation*
 */
Operation *head_insert_operation(Operation *list_operations, Operation *aux)
{
    // Alocar memoria para nodo
    Operation *tmp = (Operation *)malloc(sizeof(Operation));

    // Inserir valores a guardar
    tmp->id_op = aux->id_op;

    // Novo nodo aponta para início da lista
    tmp->next = list_operations;
    if (tmp->next)
        tmp->next->previous = tmp;
    tmp->previous = NULL;

    // Retornar o tmp, pois este agora é o início da lista
    return tmp;
}

/**
 * @brief Inserção á cabeça na lista intermedia opjobs
 * 
 * @param list_opjobs lista intermedia opjobs
 * @param aux Lista auxiliar
 * @return OpJob* 
 */
OpJob *head_insert_opjob(OpJob *list_opjobs, OpJob *aux)
{
    // Alocar memoria para nodo
    OpJob *tmp = (OpJob *)malloc(sizeof(OpJob));

    // Inserir valores a guardar
    tmp->id_job = aux->id_job;
    tmp->id_op = aux->id_op;

    // Novo nodo aponta para início da lista
    tmp->next = list_opjobs;
    if (tmp->next)
        tmp->next->previous = tmp;
    tmp->previous = NULL;

    // Retornar o tmp, pois este agora é o início da lista
    return tmp;
}

/**
 * @brief Inserção á cabeça na lista dos jobs
 * 
 * @param list_jobs Lista dos jobs
 * @param aux Lista auxiliar
 * @return Job* 
 */
Job *head_insert_job(Job *list_jobs, Job *aux)
{
    // Alocar memoria para nodo
    Job *tmp = (Job *)malloc(sizeof(Job));

    // Inserir valores a guardar
    tmp->id_job = aux->id_job;

    // Novo nodo aponta para início da lista
    tmp->next = list_jobs;
    if (tmp->next)
        tmp->next->previous = tmp;
    tmp->previous = NULL;

    // Retornar o tmp, pois este agora é o início da lista
    return tmp;
}

#pragma endregion

#pragma region EXIST

/**
 * @brief Verifica se um id de uma maquina inserido existe na lista das maquinas
 *
 * @param list_machines lista das máquinas
 * @param id_machine id de uma máquina inserido
 * @return int
 */
int exist_machine(Machine **list_machines, int id_machine)
{
    Machine *head_mac = malloc(sizeof(Machine));
    head_mac = *list_machines;

    while (head_mac)
    {
        if (head_mac->id_mac == id_machine)
        {
            // true
            return 1;
        }

        head_mac = head_mac->next;
    }
    // false
    return 0;
}

/**
 * @brief Verifica se um id de uma operação inserido existe na lista das operações
 *
 * @param list_operations lista das operações
 * @param id_operation id de uma operação inserido
 * @return int
 */
int exist_operation(Operation **list_operations, int id_operation)
{
    Operation *head_op = malloc(sizeof(Operation));
    head_op = *list_operations;

    while (head_op)
    {
        if (head_op->id_op == id_operation)
        {
            // true
            return 1;
        }

        head_op = head_op->next;
    }
    // false
    return 0;
}

/**
 * @brief Verifica se uma combinação de id_mac e id_op existe na lista MacOp
 *
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_machine id da maquina
 * @param id_operation id da operação
 * @return int
 */
int exist_macop(MacOp **list_macops, int id_machine, int id_operation)
{
    MacOp *head_mac_op = malloc(sizeof(MacOp));
    head_mac_op = *list_macops;

    while (head_mac_op)
    {
        if (head_mac_op->id_op == id_operation && head_mac_op->id_mac == id_machine)
        {
            // true
            return 1;
        }

        head_mac_op = head_mac_op->next;
    }
    // false
    return 0;
}

#pragma endregion

#pragma region GETS

/**
 * @brief Busca o valor maximo para a variavel tempo na lista das máquinas
 *
 * @param list_machines lista das máquinas
 * @return int
 */
int get_max_time(MacOp **list_macops)
{
    int max = 0;
    MacOp *head_macop = malloc(sizeof(MacOp));
    head_macop = *list_macops;

    while (head_macop)
    {
        if (head_macop->time > max)
        {
            max = head_macop->time;
        }
        head_macop = head_macop->next;
    }

    return max;
}

#pragma endregion

#pragma region SHOW FUNCTIONS

/**
 * @brief Listagem das máquinas na lista
 *
 * @param list_machines Lista das máquinas
 */
void show_machines(Machine *list_machines)
{
    printf("-------------------------\n");
    printf("    Lista das Maquinas   \n");
    printf("-------------------------\n");
    while (list_machines)
    {
        printf("ID: %d\n", list_machines->id_mac);
        list_machines = list_machines->next;
    }
    printf("-------------------------\n");
}

/**
 * @brief listagem da lista intermedia entre as operações e as máquinas
 *
 * @param list_macops Lista MacOp
 */
void show_macops(MacOp *list_macops)
{
    printf("----------------------------------\n");
    printf("          Lista Intermedia        \n");
    printf("       (Maquinas e Operacoes) \n");
    printf("----------------------------------\n");
    while (list_macops)
    {
        printf("ID Operacao: %d / ID Maquina: %d / Time: %d\n", list_macops->id_op, list_macops->id_mac, list_macops->time);
        list_macops = list_macops->next;
    }
    printf("----------------------------------\n");
}

/**
 * @brief Listagem das operações na lista
 *
 * @param list_operations Lista das operações
 */
void show_operations(Operation *list_operations)
{
    printf("-------------------------\n");
    printf("   Lista das Operacoes   \n");
    printf("-------------------------\n");
    while (list_operations)
    {
        printf("ID: %d\n", list_operations->id_op);
        list_operations = list_operations->next;
    }
    printf("-------------------------\n");
}

#pragma endregion

#pragma region MAC OP

/**
 * @brief Remoção de uma operação da lista intermedia MacOp
 *
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação a ser removida
 */
void remove_macop(MacOp **list_macops, int id_operation)
{
    MacOp *head_macop = malloc(sizeof(MacOp));
    head_macop = *list_macops;

    while (head_macop)
    {
        if (head_macop->id_op == id_operation)
        {
            if (head_macop->next)
                head_macop->next->previous = head_macop->previous;
            if (head_macop->previous)
                head_macop->previous->next = head_macop->next;
            else
                *list_macops = head_macop->next;

            free(head_macop);
        }

        head_macop = head_macop->next;
    }
}

#pragma endregion

#pragma region OPERATIONS

/**
 * @brief Inserção de uma operação na lista das operações e lista MacOp
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param list_machines lista das máquinas
 */
void insert_operation(Operation **list_operations, MacOp **list_macops, Machine *list_machines)
{
    Operation *head_op = malloc(sizeof(Operation));
    MacOp *head_macop = malloc(sizeof(MacOp));

    Operation *aux_op = (Operation *)malloc(sizeof(Operation));
    MacOp *aux_macOp = (MacOp *)malloc(sizeof(MacOp));

    head_op = *list_operations;
    head_macop = *list_macops;

    aux_macOp->id_op = head_op->id_op + 1;
    aux_op->id_op = head_op->id_op + 1;

    show_machines(list_machines);
    printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
    scanf("%d", &aux_macOp->id_mac);

    if (aux_macOp->id_mac >= 0)
    {
        printf("\nInsira o tempo:");
        scanf("%d", &aux_macOp->time);

        if (exist_machine(&list_machines, aux_macOp->id_mac))
        {
            if (exist_macop(list_macops, aux_macOp->id_mac, aux_macOp->id_op))
                printf("\nEsta combinacaoo ja existe\nNao inserido\n");
            else
            {
                *list_macops = head_insert_macop(head_macop, aux_macOp);
                head_macop = *list_macops;
            }
        }
        else if (aux_macOp->id_mac >= 0)
            printf("Essa maquina nao existe");
    }

    while (aux_macOp->id_mac >= 0)
    {
        show_machines(list_machines);
        printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
        scanf("%d", &aux_macOp->id_mac);

        if (aux_macOp->id_mac >= 0)
        {
            printf("\nInsira o tempo:");
            scanf("%d", &aux_macOp->time);

            if (exist_machine(&list_machines, aux_macOp->id_mac))
            {
                if (exist_macop(list_macops, aux_macOp->id_mac, aux_macOp->id_op))
                    printf("\nEsta combinação ja existe\nNao inserido\n");
                else
                {
                    *list_macops = head_insert_macop(head_macop, aux_macOp);
                    head_macop = *list_macops;
                }
            }
            else if (aux_macOp->id_mac >= 0)
                printf("Essa maquina nao existe");
        }
    }

    *list_operations = head_insert_operation(head_op, aux_op);

    free(aux_op);
    free(aux_macOp);
}

/**
 * @brief Remoção de uma operação da lista operações e respetivamente da lista intermedia MacOp
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação a ser removida
 */
void remove_operation(Operation **list_operations, MacOp **list_macops, int id_operation)
{
    Operation *head_op = malloc(sizeof(Operation));
    MacOp *head_macop = malloc(sizeof(MacOp));

    head_op = *list_operations;
    while (head_op)
    {
        if (head_op->id_op == id_operation)
        {
            head_macop = *list_macops;
            while (head_macop)
            {
                if (head_macop->id_op == id_operation)
                {
                    if (head_macop->next)
                        head_macop->next->previous = head_macop->previous;
                    if (head_macop->previous)
                        head_macop->previous->next = head_macop->next;
                    else
                        *list_macops = head_macop->next;

                    free(head_macop);
                }

                head_macop = head_macop->next;
            }

            if (head_op->next)
                head_op->next->previous = head_op->previous;
            if (head_op->previous)
                head_op->previous->next = head_op->next;
            else
                *list_operations = head_op->next;
        }

        head_op = head_op->next;
    }
    free(head_op);
}

/**
 * @brief Alteração de uma operação da lista operações
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação a ser alterada
 */
void change_operation(MacOp **list_macops, Machine *list_machines, int id_operation)
{
    remove_macop(list_macops, id_operation);

    MacOp *head_macop = malloc(sizeof(MacOp));
    head_macop = *list_macops;

    MacOp *aux_macop = (MacOp *)malloc(sizeof(MacOp));
    aux_macop->id_op = id_operation;

    show_machines(list_machines);
    printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
    scanf("%d", &aux_macop->id_mac);

    if (exist_machine(&list_machines, aux_macop->id_mac))
    {
        if (exist_macop(list_macops, aux_macop->id_mac, id_operation))
            printf("\nEsta combinação ja existe\nNao inserido\n");
        else
            *list_macops = head_insert_macop(head_macop, aux_macop);
    }
    else if (aux_macop->id_mac >= 0)
        printf("Essa maquina nao existe");

    while (aux_macop->id_mac >= 0)
    {
        show_machines(list_machines);
        printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
        scanf("%d", &aux_macop->id_mac);

        if (exist_machine(&list_machines, aux_macop->id_mac))
        {
            if (exist_macop(list_macops, aux_macop->id_mac, id_operation))
                printf("\nEsta combinação ja existe\nNao inserido\n");
            else
                *list_macops = head_insert_macop(head_macop, aux_macop);
        }
        else if (aux_macop->id_mac >= 0)
            printf("Essa maquina nao existe");
    }
}

/**
 * @brief Determinação da quantidade média de unidades de tempo necessárias para completar uma operação,
 *        considerando todas as alternativas possíveis
 *
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param list_machines lista das máquinas
 * @param id_operation id da operação
 */
float avg_time(MacOp **list_macops, int id_operation)
{
    int sum = 0, count = 0;
    MacOp *head_macop = malloc(sizeof(MacOp));

    head_macop = *list_macops;
    while (head_macop)
    {
        if (head_macop->id_op == id_operation)
        {
            sum += head_macop->time;
            count++;
        }
        head_macop = head_macop->next;
    }

    return (float)sum / count;
}

#pragma endregion

#pragma region JOB

/**
 * @brief Determinação da quantidade mínima de unidades de tempo necessárias para completar o job e listagem das
 *        respetivas operações
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 */
int min_time(Operation **list_operations, MacOp **list_macops)
{
    int sum = 0, min;
    Operation *head_op;
    MacOp *head_macop;

    head_op = *list_operations;
    while (head_op)
    {
        min = get_max_time(list_macops);
        head_macop = *list_macops;
        while (head_macop)
        {
            if (head_op->id_op == head_macop->id_op && head_macop->time < min)
            {
                min = head_macop->time;
            }
            head_macop = head_macop->next;
        }
        sum += min;
        head_op = head_op->next;
    }

    return sum;
}

/**
 * @brief Determinação da quantidade máxima de unidades de tempo necessárias para completar o job e listagem das
 *        respetivas operações
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 */
int max_time(Operation **list_operations, MacOp **list_macops)
{
    int sum = 0, max;
    Operation *head_op;
    MacOp *head_macop;

    head_op = *list_operations;
    while (head_op)
    {
        max = 0;
        head_macop = *list_macops;
        while (head_macop)
        {
            if (head_op->id_op == head_macop->id_op && head_macop->time > max)
            {
                max = head_macop->time;
            }
            head_macop = head_macop->next;
        }
        sum += max;
        head_op = head_op->next;
    }
    return sum;
}

#pragma endregion

#pragma region MENUS

/**
 * @brief Texto apresentado ao utilizador do menu job
 *
 */
void interface_job()
{
    printf("----------------------\n");
    printf("        Menu Job      \n");
    printf(" [1]-Visualizar listas\n [2]-Inserir Operacao\n [3]-Remover Operacao\n [4]-Alterar Operacao\n [5]-Tempo Minimo\n [6]-Tempo Maximo\n [7]-Media de Tempo (operacao)\n [0]- Sair\n");
    printf("----------------------\n");
    printf("\n-->");
}

/**
 * @brief Menu de um determinado job selecionado
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param list_machines lista das máquinas
 *
 */
void menu_job(Operation **list_operations, MacOp **list_macops, Machine **list_machines)
{
    int op;
    interface_job();
    scanf("%d", &op);

    while (op != 0)
    {
        switch (op)
        {

        case 1:
            system("cls");
            {
                show_operations(*list_operations);
                show_macops(*list_macops);
                show_machines(*list_machines);
                system("pause");
            }
            system("cls");
            break;

        case 2:
            system("cls");
            {
                insert_operation(list_operations, list_macops, *list_machines);
                system("pause");
            }
            system("cls");
            break;

        case 3:
            system("cls");
            {
                int id_op;
                show_operations(*list_operations);
                printf("\n\nSelecione o id da operacao a remover: ");
                scanf("%d", &id_op);
                if (exist_operation(list_operations, id_op))
                {
                    remove_operation(list_operations, list_macops, id_op);
                }
                else
                    printf("\nID inserido inexistente\n");
                system("pause");
            }
            system("cls");
            break;

        case 4:
            system("cls");
            {
                int id_op;
                show_operations(*list_operations);
                printf("\n\nSelecione o id da operacao a alterar: ");
                scanf("%d", &id_op);
                if (exist_operation(list_operations, id_op))
                {
                    change_operation(list_macops, *list_machines, id_op);
                }
                else
                    printf("\nID inserido inexistente\n");
                system("pause");
            }
            system("cls");
            break;

        case 5:
            system("cls");
            {
                show_operations(*list_operations);
                printf("\n\nTempo minimo executado pelo job: %d\n", min_time(list_operations, list_macops));
                system("pause");
            }
            system("cls");
            break;

        case 6:
            system("cls");
            {
                show_operations(*list_operations);
                printf("\n\nTempo maximo executado pelo job: %d\n", max_time(list_operations, list_macops));
                system("pause");
            }
            system("cls");
            break;

        case 7:
            system("cls");
            {
                int id_op;
                show_operations(*list_operations);
                printf("\n\nSelecione o id da operacao: ");
                scanf("%d", &id_op);
                if (exist_operation(list_operations, id_op))
                {
                    printf("\n\nTempo medio executado pela operacao %d: %.2f\n", id_op, avg_time(list_macops, id_op));
                }
                else
                    printf("\nID inserido inexistente\n");
                system("pause");
            }
            system("cls");
            break;

        default:
            system("cls");
            printf("Opcao invalida\nIntroduza novamente\n");
            break;
        }

        interface_job();
        scanf("%d", &op);
    }
}

#pragma endregion