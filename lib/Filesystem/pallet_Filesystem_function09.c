#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

 
/*****************************************************************************************************
 * function9:R save binary file
*****************************************************************************************************/

/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:save_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Filesystem_function9_for_terminal(GtkWidget *widget, gpointer data)
{
	gchar *script;
	g_free(script);
	Vte_terminal_insert(&VTE[VTE_No],script);
}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:save_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Filesystem_function9_for_editor(GtkWidget *widget, gpointer data)
{
	gchar *script;
	g_free(script);
	ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script);
}


