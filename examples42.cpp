#include <algorithm> // std::sort
#include <fstream>
#include <iostream> // std::cout
#include <list>
#include <map>
#include <vector> // std::vector
//#include <string>
#include <array>
#include <iosfwd>
#include <math.h>
#include <memory>
#include <sstream>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 *
 *
 */

using namespace std;

#define mnnLog printf;

#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARNING 2
#define LOG_ERROR 3

#ifndef LOG_LEVEL
#define LOG_LEVEL 0
#endif

#define MNN_LOG(level, fmt, ...)                                               \
  do {                                                                         \
    if (level == LOG_DEBUG) {                                                  \
      if (LOG_DEBUG >= LOG_LEVEL) {                                            \
        printf(fmt, ##__VA_ARGS__);                                            \
      }                                                                        \
    } else if (level == LOG_INFO) {                                            \
      if (LOG_INFO >= LOG_LEVEL) {                                             \
        printf(fmt, ##__VA_ARGS__);                                            \
      }                                                                        \
    } else if (level == LOG_WARNING) {                                         \
      if (LOG_WARNING >= LOG_LEVEL) {                                          \
        printf(fmt, ##__VA_ARGS__);                                            \
      }                                                                        \
    } else if (level == LOG_ERROR) {                                           \
      if (LOG_ERROR >= LOG_LEVEL) {                                            \
        printf(fmt, ##__VA_ARGS__);                                            \
      }                                                                        \
    } else {                                                                   \
    }                                                                          \
  } while (0)

int main() {

  cout << "start..." << endl;
  printf("hello world-ori, %d\r\n", __LINE__);

  MNN_LOG(LOG_ERROR, "func is %s, line is %d", __FUNCTION__, __LINE__);

  return 0;
}