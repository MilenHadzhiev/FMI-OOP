#ifndef HW2_CONTROL_H
#define HW2_CONTROL_H
enum inout {
    input, output, both
};

class Position {
    unsigned int x, y;
public:
    Position();

    Position(unsigned int new_x,
             unsigned int new_y);  // if 2 controls have the same coordinates the last one called will be shown

    Position(Position &other);

    unsigned int get_x_coordinate() const;

    unsigned int get_y_coordinate() const;

    void set_x_coordinate(unsigned int new_x);

    void set_y_coordinate(unsigned int new_y);

    void change_coordinates(unsigned int new_x, unsigned int new_y);

    Position &operator=(const Position &other);
};

class Size {
    unsigned int height, length;
public:
    Size();

    Size(unsigned int new_height, unsigned int new_length);

    Size(Size &other);

    unsigned int get_length() const;

    unsigned int get_height() const;

    void set_height(unsigned int new_height);

    void set_length(unsigned int new_length);

    void change_size(unsigned int new_height, unsigned int new_length);

    Size &operator=(const Size &other);
};

class Control {
    int unique_id;
    static int id_counter;
protected:
    Size size;
    Position position;
    inout type; // default = both

    char *text;
public:
    Control();

    Control(Position &new_pos, Size &new_size, const char *new_text, inout new_type);

    // ???
    Control(
            unsigned int new_x,
            unsigned int new_y,
            unsigned int new_height,
            unsigned int new_length,
            const char *new_text,
            inout new_type
    ); // if user wants to create a control object without creating new Size and Position objects

    Control(Control &other);

    ~Control();

    Control &operator=(const Control &other);

    void set_type_enum(inout new_type);

    void set_text(const char *new_text);

    int get_unique_id() const;

    Size get_size();

    Position get_position();

    virtual const char *get_text() const;

    inout get_type();

    const char *get_type_text() const;
};

#endif //HW2_CONTROL_H
