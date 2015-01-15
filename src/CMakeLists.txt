#cmake 必要バージョン
#cmake_minimum_required(VERSION 2.6.4)
#####実行ファイルの作成サブプロジェクト
#project(kuikjulia)

###### EXECUTABLE&SORCE_DEFINE #####
#作成ターゲットの設定 
SET(MAIN main.c kuikjulia.c kuikjulia_func.c)
SET(ABOUT aboutDialog.c)
SET(VTE ./vte/vte_window.c ./vte/vte_enviroment.c)
SET(SCRIPTEDITOR ./editor/script_editor.c ./editor/script_editor_file_open.c ./editor/script_editor_file_save.c ./editor/script_editor_send.c ./editor/script_editor_undo-redo.c)
SET(COMPILE_SORCE ${MAIN} ${VTE} ${ABOUT} ${SCRIPTEDITOR})


#GTKの設定
#include(FindPkgConfig)
#pkg_check_modules(GMODULE gmodule-2.0)
#pkg_check_modules(GTK gtk+-2.0)
#pkg_check_modules(VTE vte) 
#pkg_check_modules(GTKSOURCEVIEW gtksourceview-2.0)
#include_directories(${GTK_INCLUDE_DIRS} ${VTE_INCLUDE_DIRS} ${GTKSOURCEVIEW_INCLUDE_DIRS})
#link_directories(${GTK_LIBRARY_DIRS} ${VTE_LIBRARY_DIRS} ${PROJECT_LIBRARY_DIR} ${GTKSOURCEVIEW_LIBRARY_DIRS})
#link_libraries(${GTK_LIBRARIES} ${VTE_LIBRARIES} ${FUNCTION_LIBS} ${GTKSOURCEVIEW_LIBRARIES})



###### EXECUTABLE&SORCE_DEFINE #####
# 実行ファイルの生成
add_executable(${TARGET_EXE} ${COMPILE_SORCE})

# ライブラリのリンクの設定
target_link_libraries(${TARGET_EXE} ${FUNCTION_LIBS})
