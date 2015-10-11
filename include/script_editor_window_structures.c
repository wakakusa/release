/******************************************************************************
 * Title:ScriptEditor Structure define
 * summary:スクリプトエディタの構造体を定義
 * 
 *LastUpdate: 
******************************************************************************/

gint SCRIPTEDITOR_No_HighWaterMark;
gint SCRIPTEDITOR_No;


/*スクリプトエディタの構造体を定義*/
typedef struct {
   GtkWidget *window1;
   GtkWidget *scrollview;
   GtkTextView *textview1;
   gchar *file1;
   GtkTextBuffer *texbuffer1;
   gchar *buf1;
   gsize size1;
   GtkLabel *Management_SCRIPTEDITOR_No;
   GtkSourceView *sourceview1;
   GtkSourceBuffer *sourcebuffer1;
}StructSCRIPTEDITORWidget;

/*構造体変数名を宣言*/
  StructSCRIPTEDITORWidget SCRIPTEDITOR[SCRIPTEDITOR_No_MAX];//SCRIPTEDITOR_No_MAX個のScript Editorに対応

/*スクリプトエディタの上書き保存を管理するための構造体を定義*/
typedef struct {
   GtkWidget *window1;
   gchar *file1;
   GtkTextBuffer *textbuf1;
   gchar *buf1;
   gsize size1;
   gint QuikSave_flag;
}StructSCRIPTEDITOR_OPENSAVE_Widget;  

/*構造体変数名を宣言*/
 StructSCRIPTEDITOR_OPENSAVE_Widget SCRIPT_OpenSave[SCRIPTEDITOR_No_MAX];//SCRIPTEDITOR_No_MAX個のScript Editorに対応
