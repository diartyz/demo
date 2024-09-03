#include "Spreadsheet.h"

#include <cstddef>
#include <stdexcept>
#include <utility>

Spreadsheet::Spreadsheet(size_t width, size_t height)
    : width_(width), height_(height)
{
    cells_ = new SpreadsheetCell*[width];
    for (size_t i = 0; i < width; ++i) {
        cells_[i] = new SpreadsheetCell[height];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet& other)
    : Spreadsheet(other.width_, other.height_)
{
    for (size_t i = 0; i < width_; ++i) {
        for (size_t j = 0; j < height_; ++j) {
            cells_[i][j] = other.cells_[i][j];
        }
    }
}

Spreadsheet::Spreadsheet(Spreadsheet&& other) noexcept
{
    std::swap(*this, other);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
    if (this == &rhs) {
        return *this;
    }

    Spreadsheet temp(rhs);
    std::swap(this->width_, rhs.width_);
    std::swap(this->height_, rhs.height_);
    std::swap(this->cells_, rhs.cells_);
    return *this;
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept
{
    Spreadsheet temp(std::move(rhs));
    std::swap(*this, temp);
    return *this;
}

Spreadsheet::~Spreadsheet()
{
    for (size_t i = 0; i < width_; ++i) {
        delete[] cells_[i];
    }
    delete[] cells_;
    cells_ = nullptr;
    width_ = height_ = 0;
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
    verifyCoordinate(x, y);
    cells_[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
    verifyCoordinate(x, y);
    return cells_[x][y];
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= width_ || y >= height_) {
        throw std::out_of_range("Coordinates are out of bounds.");
    }
}
