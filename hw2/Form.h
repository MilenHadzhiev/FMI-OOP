#ifndef HW2_FORM_H
#define HW2_FORM_H

#include "Control.h"

class Form {
    char *name;
    Control *controls;
    int controls_count;

    void copy_controls(Control *new_controls, int count);

public:
    Form();

    Form(const char *new_name, Control *new_controls, int new_controls_count);

    Form(Form &other);

    ~Form();

    void display_form();

    const char *get_name() const { return name; };

    int get_controls_count() const { return controls_count; };

    Control *get_control_by_id(int id_to_find);
};

#endif //HW2_FORM_H
