#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * read_data function6の関数定義。 
 * Excelファイルを読み込む
 **********************************************************************************************/


/**********************************************************************************************
 * function:Excelファイル読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Read_Excelfile_chooserdialog
 **********************************************************************************************/
void create_Read_Excel_filechooserdialog(StructPalletWidget *struct_widget,char UI_FILE[256],char Window_name[512])
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
  (struct_widget->check_button1) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_checkbutton1"));
  (struct_widget->entry1) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry1"));
  (struct_widget->entry2) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry2"));
  (struct_widget->entry3) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry3"));
  (struct_widget->entry4) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Excelfile_chooserdialog_entry4"));


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
G_MODULE_EXPORT void Read_Excelfile_chooserdialog_FileOpen_OK (GtkWidget *widget,gpointer data  )
{
//読み込み対象ファイル名を取得
  (Pallet_Read_Data.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Read_Data.window1));
  
  //checkbuttonの確認
  //処理用共通変数
  gboolean toggle_button_active;
  gchar *toggle_button_active_str[]={"FALSE","TRUE"};
  
  //ヘッダーの有無 
  toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.check_button1);
  sprintf(Pallet_Read_Data.TF_flag1,toggle_button_active_str[toggle_button_active]);

  sprintf(Pallet_Read_Data.object_name, "%s", gtk_entry_get_text(Pallet_Read_Data.entry1));//オブジェクト名取得
  sprintf(Pallet_Read_Data.sheet_name, "%s", gtk_entry_get_text(Pallet_Read_Data.entry2));//シート名取得
  sprintf(Pallet_Read_Data.start_row, "%s", gtk_entry_get_text(Pallet_Read_Data.entry3));//開始行数取得
  sprintf(Pallet_Read_Data.start_col, "%s", gtk_entry_get_text(Pallet_Read_Data.entry4));//開始列数取得

  /*将来の引数拡張対応のために残しておく
  (Pallet_Read_Data.script1) =g_strconcat(Pallet_Read_Data.object_name,"<-readWorksheetFromFile(\"",Pallet_Read_Data.file1,"\",header=",Pallet_Read_Data.TF_flag1,",sheet =\"",Pallet_Read_Data.sheet_name,"\",startRow=",Pallet_Read_Data.start_row,",startCol=",Pallet_Read_Data.start_col,");\n",NULL);
*/
 //OKボタンを押下したので後続処理を実行させるためにflagを変更する。
 (Pallet_Read_Data.proc_flag1)=TRUE;
  
  gtk_widget_destroy((Pallet_Read_Data.window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Read_Excelfile_chooserdialog
*****************************************************************************************************/
/*function06 read data from Excel file*/
G_MODULE_EXPORT void cb_read_data_function6_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Read_Excel_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Excelfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.window1));
  gtk_widget_destroy(Pallet_Read_Data.window1);
  
  if((Pallet_Read_Data.proc_flag1)==TRUE)
  {
    Vte_terminal_insert(&VTE[VTE_No], "library(XLConnect)\n" );
    Vte_terminal_insert(&VTE[VTE_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.proc_flag1)=FALSE;

}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Read_Excelfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function6_for_editor(GtkWidget *widget, gpointer data)
{
	create_Read_Excel_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Excelfile_chooserdialog");
	gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.window1));
	gtk_widget_destroy(Pallet_Read_Data.window1);

  if((Pallet_Read_Data.proc_flag1)==TRUE)
  {
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], "library(XLConnect)\n" );
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  
  (Pallet_Read_Data.proc_flag1)=FALSE;

}


