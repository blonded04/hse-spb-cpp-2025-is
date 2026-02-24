#ifndef OPTIONAL_H_
#define OPTIONAL_H_

#include <utility>

namespace ex_optional {

template <typename T>
class optional {  // NOLINT(cppcoreguidelines-special-member-functions):
                  // operator=(optional) is not detected somewhy.
    alignas(alignof(T)) unsigned char storage[sizeof(T)];
    bool created = false;

public:
    optional() = default;

    // cppcheck-suppress noExplicitConstructor
    optional(const T &v) : created(true) {
        new (&storage) T(v);
    }

    // cppcheck-suppress noExplicitConstructor
    optional(T &&v) : created(true) {
        new (&storage) T(std::move(v));
    }

    [[nodiscard]] T &value() & {
        return reinterpret_cast<T &>(storage);
    }

    [[nodiscard]] T &&value() && {
        return reinterpret_cast<T &&>(storage);
    }

    [[nodiscard]] const T &value() const & {
        return reinterpret_cast<const T &>(storage);
    }

    [[nodiscard]] bool has_value() const {
        return created;
    }

    optional(const optional &other) : created(other.created) {
        if (created) {
            new (&storage) T(other.value());
        }
    }

    optional(optional &&other) : created(other.created) {
        if (created) {
            new (&storage) T(std::move(other).value());
        }
    }

    optional &operator=(optional other) {
        if (!other.created) {
            reset();
        } else {
            if (created) {
                value() = std::move(other).value();
            } else {
                new (&storage) T(std::move(other).value());
                created = true;  // Basic exception safety: flag is set after
                                 // construction.
            }
        }
        return *this;
    }

    ~optional() {
        reset();
    }

    void reset() {
        if (created) {
            value().~T();
            created = false;
        }
    }
};

}  // namespace ex_optional

#endif  // OPTIONAL_H_
