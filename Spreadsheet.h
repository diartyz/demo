#include <cstddef>

#include "SpreadsheetCell.h"

class Spreadsheet {
  public:
    Spreadsheet(size_t width, size_t height);
    Spreadsheet(const Spreadsheet& other);
    Spreadsheet(Spreadsheet&& other) noexcept;
    Spreadsheet& operator=(const Spreadsheet& rhs);
    Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;
    ~Spreadsheet();
    void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
    SpreadsheetCell& getCellAt(size_t x, size_t y) const;

  private:
    Spreadsheet() = default;
    void verifyCoordinate(size_t x, size_t y) const;
    size_t width_;
    size_t height_;
    SpreadsheetCell** cells_;
};
