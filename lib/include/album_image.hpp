#ifndef ALBUM_IMAGE_HPP_
#define ALBUM_IMAGE_HPP_

#include <string>


namespace raspify
{
    struct AlbumImage
    {
        std::uint32_t height;
        std::uint32_t width;
        std::string url;
    };
}

#endif // !ALBUM_IMAGE_HPP_