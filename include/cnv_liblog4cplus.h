

#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#ifndef CNV_LIBLOG4PLUS_H_
#define CNV_LIBLOG4PLUS_H_

#include <stdio.h>
#define LOG4CPLUS_OUTBUF (4096)
#define LOG4CPLUS_FILENAME FILENAME_MAX
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
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_DEBUG_(outbuf); \
  } while (0)

#define LOG_APP_INFO(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_INFO_(outbuf); \
  } while (0)

#define LOG_APP_WARN(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_WARN_(outbuf); \
  } while (0)

#define LOG_APP_ERROR(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_ERROR_(outbuf); \
  } while (0)

#define LOG_APP_FATAL(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_APP_FATAL_(outbuf); \
  } while (0)
  


// acc
#define LOG_ACC_DEBUG(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_DEBUG_(outbuf); \
  } while (0)

#define LOG_ACC_INFO(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_INFO_(outbuf); \
  } while (0)

#define LOG_ACC_WARN(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_WARN_(outbuf); \
  } while (0)

#define LOG_ACC_ERROR(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_ERROR_(outbuf); \
  } while (0)

#define LOG_ACC_FATAL(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_ACC_FATAL_(outbuf); \
  } while (0)

// sys
#define LOG_SYS_DEBUG(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_DEBUG_(outbuf); \
  } while (0)

#define LOG_SYS_INFO(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_INFO_(outbuf); \
  } while (0)

#define LOG_SYS_WARN(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_WARN_(outbuf); \
  } while (0)

#define LOG_SYS_ERROR(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF]; \
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_ERROR_(outbuf); \
  } while (0)

#define LOG_SYS_FATAL(fmt, ...) \
  do \
  { \
    char outbuf[LOG4CPLUS_OUTBUF];\
    char filename[LOG4CPLUS_FILENAME];\
    LOGGER_GETFILENAME(__FILE__,filename);\
    snprintf(outbuf, LOG4CPLUS_OUTBUF, "%s|%d|%s|" fmt, filename, __LINE__, __FUNCTION__ , ## __VA_ARGS__); \
    LOG_SYS_FATAL_(outbuf); \
  } while (0)

#endif //CNV_LIBLOG4PLUS_H_

// #undef LOG_SYS_FATAL
// #undef LOG_SYS_ERROR
// #undef LOG_SYS_WARN
// #undef LOG_SYS_INFO
// #undef LOG_SYS_DEBUG
// 
// #define LOG_SYS_FATAL printf
// #define LOG_SYS_ERROR printf
// #define LOG_SYS_WARN  printf
// #define LOG_SYS_INFO  printf
// #define LOG_SYS_DEBUG printf

#ifdef __cplusplus
}
#endif
