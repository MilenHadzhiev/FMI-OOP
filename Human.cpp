#include "Human.h"

const char *Human::get_first_name() const {
    return first_name;
}

const char *Human::get_last_name() const {
    return last_name;
}

unsigned short Human::get_age() {
    return age;
}