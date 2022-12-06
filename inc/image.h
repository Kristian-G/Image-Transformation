#ifndef IMAGE_TRANSFORMATION_IMAGE_H
#define IMAGE_TRANSFORMATION_IMAGE_H
#include <cstdint>
#include <cstdio>

enum ImageType{
    PNG, JPG, BMP, TGA
};


struct Image{
    uint8_t* data = NULL;
    size_t size = 0;
    int w;
    int h;
    int channels{};
    Image(const char* filename);
    Image(int w, int h, int channels);
    Image(const Image& img);
    ~Image();

    bool read(const char* filename);
    bool write(const char* filename);

    ImageType getFileType(const char* filename);

    Image& grayscale();
    Image& grayscale_lum();

};

#endif //IMAGE_TRANSFORMATION_IMAGE_H
