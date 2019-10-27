#include <iostream>

// g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"meta_arithsum.d" -MT"meta_arithsum.o" -o "meta_arithsum.o" "./meta_arithsum.cpp"

// Using template function versus template class to evaluate the arithmetic sum

#pragma GCC push_options
#pragma GCC optimize ("O0")


/*
long aith_sum<long>(long, long, long):
        push    rbp
        mov     rbp, rsp
        mov     QWORD PTR [rbp-8], rdi
        mov     QWORD PTR [rbp-16], rsi
        mov     QWORD PTR [rbp-24], rdx
        mov     rax, QWORD PTR [rbp-16]
        lea     rdx, [rax+rax]
        mov     rax, QWORD PTR [rbp-8]
        sub     rax, 1
        imul    rax, QWORD PTR [rbp-24]
        add     rax, rdx
        imul    rax, QWORD PTR [rbp-8]
        mov     rdx, rax
        shr     rdx, 63
        add     rax, rdx
        sar     rax
        pop     rbp
        ret
 */
template<typename Result>
inline Result aith_sum(long n, long a = 1, long d =1) noexcept
{
	return (n * (2 * a + (n - 1) * d)) / 2;
}
#pragma GCC pop_options

/*
        mov     esi, 55
        mov     edi, OFFSET FLAT:_ZSt4cout
        call    std::basic_ostream<char, std::char_traits<char> >::operator<<(int)
 */
template<long N, long A = 1, long D =1>
struct ArithSum
{
	enum
	{
		value = (N * (2 * A + (N - 1) * D)) / 2
	};
};

int test_arith_sum() {
	std::cout << ArithSum<10>::value << "\n";
	std::cout << aith_sum<long>(10) << "\n";
	return 0;
}

int main()
{
	test_arith_sum();
	std::cout << std::endl;
	return 0;
}

