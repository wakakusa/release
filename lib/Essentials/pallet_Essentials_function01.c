#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * function1:sample関数定義。 
 * 
 **********************************************************************************************/
/*****************************************************************************************************
 * function:ダイアログ作成
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
void create_pallet1(StructPalletWidget *struct_widget,char UI_FILE[256],char Window_name[512])
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
  (struct_widget->check_button1) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_checkbutton1"));
  (struct_widget->check_button2) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_checkbutton2"));
  (struct_widget->check_button3) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_checkbutton3"));
  (struct_widget->entry1) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_entry1"));
  (struct_widget->entry2) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_entry2"));
  (struct_widget->entry3) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_entry3"));
  (struct_widget->entry4) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_entry4"));
  (struct_widget->entry5) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_entry5"));
  (struct_widget->entry6) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "Pallet_Essentials_filechooserdialog1_entry6"));

  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 

   g_object_unref( G_OBJECT( builder ) );
}

/*ファイル選択ダイアログをOKで閉じ、処理する*/
G_MODULE_EXPORT void Pallet_Essentials_filechooserdialog1_FileOpen_OK (GtkWidget *widget,gpointer data  )
{
 
 
  (Pallet_Essentials.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Essentials.window1));
  
  sprintf(Pallet_Essentials.header_flag1,"F");
  
  if(gtk_toggle_button_get_active(Pallet_Essentials.check_button1)==TRUE)
  {
	  sprintf(Pallet_Essentials.header_flag1,"T");
  }


  //checkbuttonの確認
  //処理用共通変数
  gboolean toggle_button_active;
  gchar *toggle_button_active_str[]={"FALSE","TRUE"};

  /*row.names 制御*/
  toggle_button_active=gtk_toggle_button_get_active(Pallet_Essentials.check_button2);
  Pallet_Essentials.flag2=g_strcmp0 ( "TRUE" , toggle_button_active_str[toggle_button_active] ) ;
  g_print("\nrow.names=%s",Pallet_Essentials.flag2);
  
  
  sprintf(Pallet_Essentials.object_name, "%s", gtk_entry_get_text(Pallet_Essentials.entry1));//オブジェクト名取得
  sprintf(Pallet_Essentials.separator, "%s", gtk_entry_get_text(Pallet_Essentials.entry2));//セパレータ取得
  sprintf(Pallet_Essentials.skip, "%s", gtk_entry_get_text(Pallet_Essentials.entry3));//スキップ行数
  sprintf(Pallet_Essentials.comment_char, "%s", gtk_entry_get_text(Pallet_Essentials.entry4));//オブジェクト名取得
  sprintf(Pallet_Essentials.row_names, "%s", gtk_entry_get_text(Pallet_Essentials.entry5));//オブジェクト名取得
  sprintf(Pallet_Essentials.dec, "%s", gtk_entry_get_text(Pallet_Essentials.entry6));//オブジェクト名取得
  
  (Pallet_Essentials.script1) = g_strconcat("setwd(\"",Pallet_Essentials.file1,"\")\n",NULL);
  (Pallet_Essentials.proc_flag1) =TRUE;

  
  gtk_widget_destroy((Pallet_Essentials.window1)); 
}

/*****************************************************************************************************
 * function:ファイル選択ダイアログをOKで閉じ、処理する
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void create_workdirectory_chooserdialog_FileOpen_OK (GtkWidget *widget,gpointer data  )
{

  (Pallet_Essentials.file1) = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(Pallet_Essentials.window1));

  (Pallet_Essentials.script1) = g_strconcat("setwd(\"",Pallet_Essentials.file1,"\")\n",NULL);
  
  (Pallet_Essentials.proc_flag1) =TRUE;
  gtk_widget_destroy((Pallet_Essentials.window1)); 
}


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Essentials_function1_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],Pallet_Essentials.script1);
  g_free(Pallet_Essentials.script1);
  (Pallet_Essentials.proc_flag1) =FALSE;
}

/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:workdirectory_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Essentials_function1_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Essentials.script1);
  g_free(Pallet_Essentials.script1);
  (Pallet_Essentials.proc_flag1) =FALSE;
}