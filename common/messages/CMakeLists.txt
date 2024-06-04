cmake_minimum_required(VERSION 3.5)

project(mars_message)

if (NOT DEFINED ENV{COMMON_DIR})
	message(FATAL_ERROR "Please set COMMON_DIR first")
else()
	message(STATUS "COMMON_DIR is $ENV{COMMON_DIR}")
endif()

if(DEFINED ENV{EXE_DIR})
set(CMAKE_FIND_ROOT_PATH $ENV{EXE_DIR})
list(APPEND CMAKE_PREFIX_PATH $ENV{EXE_DIR})
set(CMAKE_INSTALL_PREFIX $ENV{COMMON_DIR})
else()
set(CMAKE_FIND_ROOT_PATH $ENV{COMMON_DIR})
list(APPEND CMAKE_PREFIX_PATH $ENV{COMMON_DIR})
set(CMAKE_INSTALL_PREFIX $ENV{COMMON_DIR})
endif()

find_package(lcm REQUIRED)
find_package(PythonInterp)
include(${LCM_USE_FILE})

if(PYTHONINTERP_FOUND)
  set(python_args PYTHON_SOURCES python_install_sources)
  message(STATUS "found python ${python_args}")
else()
  message(STATUS "No found python ${python_args}")
endif()

if(PYTHONINTERP_FOUND)
  set(python_args PYTHON_SOURCES python_install_sources)
endif()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "./src/*.lcm")
message(STATUS "source is ${SOURCES}")
lcm_wrap_types(
  C_SOURCES c_sources
  C_HEADERS c_headers
  CPP_HEADERS cpp_headers
  ${python_args}
  ${SOURCES}
)

# ...logic for C library...
lcm_add_library(mars_message C STATIC ${c_sources} ${c_headers})
lcm_add_library(mars_message_cpp CPP ${cpp_headers})
target_include_directories(mars_message INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

lcm_install_headers(DESTINATION include
  ${c_install_headers}
  ${cpp_install_headers}
)  

if(PYTHONINTERP_FOUND)
  lcm_install_python(${python_install_sources})
endif()

# Header files
install(FILES ${c_headers} ${cpp_headers}
    DESTINATION include/mars_message)

install(TARGETS mars_message mars_message_cpp
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib${LIB_SUFFIX}
  ARCHIVE DESTINATION lib${LIB_SUFFIX}
  INCLUDES DESTINATION include
)

