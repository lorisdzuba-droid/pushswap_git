/* ************************************************************************** */
/*									  */
/*							:::	 ::::::::   */
/*   ft_memcpy.c										:+:   :+:	:+:   */
/*						  +:+ +:+	   +:+	*/
/*   By: ldzuba <ldzuba@student.42.fr>		+#+  +:+	   +#+	*/
/*						+#+#+#+#+#+   +#+	 */
/*   Created: 2025/10/15 10:06:46 by ldzuba   #+#  #+#		  */
/*   Updated: 2025/10/15 10:19:05 by ldzuba	 ###   ########.fr	*/
/*									  */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*destcpy;
	const unsigned char		*srccpy;
	size_t					i;

	i = 0;
	destcpy = (unsigned char *)dest;
	srccpy = (const unsigned char *)src;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (dest);
}
