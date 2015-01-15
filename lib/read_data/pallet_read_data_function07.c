#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * read_data function7の関数定義。 
 * sasb7dat
 **********************************************************************************************/


/**********************************************************************************************
 * function:Excelファイル読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Read_sasb7datfile_chooserdialog
 **********************************************************************************************/
void create_Read_sasb7dat_filechooserdialog(StructPalletWidget *struct_widget,char UI_FILE[256],char Window_name[512])
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
  (struct_widget->entry1) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry1"));


  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 

   g_object_unref( G_OBJECT( builder ) );
}


/**********************************************************************************************
 * function:ファイル選択ダイアログをOKで閉じ、処理する 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void Read_sasb7datfile_chooserdialog_FileOpen_OK (GtkWidget *widget,gpointer data  )
{
//読み込み対象ファイル名を取得
  (Pallet_Read_Data.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Read_Data.window1)); 

  sprintf(Pallet_Read_Data.object_name, "%s", gtk_entry_get_text(Pallet_Read_Data.entry1));//オブジェクト名取得


  (Pallet_Read_Data.script1) =g_strconcat(Pallet_Read_Data.object_name,"<-read.sas7bdat(\"",Pallet_Read_Data.file1,"\")\n",NULL);

 //OKボタンを押下したので後続処理を実行させるためにflagを変更する。
 (Pallet_Read_Data.proc_flag1)=TRUE;
  
  gtk_widget_destroy((Pallet_Read_Data.window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Read_sasb7datfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function7_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Read_sasb7dat_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_sasb7datfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.window1));
  gtk_widget_destroy(Pallet_Read_Data.window1);
  
  if((Pallet_Read_Data.proc_flag1)==TRUE)
  {
    Vte_terminal_insert(&VTE[VTE_No], "library(sas7bdat)\n" );
    Vte_terminal_insert(&VTE[VTE_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.proc_flag1)=FALSE;

}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Read_sasb7datfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function7_for_editor(GtkWidget *widget, gpointer data)
{
	create_Read_sasb7dat_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_sasb7datfile_chooserdialog");
	gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.window1));
	gtk_widget_destroy(Pallet_Read_Data.window1);

  if((Pallet_Read_Data.proc_flag1)==TRUE)
  {
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], "library(sas7bdat)\n" );
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  
  (Pallet_Read_Data.proc_flag1)=FALSE;

}


