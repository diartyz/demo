#include "SpreadsheetCell.h"

#include <iostream>
#include <string>

void printCell(const SpreadsheetCell& cell)
{
    std::cout << cell.getString() << std::endl;
}

SpreadsheetCell::SpreadsheetCell(double value) : value_(value) {}

SpreadsheetCell::SpreadsheetCell(std::string_view str)
    : value_(stringToDouble(str))
{
    setString(str);
}

void SpreadsheetCell::setValue(double value)
{
    value_ = value;
}

double SpreadsheetCell::getValue() const
{
    return value_;
}

void SpreadsheetCell::setString(std::string_view str)
{
    value_ = stringToDouble(str);
    printCell(*this);
}

std::string SpreadsheetCell::getString() const
{
    return doubleToString(value_);
}

std::string SpreadsheetCell::doubleToString(double value) const
{
    return std::to_string(value);
}

double SpreadsheetCell::stringToDouble(std::string_view str) const
{
    return std::strtod(str.data(), nullptr);
}
