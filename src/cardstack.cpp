#include <iostream>
#include <iomanip>

#include "cardstack.h"

Cardstack::Cardstack(std::string name, int x, int y, Stacktype stack_type, int cards, Card *card_array[]) {
    this->name = name;
    this->x = x;
    this->y = y;
    this->stack_type = stack_type;
    this->first = nullptr;

    for (size_t i = 0; i < cards; i++) {
        add_card(card_array[i]);
    }
}

void Cardstack::print() {
    std::cout << "\033[" << y << ";" << x << "H" << name;
    if(first == nullptr) {
        std::cout << "\033[" << y + 1 << ";" << x << "H┌┄┄┄┐";
        std::cout << "\033[" << y + 2 << ";" << x << "H┆   ┆";
        std::cout << "\033[" << y + 3 << ";" << x << "H┆   ┆";
        std::cout << "\033[" << y + 4 << ";" << x << "H└┄┄┄┘";
    }
    else {
        if(stack_type == Target) {
            first->get_last_card()->print(x, y + 1);
        }
        else {
            first->print(x, y + 1);
        }
    }
}

void Cardstack::add_card(Card *card) {
    if (first == nullptr) {
        first = card;
    }
    else {
        first->add_card(card);
    }
}

Card* Cardstack::remove_last_card() {
    if (this->first == nullptr) {
        return nullptr;
    }
    else {
        return this->first->remove_last_card();
    }

    return nullptr;
}

Card *Cardstack::get_last_card() {
    if (first == nullptr) {
        return nullptr;
    }
    else {
        return first->get_last_card();
    }

    return nullptr;
}

bool Cardstack::can_place_card(Card *card) {
    if (first == nullptr) {
        if (card->get_value() == 13) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        if (card->get_value() == first->get_last_card()->get_value() - 1) {
            if (card->get_suite() == first->get_last_card()->get_suite()) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }

    return false;
}