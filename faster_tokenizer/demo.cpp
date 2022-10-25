//
// Created by 罗敏智 on 2022/10/25.
//
#include <iostream>
#include <vector>
#include <ctime>

#include "faster_tokenizer/tokenizers/ernie_faster_tokenizer.h"

using namespace paddlenlp;

void tokenize() {
    using faster_tokenizer::core::EncodeInput;

    //1. Define a Ernie faster tokenizer
    faster_tokenizer::tokenizers_impl::ErnieFasterTokenizer tokenizer("ernie_vocab.txt");

    std::cout << "case 1:  Tokenize a single string" << std::endl;

    faster_tokenizer::core::Encoding encoding;

    EncodeInput single_string =
            "商赢环球股份有限公司关于延期回复上海证券交易所对"
            "公司2017年年度报告的事后审核问询函的公告";

    tokenizer.EncodePairStrings(single_string, &encoding);
    std::cout << encoding.DebugString() << std::endl;

    // case 2: tokenize a pair of strings
    std::cout << "case 2: Tokenize a pair of strings" << std::endl;

    EncodeInput pair_string =
            std::pair<std::string, std::string>{
                    "蚂蚁借呗等额还款可以换成先息后本吗",
                    "借呗有先息到期还本吗",
            };

    tokenizer.EncodePairStrings(pair_string, &encoding);

    std::cout << encoding.DebugString() << std::endl;

    // case 3: encode batch strings
    std::vector<EncodeInput> pair_string_list = {
            "通过中介公司买了二手房，首付都付了，现在卖家不想卖了。怎么处理？",
            "凌云研发的国产两轮电动车怎么样，有什么惊喜？",
            "一辆车的寿命到底多长，最多可以开多久？"
    };

    std::vector<faster_tokenizer::core::Encoding> encodings;

    tokenizer.EncodeBatchStrings(pair_string_list, &encodings);

    for (auto &&encoding: encodings) {
        std::cout << encoding.DebugString() << std::endl;
    }

    // case 4: Tokenize a batch of pair strings
    std::cout << "case 4: Tokenize a batch of pair strings" << std::endl;
    std::vector<EncodeInput> pair_strings_list = {
            std::pair<std::string, std::string>({"花呗自动从余额宝扣款，需要我自己设置吗", "支付宝余额会自动还花呗吗"}),
            std::pair<std::string, std::string>({"这个蚂蚁花呗能恢复正常用不", "我的蚂蚁花呗 怎么用不了"}),
            std::pair<std::string, std::string>({"在经济的另一次转变中，人们发现在低地农场饲养羔羊更具成本效益，部分原因"
                                                 "是那里有更丰富、更有营养的牧场，因此湖地农场的利润变得更少。",
                                                 "人们发现，经济的另一个转变更有营养。"}),
    };
    tokenizer.EncodeBatchStrings(pair_strings_list, &encodings);
    for (auto &&encoding: encodings) {
        std::cout << encoding.DebugString() << std::endl;
    }
}

void TimeIt(const std::function<void(void)>& func) {
    clock_t start, end;

    start = clock();
    func();
    end = clock();

    std::cout << "time = " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;
    std::cout << "time = " << (end - start) / 1000 << std::endl;
}


void Tokenizer2() {
    using faster_tokenizer::core::EncodeInput;

    faster_tokenizer::tokenizers_impl::ErnieFasterTokenizer tokenizer("ernie_vocab.txt");

    EncodeInput single_string = "New York, NY, United States";

    faster_tokenizer::core::Encoding encoding;

    tokenizer.EncodePairStrings(single_string, &encoding);


    std::cout << encoding.DebugString() << std::endl;
}

int main() {

    using faster_tokenizer::core::EncodeInput;
//
    faster_tokenizer::tokenizers_impl::ErnieFasterTokenizer tokenizer("ernie_vocab.txt");

    EncodeInput single_string = "New York, NY, United States";

    faster_tokenizer::core::Encoding encoding;

    for(int i = 0; i < 10000; i++) {
        tokenizer.EncodePairStrings(single_string, &encoding);
    }

//    std::cout << "time = " << (double)(end - start) / 1000 << "ms" << std::endl;

    std::cout << encoding.DebugString() << std::endl;
    return 0;
}
