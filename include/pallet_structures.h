/******************************************************************************
 * Title:Pallet Structure 
 * summary:Palletの構造体内容を定義
 * 
 *LastUpdate: 
******************************************************************************/

/*Palletの構造体内容を定義*/
typedef struct {
	GtkWidget *pallet_window,*window1;	//
	gchar *file1;	//set file name
	GtkTextBuffer *textbuf1;	//
	gchar *buf1;	//
	gchar *script1;				// script of command
	gchar script2[1024];	// script of command
	gsize size1;	//
	gint OK_flag;//OK button clicked
	gint proc_flag1,flag1 ,flag2;	//proc_flag1:OK button clicked
	gint check_button1_flag,check_button2_flag,check_button3_flag;//
	GtkCheckButton *check_button1,*check_button2,*check_button3;//
	GtkEntry *entry1,*entry2,*entry3,*entry4,*entry5,*entry6;//
	gchar object_name[258];//common
	gchar header_flag1[2],header_flag2[2],header_flag3[2],TF_flag1[6],TF_flag2[6],TF_flag3[6];//common flag
	gchar separator[5],skip[130],comment_char[258],row_names[258],dec[3];// for text read/write option
	gchar sheet_name[258],start_row[14],start_col[14];//for excel read/write option
}StructPalletWidget;

/*構造体変数名を宣言*/
StructPalletWidget Pallet_Master; 

StructPalletWidget Pallet_Filesystem;
StructPalletWidget Pallet_Read_Data;
StructPalletWidget Pallet_Write_Data;
StructPalletWidget Pallet_Test;
StructPalletWidget Pallet_Essentials;


