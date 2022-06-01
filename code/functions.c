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
    FILE *file = fopen("files/machines.txt", "r");
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

    int c = fgetc(file);
    if (c == EOF)
    {
        return list_machines;
    }
    else
    {
        ungetc(c, file);
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
    FILE *file = fopen("files/machines.txt", "w");

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
 * @brief Leitura do ficheiro jobs.txt e armazenamento em memória
 *
 * @param list_jobs Lista intermedia que contem jobs
 * @return Job*
 */
Job *read_jobs(Job *list_jobs)
{
    FILE *file = fopen("files/jobs.txt", "r");
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

    int c = fgetc(file);
    if (c == EOF)
    {
        return list_jobs;
    }
    else
    {
        ungetc(c, file);
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
    FILE *file = fopen("files/jobs.txt", "w");

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

/**
 * @brief Leitura do ficheiro connections.txt e armazenamento em memória
 *
 * @param list_connections Lista intermedia que contem jobs
 * @return Connection*
 */
Connection *read_connections(Connection *list_connections)
{
    FILE *file = fopen("files/connections.txt", "r");
    Connection *aux = (Connection *)malloc(sizeof(Connection));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return NULL;
    }

    if (aux == NULL)
    {
        return list_connections;
    }

    int c = fgetc(file);
    if (c == EOF)
    {
        return list_connections;
    }
    else
    {
        ungetc(c, file);
    }

    while (!feof(file))
    {
        fscanf(file, "%d\t%d\t%d\t%d\n", &aux->id_job, &aux->id_op, &aux->id_mac, &aux->time);
        list_connections = head_insert_connection(list_connections, aux);
    }

    free(aux);
    fclose(file);
    return list_connections;
}

/**
 * @brief Escrita do ficheiro connections.txt e armazenamento em memória
 *
 * @param list_connections
 * @return Connection*
 */
Connection *write_connections(Connection *list_connections)
{
    FILE *file = fopen("files/connections.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return list_connections;
    }

    while (list_connections)
    {
        fprintf(file, "%d\t%d\t%d\t%d\n", list_connections->id_job, list_connections->id_op, list_connections->id_mac, list_connections->time);
        list_connections = list_connections->next;
    }

    fclose(file);
    return list_connections;
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

/**
 * @brief Desalocar memória ocupada pela lista de conexões
 *
 * @param list_connections lista de conexões
 * @return int
 */
int free_connections(Connection *list_connections)
{
    Connection *aux = (Connection *)malloc(sizeof(Connection));

    while (list_connections)
    {
        aux = list_connections;
        list_connections = list_connections->next;
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

/**
 * @brief Inserção á cabeça na lista das conexões
 *
 * @param list_connections Lista das conexões
 * @param aux Lista auxiliar
 * @return Connection*
 */
Connection *head_insert_connection(Connection *list_connections, Connection *aux)
{
    // Alocar memoria para nodo
    Connection *tmp = (Connection *)malloc(sizeof(Connection));

    // Inserir valores a guardar
    tmp->id_job = aux->id_job;
    tmp->id_op = aux->id_op;
    tmp->id_mac = aux->id_mac;
    tmp->time = aux->time;

    // Novo nodo aponta para início da lista
    tmp->next = list_connections;
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
 * @brief Verifica se um id de uma operação de um job inserido existe na lista das conexões
 *
 * @param list_connections lista das conexões
 * @param id_operation id da operação selecionado
 * @param id_job id do job
 * @return int
 */
int exist_operation(Connection *list_connections, int id_operation, int id_job)
{
    while (list_connections)
    {
        if (list_connections->id_op == id_operation && list_connections->id_job == id_job)
        {
            // true
            return 1;
        }

        list_connections = list_connections->next;
    }
    // false
    return 0;
}

/**
 * @brief Verifica se uma combinação de id_mac, id_op e id_job existe na lista das conexões
 *
 * @param list_connections lista de conexões
 * @param id_machine id da máquina
 * @param id_operation id da operação
 * @param id_job id do job
 * @return int
 */
int exist_connection(Connection *list_connections, int id_machine, int id_operation, int id_job)
{
    while (list_connections)
    {
        if (list_connections->id_job == id_job && list_connections->id_op == id_operation && list_connections->id_mac == id_machine)
        {
            // true
            return 1;
        }

        list_connections = list_connections->next;
    }
    // false
    return 0;
}

#pragma endregion

#pragma region GETS

/**
 * @brief Função para encontrar o próximo id da lista das conexões a ser usado por uma nova
 * operação a ser inserida na respetiva função
 *
 * @param list_connections lista das conexões
 * @param id_job id do job
 * @return int
 */
int get_new_operation_id(Connection *list_connections, int id_job)
{
    int new_id = 0;
    while (list_connections)
    {
        if (list_connections->id_op > new_id && list_connections->id_job == id_job)
        {
            new_id = list_connections->id_op;
        }

        list_connections = list_connections->next;
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
 * @brief Mostra maquinas de uma operação de um job, pelo seu id de operação e id do job
 *
 * @param list_connections lista de conexões
 * @param id_operation id da operação
 * @param id_job id do job
 */
void show_machines_by_opjob_id(Connection *list_connections, int id_operation, int id_job)
{
    printf("----------------------------------\n");
    printf("          Lista Intermedia        \n");
    printf("       (Job %d / Operacao %d)     \n", id_job, id_operation);
    printf("----------------------------------\n");
    while (list_connections)
    {
        if (list_connections->id_op == id_operation && list_connections->id_job == id_job)
        {
            printf("ID Maquina: %d / Time: %d\n", list_connections->id_mac, list_connections->time);
        }
        list_connections = list_connections->next;
    }
    printf("----------------------------------\n");
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

/**
 * @brief Mostra os ids das operacoes pertencentes a um job passado por id
 *
 * @param list_connections lista de conexões
 * @param id_job id do job
 */
void show_operations_by_job(Connection *list_connections, int id_job)
{
    int id_op_rep = -1;

    printf("----------------------------------\n");
    printf("          Lista Intermedia        \n");
    printf("             (Job %d) \n", id_job);
    printf("----------------------------------\n");
    while (list_connections)
    {
        if (list_connections->id_job == id_job && list_connections->id_op != id_op_rep)
        {
            printf("ID Operacao: %d\n", list_connections->id_op);
            id_op_rep = list_connections->id_op;
        }
        list_connections = list_connections->next;
    }
    printf("----------------------------------\n");
}

/**
 * @brief Mostra todas as conexões da lista
 *
 * @param list_connections Lista de conexões
 */
void show_connections(Connection *list_connections)
{
    printf("----------------------------------\n");
    printf("          Lista Conexoes          \n");
    printf("----------------------------------\n");
    while (list_connections)
    {
        printf("ID Job: %d / ID Operacao: %d / ID Maquina: %d / Duracao: %d\n", list_connections->id_job, list_connections->id_op, list_connections->id_mac, list_connections->time);
        list_connections = list_connections->next;
    }
    printf("----------------------------------\n");
}

#pragma endregion

#pragma region COUNTS

/**
 * @brief Conta o numero de vezes que um id de operacao aparece num job
 *
 * @param list_connections lista de conexoes
 * @param id_operation id da operacao
 * @param id_job id do job
 * @return int
 */
int count_op_ids(Connection *list_connections, int id_operation, int id_job)
{
    int count = 0;
    while (list_connections)
    {
        if (list_connections->id_job == id_job && list_connections->id_op == id_operation)
        {
            count++;
        }

        list_connections = list_connections->next;
    }

    return count;
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
Connection *insert_operation(Connection *list_connections, Machine *list_machines, int id_job)
{
    Connection *head_connection = malloc(sizeof(Connection));

    Connection *aux_connection = (Connection *)malloc(sizeof(Connection));

    head_connection = list_connections;

    aux_connection->id_op = get_new_operation_id(list_connections, id_job);
    aux_connection->id_job = id_job;

    show_machines(list_machines);
    printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
    scanf("%d", &aux_connection->id_mac);

    if (aux_connection->id_mac >= 0)
    {
        if (exist_machine(list_machines, aux_connection->id_mac))
        {
            printf("\nInsira o tempo:");
            scanf("%d", &aux_connection->time);

            if (exist_connection(list_connections, aux_connection->id_mac, aux_connection->id_op, aux_connection->id_job))
                printf("\nEsta combinacaoo ja existe\nNao inserido\n");
            else
            {
                list_connections = head_insert_connection(head_connection, aux_connection);
                head_connection = list_connections;
            }
        }
        else if (aux_connection->id_mac >= 0)
            printf("\nEssa maquina nao existe\n");
    }

    while (aux_connection->id_mac >= 0)
    {
        show_machines(list_machines);
        printf("\n\n(Insira numero negativo para terminar de associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
        scanf("%d", &aux_connection->id_mac);

        if (aux_connection->id_mac >= 0)
        {
            if (exist_machine(list_machines, aux_connection->id_mac))
            {
                printf("\nInsira o tempo:");
                scanf("%d", &aux_connection->time);

                if (exist_connection(list_connections, aux_connection->id_mac, aux_connection->id_op, aux_connection->id_job))
                    printf("\nEsta combinacaoo ja existe\nNao inserido\n");
                else
                {
                    list_connections = head_insert_connection(head_connection, aux_connection);
                    head_connection = list_connections;
                }
            }
            else if (aux_connection->id_mac >= 0)
                printf("\nEssa maquina nao existe\n");
        }
    }

    return list_connections;
}

/**
 * @brief Remoção de uma operação da lista operações e respetivamente da lista intermedia MacOp
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação a ser removida
 */
Connection *remove_operation(Connection *list_connections, int id_operation, int id_job)
{
    Connection *head_connection;
    head_connection = list_connections;
    int count = 0;
    while (head_connection)
    {

        if (head_connection->id_job == id_job && head_connection->id_op == id_operation)
        {
            if (head_connection->next)
                head_connection->next->previous = head_connection->previous;
            if (head_connection->previous)
                head_connection->previous->next = head_connection->next;
            else
                list_connections = head_connection->next;
        }

        // ao remover a operaçao as restantes devem decrementar o seu id para normalizar
        // verifica se ainda existem ops selecionadas para remover
        if (head_connection->id_op > id_operation && head_connection->id_job == id_job)
        {
            head_connection->id_op -= 1;
        }

        head_connection = head_connection->next;
    }

    free(head_connection);

    return list_connections;
}

/**
 * @brief Alteração de uma operação da lista operações
 * Altera os tempos de máquinas que selecione
 *
 * @param list_operations lista das operações
 * @param list_macops lista intermedia entre as operações e as máquinas
 * @param id_operation id da operação a ser alterada
 */
Connection *change_operation(Connection *list_connections, int id_operation, int id_job, int id_machine, int new_time)
{
    Connection *head_connection;
    head_connection = list_connections;

    while (head_connection)
    {
        if (head_connection->id_job == id_job && head_connection->id_op == id_operation && head_connection->id_mac == id_machine)
        {
            head_connection->time = new_time;
        }
        head_connection = head_connection->next;
    }

    // fica a apontar para o inicio da lista
    head_connection = list_connections;

    return head_connection;
}

/**
 * @brief Determinação da quantidade média de unidades de tempo necessárias para completar uma operação de um job,
 *        considerando todas as alternativas possíveis
 *
 * @param list_connections lista das conexões
 * @param id_operation id da operação selecionada
 * @param id_job id do job selecionado
 * @return float
 */
float avg_time(Connection *list_connections, int id_operation, int id_job)
{
    int sum = 0, count = 0;

    while (list_connections)
    {
        if (list_connections->id_op == id_operation && list_connections->id_job == id_job)
        {
            sum += list_connections->time;
            count++;
        }
        list_connections = list_connections->next;
    }

    return (float)sum / count;
}

#pragma endregion

#pragma region JOB

/**
 * @brief Determinação da quantidade minima de unidades de tempo necessárias para completar o job
 *
 * @param list_connections lista das conexões
 * @param id_job id do job selecionado
 * @return int
 */
int min_time(Connection *list_connections, int id_job)
{
    int sum = 0, min, id_op_rep = -1;
    Connection *head_connection;

    while (list_connections)
    {
        if (list_connections->id_job == id_job && list_connections->id_op != id_op_rep)
        {
            min = list_connections->time;
            head_connection = list_connections;
            while (head_connection)
            {
                if (list_connections->id_op == head_connection->id_op && head_connection->time < min && head_connection->id_job == id_job)
                {
                    min = head_connection->time;
                    id_op_rep = head_connection->id_op;
                }
                head_connection = head_connection->next;
            }
            sum += min;
        }
        list_connections = list_connections->next;
    }

    return sum;
}

/**
 * @brief Determinação da quantidade máxima de unidades de tempo necessárias para completar o job
 *
 * @param list_connections lista das conexões
 * @param id_job id do job selecionado
 * @return int
 */
int max_time(Connection *list_connections, int id_job)
{
    int sum = 0, max, id_op_rep = -1;
    Connection *head_connection;

    while (list_connections)
    {
        if (list_connections->id_job == id_job && list_connections->id_op != id_op_rep)
        {
            max = 0;
            head_connection = list_connections;
            while (head_connection)
            {
                if (list_connections->id_op == head_connection->id_op && head_connection->time > max && head_connection->id_job == id_job)
                {
                    max = head_connection->time;
                    id_op_rep = head_connection->id_op;
                }
                head_connection = head_connection->next;
            }
            sum += max;
        }
        list_connections = list_connections->next;
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
Job *remove_job(Job *list_jobs, Connection **list_connections, int id_job)
{
    Job *head_job = malloc(sizeof(Job));
    Connection *head_connection = malloc(sizeof(Connection));

    head_job = list_jobs;
    while (head_job)
    {
        if (head_job->id_job == id_job)
        {
            head_connection = *list_connections;
            while (head_connection)
            {
                if (head_connection->id_job == id_job)
                {

                    if (head_connection->next)
                        head_connection->next->previous = head_connection->previous;
                    if (head_connection->previous)
                        head_connection->previous->next = head_connection->next;
                    else
                        *list_connections = head_connection->next;

                    free(head_connection);
                }
                head_connection = head_connection->next;
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

#pragma region SIMULATION

/**
int simulation(Connection *list_connections)
{
    // percorrer as listas
    // verificar se maquinas sáo iguais
    //  se náo forem -> ambas iniciam no instante 0
    //  se forem -> verificar se tem tempos diferentes
    //  se m1 tiver mais tempo que m2 -> inicia no instante 0 job/op da m2
    // se forem iguais -> ???
    // enviar dados para a celula plano
    // enviar tudo para html tabelar

    int id_mac = 0, time;
    CelulaPlano simulation[][];
    Connection *head_connection, *head_connection2, *aux;

    while (mac != get_last_mac())
    {
        head_connection = *list_connections;
        while (head_connection)
        {
            if (head_connection->id_mac == id_mac)
            {
                head_connection2 = *list_connections;
                time = head_connection->time;
                while (head_connection2)
                {
                    if (head_connection->id_op == head_connection2->id_op && head_connection2->time < time)
                    {
                        aux = head_connection2;
                    }

                    head_connection2 = head_connection2->next;
                }
                simulation[aux->id_mac][t];

            }

            head_connection = head_connection->next;
        }

        id_mac++;
    }
}

int Ocupa(int job, int oper, int maq, int t)
{
}
**/

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
    printf("\n [7]-Tempo Minimo Job\n [8]-Tempo Maximo Job\n [9]-Media de Tempo (operacao)\n [0]- Sair\n");
    printf("----------------------\n");
    printf("\n-->");
}

/**
 * @brief Menu de opcoes
 *
 * @param list_jobs lista de jobs
 * @param list_operations lista de operacoes
 * @param list_machines lista de maquinas
 * @param list_connections lista de conexões
 */
void menu_principal(Job **list_jobs, Machine **list_machines, Connection **list_connections)
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
                show_machines(*list_machines);
                show_connections(*list_connections);
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
                *list_jobs = remove_job(*list_jobs, list_connections, id_job);
            }
            system("cls");
            break;

        case 4:
            system("cls");
            {
                int id_job;
                show_jobs(*list_jobs);
                printf("\nSelecione o id do job: ");
                scanf("%d", &id_job);
                *list_connections = insert_operation(*list_connections, *list_machines, id_job);
                system("pause");
            }
            system("cls");
            break;

        case 5:
            system("cls");
            {
                int id_job, id_operation;
                show_jobs(*list_jobs);
                printf("\nSelecione o id do job: ");
                scanf("%d", &id_job);
                show_operations_by_job(*list_connections, id_job);
                printf("\nSelecione o id da operacao a ser removida:");
                scanf("%d", &id_operation);
                *list_connections = remove_operation(*list_connections, id_operation, id_job);
                system("pause");
            }
            system("cls");
            break;

        case 6:
            system("cls");
            {
                int id_job, id_operation, id_machine, new_time;
                show_jobs(*list_jobs);
                printf("\nSelecione o id do job: ");
                scanf("%d", &id_job);

                show_operations_by_job(*list_connections, id_job);
                printf("\nSelecione o id da operacao:");
                scanf("%d", &id_operation);

                printf("Selecione a maquina a ser alterado o seu tempo:\n");
                show_machines_by_opjob_id(*list_connections, id_operation, id_job);
                scanf("%d", &id_machine);

                printf("\nInsira o novo tempo: ");
                scanf("%d", &new_time);

                *list_connections = change_operation(*list_connections, id_operation, id_job, id_machine, new_time);
                system("pause");
            }
            system("cls");
            break;

        case 7:
            system("cls");
            {
                int id_job;
                show_jobs(*list_jobs);
                printf("\nSelecione o id do job: ");
                scanf("%d", &id_job);
                printf("\nTempo minimo do job %d: %d\n", id_job, min_time(*list_connections, id_job));
                system("pause");
            }
            system("cls");
            break;

        case 8:
            system("cls");
            {
                int id_job;
                show_jobs(*list_jobs);
                printf("\nSelecione o id do job: ");
                scanf("%d", &id_job);
                printf("\nTempo maximo do job %d: %d\n", id_job, max_time(*list_connections, id_job));
                system("pause");
            }
            system("cls");
            break;

        case 9:
            system("cls");
            {
                int id_job, id_operation;
                show_jobs(*list_jobs);
                printf("\nSelecione o id do job: ");
                scanf("%d", &id_job);
                show_operations_by_job(*list_connections, id_job);
                printf("\nSelecione o id da operacao: ");
                scanf("%d", &id_operation);
                printf("\nMedia de tempo (Job %d / Operacao %d): %.2f\n", id_job, id_operation, avg_time(*list_connections, id_operation, id_job));
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