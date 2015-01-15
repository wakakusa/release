#include "headers.h"
#include "defines.h"
#include "UserInterfaceFile.h"
#include "kuikjulia_window.h"

/**********************************************************************************************
 * aboutdialogの定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:アバウトダイアログを作成するためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
void create_aboutDialog_window(StructWindowWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
//  (struct_widget->Button1) = GTK_ENTRY(gtk_builder_get_object(builder, "button1"));

  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 

   g_object_unref( G_OBJECT( builder ) );
}


/**********************************************************************************************
 * function:アバウトダイアログを表示するためのcallback関数。 
 * 
 * 
 * glade:aboutdialog
 **********************************************************************************************/
G_MODULE_EXPORT void cb_aboutDialog( GtkImageMenuItem *aboutdialog, gpointer user_data ) 
{
  create_aboutDialog_window(&AboutDialog,UserInterfaceFile1,"aboutdialog");
  gtk_dialog_run( GTK_DIALOG( AboutDialog.window1 ) );
  gtk_widget_destroy( AboutDialog.window1 );
}
