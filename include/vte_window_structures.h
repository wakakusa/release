/******************************************************************************
 * Title:VTE Structure 
 * summary:VTEの構造体を指定
 * 
 *LastUpdate: 
******************************************************************************/
#define VTE_No_MAX 50

gint VTE_No_HighWaterMark;
gint VTE_No;
gchar *INI_PATH;//設定ファイルのパス

/*VTEの構造体を定義*/
typedef struct {
   GtkWidget *window1;
   GtkWidget *scrollview;
   char** argva ;   
   GError* Err ;
   VteTerminal* terminal1;
   GtkLabel *Management_VTE_No;
}StructVTEWidget;

/*構造体変数名を宣言*/
  StructVTEWidget VTE[VTE_No_MAX];

/*VTEの環境変数を格納する構造体を定義*/
typedef struct {
	GtkWidget *window1;
	GtkWidget *scrollview;
	char** argva ;   
	GError* Err ;

	GtkCheckButton *check_button011,*check_button012,*check_button013,*check_button014,*check_button015;//
	GtkEntry *entry011;
	GtkFileChooser *filechooserbutton011,*filechooserbutton012;

	gchar *BIN_PATH;
	gchar BIN_FILE_PATH[PATH_LENGTH];
	gint Flag_home;
	gchar START_WORKING_DIRECTORY[PATH_LENGTH];
	gint Flag_process;
	gchar process[4];
	gint Flag_history;
	gint Flag_startup;
	gint Flag_quiet;
}StructEXE_EnvironmentWidget;

/*構造体変数名を宣言*/
  StructEXE_EnvironmentWidget EXE_ENVIROMENT;
