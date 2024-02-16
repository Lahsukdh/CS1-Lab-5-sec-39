#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* temp = head;
	int counter = 0;
	while(temp != NULL){
		temp = temp->next;
		counter++;
	}
	return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* temp = head;
	int len = length(head);
	char* toString = (char*)malloc((len+1)*sizeof(char));
	for(int i = 0; i < len; i++){
		toString[i] = temp->letter;
		temp = temp->next;
	}
	toString[len] = '\0';
	return toString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* new = (node*)malloc(sizeof(node));
	node* temp = *pHead;
	new->letter = c;
	new->next = NULL;
	
	if(*pHead == NULL){
		*pHead = new;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new;
	}
	
	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* new = *pHead;
	node* temp;
	while(new != NULL){
		temp = new->next;
		free(new);
		new = temp;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}