

#include <stdio.h>
#include <assert.h>
#include <string.h>

#ifndef WIN32
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#endif

#include "cnv_liblog4cplus.h"
#include "cnv_log_bridge.h"

#ifdef WIN32
#define snprintf _snprintf_s
#else
#define LOG4CPLUS_C_STR_TO_TCSTR(str) str
#endif

#ifdef WIN32
void set_config(const char * filename,char errmsg[],int msg_length)
{
    assert(filename || errmsg || msg_length > 0);    
}

void LOG_OUT_TERIMAL(const char * buff)
{
    printf("%s\n",buff);
}

//app
void LOG_APP_DEBUG_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_APP_INFO_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_APP_WARN_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_APP_ERROR_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_APP_FATAL_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

//acc
void LOG_ACC_DEBUG_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_ACC_INFO_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_ACC_WARN_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_ACC_ERROR_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_ACC_FATAL_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

//sys
void LOG_SYS_DEBUG_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_SYS_INFO_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_SYS_WARN_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_SYS_ERROR_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

void LOG_SYS_FATAL_(const char * buff)
{
    LOG_OUT_TERIMAL(buff);
}

#else

//APP共用了一个 logger配置
//SYS,ACC 是独立的 logger 配置,这样 SYS,ACC,APP(APP_DAILY) 分别属于不同的logger
//它们可以独立的输出文件,相互不干扰

#define LOG_APP_ROOT log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("APP.APP"))
#define LOG_ACC_ROOT log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("ACC.ACC"))
#define LOG_SYS_ROOT log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("SYS.SYS"))

int LOG_APP_GET_LEVEL_() {
  return (LOG_APP_ROOT).getLogLevel();
}
int LOG_ACC_GET_LEVEL_() {
  return (LOG_ACC_ROOT).getLogLevel();
}
int LOG_SYS_GET_LEVEL_() {
  return (LOG_SYS_ROOT).getLogLevel();
}

//app
void LOG_APP_DEBUG_(const char * buff)
{
    LOG4CPLUS_DEBUG(LOG_APP_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_APP_INFO_(const char * buff)
{
    LOG4CPLUS_INFO(LOG_APP_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_APP_WARN_(const char * buff)
{
    LOG4CPLUS_WARN(LOG_APP_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_APP_ERROR_(const char * buff)
{
    LOG4CPLUS_ERROR(LOG_APP_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_APP_FATAL_(const char * buff)
{
    LOG4CPLUS_FATAL(LOG_APP_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

//acc
void LOG_ACC_DEBUG_(const char * buff)
{
    LOG4CPLUS_DEBUG(LOG_ACC_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_ACC_INFO_(const char * buff)
{
    LOG4CPLUS_INFO(LOG_ACC_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_ACC_WARN_(const char * buff)
{
    LOG4CPLUS_WARN(LOG_ACC_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_ACC_ERROR_(const char * buff)
{
    LOG4CPLUS_ERROR(LOG_ACC_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_ACC_FATAL_(const char * buff)
{
    LOG4CPLUS_FATAL(LOG_ACC_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

//sys
void LOG_SYS_DEBUG_(const char * buff)
{
    LOG4CPLUS_DEBUG(LOG_SYS_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_SYS_INFO_(const char * buff)
{
    LOG4CPLUS_INFO(LOG_SYS_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_SYS_WARN_(const char * buff)
{
    LOG4CPLUS_WARN(LOG_SYS_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_SYS_ERROR_(const char * buff)
{
    LOG4CPLUS_ERROR(LOG_SYS_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void LOG_SYS_FATAL_(const char * buff)
{
    LOG4CPLUS_FATAL(LOG_SYS_ROOT, LOG4CPLUS_C_STR_TO_TCSTR(buff));
}

void set_config(const char * filename,char errmsg[],int msg_length)
{
    assert(filename && errmsg && msg_length > 0);
    
    try
    {
        log4cplus::PropertyConfigurator config(LOG4CPLUS_TEXT(filename));
        config.configure();
    }
    catch (std::exception &e)
    {
        memcpy(errmsg,e.what(),msg_length);
    }
    catch(...)
    {
        strcpy(errmsg,"unknown error.");
    }
}

#endif
