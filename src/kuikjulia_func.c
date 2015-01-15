#include "headers.h"
#include "defines.h"
#include "UserInterfaceFile.h"
#include "kuikjulia_window.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"

/**********************************************************************************************
 * kuikjuliaの関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:julia helpの起動 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void cb_julia_GUI_Help(GtkWidget *widget, gpointer data)
{
  create_pallet(&GuiHelp,UserInterfaceFile1,"GUI_Help");
    /* windowの表示 */
  gtk_widget_show_all((GuiHelp.window1)); 
}

/**********************************************************************************************
 * function:Script Editor のWindowを作成するためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void cb_GUI_Help_Serch( GtkEntry *GUI_Help_Entry01, gpointer user_data ) 
{
  gchar *script1;
 
  /*ラベルに表示する文字列作成*/
  script1 = g_strconcat("help(\"",gtk_entry_get_text(GUI_Help_Entry01),"\")\n",NULL);
  Vte_terminal_insert(&VTE[VTE_No],script1);
} 