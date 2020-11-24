#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "dir/addressbook.pb.h"

#include "semantic_map/map.pb.h"
#include "semantic_map/map_clear_area.pb.h"
#include "semantic_map/map_crosswalk.pb.h"
#include "semantic_map/map_junction.pb.h"
#include "semantic_map/map_lane.pb.h"
#include "semantic_map/map_overlap.pb.h"
#include "semantic_map/map_parking_space.pb.h"
#include "semantic_map/map_pnc_junction.pb.h"
#include "semantic_map/map_road.pb.h"
#include "semantic_map/map_rsu.pb.h"
#include "semantic_map/map_signal.pb.h"
#include "semantic_map/map_speed_bump.pb.h"
#include "semantic_map/map_stop_sign.pb.h"
#include "semantic_map/map_yield_sign.pb.h"

using namespace std;

// Iterates though all people in the AddressBook and prints info about them.
void ListPeople(const tutorial::AddressBook &address_book) {
    for (int i = 0; i < address_book.person_size(); i++) {
        const tutorial::Person &person = address_book.person(i);

        cout << "Person ID: " << person.id() << endl;
        cout << "  Name: " << person.name() << endl;
        if (person.has_email()) {
            cout << "  E-mail address: " << person.email() << endl;
        }

        for (int j = 0; j < person.phone_size(); j++) {
            const tutorial::Person::PhoneNumber &phone_number = person.phone(j);

            switch (phone_number.type()) {
            case tutorial::Person::MOBILE:
                cout << "  Mobile phone #: ";
                break;
            case tutorial::Person::HOME:
                cout << "  Home phone #: ";
                break;
            case tutorial::Person::WORK:
                cout << "  Work phone #: ";
                break;
            }
            cout << phone_number.number() << endl;
        }
    }
}

// Main function:  Reads the entire address book from a file and prints all
//   the information inside.
int main(int argc, char *argv[]) {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    tutorial::AddressBook address_book;
    fawai::hdmap::Map map;

    fstream input("/Users/core/Desktop/RoadMap/base_map.bin",
                  ios::in | ios::binary);
    if (!map.ParseFromIstream(&input)) {
        cerr << "Failed to parse address book." << endl;
        return -1;
    }
    // ListPeople(address_book);

    // std::cout << address_book.person_size() << endl;
    std::cout << map.junction_size() << std::endl;
    std::cout << map.lane_size() << std::endl;
    std::cout << map.road_size() << std::endl;

    return 0;
}