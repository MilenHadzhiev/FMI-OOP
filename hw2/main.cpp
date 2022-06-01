#include <iostream>
#include "Control.h"
#include "Control_children.h"
#include "string.h"
int main() {
    Size s(1, 2);
    Position pos(2, 2);
    Control con(pos, s, "Etiket", output);
    std::cout << con.get_text();
    Label new_asd(pos, "Etiket", output);
    Label asasss(new_asd);
    std::cout << asasss.get_state();
//    unsigned short input;
//    while(true) {
//        if (input == 0) {
//            break;
//        }
//
//        if (input == 1) {
//            // add stuff
//        } else {
//            std::cout << "Invalid input";
//        }
//    }
    return 0;
}