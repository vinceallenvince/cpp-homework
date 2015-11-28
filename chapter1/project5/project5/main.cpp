#include <iostream>

int main(int argc, const char * argv[]) {

    int maxCapacity, totalPeople;

    std::cout << "Enter the max capacity for the meeting room. ";
    std::cin >> maxCapacity;

    std::cout << "Enter the total number of people attending. ";
    std::cin >> totalPeople;

    if (totalPeople <= maxCapacity) {
        std::cout << "Enjoy your meeting!";
    } else {
        std::cout << "Your must decline " << totalPeople - maxCapacity << " people to hold the meeting.";
    }

    return 0;
}
