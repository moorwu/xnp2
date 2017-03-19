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

struct _Xnp2AppWindow
{
	GtkApplicationWindow parent;
};

G_DEFINE_TYPE(Xnp2AppWindow, xnp2_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
xnp2_app_window_init(Xnp2AppWindow *app)
{
}

static void
xnp2_app_window_class_init(Xnp2AppWindowClass *klass)
{
}

Xnp2AppWindow *
xnp2_app_window_new(Xnp2App *app)
{

	return g_object_new(XNP2_APP_WINDOW_TYPE, "application", app, NULL);
}

void
xnp2_app_window_open(Xnp2AppWindow *win, GFile *file)
{
}

struct _Xnp2App {
	GtkApplication parent;
};

G_DEFINE_TYPE(Xnp2App, xnp2_app, GTK_TYPE_APPLICATION);

static void
xnp2_app_init(Xnp2App *app)
{
}

static void
xnp2_app_activate(GApplication *app)
{
	Xnp2AppWindow *win;

	win = xnp2_app_window_new(XNP2_APP(app));
	gtk_window_present(GTK_WINDOW(win));
}

static void
xnp2_app_open(GApplication *app, GFile **files, gint nfiles, const gchar *hint)
{
	GList *windows;
	Xnp2AppWindow *win;
	int i;

	windows = gtk_application_get_windows(GTK_APPLICATION(app));
	if (windows != NULL)
		win = XNP2_APP_WINDOW(windows->data);
	else
		win = xnp2_app_window_new(XNP2_APP(app));

	for (i = 0; i < nfiles; i++)
		xnp2_app_window_open(win, files[i]);

	gtk_window_present(GTK_WINDOW(win));
}

static void
xnp2_app_class_init(Xnp2AppClass *klass)
{

	G_APPLICATION_CLASS(klass)->activate = xnp2_app_activate;
	G_APPLICATION_CLASS(klass)->open = xnp2_app_open;
}

Xnp2App *
xnp2_app_new(void)
{

	return g_object_new(XNP2_APP_TYPE,
	    "application-id", "org.nonakap.xnp2",
	    "flags", G_APPLICATION_HANDLES_OPEN,
	    NULL);
}

static int *xnp2_argcp;
static char ***xnp2_argvp;

/*
 * idle process
 */
static volatile int install_count = 0;
static guint idle_id;

void
install_idle_process(void)
{

	if (install_count++ == 0) {
		idle_id = gdk_threads_add_idle(mainloop, NULL);
		soundmng_play();
	}
}

void
uninstall_idle_process(void)
{

	if (--install_count == 0) {
		soundmng_stop();
		g_source_remove(idle_id);
	}
}

/*
 * toolkit
 */
BRESULT
gui_gtk_arginit(int *argcp, char ***argvp)
{

	xnp2_argcp = argcp;
	xnp2_argvp = argvp;

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

	install_idle_process();
	g_application_run(G_APPLICATION(xnp2_app_new()),
	    *xnp2_argcp, *xnp2_argvp);
	uninstall_idle_process();
}

void
gui_gtk_widget_quit(void)
{

	taskmng_exit();
	g_application_quit(g_application_get_default());
}

void
gui_gtk_event_process(void)
{

	if (taskmng_isavail() && gtk_events_pending())
		gtk_main_iteration_do(FALSE);
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
