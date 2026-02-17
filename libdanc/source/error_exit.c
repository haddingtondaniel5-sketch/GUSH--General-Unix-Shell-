/*
 * ________________________________________________________________________________
 * |  File: error_exit.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:43 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

void	error_exit(char *mess, int error_type, t_program *strct, p_cleanup_function cleanup)
{
	printf("\e[1;31mError; Explicit: %s\n", mess);
	cleanup(strct);
	printf("Program has exited with an error code <%d>\e[0;32m\n", error_type);
	exit(error_type);
}

void	ERROR_MEM(t_program *o, char *mess)
{
	save_to_error_txt(mess);
	error_exit(mess, MEMORY_ALLOCATION_ERROR, o, cleanup);
}

void	ERROR_MEM_index(t_program *o, char *mess, int v1, int v2, int v3)
{
	FILE *err = fopen("error.txt", "a");
	fprintf(err, "%s v1:%d v2:%d v3:%d\n", mess, v1, v2, v3);
	fprintf(stderr, "%s v1:%d v2:%d v3:%d\n", mess, v1, v2, v3);
	fclose(err);
	error_exit(mess, MEMORY_ALLOCATION_ERROR, o, cleanup);
}