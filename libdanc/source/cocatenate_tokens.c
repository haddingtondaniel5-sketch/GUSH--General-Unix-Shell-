/*
 * ________________________________________________________________________________
 * |  File: cocatenate_tokens.c
 * |  Project: source
 * |  File Created: Saturday, 11th January 2025 10:24 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

# include "../include/libdanc.h"

char *concatenate_tokens(char **tokens)
{
	char *out;
	int total_length = 0;
	int token_count = count_tokens(tokens);
	int i;

	i = 0;
	while (tokens[i])
	{
		total_length += (strlen(tokens[i]) + 1);
		i += 1;
	}
	out = malloc(sizeof(char) * total_length);
	out[0] = '\0';
	i = 0;
	while (tokens[i])
	{
		strcat(out, tokens[i]);
		if (i < token_count - 1)
			strcat(out, " ");
		i++;
	}
	return out;
}