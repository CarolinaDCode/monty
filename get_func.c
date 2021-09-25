#include "monty.h"
/**
 * get_func_opcode - a pointer to the function given the opcode
 * @s: opcode passed to the program
 * Return: a pointer to the function given the opcode
 */
void (*get_func_opcode(vars_opc prop))(stack_t **stack, unsigned int ln)
{
	int i = 0;

	instruction_t _opcode[] = {
		{"pall", _op_pall},
		{"push", _op_push},
		{"pint", _op_pint},
		{"pop", _op_pop},
		{"swap", _op_swap},
		{"add", _op_add},
		{"nop", _op_nop},
		{"sub", _op_sub},
		{"div", _op_div},
		{"mul", _op_mul},
		{"mod", _op_mod},
		{"pchar", _op_pchar},
		{"pstr", _op_pstr},
		{"rotl", _op_rotl},
		{"rotr", _op_rotr},
		{NULL, NULL}
	};

	if (prop.list_items[0][0] == '#')
	{
		return (_op_nop);
	}
	while (_opcode[i].opcode != NULL)
	{
		if (strcmp(prop.line, _opcode[i].opcode) == 0)
		{
			return (*(_opcode[i]).f);
		}
		i++;
	}
	/*free()*/
	return (0);
}
