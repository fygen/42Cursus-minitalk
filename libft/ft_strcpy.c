/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:29:11 by oem               #+#    #+#             */
/*   Updated: 2024/05/09 19:29:19 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
			// so this will make s1 = to whatever s2 is looping through the string
		i++;
	}
	s1[i] = s2[i];
		// now that we are finsihing looping though s1[i] will equal s2[i]
	return (s1);
}