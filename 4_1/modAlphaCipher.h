/**
* @file modAlphaCipher.h
* @author Беликов А.М.
* @version 1.0
* @brief Описание класса modAlphaCipher
* @date 02.12.2024
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

/**
 * @brief Класс для шифрования и дешифрования с использованием модифицированного шифра Альфа.
 */
class modAlphaCipher {
    private:
        wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        map <char,int> alphaNum;
        vector <int> key;
        /**
         * @brief Преобразует строку в вектор чисел.
         * @param s Исходная строка.
         * @return Вектор числовых значений.
         */
        vector<int> convert(const string& s);
         /**
         * @brief Преобразует вектор чисел в строку.
         * @param v Вектор числовых значений.
         * @return Строка.
         */
        string convert(const vector<int>& v);
        /**
         * @brief Проверяет и возвращает корректный ключ.
         * @param s Исходный ключ.
         * @return Корректный ключ.
         */
        string getValidKey(const string & s);
        /**
         * @brief Проверяет и возвращает корректный открытый текст.
         * @param s Исходный текст.
         * @return Корректный открытый текст.
         */
        string getValidOpenText(const string & s);
        /**
         * @brief Проверяет и возвращает корректный зашифрованный текст.
         * @param s Зашифрованный текст.
         * @return Корректный зашифрованный текст.
         */
        string getValidCipherText(const string & s);
    public:
        /**
         * @brief Конструктор по умолчанию удален.
         */
        modAlphaCipher()=delete;
        /**
         * @brief Конструктор с параметром ключа.
         * @param skey Ключ.
         */
        modAlphaCipher(const string& skey);
        /**
         * @brief Шифрует открытый текст.
         * @param open_text Текст для шифрования.
         * @return Зашифрованный текст.
         */
        string encrypt(const string& open_text);
         /**
         * @brief Дешифрует зашифрованный текст.
         * @param cipher_text Зашифрованный текст.
         * @return Расшифрованный текст.
         */
        string decrypt(const string& cipher_text);
};
/**
 * @brief Класс исключений для ошибок шифрования.
 */
class cipher_error : public std::invalid_argument {
public:
    /**
     * @brief Конструктор исключения с сообщением.
     * @param what_arg Сообщение исключения.
     */
    explicit cipher_error(const std::string& what_arg) : std::invalid_argument(what_arg) {}
    /**
     * @brief Конструктор исключения с сообщением.
     * @param what_arg Сообщение исключения (C-style строка).
     */
    explicit cipher_error(const char* what_arg) : std::invalid_argument(what_arg) {}
};
