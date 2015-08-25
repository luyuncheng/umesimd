// The MIT License (MIT)
//
// Copyright (c) 2015 CERN
//
// Author: Przemyslaw Karpinski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//
//  This piece of code was developed as part of ICE-DIP project at CERN.
//  “ICE-DIP is a European Industrial Doctorate project funded by the European Community’s 
//  7th Framework programme Marie Curie Actions under grant PITN-GA-2012-316596”.
//

#ifndef UME_UNIT_TEST_MASKS_H_
#define UME_UNIT_TEST_MASKS_H_

int test_UME_SIMDMask8(bool supressMessages);

int test_UME_SIMDMask8(bool supressMessages) {
    char header[] = "UME::SIMD::SIMDMask8 test";
    INIT_TEST(header, supressMessages);

    {
        UME::SIMD::SIMDMask8 mask0(true);
        bool res = true;
        for(uint32_t i = 0; i < mask0.length(); i++) res &= mask0[i];
        CHECK_CONDITION(res == true, "SIMDMask8(bool m)");
    }
    {
        UME::SIMD::SIMDMask8 mask(true, false, false, true, true, true, true, false);
        CHECK_CONDITION(mask[1] == false && mask[6] == true && mask[7] == false, "SIMDMask8(bool m0, ... bool m7)");
    }
    {
        UME::SIMD::SIMDMask8 mask0(true);
        UME::SIMD::SIMDMask8 mask1(true, false, false, true, true, true, true, false);
        mask0.assign(mask1);
        CHECK_CONDITION(mask0[1] == false && mask0[6] == true && mask0[7] == false, "SIMDMask8::ASSIGN");
    }
    // AND
    {
        UME::SIMD::SIMDMask8 mask0(true, false, false, true, true, false, false, true);
        UME::SIMD::SIMDMask8 mask1(true, false, false, false, false, true, false, true);
        UME::SIMD::SIMDMask8 mask2;
        mask2 = mask0.andm(mask1);
        CHECK_CONDITION(mask2[0] == true && mask2[3] == false && mask2[5] == false && mask2[7] == true, "SIMDMask8::AND");
    }

    return g_failCount;
}


#endif
