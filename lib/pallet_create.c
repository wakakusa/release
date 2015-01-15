#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"

/**********************************************************************************************
 * メニュー・ボタンだけのパレットを作成 
 * 
 * glade:any
 **********************************************************************************************/
void create_pallet(StructPalletWidget *struct_widget,char UI_FILE[256],char Window_name[512])
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
  (struct_widget->pallet_window) = GTK_WIDGET( gtk_builder_get_object(builder, Window_name)); 
  /*複数のウィジェットを操作する場合、構造体に格納にすること。
   * 格納先にあわせて、GTK_LABELやGTK_ENTRYなどGTK_～を変更すること。
   *不明な場合はGTK_WIDGETでも可能。ただしエラーは出力される。*/
/*  (struct_widget->check_button1) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "checkbutton1"));
  (struct_widget->check_button2) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "checkbutton2"));
  (struct_widget->check_button3) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "checkbutton3"));
  (struct_widget->entry1) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));
  (struct_widget->entry2) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "entry2"));
  (struct_widget->entry3) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "entry3"));
  (struct_widget->entry4) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "entry4"));
  (struct_widget->entry5) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "entry5"));
  (struct_widget->entry6) 		 = GTK_ENTRY(gtk_builder_get_object(builder, "entry6"));

  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 

   g_object_unref( G_OBJECT( builder ) );
}


/**********************************************************************************************
 * send command for vte 
 * 
 * glade:any
 **********************************************************************************************/
void Vte_terminal_insert(StructVTEWidget *struct_widget,gchar *Scripts)
{
  vte_terminal_feed_child(struct_widget->terminal1,Scripts,-1);
}


/**********************************************************************************************
 * send command for script editor 
 * 
 * glade:any
 **********************************************************************************************/
void ScriptEditor_insert(StructSCRIPTEDITORWidget *struct_widget,gchar *Scripts)
{
  gtk_text_buffer_insert_at_cursor(struct_widget->sourcebuffer1,Scripts,-1);
}

