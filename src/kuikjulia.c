#include "headers.h"
#include "defines.h"
#include "UserInterfaceFile.h"
#include "kuikjulia_window.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"


/**********************************************************************************************
 * kuikjulia本体の関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:kuikjulia_Mainの表示関数のcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
void create_kuikjulia_MainWindow(StructWindowWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
 * function:kuikjuliaを終了する際、どのように終了するかコマンドを送信。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void kuikjulia_quit(GtkWidget *widget, gpointer data)
{
  gchar send_command[5];
  //終了コマンドを送信
  vte_terminal_feed_child(VTE[VTE_No].terminal1,"exit(0)\n",-1);

  //データを保存するかどうか
/*  g_sprintf(send_command,"%s\n",EXE_ENVIROMENT.Save_workspace_image);
  vte_terminal_feed_child(VTE1.terminal1,send_command,-1);
*/
  //アプリ終了
  gtk_main_quit();
} 


