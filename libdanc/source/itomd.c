/*
 * ________________________________________________________________________________
 * |  File: itomd.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 08:27 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../include/libdanc.h"

static char *set_list[33] = {
    "ZERO","_A", "_B", "_C", "_D", "_E", "_F", "_G", "_H", "_I", "_J",
    "_K", "_L", "_M", "_N", "_O", "_P", "A_", "B_", "C_", "D_", "E_",
    "F_", "G_", "H_", "I_", "J_", "K_", "L_", "M_", "N_", "O_", "P_"
};

char	*itomd(int d)
{
	int		negative_flag = 0;
	double	float_index;
	int		macro;
	char	*pattern_descriptor;
	char	*index;
	char	*out;

	if (d != 0)
	{
		if (d < 0)
		{
			negative_flag = 1;
			d = -d;
		}
		float_index = ceil(d / 32.0);
		macro = (d - 32 * (float_index - 1));
		pattern_descriptor = set_list[macro];
		index = itoa(float_index);
		if (!negative_flag)
			out = strjoin_e(2, pattern_descriptor, index);
		else
			out = strjoin_e(3, "-", pattern_descriptor, index);
		free(index);
		return (out);
	}
	else if (d == 0)
	{
		char *zero;
		zero = strdup("ZERO");
		if (!zero)
			save_to_error_txt("string allocation failed");
		return (zero);
	}
	return (NULL);
}
