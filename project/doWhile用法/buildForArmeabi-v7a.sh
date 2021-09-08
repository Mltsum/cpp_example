#!/bin/bash
echo "当前编译平台为Android Armeabi-v7a"

cd build

rm -rf *

export NDK_PATH=/Users/mingren/Library/Android/sdk/ndk/16.1.4479499

cmake .. -DCMAKE_TOOLCHAIN_FILE=/Users/mingren/Library/Android/sdk/ndk/16.1.4479499/build/cmake/android.toolchain.cmake -DANDROID_ABI="armeabi-v7a" -DANDROID_STL=c++_static  -DCMAKE_BUILD_TYPE=Release -DANDROID_NATIVE_API_LEVEL=android-19 -DANDROID_ARM_NEON=TRUE

make -j32