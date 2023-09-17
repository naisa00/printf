#include "main.c"

/**
 * init_params - clears struct field and reset buf
 * @params: the parameters struct
 * @ap: the argument pointer
 *
 * Return: void
 */
void init-params(params_t *params, va_list ap)
{
	 params->unsign = 0;

	 params->plus_flag = 0;
	 params->space_flag = 0;
	 params->hashtag_flag = 0;
	 params->zero-flag = 0;
	 params->minus_flag = 0;


	 params->width = 0;
	 params->percision = UNIT_MAX;

	 params->h_modifier = 0;
	 params->l_modifier = 0;
	 (void)ap;
}

