#include "sha256.h"

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

namespace Ly {

    // SHA-256算法的初始消息摘要
    const std::vector<uint32_t> Sha256::initial_message_digest_{
        0x6a09e667, 0xbb67ae85, 0x3c6ef372,
        0xa54ff53a, 0x510e527f, 0x9b05688c,
        0x1f83d9ab, 0x5be0cd19
    };

    // SHA-256算法中使用的轮常量数组
    const std::vector<uint32_t> Sha256::add_constant_{
        0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
        0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
        0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
        0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
        0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
        0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
        0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
        0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
    };

    std::vector<uint8_t> Sha256::encrypt(std::vector<uint8_t> input_message) const{
        // 对输入消息进行预处理
        preprocessing(input_message);
        // 将输入消息分割为64字节的块
        auto chunks = breakTextInto64ByteChunks(input_message);
        // 初始化消息摘要
        std::vector<uint32_t> message_digest(initial_message_digest_);
        // 对每个块进行处理并更新消息摘要
        for (const auto &chunk : chunks)
        {
            transform(structureWords(chunk), message_digest);
        }
        // 生成最终的哈希值
        return produceFinalHashValue(message_digest);
    }

    std::string Sha256::getHexMessageDigest(const std::string &message) const{
        // 将消息转换为字节流，并加密获取哈希值
        auto digest = encrypt(std::vector<uint8_t>(message.begin(), message.end()));

        // 将哈希值转换为十六进制字符串
        std::ostringstream o_s;
        o_s << std::hex << std::setiosflags(std::ios::uppercase);
        for (auto c : digest) {
            o_s << std::setw(2) << std::setfill('0') << static_cast<unsigned short>(c);
        }

        return o_s.str();
    }


    void Sha256::preprocessing(std::vector<uint8_t> &message) const{
        // 计算消息的原始比特大小
        const auto original_bit_size = message.size() * 8;
        // 计算消息的长度对64取余数
        auto remainder = message.size() % 64;
        auto origialSize = message.size();
        // 根据不同的余数情况进行填充
        if (remainder < 56)
        {
            message.resize(message.size() + 56 - remainder, 0x00);
            message[origialSize] = 0x80;
        }
        else if (remainder == 56)
        {
            message.resize(message.size() + 64, 0x00);
            message[origialSize] = 0x80;
        }
        else
        {
            message.resize(message.size() + 120 - remainder, 0x00);
            message[origialSize] = 0x80;
        }

        // 将消息的原始比特大小作为64位大端序整数追加到消息末尾
        for (int i = 1; i <= 8; ++i)
        {
            message.emplace_back(static_cast<uint8_t>(original_bit_size >> (64 - 8 * i)));
        }
    }


    std::vector<std::vector<uint8_t>> Sha256::breakTextInto64ByteChunks(const std::vector<uint8_t> &message) const{
        // 检查消息大小是否为64字节的倍数
        if (0 != message.size() % 64)
        {
            // 若消息大小不合法，则抛出异常
            std::ostringstream oss;
            oss << "invalid message size: " << message.size();
            throw std::invalid_argument(oss.str());
        }

        // 将消息分割为64字节的块
        std::vector<std::vector<uint8_t>> chunks;
        auto quotient = message.size() / 64;
        for (size_t i = 0; i < quotient; ++i)
        {
            chunks.emplace_back(message.begin() + i * 64, message.begin() + (i + 1) * 64);
        }
        return chunks;
    }


    std::vector<uint32_t> Sha256::structureWords(const std::vector<uint8_t> &chunk) const{
        // 检查块大小是否为64字节
        if (64 != chunk.size())
        {
            // 若块大小不合法，则抛出异常
            std::ostringstream oss;
            oss << "invalid chunk size: " << chunk.size();
            throw std::invalid_argument(oss.str());
        }

        // 初始化用于存储64个字的数组
        std::vector<uint32_t> words(64);

        // 将前16个字从块中提取并转换为32位无符号整数
        for (size_t i = 0; i < 16; ++i)
        {
            words[i] = (static_cast<uint32_t>(chunk[i * 4]) << 24) | (static_cast<uint32_t>(chunk[i * 4 + 1]) << 16) |
                       (static_cast<uint32_t>(chunk[i * 4 + 2]) << 8) | static_cast<uint32_t>(chunk[i * 4 + 3]);
        }

        // 根据SHA-256算法中的公式计算剩余的48个字
        for (size_t i = 16; i < 64; ++i)
        {
            words[i] = smallSigma1(words[i - 2]) + words[i - 7] + smallSigma0(words[i - 15]) + words[i - 16];
        }

        return words;
    }


    void Sha256::transform(const std::vector<uint32_t> &words, std::vector<uint32_t> &message_digest) const{
        // 检查message_digest和words的大小是否合法
        if (8 != message_digest.size() || 64 != words.size())
        {
            // 若大小不合法，则抛出异常
            std::ostringstream oss;
            oss << "invalid message_digest size: " << message_digest.size() <<
                "Or invalid words size: " << words.size();
            throw std::invalid_argument(oss.str());
        }

        // 创建一个临时数组，以便在计算过程中保留原始的message_digest
        auto d = message_digest;

        // SHA-256算法中的64轮迭代过程
        for (int i = 0; i < 64; ++i)
        {
            uint32_t temp1 = d[7] + bigSigma1(d[4]) + ch(d[4], d[5], d[6]) + add_constant_[i] + words[i];
            uint32_t temp2 = bigSigma0(d[0]) + maj(d[0], d[1], d[2]);

            // 更新d数组中的元素
            d[7] = d[6];
            d[6] = d[5];
            d[5] = d[4];
            d[4] = d[3] + temp1;
            d[3] = d[2];
            d[2] = d[1];
            d[1] = d[0];
            d[0] = temp1 + temp2;
        }

        // 将更新后的d数组与原始的message_digest相加
        for (int i = 0; i < 8; ++i)
        {
            message_digest[i] += d[i];
        }
    }


    std::vector<uint8_t> Sha256::produceFinalHashValue(const std::vector<uint32_t> &input) const{
        // 创建一个空的输出向量
        std::vector<uint8_t> output;

        // 遍历输入向量中的每个元素
        for (auto it = input.begin(); it != input.end(); ++it)
        {
            // 将每个32位整数按字节顺序添加到输出向量中
            for (int i = 0; i < 4; i++)
            {
                output.emplace_back(static_cast<uint8_t>((*it) >> (24 - 8 * i)));
            }
        }

        // 返回输出向量
        return output;
    }


} // namespace Ly
