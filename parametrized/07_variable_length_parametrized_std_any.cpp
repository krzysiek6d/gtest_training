#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <utility>
#include <typeindex>

/*
    system configuration base class and it's specified derived types
*/
class SystemConfig
{
public:
    virtual int getX() const = 0;
};
using SystemConfig_t = std::unique_ptr<SystemConfig> (*)();

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
using NetworkConfig_t = std::unique_ptr<NetworkConfig> (*)();

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
using MyTestParams = std::vector<std::any>;
class MyTest2 : public ::testing::TestWithParam<std::vector<std::any>>
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
        }
        else
        {
            FAIL() << "SystemConfig is mandatory in Fixture.";
        }
        if (auto creator = getConfig<NetworkConfig_t>(params))
        {
            std::cout << "has networkConfig" << std::endl;
        }
    }


    template<typename T>
    std::optional<T> getConfig(const std::vector<std::any>& v)
    {
        for(auto&& e : v){
            if(auto ptr = std::any_cast<T>(&e)){
                return *ptr;
            }
        }
        return std::nullopt;
    } 

    void assert_unqiue(const std::vector<std::any>& v)
    {
        std::map<std::type_index, int> m;
        for (const auto& e: v)
        {
            m[std::type_index(e.type())]++;
            
            if (m[std::type_index(e.type())] > 1)
            {
                FAIL() << "Fixture parameters are not unique";
            }
        }
    }
};

TEST_P(MyTest2, t1)
{
    //int v = &SystemConfig_x_123::create;
    std::cout << "t1" << std::endl;
}

INSTANTIATE_TEST_CASE_P(
        var_len,
        MyTest2,
        ::testing::Values(
            MyTestParams{{&SystemConfig_x_123::create, &NetworkConfig_a_555::create}},
            MyTestParams{{&SystemConfig_x_123::create}}
            //,
            //MyTestParams{{&NetworkConfig_a_555::create}}, // should fail as we said in fixture that SystemConfig is mandatory
            //MyTestParams{{&SystemConfig_x_123::create, &NetworkConfig_a_555::create, &SystemConfig_x_123::create}} // fail, not unique
        ));