project( fc )
cmake_minimum_required( VERSION 3.8 )

include_directories(/usr/local/Cellar/boost/1.72.0/include)
include_directories(/usr/local/Cellar/openssl@1.1/1.1.1d/include)
include_directories(/Users/dongbo/Documents/rapidjson/include)
include_directories(vendor/websocketpp)

link_directories(/usr/local/Cellar/boost/1.72.0/lib)
link_directories(/usr/local/Cellar/openssl@1.1/1.1.1d/lib)
link_directories(/usr/local/Cellar/gmp/6.1.2_2/lib)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_C_COMPILER gcc-9)
#set(CMAKE_CXX_COMPILER g++-9)

include_directories(include)
include_directories(secp256k1/upstream/include)

add_subdirectory( secp256k1 )

SET(ECC_IMPL secp256k1 ) #openssl
SET( ECC_REST src/crypto/elliptic_impl_priv.cpp )
#SET( ECC_REST src/crypto/elliptic_impl_priv.cpp src/crypto/elliptic_impl_pub.cpp )


set( fc_sources
     src/uint128.cpp
     src/real128.cpp
     src/variant.cpp
     src/exception.cpp
     src/variant_object.cpp
     src/string.cpp
     src/time.cpp
     src/utf8.cpp
     src/io/datastream.cpp
     src/io/json.cpp
     src/io/varint.cpp
     src/io/fstream.cpp
     src/io/console.cpp
     src/filesystem.cpp
     src/interprocess/file_mapping.cpp
     src/interprocess/mmap_struct.cpp
     src/log/log_message.cpp
     src/log/logger.cpp
     src/log/appender.cpp
     src/log/console_appender.cpp
     src/log/gelf_appender.cpp
     src/log/logger_config.cpp
     src/crypto/_digest_common.cpp
     src/crypto/openssl.cpp
     src/crypto/aes.cpp
     src/crypto/crc.cpp
     src/crypto/city.cpp
#     src/crypto/base32.cpp
     src/crypto/base36.cpp
     src/crypto/base58.cpp
     src/crypto/base64.cpp
     src/crypto/bigint.cpp
     src/crypto/hex.cpp
     src/crypto/sha1.cpp
     src/crypto/ripemd160.cpp
     src/crypto/sha256.cpp
     src/crypto/sha224.cpp
     src/crypto/sha512.cpp
     src/crypto/dh.cpp
     src/crypto/blowfish.cpp
     src/crypto/elliptic_common.cpp
     ${ECC_REST}
     src/crypto/elliptic_${ECC_IMPL}.cpp
     src/crypto/elliptic_r1.cpp
     src/crypto/elliptic_webauthn.cpp
     src/crypto/rand.cpp
     src/crypto/public_key.cpp
     src/crypto/private_key.cpp
     src/crypto/signature.cpp
     src/network/ip.cpp
     src/network/platform_root_ca.cpp
     src/network/resolve.cpp
     src/network/udp_socket.cpp
     src/network/url.cpp
     src/network/http/http_client.cpp
     src/compress/smaz.cpp
     src/compress/zlib.cpp
     )


add_executable(fc main.cpp ${fc_sources})
target_link_libraries(fc c++ secp256k1 crypto ssl boost_date_time boost_filesystem boost_context-mt boost_chrono boost_iostreams boost_thread-mt gmp )