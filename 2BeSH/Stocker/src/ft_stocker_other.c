#include "ft_stocker_private.h"
#include <stdlib.h>

#include <stdio.h>

int				p_stocker_size(void)
{
	return (stocker_singleton()->m_length);
}

char			*p_stocker_to_string(void)
{
	t_stocker		*stocker;
	t_lst_stocker	*cursor;
	char			*str;
	int				i;

	i = 0;
	stocker = stocker_singleton();
	str = (char*)malloc(sizeof(char) * (stocker->m_length + 1));
	cursor = stocker->m_start;
	while (cursor)
	{
		printf(" %c | ", cursor->c);
		str[i] = cursor->c;
		cursor = cursor->next;
		i++;
	}
	printf("Pos : %d | Parcours : %d | Length : %d\n", stocker->m_pos, i, stocker->m_length);
	return (str);
}
