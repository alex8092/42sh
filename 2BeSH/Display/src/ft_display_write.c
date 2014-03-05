#include "ft_display_private.h"
#include "ft_prompt.h"
#include "common.h"
#include <term.h>
#include <unistd.h>
#include <stdlib.h>

t_display		*p_display_putchar(char c)
{
	static t_display	*dis = NULL;

	if (!dis)
		dis = display_singleton();
	write(dis->m_fd, &c, 1);
	return (dis);
}

t_display		*p_display_write_prompt(void)
{
	write(1, prompt_singleton()->to_string(), prompt_singleton()->size());
	return (display_singleton());
}

t_display		*p_display_termcaps_puts(char *cmd)
{
	char		*result;

	result = tgetstr(cmd, NULL);
	if (result)
		write(1, result, ft_strlen(result));
	return (display_singleton());
}
