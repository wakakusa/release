#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * read_dataの共通関数定義。 
 * 
 **********************************************************************************************/

/*****************************************************************************************************
 * function:Palletを表示するためのcallback関数
 * 
 * 
 * 
 * glade:Pallet_Read_Data
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Pallet_Read_Data( GtkImageMenuItem *pallet_test, gpointer user_data ) 
{
  (Pallet_Read_Data.process_check_flag1) =FALSE;
  create_pallet(&Pallet_Read_Data,PalletInterfaceFile02,"Pallet_Read_Data");
    /* windowの表示 */
  gtk_widget_show_all((Pallet_Read_Data.pallet_window)); 
} 


/*****************************************************************************************************
 * function:ファイル選択ダイアログをcabcelで閉じる
 * 
 * 
 * glade:none
*****************************************************************************************************/
G_MODULE_EXPORT void Pallet_Read_Data_filechooserdialog_Cancel(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy((Pallet_Read_Data.pallet_window)); 
}

