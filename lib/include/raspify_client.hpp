#ifndef RASPIFY_CLIENT_HPP_
#define RASPIFY_CLIENT_HPP_

#include <fstream>
#include <string_view>
#include <string>


namespace raspify::gui
{
	class RaspifyClient
	{
	public:
		inline void tryConnect()
		{
			_pipe.open(_pipePath.data(), std::ios::binary);
			if (!_pipe) {
				throw std::runtime_error("Couldn't connect to the server");
			}
		}


		inline std::string read() {
			std::string track;
			std::getline(_pipe, track, '\0');
			return track;
		}


		inline void close() {
			_pipe.close();
		}

	private:
		std::ifstream _pipe;

	#ifdef _WIN32
		static constexpr std::string_view _pipePath = R"(\\.\pipe\raspify_pipe)";
	#elif defined(__unix__)
		static constexpr std::string_view _pipePath = R"(\\.\pipe\raspify_pipe)";
	#endif
	};
}



#endif // !RASPIFY_CLIENT_HPP_