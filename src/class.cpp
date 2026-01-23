#include "class.h"

Class::Class()
    : Class(nullptr)
{

}

Class::Class(Class* super)
    : super(super)
{
}