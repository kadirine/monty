#include "monty.h"


/**
 * mul_nodes - Adds the top two elements of the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @l_num: Integer representing the line number of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, l_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * mod_nodes - Computes the modulo of the top two elements in the stack.
 * @stack: The pointer to a pointer pointing to the top node of the stack.
 * @l_num: Integer showing the line number of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int l_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, l_num, "mod");


	if ((*stack)->n == 0)
		more_err(9, l_num);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
