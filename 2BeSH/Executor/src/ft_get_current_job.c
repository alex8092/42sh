#include "ft_executor.h"

pid_t	p_exec_get_current_job(void)
{
	return (exec_singleton()->m_current);
}
