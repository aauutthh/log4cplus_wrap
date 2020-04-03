

#ifndef CNV_LOGBRIDGE_H_
#define CNV_LOGBRIDGE_H_

// copy from log4cplus/loglevel.h 
// type: LogLevel
// typedef int LOG_LEVEL;
#define LL_OFF_LOG_LEVEL      60000
#define LL_FATAL_LOG_LEVEL    50000
#define LL_ERROR_LOG_LEVEL    40000
#define LL_WARN_LOG_LEVEL     30000
#define LL_INFO_LOG_LEVEL     20000
#define LL_DEBUG_LOG_LEVEL    10000
#define LL_TRACE_LOG_LEVEL    0
#define LL_ALL_LOG_LEVEL      0

#pragma once
#ifdef __cplusplus
extern "C" {
#endif

#ifndef LOG_BRIDGE_OUTPUT_H_
#define LOG_BRIDGE_OUTPUT_H_

void LOG_APP_DEBUG_(const char * buff);
void LOG_APP_INFO_(const char * buff);
void LOG_APP_WARN_(const char * buff);
void LOG_APP_ERROR_(const char * buff);
void LOG_APP_FATAL_(const char * buff);

void LOG_ACC_DEBUG_(const char * buff);
void LOG_ACC_INFO_(const char * buff);
void LOG_ACC_WARN_(const char * buff);
void LOG_ACC_ERROR_(const char * buff);
void LOG_ACC_FATAL_(const char * buff);

void LOG_SYS_DEBUG_(const char * buff);
void LOG_SYS_INFO_(const char * buff);
void LOG_SYS_WARN_(const char * buff);
void LOG_SYS_ERROR_(const char * buff);
void LOG_SYS_FATAL_(const char * buff);

int LOG_APP_GET_LEVEL_() ;
int LOG_ACC_GET_LEVEL_() ;
int LOG_SYS_GET_LEVEL_() ;

 
#endif

#ifdef __cplusplus
}
#endif

#endif //CNV_LOGBRIDGE_H_
