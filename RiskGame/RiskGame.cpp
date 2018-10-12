// RiskGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <time.h>
#include "DiceRollingFacility.h"
#include "MapLoader.h"
#include "Player.h"
#include "Hand.h"
#include "Deck.h"

using namespace std;

void diceDriver();
void mapDriver();
void mapLoaderDriver();
void playerDriver();
void cardDeckDriver();
void printContainer(vector<int> &MyV);

int main() {
	char ans = 'y';
	int choice = 0;
	do {
		printf("Choose the driver you want to run: \n");
		printf("\t[0] Dice Driver\n");
		printf("\t[1] Map Driver\n");
		printf("\t[2] Map Loader Driver (RUN LAST)\n");
		printf("\t[3] Player Driver\n");
		printf("\t[4] Card Deck Driver\n");
		cin >> choice;

		switch (choice) {
		case 0:
			diceDriver();
			break;
		case 1:
			mapDriver();
			break;
		case 2:
			mapLoaderDriver();
			break;
		case 3:
			playerDriver();
			break;
		case 4:
			cardDeckDriver();
			break;
		default: break;
		}

		cout << "Do you wish to run another driver? (y/n)" << endl;
		cin >> ans;

	} while (ans == 'y');

	return 0;
}

// Test for DiceDriver
void diceDriver() {
	srand(time(0));	// Unique pattern for the rand() function. MUST BE first statement in main function!

					// Two Dice Rolling objects with respective containers
	DiceRollingFacility obj1, obj2;
	vector <int> container1, container2;
	char repeat;
	do {
		// Test object 1
		cout << "\nTest for the first object" << endl;
		container1 = obj1.rollDice(3);
		cout << "Container values: ";
		printContainer(container1);
		cout << "Percentage of rolls " << endl;
		obj1.displayPercentArr();

		// Test object 2
		cout << "\nTest for the second object" << endl;
		container2 = obj2.rollDice(3);
		cout << "Container values: ";
		printContainer(container2);
		cout << "Percentage of rolls: " << endl;
		obj2.displayPercentArr();

		// Run test again
		cout << "\nRepeat test? (y/n): ";
		cin >> repeat;
	} while (repeat != 'n');

	//	 Test for the equal share of rolls
	for (int i = 0; i < 500; ++i) {
		obj1.rollDice(3);
	}
	obj1.displayPercentArr();
	std::cout << std::endl;
}

// Test for MapDriver
void mapDriver() {
	std::vector<std::string> map_info_vector = {
		"Alaska,North America,Northwest Territory,Alberta,Kamchatka",
		"Northwest Territory,North America,Alaska,Alberta,Ontario,Greenland",
		"Alberta,North America,Alaska,Northwest Territory,Ontario,Western United States",
		"Greenland,North America,Northwest Territory,Ontario,Quebec,Iceland",
		"Ontario,North America,Northwest Territory,Alberta,Greenland,Quebec,Western United States,Eastern United States",
		"Quebec,North America,Greenland,Ontario,Eastern United States",
		"Western United States,North America,Alberta,Ontario,Eastern United States,Central America",
		"Eastern United States,North America,Ontario,Quebec,Western United States,Central America",
		"Central America,North America,Western United States,Eastern United States,Venezuala",
		"Venezuala,South America,Central America,Peru,Brazil",
		"Peru,South America,Venezuala,Brazil,Argentina",
		"Argentina,South America,Peru,Brazil",
		"Brazil,South America,Venezuala,Peru,Argentina,North Africa",
		"North Africa,Africa,Brazil,Western Europe,Southern Europe,Egypt,East Africa,Congo",
		"Congo,Africa,North Africa,East Africa,South Africa",
		"South Africa,Africa,Congo,East Africa,Madagascar",
		"Madagascar,Africa,East Africa,South Africa",
		"East Africa,Africa,Egypt,Middle East,Congo,North Africa,South Africa,Madagascar",
		"Egypt,Africa,Southern Europe,North Africa,Middle East,East Africa",
		"Iceland,Europe,Greenland,Great Britain,Scandinavia",
		"Great Britain,Europe,Iceland,Scandinavia,Western Europe,Northern Europe",
		"Western Europe,Europe,Great Britain,Northern Europe,Southern Europe,North Africa",
		"Scandinavia,Europe,Iceland,Great Britain,Northern Europe,Ukraine",
		"Northern Europe,Europe,Great Britain,Scandinavia,Ukraine,Southern Europe,Western Europe",
		"Southern Europe,Europe,Northern Europe,Ukraine,Middle East,Egypt,North Africa,Western Europe",
		"Ukraine,Europe,Ural,Afghanistan,Middle East,Southern Europe,Northern Europe,Scandinavia",
		"Middle East,Asia,Ukraine,Afghanistan,India,Southern Europe,Egypt,East Africa",
		"Ural,Asia,Siberia,China,Afghanistan,Ukraine",
		"Afghanistan,Asia,Ural,China,India,Middle East,Ukraine",
		"India,Asia,China,Siam,Afghanistan,Middle East",
		"Siberia,Asia,Yatusk,Irkutsk,Mongolia,China,Ural",
		"China,Asia,Ural,Siberia,Mongolia,Siam,India,Afghanistan",
		"Siam,Asia,China,India,Indonesia",
		"Mongolia,Asia,Siberia,Irkutsk,Japan,China,Kamchatka",
		"Irkutsk,Asia,Siberia,Yatusk,Kamchatka,Mongolia",
		"Yatusk,Asia,Siberia,Irkutsk,Kamchatka",
		"Kamchatka,Asia,Yatusk,Irkutsk,Japan,Alaska,Mongolia",
		"Japan,Asia,Kamchatka,Mongolia",
		"Indonesia,Australia,Siam,New Guinea,Western Australia",
		"New Guinea,Australia,Indonesia,Western Australia,Eastern Australia",
		"Western Australia,Australia,Indonesia,New Guinea,Eastern Australia",
		"Eastern Australia,Australia,Western Australia,New Guinea"
	};


	Map map1;
	Graph map_1 = map1.generate_map(map_info_vector);

	// Not accepted map
	map_info_vector.push_back("Eastern Australia,North America,Western Australia,New Guinea");
	Map map2;
	try {
		Graph map_2 = map2.generate_map(map_info_vector);
		map2.print_all_edges(map_2);
	} catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}

// Test for MapLoader
void mapLoaderDriver() {

	try {
		Map map1 = read_map_file("World1.map");
	} catch (std::exception e) {
		cout << e.what() << endl;
		cout << endl;
	}

	try {
		Map map2 = read_map_file("World2.map");
	} catch (std::exception e) {
		cout << e.what() << endl;
		cout << endl;
	}

	Map map = read_map_file("World.map");
	std::cout << std::endl;

	map.print_all_edges(map.get_graph());
	map.print_all_vertices(map.get_graph());
	std::cout << "Continents: ";
	for (auto continent : map.get_continents()) {
		std::cout << continent << " ";
	}
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;

	Vertex v = map.find_country_vertex("Alaska");
	map.traverse_edges(v);

	std::cout << std::endl;
}

// Test for PlayerDriver
void playerDriver() {
	Map map = read_map_file("World.map");

	Player player("Bob");

	Vertex x = map.find_country_vertex("Alaska");
	player.add_country(x, map);
	x = map.find_country_vertex("Ontario");
	player.add_country(x, map);
	x = map.find_country_vertex("Quebec");
	player.add_country(x, map);

	for (Vertex v : player.getCountries()) {
		std::cout << map.get_graph()[v].country << " is owned by " << map.get_graph()[v].player->getName() << std::endl;
	}

	std::cout << std::endl;
}

// Test for CardDeck/HandDriver
void cardDeckDriver() {
	int numberOfCountries = 42;

	Deck game(numberOfCountries);
	Hand player;

	srand(time(0));
	for (int i = 0; i < numberOfCountries; i++) {
		game.draw(player.hand);
		//call exchange() for random values
		if (i == 2 || i == 3 || i == 4)
			cout << "Number of armies:" << player.exchange() << endl;
	}

	int infantry = 0, cavalry = 0, artillery = 0;
	for (int i = 0; i < player.hand.size(); i++) {
		if (player.hand[i] == 1)
			infantry++;
		else if (player.hand[i] == 2)
			cavalry++;
		else
			artillery++;
	}

	cout << endl << "There are: " << infantry << " infantry, " << artillery << " artilleries and "
		<< cavalry << " cavalry." << endl;
}

// Helper method to display container
void printContainer(vector<int> &MyV) {
	for (unsigned int i = 0; i < MyV.size(); ++i) {
		cout << MyV.at(i) << " ";
	}
	cout << endl;
}
