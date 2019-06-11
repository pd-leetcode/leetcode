#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
private:
    Singleton() = default;
    static std::shared_ptr<Singleton> m_pInstance;
    static std::mutex g_mutex;
public:
    static std::shared_ptr<Singleton> GetInstance() {
        if (m_pInstance == nullptr) {
            std::lock_guard<std::mutex> lock(g_mutex);
            if (m_pInstance == nullptr) {
                m_pInstance = std::make_shared<Singleton>();
            }
        }
        return m_pInstance;
    }
};