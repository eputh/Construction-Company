//
//
// Name: Emily Puth
// ID: 28239807
//
//

#include "roof-and-fence-constants.hpp"
#include "calculations.hpp"

using namespace std;

int numFenceRolls = 0;
int numRoofBundles = 0;
int totalCost = 0;

// calculates and returns the number of bundles or rolls the user needs
// for their space
int calculateNeedQuantity(int lengthOrCover, float userWants) {
	return ceil(userWants/lengthOrCover);
}	

// prompts the user to input the perimeter of the area
// needing fencing - outputs the result
void fencePrompt(int l, int p) {
	float length = 0;
	cout << "What is the perimeter of the area you need to fence? ";
	cin >> length;

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please try again." << endl;
		fencePrompt(l,p);
	}
	else{
		int rolls = calculateNeedQuantity(l, length);
		numFenceRolls += rolls;
		cout << "You need " << rolls << " rolls" << endl;
	
		int cost = rolls * p;
		totalCost += cost;
		cout << "The cost for this fence is $" << cost << "\n\n";
	}
}

// prompts the user to input the square feet of
// the roof needed to be covered
void roofPrompt(int c, int p) {
	float squareFeet = 0;
	cout << "How many square feet is your roof? ";
	cin >> squareFeet;

	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Please try again." << endl;
		roofPrompt(c,p);
	}
	else {
		int bundles = calculateNeedQuantity(c, squareFeet);
		numRoofBundles += bundles;
		cout << "You need " << bundles << " bundles" << endl;

		int cost = bundles * p;
		totalCost += cost;
		cout << "The cost for this roof is $" << cost << "\n\n";
	}
}


int main() {
	int choice = 0;
	cout << "Welcome to Construction Co." << endl;
	while (choice != 6) {
		
		cout << "Choose a product from the list below." << endl
		<< "1. Wooden Fence" << endl
		<< "2. Chain link Fence" << endl
		<< "3. Tile Roof" << endl
		<< "4. Shingle Roof" << endl
		<< "5. Metal Roof" << endl
		<< "6. Quit and display order totals" << endl;
		cout << "Enter the number corresponding to your choice: ";
		cin >> choice;
		if (!cin) {cin.clear(); cin.ignore(256, '\n');}
		switch(choice)
		{
		case WOODEN_FENCE:
			fencePrompt(WOODEN_FENCE_LENGTH, WOODEN_FENCE_PRICE);
			break;
		case CHAIN_LINK_FENCE:
			fencePrompt(CHAIN_LINK_FENCE_LENGTH, CHAIN_LINK_FENCE_PRICE);
			break;
		case TILE_ROOF:
			roofPrompt(TILE_ROOF_COVER, TILE_ROOF_PRICE);
			break;
		case SHINGLE_ROOF:
			roofPrompt(SHINGLE_ROOF_COVER, SHINGLE_ROOF_PRICE);
			break;
		case METAL_ROOF:
			roofPrompt(METAL_ROOF_COVER, METAL_ROOF_PRICE);
			break;
		case QUIT_AND_DISPLAY:
			cout << "\n\nNumber of Fence Rolls needed: " << numFenceRolls << endl;
			cout << "Number of Roof Bundles needed: " << numRoofBundles << endl;
			cout << "Total cost of the project: $" << totalCost << "\n\n\n";
			break;
		default:
			cout << "You did not pick a valid option. Try again." << endl;
			break;
		}
	}
	return 0;
}	
	
