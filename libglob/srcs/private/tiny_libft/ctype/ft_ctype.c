/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:22:11 by rclanget          #+#    #+#             */
/*   Updated: 2016/12/07 17:27:05 by rclanget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const int	g_ctype[256] =
{
	0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808,
	0x0808, 0x090c, 0x0908, 0x0908, 0x0908, 0x0908, 0x0808, 0x0808,
	0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808,
	0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808, 0x0808,
	0x1904, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0,
	0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0,
	0x1c31, 0x1c31, 0x1c31, 0x1c31, 0x1c31, 0x1c31, 0x1c31, 0x1c31,
	0x1c31, 0x1c31, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0,
	0x18a0, 0x1e23, 0x1e23, 0x1e23, 0x1e23, 0x1e23, 0x1e23, 0x1a23,
	0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23,
	0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23, 0x1a23,
	0x1a23, 0x1a23, 0x1a23, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x18a0,
	0x18a0, 0x1c63, 0x1c63, 0x1c63, 0x1c63, 0x1c63, 0x1c63, 0x1863,
	0x1863, 0x1863, 0x1863, 0x1863, 0x1863, 0x1863, 0x1863, 0x1863,
	0x1863, 0x1863, 0x1863, 0x1863, 0x1863, 0x1863, 0x1863, 0x1863,
	0x1863, 0x1863, 0x1863, 0x18a0, 0x18a0, 0x18a0, 0x18a0, 0x0808,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
};

int	ft_ctype_mask(int c, int mask)
{
	return (mask == (g_ctype[(unsigned char)(c & 0xFF)] & mask));
}
