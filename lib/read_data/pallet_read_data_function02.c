#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

/**********************************************************************************************
 * function2:HDF5ファイルへ dataの読み込み込み関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Read_HDF5_filechooserdialog
 **********************************************************************************************/
void create_Read_HDF5_filechooserdialog(StructPalletReadWriteData *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
   (struct_widget->entry_variable_name) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_HDF5_filechooserdialog_entry_variable_name"));
   (struct_widget->entry_groupe_name) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_HDF5_filechooserdialog_entry_groupe_name"));

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
G_MODULE_EXPORT void create_ReadHDF5_filechooserdialog_OK (GtkWidget *widget,gpointer data  )
{
	const gchar *toggle_button_active_str[]={"false","true"};

	//変数名取得
	Pallet_Read_Data.variable_name=gtk_entry_get_text(Pallet_Read_Data.entry_variable_name);//変数名取得

	//グループ名取得
	Pallet_Read_Data.groupe_name=gtk_entry_get_text(Pallet_Read_Data.entry_groupe_name);//変数名取得

		
	//保存先ファイル名を取得
	Pallet_Read_Data.file_path1 = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Read_Data.function_window1));
	Pallet_Read_Data.script1 =g_strconcat("using HDF5\n",Pallet_Read_Data.variable_name,"=h5read(\"",Pallet_Read_Data.file_path1,"\",\"",Pallet_Read_Data.groupe_name,"\"",NULL);
	g_free(Pallet_Read_Data.file_path1);
	
	Pallet_Read_Data.script1=g_strconcat(Pallet_Read_Data.script1,");\n",NULL);
	(Pallet_Read_Data.process_check_flag1) =TRUE;

	gtk_widget_destroy((Pallet_Read_Data.function_window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Read_HDF5_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function2_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Read_HDF5_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_HDF5_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);

  if((Pallet_Read_Data.process_check_flag1) ==TRUE)
  {
	Vte_terminal_insert(&VTE[VTE_No],Pallet_Read_Data.script1);
	g_free( Pallet_Read_Data.script1 );
  }
  
  (Pallet_Read_Data.process_check_flag1) =FALSE;
}

/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Read_HDF5_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function2_for_editor(GtkWidget *widget, gpointer data)
{
  create_Read_HDF5_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_HDF5_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);

  if((Pallet_Read_Data.process_check_flag1) ==TRUE)
  {
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Read_Data.script1);
	  g_free( Pallet_Read_Data.script1 );
  }
  
  (Pallet_Read_Data.process_check_flag1) =FALSE;
}

