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
SET(FUNCTION_SOURCE pallet_write_data.c pallet_write_data_function01.c pallet_write_data_function02.c pallet_write_data_function03.c pallet_write_data_function04.c
 pallet_write_data_function05.c pallet_write_data_function06.c pallet_write_data_function07.c pallet_write_data_function08.c pallet_write_data_function09.c pallet_write_data_function10.c)


##ライブラリの作成
add_library(${FUNCTION_LIB_WRITE_DATA} SHARED ${PALLET} ${FUNCTION_SOURCE})


