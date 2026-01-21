#pragma once

#include <memory>
#include <type_traits>

template <typename T>
class ObjectPointer
{
public:
    ObjectPointer(std::nullptr_t) noexcept
        : ptr(nullptr)
    {

    }

    ObjectPointer(T* p) : ptr(p), alive(p ? p->GetAliveFlag() : std::weak_ptr<bool>{}) {}

    ObjectPointer(const ObjectPointer&) = default;
    ObjectPointer& operator=(const ObjectPointer&) = default;

    // Move constructor
    ObjectPointer(ObjectPointer&& other) noexcept
        : ptr(std::exchange(other.ptr, nullptr)), alive(std::move(other.alive))
    {
    }

    // Move assignment
    ObjectPointer& operator=(ObjectPointer&& other) noexcept
    {
        ObjectPointer temp(std::move(other));
        Swap(temp);
        return *this;
    }

    const T* Get() const
    {
        auto flag = alive.lock();
        if (!ptr || !flag || !*flag) return nullptr;
        return ptr;
    }

    T* Get()
    {
        auto flag = alive.lock();
        if (!ptr || !flag || !*flag) return nullptr;
        return ptr;
    }

    // Operators for convenience
    T* operator->() { return Get(); }
    const T* operator->() const { return Get(); }

    T* operator*() { return Get(); }
    const T* operator*() const { return Get(); }

    // Reset the handle
    void Reset() { ptr = nullptr; alive.reset(); }

    // Swap with another handle
    void Swap(ObjectPointer& other) noexcept
    {
        std::swap(ptr, other.ptr);
        std::swap(alive, other.alive);
    }

    explicit operator bool() const { return Get() != nullptr; }

    bool operator==(std::nullptr_t) const { return !Get(); }
    bool operator!=(std::nullptr_t) const { return Get(); }

    bool operator==(const ObjectPointer& other) const { return Get() == other.Get(); }
    bool operator!=(const ObjectPointer& other) const { return Get() != other.Get(); }

    bool operator!() const noexcept { return Get() == nullptr; }

    template <typename U>
    ObjectPointer<U> Cast() const
    {
        if (!*this) return ObjectPointer<U>(nullptr);

        U* casted = dynamic_cast<U*>(ptr);
        return ObjectPointer<U>(casted);
    }

private:
    T* ptr = nullptr;
    std::weak_ptr<bool> alive;
};
