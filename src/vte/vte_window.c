#include "headers.h"
#include "defines.h"
#include "UserInterfaceFile.h"
#include "vte_window_structures.h"

/**********************************************************************************************
 * VTEの基本関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:VTE Windowを作成するためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/

int create_vte_window(StructVTEWidget *Struct_Widget,char UI_FILE[PATH_LENGTH])
{
  
  Struct_Widget->argva =NULL;
  Struct_Widget->Err=NULL;


#ifdef ENABLE_NLS
   bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
   bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
   textdomain (GETTEXT_PACKAGE);
#endif
   
  GtkBuilder *builder;
  GError* error = NULL;
  
  /* GtkBuilder作成 */
  builder = gtk_builder_new(); 
  
  /* UI_FILEの読み込み*/
  if (!gtk_builder_add_from_file (builder, UI_FILE, &error))
  {
	g_warning ("Couldn't load builder file: %s", error->message);
	g_error_free (error);
//	return 1;
  }

 
  /* windowのオブジェクト取得 */
  (Struct_Widget->window1) = GTK_WIDGET( gtk_builder_get_object(builder, "VTE_MainWindow")); 
  /*複数のウィジェットを操作する場合、構造体に格納にすること。
   * 格納先にあわせて、GTK_LABELやGTK_ENTRYなどGTK_～を変更すること。
   *不明な場合はGTK_WIDGETでも可能。ただしエラーは出力される。*/
      (Struct_Widget->terminal1) =  VTE_TERMINAL(gtk_builder_get_object(builder, "terminal1"));  
      (Struct_Widget->Management_VTE_No )= GTK_LABEL( gtk_builder_get_object(builder, "vte_VTE_No") );
  
  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &Struct_Widget); 

   g_object_unref( G_OBJECT( builder ) );
   
    
   g_shell_parse_argv(EXE_ENVIROMENT.BIN_PATH, NULL, &Struct_Widget->argva, NULL);
   //hint https://github.com/geany/geany/issues/336
	vte_terminal_spawn_sync(
				  VTE_TERMINAL(Struct_Widget->terminal1),//a VteTerminal
				  0,//flags from VtePtyFlags
  				  NULL,//the name of a directory the command should start in, or NULL to use the current working directory.
				  Struct_Widget->argva,//child's argument vector. [array zero-terminated=1][element-type filename]
				  NULL, //a list of environment variables to be added to the environment before starting the process, or NULL. [allow-none][array zero-terminated=1][element-type filename]
				  0, //flags from GSpawnFlags
				  NULL, //function to run in the child just before exec(), or NULL. [allow-none][scope call]
				  NULL, //user data for child_setup
				  NULL, //a location to store the child PID, or NULL. [out][allow-none][transfer full]
				  NULL, //cancellable
				  &Struct_Widget->Err//return location for a GError, or NULL. [allow-none]
				 );
	
/*   vte_terminal_feed(
				  VTE_TERMINAL(Struct_Widget->terminal1),//a VteTerminal
				  Struct_Widget->argva,//child's argument vector. [array zero-terminated=1][element-type filename]
				 -1);
	
   vte_terminal_feed_child( VTE_TERMINAL(Struct_Widget->terminal1), EXE_ENVIROMENT.BIN_PATH ,-1 );
*/
   g_strfreev(Struct_Widget->argva);
  
   return 0;
}


/**********************************************************************************************
 * function:kuikjuliaを起動する際、VTEを同時起動。 
 * 
 * 
 * glade:VTE_MainWindow
 **********************************************************************************************/

G_MODULE_EXPORT void start_vte(GtkWidget *widget, gpointer data)
{
  create_vte_window(&VTE[VTE_No_HighWaterMark],UserInterfaceFile2);
  
  /*SCRIPTEDITOR_No_HighWaterMarkを格納しどのウィンドを最終的にアクティブにしたか把握できるようにする*/
  gchar Management_No[3];
  sprintf(Management_No,"%d",VTE_No_HighWaterMark);
  gtk_label_set_text( VTE[VTE_No_HighWaterMark].Management_VTE_No , Management_No );
  
  gtk_widget_show_all((VTE[VTE_No_HighWaterMark].window1)); 
  VTE_No_HighWaterMark++;//VTE_Noのカウントアップ
}


/**********************************************************************************************
 * function:VTE管理番号を取得 
 * 
 * 
 * glade:scriptEditor
 **********************************************************************************************/
G_MODULE_EXPORT void Get_Management_VTE_No(GtkLabel *vte_VTE_No)
{
  VTE_No=atoi( gtk_label_get_text( vte_VTE_No ) );
  sleep(0);
}


/**********************************************************************************************
 * function:kuikjuliaを終了する際、どのように終了するかコマンドを送信。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
G_MODULE_EXPORT void vte_quit(GtkWidget *widget, gpointer data)
{
  //終了コマンドを送信
  vte_terminal_feed_child(VTE[VTE_No].terminal1,"exit()\n",-1);
} 
