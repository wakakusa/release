#include "headers.h"
#include "defines.h"
#include "script_editor_window_structures.h"
#include "UserInterfaceFile.h"
#include "vte_window_structures.h"

/**********************************************************************************************
 * Script Editorのfile save 定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:スクリプトのsave用ファイル選択ダイアログを作成するためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
void create_script_file_save_dialog(StructSCRIPTEDITORWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
 * function:save用ファイル選択ダイアログを表示 
 * 
 * 
 * glade:filechooserdialog_save
 **********************************************************************************************/
G_MODULE_EXPORT void Script_FileSave_Dialog(GtkWidget *widget, gpointer data)
{
  create_script_file_save_dialog(&SCRIPT_OpenSave[SCRIPTEDITOR_No],UserInterfaceFile3,"filechooserdialog_save");
  gtk_dialog_run(GTK_DIALOG(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1));
  gtk_widget_destroy(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1);
}


/**********************************************************************************************
 * function:save用ファイル選択ダイアログをcabcelで閉じる 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Script_FileSave_Cancel(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy((SCRIPT_OpenSave[SCRIPTEDITOR_No].window1)); 
}


/**********************************************************************************************
 * function:ファイル選択ダイアログでOKを押下時、Editorからファイルを書き込む
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Script_FileSave_OK (GtkWidget *widget,gpointer data  )
{
  StructSCRIPTEDITORWidget *struct_widget =&SCRIPTEDITOR[SCRIPTEDITOR_No];

  gchar *buf;
  gsize size;
  GtkTextIter start, end;
 
  ( SCRIPT_OpenSave[SCRIPTEDITOR_No].file1 )= gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1));

  //開始行のGtkTextIterを取得（行番号は0から開始）
   gtk_text_buffer_get_start_iter(struct_widget->sourcebuffer1, &start);
  //最終行のGtkTextIterを取得
   gtk_text_buffer_get_end_iter(struct_widget->sourcebuffer1, &end);
  //startからendまでの行のテキストを取得（UTF8でエンコーディングされ、新しく領域を確保）
   buf = gtk_text_buffer_get_text(struct_widget->sourcebuffer1, &start, &end, TRUE);
  //テキストを保存
   g_file_set_contents(SCRIPT_OpenSave[SCRIPTEDITOR_No].file1 ,buf,-1,NULL);
   g_free(buf);
   
   SCRIPT_OpenSave[SCRIPTEDITOR_No].QuikSave_flag=TRUE ;
   
  /*window title変更*/
  gtk_window_set_title( SCRIPTEDITOR[SCRIPTEDITOR_No].window1, SCRIPT_OpenSave[SCRIPTEDITOR_No].file1 );
  
  gtk_widget_destroy((SCRIPT_OpenSave[SCRIPTEDITOR_No].window1)); 
}


/**********************************************************************************************
 * function:上書き保存
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Script_QuikFileSave (GtkWidget *widget,gpointer data  )
{
  StructSCRIPTEDITORWidget *struct_widget =&SCRIPTEDITOR[SCRIPTEDITOR_No];

  gchar *buf;
  gsize size;
  GtkTextIter start, end;
 
  if(SCRIPT_OpenSave[SCRIPTEDITOR_No].QuikSave_flag==FALSE)
 {
  create_script_file_save_dialog(&SCRIPT_OpenSave[SCRIPTEDITOR_No],UserInterfaceFile3,"filechooserdialog_save");
  gtk_dialog_run(GTK_DIALOG(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1));
  gtk_widget_destroy(SCRIPT_OpenSave[SCRIPTEDITOR_No].window1);
 } 
 else
 {
   //開始行のGtkTextIterを取得（行番号は0から開始）
   gtk_text_buffer_get_start_iter(struct_widget->sourcebuffer1, &start);
  //最終行のGtkTextIterを取得
   gtk_text_buffer_get_end_iter(struct_widget->sourcebuffer1, &end);
  //startからendまでの行のテキストを取得（UTF8でエンコーディングされ、新しく領域を確保）
   buf = gtk_text_buffer_get_text(struct_widget->sourcebuffer1, &start, &end, TRUE);
  //テキストを保存
   g_file_set_contents(SCRIPT_OpenSave[SCRIPTEDITOR_No].file1 ,buf,-1,NULL);
   g_free(buf);
 }
   
}
