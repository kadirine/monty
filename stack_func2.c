#include "monty.h"


/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *temp;
	stack_t *head = NULL;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * swap_nodes - Swaps the top two elements of the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @l_num: Integer showing the line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int l_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}


/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @l_num: Integer showing the line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_num, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nop - Performs no operation.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @l_num: Integer showing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int l_num)
{
	(void)stack;
	(void)l_num;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @l_num: Integer showing the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, l_num, "sub");


	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
