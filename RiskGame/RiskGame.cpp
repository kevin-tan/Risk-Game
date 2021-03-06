 // RiskGame.cpp : Defines the entry point for the console application.
 //

   #include "stdafx.h"
// #include <cstdlib>
// #include <time.h>
// #include "DiceRollingFacility.h"
// #include "MapLoader.h"
// #include "Player.h"
// #include "Hand.h"
// #include "Deck.h"
//
// using namespace std;
//
// void diceDriver();
// void mapDriver();
// void mapTraversalDriver();
// void playerDriver();
// void cardDeckDriver();
// void printContainer(vector<int>& MyV);
// void print_hand(Hand* hand, Deck* deck);
//
// int main() {
// 	char ans = 'y';
// 	int choice = 0;
// 	do {
// 		printf("Choose the driver you want to run: \n");
// 		printf("[0] Dice Driver\n");
// 		printf("[1] Map/Map Loader Driver\n");
// 		printf("[2] Map Traversal Driver (RUN LAST)\n");
// 		printf("[3] Player Driver\n");
// 		printf("[4] Card Deck Driver\n");
// 		cin >> choice;
//
// 		switch (choice) {
// 		case 0:
// 			diceDriver();
// 			break;
// 		case 1:
// 			mapDriver();
// 			break;
// 		case 2:
// 			mapTraversalDriver();
// 			break;
// 		case 3:
// 			playerDriver();
// 			break;
// 		case 4:
// 			cardDeckDriver();
// 			break;
// 		default: break;
// 		}
//
// 		cout << "Do you wish to run another driver? (y/n)" << endl;
// 		cin >> ans;
//
// 	} while (ans == 'y');
//
// 	return 0;
// }
//
// // Test for DiceDriver
// void diceDriver() {
// 	srand(time(0)); // Unique pattern for the rand() function. MUST BE first statement in main function!
//
// 	// Two Dice Rolling objects with respective containers
// 	DiceRollingFacility obj1, obj2;
// 	vector<int> container1, container2;
// 	int number_of_dice;
// 	char repeat;
// 	do {
// 		// Test object 1
// 		cout << "\nTest for the first object" << endl;
// 		cout << "How many dice would you like to roll (1-3)?";
// 		cin >> number_of_dice;
// 		container1 = obj1.rollDice(number_of_dice);
// 		cout << "Container values: ";
// 		printContainer(container1);
// 		cout << "Percentage of rolls " << endl;
// 		obj1.displayPercentArr();
//
// 		// Test object 2
// 		cout << "\nTest for the second object" << endl;
// 		cout << "How many dice would you like to roll (1-3)?";
// 		cin >> number_of_dice;
// 		container2 = obj2.rollDice(number_of_dice);
// 		cout << "Container values: ";
// 		printContainer(container2);
// 		cout << "Percentage of rolls: " << endl;
// 		obj2.displayPercentArr();
//
// 		// Run test again
// 		cout << "\nRepeat test? (y/n): ";
// 		cin >> repeat;
// 	} while (repeat != 'n');
//
// 	//	 Test for the equal share of rolls
// 	for (int i = 0; i < 500; ++i) {
// 		obj1.rollDice(3);
// 	}
// 	cout << "\nRolling 500 dice to show equal share of rolls: " << endl;
// 	obj1.displayPercentArr();
// 	cout << endl;
// }
//
// // Test for MapDriver
// void mapDriver() {
// 	int next;
// 	int choice;
//
// 	cout << "Would you like to enter your own file (1) or proceed with pre-made test cases (2)?" << endl;
// 	cin >> choice;
//
// 	if (choice == 1) {
// 		//Enter your own map
// 		string given_map_file;
// 		cout << "Enter map file: " << endl;
// 		cin >> given_map_file;
// 		try {
// 			Map given_map = read_map_file(given_map_file);
// 			given_map.print_all_vertices(given_map.get_graph());
// 		}
// 		catch (exception e) {
// 			cout << e.what() << endl;
// 		}
// 	}
// 	else if (choice == 2) {
// 		//Invalid map (territory belonging to two continents)
// 		string territory_two_continents_map_file = "Maps/TerritoryTwoContinents.map";
// 		cout << "Running invalid test case #1 (Territory belongs to two continents)" << "\nOpening " <<
// 			territory_two_continents_map_file << " ..." << endl;
// 		try {
// 			Map territory_two_continents = read_map_file(territory_two_continents_map_file);
// 		}
// 		catch (exception e) {
// 			cout << e.what() << endl;
// 		}
// 		cout << "Move to next case: " << endl;
// 		cin >> next;
// 		cout << "\n-------------------------------------------\n";
//
// 		//Map file cannot be read (invalid format/does not exist)
// 		string map_file_dne = "Maps/DoesNotExist.map";
// 		cout << "Running invalid test case #2 (Map file cannot be read/does not exist)" << "\nOpening " << map_file_dne
// 			<<
// 			" ..." << endl;
// 		try {
// 			Map dne_map = read_map_file(map_file_dne);
// 		}
// 		catch (exception e) {
// 			cout << e.what() << endl;
// 		}
// 		cout << "Move to next case: " << endl;
// 		cin >> next;
// 		cout << "\n-------------------------------------------\n";
//
// 		//Map file continents section cannot be read
// 		string invalid_continents_map_file = "Maps/InvalidContinents.map";
// 		cout << "Running invalid test case #3 (Continents section cannot be parsed)" << "\nOpening " <<
// 			invalid_continents_map_file <<
// 			" ..." << endl;
// 		try {
// 			Map invalid_continents = read_map_file(invalid_continents_map_file);
// 		}
// 		catch (exception e) {
// 			cout << e.what() << endl;
// 		}
// 		cout << "Move to next case: " << endl;
// 		cin >> next;
// 		cout << "\n-------------------------------------------\n";
//
// 		//Map file territories section cannot be read
// 		string invalid_territories_map_file = "Maps/InvalidTerritories.map";
// 		cout << "Running invalid test case #4 (Territories section cannot be parsed/Unconnected territory)" <<
// 			"\nOpening "
// 			<< invalid_territories_map_file <<
// 			" ..." << endl;
// 		try {
// 			Map invalid_territories = read_map_file(invalid_territories_map_file);
// 		}
// 		catch (exception e) {
// 			cout << e.what() << endl;
// 		}
// 		cout << "Move to next case: " << endl;
// 		cin >> next;
// 		cout << "\n-------------------------------------------\n";
//
// 		//Valid map file
// 		string valid_map_file = "Maps/World.map";
// 		cout << "Running valid test case" << "\nOpening " << valid_map_file << " ..." << endl;
// 		try {
// 			Map valid_map = read_map_file(valid_map_file);
// 			valid_map.print_all_vertices(valid_map.get_graph());
// 		}
// 		catch (exception e) {
// 			cout << e.what() << endl;
// 		}
// 	}
//
// 	cout << endl;
// }
//
// // Test for Map Traversal
// void mapTraversalDriver() {
//
// 	Map map = read_map_file("Maps/World.map");
// 	std::cout << std::endl;
//
// 	Vertex v = map.find_country_vertex("Alaska");
// 	map.traverse_edges(v);
//
// 	std::cout << std::endl;
// }
//
// // Test for PlayerDriver
// void playerDriver() {
// 	vector<int> container;
// 	Deck deck(42);
// 	Map map = read_map_file("World.map");
//
// 	Player player;
//
// 	Vertex x = map.find_country_vertex("Alaska");
// 	player.add_country(x, map);
// 	x = map.find_country_vertex("Ontario");
// 	player.add_country(x, map);
// 	x = map.find_country_vertex("Quebec");
// 	player.add_country(x, map);
//
// 	cout << "Showing that player owns a collection of countries..." << endl;
// 	for (Vertex v : player.get_countries()) {
// 		cout << map.get_graph()[v].country << " is owned by " << map.get_graph()[v].player << endl;
// 	}
//
// 	cout << "\n-------------------------------------------\n";
//
// 	cout << "Showing that player owns a dice rolling facility..." << endl;
// 	cout << "Rolling 3 dice 2 times..." << endl;
// 	for (int i = 0; i < 2; i++) {
// 		container = player.get_dice_rolling_facility()->rollDice(3);
// 		printContainer(container);
// 	}
// 	cout << "Results ..." << endl;
// 	player.get_dice_rolling_facility()->displayPercentArr();
//
// 	cout << "\n-------------------------------------------\n";
//
// 	cout << "Showing that player owns a hand of Risk cards..." << endl;
// 	cout << "Drawing 6 cards..." << endl;
// 	
// 	for (int i = 0; i < 6; i++) {
// 		deck.draw(player.get_hand());
// 	}
// 	print_hand(player.get_hand(), &deck);
//
// 	cout << "\n-------------------------------------------\n";
//
// 	cout << "Showing that player implements reinforce(), attack(), fortify()" << endl;
// 	player.attack();
// 	player.reinforce();
// 	player.fortify();
//
// 	std::cout << std::endl;
// }
//
// // Test for CardDeck/HandDriver
// void cardDeckDriver() {
// 	int number_of_countries = 42;
// 	int choice;
//
// 	cout << "Creating new deck..." << endl;
// 	cout << "Creating new hand..." << endl;
// 	Deck deck(number_of_countries);
// 	Hand hand;
//
// 	cout << "Verifying number of each type of card in deck..." << endl;
//
// 	cout << endl << "There are: " << deck.get_number_of_infantry() << " infantry cards, " << deck.get_number_of_artillery() << " artillery cards, and "
// 		<< deck.get_number_of_cavalry() << " cavalry cards in this deck of " << deck.get_deck_size() << " cards." << endl;
//
// 	srand(time(0));
//
// 	cout << "\nInitially drawing 6 cards into hand..." << endl;
// 	for (int i = 0; i < 6; i++) {
// 		deck.draw(&hand);
// 	}
// 	print_hand(&hand, &deck);
//
// 	cout << "-------------------------------------------\n";
// 	cout << "Press 1 to draw a card\nPress 2 to exchange your cards\nPress 3 to stop" << endl;
// 	cin >> choice;
// 	do {
// 		if (choice == 1) {
// 			deck.draw(&hand);
// 			print_hand(&hand, &deck);
// 		}
// 		else if (choice == 2) {
// 			int number_of_armies = hand.exchange(&deck);
// 			cout << "Received " << number_of_armies << " armies" << endl;
// 			print_hand(&hand, &deck);
// 		}
//
// 		cout << "-------------------------------------------\n";
// 		cout << "Press 1 to draw a card\nPress 2 to exchange your cards\nPress 3 to stop" << endl;
// 		cin >> choice;
// 	} while (choice != 3);
// }
//
// // Helper method to display container
// void printContainer(vector<int>& MyV) {
// 	for (unsigned int i = 0; i < MyV.size(); ++i) {
// 		cout << MyV.at(i) << " ";
// 	}
// 	cout << endl;
// }
//
// void print_hand(Hand* hand, Deck* deck) {
// 	cout << "Current hand:\n" << "Infantry cards: " << hand->get_number_of_infantry() << "\nArtillery cards: " << hand->get_number_of_artillery() <<
// 		"\nCavalry cards: " << hand->get_number_of_cavalry() << endl;
//
// 	cout << "\nCurrent number of cards in the deck: " << deck->get_deck_size() << endl << endl;
// }
