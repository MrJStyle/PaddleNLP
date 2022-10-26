/* Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#include "faster_tokenizer/tokenizers/ernie_faster_tokenizer.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace paddlenlp;
//
//int main() {
using faster_tokenizer::core::EncodeInput;
using namespace std::chrono;
//using faster_tokenizer::core::EncodeInput;


 faster_tokenizer::tokenizers_impl::ErnieFasterTokenizer tokenizer("ernie_vocab.txt");
//faster_tokenizer::tokenizers_impl::ErnieFasterTokenizer tokenizer("ap_vocab.txt");




void tokenizeTest(std::string& text) {

    std::cout << "case 1: Tokenize a single string" << std::endl;
    faster_tokenizer::core::Encoding encoding;


    // EncodeInput single_string = "울산남구삼산";
//    EncodeInput single_string = "เมืองสุรินทร์, สุรินทร์, Thailand";
    EncodeInput single_string = text;

    microseconds sum;
    double times = 1000;

    high_resolution_clock::time_point start = high_resolution_clock::now();
//    for (int i = 0; i < (int)times; i++) {

    tokenizer.EncodePairStrings(single_string, &encoding);

//    }
    high_resolution_clock::time_point end = high_resolution_clock::now();

    std::cout << "Time: " << (double)duration_cast<microseconds>(end - start).count() / times << "us" << std::endl;
    std::cout << encoding.DebugString() << std::endl;
}


void Timeit (std::function<void (void)> func) {
    high_resolution_clock::time_point start = high_resolution_clock::now();
    func();
    high_resolution_clock::time_point end = high_resolution_clock::now();

    std::cout << "Time: " << duration_cast<milliseconds>(end - start).count() << "ms" << std::endl;
}


int main() {
    // Timeit(tokenizeTest);
    std::vector<std::string> texts{
        "เมืองร้อยเอ็ด, ร้อยเอ็ด, Thailand",
//        "名古屋栄１丁目営業所（名古屋栄１丁目）, JPN, Japan",
//        "日野営業所（日野旭丘）, JPN, Japan",
//        "世羅営業所（世羅）, JPN, Japan",
//        "KOTO-KU, TOKYO, JP, Japan",
//        "福井鯖江営業所（鯖江水落）, JPN, Japan",
//        "小矢部営業所（小矢部）, JPN, Japan",
//        "เมืองสุรินทร์, สุรินทร์, Thailand",
//        "หนองไผ่, เพชรบูรณ์, Thailand",
//        "เมืองร้อยเอ็ด, ร้อยเอ็ด, Thailand",
//        "หันคา, ชัยนาท, Thailand",
//        "เมืองหนองบัวลำภู, หนองบัวลำภู, Thailand",
//        "동부산지점, Korea, Republic Of",
//        "제주구제주",
//        "제주신서부",
//        "남세종",
//        "부산연제거제2동",
//        "OPPIDO MAMERTINA, 89014, IT, Italy",
//        "Göödnight",
//        "江苏省苏州市吴江区吴江经济技术开发区柳胥路100号, China",
//        "广东省惠州市惠城区陈江镇吉祥街22号, China",
    };

    for (auto text: texts) {
        std::cout << text << std::endl;
        tokenizeTest(text);
        std::cout << "\n\n\n";
    }
//    std::string s("เมืองสุรินทร์, สุรินทร์, Thailand");
//    tokenizeTest(s);
    return 0;
}



