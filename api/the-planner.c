/*
 * Copyright (c) 2002 Matteo Frigo
 * Copyright (c) 2002 Steven G. Johnson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "api.h"
#include "dft.h"
#include "rdft.h"
#include "reodft.h"
#include "threads.h"

static planner *plnr = 0;

/* create the planner for the rest of the API */
planner *X(the_planner)(void)
{
     if (!plnr) {
	  plnr = X(mkplanner)();
	  X(dft_conf_standard)(plnr);
	  X(rdft_conf_standard)(plnr);
	  X(reodft_conf_standard)(plnr);
	  X(threads_conf_standard)(plnr);
	  plnr->nthr = 1;
     }
     
     return plnr;
}
