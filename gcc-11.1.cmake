# CMAKE_SYSTEM_NAME is by default set to the same value as the
# CMAKE_HOST_SYSTEM_NAME variable so that the build targets the host system.
#SET(CMAKE_SYSTEM_NAME Linux)
# When the CMAKE_SYSTEM_NAME variable is set explicitly to enable cross compiling then
# the value of CMAKE_SYSTEM_VERSION must also be set explicitly to specify the target system version.
#SET(CMAKE_SYSTEM_VERSION 1)

# specify the compiler
SET(CMAKE_C_COMPILER   /usr/local/gcc-11.1.0/bin/gcc-11.1)
SET(CMAKE_CXX_COMPILER /usr/local/gcc-11.1.0/bin/g++-11.1)