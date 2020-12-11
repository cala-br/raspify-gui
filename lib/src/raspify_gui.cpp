#include <iostream>
#include <chrono>
#include "raspify_client.hpp"
#include "json.hpp"
#include "current_track.hpp"
#include "json_conversions.hpp"
#include "gui/root_frame.hpp"

using namespace raspify;
using namespace std::string_view_literals;
using namespace sf;
using nlohmann::json;

int main()
{
	gui::RootFrame frame;
	frame.loop();

	return 0;

	RaspifyClient client;
	try {
		client.tryConnect();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	}

	const auto rawTrack = client.read();
	json track = json::parse(rawTrack);

	const auto cTrack = 
		track.get<CurrentTrack>();

	std::cout 
		<< cTrack.name << '\n'
		<< cTrack.albumName << '\n'
		<< cTrack.artists[0] << '\n'
		<< cTrack.duration.minutes << '\n'
		<< cTrack.progress.seconds;
}