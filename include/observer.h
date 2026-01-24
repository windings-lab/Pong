#pragma once

#include <functional>

template<typename... Args>
class Observer {
public:
    using Callback = std::function<void(Args...)>;

    // Subscribe a new callback
    void Subscribe(const Callback& callback) {
        m_callbacks.push_back(callback);
    }

    void Subscribe(Callback&& callback) {
        m_callbacks.push_back(std::move(callback));
    }

    // Emit event to all subscribers
    void Emit(Args... args) {
        for (auto& callback : m_callbacks) {
            callback(args...);
        }
    }

private:
    std::vector<Callback> m_callbacks;
};
