#include <dirent.h>
#include <stdio.h>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <map>
#include <unsupported/Eigen/CXX11/Tensor>
#include "math.h"

using namespace std;
using namespace Eigen;

/*
 *  MNN 的内存对齐
 */

#define MNN_MEMORY_ALIGN_DEFAULT 64

static inline void **alignPointer(void **ptr, size_t alignment) {
    void *ptr1 = ((unsigned char *)ptr + alignment - 1);
    int   al = -alignment;

    return (void **)((intptr_t)((unsigned char *)ptr + alignment - 1) & -alignment);
}

extern "C" void *MNNMemoryAllocAlign(size_t size, size_t alignment) {
    assert(size > 0);

    int    vsize = sizeof(void *);
    void **origin = (void **)malloc(size + sizeof(void *) + alignment);
    assert(origin != NULL);
    if (!origin) {
        return NULL;
    }

    void **aligned = alignPointer(origin + 1, alignment);
    aligned[-1] = origin;
    return aligned;
}

int main(int argc, char **argv) {
    int   size = 1000;
    void *ptr = MNNMemoryAllocAlign(size, MNN_MEMORY_ALIGN_DEFAULT);
    if (ptr = nullptr) {
        cout << "malloc align faild" << endl;
    } else {
        cout << "malloc align success" << endl;
    }

    return 0;
}
