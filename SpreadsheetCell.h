#include <string>
#include <string_view>

class SpreadsheetCell {
  public:
    SpreadsheetCell() = default;
    explicit SpreadsheetCell(double value);
    explicit SpreadsheetCell(std::string_view str);

    void setValue(double inValue);
    double getValue() const;

    void setString(std::string_view str);
    std::string getString() const;

  private:
    std::string doubleToString(double value) const;
    double stringToDouble(std::string_view str) const;

    double value_ = 0;
};
