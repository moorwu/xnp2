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
#include "pccore.h"
#include "scrndraw.h"
#include "timing.h"

#include "toolkit.h"

#include "joymng.h"
#include "mousemng.h"
#include "scrnmng.h"
#include "soundmng.h"
#include "taskmng.h"

#include "gtk3/xnp2.h"
#include "gtk3/gtk_keyboard.h"
#include "gtk3/gtk_menu.h"

#include "resources/np2.xbm"

/*
 * idle process
 */
void
install_idle_process(void)
{
}

void
uninstall_idle_process(void)
{
}

/*
 * toolkit
 */
BRESULT
gui_gtk_arginit(int *argcp, char ***argvp)
{
	return SUCCESS;
}

void
gui_gtk_widget_create(void)
{
}

void
gui_gtk_widget_show(void)
{
}

void
gui_gtk_widget_mainloop(void)
{
}

void
gui_gtk_widget_quit(void)
{
}

void
gui_gtk_event_process(void)
{
}

void
gui_gtk_set_window_title(const char* str)
{
}

int
gui_gtk_msgbox(const char *title, const char *msg, UINT flags)
{
	return 0;
}
