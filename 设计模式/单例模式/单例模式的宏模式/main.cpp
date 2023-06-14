//
// Created by mingren on 2022/11/30.
//

#include <iostream>
#include "ClassExample.h"
#include "ClassCreateExample.h"

int main() {
    auto instance = GET_INSTANCE(ClassExample);

    auto instance1 = CREATE(ClassCreateExample);
}