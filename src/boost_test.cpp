// #include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    // using namespace boost::lambda;
    // typedef std::istream_iterator<int> in;

    // std::for_each(in(std::cin), in(), std::cout << (_1 * 3) << " " );
    int i = 3;
    int arr[i];

    for(int i = 0; i < 3; i++) {
        arr[i] = i;
    }

    return 0;
}