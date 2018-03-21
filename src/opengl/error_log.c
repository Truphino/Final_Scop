/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:46:17 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/20 13:40:21 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

int			restart_log(void)
{
	int		fd;

	if ((fd = open(GL_LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU)) < 0)
	{
		ft_putendl("Error while opening the log file");
		exit(1);
	}
	ft_putendl_fd("-------------------------------------------------", fd);
	ft_putendl_fd(__DATE__ " " __TIME__, fd);
	close(fd);
	return (1);
}

int			gl_log(const char *message)
{
	int		fd;

	if ((fd = open(GL_LOG_FILE, O_WRONLY | O_APPEND)) < 0)
	{
		ft_putendl("Error while opening the log file");
		exit(1);
	}
	ft_putstr_fd(message, fd);
	close(fd);
	return (1);
}
