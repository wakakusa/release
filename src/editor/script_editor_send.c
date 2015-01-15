#include "headers.h"
#include "defines.h"
#include "script_editor_window_structures.h"
#include "UserInterfaceFile.h"
#include "vte_window_structures.h"

/**********************************************************************************************
 *Script send from Editor to VTEの定義。 
 * 
 **********************************************************************************************/

/**********************************************************************************************
 * function:Script Editorのカーソル行のスクリプトをVTEに送信するcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Send_Script_to_VTE_from_Editor(GtkWidget *widget, gpointer data)
{
  StructSCRIPTEDITORWidget *struct_widget =&SCRIPTEDITOR[SCRIPTEDITOR_No];
  GtkSourceBuffer *buffer=struct_widget->sourcebuffer1;

  gint row, col;
  GtkTextIter start,end,iter;
  gchar *text;
  
  gtk_text_buffer_get_iter_at_mark(buffer,&iter, gtk_text_buffer_get_insert(buffer));
  row = gtk_text_iter_get_line(&iter);

  gtk_text_buffer_get_iter_at_line(buffer,&start,row);
  gtk_text_buffer_get_iter_at_line(buffer,&end,row);
  gtk_text_iter_forward_line (&end);
  
  text=gtk_text_iter_get_text (&start, &end);

  Vte_terminal_insert(&VTE[VTE_No],text);
  g_free(text);
  
//  coursor potion change
  gtk_text_buffer_place_cursor(buffer,&end);
}


/**********************************************************************************************
 * function:Script Editorの全スクリプトをVTEに送信するcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Send_ALL_Script_to_VTE_from_Editor(GtkWidget *widget, gpointer data)
{
  StructSCRIPTEDITORWidget *struct_widget =&SCRIPTEDITOR[SCRIPTEDITOR_No];
  GtkSourceBuffer *buffer=struct_widget->sourcebuffer1;
  gint row, col;
  GtkTextIter start,end,iter;
  gchar *scripts;

  gtk_text_buffer_get_start_iter (buffer,&start);
  gtk_text_buffer_get_end_iter (buffer,&end);
   
  scripts=gtk_text_iter_get_text (&start, &end);
  Vte_terminal_insert(&VTE[VTE_No],scripts);
  g_free(scripts);
}
