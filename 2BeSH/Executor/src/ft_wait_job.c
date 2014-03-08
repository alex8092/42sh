#include "ft_executor.h"
#include <sys/wait.h>

void	p_exec_wait_current_job(void)
{
	int	status;

	if (exec_singleton()->m_current != 0)
	{
		waitpid(exec_singleton()->m_current, &status, 0);
	}
}
