#pragma once

#include <stdio.h>
#include <stdint.h>

/**
  This file provides trivial logging facility.

  Configuration is done trought defining some macros before log.h is included.

  #define LOG_PREFIX "some_prefix"  // prefix used for logging (optional)
  #define LOG_LVL DBG               // override log level for this file

  */

extern int32_t R0;
extern int32_t R1;
extern int32_t R2;
extern int32_t F0;
extern int32_t S0;
extern int32_t S1;
extern int32_t I0;
extern int32_t I1;
extern int32_t I2;

#define WTF 0
#define ERR 20
#define INFO 40
#define DBG 60

extern int log_global_lvl;

// define LOG_LVL to override log level for single file
#ifndef LOG_LVL
#define LOG_LOCAL_LVL(lvl) (0)
#else
#define LOG_LOCAL_LVL(lvl) (lvl <= LOG_LVL)
#endif

#ifndef LOG_PREFIX
#define LOG_PREFIX "_"
#endif

#define LOG_STR_(s) #s

#define LOGF(...) fprintf(stderr, ##__VA_ARGS__)

#define LOG__(line, msg, ...) \
    LOGF(LOG_PREFIX ":" LOG_STR_(line) " " msg , ##__VA_ARGS__)

#define LOG_(msg, ...) \
    LOG__(__LINE__, msg , ##__VA_ARGS__)

#define LOG_IF(lvl) \
    if (LOG_LOCAL_LVL(lvl) || lvl <= log_global_lvl)

#define LOG(lvl, msg, ...) \
    LOG_IF(lvl) { \
        LOG_(msg "\n", ##__VA_ARGS__); \
    }

static inline void log_set_lvl(int lvl)
{
    log_global_lvl = lvl;
}
