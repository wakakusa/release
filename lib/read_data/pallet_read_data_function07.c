#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * read_data function7の関数定義。 
 * sasb7dat
 **********************************************************************************************/


/**********************************************************************************************
 * function:Excelファイル読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Read_sasb7datfile_chooserdialog
 **********************************************************************************************/



/**********************************************************************************************
 * function:ファイル選択ダイアログをOKで閉じ、処理する 
 * 
 * 
 * glade:none
 **********************************************************************************************/


/*****************************************************************************************************
 * function:ターミナル用処理
 * 
 * 
 * glade:Read_sasb7datfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function7_for_terminal(GtkWidget *widget, gpointer data)
{
  create_ReadText_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Textfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);
    
  if((Pallet_Read_Data.process_check_flag1)==TRUE)
  {
    Vte_terminal_insert(&VTE[VTE_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.process_check_flag1)=FALSE;

}


/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Read_sasb7datfile_chooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_read_data_function7_for_editor(GtkWidget *widget, gpointer data)
{
  create_ReadText_filechooserdialog(&Pallet_Read_Data,PalletInterfaceFile02,"Read_Textfile_chooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Read_Data.function_window1));
  gtk_widget_destroy(Pallet_Read_Data.function_window1);
   
  if((Pallet_Read_Data.process_check_flag1)==TRUE)
  {
    ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No], Pallet_Read_Data.script1 );
    g_free( Pallet_Read_Data.script1 );
  }
  (Pallet_Read_Data.process_check_flag1)=FALSE;

}


