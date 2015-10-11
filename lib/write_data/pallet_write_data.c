#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/**********************************************************************************************
 * write_dataの共通関数定義。 
 * 
 **********************************************************************************************/

/*****************************************************************************************************
 * function:Palletを表示するためのcallback関数
 * 
 * 
 * 
 * glade:Pallet_Write_Data
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Pallet_Write_Data( GtkImageMenuItem *pallet_test, gpointer user_data ) 
{
	(Pallet_Write_Data.process_check_flag1) =FALSE;
	create_pallet(&Pallet_Write_Data,PalletInterfaceFile03,"Pallet_Write_Data");
    /* windowの表示 */
	gtk_widget_show_all((Pallet_Write_Data.pallet_window)); 
} 


/*****************************************************************************************************
 * function:ファイル選択ダイアログをcabcelで閉じる
 * 
 * 
 * glade:none
*****************************************************************************************************/
G_MODULE_EXPORT void Pallet_Write_Data_chooserdialog_Cancel(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy((Pallet_Write_Data.function_window1)); 
}

