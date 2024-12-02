/**
* @file modAlphaCipher.h
* @author Беликов А.М.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @date 02.12.2024
*/
#pragma once
#include <string>
#include <stdexcept>
#include <vector>
/**
 * @brief Исключение для ошибок шифрования.
 */
class cipher_error : public std::runtime_error {
public:
    /**
     * @brief Конструктор исключения с сообщением.
     * @param what_arg Сообщение об ошибке.
     */
    explicit cipher_error(const std::string& what_arg) : std::runtime_error(what_arg) {}
};
/**
 * @brief Подготавливает текст для шифрования.
 * @param text Исходный текст.
 * @return Подготовленный текст.
 */
std::string prepareText(const std::string& text);
/**
 * @brief Шифрует текст.
 * @param key Ключ шифрования.
 * @param text Текст для шифрования.
 * @return Зашифрованный текст.
 */
std::string coder(int key, const std::string& text);
/**
 * @brief Дешифрует текст.
 * @param key Ключ дешифрования.
 * @param text Зашифрованный текст.
 * @return Расшифрованный текст.
 */
std::string decoder(int key, const std::string& text);
/**
 * @brief Проверяет корректность ключа.
 * @param key Ключ.
 * @param text Текст.
 * @return Корректный ключ.
 */
int getValidKey(int key, const std::string& text);
