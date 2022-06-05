#include "Control.h"
#include "iostream"
#include <cstring>

int Control::id_counter = 0;

Position::Position() {
    x = 0, y = 0;
}

Position::Position(unsigned int new_x, unsigned int new_y) {
    if (new_x >= 0 && new_y >= 0) {
        x = new_x;
        y = new_y;
    } else {
        throw std::invalid_argument("X and Y coordinates must be integers bigger than or equal to 0.");
    }
}


Position::Position(Position &other) {
    x = other.get_x_coordinate();
    y = other.get_y_coordinate();
}

unsigned int Position::get_x_coordinate() const {
    return x;
}

unsigned int Position::get_y_coordinate() const {
    return y;
}

void Position::set_x_coordinate(unsigned int new_x) {
    if (new_x >= 0) {
        this->x = new_x;
    } else {
        throw std::invalid_argument("X coordinate must be integers bigger than or equal to 0.");
    }
}

void Position::set_y_coordinate(unsigned int new_y) {
    if (new_y >= 0) {
        this->y = new_y;
    } else {
        throw std::invalid_argument("Y coordinate must be integers bigger than or equal to 0.");
    }
}

void Position::change_coordinates(unsigned int new_x, unsigned int new_y) {
    set_x_coordinate(new_x);
    set_y_coordinate(new_y);
}

Position &Position::operator=(const Position &other) {
    change_coordinates(other.get_x_coordinate(), other.get_y_coordinate());
    return *this;
}

Size::Size() {
    height = 1, length = 1;
}

Size::Size(unsigned int new_height, unsigned int new_length) {
    if (new_height <= 0 || new_length <= 0) {
        throw std::invalid_argument("Height and length must be positive real numbers.");
    }
    height = new_height;
    length = new_length;
}

Size::Size(Size &other) {
    height = other.height;
    length = other.length;
}

unsigned int Size::get_height() const {
    return height;
}

unsigned int Size::get_length() const {
    return length;
}

void Size::set_height(unsigned int new_height) {
    if (new_height <= 0) {
        throw std::invalid_argument("Height and length must be positive real numbers.");
    }
    height = new_height;
}

void Size::set_length(unsigned int new_length) {
    if (new_length <= 0) {
        throw std::invalid_argument("Height and length must be positive real numbers.");
    }
    length = new_length;
}

void Size::change_size(unsigned int new_height, unsigned int new_length) {
    if (new_height <= 0 || new_length <= 0) {
        throw std::invalid_argument("Height and length must be positive real numbers.");
    }
    height = new_height;
    length = new_length;
}

Size &Size::operator=(const Size &other) {
    change_size(other.get_height(), other.get_length());
    return *this;
}

Control::Control() {
    text_len = 0;
    size = Size();
    position = Position();
    text = nullptr;
    type = both;

    // unique identification number
    id_counter++;
    unique_id = id_counter;
}

Control::Control(Position &new_pos, Size &new_size, const char *new_text, inout new_type) {
    text_len = strlen(new_text);
    position = new_pos; // no validations needed
    size = new_size;    // position and size would have already been validated
    text = new char[strlen(new_text)];
    strcpy(text, new_text);
    type = new_type;

    // unique identification number
    id_counter++;
    unique_id = id_counter;

}

Control::Control(
        unsigned int new_x,
        unsigned int new_y,
        unsigned int new_height,
        unsigned int new_length,
        const char *new_text,
        inout new_type
        ) {
    try {
        position = Position(new_x, new_y);
    } catch (...) {
        std::cout << "X and Y coordinates must be integers bigger than or equal to 0.";
    }
    try {
        size = Size(new_height, new_length);
    } catch (...) {
        std::cout << "Height and length must be positive real numbers.";
    }
    text_len = strlen(new_text);
    text = new char[text_len];
    strcpy(text, new_text);
    type = new_type;

    // unique identification number
    id_counter++;
    unique_id = id_counter;
}

Control::Control(Control &other) {
    text_len = other.get_text_len();
    position = other.position;
    size = other.size;
    text = new char[strlen(other.get_text())];
    strcpy(text, other.get_text());
    type = other.type;

    // unique identification number
    id_counter++;
    unique_id = id_counter;
}

Control::~Control() {
    delete[] text;
}

Control& Control::operator=(const Control &other) {
    if (&other == this) {
        return *this;
    }

    size = other.size;
    position = other.position;
    type = other.type;
    text = nullptr;
    strcpy(text, other.get_text());

    // id must always be unique even when copying
    // unique identification number
    id_counter++;
    unique_id = id_counter;
    return *this;
}

void Control::set_type_enum(inout new_type) {
    type = new_type;
}

void Control::set_text(const char* new_text) {
    strcpy(text, new_text);
}

void Control::set_position(int x, int y) {
    position.set_x_coordinate(x);
    position.set_y_coordinate(y);
}

int Control::get_unique_id() const {
    return unique_id;
}

Size& Control::get_size() {
    return size;
}

Position& Control::get_position() {
    return position;
}

const char *Control::get_text() const {
    return text;
}

inout Control::get_type() {
    return type;
}

const char *Control::get_type_str() const {
    return type == input ? "Input" : type == output ? "Output" : "Both";
}
