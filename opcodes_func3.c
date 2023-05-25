#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_cnt)
{
	char *n = glbal.arg;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	if (glbal.data == 1)
	{
		if (!add_node(stack, atoi(glbal.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!queue_node(stack, atoi(glbal.arg)))
		{
			exit(EXIT_FAILURE);
		}
	}
}


/**
* rotl - rotates the first element of the stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotl(stack_t **stack, unsigned int line_count)
{
	stack_t *left;
	stack_t *right;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next) /* move the right pointer to the last node */
		right = right->next;
	right->next = left; /* a circle infinite linked list loop */
	left->prev = right;
	*stack = left->next; /* so we cut the link between the 0 and 1 element */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
* rotr - rotates the last node of a stack_t stack
* @stack: stack head
* @line_count: line count
*
* Return: void
*/
void rotr(stack_t **stack, unsigned int line_count)
{
	stack_t *bottom;
	stack_t *prev;

	(void) line_count;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}


/**
 * _sub -  substracts the first two nodes of the stack
 * @stack: stack given by main
 * @line_cnt: line counter
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int line_cnt)
{
	int result;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}

	result = ((*stack)->next->n) - ((*stack)->n);
	pop(stack, line_cnt);/*For top node*/
	(*stack)->n = result;
}


/**
 * swap -  swaps data from top to previous
 * @stack: stack given by main
 * @line_cnt: amount of lines
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_cnt)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;

	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}
