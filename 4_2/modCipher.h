/** @file modCipher.h
* * @author Беликов А.М.
* * @version 1.0
* * @date 02.12.2024
* * @brief Описание класса modCipher и связанных функций.
*/
#pragma once
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>

/**
 ** @class cipher_error
 ** @brief Исключение, используемое для обозначения ошибок шифрования.
 */
class cipher_error : public std::invalid_argument {
public:
    /**
     ** @brief Конструктор с сообщением об ошибке.
     ** @param what_arg Описание ошибки.
     */
    explicit cipher_error(const std::string& what_arg) : std::invalid_argument(what_arg) {}

    /**
     ** @brief Конструктор с сообщением об ошибке.
     ** @param what_arg Описание ошибки в виде C-строки.
     */
    explicit cipher_error(const char* what_arg) : std::invalid_argument(what_arg) {}
};

/**
 ** @class Code
 ** @brief Класс для шифрования и дешифрования текста.
 */
class Code {
private:
    int key; ///< Ключ для шифрования

    /**
     ** @brief Проверяет и возвращает корректный ключ.
     ** @param key Исходный ключ.
     ** @param text Текст для шифрования или дешифрования.
     ** @return Корректированный ключ.
     */
    int getValidKey(int key, const std::string& text);

    /**
     ** @brief Проверяет и возвращает корректный открытый текст.
     ** @param s Исходная строка.
     ** @return Корректированный открытый текст.
     */
    std::string getValidOpenText(const std::string& s);

    /**
     ** @brief Проверяет и возвращает корректный зашифрованный текст.
     ** @param s Исходная строка.
     ** @param open_text Открытый текст.
     ** @return Корректированный зашифрованный текст.
     */
    std::string getValidCipherText(const std::string& s, const std::string& open_text);

public:
    /**
     ** @brief Удалённый конструктор по умолчанию.
     */
    Code() = delete;

    /**
     ** @brief Конструктор с заданным ключом и текстом.
     ** @param skey Ключ шифрования.
     ** @param text Текст для шифрования.
     */
    Code(int skey, const std::string& text);

    /**
     ** @brief Шифрует текст.
     ** @param text Текст для шифрования.
     ** @return Зашифрованный текст.
     */
    std::string encryption(const std::string& text);

    /**
     ** @brief Дешифрует текст.
     ** @param text Зашифрованный текст.
     ** @param open_text Открытый текст.
     ** @return Дешифрованный текст.
     */
    std::string decrypt(const std::string& text, const std::string& open_text);
};
