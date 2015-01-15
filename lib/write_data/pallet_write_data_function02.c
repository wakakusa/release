#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

/**********************************************************************************************
 * function2:Excelファイルへ dataの書き込み関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Write_Excel_filechooserdialog
 **********************************************************************************************/
void create_Write_Excel_filechooserdialog(StructPalletWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
   (struct_widget->entry1) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_Excel_filechooserdialog_entry1"));
   (struct_widget->entry2) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_Excel_filechooserdialog_entry2"));
   (struct_widget->entry3) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_Excel_filechooserdialog_entry3"));
   (struct_widget->entry4) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_Excel_filechooserdialog_entry4"));


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
G_MODULE_EXPORT void create_Excel_Excel_filechooserdialog_OK (GtkWidget *widget,gpointer data  )
{
  //保存先ファイル名を取得
  (Pallet_Write_Data.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Write_Data.window1));

  
  sprintf(Pallet_Write_Data.object_name, "%s", gtk_entry_get_text(Pallet_Write_Data.entry1));//オブジェクト名取得
  sprintf(Pallet_Write_Data.sheet_name, "%s", gtk_entry_get_text(Pallet_Write_Data.entry2));//シート名取得
  sprintf(Pallet_Write_Data.start_row, "%s", gtk_entry_get_text(Pallet_Write_Data.entry3));//startRow数取得
  sprintf(Pallet_Write_Data.start_col, "%s", gtk_entry_get_text(Pallet_Write_Data.entry4));//startCol 数取得
 
  Pallet_Write_Data.script1 =g_strconcat("writeWorksheetToFile( data=",Pallet_Write_Data.object_name,",file=\"",Pallet_Write_Data.file1,"\",sheet=\"",Pallet_Write_Data.sheet_name,"\",startRow=",Pallet_Write_Data.start_row,",startCol=",Pallet_Write_Data.start_col,");\n",NULL);
  (Pallet_Write_Data.proc_flag1) =TRUE;
  gtk_widget_destroy((Pallet_Write_Data.window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Write_Excel_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function2_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Write_Excel_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_Excel_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.window1));
  gtk_widget_destroy(Pallet_Write_Data.window1);

  if((Pallet_Write_Data.proc_flag1) ==TRUE)
  {
	Vte_terminal_insert(&VTE[VTE_No],Pallet_Write_Data.script1);
	g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.proc_flag1) =FALSE;
}

/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Write_Excel_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function2_for_editor(GtkWidget *widget, gpointer data)
{
  create_Write_Excel_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_Excel_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.window1));
  gtk_widget_destroy(Pallet_Write_Data.window1);

  if((Pallet_Write_Data.proc_flag1) ==TRUE)
  {
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Write_Data.script1);
	  g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.proc_flag1) =FALSE;
}

