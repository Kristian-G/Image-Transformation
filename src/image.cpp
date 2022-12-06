#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "image.h"
#include "stb_image.h"
#include "stb_image_write.h"


Image::Image(const char* filename) {
    if (read(filename)) {
        printf("Read %s\n", filename);
        size = w * h * channels;
    } else {
        printf("Failed to read %s\n", filename);
    }
}

Image::Image(int w, int h, int channels) : w(w), h(h), channels(channels) {
    size = w * h * channels;
    data = new uint8_t[size];
}

Image::Image(const Image &img) : Image(img.w, img.w, img.channels) {
    memcpy(data, img.data, img.size);
}

Image::~Image() {
    stbi_image_free(data);
}

bool Image::read(const char *filename) {
    data = stbi_load(filename, &w, &h, &channels, 0);
    return data != NULL;
}

bool Image::write(const char *filename) {
    ImageType type = getFileType(filename);
    int success;
    switch (type) {
        case PNG:
            success = stbi_write_png(filename, w, h, channels, data, w*channels);
        case BMP:
            success = stbi_write_bmp(filename, w, h, channels, data);
        case JPG:
            success = stbi_write_jpg(filename, w, h, channels, data, 100);
        case TGA:
            success = stbi_write_tga(filename, w, h, channels, data);
    }
    return success != 0;
}

ImageType Image::getFileType(const char *filename) {
    const char *ext = strrchr(filename, '.');
    if (ext != nullptr) {
        if (strcmp(ext, ".png") == 0) {
            return PNG;
        } else if (strcmp(ext, ".jpg") == 0) {
            return JPG;
        } else if (strcmp(ext, ".bmp") == 0) {
            return BMP;
        } else if (strcmp(ext, ".tga") == 0) {
            return TGA;
        }
    }
    return PNG;
}
Image& Image::grayscale(){
    if (channels < 3){
        printf("Image %p has less then 3 channels, it is assumed to already tbe grayscale.", this);
    }else{
        for (int i = 0; i < size; i += channels) {
            int gray = (data[i] + data[i+1] + data[i+2]) / 3;
            memset(data+i, gray, 3 );
        }
    }
    return *this;
}
Image& grayscale_lum(){}