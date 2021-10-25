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

int main(int argc, char **argv) {
    string         cate_dir = "/Users/mingren/Documents/07.Code/merge/data/hdmap_filt/";
    vector<string> files;

    DIR *          dir;
    struct dirent *ptr;

    if ((dir = opendir(cate_dir.c_str())) == NULL) {
        perror("Open dir error...");
        exit(1);
    }

    while ((ptr = readdir(dir)) != NULL) {
        if (strcmp(ptr->d_name, ".") == 0 || strcmp(ptr->d_name, "..") == 0) {
            continue;
        } else if (ptr->d_type == 8) {
            files.push_back(ptr->d_name);

        } else if (ptr->d_type == 10) {
            continue;

        } else if (ptr->d_type == 4) {
            files.push_back(ptr->d_name);
        }
    }
    closedir(dir);

    return 0;
};
