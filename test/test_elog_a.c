#include <elog.h>

int main() {
    ELOG_FATAL(stdout, "%s", "FATAL hi");
    ELOG_ERROR(stdout, "%s", "ERROR how");
    ELOG_WARN(stdout, "%s", "WARN are");
    ELOG_INFO(stdout, "%s", "INFO you ");
    ELOG_DEBUG(stdout, "%s", "DEBUG goo");
    ELOG_TRACE(stdout, "%s", "TRACE foo");
    return 0;
}
