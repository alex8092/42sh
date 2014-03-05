#include "ft_event_private.h"
#include "ft_stocker.h"
#include "ft_security.h"
#include "common.h"
#include <unistd.h>

t_event_item	*p_event_add_item(t_event_item *p, int key, void (*f)(void))
{
	t_event_item	*item;

	item = (t_event_item *)ft_memalloc(sizeof(t_event_item));
	if (!item)
		security_singleton()->critical("malloc");
	item->key = key;
	item->function = f;
	if (p != NULL)
		p->next = item;
	return (item);
}
