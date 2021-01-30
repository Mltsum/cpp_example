#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>
#include <unsupported/Eigen/CXX11/Tensor>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv) {
    // 随机初始化
    Eigen::Tensor<unsigned int, 2> a(4, 4);
    a.setRandom<Eigen::internal::NormalRandomGenerator<unsigned int>>();
    std::cout << a << std::endl;
    //
    //    //    // reshape : 需要显示的声明
    //    //    Eigen::array<int, 2> new_shape {3, 2};
    //    //    auto                 b = a.reshape(new_shape);
    //    //    std::cout << b << std::endl;
    //
    //    // 单行切片
    //    // 0 表示行切还是列切， 3表示行数或者列数
    //    //    auto c2 = a.chip<0>(3);
    //    //    std::cout << "c2: \n" << c2 << std::endl;
    //
    //    // 切片， slice 和 strided_slice
    auto d0 = std::make_pair(2, 2);
    auto d1 = std::make_pair(2, 2);
    // auto dims = std::experimental::make_array(d0, d1); // 便利的写法
    Eigen::array<std::pair<int, int>, 2> dims {d0, d1};
    auto                                 padded = a.pad(dims, 10);
    std::cout << padded << std::endl;

    Eigen::array<int, 2> offstes {2, 2};
    Eigen::array<int, 2> extents {2, 3};
    auto                 origin = padded.slice(offstes, extents);
    std::cout << origin << std::endl;

    // dot ?
    //    Eigen::Tensor<float, 2> a(2, 3);
    //    a.setValues({{1, 2, 3}, {4, 5, 6}});
    //    Eigen::Tensor<float, 2> b(3, 1);
    //    b.setValues({{1}, {2}, {3}});
    //    std::cout << a << std::endl;
    //    std::cout << b << std::endl;
    //    Eigen::array<Eigen::IndexPair<long int>, 1> dimensions {Eigen::IndexPair<long int> {1, 0}};
    //    auto                                        ab = a.contract(b, dimensions);
    //    std::cout << "======" << std::endl;
    //    std::cout << ab << std::endl;

    // 转置 和 共轭
    //    MatrixXcf a = MatrixXcf::Random(2, 2);
    //    std::cout << a << std::endl;
    //    cout << "Here is the matrix a^T\n" << a.transpose() << endl;
    //    cout << "Here is the conjugate of a\n" << a.conjugate() << endl;

    cout << "Eigen successful." << endl;

    return 0;
}
