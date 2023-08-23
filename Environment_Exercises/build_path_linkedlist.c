#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct ListNode - Structure for a linked list node
 *
 * @directory: pointer to function
 * @next: pointer to buffer function
 */
struct ListNode
{
	char *directory;
	struct ListNode *next;
};

/**
 * buildPathLinkedList() - Function to build a linked list
 * of PATH directories
 *
 * Return: 1
 */
struct ListNode *buildPathLinkedList()
{
	struct ListNode *head = NULL;
	char *path = getenv("PATH");

	if (path == NULL)
	{
		printf("PATH environment variable not found.\n");
		return NULL;
	}

	char *token = strtok(path, ":");

	while (token != NULL)
	{
	/* Create a new node */
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

	if (newNode == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	/* Copy the directory path into the node */
	newNode->directory = strdup(token);
	newNode->next = NULL;

        /* Add the node to the linked list */

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		struct ListNode *current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}

	token = strtok(NULL, ":");
	}

	return head;
}

/** 
 * freeLinkedList - Function to free the linked list
 *
 * @ListNode: typedef
 * @head: temporary buffer
 */
void freeLinkedList(struct ListNode *head)
{
	while (head != NULL)
	{
		struct ListNode *temp = head;

		head = head->next;
		free(temp->directory);
		free(temp);
	}
}

/**
 * main - return linked list of the PATH directories
 *
 * Return: Always 0
 */
int main()
{
	printf("Building linked list of PATH directories...\n");

	/* Build the linked list */
	struct ListNode *head = buildPathLinkedList();

	/* Print the linked list */
	struct ListNode *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}

	/* Free the linked list */
	freeLinkedList(head);

	return 0;
}

