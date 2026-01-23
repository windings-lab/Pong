#pragma once

struct Class {
    explicit Class();
    explicit Class(Class* super);

    Class* super;
};

#define ROOT_STATIC_CLASS()             \
    static Class* StaticClass() \
    {                \
        static std::unique_ptr<Class> static_class = nullptr;   \
        if (!static_class) {                     \
            static_class = std::make_unique<Class>(); \
        }                                        \
        return static_class.get();                     \
    } \
    virtual Class* GetClass() = 0;

#define DERIVED_STATIC_CLASS(SuperClassName)  \
    static Class* StaticClass() {                         \
        static std::unique_ptr<Class> static_class;            \
        if (!static_class) {                              \
            static_class = std::make_unique<Class>(SuperClassName::StaticClass()); \
        }                                                 \
        return static_class.get();                              \
    } \
    Class* GetClass() override \
    { \
        return StaticClass(); \
    }