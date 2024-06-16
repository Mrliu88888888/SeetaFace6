# include orz

# option 
set(ORZ_ROOT_DIR "${PROJECT_SOURCE_DIR}/../OpenRoleZoo")

message(STATUS "Found ORZ in ${ORZ_ROOT_DIR}")

# build
message(STATUS "Build with ORZ")
include_directories(${ORZ_INCLUDE_DIR})
link_directories(${ORZ_ROOT_DIR}/${ENV_ARCHIVE_DIR})

