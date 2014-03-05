#include "ft_event_private.h"
#include "ft_stocker.h"
#include "ft_display.h"
#include "common.h"

static void		p_event_read_for_print(char *c)
{
	while (c[0])
	{
		display_singleton()->puts("im");
		display_singleton()->putchar(c[0]);
		if (c[0] != '\n')
			stocker_singleton()->push((char)c[0]);
		else
			break ;
		c[0] = c[1];
		c[1] = c[2];
		c[2] = c[3];
		c[3] = 0;
	}
}

static void 	p_event_read_for_key(char *c)
{
	t_event_item	*cur;
	int				comp;

	cur = event_singleton()->m_begin;
	while (cur)
	{
		comp = (c[0] << 24) | (c[1] << 16) | (c[2] << 8) | c[3];
		if (comp == cur->key)
		{
			cur->function();
			break ;
		}
		cur = cur->next;
	}
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
}

t_event			*p_event_read(char *c)
{
	if (ft_isprint(c[0]) || c[0] == '\n')
		p_event_read_for_print(c);
	else
		p_event_read_for_key(c);
	return (event_singleton());
}
