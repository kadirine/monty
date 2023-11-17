#include "monty.h"


/**
 * add_to_stack - Pushes a node into the stack.
 * @recent_node: The pointer to the new node.
 * @l_num: Integer showing the line number of the opcode.
 */
void add_to_stack(stack_t **recent_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *temp;
	stack_t *head = NULL;

	if (recent_node == NULL || *recent_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *recent_node;
		return;
	}
	temp = head;
	head = *recent_node;
	head->next = temp;
	temp->prev = head;
}



/**
 * add_to_queue - Adds a node to the queue.
 * @recent_node: The pointer to the new node.
 * @l_num: Integer showing the line number of the opcode.
 */
void add_to_queue(stack_t **recent_node, __attribute__((unused))unsigned int l_num)
{
	stack_t *temp;
	stack_t *head = NULL;

	if (recent_node == NULL || *recent_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *recent_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *recent_node;
	(*recent_node)->prev = temp;

}

/**
 * print_stack - Displays the contents of a stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 */
void print_stack(stack_t **stack, unsigned int l_num)
{
	stack_t *temp;
	
	(void) l_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

