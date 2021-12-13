#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <utility>


/*
    system configuration base class and it's specified derived types
*/
class SystemConfig
{
public:
    virtual int getX() const = 0;
};
using SystemConfig_t = std::function<std::unique_ptr<SystemConfig>(void)>;

class SystemConfig_x_123 : public SystemConfig
{
public:
    static std::unique_ptr<SystemConfig> create()
    {
        return std::make_unique<SystemConfig_x_123>();
    }

    SystemConfig_x_123()
    {
        x = 5;
    }

    int getX() const override
    {
        return x;
    }

private:
    int x;
};

/*
    network configuration base class and it's specified derived types
*/
class NetworkConfig
{
public:
    virtual int getA() const = 0;
};
using NetworkConfig_t = std::function<std::unique_ptr<NetworkConfig>(void)>;

class NetworkConfig_a_555 : public NetworkConfig
{
public:
    static std::unique_ptr<NetworkConfig> create()
    {
        return std::make_unique<NetworkConfig_a_555>();
    }

    NetworkConfig_a_555()
    {
        a = 555;
    }

    int getA() const override
    {
        return a;
    }

private:
    int a;
};


/*
    test fixture - using vector of variants to hold variable-length number of params
    note: having tuple forces to have explicit number of params
*/
using ParamTypes = std::variant<SystemConfig_t, NetworkConfig_t>;
using MyTestParams = std::vector<ParamTypes>;
class MyTest : public ::testing::TestWithParam<std::vector<ParamTypes>>
{
    public:
    void SetUp() override
    {
        std::cout << "mytest setup" << std::endl;
        auto params = GetParam();
        assert_unqiue(params);
        std::cout << "num of params: " << params.size() << std::endl;
        if (auto creator = getConfig<SystemConfig_t>(params))
        {
            std::cout << "has systemConfig" << std::endl;
            systemConfig = (*creator)();
        }
        else
        {
            FAIL() << "SystemConfig is mandatory in Fixture.";
        }
        if (auto creator = getConfig<NetworkConfig_t>(params))
        {
            std::cout << "has networkConfig" << std::endl;
            networkConfig = (*creator)();
        }
    }

    template<typename T>
    std::optional<T> getConfig(const std::vector<ParamTypes>& params)
    {
        auto it = std::find_if(params.begin(), params.end(), [](const ParamTypes& param){return std::holds_alternative<T>(param);});
        if (it == params.end())
            return {};
        return std::get<T>(*it);
    }

    void assert_unqiue(std::vector<ParamTypes> params)
    {
        auto initialSize = params.size();
        std::sort(params.begin(), params.end(), [](const auto& l, const auto& r)
        {
            return l.index() < r.index();
        });
        auto newEnd = std::unique(params.begin(), params.end(), [](const auto& l, const auto& r)
        {
            return l.index() == r.index();
        });
        params.erase(newEnd, params.end());
        if (initialSize != params.size())
            FAIL() << "Fixture parameters are not unique";
    }

    std::unique_ptr<SystemConfig> systemConfig;
    std::unique_ptr<NetworkConfig> networkConfig;
};

TEST_P(MyTest, t1)
{
    std::cout << "t1" << std::endl;
}

INSTANTIATE_TEST_CASE_P(
        var_len,
        MyTest,
        ::testing::Values(
            MyTestParams{{&SystemConfig_x_123::create, &NetworkConfig_a_555::create}},
            MyTestParams{{&SystemConfig_x_123::create}},
            MyTestParams{{&NetworkConfig_a_555::create}}, // should fail as we said in fixture that SystemConfig is mandatory
            MyTestParams{{&SystemConfig_x_123::create, &NetworkConfig_a_555::create, &SystemConfig_x_123::create}} // fail, not unique
        ));