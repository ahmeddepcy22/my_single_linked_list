#include "linkedlist_ds.h"

struct node *sorted = NULL;

LIST_status_t insert_node_at_beginning(struct node **my_list)
{
    LIST_status_t status = LIST_NOK;
    struct node *temp_node = NULL;

    temp_node = (struct node *)malloc(sizeof(struct node));                     /* creates the node */
    if(temp_node == NULL)
    {
        printf("ERROR !! ,,, failed to create the node \n");
        status = LIST_NOK;
    }
    else
    {
        printf("please enter the node data : \n");
        scanf("%i",&temp_node->data);
    }
    if(*my_list == NULL)                                                         /* check if the list is empty "list head = null" */
    {
        *my_list = temp_node;
        temp_node->node_link = NULL;
    }
    else                                                                          /* the list is not empty */
    {
        temp_node->node_link = *my_list ;
        *my_list=temp_node;
        status=LIST_OK;
        printf(" The data (%i) added to the list at beginning successfully :) \n",temp_node->data);
    }

    return  status;
}
LIST_status_t insert_node_at_end(struct node **my_list)
{
    LIST_status_t status =LIST_NOK;
    struct node *temp_node =NULL;
    struct node *last_node =NULL;

    temp_node = (struct node *)malloc(sizeof(struct node));
    if(temp_node == NULL)
    {
        printf("ERROR !! ,,, failed to create the node \n");
        status = LIST_NOK;
    }
    else
    {
        printf("please enter the node data : \n");
        scanf("%i",&temp_node->data);
        temp_node->node_link = NULL;
    }
    if(NULL == *my_list)                                      /* check if the list is empty */
    {
        *my_list = temp_node;
    }
    else                                                      /* the list is not empty  */
    {
        last_node=*my_list;
        while(NULL != last_node->node_link)                   /* traversal in the list to get the last node */
        {
            last_node = last_node->node_link;
        }
        last_node->node_link=temp_node;
        status = LIST_OK;
        printf(" The data (%i) added to the list at end successfully :) \n",temp_node->data);
    }

    return status;
}
LIST_status_t insert_node_after(struct node *my_list)
{
    LIST_status_t status = LIST_NOK , status1=LIST_NOK;
    struct node *temp_node = NULL;
    struct node *node_counter=NULL;
    uint32 node_pos = 0,counter = 1;
    uint32 length = 0;

    printf("please enter the node position (first node position =1) : \n");
    scanf("%i",&node_pos);
    status1 = get_length(my_list , &length);
    if(node_pos > length)                                 /* check the position user entered is not valid */
    {
        printf("ERROR !! ,, INVALID position ,, The list has (%i) nodes \n",length);
    }
    else
    {
        node_counter = my_list;
        while(counter < node_pos)                               /* traversing in the list to get the desired position */
        {
            counter++;
            node_counter= node_counter->node_link;
        }
        temp_node = (struct node *)malloc(sizeof(struct node));
        if(temp_node == NULL)
        {
            printf("ERROR !! ,,, failed to create the node \n");
            status = LIST_NOK;
        }
        else
        {
            printf("please enter the node data : \n");
            scanf("%i",&temp_node->data);
            temp_node->node_link=node_counter->node_link;
            node_counter->node_link=temp_node;
            status = LIST_OK;
            printf(" The data (%i) added to the list after position (%i) successfully :) \n",temp_node->data,node_pos);
        }
    }

    return status;
}
LIST_status_t delete_node_at_beginning(struct node **my_list)
{
    LIST_status_t status = LIST_NOK, status1=LIST_NOK;
    struct node *temp_node = *my_list;
    uint32 length = 0;
    status1 = get_length(my_list , &length);
    if(0 == length)                                   /* check if the list is empty */
    {
        printf("ERROR !! ,,, nothing to be deleted the list is empty \n");
        status = LIST_EMPTY ;
    }
    else
    {
        *my_list=temp_node->node_link;
        temp_node->node_link=NULL;
        free(temp_node);
        printf("The 1st node of the list has been deleted successfully \n");
        status = LIST_OK;
    }
    return status;
}
LIST_status_t delete_node(struct node *my_list)
{
    LIST_status_t status = LIST_NOK , status1=LIST_NOK;
    uint32 length =0;
    struct node *node_counter= my_list;
    struct node *next_node = my_list;
    uint32 counter=1 , node_pos=0;

    printf("please enter the node position to be deleted (1st node position =1) : \n");
    scanf("%i",&node_pos);
    status1 = get_length(my_list , &length);
    if(node_pos > length  ||  length==1 )                                 /* check the position user entered is not valid */
    {
        printf("ERROR !! ,, INVALID position ,, The list has (%i) nodes \n",length);
    }
    else
    {
        while(counter < (node_pos-1))
        {
            counter++;
            node_counter=node_counter->node_link;
        }
        next_node=node_counter->node_link;
        node_counter->node_link=next_node->node_link;
        free(next_node);
        status=LIST_OK;
        printf("The node of (%i) position has been deleted successfully :} \n",node_pos);
    }
    return status;
}
LIST_status_t display_all_nodes(struct node *my_list)
{
    LIST_status_t status = LIST_NOK;
    struct node *temp_node = my_list;
    printf("The nodes in the list : \n");
    if(temp_node==NULL)                                     /* check if the list is empty */
    {
        printf("The list is empty \n");
        status = LIST_EMPTY;
    }
    else
    {
        while(temp_node != NULL)                 /* traversing in the list to print node data */
        {
            printf("(%i) -> \t",temp_node->data);
            temp_node=temp_node->node_link;
        }
        if(temp_node == NULL)
        {
            printf("END OF LIST \n");
        }
        status=LIST_OK;
    }
    return status;
}
LIST_status_t get_length(struct node *my_list, uint32 *length)
{
    LIST_status_t status = LIST_NOK;
    struct node *temp_node = my_list;
    uint32 node_count =0;
    if(temp_node==NULL)                                     /* check if the list is empty */
    {
        printf("The list is empty \n");
        status = LIST_EMPTY;
    }
    else
    {
        while(temp_node != NULL)                       /* traversing in the list */
        {
            node_count++;
            temp_node=temp_node->node_link;
        }
        *length=node_count;
        printf("List length = << %i >> nodes \n",*length);
    }
    return status;
}

void sorted_insert(struct node *new_node)
{
    if((NULL == sorted) || (sorted->data >=new_node->data))  /* special case for the list head and end */
    {
        new_node->node_link = sorted;
        sorted = new_node;
    }
    else
    {
        struct node *current = sorted;
        while((current->node_link != NULL) && (current->node_link->data < new_node->data))  /* traversing in the list and compare to find the right place */
        {
            current = current->node_link;
        }
        new_node->node_link = current->node_link;
        current->node_link = new_node;
    }
}

LIST_status_t sort_list(struct node **my_list)
{
    LIST_status_t status = LIST_NOK;
    struct node *current = *my_list;

    while(current != NULL)
    {
        struct node *next = current->node_link;              /* traverse in the list */
        sorted_insert(current);                              /* sorted insert current node */
        current = next;
    }
    my_list = sorted;                                 /* returns the head of the sorted list through parameter */
    status = LIST_OK;
    return status;
}
/* applying selection sort to my single linked list */
LIST_status_t s_sort(struct node**my_list)
{
    LIST_status_t status = LIST_NOK;
    struct node *i=*my_list;                             /* i is for main iteration */
    struct node *j=NULL;                                 /* j is for comparing with each node */
    uint32 temp = 0;                                     /* temp to store the data for swapping */
    for(i=*my_list ; i->node_link != NULL ; i=i->node_link)
    {
        for(j=i->node_link ; j!=NULL ; j=j->node_link)
        {
            temp=i->data;
            i->data=j->data;
            j->data=temp;
        }
    }
    printf("The data has been sorted successfully \n");
    status= LIST_OK;
    return status;
}

static uint32 get_length_2(struct node *my_list)
{
    struct node *temp_node = my_list;
    uint32 node_count =0;
    if(temp_node==NULL)                                     /* check if the list is empty */
    {
        printf("The list is empty \n");
    }
    else
    {
        while(temp_node != NULL)                       /* traversing in the list */
        {
            node_count++;
            temp_node=temp_node->node_link;
        }
        printf("List length = << %i >> nodes \n",node_count);
    }
    return node_count;
}
/* function to swap nodes */
static struct node* swap(struct node *ptr1 , struct node *ptr2)
{
    struct node *temp = ptr2->node_link;
    ptr2->node_link=ptr1;
    ptr1->node_link=ptr2;                 /* now ptr2 points to ptr1 and ptr1 points to the node which ptr2 was pointing to before swapping */
    return ptr2;
}
/* applying bubble sort to my single linked list */
LIST_status_t b_sort(struct node **my_list)
{
    LIST_status_t status = LIST_NOK,status1=LIST_NOK;
    struct node **head = my_list;
    uint32 i=0,j=0,length=0;
    uint32 flag=0;
    printf("please enter the length of the list:");
    scanf("%i",&length);
    for(i=0 ; i<(length-1) ; i++)
    {
        head=my_list;
        flag=0;
        for(j=0 ; j<(length-1-i) ; j++)
        {
            struct node *p1=*head;
            struct node *p2=p1->node_link;
            if(p1->data >p2->data)
            {
                *head=swap(p1,p2);
                flag=1;
            }
            head=&(*head)->node_link;
        }
        if(0 == flag)
        {
            printf("the data is already sorted\n");
            return status;
        }
    }


    printf("the data has been sorted successfully \n");
    status = LIST_OK;
    return status;
}

/* function to insert the data in linked list to an array */
uint32* list2arr (struct node *my_list)
{
    struct node *temp_node = my_list;
    uint32 index=0,length=0;
    uint32 *my_array=NULL;
    printf("please enter the length of the list :");
    scanf("%i",&length);
    my_array= (uint32 *)malloc(sizeof(uint32)*length);
    for(index=0 ; index<length ; index++)
    {
        my_array[index]=temp_node->data;
        temp_node=temp_node->node_link;
    }
    printf("the array has been created successfully\n");
    return my_array;
}
/* function to display the array */
void display_array (uint32 *arr)
{
    uint32 index =0,length=0;
    printf("please enter the length of the list to display :");
    scanf("%i",&length);
    for(index =0 ; index < (length) ; index++)
    {
        printf("%i\t",arr[index]);
    }
    printf("\n");
}
/* function to search for item in array */
signed int my_search(uint32 *arr)
{
    uint32 elem_index=0;
    uint32 s_index=0,e_index=0,element=0;
    printf("please enter start index:");
    scanf("%i",&s_index);
    printf("\n");
    printf("please enter end index:");
    scanf("%i",&e_index);
    printf("\n");
    printf("please enter element you want to search for :");
    scanf("%i",&element);
    printf("\n");
    while(s_index <= e_index)              /* check the array is not empty */
    {
        elem_index= s_index + (e_index-s_index)/2;
        if(element == arr[elem_index])
        {
            return elem_index;
        }
        else if(element > arr[elem_index])
        {
            s_index = elem_index +1;
        }
        else
        {
            e_index = elem_index -1;
        }
    }
    return -1;
}
/* applying insertion sort to my single linked list */
// LIST_status_t i_sort(struct node **my_list)
// {
//     LIST_status_t status= LIST_NOK;
//     struct node *iteration = *my_list->node_link;
//     struct node *compare_index = NULL;
//     uint32 node_data = 0,temp=0;
//     for(iteration=my_list->node_link ; iteration!=NULL ; iteration=iteration->node_link)
 //    {
   //      node_data=iteration->data;
//         compare_index=my_list;
//         while(element < compare_index->data)
//         {
//             /* cannot decrement (traverse backward in single linked list) ,, so the idea of my implementation failed :{{ */
//         }
//     }
//
 //    return status;
 // }








