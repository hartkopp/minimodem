/*
 * databits_ascii.c
 *
 * Copyright (C) 2012 Kamal Mostafa <kamal@whence.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "databits.h"

/*
 * ASCII HEX 8-bit data databits decoder/encoder (passthrough)
 */

#include <stdio.h>
#include <assert.h>

/* returns the number of datawords stuffed into *databits_outp */
int
databits_encode_asciihex( unsigned int *databits_outp, char char_out )
{
	*databits_outp = char_out;
	return 1;
}

/* returns nbytes decoded */
unsigned int
databits_decode_asciihex( char *dataout_p, unsigned int dataout_size,
			  unsigned long long bits, unsigned int n_databits,
			  int parity )
{
# if 0
	if ( ! dataout_p )	// databits processor reset: noop
		return 0;
	bits &= 0xFF;
	*dataout_p = bits;
	return 1;
	if (parity)
		n_databits++;
#endif
	n_databits = 8;

	if ( ! dataout_p )	// databits processor reset: noop
		return 0;
	assert( dataout_size >= n_databits + 1 );
	int j;
	for ( j=0; j<n_databits; j++ )
		dataout_p[j] = (bits>>j & 1) + '0';
	sprintf(&dataout_p[j], " %02X\n", (unsigned int)bits&0xFF);
//	dataout_p[j] = '\n';
	return n_databits + 1 + 3;
}

