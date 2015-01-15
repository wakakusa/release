#cmake によるconfigure_fileからヘッダーファイル作成

configure_file (
  "${PROJECT_INCLUDE_DIR}/pallet_defines.h.in"
  "${PROJECT_INCLUDE_DIR}/pallet_defines.h"
  )

configure_file (
  "${PROJECT_INCLUDE_DIR}/UserInterfaceFile.h.in"
  "${PROJECT_INCLUDE_DIR}/UserInterfaceFile.h"
  )  
  
