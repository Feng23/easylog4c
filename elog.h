#ifndef __ELOG_H__
#define __ELOG_H__
#include <stdio.h>

typedef enum {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
} ELogLevelType;

void elog_write_log(ELogLevelType level, FILE *out, const char *file, const char *func, int line, const char *fmt, ...);

#ifndef ElogLevel
    #define ElogLevel 5
#endif

#if ElogLevel >= 0
    #define ELOG_FATAL(out, fmt, args...) elog_write_log(FATAL, out, __FILE__, __FUNCTION__, __LINE__, fmt, ##args)
#else
    #define ELOG_FATAL(...)
#endif
#if ElogLevel >= 1
    #define ELOG_ERROR(out, fmt, args...) elog_write_log(ERROR, out, __FILE__, __FUNCTION__, __LINE__, fmt, ##args)
#else
    #define ELOG_ERROR(...)
#endif
#if ElogLevel >= 2
    #define ELOG_WARN(out, fmt, args...) elog_write_log(WARN, out, __FILE__, __FUNCTION__, __LINE__, fmt, ##args)
#else
    #define ELOG_WARN(...)
#endif
#if ElogLevel >= 3
    #define ELOG_INFO(out, fmt, args...) elog_write_log(INFO, out, __FILE__, __FUNCTION__, __LINE__, fmt, ##args)
#else
    #define ELOG_INFO(...)
#endif
#if ElogLevel >= 4
    #define ELOG_DEBUG(out, fmt, args...) elog_write_log(DEBUG, out, __FILE__, __FUNCTION__, __LINE__, fmt, ##args)
#else
    #define ELOG_DEBUG(...)
#endif
#if ElogLevel >= 5
    #define ELOG_TRACE(out, fmt, args...) elog_write_log(TRACE, out, __FILE__, __FUNCTION__, __LINE__, fmt, ##args)
#else
    #define ELOG_TRACE(...)
#endif

#endif
