//
// Created by mingren on 2022/11/30.
//

#include <iostream>
#include "ClassExample.h"
#include "ClassExampleSon.h"

int main() {
    auto instance = GET_INSTANCE(ClassExample);

    instance->running();
}