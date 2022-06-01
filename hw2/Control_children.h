#include "Control.h"
#ifndef HW2_CONTROL_CHILDREN_H
#define HW2_CONTROL_CHILDREN_H

class Label : public Control { // height = 1; length = len(text);
    char* state;
public:
    Label();
    Label(Position& new_position, const char* new_text, inout new_type);
    Label(Label &other) = default;
    const char* get_state() const {
        return get_text(); // Label's state is always its text
    };
};

class Checkbox : public Control { // height = 1; length = 1;
    bool is_checked;
public:
    Checkbox() : Control() { is_checked = false; };
    Checkbox(Position &new_pos, Size &new_size, const char *new_text, inout new_type, bool is_checked);
    Checkbox(Checkbox &other);

    void change_checkbox() {is_checked = !is_checked;};
    bool is_it_checked() const;
    const char* get_state() const;
};

class RadioButton : public Control { // height = options_count; length = len(longest_option);
};

class TexBox : public Control { // variable size
};

class ListBox : public Control { // height = 1; length = len(longest_element);
};

class Panel : public Control { // size = the minimal that can contain all controls
};


#endif //HW2_CONTROL_CHILDREN_H
