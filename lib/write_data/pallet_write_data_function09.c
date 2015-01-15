#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

 
/**function9:**/
/*for terminal*/
G_MODULE_EXPORT void cb_basic_function9_for_terminal(GtkWidget *widget, gpointer data)
{
	gchar *script;
	g_free(script);
	Vte_terminal_insert(&VTE[VTE_No],script);
}
/*for editor*/
G_MODULE_EXPORT void cb_basic_function9_for_editor(GtkWidget *widget, gpointer data)
{
	gchar *script;
	g_free(script);
	RScriptEditor_insert(&RSCRIPTEDITOR1,script);
}


