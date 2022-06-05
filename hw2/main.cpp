#include <iostream>
#include "Control.h"
#include "Control_children.h"
#include <cstring>
#include "Form.h"

void create_checkbox(Form &form) {
    std::cout << "Enter x coordinate for your Checkbox: ";
    unsigned int new_x;
    unsigned int new_y;

    std::cin >> new_x;

    std::cout << "\nEnter y coordinate for your Checkbox: ";

    std::cin >> new_y;

    std::cout << "\nEnter a short description for your Checkbox: ";

    char* description = new char[2000];
    std::cin >> description;
    std::cout << "\nIs your checkbox checked or not? 0/1";
    bool y_n;
    std::cin >> y_n;
    Position pos(new_x, new_y);

    Checkbox checkbox(pos, description, y_n);

    delete[] description;

    form.add_new_control( checkbox);

}

int main() {
    Form form;

    unsigned short input;
    char *name = new char[1000];

    std::cout << "Enter a name for your form: ";

    std::cin >> name;

    form.set_name(name);

    std::cout << '\n';

    delete[] name;

    while (true) {
        std::cout << "Choose from the following:\n"
                     "0 to exit\n"
                     "1 to display the entire Form\n"
                     "2 to view Labels\n"
                     "3 to view and edit Checkboxes\n"
                     "4 to view and edit Radio Buttons\n"
                     "5 to view and edit Text Boxes\n"
                     "6 to choose from List Boxes\n"
                     "7 to choose a Panel to be displayed\n"
                     "8 to add a new control\n"
                     "9 to change control text";
        std::cin >> input;

        if (input == 0) { break; }

        if (input == 8) {
            while (true) {
                std::cout << "Select control type: \n"
                             "1 for Label\n"
                             "2 for Checkbox\n"
                             "3 for Radio Button\n"
                             "4 for Textbox\n"
                             "5 for Listbox\n"
                             "6 for Panel\n"
                             "0 to go back\n";

                unsigned short control_type;

                std::cin >> control_type;

                if (control_type == 0) { break; }
                if (control_type == 1) {
                    std::cout << "Enter x coordinate for your Label: ";
                    unsigned int new_x;
                    unsigned int new_y;

                    std::cin >> new_x;

                    std::cout << "Enter y coordinate for your Label: ";

                    std::cin >> new_y;

                    std::cout << "Enter a short description for your Label: ";

                    char* description = new char[2000];
                    std::cin >> description;

                    Position pos(new_x, new_y);

                    Label label(pos, description);

                    delete[] description;

                    form.add_new_control(label);
                } else if (control_type == 2) {
                    create_checkbox(form);
                } else if (control_type == 3) {}

            }
        } else {
            std::cout << "Invalid input. Please ";
        }
    }
    return 0;
}