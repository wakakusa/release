/*ヘッダーの読み込み順番でエラーが発生するため、注意すること*/
#include "headers.h"
#include "defines.h"
#include "UserInterfaceFile.h"
#include "kuikjulia_window.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"

/* For testing propose use the local (not installed) ui file */
/* #define UI_FILE PACKAGE_DATA_DIR"/sample/ui/sample.ui" */
/* gladeでuiファイルを新規作成する場合、可視性が「いいえ」になっていることを確認すること*/

int main(int argc, char *argv[])
{
  /* Gtkの初期化*/
  gtk_init(&argc,&argv); 
  gchar Management_No[3];//管理番号処理のための変数
  SCRIPTEDITOR_No_HighWaterMark=0;//SCRIPTEDITOR_No_HighWaterMarkの初期化
  SCRIPTEDITOR_No=0;//SCRIPTEDITOR_Noの初期化

  VTE_No_HighWaterMark=0;//VTE_No_HighWaterMarkの初期化
  VTE_No=0;//VTE_Noの初期化

  
  /* windowの表示 */
  create_kuikjulia_MainWindow(&MainWindow,UserInterfaceFile1,"kuikjulia_MainWindow");
  gtk_widget_show_all((MainWindow.window1)); 
  
  
  /*仮想端末の表示 */
  INI_PATH=g_strconcat(getenv("HOME"),"/.kuikjulia/ini/kuikjulia.ini",NULL);
  
  //ファイルの存在チェック
  if(fopen(INI_PATH, "r") == NULL)
  {
  	mkdir(g_strconcat(getenv("HOME"),"/.kuikjulia/",NULL),0775 );
  	mkdir(g_strconcat(getenv("HOME"),"/.kuikjulia/ini",NULL),0775 );
  	exe_enviroment_save(INI_PATH);
  	printf("Please Edit ~/.kuikjulia/ini/kuikjulia.ini\n");
//    printf("file open error!!\nPlease run \"cp ./ini.sample/kuikjulia.ini ~/.kuikjulia/ini/kuikjulia.ini\"");
//    exit(EXIT_FAILURE);	/* (3)エラーの場合は通常、異常終了する */
  }
  
  exe_enviroment_load(INI_PATH);
  create_vte_window(&VTE[0],UserInterfaceFile2);
	/*VTE_No_HighWaterMarkを格納しどのウィンドを最終的にアクティブにしたか把握できるようにする*/
	sprintf(Management_No,"%d",VTE_No_HighWaterMark);
	gtk_label_set_text( VTE[VTE_No_HighWaterMark].Management_VTE_No , Management_No );

  gtk_widget_show_all((VTE[0].window1)); 

  /*テキストエディタの表示 */
  create_script_editor(&SCRIPTEDITOR[0],UserInterfaceFile3,"scriptEditor");
	/*SCRIPTEDITOR_No_HighWaterMarkを格納しどのウィンドを最終的にアクティブにしたか把握できるようにする*/
	sprintf(Management_No,"%d",SCRIPTEDITOR_No_HighWaterMark);
	gtk_label_set_text( SCRIPTEDITOR[SCRIPTEDITOR_No_HighWaterMark].Management_SCRIPTEDITOR_No , Management_No );

  gtk_widget_show_all((SCRIPTEDITOR[0].window1)); 
  SCRIPTEDITOR_No_HighWaterMark++;//SCRIPTEDITOR_No_HighWaterMarkのカウントアップ

  /*windowの開始位置を指定*/
  gtk_window_move (MainWindow.window1,0,0);
  gtk_window_move (VTE[0].window1,0,70);
  gtk_window_move (SCRIPTEDITOR[0].window1,743,70);
  
  /* イベントループ開始 */
  gtk_main(); 
 
  return 0;
}

