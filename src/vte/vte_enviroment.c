#include "headers.h"
#include "defines.h"
#include "UserInterfaceFile.h"
#include "vte_window_structures.h"

/**********************************************************************************************
 * VTEの環境設定関数定義。 
 * 
 **********************************************************************************************/
extern int exe_enviroment_load(char INI_FILE[PATH_LENGTH]);
extern int exe_enviroment_save(char INI_FILE[PATH_LENGTH]);

/**********************************************************************************************
 * function:EXE_Environmentを作成するためのcallback関数。 
 * 
 * 
 * glade:kuikjuka
 **********************************************************************************************/ 
void create_VTE_Enviroment(StructEXE_EnvironmentWidget *struct_widget,char UI_FILE[PATH_LENGTH],char Window_name[512])
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
	(struct_widget->filechooserbutton011) = GTK_FILE_CHOOSER(gtk_builder_get_object(builder, "EXE_Enviroment_filechooserbutton011"));
	(struct_widget->filechooserbutton012) = GTK_FILE_CHOOSER(gtk_builder_get_object(builder, "EXE_Enviroment_filechooserbutton012"));
	(struct_widget->check_button011) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "EXE_Enviroment_checkbutton011"));
	(struct_widget->check_button012) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "EXE_Enviroment_checkbutton012"));
	(struct_widget->check_button013) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "EXE_Enviroment_checkbutton013"));
	(struct_widget->check_button014) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "EXE_Enviroment_checkbutton014"));
	(struct_widget->check_button015) = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "EXE_Enviroment_checkbutton015"));
	(struct_widget->entry011)	 = GTK_ENTRY(gtk_builder_get_object(builder, "EXE_Enviroment_entry011"));

  /* UI_FILEのシグナルハンドラの設定  This is important */
  gtk_builder_connect_signals (builder, &struct_widget); 
 
   g_object_unref( G_OBJECT( builder ) );

   
     /*現在の設定値を読み込み表示*/
    gtk_file_chooser_set_filename  (struct_widget->filechooserbutton011 , EXE_ENVIROMENT.BIN_FILE_PATH);
    gtk_toggle_button_set_active(EXE_ENVIROMENT.check_button011 , EXE_ENVIROMENT.Flag_home);
    gtk_file_chooser_set_current_name(struct_widget->filechooserbutton012 , EXE_ENVIROMENT.BIN_PATH);
    gtk_toggle_button_set_active(EXE_ENVIROMENT.check_button012 , EXE_ENVIROMENT.Flag_process);
    gtk_entry_set_text (struct_widget->entry011 , EXE_ENVIROMENT.process);
    gtk_toggle_button_set_active(EXE_ENVIROMENT.check_button013 , EXE_ENVIROMENT.Flag_history);
    gtk_toggle_button_set_active(EXE_ENVIROMENT.check_button014 , EXE_ENVIROMENT.Flag_startup);
    gtk_toggle_button_set_active(EXE_ENVIROMENT.check_button015 , EXE_ENVIROMENT.Flag_quiet);
}


/**********************************************************************************************
 * function:EXE_Environmentを表示するためのcallback関数。 
 * 
 * 
 * glade:kuikjuka
 **********************************************************************************************/ 
G_MODULE_EXPORT void cb_VTE_Enviroment( GtkImageMenuItem *pallet_test, gpointer user_data ) 
{
  create_VTE_Enviroment(&EXE_ENVIROMENT,UserInterfaceFile1,"EXE_Enviroment");
    /* windowの表示 */
  gtk_widget_show_all((EXE_ENVIROMENT.window1)); 
} 


/**********************************************************************************************
 * function:EXE_Environmentの処理をキャンセルするためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/ 
G_MODULE_EXPORT void EXE_Environment_Cancel(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy((EXE_ENVIROMENT.window1)); 
}


/**********************************************************************************************
 * function:EXE_Environmentの処理をするためのcallback関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/ 
G_MODULE_EXPORT void EXE_Environment_Ok(GtkWidget *widget, gpointer data)
{
  exe_enviroment_save(INI_PATH);
  gtk_widget_destroy((EXE_ENVIROMENT.window1));
}


/**********************************************************************************************
 * function:VTEで起動するためのパラメータを呼び出す読み込む関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
extern int exe_enviroment_load(char INI_FILE[PATH_LENGTH])
{
  
	FILE *fp;
	gchar enviroments[PATH_LENGTH],Dummy[PATH_LENGTH];

	if ((fp = fopen(INI_FILE, "r")) == NULL)
	{
		printf("kuikjulia.ini file open error!!\n");
	}
	
	/*read enviroment ini file*/
	g_free(EXE_ENVIROMENT.BIN_PATH);
	memset(EXE_ENVIROMENT.BIN_FILE_PATH,0,PATH_LENGTH);

	/* bin file path*/
	fscanf(fp,"%s %s",&Dummy,&EXE_ENVIROMENT.BIN_FILE_PATH);
	EXE_ENVIROMENT.BIN_PATH=g_strdup (EXE_ENVIROMENT.BIN_FILE_PATH);
	//strcpy(EXE_ENVIROMENT.BIN_PATH,EXE_ENVIROMENT.BIN_FILE_PATH);

	/*working directory*/
	fscanf(fp,"%s %d %s",&Dummy,&EXE_ENVIROMENT.Flag_home,&EXE_ENVIROMENT.START_WORKING_DIRECTORY);

	if(EXE_ENVIROMENT.Flag_home==TRUE)
	{
		EXE_ENVIROMENT.BIN_PATH=g_strconcat(EXE_ENVIROMENT.BIN_PATH," -H ",EXE_ENVIROMENT.START_WORKING_DIRECTORY,NULL);
	}

	/*process*/
	fscanf(fp,"%s %d %s",&Dummy,&EXE_ENVIROMENT.Flag_process,&EXE_ENVIROMENT. process);
	if(atoi(EXE_ENVIROMENT.process)<0)  {	g_sprintf(EXE_ENVIROMENT.process,"1");		}
	if(EXE_ENVIROMENT.Flag_process==TRUE)
	{
		sprintf(Dummy,"%s",EXE_ENVIROMENT.process);
		EXE_ENVIROMENT.BIN_PATH=g_strconcat(EXE_ENVIROMENT.BIN_PATH," -p ",EXE_ENVIROMENT.process,NULL);
	}

	/*no_history*/
	fscanf(fp,"%s %d",&Dummy,&EXE_ENVIROMENT.Flag_history);
	if(EXE_ENVIROMENT.Flag_history==TRUE)
	{
		EXE_ENVIROMENT.BIN_PATH=g_strconcat(EXE_ENVIROMENT.BIN_PATH," --no-history-file",NULL);
	}

	/*startup*/
	fscanf(fp,"%s %d",&Dummy,&EXE_ENVIROMENT.Flag_startup);
	if(EXE_ENVIROMENT.Flag_startup==TRUE)
	{
		EXE_ENVIROMENT.BIN_PATH=g_strconcat(EXE_ENVIROMENT.BIN_PATH," -f",NULL);
	}

	/*quiet*/
	fscanf(fp,"%s %d",&Dummy,&EXE_ENVIROMENT.Flag_quiet);
	if(EXE_ENVIROMENT.Flag_quiet==TRUE)
	{
		EXE_ENVIROMENT.BIN_PATH=g_strconcat(EXE_ENVIROMENT.BIN_PATH," -q",NULL);
	}

	fclose(fp);
	printf("Path is %s\n",EXE_ENVIROMENT.BIN_PATH);

	return 0;
}


/**********************************************************************************************
 * function:VTEで起動するためのパラメータを書き出す関数。 
 * 
 * 
 * glade:none
 **********************************************************************************************/
extern int exe_enviroment_save(char INI_FILE[PATH_LENGTH])
{
	FILE *fp;

	if ((fp = fopen(INI_FILE, "w")) == NULL)
	{
		printf("kuikjulia.ini file open error!!\n");
	}
	
	/* bin file path*/
	g_sprintf (EXE_ENVIROMENT.BIN_FILE_PATH,"%s",gtk_file_chooser_get_filename((EXE_ENVIROMENT.filechooserbutton011)));
	fprintf(fp, "#BIN_PATH\n%s\n", EXE_ENVIROMENT.BIN_FILE_PATH);

	/*working directory*/
	EXE_ENVIROMENT.Flag_home=gtk_toggle_button_get_active(EXE_ENVIROMENT.check_button011);
	g_sprintf (EXE_ENVIROMENT.START_WORKING_DIRECTORY,"%s",gtk_file_chooser_get_filename((EXE_ENVIROMENT.filechooserbutton012)));
	fprintf(fp, "#START_WORKING_DIRECTORY\n%d %s\n", EXE_ENVIROMENT.Flag_home , EXE_ENVIROMENT.START_WORKING_DIRECTORY);

	/*process*/
	EXE_ENVIROMENT.Flag_process=gtk_toggle_button_get_active(EXE_ENVIROMENT.check_button012);
	g_sprintf (EXE_ENVIROMENT.process,"%s",gtk_entry_get_text(EXE_ENVIROMENT.entry011));
	fprintf(fp, "#parallel\n%d %s\n", EXE_ENVIROMENT.Flag_process , EXE_ENVIROMENT.process );

	/*no_history*/
	EXE_ENVIROMENT.Flag_history=gtk_toggle_button_get_active(EXE_ENVIROMENT.check_button013);
	fprintf(fp, "#no_history\n%d\n",EXE_ENVIROMENT.Flag_history);

	/*startup*/
	EXE_ENVIROMENT.Flag_startup=gtk_toggle_button_get_active(EXE_ENVIROMENT.check_button014);
	fprintf(fp, "#startup\n%d\n",EXE_ENVIROMENT.Flag_startup);
	
	/*quiet*/
	EXE_ENVIROMENT.Flag_quiet=gtk_toggle_button_get_active(EXE_ENVIROMENT.check_button015);
	fprintf(fp, "#quiet\n%d\n",EXE_ENVIROMENT.Flag_quiet);

	fclose(fp);
	
	return 0;
}


  	
