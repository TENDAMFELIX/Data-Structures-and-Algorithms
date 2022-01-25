#include <stdio.h>
#include <stdlib.h>
// [ O O ] TirthPatel3108
//    -
//    ~
struct NODE
{
    int DATA;
    struct NODE *NEXT, *PREV;
} *HEAD = NULL,*TAIL=NULL;
// O-----------------------------------O
// | INSERT VALUE IN CIRCULARLINK LIST |
// O-----------------------------------O
void CREATE_NODE(int DATA)
{
    struct NODE *NEW_NODE = (struct NODE *)malloc(sizeof(struct NODE));
    NEW_NODE->DATA = DATA;
    TAIL=NEW_NODE;
    if (HEAD == NULL)
    {
        HEAD = NEW_NODE;
        NEW_NODE->NEXT = NEW_NODE->PREV = HEAD;
    }
    else
    {
        struct NODE *TEMP;
        TEMP = HEAD;
        while (TEMP->NEXT != HEAD)
            TEMP = TEMP->NEXT;
        TEMP->NEXT = NEW_NODE;
        NEW_NODE->PREV = TEMP;
        NEW_NODE->NEXT = HEAD;
        HEAD->PREV=TAIL;
    }
}
// O---------------------------O
// | SEARCH VALUE IN LINK LIST |
// O---------------------------O
struct NODE *SEARCH(int DATA)
{
    struct NODE *TEMP = NULL;
    TEMP = HEAD;
    do
    {
        if (TEMP->DATA == DATA)
            return TEMP;
        else
            TEMP = TEMP->NEXT;
    } while (TEMP != HEAD);
    return NULL;
}
// O---------------------O
// | DELETE NODE IN LINK |
// O---------------------O
void DELETE_NODE(int DATA)
{
    struct NODE *TEMP = HEAD;
    struct NODE *PREV_NODE;
    do
    {
        if (TEMP->DATA == DATA)
        {
            if (TEMP == HEAD)
                HEAD = HEAD->NEXT;
            else if (TEMP->NEXT == HEAD)
                TEMP->PREV->NEXT = HEAD;
            else
            {
                TEMP->PREV->NEXT = TEMP->NEXT;
                TEMP->NEXT->PREV = TEMP->PREV;
            }
            free(TEMP);
            break;
        }
        else
            TEMP = TEMP->NEXT;
    } while (TEMP != HEAD);
}
// O-------------------------O
// | INSERT NODE AFTER VALUE |
// O-------------------------O
void INSERT_NODE(int DATA, int DATA_ADD)
{
    struct NODE *NEW_NODE = (struct NODE *)malloc(sizeof(struct NODE));
    NEW_NODE->DATA = DATA_ADD;
    struct NODE *FIND = SEARCH(DATA);
    if (FIND != NULL)
    {
        NEW_NODE->NEXT = FIND->NEXT;
        FIND->NEXT = NEW_NODE;
        NEW_NODE->PREV = FIND;
        }
    else
    {
        printf("REQUIRED NODE NOT FOUND :(");
    }
}
// O----------------O
// | PRINTNG VALUES |
// O----------------O
void PRINT(struct NODE *TEMP)
{
    do
    {
        printf("%d", TEMP->DATA);
        if (TEMP->NEXT!= HEAD)
            printf(" -> ");
        TEMP = TEMP->NEXT;
    } while (TEMP!= HEAD);
    printf("\n");
}
int main()
{
    //  O-------------------------------O
    //  | 12 -> 13 -> 11 -> 5 -> 8 -> 2 |
    //  O-------------------------------O
    CREATE_NODE(12);
    CREATE_NODE(13);
    CREATE_NODE(11);
    CREATE_NODE(5);
    CREATE_NODE(8);
    CREATE_NODE(2);
    // DELETING NODE WITH VALUE 5
    DELETE_NODE(5);
    // INSERT NODE AFTER NODE WITH VALUE 13
    INSERT_NODE(11, 15);
    PRINT(HEAD);
    struct NODE *FIND = SEARCH(2);
    if (FIND == NULL)
        printf("ELEMENT NOT FOUND\n");
    else
        printf("ELEMENT FOUND AT : %X", FIND);
}
