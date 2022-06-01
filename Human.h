#ifndef FMI_OOP_HUMAN_H
#define FMI_OOP_HUMAN_H

class Human{
    char* first_name; // 1b
    char* last_name; // 1b
    unsigned short age: 7; // 2b // max age is 127, 128 wraps around to 0
//    Course* courses;
public:
    const char* get_first_name() const;
    const char* get_last_name() const;
    unsigned short get_age();
};

#endif //FMI_OOP_HUMAN_H
