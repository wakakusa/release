#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * read_data function8の関数定義。 
 * csv
 **********************************************************************************************/


/**********************************************************************************************
 * function:Excelファイル読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Read_CSVfile_chooserdialog3
 **********************************************************************************************/
void create_Read_CSV_filechooserdialog3(StructPalletWidget *struct_widget,char UI_FILE[256],char Window_name[512])
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
G_MODULE_EXPORT void Read_CSVfile_chooserdialog3_FileOpen_OK (GtkWidget *widget,gpointer data  )
{
//読み込み対象ファイル名を取得
  (Pallet_Read_Data.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Read_Data.window1)); 

  sprintf(Pallet_Read_Data.object_name, "%s", gtk_entry_get_text(Pallet_Read_Data.entry1));//オブジェクト名取得


  (Pallet_Read_Data.script1) =g_strconcat(Pallet_Read_Data.object_name,"<-read.csv(\"",Pallet_Read_Data.file1,"\")\n",NULL);

 //OKボタンを押下したので後続処理を実行させるためにflagを変更する。
 (Pallet_Read_Data.proc_flag1)=TRUE;
  
  gtk_widget_destroy((Pallet_Read_Data.window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Read_CSVfile_chooserdialog3
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function8_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Read_CSV_filechooserdialog3(&Pallet_Read_Data,PalletInterfaceFile02,"Read_CSVfile_chooserdialog3");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.window1));
  gtk_widget_destroy(Pallet_Read_Data.window1);
  
  if((Pallet_Read_Data.proc_flag1)==TRUE)
  {
    Vte_terminal_insert(&VTE[VTE_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.proc_flag1)=FALSE;

}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Read_CSVfile_chooserdialog3
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function8_for_editor(GtkWidget *widget, gpointer data)
{
	create_Read_CSV_filechooserdialog3(&Pallet_Read_Data,PalletInterfaceFile02,"Read_CSVfile_chooserdialog3");
	gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.window1));
	gtk_widget_destroy(Pallet_Read_Data.window1);

  if((Pallet_Read_Data.proc_flag1)==TRUE)
  {
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  
  (Pallet_Read_Data.proc_flag1)=FALSE;

}


