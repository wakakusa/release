#include "headers.h"
#include "defines.h"
#include "pallet_structures.h"
#include "vte_window_structures.h"
#include "script_editor_window_structures.h"
#include "pallet_defines.h"

#define script01 "x=1:10\n"
#define script02 "y=2:2:20\n"
#define script03 "x\n"
#define script04 "y\n"
#define script05 "using Gadfly\n"
#define script06 "plot(x=x,y=y)\n"
#define script07 ""
#define script08 ""
#define script09 "versioninfo()\n"
#define script10 "help()\n"

  
/*Pallet_Testを表示するためのcallback関数*/
G_MODULE_EXPORT void cb_Pallet_Test( GtkImageMenuItem *pallet_test, gpointer user_data ) 
{
  create_pallet(&Pallet_Test,PalletInterfaceFile99,"Pallet_Test");
    /* windowの表示 */
  gtk_widget_show_all((Pallet_Test.pallet_window)); 
} 

/*function for terminal*/
G_MODULE_EXPORT void cb_function1_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script01);
}

G_MODULE_EXPORT void cb_function2_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script02);
}

G_MODULE_EXPORT void cb_function3_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script03);
}

G_MODULE_EXPORT void cb_function4_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script04);
}

G_MODULE_EXPORT void cb_function5_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script05);
}

G_MODULE_EXPORT void cb_function6_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script06);
}

G_MODULE_EXPORT void cb_function7_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script07);
}

G_MODULE_EXPORT void cb_function8_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script08);
}

G_MODULE_EXPORT void cb_function9_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script09);
}

G_MODULE_EXPORT void cb_function10_for_terminal(GtkWidget *widget, gpointer data)
{
  Vte_terminal_insert(&VTE[VTE_No],script10);
}

/*function for text editor*/

//StructRSCRIPTEDITORWidget RSCRIPTEDITOR[RSCRIPTEDITOR_No];

G_MODULE_EXPORT void cb_function1_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script01);
}

G_MODULE_EXPORT void cb_function2_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script02);
}

G_MODULE_EXPORT void cb_function3_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script03);
}

G_MODULE_EXPORT void cb_function4_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script04);
}

G_MODULE_EXPORT void cb_function5_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script05);
}

G_MODULE_EXPORT void cb_function6_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script06);
}

G_MODULE_EXPORT void cb_function7_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script07);
}

G_MODULE_EXPORT void cb_function8_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script08);
}

G_MODULE_EXPORT void cb_function9_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script09);
}

G_MODULE_EXPORT void cb_function10_for_editor(GtkWidget *widget, gpointer data)
{
  ScriptEditor_insert(&SCRIPTEDITOR[SCRIPTEDITOR_No],script10);
}
