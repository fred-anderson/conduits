#ifndef CONDUITS_ARRAY_H
#define CONDUITS_ARRAY_H

#include <initializer_list>
#include <list>
#include <vector>
#include <set>
#include <cstddef>
#include <stdexcept>
#include <cstring>

namespace conduits {

namespace util {

/**
 * @brief Template for an array-like class
 */
template <typename T> class array {
public:

    virtual ~array();

    /**
     * @brief Default constructor
     */
    array();

    /**
     * @brief Construct with initial length
     * @param length Initial length for array
     */
    array(int length);

    /**
     * @brief Construct from allocated memory
     * @param original Allocated memory to copy from
     * @param length Length (in T objects) to copy
     */
    array(T* original, int length);

    /**
     * @brief Construct from initializer_list
     * @param list List from which to construct
     */
    array(std::initializer_list<T> list);

    /**
     * @brief Construct from container
     * @param container Container from which to construct
     */
    template <class U> array(const U& container);

    /**
     * @brief Assignment operator
     * @param rhs Similar array to assign from
     * @return Newly assigned array
     */
    array<T>& operator=(const array<T>& rhs) noexcept;

    /**
     * @brief Assignment operator from container
     * @param rhs Container to assign from
     * @return Newly assigned array
     */
    template <typename U> array<T>& operator=(const U& rhs) noexcept;

    /**
     * @brief Concatenation operator
     * @param rhs Similar array to concatenate
     * @return Newly concatenated array
     */
    array<T> operator+(const array<T>& rhs) noexcept;

    /**
     * @brief Concatenation operator for container
     * @param rhs Container to concatenate
     * @return Newly concatenated array
     */
    template <typename U> array<T> operator+(const U& rhs) noexcept;

    /**
     * @brief Concatenation assignment operator
     * @param rhs Similar array to concatenate to this one
     * @return This array with rhs concatenated
     */
    array<T>& operator+=(const array<T>& rhs) noexcept;

    /**
     * @brief Concatenation assignment operator for container
     * @param rhs Container to concatenate to this array
     * @return This array with rhs concatenated
     */
    template <typename U> array<T>& operator+=(const U& rhs) noexcept;

    /**
     * @brief Bracket operator for array-like access
     * @param offset Offset in T objects to return
     * @return Item at offset
     */
    T& operator[](size_t offset);

    T* data = nullptr;
    size_t length = 0;
};


template <typename T> array<T>::~array() {
    if (data) {
        delete [] data;
    }
}


template <typename T> array<T>::array() { }


template <typename T> array<T>::array(int length) : length(length) {
    if (length < 0) {
        throw std::invalid_argument("invalid length");
    } else if (length > 0) {
        data = new T[length];
        std::memset(data, 0, length * sizeof(T));
    }
}


template <typename T> array<T>::array(T* original, int length) : length(length) {
    if (length < 0) {
        throw std::invalid_argument("invalid length");
    } else if (length > 0) {
        data = new T[length];
        for (int x = 0; x < length; ++x) {
            data[x] = original[x];
        }
    }
}


template <typename T> array<T>::array(std::initializer_list<T> list) : length(list.size()) {
    data = new T[length];
    int x = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        data[x++] = *it;
    }
}


template <typename T> template <class U> array<T>::array(const U& container) : length(container.size()) {
    data = new T[length];
    int x = 0;
    for (auto it = container.begin(); it != container.end(); ++it) {
        data[x++] = *it;
    }
}


template <typename T> array<T>& array<T>::operator=(const array<T>& rhs) noexcept {
    if (this != &rhs) {
        if (data) {
            delete [] data;
            data = nullptr;
        }
        length = rhs.length;
        if (rhs.data) {
            data = new T[length];
            for (int x = 0; x < length; ++x) {
                data[x] = rhs.data[x];
            }
        }
    }
}


template <typename T> template <typename U> array<T>& array<T>::operator=(const U& rhs) noexcept {
    if (data) {
        delete [] data;
        data = nullptr;
    }
    length = rhs.size();
    if (length) {
        data = new T[length];
        int x = 0;
        for (auto it = rhs.begin(); it != rhs.end(); ++it) {
            data[x++] = *it;
        }
    }
}


template <typename T> array<T> array<T>::operator+(const array<T>& rhs) noexcept {
    array<T> newArray(length + rhs.length);
    std::copy(std::begin(data), std::end(data), newArray.data);
    std::copy(std::begin(rhs.data), std::end(rhs.data), newArray.data + length);

    return newArray;
}


template <typename T> template <typename U> array<T> array<T>::operator+(const U& rhs) noexcept {
    array<T> newArray(length + rhs.size());
    std::copy(std::begin(data), std::end(data), newArray.data);
    std::copy(rhs.begin(), rhs.end(), newArray.data + length);

    return newArray;
}


template <typename T> array<T>& array<T>::operator+=(const array<T>& rhs) noexcept {
    T* ptr = data;

    data = new T[length + rhs.length];
    std::copy(std::begin(ptr), std::end(ptr), data);
    std::copy(std::begin(rhs.data), std::end(rhs.data), data + length);
    length += rhs.length;
    delete [] ptr;
    return *this;
}


template <typename T> template <typename U> array<T>& array<T>::operator+=(const U& rhs) noexcept {
    T* ptr = data;

    data = new T[length + rhs.size()];
    std::copy(std::begin(ptr), std::end(ptr), data);
    std::copy(rhs.begin(), rhs.end(), data + length);
    length += rhs.size();
    delete [] ptr;
    return *this;
}


template <typename T> T& array<T>::operator[](size_t offset) {
    if (offset < 0 || offset >= length) {
        throw std::runtime_error("index out of bounds");
    }
    return data[offset];
}

} // namespace util

} // namespace conduit
#endif // CONDUITS_ARRAY_H
