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


###### EXECUTABLE&SORCE_DEFINE #####
# 実行ファイルの生成
add_executable(${TARGET_EXE} ${COMPILE_SORCE})

# ライブラリのリンクの設定
target_link_libraries(${TARGET_EXE} ${FUNCTION_LIBS})
