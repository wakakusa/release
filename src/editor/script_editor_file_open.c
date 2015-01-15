#include "headers.h"
#include "defines.h"
#include "script_editor_window_structures.h"
#include "UserInterfaceFile.h"
#include "vte_window_structures.h"

/**********************************************************************************************
 * Script Editorのfile open 定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:スクリプトのオープン用ファイル選択ダイアログを作成するためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
void create_script_file_open_dialog(StructSCRIPTEDITORWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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

/**********************************************************************************************
 * function:open用ファイル選択ダイアログを表示 
 * 
 * 
 * glade:filechooserdialog_open
 **********************************************************************************************/
G_MODULE_EXPORT void Script_FileOpen_Dialog(GtkWidget *widget, gpointer data)
{
  create_script_file_open_dialog(&SCRIPT_OpenSave[SCRIPTEDITOR_No],UserInterfaceFile3,"filechooserdialog_open");
  gtk_dialog_run(GTK_DIALOG(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1));
  gtk_widget_destroy(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1);
//  gtk_widget_show_all((RSCRIPT_OpenSave[RSCRIPTEDITOR_No].window1)); 
}


/**********************************************************************************************
 * function:open用ファイル選択ダイアログをcabcelで閉じる 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Script_FileOpen_Cancel(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy((SCRIPT_OpenSave[SCRIPTEDITOR_No].window1)); 
}


/**********************************************************************************************
 * function:ファイル選択ダイアログでOKを押下時、Editorにファイルを読み込む
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Script_FileOpen_OK (GtkWidget *widget,gpointer data  )
{
  StructSCRIPTEDITORWidget *struct_widget =&SCRIPTEDITOR[SCRIPTEDITOR_No];
  gchar *file;
  gchar *buf;
  gsize size;
 
  ( SCRIPT_OpenSave[SCRIPTEDITOR_No].file1 ) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1));
 
  /*テキストファイルを読み込み、テキストビューに表示*/
  if (g_file_get_contents( SCRIPT_OpenSave[SCRIPTEDITOR_No].file1 ,&buf,&size,NULL)) {
    gtk_text_buffer_set_text(struct_widget->sourcebuffer1,buf,size);
    g_free(buf);
  }
  
  SCRIPT_OpenSave[SCRIPTEDITOR_No].QuikSave_flag=TRUE ;
  
  gtk_widget_destroy((SCRIPT_OpenSave[SCRIPTEDITOR_No].window1)); 
}

