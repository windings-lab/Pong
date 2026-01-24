#pragma once

class Level;

class Object
{
public:
    ROOT_STATIC_CLASS()

    Object();
    virtual ~Object();

    template<typename T, typename = std::enable_if_t<std::is_base_of_v<Object, T>>>
    T* Cast()
    {
        if (!IsA<T>())
            return nullptr;

        return static_cast<T*>(this);
    }

    template<typename T>
    bool IsA()
    {
        Class* from = GetClass();
        Class* to = T::StaticClass();

        for (; from != nullptr; from = from->super) {
            if (from == to) {
                return true;
            }
        }

        return false;
    }

    virtual void Initialize();
    virtual void Tick(float dt);

    void SetLevel(Level* level);
    const Level* GetLevel() const;

    void SubscribeToOnDestroy(std::function<void()>&& callback) const;

private:
    Level* m_level = nullptr;
    mutable std::unique_ptr<Observer<>> OnDestroyedEvent = nullptr;
};
