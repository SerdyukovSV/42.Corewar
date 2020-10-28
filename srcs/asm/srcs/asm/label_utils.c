/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhitmonc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:07:52 by lhitmonc          #+#    #+#             */
/*   Updated: 2020/10/25 15:07:53 by lhitmonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label			*getlabels(void)
{
	static t_label		labels = (t_label){0, NULL};

	if (labels.label == NULL)
		labels.label = ft_lstnew(NULL, 0);
	return (&labels);
}

t_label			*getlabels_use(void)
{
	static t_label		labels = (t_label){0, NULL};

	if (labels.label == NULL)
		labels.label = ft_lstnew(NULL, 0);
	return (&labels);
}

int				label_index(char *name)
{
	t_list				*labels;
	int					index;

	index = 0;
	labels = getlabels()->label;
	while (labels)
	{
		if (labels->content)
			if (!ft_strcmp(labels->content, name))
				return (index);
		index++;
		labels = labels->next;
	}
	return (-1);
}

int				label_value(char *name, int index)
{
	t_list				*labels;

	labels = getlabels()->label;
	while (labels)
	{
		if (labels->content)
			if (!ft_strcmp(labels->content, name))
				return (labels->content_size - index);
		labels = labels->next;
	}
	return (INT_MAX);
}

int				add_label(char *name, int value)
{
	t_list				*new_labels;
	t_list				*labels;

	if (name)
	{
		if (label_index(name) != -1)
			return (1);
		new_labels = ft_lstnew(name, ft_strlen(name) + 1);
	}
	else
		new_labels = ft_lstnew(NULL, 0);
	new_labels->content_size = value;
	labels = getlabels()->label;
	ft_lstaddback(&labels, new_labels);
	return (0);
}
