#include "ft_display_private.h"
#include "ft_prompt.h"

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
