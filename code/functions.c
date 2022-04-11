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
 * @param listMachine Lista que contem todas as máquinas
 * @return Machine*
 */
Machine *readMachines(Machine *listMachine)
{
    FILE *file = fopen("machines.txt", "r");
    Machine *aux = (Machine *)malloc(sizeof(Machine));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return listMachine;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\t%d\n", &aux->id_mac, &aux->time);
        listMachine = head_insert_machine(listMachine, aux);
    }

    free(aux);
    fclose(file);
    return listMachine;
}

/**
 * @brief Escrita do ficheiro machines.txt e armazenamento em memória
 *
 * @param listMachine lista das maquinas
 * @return Machine*
 */
Machine *writeMachines(Machine *listMachine)
{
    FILE *file = fopen("machines.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return listMachine;
    }

    while (listMachine)
    {
        fprintf(file, "%d\t%d\n", listMachine->id_mac, listMachine->time);
        listMachine = listMachine->next;
    }

    fclose(file);
    return listMachine;
}

/**
 * @brief Leitura do ficheiro macop.txt e armazenamento em memória
 *
 * @param listMacOp Lista que contem os ids de todas as operações e suas respetivas máquinas
 * @return MacOp*
 */
MacOp *readMacOp(MacOp *listMacOp)
{
    FILE *file = fopen("macop.txt", "r");
    MacOp *aux = (MacOp *)malloc(sizeof(MacOp));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return listMacOp;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\t%d\n", &aux->id_op, &aux->id_mac);
        listMacOp = head_insert_macop(listMacOp, aux);
    }

    free(aux);
    fclose(file);
    return listMacOp;
}

/**
 * @brief Escrita do ficheiro macop.txt e armazenamento em memória
 *
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @return MacOp*
 */
MacOp *writeMacOp(MacOp *listMacOp)
{
    FILE *file = fopen("macop.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return listMacOp;
    }

    while (listMacOp)
    {
        fprintf(file, "%d\t%d\n", listMacOp->id_op, listMacOp->id_mac);
        listMacOp = listMacOp->next;
    }

    fclose(file);
    return listMacOp;
}

/**
 * @brief Leitura do ficheiro operations.txt e armazenamento em memória
 *
 * @param listOperation Lista que contem todas as operações
 * @return Operation*
 */
Operation *readOperations(Operation *listOperation)
{
    FILE *file = fopen("operations.txt", "r");
    Operation *aux = (Operation *)malloc(sizeof(Operation));

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return listOperation;
    }

    while (!feof(file))
    {
        fscanf(file, "%d\n", &aux->id_op);
        listOperation = head_insert_operation(listOperation, aux);
    }

    free(aux);
    fclose(file);
    return listOperation;
}

/**
 * @brief Escrita do ficheiro operations.txt e armazenamento em memória
 *
 * @param listOperation lista das operações
 * @return Operation*
 */
Operation *writeOperations(Operation *listOperation)
{
    FILE *file = fopen("operations.txt", "w");

    if (file == NULL)
    {
        printf("Ficheiro não pode ser aberto!\n");
        getchar();
        return listOperation;
    }

    while (listOperation)
    {
        fprintf(file, "%d\n", listOperation->id_op);
        listOperation = listOperation->next;
    }

    fclose(file);
    return listOperation;
}

#pragma endregion

#pragma region FREE

/**
 * @brief Desalocar memória ocupada pela lista das máquinas
 *
 * @param list lista das máquinas
 */
void freeMachines(Machine *list)
{
    Machine *aux = malloc(sizeof(Machine));

    while (list)
    {
        aux = list;
        list = list->next;
        free(aux);
    }
}

/**
 * @brief Desalocar memória ocupada pela lista MacOp
 *
 * @param list lista MacOp
 */
void freeMacOp(MacOp *list)
{
    MacOp *aux = malloc(sizeof(MacOp));

    while (list)
    {
        aux = list;
        list = list->next;
        free(aux);
    }
}

/**
 * @brief Desalocar memória ocupada pela lista das operações
 *
 * @param list lista das operações
 */
void freeOperations(Operation *list)
{
    Operation *aux = malloc(sizeof(Operation));

    while (list)
    {
        aux = list;
        list = list->next;
        free(aux);
    }
}

#pragma endregion

#pragma region HEAD_INSERTS

/**
 * @brief Inserção á cabeça na lista das máquinas
 *
 * @param list Lista das máquinas
 * @param aux Lista auxiliar
 * @return Machine*
 */
Machine *head_insert_machine(Machine *list, Machine *aux)
{
    // Alocagem de memoria para nodo
    Machine *tmp = (Machine *)malloc(sizeof(Machine));

    // Inserição dos valores a armazenar
    tmp->id_mac = aux->id_mac;
    tmp->time = aux->time;

    // Novo nodo aponta para início da lista
    tmp->next = list;
    if (tmp->next)
        tmp->next->previous = tmp;
    tmp->previous = NULL;

    // Retorno do tmp, pois este agora é o início da lista
    return tmp;
}

/**
 * @brief Inserção á cabeça na lista MacOp
 *
 * @param list Lista MacOp
 * @param aux Lista auxiliar
 * @return MacOp*
 */
MacOp *head_insert_macop(MacOp *list, MacOp *aux)
{
    // Alocagem de memoria para nodo
    MacOp *tmp = (MacOp *)malloc(sizeof(MacOp));

    // Inserção dos valores a armazenar
    tmp->id_mac = aux->id_mac;
    tmp->id_op = aux->id_op;

    // Novo nodo aponta para início da lista
    tmp->next = list;
    if (tmp->next)
        tmp->next->previous = tmp;
    tmp->previous = NULL;

    // Retorno do tmp, pois este agora é o início da lista
    return tmp;
}

/**
 * @brief Inserção á cabeça na lista das operações
 *
 * @param list Lista de operações
 * @param aux Lista auxiliar
 * @return Operation*
 */
Operation *head_insert_operation(Operation *list, Operation *aux)
{
    // Alocar memoria para nodo
    Operation *tmp = (Operation *)malloc(sizeof(Operation));

    // Inserir valores a guardar
    tmp->id_op = aux->id_op;

    // Novo nodo aponta para início da lista
    tmp->next = list;
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
 * @param listMachine lista das máquinas
 * @param id id de uma máquina inserido
 * @return int
 */
int exist_mac(Machine **listMachine, int id)
{
    Machine *head_mac = malloc(sizeof(Machine));
    head_mac = *listMachine;

    while (head_mac)
    {
        if (head_mac->id_mac == id)
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
 * @param listOperation lista das operações
 * @param id id de uma operação inserido
 * @return int
 */
int exist_op(Operation **listOperation, int id)
{
    Operation *head_op = malloc(sizeof(Operation));
    head_op = *listOperation;

    while (head_op)
    {
        if (head_op->id_op == id)
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
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param id_mac id da maquina
 * @param id_op id da operação
 * @return int
 */
int exist_MacOp(MacOp **listMacOp, int id_mac, int id_op)
{
    MacOp *head_mac_op = malloc(sizeof(MacOp));
    head_mac_op = *listMacOp;

    while (head_mac_op)
    {
        if (head_mac_op->id_op == id_op && head_mac_op->id_mac == id_mac)
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
 * @param listMachine lista das máquinas
 * @return int
 */
int get_max_time(Machine **listMachine)
{
    int max = 0;
    Machine *head_mac = malloc(sizeof(Machine));
    head_mac = *listMachine;

    while (head_mac)
    {
        if (head_mac->time > max)
        {
            max = head_mac->time;
        }
        head_mac = head_mac->next;
    }

    return max;
}

#pragma endregion

#pragma region SHOW FUNCTIONS

/**
 * @brief Listagem das máquinas na lista
 *
 * @param list Lista das máquinas
 */
void showMachineList(Machine *list)
{
    printf("-------------------------\n");
    printf("    Lista das Maquinas   \n");
    printf("-------------------------\n");
    while (list)
    {
        printf("ID: %d / TIME: %d\n", list->id_mac, list->time);
        list = list->next;
    }
    printf("-------------------------\n");
}

/**
 * @brief listagem da lista intermedia entre as operações e as máquinas
 *
 * @param list Lista MacOp
 */
void showMacOpList(MacOp *list)
{
    printf("----------------------------------\n");
    printf("          Lista Intermedia        \n");
    printf("       (Maquinas e Operacoes) \n");
    printf("----------------------------------\n");
    while (list)
    {
        printf("ID Operacao: %d / ID Maquina: %d\n", list->id_op, list->id_mac);
        list = list->next;
    }
    printf("----------------------------------\n");
}

/**
 * @brief Listagem das operações na lista
 *
 * @param list Lista das operações
 */
void showOperationList(Operation *list)
{
    printf("-------------------------\n");
    printf("   Lista das Operacoes   \n");
    printf("-------------------------\n");
    while (list)
    {
        printf("ID: %d\n", list->id_op);
        list = list->next;
    }
    printf("-------------------------\n");
}

#pragma endregion

#pragma region MAC OP

/**
 * @brief Remoção de uma operação da lista intermedia MacOp
 * 
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param id_op id da operação a ser removida
 */
void remove_MacOp(MacOp **listMacOp, int id_op)
{
    MacOp *head_MacOp = malloc(sizeof(MacOp));
    head_MacOp = *listMacOp;

    while (head_MacOp)
    {
        if (head_MacOp->id_op == id_op)
        {
            if (head_MacOp->next)
                head_MacOp->next->previous = head_MacOp->previous;
            if (head_MacOp->previous)
                head_MacOp->previous->next = head_MacOp->next;
            else
                *listMacOp = head_MacOp->next;

            free(head_MacOp);
        }

        head_MacOp = head_MacOp->next;
    }
}

#pragma endregion

#pragma region OPERATIONS

/**
 * @brief Inserção de uma operação na lista das operações e lista MacOp
 *
 * @param listOperation lista das operações
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param listMachine lista das máquinas
 */
void insert_operation(Operation **listOperation, MacOp **listMacOp, Machine *listMachine)
{
    Operation *head_Op = malloc(sizeof(Operation));
    MacOp *head_MacOp = malloc(sizeof(MacOp));

    Operation *aux_op = (Operation *)malloc(sizeof(Operation));
    MacOp *aux_macOp = (MacOp *)malloc(sizeof(MacOp));

    head_Op = *listOperation;
    head_MacOp = *listMacOp;

    aux_macOp->id_op = head_Op->id_op + 1;
    aux_op->id_op = head_Op->id_op + 1;

    showMachineList(listMachine);
    printf("\n\n(Insira numero negativo para terminar nao associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
    scanf("%d", &aux_macOp->id_mac);

    if (exist_mac(&listMachine, aux_macOp->id_mac))
    {
        if (exist_MacOp(listMacOp, aux_macOp->id_mac, aux_macOp->id_op))
            printf("\nEsta combinação ja existe\nNao inserido\n");
        else
            *listMacOp = head_insert_macop(head_MacOp, aux_macOp);
    }
    else if (aux_macOp->id_mac >= 0)
        printf("Essa maquina nao existe");

    while (aux_macOp->id_mac >= 0)
    {
        showMachineList(listMachine);
        printf("\n\n(Insira numero negativo para terminar nao associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
        scanf("%d", &aux_macOp->id_mac);

        if (exist_mac(&listMachine, aux_macOp->id_mac))
        {
            if (exist_MacOp(listMacOp, aux_macOp->id_mac, aux_macOp->id_op))
                printf("\nEsta combinação ja existe\nNao inserido\n");
            else
                *listMacOp = head_insert_macop(head_MacOp, aux_macOp);
        }
        else if (aux_macOp->id_mac >= 0)
            printf("Essa maquina nao existe");
    }

    *listOperation = head_insert_operation(head_Op, aux_op);

    free(aux_op);
    free(aux_macOp);
}

/**
 * @brief Remoção de uma operação da lista operações e respetivamente da lista intermedia MacOp
 *
 * @param listOperation lista das operações
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param id_op id da operação a ser removida
 */
void remove_operation(Operation **listOperation, MacOp **listMacOp, int id_op)
{
    Operation *head_Op = malloc(sizeof(Operation));
    MacOp *head_MacOp = malloc(sizeof(MacOp));

    head_Op = *listOperation;
    while (head_Op)
    {
        if (head_Op->id_op == id_op)
        {
            head_MacOp = *listMacOp;
            while (head_MacOp)
            {
                if (head_MacOp->id_op == id_op)
                {
                    if (head_MacOp->next)
                        head_MacOp->next->previous = head_MacOp->previous;
                    if (head_MacOp->previous)
                        head_MacOp->previous->next = head_MacOp->next;
                    else
                        *listMacOp = head_MacOp->next;

                    free(head_MacOp);
                }

                head_MacOp = head_MacOp->next;
            }

            if (head_Op->next)
                head_Op->next->previous = head_Op->previous;
            if (head_Op->previous)
                head_Op->previous->next = head_Op->next;
            else
                *listOperation = head_Op->next;

        }

        head_Op = head_Op->next;
    }
    free(head_Op);
}

/**
 * @brief Alteração de uma operação da lista operações
 *
 * @param listOperation lista das operações
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param id_op id da operação a ser alterada
 */
void change_operation(MacOp **listMacOp, Machine *listMachine, int id_op)
{
    remove_MacOp(listMacOp, id_op);

    MacOp *head_MacOp = malloc(sizeof(MacOp));
    head_MacOp = *listMacOp;

    MacOp *aux_macOp = (MacOp *)malloc(sizeof(MacOp));
    aux_macOp->id_op = id_op;

    showMachineList(listMachine);
    printf("\n\n(Insira numero negativo para terminar nao associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
    scanf("%d", &aux_macOp->id_mac);

    if (exist_mac(&listMachine, aux_macOp->id_mac))
    {
        if (exist_MacOp(listMacOp, aux_macOp->id_mac, id_op))
            printf("\nEsta combinação ja existe\nNao inserido\n");
        else
            *listMacOp = head_insert_macop(head_MacOp, aux_macOp);
    }
    else if (aux_macOp->id_mac >= 0)
        printf("Essa maquina nao existe");

    while (aux_macOp->id_mac >= 0)
    {
        showMachineList(listMachine);
        printf("\n\n(Insira numero negativo para terminar nao associar mais maquinas)\nSelecione o id da maquina a associar a operacao: ");
        scanf("%d", &aux_macOp->id_mac);

        if (exist_mac(&listMachine, aux_macOp->id_mac))
        {
            if (exist_MacOp(listMacOp, aux_macOp->id_mac, id_op))
                printf("\nEsta combinação ja existe\nNao inserido\n");
            else
                *listMacOp = head_insert_macop(head_MacOp, aux_macOp);
        }
        else if (aux_macOp->id_mac >= 0)
            printf("Essa maquina nao existe");
    }
}

/**
 * @brief Determinação da quantidade média de unidades de tempo necessárias para completar uma operação,
 *        considerando todas as alternativas possíveis
 *
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param listMachine lista das máquinas
 * @param id_op id da operação
 */
float avg_time(MacOp **listMacOp, Machine **listMachine, int id_op)
{
    int sum = 0, count = 0;
    MacOp *head_MacOp = malloc(sizeof(MacOp));
    Machine *head_Mac = malloc(sizeof(Machine));

    head_MacOp = *listMacOp;
    while (head_MacOp)
    {
        if (head_MacOp->id_op == id_op)
        {
            head_Mac = *listMachine;
            while (head_Mac)
            {
                if (head_MacOp->id_mac == head_Mac->id_mac)
                {
                    sum += head_Mac->time;
                    count++;
                }
                head_Mac = head_Mac->next;
            }
        }
        head_MacOp = head_MacOp->next;
    }

    return (float)sum / count;
}

#pragma endregion

#pragma region JOB

/**
 * @brief Determinação da quantidade mínima de unidades de tempo necessárias para completar o job e listagem das
 *        respetivas operações
 *
 * @param listOperation lista das operações
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param listMachine lista das máquinas
 */
int min_time(Operation **listOperation, MacOp **listMacOp, Machine **listMachine)
{
    int sum = 0, min;
    Operation *head_Op = malloc(sizeof(Operation));
    MacOp *head_MacOp = malloc(sizeof(MacOp));
    Machine *head_Mac = malloc(sizeof(Machine));

    head_Op = *listOperation;
    while (head_Op)
    {
        min = get_max_time(listMachine);
        head_MacOp = *listMacOp;
        while (head_MacOp)
        {
            if (head_Op->id_op == head_MacOp->id_op)
            {
                head_Mac = *listMachine;
                while (head_Mac)
                {
                    if (head_MacOp->id_mac == head_Mac->id_mac && head_Mac->time < min)
                    {
                        min = head_Mac->time;
                    }

                    head_Mac = head_Mac->next;
                }
            }
            head_MacOp = head_MacOp->next;
        }
        sum += min;
        head_Op = head_Op->next;
    }

    return sum;
}

/**
 * @brief Determinação da quantidade máxima de unidades de tempo necessárias para completar o job e listagem das
 *        respetivas operações
 *
 * @param listOperation lista das operações
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param listMachine lista das máquinas
 */
int max_time(Operation **listOperation, MacOp **listMacOp, Machine **listMachine)
{
    int sum = 0, max;
    Operation *head_Op = malloc(sizeof(Operation));
    MacOp *head_MacOp = malloc(sizeof(MacOp));
    Machine *head_Mac = malloc(sizeof(Machine));

    head_Op = *listOperation;
    while (head_Op)
    {
        max = 0;
        head_MacOp = *listMacOp;
        while (head_MacOp)
        {
            if (head_Op->id_op == head_MacOp->id_op)
            {
                head_Mac = *listMachine;
                while (head_Mac)
                {
                    if (head_MacOp->id_mac == head_Mac->id_mac && head_Mac->time > max)
                    {
                        max = head_Mac->time;
                    }

                    head_Mac = head_Mac->next;
                }
            }
            head_MacOp = head_MacOp->next;
        }
        sum += max;
        head_Op = head_Op->next;
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
 * @param listOperation lista das operações
 * @param listMacOp lista intermedia entre as operações e as máquinas
 * @param listMachine lista das máquinas
 *
 */
void menu_job(Operation **listOperation, MacOp **listMacOp, Machine **listMachine)
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
                showOperationList(*listOperation);
                showMacOpList(*listMacOp);
                showMachineList(*listMachine);
                system("pause");
            }
            system("cls");
            break;

        case 2:
            system("cls");
            {
                insert_operation(listOperation, listMacOp, *listMachine);
                system("pause");
            }
            system("cls");
            break;

        case 3:
            system("cls");
            {
                int id_op;
                showOperationList(*listOperation);
                printf("\n\nSelecione o id da operacao a remover: ");
                scanf("%d", &id_op);
                if (exist_op(listOperation, id_op))
                {
                    remove_operation(listOperation, listMacOp, id_op);
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
                showOperationList(*listOperation);
                printf("\n\nSelecione o id da operacao a alterar: ");
                scanf("%d", &id_op);
                if (exist_op(listOperation, id_op))
                {
                    change_operation(listMacOp, *listMachine, id_op);
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
                showOperationList(*listOperation);
                printf("\n\nTempo minimo executado pelo job: %d\n", min_time(listOperation, listMacOp, listMachine));
                system("pause");
            }
            system("cls");
            break;

        case 6:
            system("cls");
            {
                showOperationList(*listOperation);
                printf("\n\nTempo maximo executado pelo job: %d\n", max_time(listOperation, listMacOp, listMachine));
                system("pause");
            }
            system("cls");
            break;

        case 7:
            system("cls");
            {
                int id_op;
                showOperationList(*listOperation);
                printf("\n\nSelecione o id da operacao: ");
                scanf("%d", &id_op);
                if (exist_op(listOperation, id_op))
                {
                    printf("\n\nTempo medio executado pela operacao %d: %.2f\n", id_op, avg_time(listMacOp, listMachine, id_op));
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