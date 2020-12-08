#ifndef _AES_LIB_H
#define _AES_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
 * Advanced Encryption Standard
 * @author Dani Huertas
 * @email huertas.dani@gmail.com
 *
 * Based on the document FIPS PUB 197
 */

// command by clark:: 零长度数组存在的价值 :: 2020-12-08
/*
第一，节省内存。从上面的例子中可以看出，零长度数组不占用内存空间，而指针却占用内存空间。
第二，方便内存释放。如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。用户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体指针，用户做一次free就可以把所有的内存也给释放掉。
第三，这样有利于访问速度。连续的内存有益于提高访问速度，也有益于减少内存碎片。
*/

typedef struct _cypher_t{
	uint8_t len_data;
	uint8_t data[0];
}cypher_t;

extern void array_xor(int len, unsigned char*des, unsigned char*a1, unsigned char* a2);

extern int _aes128_encryption(unsigned char* key, unsigned char* ciphertext, unsigned char* plaintext);

extern int _aes128_decryption(unsigned char* key, unsigned char* plain_text, unsigned char* cypher);

#endif // _AES_LIB_H
