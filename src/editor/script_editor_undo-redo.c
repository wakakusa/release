#include "headers.h"
#include "defines.h"
#include "script_editor_window_structures.h"
#include "UserInterfaceFile.h"
#include "vte_window_structures.h"

/**********************************************************************************************
 * Script Editorのundo/redo 定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:undo処理
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Script_undo (GtkWidget *widget,gpointer data  )
{
  StructSCRIPTEDITORWidget *struct_widget =&SCRIPTEDITOR[SCRIPTEDITOR_No];
  GtkSourceBuffer *buffer=struct_widget->sourcebuffer1;

  if (gtk_source_buffer_can_undo(buffer)) {
	  gtk_source_buffer_undo(buffer);
  }

}


/**********************************************************************************************
 * function:redo処理
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Script_redo (GtkWidget *widget,gpointer data  )
{
  StructSCRIPTEDITORWidget *struct_widget =&SCRIPTEDITOR[SCRIPTEDITOR_No];
  GtkSourceBuffer *buffer=struct_widget->sourcebuffer1;

  if (gtk_source_buffer_can_redo(buffer)) {
	  gtk_source_buffer_redo(buffer);
  }

}
