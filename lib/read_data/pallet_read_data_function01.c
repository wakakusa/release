#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * function1:text dataの読み込み関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Read_Textfile_chooserdialog
 **********************************************************************************************/
void create_ReadText_filechooserdialog(StructPalletReadWriteData *struct_widget,char UI_FILE[256],char Window_name[512])
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
	(struct_widget->entry_variable_name) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_variable_name"));
   
	(struct_widget->checkbutton_header) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_header"));

	(struct_widget->checkbutton_separator) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_separator"));
	(struct_widget->entry_separator) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_separator"));
	
	(struct_widget->checkbutton_quotemark) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_quotemark"));
	(struct_widget->entry_quotemark) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_quotemark"));

	(struct_widget->checkbutton_decimal) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_decimal"));
	(struct_widget->entry_decimal) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_decimal"));
	
	(struct_widget->checkbutton_nastrings) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_nastrings"));
	(struct_widget->entry_nastrings) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_nastrings"));
	
	(struct_widget->checkbutton_truestrings) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_truestrings"));
	(struct_widget->entry_truestrings) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_truestrings"));

	(struct_widget->checkbutton_falsestrings) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_falsestrings"));
	(struct_widget->entry_falsestrings) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_falsestrings"));

	(struct_widget->checkbutton_makefactors) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_makefactors"));

	(struct_widget->checkbutton_nrows) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_nrows"));
	(struct_widget->entry_nrows) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_nrows"));

	(struct_widget->checkbutton_names) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_names"));
	(struct_widget->entry_names) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_names"));

	(struct_widget->checkbutton_eltypes) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_eltypes"));
	(struct_widget->entry_eltypes) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_eltypes"));

	(struct_widget->checkbutton_allowcomments) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_allowcomments"));

	(struct_widget->checkbutton_commentmark) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_commentmark"));
	(struct_widget->entry_commentmark) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_commentmark"));

	(struct_widget->checkbutton_ignorepadding) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_ignorepadding"));

	(struct_widget->checkbutton_skipstart) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_skipstart"));
	(struct_widget->entry_skipstart) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_skipstart"));

	(struct_widget->checkbutton_skiprows) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_skiprows"));
	(struct_widget->entry_skiprows) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_skiprows"));

	(struct_widget->checkbutton_skipblanks) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_skipblanks"));

	(struct_widget->checkbutton_encoding) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_checkbutton_encoding"));
	(struct_widget->entry_encoding) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Read_Textfile_chooserdialog_entry_encoding"));
	
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
G_MODULE_EXPORT void ReadText_filechooserdialog_FileOpen_OK (GtkWidget *widget,gpointer data  )
{
	const gchar *toggle_button_active_str[]={"false","true"}; 
	//OKボタンを押下したので後続処理を実行させるためにflagを変更する。

	
	//変数名取得
	Pallet_Read_Data.variable_name=gtk_entry_get_text(Pallet_Read_Data.entry_variable_name);
	
	//読み込み対象ファイル名を取得
	Pallet_Read_Data.file_path1 = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Read_Data.function_window1));
	Pallet_Read_Data.script1 =g_strconcat("using DataFrames\n",Pallet_Read_Data.variable_name,"=readtable(\"",Pallet_Read_Data.file_path1,"\"",NULL);
	g_free(Pallet_Read_Data.file_path1);
	
	//header
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_header);
	Pallet_Read_Data.header=g_strconcat(",header=",toggle_button_active_str[Pallet_Read_Data.toggle_button_active],NULL);
	Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.header,NULL);
	g_free(Pallet_Read_Data.header);

	//separator
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_separator);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.separator=g_strconcat(",separator='",gtk_entry_get_text(Pallet_Read_Data.entry_separator),"'",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.separator,NULL);
		g_free(Pallet_Read_Data.separator);
	}
	
	//quotemark
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_quotemark);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.quotemark=g_strconcat(",quotemark=['",gtk_entry_get_text(Pallet_Read_Data.entry_quotemark),"']",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.quotemark,NULL);
		g_free(Pallet_Read_Data.quotemark);
	}
		
	//decimal
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_quotemark);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.decimal=g_strconcat(",decimal='",gtk_entry_get_text(Pallet_Read_Data.entry_decimal),"'",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.decimal,NULL);
		g_free(Pallet_Read_Data.decimal);
	}
	
	//nastrings
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_nastrings);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.nastrings=g_strconcat(",nastrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_nastrings),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.nastrings,NULL);
		g_free(Pallet_Read_Data.nastrings);	
	}
	
	//truestrings
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_truestrings);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.truestrings=g_strconcat(",truestrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_truestrings),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.truestrings,NULL);
		g_free(Pallet_Read_Data.truestrings);
	}
	
	//falsestrings
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_falsestrings);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.falsestrings=g_malloc(g_strconcat(",falsestrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_falsestrings),"]",NULL));
		Pallet_Read_Data.falsestrings=g_strconcat(",falsestrings=[",gtk_entry_get_text(Pallet_Read_Data.entry_falsestrings),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.falsestrings,NULL);
		g_free(Pallet_Read_Data.falsestrings);
	}
	
	//makefactors
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_makefactors);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.makefactors=g_strconcat(",makefactors=",toggle_button_active_str[Pallet_Read_Data.toggle_button_active],NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.makefactors,NULL);
		g_free(Pallet_Read_Data.makefactors);
	}
	
	//nrows
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_nrows);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.nrows=g_strconcat(",nrows=",gtk_entry_get_text(Pallet_Read_Data.entry_nrows),NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.nrows,NULL);
		g_free(Pallet_Read_Data.nrows);
	}
	
	//names
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_names);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.names=g_strconcat(",names=[",gtk_entry_get_text(Pallet_Read_Data.entry_names),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.names,NULL);
		g_free(Pallet_Read_Data.names);
	}
	
	//eltypes
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_eltypes);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.eltypes=g_strconcat(",eltypes=[",gtk_entry_get_text(Pallet_Read_Data.entry_eltypes),"]",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.eltypes,NULL);
		g_free(Pallet_Read_Data.eltypes);
	}
	
	//allowcomments
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_allowcomments);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.allowcomments=g_strconcat(",allowcomments=",toggle_button_active_str[Pallet_Read_Data.toggle_button_active],NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.allowcomments,NULL);
		g_free(Pallet_Read_Data.allowcomments);
	}
	
	//commentmark
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_commentmark);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.commentmark=g_strconcat(",commentmark='",gtk_entry_get_text(Pallet_Read_Data.entry_commentmark),"'",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.commentmark,NULL);
		g_free(Pallet_Read_Data.commentmark);	
	}
	
	//ignorepadding
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_ignorepadding);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.ignorepadding=g_strconcat(",ignorepadding=",toggle_button_active_str[Pallet_Read_Data.toggle_button_active],NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.ignorepadding,NULL);
		g_free(Pallet_Read_Data.ignorepadding);
	}
	
	//skipstart
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_skipstart);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.skipstart=g_strconcat(",skipstart=",gtk_entry_get_text(Pallet_Read_Data.entry_skipstart),NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.skipstart,NULL);
		g_free(Pallet_Read_Data.skipstart);	
	}
	
	//skiprows
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_skiprows);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.skiprows=g_strconcat(",skiprows=",gtk_entry_get_text(Pallet_Read_Data.entry_skiprows),NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.skiprows,NULL);
		g_free(Pallet_Read_Data.skiprows);
	}
	
	//skipblanks
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_skipblanks);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.skipblanks=g_strconcat(",skipblanks=",toggle_button_active_str[Pallet_Read_Data.toggle_button_active],NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.skipblanks,NULL);
		g_free(Pallet_Read_Data.skipblanks);
	}
	
	//encoding
	Pallet_Read_Data.toggle_button_active=gtk_toggle_button_get_active(Pallet_Read_Data.checkbutton_encoding);
	if(Pallet_Read_Data.toggle_button_active==TRUE)
	{
		Pallet_Read_Data.encoding=g_strconcat(",encodings='",gtk_entry_get_text(Pallet_Read_Data.entry_encoding),"'",NULL);
		Pallet_Read_Data.script1 =g_strconcat(Pallet_Read_Data.script1,Pallet_Read_Data.encoding,NULL);
		g_free(Pallet_Read_Data.encoding);
	}
	

	//finish
	Pallet_Read_Data.script1=g_strconcat(Pallet_Read_Data.script1,");\n",NULL);
	(Pallet_Read_Data.process_check_flag1) =TRUE;

	gtk_widget_destroy((Pallet_Read_Data.function_window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Read_Textfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function1_for_terminal(GtkWidget *widget, gpointer data)
{
  create_ReadText_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Textfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);
    
  if((Pallet_Read_Data.process_check_flag1)==TRUE)
  {
    Vte_terminal_insert(&VTE[VTE_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.process_check_flag1)=FALSE;

}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Read_Textfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function1_for_editor(GtkWidget *widget, gpointer data)
{
  create_ReadText_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Textfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);
   
  if((Pallet_Read_Data.process_check_flag1)==TRUE)
  {
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.process_check_flag1)=FALSE;

}

