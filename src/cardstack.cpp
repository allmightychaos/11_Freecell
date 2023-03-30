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

    for (size_t i = 0; i < cards; i++)
    {
        add_card(card_array[i]);
    }
    

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
    if (first == nullptr)
    {
        return first;

    }
    else
    {
        return first->remove_last_card();
    }
    
}

Card *Cardstack::get_last_card()
{
    //vervollständigen
    if (first == nullptr)
    {
        return first;
    }
    else
    {
        return first->get_last_card();
    }
    
    
    return nullptr;
}

bool Cardstack::can_place_card(Card *card)
{
    //vervollständigen
    Card *last = get_last_card();
    
    if (stack_type == Free && first != nullptr)
    {
        return false;
    }

    if (stack_type == Game && last->get_value() - 1 != card->get_value())
    {
        return false;
    }

    if (stack_type == Game)
    {
        if ((last->get_suite() == card->get_suite()) || (last->get_suite() == Heart && card->get_suite() == Diamond) || (last->get_suite() == Club && card->get_suite() == Spade))
        {
            return false;
        }
    }
    
    if (stack_type == Target)
    {
        if (last == nullptr)
        {
            if (card->get_value() == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        if (last->get_value() + 1 != card->get_value())
        {
            return false;
        }
        
    }
    

    return true;
}

void Cardstack::add_card(Card *card)
{
    //vervollständigen

    if (first == nullptr)
    {
        first = card;
    }
    else
    {
        first->add_card(card);
    }
}