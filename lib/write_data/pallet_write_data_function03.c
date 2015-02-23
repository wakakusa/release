#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

/**********************************************************************************************
 * function3:TXTファイルへ dataの書き込み関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Write_txt_filechooserdialog
 **********************************************************************************************/
void create_Write_Txt_filechooserdialog(StructPalletWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
   (struct_widget->entry1) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Write_CSV_filechooserdialog_entry1"));
   (struct_widget->check_button1) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Write_CSV_filechooserdialog_checkbutton1"));
   (struct_widget->check_button2) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Write_CSV_filechooserdialog_checkbutton2"));

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
  //保存先ファイル名を取得
  (Pallet_Write_Data.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Write_Data.window1));

  //オブジェクト名取得
  sprintf(Pallet_Write_Data.object_name, "%s", gtk_entry_get_text(Pallet_Write_Data.entry1));
 
  //checkbuttonの確認
  //処理用共通変数
  gboolean toggle_button_active;
  gchar *toggle_button_active_str[]={"FALSE","TRUE"};  
  
  /*written row.names 制御*/
  toggle_button_active=gtk_toggle_button_get_active(Pallet_Write_Data.check_button1);
  sprintf(Pallet_Write_Data.TF_flag1,toggle_button_active_str[toggle_button_active]);
  
  /*written col.names 制御*/
  toggle_button_active=gtk_toggle_button_get_active(Pallet_Write_Data.check_button2);
  sprintf(Pallet_Write_Data.TF_flag2,toggle_button_active_str[toggle_button_active]);

  Pallet_Write_Data.script1 =g_strconcat("writetable(",Pallet_Write_Data.object_name,",file=\"",Pallet_Write_Data.file1,"\",row.names=",Pallet_Write_Data.TF_flag1,",col.names=",Pallet_Write_Data.TF_flag2,");\n",NULL);
  (Pallet_Write_Data.proc_flag1) =TRUE;

  gtk_widget_destroy((Pallet_Write_Data.window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Write_CSV_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function3_for_terminal(GtkWidget *widget, gpointer data)
{
  create_Write_CSV_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_Txt_filechooserdialog");
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
 * glade:Write_CSV_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function1_for_editor(GtkWidget *widget, gpointer data)
{
  create_Write_CSV_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_Txt_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.window1));
  gtk_widget_destroy(Pallet_Write_Data.window1);

  if((Pallet_Write_Data.proc_flag1) ==TRUE)
  {
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Write_Data.script1);
	  g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.proc_flag1) =FALSE;
}

