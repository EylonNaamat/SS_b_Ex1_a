/**
 * Demo program for mat exercise.
 * 
 * Author: Tal Zichlinsky
 * Since : 2022-01
 */

#include "mat.hpp"

#include <iostream>
#include <stdexcept>
#include <typeinfo>
using namespace std;

int main() {
	cout << ariel::mat(9, 7, '@', '-') << endl;
/* Should print:
@@@@@@@@@
@-------@
@-@@@@@-@
@-@---@-@
@-@@@@@-@
@-------@
@@@@@@@@@
*/
	cout << ariel::mat(13, 5, '@', '-') << endl; 
/* Should print:
@@@@@@@@@@@@@
@-----------@
@-@@@@@@@@@-@
@-----------@
@@@@@@@@@@@@@
*/

	cout << ariel::mat(9, 7, '@', '$') << endl;
	cout << ariel::mat(9, 7, 1, 2) << endl;
	// cout << typeid(long).name() << endl;
	cout << ariel::mat(1, 1, '@', '$') << endl;
	cout << ariel::mat(int(9.5), int(7.7), '@', '-') << endl;
	// cout << std::string(typeid(1).name()) << endl;

	try {
		cout << ariel::mat(10, 5, '$', '%') << endl; // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Mat size is always odd"
	}
}
