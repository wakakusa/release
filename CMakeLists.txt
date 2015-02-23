#必要に応じて不要なコマンドは削除のこと！
#cmake 実行時のオプション（GUIで設定可能）
#アーキテクテャに依存する場合は、cmakeのオプションで設定する
#SET(CMAKE_C_FLAGS "-O2 -march=native")
#cmake 必要バージョン
cmake_minimum_required(VERSION 2.6.4)
# プロジェクト名
project(kuikR)
#バージョン番号
#SET(serial "1.0.0")
#ビルドタイプ
SET(CMAKE_BUILD_TYPE DEBUG) #release
#インストール場所
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}) #Install root path
SET(CMAKE_INSTALL_BIN_PREFIX ${CMAKE_INSTALL_PREFIX}/bin) #Install bin path
SET(CMAKE_INSTALL_LIBRARY_PREFIX ${CMAKE_INSTALL_PREFIX}/lib) #Install library path
SET(CMAKE_INSTALL_GLADE_PREFIX ${CMAKE_INSTALL_PREFIX}/glade) #Install Glade path

#ファイル所在の設定 
SET(PROJECT_DIR ${PROJECT_SOURCE_DIR})
SET(PROJECT_LIBRARY_DIR ${PROJECT_SOURCE_DIR}/lib)
SET(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
SET(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)
SET(PROJECT_GLADE_DIR ${PROJECT_SOURCE_DIR}/glade)


##作成ターゲットの設定 
SET(FUNCTION_LIB_TEST "test_func")
SET(FUNCTION_LIB_QUICK "quick_func")
SET(FUNCTION_LIB_FILESYSTEM "Filesystem_func")
SET(FUNCTION_LIB_READ_DATA "read_data_func")
SET(FUNCTION_LIB_WRITE_DATA "write_data_func")
SET(FUNCTION_LIB_PARALLEL "paralle_func")
SET(FUNCTION_LIB_ESSENTIALS "Essentials_func")

SET(FUNCTION_LIBS ${FUNCTION_LIB_TEST} ${FUNCTION_LIB_FILESYSTEM} ${FUNCTION_LIB_READ_DATA} ${FUNCTION_LIB_WRITE_DATA} ${FUNCTION_LIB_PARALLEL} ${FUNCTION_LIB_ESSENTIALS})
SET(TARGET_EXE "kuikjulia")

#インクルードパスを指定
#GTKの設定
include(FindPkgConfig)
pkg_check_modules(GMODULE gmodule-2.0)
pkg_check_modules(GTK gtk+-3.0)
pkg_check_modules(VTE vte-2.91) 
pkg_check_modules(GTKSOURCEVIEW gtksourceview-3.0)
include_directories(${GTK_INCLUDE_DIRS} ${VTE_INCLUDE_DIRS} ${PROJECT_INCLUDE_DIR} ${PROJECT_LIBRARY_DIR} ${GTKSOURCEVIEW_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS} ${VTE_LIBRARY_DIRS} ${PROJECT_LIBRARY_DIR} ${PROJECT_SOURCES_DIR} ${GTKSOURCEVIEW_LIBRARY_DIRS})
link_libraries(${GTK_LIBRARIES} ${VTE_LIBRARIES} ${GTKSOURCEVIEW_LIBRARIES})


#　サブディレクトリ(各，サブディレクトリにもCMakeLists.txtを置く)
#ADD_SUBDIRECTORY(${PROJECT_INCLUDE_DIR})
ADD_SUBDIRECTORY(${PROJECT_LIBRARY_DIR})
ADD_SUBDIRECTORY(${PROJECT_SOURCES_DIR})
ADD_SUBDIRECTORY(${PROJECT_INCLUDE_DIR})

######Compiler Option コンパイラの種類によってオプションを変更#####
# コンパイル時のオプション(OpenMP http://www.cmake.org/pipermail/cmake/2009-January/026607.html)
#ここの書き方は、GCC用　LINKER　FLAGSはビルド時間の短縮のため https://www.grapecity.com/japan/powernews/column/clang/003/page02.htm#1
if(MINGW)
  set(CMAKE_C_FLAGS -mms-bitfields)
  set(CMAKE_CXX_FLAGS -mms-bitfields)
  set(CMAKE_EXE_LINKER_FLAGS -mwindows)
endif(MINGW)

if(CMAKE_C_COMPILER MATCHES "icc")
  MESSAGE("Compiler's setting is Intel Compiler")
  #C用コンパイラの指定&コンパイラオプション
  SET(CMAKE_C_COMPILER icc)
  SET(CMAKE_C_FLAGS "-ggdb -O0")
  #C++用コンパイラの指定&コンパイラオプション
  SET(CMAKE_CXX_COMPILER icpc)
  SET(CMAKE_CXX_FLAGS "-ggdb -O0")
else()
  MESSAGE("Compiler's setting is GNU Compiler")
  #C用コンパイラの指定&コンパイラオプション
  SET(CMAKE_C_COMPILER gcc)
  SET(CMAKE_C_FLAGS "-Wall -ggdb -O0")
  #SET(CMAKE_EXE_LINKER_FLAGS -lgomp)#コンパイラのオプションによっては削除のこと
  #C++用コンパイラの指定&コンパイラオプション
  SET(CMAKE_CXX_COMPILER g++)
  SET(CMAKE_CXX_FLAGS "-Wall -ggdb -O0")
endif()
