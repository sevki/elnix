#ifndef _ELNIX_DEBUG_H_
#define _ELNIX_DEBUG_H_

#ifndef _ELNIX_KPRINT_
#include <kprint.h>
#endif /* _ELNIX_KPRINT_ */

#define kdebug(msg)  kprint("%q%Q[ %s ]%q%Q  %s %d : %s\n", COLOR_YELLOW, 1, "DEBUG", COLOR_WHITE, 1,  __FILE__, __LINE__, msg)
#define kwarn(msg) kprint("%q%Q[ %s ]%q%Q  %s %d : %s\n", COLOR_YELLOW, 1, "WARN", COLOR_WHITE, 1,  __FILE__, __LINE__, msg)
#define kinfo(msg) kprint("%q%Q[ %s ]%q%Q  %s %d : %s\n", COLOR_GREEN, 1, "INFO", COLOR_WHITE, 1,  __FILE__, __LINE__, msg)

#define kerror(msg) kprint("%q%Q[ %s ]%q%Q  %s %d : %s\n", COLOR_RED , 1, "ERROR", COLOR_WHITE, 1,  __FILE__, __LINE__, msg)
#define kcritical(msg) kprint("%q%Q[ %s ]%q%Q  %s %d : %s\n", COLOR_RED, 1, "PANIC", COLOR_WHITE, 1,  __FILE__, __LINE__, msg)


#define ksucc(msg) kprint("%q%Q[ %s ]%q%Q %s\n", COLOR_GREEN, 1, " OK ", COLOR_WHITE, 1, msg)
#define kfail(msg) kprint("%q%Q[ %s ]%q%Q %s\n", COLOR_RED, 1, "FAIL", COLOR_WHITE, 1, msg)

#endif /* _ELNIX_DEBUG_H_ */
