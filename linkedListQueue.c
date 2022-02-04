#include <stdio.h>
#include <stdlib.h>

// --- header ---
struct Node {
	int data;
	struct Node *next;
};

/*
struct List {
	struct Node *head;
};
*/
//typedef struct List List;

struct Node * insert(struct Node *start);
struct Node * deleteElement(struct Node *start);
struct Node *  deleteQueue(struct Node *start);
void display(struct Node *start);

// --- lib ---

struct Node * createNode(int info, struct Node *p) {
	struct Node *temp = NULL;

	//temp = (struct Node*) malloc(sizeof(struct Node));

	temp = (struct Node*) malloc(sizeof(*temp)); // Good-programming-practice

	if (NULL == temp) // if(temp == NULL) // if (degree = 80)
	{
		printf(" Low mem...(clean-up..wait..exit)\n");
	}
	temp->data = info;
	temp->next = p;

	return temp;
}

struct Node * insert(struct Node *start) {
	int val = -1;
	struct Node *temp = NULL;

	printf("Enter the data to be inserted: ");
	scanf("%d", &val);
	printf("\n");
	temp = createNode(val, start);
	return temp;
}

struct Node * deleteElement(struct Node *start) {
	if (start) {
		struct Node * temp = start;
		if (start && !start->next) {
			printf(" Node deleted with data: %d\n", start->data);
			free(start);
			start = NULL;
		}
		if (start->next) {
			struct Node * s = start;
			for (temp = start->next; temp->next; temp = temp->next)
				start = start->next;

			printf(" Node deleted with data: %d\n", temp->data);
			free(temp);
			start->next	= NULL;
			start = s;
		}
		else {
			printf(" Node deleted with data: %d\n", start->data);
			free(start);
			start = NULL;
		}		
	}
	else
		printf("Queue is empty.. cannot delete an element\n");
	return start;
}

struct Node *  deleteQueue(struct Node *start) {
	if (start) {
		struct Node * trav = start;

		for (; trav;) {
			start = trav;
			printf(" Node deleted with data: %d\n", start->data);
			trav = trav->next;
			free(start);
		}

		start = NULL;
	}
	else
		printf("Queue is empty.. cannot delete Q\n");
	return start;
}

void recursive(struct Node *p) {
	if (p) {
		recursive(p->next);
		printf(" %d, ", p->data);
	}	
}

void display(struct Node *start) {

	if (start) {
		recursive(start);
		printf("\n");
	}
	else
		printf("Queue is empty.. cannot display\n");
}


// --- app ---
int main() {
	//struct List myQueue;
	//myQueue.head = NULL;
	struct Node *head = NULL;
	int choice = -1;

	while (1) {
		printf("1. Insert into queue\n");
		printf("2. Delete an element in the queue\n");
		printf("3. Delete entire queue\n");
		printf("4. Display the queue \n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("\n");
		switch (choice) {
		case 1:
			//insert(myQueue);
			head = insert(head);
			break;
		case 2:
			//deleteElement(myQueue);
			head = deleteElement(head);
			break;
		case 3:
			//deleteQueue(myQueue);
			head = deleteQueue(head);
			break;
		case 4:
			display(head);
			break;
		case 5:
		default:
			printf(" .. Program exiting ...\n");
			deleteQueue(head);

			exit(0);
		}
	}
}





