#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class ICar {
public:
    virtual ~ICar() = default;
    virtual std::string info() const = 0;
};

class Ford : public ICar {
public:
    std::string info() const override
    {
        return "Ford";
    }
};

class Toyoto : public ICar {
public:
    std::string info() const override
    {
        return "Toyota";
    }
};

class CarFactory {
public:
    virtual ~CarFactory() = default;
    std::unique_ptr<ICar> requestCar()
    {
        ++numberOfCarsProduced_;
        return createCar();
    }
    size_t getNumberOfCarsProduced() const
    {
        return numberOfCarsProduced_;
    }

protected:
    virtual std::unique_ptr<ICar> createCar() = 0;

private:
    size_t numberOfCarsProduced_{0};
};

class FordFactory : public CarFactory {
protected:
    std::unique_ptr<ICar> createCar() override
    {
        return std::make_unique<Ford>();
    }
};

class ToyotoFactory : public CarFactory {
protected:
    std::unique_ptr<ICar> createCar() override
    {
        return std::make_unique<Toyoto>();
    }
};

class LeastBusyFactory : public CarFactory {
public:
    explicit LeastBusyFactory(std::vector<std::unique_ptr<CarFactory>>&& factories);

protected:
    std::unique_ptr<ICar> createCar() override;

private:
    std::vector<std::unique_ptr<CarFactory>> factories_;
};

LeastBusyFactory::LeastBusyFactory(std::vector<std::unique_ptr<CarFactory>>&& factories)
    : factories_{std::move(factories)}
{
    if (factories_.empty()) {
        throw std::runtime_error{"No factories provided"};
    }
}

std::unique_ptr<ICar> LeastBusyFactory::createCar()
{
    CarFactory* bestSoFar{factories_[0].get()};
    for (auto& factory : factories_) {
        if (factory->getNumberOfCarsProduced() < bestSoFar->getNumberOfCarsProduced()) {
            bestSoFar = factory.get();
        }
    }
    return bestSoFar->requestCar();
}

int main(int argc, char* argv[])
{
    FordFactory factory;
    auto myCar{factory.requestCar()};
    std::cout << myCar->info() << std::endl;
    return 0;
}
