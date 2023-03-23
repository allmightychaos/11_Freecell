#include <iostream>
#include <iomanip>

#include "cardstack.h"

Cardstack::Cardstack(std::string name, int x, int y, Stacktype stack_type, int cards, Card *card_array[])
{
    this->name = name;
    this->x = x;
    this->y = y;
    this->stack_type = stack_type;
    //vervollständigen
}

void Cardstack::print()
{
    std::cout << "\033[" << y << ";" << x << "H" << name;
    if(first == nullptr)
    {
        std::cout << "\033[" << y + 1 << ";" << x << "H┌┄┄┄┐";
        std::cout << "\033[" << y + 2 << ";" << x << "H┆   ┆";
        std::cout << "\033[" << y + 3 << ";" << x << "H┆   ┆";
        std::cout << "\033[" << y + 4 << ";" << x << "H└┄┄┄┘";
    }
    else
    {
        if(stack_type == Target)
        {
            first->get_last_card()->print(x, y + 1);
        }
        else
        {
            first->print(x, y + 1);
        }
    }
}

Card *Cardstack::remove_last_card()
{
    //vervollständigen
    return nullptr;
}

Card *Cardstack::get_last_card()
{
    //vervollständigen
    return nullptr;
}

bool Cardstack::can_place_card(Card *card)
{
    //vervollständigen
    return false;
}

void Cardstack::add_card(Card *card)
{
    //vervollständigen
}