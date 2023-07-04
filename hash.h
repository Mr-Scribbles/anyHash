//
// Created by Danny Connolly on 4/07/2023.
//
//#include <-lcrypto>
#include <openssl/sha.h>
#include <openssl/md5.h>

// Directive to ignore the warningt hat MD5 is deprecated
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

// MD5
// Take strings called "input" and "output"
// and put the MD5 hash of input into output
void md5(char input[], unsigned char output[]) {
    unsigned char temp[MD5_DIGEST_LENGTH];
    MD5((unsigned char *) input, strlen(input), temp);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf((char * restrict)output + (i * 2), "%02x", temp[i]);
    }
}
// SHA1
// Take strings called "input" and "output"
// and put the SHA1 hash of input into output
void sha1(char input[], unsigned char output[]) {
    unsigned char temp[SHA_DIGEST_LENGTH];
    SHA1((unsigned char *) input, strlen(input), temp);
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        sprintf((char * restrict)output + (i * 2), "%02x", temp[i]);
    }
}
// SHA256
// Take strings called "input" and "output"
// and put the SHA256 hash of input into output
void sha256(char input[], unsigned char output[]) {
    unsigned char temp[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *) input, strlen(input), temp);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf((char * restrict)output + (i * 2), "%02x", temp[i]);
    }
}