#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/*****************************************************************************************************
 * function1:change working directory
*****************************************************************************************************/
 
/*****************************************************************************************************
 * function:ダイアログ作成
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
void create_workdirectory_chooserdialog(StructPalletWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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


/*****************************************************************************************************
 * function:ファイル選択ダイアログをOKで閉じ、処理する
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void create_workdirectory_chooserdialog_FileOpen_OK (GtkWidget *widget,gpointer data  )
{

  (Pallet_Filesystem.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Filesystem.window1));

  (Pallet_Filesystem.script1) = g_strconcat("cd(\"",Pallet_Filesystem.file1,"\")\n",NULL);
  
  (Pallet_Filesystem.proc_flag1) =TRUE;
  gtk_widget_destroy((Pallet_Filesystem.window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Filesystem_function1_for_terminal(GtkWidget *widget, gpointer data)
{
  create_workdirectory_chooserdialog(&Pallet_Filesystem,PalletInterfaceFile01,"workdirectory_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Filesystem.window1));
  gtk_widget_destroy(Pallet_Filesystem.window1);
   
  if((Pallet_Filesystem.proc_flag1) ==TRUE)
  { 
	  Vte_terminal_insert(&VTE[VTE_No],Pallet_Filesystem.script1);
	  g_free( Pallet_Filesystem.script1 );
  }
  
  (Pallet_Filesystem.proc_flag1) =FALSE;
}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Filesystem_function1_for_editor(GtkWidget *widget, gpointer data)
{
  create_workdirectory_chooserdialog(&Pallet_Filesystem,PalletInterfaceFile01,"workdirectory_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Filesystem.window1));
  gtk_widget_destroy(Pallet_Filesystem.window1);
  
  if((Pallet_Filesystem.proc_flag1) ==TRUE)
  { 
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Filesystem.script1);
	  g_free( Pallet_Filesystem.script1 );
  }
  
  (Pallet_Filesystem.proc_flag1) =FALSE;
}


