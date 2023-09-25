#include <stdio.h>
#include <stdlib.h>
#include "linkedlist_ds.h"

struct node *list_head = NULL;

int main()
{
    uint32 length =0;
    uint8 choice = 0;
    uint32 *arr =NULL;
    LIST_status_t status=LIST_NOK;
    sint32 ret=0;

    printf("---->  Hello to my single linked list :}  <----\n");
    while(1)
    {
        printf("\n");
        printf("========================================\n");
        printf("-> 1) insert_node_at_beginning \n");
        printf("-> 2) insert_node_at_end \n");
        printf("-> 3) insert_node_after \n");
        printf("-> 4) delete_node_at_beginning \n");
        printf("-> 5) delete_node \n");
        printf("-> 6) display_all_nodes \n");
        printf("-> 7) get_length \n");
        printf("-> 8) sort the data in the list (ascending) \n");
        printf("-> 9) store the list into array \n");
        printf("-> 10) search for item in the list (NOTE :: the list must be sorted and stored in array first (8,9)) \n");
        printf("-> 11) Quit from the app \n");
        printf("========================================\n");
        printf("\n");
        printf("User choice : ");
        scanf("%i",&choice);
        switch (choice)
        {
            case 1:
                status = insert_node_at_beginning(&list_head);
                break;
            case 2:
                status = insert_node_at_end(&list_head);
                break;
            case 3:
                status = insert_node_after(list_head);
                break;
            case 4:
                status = delete_node_at_beginning(&list_head);
                break;
            case 5:
                status = delete_node(list_head);
                break;
            case 6:
                status = display_all_nodes(list_head);
                break;
            case 7:
                status = get_length(list_head,&length);
                break;
            case 8:
                status = s_sort(&list_head);
                break;
            case 9:
                arr=list2arr(list_head);
                printf("the address of array : 0x%X \n",arr);
                display_array(arr);
                break;
            case 10:
                ret= my_search(arr);
                if(-1 == ret)
                {
                    printf("the item you search for is not in the list\n");
                }
                printf("your item is at ---> %i <--- position in the array\n",ret);
                break;
            case 11:
                printf("Quit from the app \n");
                exit(1);
                break;
            default:
                printf("INVALID user choice !! \n");
                break;

        }

    }


    return 0;
}
