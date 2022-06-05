#ifndef HW2_FORM_H
#define HW2_FORM_H
#include "Control.h"

class Form{
    char* name;
    Control* controls;
public:
    Form();
    Form(const char* new_name, Control* new_controls);
    Form(Form& other);

};
#endif //HW2_FORM_H
