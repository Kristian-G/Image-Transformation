#include "image.h"


int main(int argc, char **argv) {
    Image test("test.jpg");
    Image gray = test;
    gray.grayscale();
    gray.write("gray.png");


    return 0;
}