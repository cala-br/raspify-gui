#ifndef TRACK_HPP_
#define TRACK_HPP_

#include <string>
#include <vector>
#include "json.hpp"
#include "time_span.hpp"
#include "album_image.hpp"


namespace raspify
{
    struct CurrentTrack
    {
        std::string name;
        std::string albumName;
        std::vector<AlbumImage> albumImages;
        std::vector<std::string> artists;
        TimeSpan duration;
        TimeSpan progress;
    };
}

#endif // !TRACK_HPP_