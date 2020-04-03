
#include "cnv_liblog4cplus.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void printlog(int i )
{
     LOG_SYS_DEBUG("sys :%d",i);
     LOG_SYS_INFO("sys :%d",i);
     LOG_SYS_WARN("sys :%d",i);
     LOG_SYS_ERROR("sys :%d",i);
     LOG_SYS_FATAL("sys :%d",i);
}

int main(int argc, char* argv[])
{
    char msg_buff[255] = {0};
    set_config("../bin/urconfig.properties",msg_buff,255);
	if(strlen(msg_buff) > 0)
	{
	    printf("aa=%s\n",msg_buff);
		return 0; 
	}	

    for (int i = 0; i < 10; ++i)
    {
   
        LOG_APP_DEBUG("app :%d",i);
        LOG_APP_INFO("app :%d",i);
        LOG_APP_WARN("app :%d",i);
        LOG_APP_ERROR("app :%d",i);
        LOG_APP_FATAL("app :%d",i);
        
        LOG_ACC_DEBUG("acc :%d",i);
        LOG_ACC_INFO("acc :%d",i);
        LOG_ACC_WARN("acc :%d",i);
        LOG_ACC_ERROR("acc :%d",i);
        LOG_ACC_FATAL("acc :%d",i);
        
        LOG_SYS_DEBUG("sys :%d",i);
        LOG_SYS_INFO("sys :%d",i);
        LOG_SYS_WARN("sys :%d",i);
        LOG_SYS_ERROR("sys :%d",i);
        LOG_SYS_FATAL("sys :%d",i);
    }
    
    
    
    const char *s = "fasfdsdf%lddd%d%s%xfsa%ufdAAA发放的撒";
    LOG_SYS_FATAL("sys :%d,%d,%s",1,100,s);
    
    //printlog(100);
    
    //const char *s = "fasfdsdf%d%s%xfsafdAAA";
    //LOG_SYS_FATAL("sys :%d,%d,%s",1,100,s);
    //LOG_SYS_DEBUG("sys :%d,%d,%s",1,100,s);
    //LOG_SYS_INFO("sys :%d,%d,%s",1,100,s);
    //LOG_SYS_WARN("sys :%d,%d,%s",1,100,s);
    //LOG_SYS_ERROR("sys :%d,%d,%s",1,100,s); 

	pause();

    return 0;
}
