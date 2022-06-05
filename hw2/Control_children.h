#include "Control.h"
#include <cstring>

#ifndef HW2_CONTROL_CHILDREN_H
#define HW2_CONTROL_CHILDREN_H

class Label : public Control { // height = 1; length = len(text);
public:
    Label();

    Label(Position &new_position, const char *new_text);

    Label(Label &other) = default;

};

class Checkbox : public Control { // height = 1; length = 1;
    bool is_checked;

public:

    void
    copy_text(char *dest, const char *source, int new_text_len);// adds [] (and X between them if is_checked) + text

    void set_text(const char *new_text) override {
        copy_text(text, new_text, strlen(new_text) + 4);
    };

    Checkbox();

    Checkbox(Position &new_pos, const char *new_text, bool is_checked);

    Checkbox(Checkbox &other);

    void change_checkbox() { is_checked = !is_checked; };

    void set_false() { is_checked = false; };

    void set_true() { is_checked = true; };

    bool is_it_checked() const;
};

class RadioButton : public Control { // height = options_count; length = len(longest_option);
    unsigned short options_count;
    unsigned short selected_option; // = -1 if no option is selected
    Checkbox *options;

    static Checkbox &get_longest_text_option(
            Checkbox *options,
            unsigned short options_count
    ); // returns ref to the option with longest text;

    static int find_selected_option_id(
            Checkbox *options,
            unsigned short options_count
    ); // returns first id where checkbox.is_checked == true, turns all others to false;


    void copy_longest_text(char *dest, Checkbox &source);// adds [] (and X between them if is_checked) + text

    void set_text(const char *new_text) override;// adds [] (and X between them if is_checked) + text
public:

    RadioButton();

    RadioButton(
            Position &new_pos,
            unsigned short new_options_count,
            Checkbox *new_options
    );

    RadioButton(RadioButton &other);

    RadioButton &operator=(RadioButton &other);

    void copy_options(Checkbox *new_options, unsigned short new_options_count);

    unsigned short get_options_count() const { return options_count; };

    unsigned short get_selected_option_index() const { return selected_option; };

    void add_option(Checkbox &new_option);

};

class TextBox : public Control { // variable size
public:
    TextBox() : Control() {};

    TextBox(Position &new_pos, Size &new_size);

    TextBox(TextBox &other);

    const char *get_state() const;

};

class ListBox : public Control { // height = 1; length = len(longest_element);
};

class Panel : public Control { // size = the minimal that can contain all controls
};


#endif //HW2_CONTROL_CHILDREN_H
