#include <iostream>
#include <chrono>
#include "raspify_client.hpp"
#include "json.hpp"
#include "current_track.hpp"
#include "json_conversions.hpp"

using namespace raspify::gui;
using namespace std::string_view_literals;
using nlohmann::json;

int main()
{
	RaspifyClient client;
	try {
		client.tryConnect();
	}
	catch (std::exception& e) {
		std::cerr << e.what();
		return 1;
	}

	const auto rawTrack = client.read();
	json track = json::parse(rawTrack);

	auto cTrack = 
		track.get<raspify::CurrentTrack>();

	std::cout 
		<< cTrack.name << '\n'
		<< cTrack.albumName << '\n'
		<< cTrack.artists[0] << '\n'
		<< cTrack.duration.minutes << '\n'
		<< cTrack.progress.seconds;


	client.close();
}