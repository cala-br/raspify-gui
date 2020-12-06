#ifndef TIME_SPAN_HPP_
#define TIME_SPAN_HPP_

namespace raspify 
{
    struct TimeSpan
    {
        std::uint16_t seconds;
        std::uint16_t minutes;
        std::uint16_t hours;
    };
}

#endif // !TIME_SPAN_HPP_