cmake_minimum_required (VERSION 2.8)

project(class_paser)

aux_source_directory(./src DIR_SOURCE)
add_executable(class_parser ${DIR_SOURCE})
