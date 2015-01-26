#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

 /*****************************************************************************************************
 * function3:read sourcefile 
 * 
 * 
 * GUI:sourcefile_chooserdialog
*****************************************************************************************************/
void create_sourcefile_chooserdialog(StructPalletWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
{
  GtkBuilder *builder;
  GError* error = NULL;

  /* GtkBuilder作成 */
  builder = gtk_builder_new(); 
  
  /* UI_FILEの読み込み*/
  if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
  {
	g_warning ("Couldn't load builder file: %s", error->message);
	g_error_free (error);
  }

  /* windowのオブジェクト取得 */
  (struct_widget->window1) = GTK_WIDGET( gtk_builder_get_object(builder, Window_name)); 
  /*複数のウィジェットを操作する場合、構造体に格納にすること。
   * 格納先にあわせて、GTK_LABELやGTK_ENTRYなどGTK_～を変更すること。
   *不明な場合はGTK_WIDGETでも可能。ただしエラーは出力される。*/


  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 

   g_object_unref( G_OBJECT( builder ) );
} 

/*ファイル選択ダイアログをOKで閉じ、処理する*/
G_MODULE_EXPORT void create_sourcefile_chooserdialog_FileOpen_OK (GtkWidget *widget,gpointer data  )
{

  (Pallet_Operation.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Operation.window1));

  (Pallet_Operation.script1) = g_strconcat("source(\"",Pallet_Operation.file1,"\")\n",NULL);
  
  (Pallet_Operation.proc_flag1) =TRUE;
  gtk_widget_destroy((Pallet_Operation.window1)); 
}


/**function3:source()**/
/*for terminal*/
G_MODULE_EXPORT void cb_basic_function3_for_terminal(GtkWidget *widget, gpointer data)
{
  create_sourcefile_chooserdialog(&Pallet_Operation,PalletInterfaceFile01,"sourcefile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Operation.window1));
  gtk_widget_destroy(Pallet_Operation.window1);
  
  if((Pallet_Operation.proc_flag1) ==TRUE)
  {  
	  Vte_terminal_insert(&VTE[VTE_No],Pallet_Operation.script1 );
	  g_free(Pallet_Operation.script1);
  }
  
  (Pallet_Operation.proc_flag1) =FALSE;
}
/*for editor*/
G_MODULE_EXPORT void cb_basic_function3_for_editor(GtkWidget *widget, gpointer data)
{
  create_sourcefile_chooserdialog(&Pallet_Operation,PalletInterfaceFile01,"sourcefile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Operation.window1));
  gtk_widget_destroy(Pallet_Operation.window1);
  
  if((Pallet_Operation.proc_flag1) ==TRUE)
  {  
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Operation.script1);
	  g_free(Pallet_Operation.script1);
  }
  
  (Pallet_Operation.proc_flag1) =FALSE;
}

