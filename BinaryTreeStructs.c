//  Lab 9
//  Michael Hinds
//  4/5/17

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Binary tree with structs and memory allocation

typedef struct Node
{	
	int num;
	int count;
	struct Node* left;
	struct Node* right;
	
}node;

node* add_to_tree(node* head, int number);
int print_totals(node* head, int count);
void free_tree(node* head);

int main(int argc, char** argv)
{
	
	if(argc != 3)                                                            // Error check correct amount of arguments
    {
		printf("Correct usage: ./a.out <input file> <max number>\n");
		return 0;	
	}	

	int userChoice, newNum, i;
	int size = atoi(argv[2]);                                                // Turn command line argument into an integer
	node* head = NULL;

	FILE* fp = fopen(argv[1], "r");                                          // Open a file to read

	for(i=0; i<size; i++)                                                    // Scan file and add numbers to a binary tree
    {
		fscanf(fp, "%d", &newNum);
		head = add_to_tree(head, newNum);	
	}

	while(1)
    {
		
		printf("Enter '1' to add a number to the tree\n");
		printf("Enter '2' to print the totals for each number\n");
		printf("Enter '-1' to terminate the program\n");
		printf("Enter your choice: ");
		scanf("%d", &userChoice);
		
		if(userChoice == 1)                                                   // Add new numbers to the binary tree
        {
			printf("Enter the number you want to add: ");
			scanf("%d", &newNum);
			head = add_to_tree(head, newNum);	
		}	

		if(userChoice == 2)                                                   // Print the total time each number occurs
        {
			int sum = print_totals(head, 0);
			printf("total = %d\n", sum);	
		}
		
		if(userChoice == -1)                                                  // Exit the program and free allocated memory
        {
            fclose(fp);
			free_tree(head);
			return 0;	
		}					
	}	
}

node* add_to_tree(node* head, int number){

	if(head == NULL)
    {
		node* temp = malloc(sizeof(node));
		temp->num = number;
		temp->count = 1;
		temp->left = NULL;
		temp->right = NULL;
		return temp;	
	}	

	if(number < head->num)
		head->left = add_to_tree(head->left, number);

	if(number > head->num)
		head->right = add_to_tree(head->right, number);
	
	if(number == head->num)
		head->count++;
	
	return head;
}

int print_totals(node* head, int count){
	
	if(head != NULL)
    {
		count = print_totals(head->left, count);
		printf("There are %d occurances of the number %d\n", head->count, head->num);
		count = print_totals(head->right, count) + head->count;
	}
	return count;
}

void free_tree(node* head)
{
	if(head == NULL)
		return;

	free_tree(head->left);
	free_tree(head->right);
	free(head);
}
