#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"


/*****************************************************************************************************
 * function:Palletを表示するためのcallback関数
 * 
 * 
 * glade:Pallet_Operation
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Pallet_Basic( GtkImageMenuItem *pallet_test, gpointer user_data ) 
{
  (Pallet_Operation.proc_flag1) =FALSE;
  create_pallet(&Pallet_Operation,PalletInterfaceFile01,"Pallet_Operation");
    /* windowの表示 */
  gtk_widget_show_all((Pallet_Operation.pallet_window)); 
} 

/*****************************************************************************************************
 * function:ファイル選択ダイアログをcabcelで閉じる
 * 
 * 
 * glade:none
*****************************************************************************************************/
G_MODULE_EXPORT void Pallet_Basic_chooserdialog_Cancel(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy((Pallet_Operation.window1)); 
}
