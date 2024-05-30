#ifndef LY_SHA256_H
#define LY_SHA256_H

#include <cstdint>

#include <string>
#include <vector>

namespace Ly {

class Sha256 {
public:
    //! 获取单例
    inline static Sha256 &getInstance()
    {
        static Sha256 instance;
        return instance;
    }

    std::vector<uint8_t> encrypt(std::vector<uint8_t> message) const;

    std::string getHexMessageDigest(const std::string &message) const;

protected:
    /// SHA256算法中定义的6种逻辑运算 ///

    inline uint32_t ch(uint32_t x, uint32_t y, uint32_t z) const noexcept
    {
        return (x & y) ^ ((~x) & z);
    }

    inline uint32_t maj(uint32_t x, uint32_t y, uint32_t z) const noexcept
    {
        return (x & y) ^ (x & z) ^ (y & z);
    }

    inline uint32_t bigSigma0(uint32_t x) const noexcept
    {
        return (x >> 2 | x << 30) ^ (x >> 13 | x << 19) ^ (x >> 22 | x << 10);
    }

    inline uint32_t bigSigma1(uint32_t x) const noexcept
    {
        return (x >> 6 | x << 26) ^ (x >> 11 | x << 21) ^ (x >> 25 | x << 7);
    }

    inline uint32_t smallSigma0(uint32_t x) const noexcept
    {
        return (x >> 7 | x << 25) ^ (x >> 18 | x << 14) ^ (x >> 3);
    }

    inline uint32_t smallSigma1(uint32_t x) const noexcept
    {
        return (x >> 17 | x << 15) ^ (x >> 19 | x << 13) ^ (x >> 10);
    }


    void preprocessing(std::vector<uint8_t> &message) const;

    std::vector<std::vector<uint8_t>> breakTextInto64ByteChunks(const std::vector<uint8_t> &message) const;


    std::vector<uint32_t> structureWords(const std::vector<uint8_t> &chunk) const;


    void transform(const std::vector<uint32_t> &words, std::vector<uint32_t> &message_digest) const;


    std::vector<uint8_t> produceFinalHashValue(const std::vector<uint32_t> &input) const;

private:

    Sha256() = default;

    Sha256(const Sha256 &) = delete;
    Sha256 &operator=(const Sha256 &) = delete;

    Sha256(Sha256 &&) = delete;
    Sha256 &operator=(Sha256 &&) = delete;

    ~Sha256() = default;

    static const std::vector<uint32_t> initial_message_digest_;

    static const std::vector<uint32_t> add_constant_;
};

} // namespace Ly
#endif // LY_SHA256_H
