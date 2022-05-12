cmake_minimum_required(VERSION 3.13)
project("HunspellNative")

set(CMAKE_SHARED_LIBRARY_PREFIX "")

if(NOT DEFINED NATIVE_LIBRARY_NAME)
  set( NATIVE_LIBRARY_NAME ${PROJECT_NAME})
endif()

message(STATUS "Native Library Name: ${NATIVE_LIBRARY_NAME}")
message(STATUS "Build Directory: ${CMAKE_BINARY_DIR}")

set(HunspellSourcecodeDir "hunspell")
set(HyphenSourcecodeDir "hyphen")


message(STATUS "Hunspell / Hyphen Code: ${HunspellSourcecodeDir} / ${HyphenSourcecodeDir}")

add_library(${PROJECT_NAME} SHARED)
set_target_properties(${PROJECT_NAME}  PROPERTIES  OUTPUT_NAME  ${NATIVE_LIBRARY_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_SEARCH_START_STATIC ON)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_SEARCH_END_STATIC ON)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR} ${HunspellSourcecodeDir} ${HyphenSourcecodeDir})
target_compile_definitions(${PROJECT_NAME} PRIVATE HUNSPELL_STATIC _CRT_SECURE_NO_WARNINGS NOMINMAX)
target_link_options(${PROJECT_NAME} PRIVATE -static)

target_sources(${PROJECT_NAME} PRIVATE

    # Interface
    DllMain.cpp
	EncodingToCodePage.h
    HunspellExportFunctions.cpp
    HyphenExportFunctions.cpp
	MemoryFile.cpp MemoryFile.hpp
	NHunspellExtensions.h

    # Modified hunspell filemanager
    filemgr.cxx filemgr.hxx

    # Hunspell Sources
    ${HunspellSourcecodeDir}/affentry.cxx
    ${HunspellSourcecodeDir}/affixmgr.cxx
    ${HunspellSourcecodeDir}/csutil.cxx
    # ${HunspellSourcecodeDir}/filemgr.cxx ${HunspellSourcecodeDir}/filemgr.hxx
    ${HunspellSourcecodeDir}/hashmgr.cxx
    ${HunspellSourcecodeDir}/hunspell.cxx
    ${HunspellSourcecodeDir}/hunzip.cxx
    ${HunspellSourcecodeDir}/phonet.cxx
    ${HunspellSourcecodeDir}/replist.cxx
    ${HunspellSourcecodeDir}/suggestmgr.cxx
    ${HunspellSourcecodeDir}/affentry.cxx
    ${HunspellSourcecodeDir}/affentry.cxx

    #Hyphen Sources
    ${HyphenSourcecodeDir}/hnjalloc.cpp
    ${HyphenSourcecodeDir}/hyphen.cpp
    ${HyphenSourcecodeDir}/substrings.cpp
)