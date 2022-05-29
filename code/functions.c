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
        return NULL;
    }

    if (aux == NULL)
    {
        return list_machines;
    }

    ///////////////////////////////////////
    int c = fgetc(file);
    if (c == EOF)
    {
        return list_machines;
    }
    else
    {
        ungetc(c, file);
    }
    ///////////////////////////////////////

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
        return NULL;
    }

    if (aux == NULL)
    {
        return list_macops;
    }

    ///////////////////////////////////////
    int c = fgetc(file);
    if (c == EOF)
    {
        return list_macops;
    }
    else
    {
        ungetc(c, file);
    }
    ///////////////////////////////////////

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
        return NULL;
    }

    if (aux == NULL)
    {
        return list_operations;
    }

    ///////////////////////////////////////
    int c = fgetc(file);
    if (c == EOF)
    {
        return list_operations;
    }
    else
    {
        ungetc(c, file);
    }
    ///////////////////////////////////////

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
        return NULL;
    }

    if (aux == NULL)
    {
        return list_opjobs;
    }

    ///////////////////////////////////////
    int c = fgetc(file);
    if (c == EOF)
    {
        return list_opjobs;
    }
    else
    {
        ungetc(c, file);
    }
    ///////////////////////////////////////

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
        return NULL;
    }

    if (aux == NULL)
    {
        return list_jobs;
    }

    ///////////////////////////////////////
    int c = fgetc(file);
    if (c == EOF)
    {
        return list_jobs;
    }
    else
    {
        ungetc(c, file);
    }
    ///////////////////////////////////////

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
 * @return int
 */
int free_machines(Machine *list_machines)
{
    Machine *aux = (Machine *)malloc(sizeof(Machine));

    while (list_machines)
    {
        aux = list_machines;
        list_machines = list_machines->next;
        free(aux);
    }

    return 1;
}

/**
 * @brief Desalocar memória ocupada pela lista MacOp
 *
 * @param list_macops lista MacOp
 * @return int
 */
int free_macops(MacOp *list_macops)
{
    MacOp *aux = (MacOp *)malloc(sizeof(MacOp));

    while (list_macops)
    {
        aux = list_macops;
        list_macops = list_macops->next;
        free(aux);
    }

    return 1;
}

/**
 * @brief Desalocar memória ocupada pela lista das operações
 *
 * @param list_operations lista das operações
 * @return int
 */
int free_operations(Operation *list_operations)
{
    Operation *aux = (Operation *)malloc(sizeof(Operation));

    while (list_operations)
    {
        aux = list_operations;
        list_operations = list_operations->next;
        free(aux);
    }

    return 1;
}

/**
 * @brief Desalocar memória ocupada pela lista intermedia opjobs
 *
 * @param list_opjobs lista intermedia de operações e jobs
 * @return int
 */
int free_opjobs(OpJob *list_opjobs)
{
    OpJob *aux = (OpJob *)malloc(sizeof(OpJob));

    while (list_opjobs)
    {
        aux = list_opjobs;
        list_opjobs = list_opjobs->next;
        free(aux);
    }

    return 1;
}

/**
 * @brief Desalocar memória ocupada pela lista de jobs
 *
 * @param list_job lista de jobs
 * @return int
 */
int free_jobs(Job *list_job)
{
    Job *aux = (Job *)malloc(sizeof(Job));

    while (list_job)
    {
        aux = list_job;
        list_job = list_job->next;
        free(aux);
    }

    return 1;
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
int exist_machine(Machine *list_machines, int id_machine)
{
    while (list_machines)
    {
        if (list_machines->id_mac == id_machine)
        {
            // true
            return 1;
        }

        list_machines = list_machines->next;
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
int exist_operation(Operation *list_operations, int id_operation)
{
    while (list_operations)
    {
        if (list_operations->id_op == id_operation)
        {
            // true
            return 1;
        }

        list_operations = list_operations->next;
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
int exist_macop(MacOp *list_macops, int id_machine, int id_operation)
{
    while (list_macops)
    {
        if (list_macops->id_op == id_operation && list_macops->id_mac == id_machine)
        {
            // true
            return 1;
        }

        list_macops = list_macops->next;
    }
    // false
    return 0;
}

#pragma endregion

#pragma region GETS

/**
 * @brief Busca o valor maximo para a variavel tempo na lista intermedia macops
 *
 * @param list_macops lista intermedia de maquinas e operações
 * @return int
 */
int get_max_time(MacOp *list_macops)
{
    int max = 0;

    while (list_macops)
    {
        if (list_macops->time > max)
        {
            max = list_macops->time;
        }
        list_macops = list_macops->next;
    }

    return max;
}

/**
 * @brief Função para encontrar o próximo id da lista das operações a ser usado por uma nova
 * operação a ser inserida na respetiva função
 *
 * @param list_operation lista de operações
 * @return int
 */
int get_new_operation_id(Operation *list_operations)
{
    int new_id = -1;
    while (list_operations)
    {
        if (list_operations->id_op > new_id)
        {
            new_id = list_operations->id_op;
        }

        list_operations = list_operations->next;
    }
    return new_id + 1;
}

/**
 * @brief Função para encontrar o próximo id da lista jobs a ser usado por um novo
 * job a ser inserida na respetiva função
 *
 * @param list_jobs lista dos jobs
 * @return int
 */
int get_new_job_id(Job *list_jobs)
{
    int new_id = -1;
    while (list_jobs)
    {
        if (list_jobs->id_job > new_id)
        {
            new_id = list_jobs->id_job;
        }

        list_jobs = list_jobs->next;
    }
    return new_id + 1;
}

#pragma endregion

#pragma region SHOW

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
        printf("ID Maquina: %d\n", list_machines->id_mac);
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
 * @brief Mostra maquinas de uma operação pelo seu id de operação
 *
 * @param list_macops lista intermedia de operações e maquinas
 * @param id_operation id da operação
 */
void show_machines_by_op_id(MacOp *list_macops, int id_operation)
{
    printf("----------------------------------\n");
    printf("          Lista Intermedia        \n");
    printf("           (Operacao %d) \n", id_operation);
    printf("----------------------------------\n");
    while (list_macops)
    {
        if (list_macops->id_op == id_operation)
        {
            printf("ID Operacao: %d / ID Maquina: %d / Time: %d\n", list_macops->id_op, list_macops->id_mac, list_macops->time);
        }
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
        printf("ID Operacao: %d\n", list_operations->id_op);
        list_operations = list_operations->next;
    }
    printf("-------------------------\n");
}

/**
 * @brief Listagem da lista intermedia entre operações e jobs
 *
 * @param list_opjobs Lista das op jobs
 */
void show_opjobs(OpJob *list_opjobs)
{
    printf("----------------------------------\n");
    printf("          Lista Intermedia        \n");
    printf("         (Operacoes e Jobs) \n");
    printf("----------------------------------\n");
    while (list_opjobs)
    {
        printf("ID Job: %d / ID Operacao: %d\n", list_opjobs->id_job, list_opjobs->id_op);
        list_opjobs = list_opjobs->next;
    }
    printf("-------------------------\n");
}

/**
 * @brief Listagem dos jobs
 *
 * @param list_jobs Lista dos jobs
 */
void show_jobs(Job *list_jobs)
{
    printf("-------------------------\n");
    printf("      Lista das Jobs     \n");
    printf("-------------------------\n");
    while (list_jobs)
    {
        printf("ID Job: %d\n", list_jobs->id_job);
        list_jobs = list_jobs->next;
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
MacOp *remove_macop(MacOp *list_macops, int id_operation)
{
    MacOp *head_macop = malloc(sizeof(MacOp));
    head_macop = list_macops;

    while (head_macop)
    {
        if (head_macop->id_op == id_operation)
        {
            if (head_macop->next)
                head_macop->next->previous = head_macop->previous;
            if (head_macop->previous)
                head_macop->previous->next = head_macop->next;
            else
                list_macops = head_macop->next;

            free(head_macop);
        }

        head_macop = head_macop->next;
    }

    return list_macops;
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
Operation *insert_operation(OpJob **list_opjobs, Operation *list_operations, MacOp **list_macops, Machine *list_machines, int id_job)
{
    OpJob *head_opjob = malloc(sizeof(OpJob));
    Operation *head_op = malloc(sizeof(Operation));
    MacOp *head_macop = malloc(sizeof(MacOp));

    OpJob *aux_opjob = malloc(sizeof(OpJob));
    Operation *aux_op = (Operation *)malloc(sizeof(Operation));
    MacOp *aux_macop = (MacOp *)malloc(sizeof(MacOp));

    head_opjob = *list_opjobs;
    head_op = list_operations;
    head_macop = *list_macops;

    aux_macop->id_op = get_new_operation_id(head_op);
    aux_op->id_op = aux_macop->id_op;
    aux_opjob->id_op = aux_macop->id_op;
    aux_opjob->id_job = id_job;

    show_machines(list_machines);
    printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
    scanf("%d", &aux_macop->id_mac);

    if (aux_macop->id_mac >= 0)
    {
        printf("\nInsira o tempo:");
        scanf("%d", &aux_macop->time);

        if (exist_machine(list_machines, aux_macop->id_mac))
        {
            if (exist_macop(*list_macops, aux_macop->id_mac, aux_macop->id_op))
                printf("\nEsta combinacaoo ja existe\nNao inserido\n");
            else
            {
                *list_macops = head_insert_macop(head_macop, aux_macop);
                head_macop = *list_macops;
            }
        }
        else if (aux_macop->id_mac >= 0)
            printf("\nEssa maquina nao existe\n");
    }

    while (aux_macop->id_mac >= 0)
    {
        show_machines(list_machines);
        printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
        scanf("%d", &aux_macop->id_mac);

        if (aux_macop->id_mac >= 0)
        {
            printf("\nInsira o tempo:");
            scanf("%d", &aux_macop->time);

            if (exist_machine(list_machines, aux_macop->id_mac))
            {
                if (exist_macop(*list_macops, aux_macop->id_mac, aux_macop->id_op))
                    printf("\nEsta combinação ja existe\nNao inserido\n");
                else
                {
                    *list_macops = head_insert_macop(head_macop, aux_macop);
                    head_macop = *list_macops;
                }
            }
            else if (aux_macop->id_mac >= 0)
                printf("\nEssa maquina nao existe\n");
        }
    }

    list_operations = head_insert_operation(head_op, aux_op);
    *list_opjobs = head_insert_opjob(head_opjob, aux_opjob);

    free(aux_op);
    free(aux_macop);

    return list_operations;
}

/**
 * @brief Remoção de uma operação da lista operações e respetivamente da lista intermedia MacOp
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação a ser removida
 */
Operation *remove_operation(Operation *list_operations, MacOp **list_macops, int id_operation)
{
    Operation *head_op = malloc(sizeof(Operation));
    MacOp *head_macop = malloc(sizeof(MacOp));

    head_op = list_operations;
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
                list_operations = head_op->next;
        }

        head_op = head_op->next;
    }
    free(head_op);

    return list_operations;
}

/**
 * @brief Alteração de uma operação da lista operações
 * Altera os tempos de máquinas que selecione
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação a ser alterada
 */
MacOp *change_operation(MacOp *list_macops, int id_operation)
{
    int id_machine, new_time;

    printf("Selecione a maquina a ser alterado o seu tempo:\n");
    show_machines_by_op_id(list_macops, id_operation);
    scanf("%d", &id_machine);

    printf("\nInsira o novo tempo: ");
    scanf("%d", &new_time);

    while (list_macops)
    {
        if (list_macops->id_op == id_operation && list_macops->id_mac == id_machine)
        {
            list_macops->time = new_time;
        }
        list_macops = list_macops->next;
    }

    return list_macops;
}

/**
 * @brief Determinação da quantidade média de unidades de tempo necessárias para completar uma operação,
 *        considerando todas as alternativas possíveis
 *
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação
 */
float avg_time(MacOp **list_macops, int id_operation)
{
    int sum = 0, count = 0;
    MacOp *head_macop;

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
        min = get_max_time(*list_macops);
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

/**
 * @brief Remoção de um job
 * Sucessidamente ira remover das restantes listas a ligações
 *
 * @param list_jobs Lista de jobs
 * @param list_opjobs Lista intermedia de jobs e operações
 * @param list_operations Lista de operações
 * @param list_macops Lista intermedia de máquinas e operações
 * @param id_job Id do job a ser removido
 * @return Job*
 */
Job *remove_job(Job *list_jobs, OpJob **list_opjobs, Operation **list_operations, MacOp **list_macops, int id_job)
{
    Job *head_job = malloc(sizeof(Job));
    OpJob *head_opjob = malloc(sizeof(OpJob));

    head_job = list_jobs;
    while (head_job)
    {
        if (head_job->id_job == id_job)
        {
            head_opjob = *list_opjobs;
            while (head_opjob)
            {
                if (head_opjob->id_job == id_job)
                {
                    // remoção das restantes ligações nas outras listas (operaçoes e macops)
                    *list_operations = remove_operation(*list_operations, list_macops, head_opjob->id_op);

                    if (head_opjob->next)
                        head_opjob->next->previous = head_opjob->previous;
                    if (head_opjob->previous)
                        head_opjob->previous->next = head_opjob->next;
                    else
                        *list_opjobs = head_opjob->next;

                    free(head_opjob);
                }

                head_opjob = head_opjob->next;
            }

            if (head_job->next)
                head_job->next->previous = head_job->previous;
            if (head_job->previous)
                head_job->previous->next = head_job->next;
            else
                list_jobs = head_job->next;
        }

        head_job = head_job->next;
    }
    free(head_job);

    return list_jobs;
}

#pragma endregion

#pragma region MENUS

/**
 * @brief texto apresentado ao utilizador no Menu principal
 *
 */
void interface_principal()
{
    printf("----------------------\n");
    printf("        Menu Principal      \n");
    printf(" [1]-Visualizar Jobs\n [2]-Inserir Job\n [3]-Remover Job");
    printf("\n [4]-Inserir Operacao em Job\n [5]-Remover Operacao em Job\n [6]-Editar Operacao em Job");
    printf("\n [7]-Tempo Minimo Job\n [8]-Tempo Maximo Job\n [9]-Media de Tempo (operacao)");
    printf("\n [10]-Simular\n [11]-(ponto 9 TO DO)\n [0]- Sair\n");
    printf("----------------------\n");
    printf("\n-->");
}

void menu_principal(Job **list_jobs, OpJob **list_opjobs, Operation **list_operations, MacOp **list_macops, Machine **list_machines)
{
    int op;
    interface_principal();
    scanf("%d", &op);

    while (op != 0)
    {
        switch (op)
        {

        case 1:
            system("cls");
            {
                show_jobs(*list_jobs);
                show_opjobs(*list_opjobs);
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
                Job *aux_job = (Job *)malloc(sizeof(Job));
                aux_job->id_job = get_new_job_id(*list_jobs);
                *list_jobs = head_insert_job(*list_jobs, aux_job);
            }
            system("cls");
            break;

        case 3:
            system("cls");
            {
                int id_job;
                show_jobs(*list_jobs);
                printf("\nSelecione o id a remover: ");
                scanf("%d", &id_job);
                *list_jobs = remove_job(*list_jobs, list_opjobs, list_operations, list_macops, id_job);
            }
            system("cls");
            break;

        case 4:
            system("cls");
            {
                int id_job;
                show_jobs(*list_jobs);
                printf("\nSelecione o id a remover: ");
                scanf("%d", &id_job);
                *list_operations = insert_operation(list_opjobs,*list_operations, list_macops, *list_machines, id_job);
                system("pause");
            }
            system("cls");
            break;

        case 5:
            system("cls");
            {
                // remover operaçao em job
                system("pause");
            }
            system("cls");
            break;

        case 6:
            system("cls");
            {
                // editar operacao em job
                system("pause");
            }
            system("cls");
            break;

        case 7:
            system("cls");
            {
                // tempo minimo de um job
                system("pause");
            }
            system("cls");
            break;

        case 8:
            system("cls");
            {
                // tempo maximo de um job
                system("pause");
            }
            system("cls");
            break;

        case 9:
            system("cls");
            {
                // Media de Tempo (operacao)
                system("pause");
            }
            system("cls");
            break;

        case 10:
            system("cls");
            {
                // Simular
                system("pause");
            }
            system("cls");
            break;

        case 11:
            system("cls");
            {
                // (ponto 9 TO DO)
                system("pause");
            }
            system("cls");
            break;

        default:
            system("cls");
            printf("Opcao invalida\nIntroduza novamente\n");
            break;
        }

        interface_principal();
        scanf("%d", &op);
    }
}

#pragma endregion