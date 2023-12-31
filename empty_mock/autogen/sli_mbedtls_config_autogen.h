// This is an autogenerated config file, any changes to this file will be overwritten

#ifndef SLI_MBEDTLS_CONFIG_AUTOGEN_H
#define SLI_MBEDTLS_CONFIG_AUTOGEN_H



#define MBEDTLS_PLATFORM_C
#define MBEDTLS_PLATFORM_MEMORY
#define MBEDTLS_PLATFORM_CALLOC_MACRO sl_calloc
#define MBEDTLS_PLATFORM_FREE_MACRO   sl_free
#define MBEDTLS_PSA_CRYPTO_C
#define MBEDTLS_USE_PSA_CRYPTO
#define MBEDTLS_CIPHER_C
#define MBEDTLS_PSA_CRYPTO_CONFIG
#define MBEDTLS_PSA_CRYPTO_DRIVERS
#define MBEDTLS_PSA_CRYPTO_STORAGE_C


#if defined(SL_TRUSTZONE_NONSECURE)

#endif // #if defined(SL_TRUSTZONE_NONSECURE)

#if defined(SL_TRUSTZONE_SECURE)

#endif // #if defined(SL_TRUSTZONE_SECURE)

#endif // SLI_MBEDTLS_CONFIG_AUTOGEN_H
