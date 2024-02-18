#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rft_com_library::rft_com_library" for configuration ""
set_property(TARGET rft_com_library::rft_com_library APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(rft_com_library::rft_com_library PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/librft_com_library.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS rft_com_library::rft_com_library )
list(APPEND _IMPORT_CHECK_FILES_FOR_rft_com_library::rft_com_library "${_IMPORT_PREFIX}/lib/librft_com_library.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
