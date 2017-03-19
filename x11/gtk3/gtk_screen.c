/*
 * Copyright (c) 2017 Kimihiro Nonaka
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "compiler.h"

#include "np2.h"
#include "palettes.h"
#include "scrndraw.h"

#include "toolkit.h"

#include "scrnmng.h"
#include "mousemng.h"
#include "soundmng.h"

#include "gtk3/xnp2.h"
#include "gtk3/gtk_drawmng.h"
#include "gtk3/gtk_menu.h"

static SCRNMNG scrnmng;
SCRNMNG *scrnmngp = &scrnmng;

void
scrnmng_initialize(void)
{
}

BRESULT
scrnmng_create(UINT8 mode)
{
	return SUCCESS;
}

void
scrnmng_destroy(void)
{
}

void
scrnmng_fullscreen(int onoff)
{
}

RGB16
scrnmng_makepal16(RGB32 pal32)
{
	return 0;
}

void
scrnmng_setwidth(int posx, int width)
{
}

void
scrnmng_setheight(int posy, int height)
{
}

void
scrnmng_setextend(int extend)
{
}

void
scrnmng_setmultiple(int multiple)
{
}

const SCRNSURF *
scrnmng_surflock(void)
{
	return NULL;
}

void
scrnmng_surfunlock(const SCRNSURF *surf)
{
}

void
scrnmng_update(void)
{
}