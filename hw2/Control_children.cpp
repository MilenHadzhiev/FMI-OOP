#include <cstring>
#include "Control_children.h"
#include "iostream"

Label::Label() : Control() {
    text = strdup("Empty");
    state = strdup("Empty");
    size = Size(1, strlen(text));
    position = Position(0, 0);
}

Label::Label(
        Position &new_position,
        const char *new_text,
        inout new_type
) {
    int text_len = strlen(new_text);
    position = new_position;
    size = Size(1, text_len);
    type = new_type;
    text = new char[text_len];
    strcpy(text, new_text);
    state = new char[text_len];
    strcpy(state, new_text);
}
// THIS IS WRONG
//Checkbox::Checkbox(
//        Position &new_pos,
//        Size &new_size,
//        const char *new_text,
//        inout new_type,
//        bool is_checked
//        ) : Control(
//                new_pos,
//                new_size,
//                new_text,
//                new_type
//                ) {
//    this->is_checked = is_checked;
//}

Checkbox::Checkbox(Checkbox &other) : Control(other) {
    is_checked = other.is_it_checked();
}

bool Checkbox::is_it_checked() const {
    return is_checked;
}
//
//const char* Checkbox::get_state() const {
//    std::cout <<
//    if (is_checked) {
//        std::cout << 'X';
//    } else {
//        std::cout << ' ';
//    }
//}