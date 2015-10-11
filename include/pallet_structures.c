/******************************************************************************
 * Title:Pallet Structure 
 * summary:Palletの構造体内容を定義
 * 
 *LastUpdate: 
******************************************************************************/

//基本形Palletの構造体内容を定義
typedef struct {
	GtkWidget *pallet_window,*function_window1;	//
	gchar *file_path1;	//set file name
	gchar *script1;				// script of command
	gboolean process_check_flag1;	//proc_flag1:OK button clicked
	const gchar *variable_name;
	GtkEntry *entry_variable_name;//
}StructPalletWidget;

/*構造体変数名を宣言*/
StructPalletWidget Pallet_Master; 
StructPalletWidget Pallet_Test;
StructPalletWidget Pallet_Essentials;

//FileSystemコマンド用Palletの構造体内容を定義
typedef struct {
	GtkWidget *pallet_window,*function_window1;	//
	gchar *file_path1;	//set file name
	gchar *script1;				// script of command
	gboolean process_check_flag1;	//proc_flag1:OK button clicked
	const gchar *variable_name;
	GtkEntry *entry_variable_name;//
}StructPalletFilesystemWidget;

/*構造体変数名を宣言*/
StructPalletFilesystemWidget Pallet_Filesystem;


//データ読み書きコマンド用Palletの構造体内容を定義
typedef struct {
	GtkWidget *pallet_window,*function_window1;	//
	
	gchar *file_path1;	//set file name
	gint file_path1_length;
	
	gchar *script1,*script2;				// script of command
	gint script1_length,script2_length;
	
	gboolean process_check_flag1;	//proc_flag1:OK button clicked
	gboolean toggle_button_active;	//checkbuttonの確認
	
	const gchar *variable_name;
	GtkEntry *entry_variable_name;
	gint variable_name_length;
	
	gchar *header;//Bool -- Use the information from the file's header line to determine column names. Defaults to true.
	GtkCheckButton *checkbutton_header;
	gint header_length;
	
	gchar *separator;//Char -- Assume that fields are split by the separator character. If not specified, it will be guessed from the filename: .csv defaults to ',', .tsv defaults to '\t', .wsv defaults to ' '.
	GtkCheckButton *checkbutton_separator;
	GtkEntry *entry_separator;
	gint separator_length;
	
	gchar *quotemark;//Vector{Char} -- Assume that fields contained inside of two quotemark characters are quoted, which disables processing of separators and linebreaks. Set to Char[] to disable this feature and slightly improve performance. Defaults to ['"'].
	GtkCheckButton *checkbutton_quotemark;
	GtkEntry *entry_quotemark;
	gint quotemark_length;
	
	gchar *decimal;//Char -- Assume that the decimal place in numbers is written using the decimal character. Defaults to '.'.
	GtkCheckButton *checkbutton_decimal;
	GtkEntry *entry_decimal;
	gint decimal_length;
	
	gchar *nastrings;//Vector{ASCIIString} -- Translate any of the strings into this vector into an NA. Defaults to ["", "NA"].
	GtkCheckButton *checkbutton_nastrings;
	GtkEntry *entry_nastrings;
	gint nastrings_length;
	
	gchar *truestrings;//Vector{ASCIIString} -- Translate any of the strings into this vector into a Boolean true. Defaults to ["T", "t", "TRUE", "true"].
	GtkCheckButton *checkbutton_truestrings;
	GtkEntry *entry_truestrings;
	gint truestrings_length;

	gchar *falsestrings;//Vector{ASCIIString} -- Translate any of the strings into this vector into a Boolean true. Defaults to ["F", "f", "FALSE", "false"].
	GtkCheckButton *checkbutton_falsestrings;
	GtkEntry *entry_falsestrings;
	gint falsestrings_length;
	
	gchar *makefactors;//Bool -- Convert string columns into PooledDataVector's for use as factors. Defaults to false.
	GtkCheckButton *checkbutton_makefactors;
	gint makefactors_length;
	
	gchar *nrows;//Int -- Read only nrows from the file. Defaults to -1, which indicates that the entire file should be read.
	GtkCheckButton *checkbutton_nrows;
	GtkEntry *entry_nrows;
	gint nrows_length;
	
	gchar *names;//Vector{Symbol} -- Use the values in this array as the names for all columns instead of or in lieu of the names in the file's header. Defaults to [], which indicates that the header should be used if present or that numeric names should be invented if there is no header.
	GtkCheckButton *checkbutton_names;
	GtkEntry *entry_names;
	gint names_length;
	
	gchar *eltypes;//Vector{DataType} -- Specify the types of all columns. Defaults to [].
	GtkCheckButton *checkbutton_eltypes;
	GtkEntry *entry_eltypes;
	gint eltypes_length;
	
	gchar *allowcomments;//Bool -- Ignore all text inside comments. Defaults to false.
	GtkCheckButton *checkbutton_allowcomments;
	gint allowcomments_length;
	
	gchar *commentmark;//Char -- Specify the character that starts comments. Defaults to '#'.
	GtkCheckButton *checkbutton_commentmark;
	GtkEntry *entry_commentmark;
	gint commentmark_length;
	
	const gchar *ignorepadding;//Bool -- Ignore all whitespace on left and right sides of a field. Defaults to true.
	GtkCheckButton *checkbutton_ignorepadding;
	gint ignorepadding_length;
	
	gchar *skipstart;//Int -- Specify the number of initial rows to skip. Defaults to 0.
	GtkCheckButton *checkbutton_skipstart;
	GtkEntry *entry_skipstart;
	gint skipstart_length;
	
	gchar *skiprows;//Vector{Int} -- Specify the indices of lines in the input to ignore. Defaults to [].
	GtkCheckButton *checkbutton_skiprows;
	GtkEntry *entry_skiprows;
	gint skiprows_length;
	
	gchar *skipblanks;//Bool -- Skip any blank lines in input. Defaults to true.
	GtkCheckButton *checkbutton_skipblanks;
	gint skipblanks_length;
	
	gchar *encoding;//Symbol -- Specify the file's encoding as either :utf8 or :latin1. Defaults to :utf8
	GtkCheckButton *checkbutton_encoding;
	GtkEntry *entry_encoding;
	gint encoding_length;
	
	const gchar *groupe_name;
	GtkEntry *entry_groupe_name;//
	gint groupe_name_length;
	
}StructPalletReadWriteData;

/*構造体変数名を宣言*/
StructPalletReadWriteData Pallet_Write_Data;
StructPalletReadWriteData Pallet_Read_Data; 
