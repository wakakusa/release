#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

/**********************************************************************************************
 * function2:HDF5ファイルへ dataの書き込み関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Write_HDF5_filechooserdialog
 **********************************************************************************************/
void create_Write_HDF5_filechooserdialog(StructPalletReadWriteData *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
  (struct_widget->function_window1) = GTK_WIDGET( gtk_builder_get_object(builder, Window_name)); 
  /*複数のウィジェットを操作する場合、構造体に格納にすること。
   * 格納先にあわせて、GTK_LABELやGTK_ENTRYなどGTK_～を変更すること。
   *不明な場合はGTK_WIDGETでも可能。ただしエラーは出力される。*/
   (struct_widget->entry_variable_name) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_HDF5_filechooserdialog_entry_variable_name"));
   (struct_widget->entry_groupe_name) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_HDF5_filechooserdialog_entry_groupe_name"));

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
G_MODULE_EXPORT void create_WriteHDF5_filechooserdialog_OK (GtkWidget *widget,gpointer data  )
{
	const gchar *toggle_button_active_str[]={"false","true"};

	//変数名取得
	Pallet_Write_Data.variable_name=gtk_entry_get_text(Pallet_Write_Data.entry_variable_name);//変数名取得

	//グループ名取得
	Pallet_Write_Data.groupe_name=gtk_entry_get_text(Pallet_Write_Data.entry_groupe_name);//変数名取得

		
	//保存先ファイル名を取得
	Pallet_Write_Data.file_path1 = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Write_Data.function_window1));
	Pallet_Write_Data.script1 =g_strconcat("using HDF5\n","h5write(\"",Pallet_Write_Data.file_path1,"\",\"",Pallet_Write_Data.groupe_name,"\",",Pallet_Write_Data.variable_name,NULL);
	g_free(Pallet_Write_Data.file_path1);
	
	Pallet_Write_Data.script1=g_strconcat(Pallet_Write_Data.script1,");\n",NULL);
	(Pallet_Write_Data.process_check_flag1) =TRUE;

	gtk_widget_destroy((Pallet_Write_Data.function_window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Write_HDF5_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function2_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Write_HDF5_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_HDF5_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.function_window1));
  gtk_widget_destroy(Pallet_Write_Data.function_window1);

  if((Pallet_Write_Data.process_check_flag1) ==TRUE)
  {
	Vte_terminal_insert(&VTE[VTE_No],Pallet_Write_Data.script1);
	g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.process_check_flag1) =FALSE;
}

/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Write_HDF5_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function2_for_editor(GtkWidget *widget, gpointer data)
{
  create_Write_HDF5_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_HDF5_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.function_window1));
  gtk_widget_destroy(Pallet_Write_Data.function_window1);

  if((Pallet_Write_Data.process_check_flag1) ==TRUE)
  {
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Write_Data.script1);
	  g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.process_check_flag1) =FALSE;
}

