#ifndef _LINKEDLIST_DS_H
#define _LINKEDLIST_DS_H
#include <stdio.h>
#include <stdlib.h>
#include "Platform_Types.h"

typedef struct node
{
  uint32 data;
  struct node *node_link;
};

typedef enum
{
    LIST_OK=0,
    LIST_NOK,
    LIST_EMPTY
}LIST_status_t;

/**
  * @brief  insert a node at the beginning of the list
  * @param  my_list   : double pointer points to the location of the address of the list head
  * @retval status   : the status of the process
*/
LIST_status_t insert_node_at_beginning(struct node **my_list);

/**
  * @brief  insert a node at the end of the list
  * @param  my_list  : double pointer points to the location of the address of the list head
  * @retval status   : the status of the process
*/
LIST_status_t insert_node_at_end(struct node **my_list);

/**
  * @brief  insert a node after a certain position in the list
  * @param  my_list  : pointer points to the list head
  * @retval status   : the status of the process
*/

LIST_status_t insert_node_after(struct node *my_list);

/**
  * @brief  delete a node from the beginning of the list
  * @param  my_list  : double pointer points to the location of the address of the list head
  * @retval status   : the status of the process
*/
LIST_status_t delete_node_at_beginning(struct node **my_list);

/**
  * @brief  delete a node with a certain position at the list (not the beginning)
  * @param  my_list  : double pointer points to the location of the address of the list head
  * @retval status   : the status of the process
*/
LIST_status_t delete_node(struct node *my_list);

/**
  * @brief  display all nodes in the list
  * @param  my_list  : pointer points to the list head
  * @retval status   : the status of the process
*/
LIST_status_t display_all_nodes(struct node *my_list);

/**
  * @brief  gets the length (number of nodes) in the list
  * @param  my_list  : pointer points to the list head
  * @param  length   : pointer points to address of the length variable
  * @retval status   : the status of the process
*/
LIST_status_t get_length(struct node *my_list, uint32 *length);

/**
  * @brief  apply selection sort on the list
  * @param  my_list  : pointer points to the address of the list head
  * @retval status   : the status of the process
*/
LIST_status_t s_sort(struct node**my_list);

/**
  * @brief  apply bubble sort on the list
  * @param  my_list  : pointer points to the address of the list head
  * @retval status   : the status of the process
*/
LIST_status_t b_sort(struct node **my_list);



/**
  * @brief  converts the list into array
  * @param  my_list  : pointer points to the address of the list head
  * @retval my_array : the address of the array allocated in dynamic memory
*/
uint32* list2arr (struct node *my_list);
void display_array (uint32 *arr);
/**
  * @brief  applies bubble search to the array of the list
  * @param  arr      : pointer points to the address of the array created
  * @retval ret      : the index of the element in the array
*/
signed int my_search(uint32 *arr );
LIST_status_t sort_list(struct node **my_list);
void sorted_insert(struct node *new_node);



#endif // _LINKEDLIST_DS_H
