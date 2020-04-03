SET(LIBRARY_OUTPUT_PATH ${PROJECT_ROOT_PATH}/lib)

SET(SRC_LIST cnv_liblog4cplus.cpp)

INCLUDE_DIRECTORIES(${PROJECT_ROOT_PATH}/include)
INCLUDE_DIRECTORIES(${SYS_LIBLOG4CPLUS}/include)

ADD_LIBRARY(cnv_liblog4cplus SHARED ${SRC_LIST})
ADD_LIBRARY(cnv_liblog4cplus_static STATIC ${SRC_LIST})
SET_TARGET_PROPERTIES(cnv_liblog4cplus_static PROPERTIES OUTPUT_NAME "cnv_liblog4cplus")
target_link_libraries(cnv_liblog4cplus_static log4cplus)

if(${APPLE})
target_link_libraries(cnv_liblog4cplus log4cplus)
endif()
