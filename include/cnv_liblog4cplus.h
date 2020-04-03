
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#ifndef CNV_LIBLOG4PLUS_H_
#define CNV_LIBLOG4PLUS_H_

#define LOG4CPLUS_OUTBUF 4096
#define LOG4CPLUS_FILENAME 128
#include "cnv_log_bridge.h"

#ifdef WIN32
#define _BACKSLASH_ '\\'
#else
#define _BACKSLASH_	'/'
#endif

#define LOGGER_GETFILENAME(pathname, filename) { \
	char *path = (char *)pathname; \
	char *name = (char *)pathname; \
	while(*path) { \
		if(*path == _BACKSLASH_) { \
			name = path; \
			name++;\
		} \
		path++; \
	} \
	if(name) snprintf(filename,LOG4CPLUS_FILENAME,"%s", name); \
}

//设定配置文件
void set_config(const char * filename,char errmsg[],int msg_length);
// app
#define LOG_APP_DEBUG(fmt, ...) \
  do \
  { \
    if ( LL_DEBUG_LOG_LEVEL < LOG_APP_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_DEBUG_(outbuf); \
  } while (0)

#define LOG_APP_INFO(fmt, ...) \
  do \
  { \
    if ( LL_INFO_LOG_LEVEL < LOG_APP_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_INFO_(outbuf); \
  } while (0)

#define LOG_APP_WARN(fmt, ...) \
  do \
  { \
    if ( LL_WARN_LOG_LEVEL < LOG_APP_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_WARN_(outbuf); \
  } while (0)

#define LOG_APP_ERROR(fmt, ...) \
  do \
  { \
    if ( LL_ERROR_LOG_LEVEL < LOG_APP_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_ERROR_(outbuf); \
  } while (0)

#define LOG_APP_FATAL(fmt, ...) \
  do \
  { \
    if ( LL_FATAL_LOG_LEVEL < LOG_APP_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_FATAL_(outbuf); \
  } while (0)
  


// acc
#define LOG_ACC_DEBUG(fmt, ...) \
  do \
  { \
    if ( LL_DEBUG_LOG_LEVEL < LOG_ACC_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_DEBUG_(outbuf); \
  } while (0)

#define LOG_ACC_INFO(fmt, ...) \
  do \
  { \
    if ( LL_INFO_LOG_LEVEL < LOG_ACC_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_INFO_(outbuf); \
  } while (0)

#define LOG_ACC_WARN(fmt, ...) \
  do \
  { \
    if ( LL_WARN_LOG_LEVEL < LOG_ACC_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_WARN_(outbuf); \
  } while (0)

#define LOG_ACC_ERROR(fmt, ...) \
  do \
  { \
    if ( LL_ERROR_LOG_LEVEL < LOG_ACC_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_ERROR_(outbuf); \
  } while (0)

#define LOG_ACC_FATAL(fmt, ...) \
  do \
  { \
    if ( LL_FATAL_LOG_LEVEL < LOG_ACC_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_FATAL_(outbuf); \
  } while (0)

// sys
#define LOG_SYS_DEBUG(fmt, ...) \
  do \
  { \
    if ( LL_DEBUG_LOG_LEVEL < LOG_SYS_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_DEBUG_(outbuf); \
  } while (0)

#define LOG_SYS_INFO(fmt, ...) \
  do \
  { \
    if ( LL_INFO_LOG_LEVEL < LOG_SYS_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_INFO_(outbuf); \
  } while (0)

#define LOG_SYS_WARN(fmt, ...) \
  do \
  { \
    if ( LL_WARN_LOG_LEVEL < LOG_SYS_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_WARN_(outbuf); \
  } while (0)

#define LOG_SYS_ERROR(fmt, ...) \
  do \
  { \
    if ( LL_ERROR_LOG_LEVEL < LOG_SYS_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_ERROR_(outbuf); \
  } while (0)

#define LOG_SYS_FATAL(fmt, ...) \
  do \
  { \
    if ( LL_FATAL_LOG_LEVEL < LOG_SYS_GET_LEVEL_() ) {break;} \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|"fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_FATAL_(outbuf); \
  } while (0)

#endif //CNV_LIBLOG4PLUS_H_

#ifdef __cplusplus
}
#endif
