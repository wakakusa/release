#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

/**********************************************************************************************
 * function10:JLDファイルへ dataの書き込み関数定義。 
 * 
 **********************************************************************************************/


/**********************************************************************************************
 * function:データ読み込み用ダイアログ表示callback関数。 
 * 
 * 
 * glade:Write_JLD_filechooserdialog
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
 * glade:Write_HDF5_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function10_for_terminal(GtkWidget *widget, gpointer data)
{
//  create_Write_JLD_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_JLD_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.function_window1));
  gtk_widget_destroy(Pallet_Write_Data.function_window1);

  if((Pallet_Write_Data.process_check_flag1) ==TRUE)
  {
	Vte_terminal_insert(&VTE[VTE_No],Pallet_Write_Data.script1);
	g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.process_check_flag1) =FALSE;
}

/*****************************************************************************************************
 * function:エディタ用処理
 * 
 * 
 * glade:Write_HDF5_filechooserdialog
*****************************************************************************************************/
G_MODULE_EXPORT void cb_write_data_function10_for_editor(GtkWidget *widget, gpointer data)
{
//  create_Write_JLD_filechooserdialog(&Pallet_Write_Data,PalletInterfaceFile03,"Write_JLD_filechooserdialog");
  gtk_dialog_run(GTK_DIALOG(Pallet_Write_Data.function_window1));
  gtk_widget_destroy(Pallet_Write_Data.function_window1);

  if((Pallet_Write_Data.process_check_flag1) ==TRUE)
  {
	  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],Pallet_Write_Data.script1);
	  g_free( Pallet_Write_Data.script1 );
  }
  
  (Pallet_Write_Data.process_check_flag1) =FALSE;
}
