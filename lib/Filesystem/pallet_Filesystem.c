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
 * glade:Pallet_Filesystem
*****************************************************************************************************/
G_MODULE_EXPORT void cb_Pallet_Filesystem( GtkImageMenuItem *pallet_test, gpointer user_data ) 
{
  (Pallet_Filesystem.process_check_flag1) =FALSE;
  create_pallet(&Pallet_Filesystem,PalletInterfaceFile01,"Pallet_Filesystem");
    /* windowの表示 */
  gtk_widget_show_all((Pallet_Filesystem.pallet_window)); 
} 

/*****************************************************************************************************
 * function:ファイル選択ダイアログをcabcelで閉じる
 * 
 * 
 * glade:none
*****************************************************************************************************/
G_MODULE_EXPORT void Pallet_Filesystem_chooserdialog_Cancel(GtkWidget *widget, gpointer data)
{
  gtk_widget_destroy((Pallet_Filesystem.function_window1)); 
}
