#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include "linkedList.h"



typedef struct listElementStruct
{
  
	char* data;
  
	size_t size;
  
	struct listElementStruct* next;

} 
listElement;



//Creates a new linked list element with given content of size

//Returns a pointer to the element

listElement* createEl(char* data, size_t size)
{
  
	listElement* e = malloc(sizeof(listElement));

  	if(e == NULL)
	{
    
		//malloc has had an error
    
		return NULL; 
		//return NULL to indicate an error.
  
	}
  
	char* dataPointer = malloc(sizeof(char)*size);
  
	if(dataPointer == NULL)
	{
    
		//malloc has had an error
    
		free(e); 
		//release the previously allocated memory
    
		return NULL; 
		//return NULL to indicate an error.
  
	}
  
	strcpy(dataPointer, data);
	
	e->data = dataPointer;
  
	e->size = size;
  
	e->next = NULL;
  
	return e;

}


void push(listElement** head_ref, char* new_data, size_t size)
{
	listElement* new_node = malloc(size);

	new_node->data = new_data;

	new_node->next = *head_ref;

	*head_ref = new_node;
}


//Prints out each element in the list

void traverse(listElement* start)
{
  
	listElement* current = start;
  
	while(current != NULL)
	{
    
		printf("%s\n", current->data);
    
		current = current->next;
  
	}

}


//Inserts a new element after the given el

//Returns the pointer to the new element

listElement* insertAfter(listElement* el, char* data, size_t size)
{

	listElement* newEl = createEl(data, size);
  
	listElement* next = el->next;
  
	newEl->next = next;
  
	el->next = newEl;
  
	return newEl;

}



//Delete the element after the given el

void deleteAfter(listElement* after)
{
  
	listElement* delete = after->next;
  
	listElement* newNext = delete->next;
  
	after->next = newNext;
  
	//need to free the memory because we used malloc
	free(delete->data);
  
	free(delete);

}

int length(struct listElement* head) 
{ 
    int count = 0;
    listElement* current = head; 
	
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 

listElement *pop(listElement **head) {
    listElement *temp = *head;
    if (temp) {
        *head = temp->next;
    }
    return temp;
}

listElement *enqueue(listElement *queue, char* data, size_t size){

    listElement *enqueued = createEl(data, size);
    enqueued-> next = queue;
	queue = enqueued;

}

listElement *dequeue(listElement *list) {
    listElement *temp = list;
    
    while((temp-> next)-> next != NULL) {
        temp = temp-> next;
    }
    
    listElement *tail = temp-> next;
    temp-> next = NULL;
    
    return tail;
}