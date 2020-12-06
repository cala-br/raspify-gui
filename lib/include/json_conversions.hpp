#ifndef JSON_CONVERSIONS_HPP_
#define JSON_CONVERSIONS_HPP_

#include "json.hpp"
#include "current_track.hpp"

namespace raspify 
{
    inline void to_json(nlohmann::json& json, const CurrentTrack& track) {
        json = nlohmann::json{
            
        };
    }

    inline void from_json(const nlohmann::json& j, CurrentTrack& track) {
        j.at("Name").get_to(track.name);
        j.at("AlbumName").get_to(track.albumName);
        j.at("Artists").get_to(track.artists);

        const auto getInt = [&j](std::string a, std::string b) -> std::uint16_t {
            return j.at(a).at(b).get<std::uint16_t>();
        };

        const auto getTimeSpan = [&getInt](std::string prefix) {
            return TimeSpan{ 
                getInt(prefix, "Seconds"),
                getInt(prefix, "Minutes"),
                getInt(prefix, "Hours"),
            };
        };

        track.duration = getTimeSpan("Duration");
        track.progress = getTimeSpan("Progress");
    }
}

#endif // !JSON_CONVERSIONS_HPP_
