#include <stdarg.h>
#include <time.h>
#include <elog.h>

#define MAX_LEN 30

void elog_get_time(char *s) {
    time_t t;
    struct tm *tm;
    t = time(NULL);
    tm = gmtime(&t);
    strftime(s, MAX_LEN, "[%Y-%m-%d %H-%M-%S %z]", tm);
}

void elog_write_log(ELogLevelType level, FILE *out, const char *file, const char *func, int line, const char *fmt, ...) {
    char s[MAX_LEN];
    static const char levelChars[] = "FEWIDT";
    va_list ap;
    elog_get_time(s);
    /*You can change the format by hand. */
    fprintf(out, "%s\t%c[%s@%s:%d]\t", s, levelChars[level], func, file, line);
    va_start(ap, fmt);
    vfprintf(out, fmt, ap);
    va_end(ap);
    fprintf(out, "\n");
}

