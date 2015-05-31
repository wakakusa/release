#include "headers.h"
#include "defines.h"
#include "script_editor_window_structures.h"
#include "UserInterfaceFile.h"
#include "vte_window_structures.h"


/**********************************************************************************************
 * Script Editorの基本関数定義。 
 * 
 **********************************************************************************************/
/**
 * 参考HP：http://stackoverflow.com/questions/5133183/c-gtk2-glade3-how-can-i-set-a-sourcebuffer-to-a-gtksourceview-that-was-loaded
**/
/**********************************************************************************************
 * function:Script Editor のWindowを作成するためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
void create_script_editor(StructSCRIPTEDITORWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
{
  GtkBuilder *builder;
  GError* error = NULL;
  gchar header[]="################################################################################\n#Title:\n#Summary:\n#Author:\n#Last Update:\n################################################################################\n\n\n\n\n";

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
  (struct_widget->sourceview1) = GTK_SOURCE_VIEW(gtk_builder_get_object(builder, "script_editor"));
	/* Get the buffer */
//	(struct_widget->sourcebuffer1) = GTK_SOURCE_BUFFER(gtk_builder_get_object(builder, "textbuffer1"));
  ( struct_widget->Management_SCRIPTEDITOR_No )= GTK_LABEL( gtk_builder_get_object(builder, "scriptEditor_SCRIPTEDITOR_No") );


//	gtk_source_buffer_begin_not_undoable_action (struct_widget->sourcebuffer1);
  ( struct_widget->sourcebuffer1 )=GTK_SOURCE_BUFFER(gtk_text_view_get_buffer(GTK_TEXT_VIEW(struct_widget->sourceview1)));
	gtk_text_buffer_set_text(GTK_TEXT_BUFFER(struct_widget->sourcebuffer1), header ,-1);
//	gtk_source_buffer_end_not_undoable_action (struct_widget->sourcebuffer1);


  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 

   g_object_unref( G_OBJECT( builder ) );

}


/**********************************************************************************************
 * function:KuikJuliaを起動する際、KuikJuliaのエディタを同時起動。 
 * 
 * 
 * glade:scriptEditor
 **********************************************************************************************/
G_MODULE_EXPORT void start_script_editor(GtkWidget *widget, gpointer data)
{
  create_script_editor(&SCRIPTEDITOR[SCRIPTEDITOR_No_HighWaterMark],UserInterfaceFile3,"scriptEditor");
 
  /*SCRIPTEDITOR_No_HighWaterMarkを格納しどのウィンドを最終的にアクティブにしたか把握できるようにする*/
  gchar Management_No[3];
  sprintf(Management_No,"%d",SCRIPTEDITOR_No_HighWaterMark);
  gtk_label_set_text( SCRIPTEDITOR[SCRIPTEDITOR_No_HighWaterMark].Management_SCRIPTEDITOR_No , Management_No );
   
  /* windowの表示 */
  gtk_widget_show_all((SCRIPTEDITOR[SCRIPTEDITOR_No_HighWaterMark].window1)); 
  SCRIPTEDITOR_No_HighWaterMark++;//SCRIPTEDITOR_Noのカウントアップ
}


/**********************************************************************************************
 * function:エディタ管理番号を取得 
 * 
 * 
 * glade:scriptEditor
 **********************************************************************************************/
G_MODULE_EXPORT void Get_Management_SCRIPTEDITOR_No(GtkLabel *scriptEditor_SCRIPTEDITOR_No)
{
  SCRIPTEDITOR_No=atoi( gtk_label_get_text( scriptEditor_SCRIPTEDITOR_No ) );
  sleep(0);
}

