#cmake 必要バージョン
#cmake_minimum_required(VERSION 2.6.4)
# プロジェクト名
#####共有ライブラリの作成
#project(kuikjulia)

# SHARED Libraryのバージョン
SET(soserial "1.0.0")

###### EXECUTABLE&SORCE_DEFINE #####
## 元となるソースSET
SET(PALLET ${PROJECT_LIBRARY_DIR}/pallet_create.c)
SET(FUNCTION_SOURCE pallet_Filesystem.c pallet_Filesystem_function01.c pallet_Filesystem_function02.c pallet_Filesystem_function03.c pallet_Filesystem_function04.c
 pallet_Filesystem_function05.c pallet_Filesystem_function06.c pallet_Filesystem_function07.c pallet_Filesystem_function08.c pallet_Filesystem_function09.c pallet_Filesystem_function10.c)


##ライブラリの作成
add_library(${FUNCTION_LIB_FILESYSTEM} SHARED ${PALLET} ${FUNCTION_SOURCE})


