#include "Form.h"
#include <cstring>

void Form::copy_controls(Control *new_controls, int count) {
    for (int i = 0; i < count; i++) {
        controls[i] = new_controls[i];
    }
}

Form::Form() {
    name = new char[strlen("No name")];
    strcpy(name, "No name");
    controls = nullptr;
    controls_count = 0;
}

Form::Form(const char *new_name, Control *new_controls, int new_controls_count) {
    name = new char[strlen(new_name)];
    strcpy(name, new_name);
    controls_count = new_controls_count;
    controls = new Control[controls_count];
    copy_controls(new_controls, new_controls_count);
}

Form::Form(Form &other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.get_name())];
        strcpy(name, other.get_name());
        delete[] controls;
        controls_count = other.get_controls_count();
        controls = new Control[controls_count];
        copy_controls(other.controls, controls_count);

    }
}

Form::~Form() {
    delete[] name;
    delete[] controls;
}

Control* Form::get_control_by_id(int id_to_find) {
    Control to_return;
    for (int i = 0; i < controls_count; i++) {
        if (id_to_find == controls[i].get_unique_id()) {
            return &controls[i];
        }
    }
    return nullptr;
}

void Form::display_form() {

}