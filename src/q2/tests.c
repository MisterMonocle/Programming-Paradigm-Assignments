#include <stdio.h>
#include "tests.h"
#include "linkedList.h"

void runTests(){
	printf("Tests running...\n");
	
	listElement *l = createEl("String (a)", 30);
    traverse(l);
	length(l); //a
	push(&l, "String (c)", 30);
    insertAfter(l, "String (b)", 30);
    push(&l, "String (d)", 30);
    traverse(l);
	length(l); //dcba
	pop(&l);
    traverse(l);
	length(l); //cba
	pop(&l);
	pop(&l);
	pop(&l);
	
	enqueue(&l, "String (e)", 30);
    insertAfter(l, "String (f)", 30);
    enqueue(&l, "String (g)", 30);
    traverse(l);
    length(l); 
    dequeue(l);
    traverse(l);
	length(l);
	deleteAfter(l);
    traverse(l);
	length(l);

	printf("\nTests complete.\n");
}
