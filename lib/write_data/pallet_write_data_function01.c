#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

/**********************************************************************************************
 * function1:textファイルへ dataの書き込み関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Write_TEXT_filechooserdialog
 **********************************************************************************************/
void create_Write_TEXT_filechooserdialog(StructPalletReadWriteData *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
   (struct_widget->entry_variable_name) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_TEXT_filechooserdialog_entry_variable_name"));

   (struct_widget->checkbutton_header) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Write_TEXT_filechooserdialog_checkbutton_header"));
   
   (struct_widget->checkbutton_separator) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Write_TEXT_filechooserdialog_checkbutton_separator"));
   (struct_widget->entry_separator) = GTK_ENTRY(gtk_builder_get_object(builder, "Write_TEXT_filechooserdialog_entry_separator"));
   
   (struct_widget->checkbutton_quotemark) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Write_TEXT_filechooserdialog_checkbutton_quotemark"));
   (struct_widget->entry_quotemark) = GTK_ENTRY(gtk_builder_get_object(builder, "Write_TEXT_filechooserdialog_entry_quotemark"));

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
G_MODULE_EXPORT void create_WriteText_filechooserdialog_OK (GtkWidget *widget,gpointer data  )
{
	const gchar *toggle_button_active_str[]={"false","true"}; 
	
	//変数名取得
	Pallet_Write_Data.variable_name=gtk_entry_get_text(Pallet_Write_Data.entry_variable_name);//変数名取得
		
	//保存先ファイル名を取得
	Pallet_Write_Data.file_path1 = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Write_Data.function_window1));
	Pallet_Write_Data.script1 =g_strconcat("using DataFrames\n","writetable(\"",Pallet_Write_Data.file_path1,"\",",Pallet_Write_Data.variable_name,NULL);
	g_free(Pallet_Write_Data.file_path1);

	//file's header 制御
	Pallet_Write_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Write_Data.checkbutton_header);
	Pallet_Write_Data.header=g_strconcat(",header=",toggle_button_active_str[Pallet_Write_Data.toggle_button_active],NULL);
	Pallet_Write_Data.script1 =g_strconcat(Pallet_Write_Data.script1,Pallet_Write_Data.header,NULL);
	g_free(Pallet_Write_Data.header);
  
  /*separator 制御*/
	Pallet_Write_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Write_Data.checkbutton_separator);
	if(Pallet_Write_Data.toggle_button_active==TRUE)
	{
		Pallet_Write_Data.separator=g_strconcat(",separator='",gtk_entry_get_text(Pallet_Write_Data.entry_separator),"'",NULL);
		Pallet_Write_Data.script1 =g_strconcat(Pallet_Write_Data.script1,Pallet_Write_Data.separator,NULL);
		g_free(Pallet_Write_Data.separator);
	}


  /*quotemark 制御*/
	Pallet_Write_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Write_Data.checkbutton_quotemark);
	if(Pallet_Write_Data.toggle_button_active==TRUE)
	{
		Pallet_Write_Data.quotemark=g_strconcat(",quotemark='",gtk_entry_get_text(Pallet_Write_Data.entry_quotemark),"'",NULL);
		Pallet_Write_Data.script1 =g_strconcat(Pallet_Write_Data.script1,Pallet_Write_Data.quotemark,NULL);
		g_free(Pallet_Write_Data.quotemark);
	}
	
	Pallet_Write_Data.script1=g_strconcat(Pallet_Write_Data.script1,");\n",NULL);
	(Pallet_Write_Data.process_check_flag1) =TRUE;

	gtk_widget_destroy((Pallet_Write_Data.function_window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Write_TEXT_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function1_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Write_TEXT_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_TEXT_filechooserdialog");
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
 * glade:Write_TEXT_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function1_for_editor(GtkWidget *widget, gpointer data)
{
  create_Write_TEXT_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_TEXT_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.function_window1));
  gtk_widget_destroy(Pallet_Write_Data.function_window1);

  if((Pallet_Write_Data.process_check_flag1) ==TRUE)
  {
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Write_Data.script1);
	  g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.process_check_flag1) =FALSE;
}

