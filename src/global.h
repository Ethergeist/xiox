#ifndef GLOBAL_H_
#define GLOBAL_H_
#define _XOPEN_SOURCE 700
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

/** @brief 8-bit signed int */
typedef int8_t i8;
/** @brief 16-bit signed int */
typedef int16_t i16;
/** @brief 32-bit signed int */
typedef int32_t i32;
/** @brief 64-bit signed int */
typedef int64_t i64;
/** @brief 8-bit unsigned int */
typedef uint8_t u8;
/** @brief 16-bit unsigned int */
typedef uint16_t u16;
/** @brief 32-bit unsigned int */
typedef uint32_t u32;
/** @brief 64-bit unsigned int */
typedef uint64_t u64;
/** @brief 8-bit bool */
typedef bool b8;
/** @brief 32-bit bool */
typedef int b32;
/** @brief 32-bit float */
typedef float f32;
/** @brief 64-bit float (double) */
typedef double f64;

#if defined(__clang__) || defined(__GNUC__)
    #define INLINE __attribute__((always_inline)) inline
    #define NOINLINE __attribute((noinline))
    #define STATIC_ASSERT _Static_assert
#elif defined(_MSC_VER)
    #define INLINE __forceinline
    #define NOINLINE _declspec(noinline)
#else
    #define INLINE static inline
    #define NOINLINE
    #define STATIC_ASSERT static_assert
#endif

#ifdef TDEBUG
    #define LOG_DEBUG(fmt, ...) fprintf(stdout, "DEBUG: " fmt "\n", __VA_ARGS__)
    #define LOG_WARN(fmt, ...) fprintf(stderr, "WARN: " fmt "\n", __VA_ARGS__)
    #define LOG_ERROR(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", __VA_ARGS__)
    #define LOG_PERROR(error) perror("ERROR: " error)
#else
    #define LOG_DEBUG(...)
    #define LOG_WARN(...)
    #define LOG_ERROR(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", __VA_ARGS__)
    #define LOG_PERROR(error) perror("ERROR: " error)
#endif

STATIC_ASSERT(sizeof(f32) == 4, "f32 should be 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "f64 should be 8 bytes");

#endif // GLOBAL_H_
