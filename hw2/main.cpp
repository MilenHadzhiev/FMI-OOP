#include <iostream>
#include "Control.h"
#include "Control_children.h"
#include <cstring>

int main() {
//    Size s(1, 2);
//    Position pos(2, 2);
//    Control con(pos, s, "Etiket", output);
//    std::cout << con.get_text();
//    Label new_asd(pos, "Etiket");
//    Label asasss(new_asd);
//
//
//    Checkbox cb1(pos, "Check here", true);
//    Checkbox cb2(pos, "Don't Check here", false);
//    Checkbox* ofa;
//    ofa[0] = cb1;
//    ofa[1] = cb2;
    while(true) {
        std::cout << "Choose from the following:\n"
                     "0 to exit\n"
                     "1 to display the Form\n"
                     "2 to view Labels\n"
                     "3 to view and edit Checkboxes\n"
                     "4 to view and edit Radio Buttons\n"
                     "5 to view and edit Text Boxes\n"
                     "6 to choose from List Boxes\n"
                     "7 to choose a Panel to be displayed\n";
        unsigned short input;
        std::cin >> input;
        if (input == 0) {
            break;
        }

        if (input == 1) {
            // add stuff
        } else {
            std::cout << "Invalid input. Please ";
        }
    }
    return 0;
}