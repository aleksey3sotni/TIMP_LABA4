/**
 * @file modAlphaCipher.h
 * @author Беликов А.М.
 * @version 1.0
 * @brief Описание класса modAlphaCipher и связанных функций.
 * @date 02.12.2024
 */

#pragma once

#include <string>
#include <stdexcept>

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
 * 
 * Эта функция удаляет все неалфавитные символы и приводит текст к нижнему регистру,
 * чтобы обеспечить корректное шифрование.
 *
 * @param text Исходный текст.
 * @return Подготовленный текст.
 */
std::string prepareText(const std::string& text);

/**
 * @brief Шифрует текст.
 * 
 * Эта функция применяет шифр с использованием заданного ключа для преобразования текста.
 *
 * @param key Ключ шифрования.
 * @param text Текст для шифрования.
 * @return Зашифрованный текст.
 */
std::string coder(int key, const std::string& text);

/**
 * @brief Дешифрует текст.
 * 
 * Эта функция восстанавливает исходный текст из зашифрованного текста с использованием 
 * заданного ключа.
 *
 * @param key Ключ дешифрования.
 * @param text Зашифрованный текст.
 * @return Расшифрованный текст.
 */
std::string decoder(int key, const std::string& text);

/**
 * @brief Проверяет корректность ключа.
 *
 * Эта функция проверяет, является ли ключ допустимым для использования в шифровании,
 * и при необходимости корректирует его.
 *
 * @param key Ключ.
 * @param text Текст.
 * @return Корректный ключ.
 */
int getValidKey(int key, const std::string& text);
