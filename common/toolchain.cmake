set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_LIBRARY_ARCHITECTURE aarch64-linux-gnu)
set(CMAKE_SYSTEM_PROCESSOR arm)

#set(CMAKE_C_COMPILER   aarch64-linux-gnu-gcc)
#set(CMAKE_CXX_COMPILER aarch64-linux-gnu-g++)
#set(CMAKE_Fortran_COMPILER  aarch64-linux-gnu-gfortran)

set(CMAKE_C_COMPILER   aarch64-openwrt-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER aarch64-openwrt-linux-gnu-g++)
set(CMAKE_Fortran_COMPILER  aarch64-openwrt-linux-gnu-gfortran)

set(CMAKE_SKIP_RPATH TRUE)
set(CMAKE_SKIP_INSTALL_RPATH TRUE)
set(CMAKE_SKIP_BUILD_RPATH TRUE)
set(CMAKE_CXX_STANDARD 11)  
add_compile_options(-O3 -s -Wno-multichar)
add_link_options("LINKER:-rpath-link,$ENV{COMMON_DIR}/lib")

#set(PLATFORM_RK3308 TRUE)
set(CMAKE_FIND_ROOT_PATH $ENV{COMMON_DIR} $ENV{COMPLIE_DIR})
#set(CMAKE_EXE_LINKER_FLAGS "--sysroot=linux_app/tool/host/aarch64-rockchip-linux-gnu/sysroot")
set(CMAKE_SYSROOT $ENV{SYSROOT})

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

