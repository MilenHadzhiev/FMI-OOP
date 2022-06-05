#include <cstring>
#include "Control_children.h"
#include "iostream"

// LABEL
Label::Label() {
    text = strdup("Empty");
    text_len = strlen(text);
    size = Size(1, text_len);
    position = Position(0, 0);
    type = output;
}

Label::Label(
        Position &new_position,
        const char *new_text
) {
    text_len = strlen(new_text);
    position = new_position;
    size = Size(1, text_len);
    type = output;
    text = new char[text_len];
    strcpy(text, new_text);
}


//CHECKBOX

void Checkbox::copy_text(char *dest, const char *source, int new_text_len) {
    delete[] dest;
    dest = new char[new_text_len];
    text_len = new_text_len;
    dest[0] = '[';
    dest[1] = is_checked ? 'X' : ' ';
    dest[2] = ']';
    dest[3] = ' ';
    for (int i = 4; i < new_text_len; i++) {
        dest[i] = source[i - 4];
    }
}

Checkbox::Checkbox() {
    text_len = strlen("Empty") + 4;
    text = new char[text_len];
    copy_text(text, "Empty", text_len);
    size = Size(1, text_len);
    position = Position(0, 0);
    is_checked = false;
    type = input;
}

Checkbox::Checkbox(
        Position &new_pos,
        const char *new_text,
        bool is_checked
) {
    type = input;
    text_len = strlen(new_text) + 4;
    position = new_pos;
    size = Size(1, text_len);
    text = new char[text_len];
    copy_text(text, new_text, text_len);
    this->is_checked = is_checked;
}

Checkbox::Checkbox(Checkbox &other) {
    is_checked = other.is_it_checked();
    text_len = other.text_len;
    position = other.get_position();
    size = other.get_size();
    type = input;
    delete[] text;
    text = new char[text_len];
    copy_text(text, other.get_text(), text_len);
}

bool Checkbox::is_it_checked() const {
    return is_checked;
}

//RADIOBUTTON

Checkbox& RadioButton::get_longest_text_option(Checkbox *options, unsigned short options_count) {

    //Checkbox longest(options[0]); // longest option
    int index = 0;
    unsigned int n = options[index].get_size().get_length(); // length of longest option text
    for (int i = 1; i < options_count; i++) {
        int m = options[i].get_size().get_length(); // current option text length
        if (m > n) {
            n = m;
            index = i;
//            longest = options[i];
        }
    }
    return options[index]; // warning: Reference to stack memory associated with local variable 'longest' returned
}

void RadioButton::set_text(const char *new_text) {
    int temp = strlen(new_text); // temp var to hold text len to avoid invoking the function three separate times
    delete[] text;
    text = new char[temp];
    text[0] = '[';
    text[1] = ' ';
    text[2] = ']';
    text[3] = ' ';
    for (int i = 4; i < temp; i++) {
        text[i] = new_text[i - 4];
    }
}

void RadioButton::copy_longest_text(char *dest, Checkbox& source) {
    delete[] dest;
    int temp = source.get_text_len(); // temp var to hold text len to avoid invoking the function three separate times
    dest = new char[temp];
//    dest[0] = '[';
//    dest[1] = source.is_it_checked() ? 'X' : ' ';
//    dest[2] = ']';
//    dest[3] = ' ';
    const char* temp_str = source.get_text();
    for (int i = 4; i < temp; i++) {
        dest[i] = temp_str[i - 4];
    }
    delete[] temp_str;
    text_len = temp;
}

int RadioButton::find_selected_option_id(Checkbox *options, unsigned short options_count) {
    int n = -1;
    for (int i = 0; i < options_count; i++) {
        if (n == -1 && options[i].is_it_checked()) {
            n = i;
        } else {
            options[i].set_false();
        }
    }
    return n;
}

void RadioButton::copy_options(Checkbox *new_options, unsigned short new_options_count) {
    delete[] options;
    options = new Checkbox[new_options_count];
    for (int i = 0; i < new_options_count; i++) {
        options[i] = new_options[i];
    }
    options_count = new_options_count;
}

RadioButton::RadioButton() { // initializes object with these default values
    type = input; // radio buttons are always an input control
    options_count = 1;
    text_len = strlen("[ ] Empty RadioButton") + 4;
    text = new char[text_len];
    strcpy(text, "[ ] Empty RadioButton");
    position = Position(0, 0);
    size = Size(1, text_len);
    options = new Checkbox[options_count];
    selected_option = -1;
    options[0] = Checkbox(position, text, false);
}

RadioButton::RadioButton(
        Position &new_pos,
        unsigned short new_options_count,
        Checkbox *new_options
) {
    type = input;
    position = new_pos;
    options_count = new_options_count;
    options = new Checkbox[options_count];
    copy_options(new_options, new_options_count);
    selected_option = find_selected_option_id(new_options, new_options_count);
    Checkbox longest = get_longest_text_option(new_options, new_options_count);

    text_len = longest.get_text_len();
    text = new char[text_len];
    copy_longest_text(text, longest);
}

RadioButton::RadioButton(RadioButton &other) {
    *this = other;
//    delete[] options;
//    delete[] text;
//    type = input;
//    position = other.get_position();
//    size = other.get_size();
//    options_count = other.get_options_count();
//    options = new Checkbox[options_count];
//    copy_options(other.options, options_count);
//    selected_option = other.get_selected_option_index();
//    text_len = other.get_text_len();
//    text = new char[text_len];
//    Checkbox::copy_text(text, other.get_text(), text_len);
}

RadioButton& RadioButton::operator=(RadioButton &other) {
    if (this == &other) {
        return *this;
    }
    delete[] options;
    delete[] text;
    type = input;
    position = other.get_position();
    size = other.get_size();
    options_count = other.get_options_count();
    options = new Checkbox[options_count];
    copy_options(other.options, options_count);
    selected_option = other.get_selected_option_index();
    text_len = other.get_text_len();
    text = new char[text_len];
    set_text(other.get_text());
    return *this;
}

void RadioButton::add_option(Checkbox &new_option) {
    options[options_count] = new_option;
    options_count++;
}

// Textbox


TextBox::TextBox(Position &new_pos, Size &new_size) {

}

TextBox::TextBox(TextBox &other) {

}

const char* TextBox::get_state() const {
    return ":as";// not finished
}


