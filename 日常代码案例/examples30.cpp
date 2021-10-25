//
// Created by mingren.ms on 2020/8/4.
//
#include <fstream>
#include <iostream>
#include <string>
/*
 * 文件的读取和写入
 */
using namespace std;
int main() {
  //  cout << "test in" << endl;
  //  ofstream outfile;
  //  string filename1 =
  //  "D:\\Working_repo\\09.cpp_learning\\demo1\\test_file1.txt";
  //  outfile.open(filename1, ios::app);
  //  cout << "test pos0" << endl;
  //  outfile << "world" << endl;
  //  outfile.close();
  //  cout << "test out" << endl;

  string fileStr = "images_hd";
  cout << "test in" << endl;
  string filename = "D:\\Working_repo\\09.cpp_learning\\demo1\\test_file.txt";
  ofstream file_writer(filename, ios_base::app);
  file_writer << fileStr << "\t";
  file_writer << 0.3 << "\t";
  file_writer << endl;
  file_writer.close();
  cout << "test out" << endl;
  return 0;
}
