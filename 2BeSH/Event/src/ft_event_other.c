#include "ft_event_private.h"
#include "ft_stocker.h"
#include "ft_display.h"
#include "common.h"

t_event		*p_event_read(char *c)
{
	t_event_item	*cur;
	int				comp;

	if (ft_isprint(c[0]) || c[0] == '\n')
	{
		while (c[0])
		{
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
	else
	{
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
	return (event_singleton());
}