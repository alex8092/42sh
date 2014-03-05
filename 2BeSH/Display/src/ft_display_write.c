#include "ft_display_private.h"
#include "ft_prompt.h"
#include "common.h"
#include <term.h>
#include <unistd.h>
#include <stdlib.h>

t_display		*p_display_putchar(char c)
{
	static t_display	*display = NULL;

	if (!display)
		display = display_singleton();
	write(display->m_fd, &c, 1);
	return (display);
}

t_display		*p_display_putstr(char *str)
{
	static t_display	*display = NULL;

	if (!display)
		display = display_singleton();
	write(display->m_fd, str, ft_strlen(str));
	return (display);
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
