/*
 * Copyright (c) 2018, The bitcoin2network developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of bitcoin2network.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                  500000000
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX         2345936 // starts with "btc2f"
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            60
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              360

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60


#define MONEY_SUPPLY                                    21000000000
#define MIN_MIXIN                                       0
#define MANDATORY_MIXIN_BLOCK_VERSION                   0
#define KILL_HEIGHT                                     0
#define ZAWY_DIFFICULTY_BLOCK_INDEX                     0
#define ZAWY_DIFFICULTY_V2                              1
#define ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION        0


#define EMISSION_SPEED_FACTOR                           25
#define GENESIS_BLOCK_REWARD                            1057000000

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE       200000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    90000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    80000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_MONEY_DECIMAL_POINT                  8
#define CRYPTONOTE_MONEY_DECIMAL_UNITS                  (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT)
#define MINIMUM_FEE                                     (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT - 2)
#define DEFAULT_FEE                                     (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT - 1)
#define DEFAULT_DUST_THRESHOLD                          (uint64_t)pow(10, CRYPTONOTE_MONEY_DECIMAL_POINT / 4)

#define MAX_TRANSACTION_SIZE_LIMIT                      200000 
#define MEMPOOL_POLLING_INTERVAL                        60 // how often to clean mempool

#define DIFFICULTY_TARGET                               90
#define EXPECTED_NUMBER_OF_BLOCKS_PER_DAY               24 * 60 * 60 / DIFFICULTY_TARGET
#define DIFFICULTY_WINDOW                               17
#define DIFFICULTY_WINDOW_V1                            DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW_V2                            DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW_V4                            DIFFICULTY_WINDOW
#define DIFFICULTY_WINDOW_V5                            90
#define DIFFICULTY_CUT                                  0
#define DIFFICULTY_CUT_V1                               DIFFICULTY_CUT
#define DIFFICULTY_CUT_V2                               DIFFICULTY_CUT
#define DIFFICULTY_LAG                                  0
#define DIFFICULTY_LAG_V1                               DIFFICULTY_LAG
#define DIFFICULTY_LAG_V2                               DIFFICULTY_LAG

#define B2N                                             0x60000
#define MAX_BLOCK_SIZE_INITIAL                          256 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR           100 * 1024
#define MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR         365 * 24 * 60 * 60 / DIFFICULTY_TARGET

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS      DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                  60 * 60 * 24    // 1 day
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME   CRYPTONOTE_MEMPOOL_TX_LIVETIME * 2  // 2 days
#define CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL 2   // 2 days


#define FUSION_TX_MIN_INPUT_COUNT                       12
#define FUSION_TX_MIN_IN_OUT_COUNT_RATIO                4

#define KEY_IMAGE_CHECKING_BLOCK_INDEX                  0
#define UPGRADE_HEIGHT_V2                               1
#define UPGRADE_HEIGHT_V3                               2
#define UPGRADE_HEIGHT_V4                               10
#define UPGRADE_HEIGHT_V5                               20

#define UPGRADE_VOTING_THRESHOLD                        90
#define UPGRADE_VOTING_WINDOW                           EXPECTED_NUMBER_OF_BLOCKS_PER_DAY
#define UPGRADE_WINDOW                                  EXPECTED_NUMBER_OF_BLOCKS_PER_DAY

#define CRYPTONOTE_BLOCKS_FILENAME                      "blocks.bin"
#define CRYPTONOTE_BLOCKINDEXES_FILENAME                "blockindexes.bin"
#define CRYPTONOTE_POOLDATA_FILENAME                    "poolstate.bin"
#define P2P_NET_DATA_FILENAME                           "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                          "miner_conf.json"

} // parameters

#define CRYPTONOTE_NAME                                 "b2n"
#define CRYPTONOTE_GENESIS_TX                           "013c01ff0001c09482f803021c35e6e76586e05bccd0b48112ec0065a5f834c6c76131b17ab2d308df934a6a210130090e9cbf0f61dfd583db08ec93545e66533aed04817fd4148d2e5a1abf39b4"


#define TRANSACTION_VERSION_1                           1
#define TRANSACTION_VERSION_2                           2
#define CURRENT_TRANSACTION_VERSION                     TRANSACTION_VERSION_1
#define BLOCK_MAJOR_VERSION_1                           1
#define BLOCK_MAJOR_VERSION_2                           2
#define BLOCK_MAJOR_VERSION_3                           3
#define BLOCK_MAJOR_VERSION_4                           4
#define BLOCK_MAJOR_VERSION_5                           5

#define BLOCK_MINOR_VERSION_0                           0
#define BLOCK_MINOR_VERSION_1                           1

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000   //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              2000    //by default, blocks count in blocks downloading
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_DEFAULT_PORT                                19936
#define RPC_DEFAULT_PORT                                19935

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE            64 * 1024 * 1024   // 64 MB
#define P2P_DEFAULT_CONNECTIONS_COUNT                   10
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60  // seconds
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000    // 50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000    // 7 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             5000    // 3 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60 * 2 * 1000   // 2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000    // 7 seconds


const std::initializer_list<const char*> SEED_NODES {

    "node1.bitcoin2.network:19936",
    "node2.bitcoin2.network:19936",
    "node3.bitcoin2.network:19936",
    "node4.bitcoin2.network:19936",
    "node5.bitcoin2.network:19936",
    "node6.bitcoin2.network:19936",
    "node7.bitcoin2.network:19936",
    "node8.bitcoin2.network:19936",
    "node9.bitcoin2.network:19936",

};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

const std::initializer_list<CheckpointData> CHECKPOINTS {

    { 0,"18a173e1dee0a6cbc80b9d62d157eb978f418b12888e1cb63a80a4084dcba915" },
    { 100,"cf1d0edbe7135edd99c02e2cab27601953a7b90e7c34e35c6d66dc1c3791264b" },
    { 200,"0c9a720292a41f75d9e43b93618f6bb13708f6ba72bca4ad6b330460e72327df" },
    { 300,"3f3a96183a8a48840e1e6d829a26257d979cb4b7f98c576f36fb728aae5d1c6c" },
    { 400,"6cf74c92a76169ed7a4031162c17330ffacd080802bb60d419590902ea0da0e7" },
    { 848,"65ca7017b8548c90521cb334b53bc9f3932abe20c4aeea10a05bbad9f114e176" },
    { 1221,"7c3fe3eb0724565ddd8cb057ae5178f7a804a99a124cabf74e89107e7fec22c0" },
    { 2442,"303d64f1036712afc6bbe6bee9eca5d44d7df17e261242cce0e601cca71aa01b" },
    { 4444,"59fb92575ba33a2ec15003f3e418d5c1233b1bd854b37a0b6de22be0680128ce" },
    { 6446,"7013a8e839d2a5bc969c305ff7b0e2cb0d6b61a1a50ef10de9bcf680f22485c0" },
    { 10801,"69a089520f23056ad7bab4f30d51eb4e04d7c60a42c409a212cb07046683132a" },
    { 12821,"e8153e76cb61ed094d3ddb6dc9dd7cb2b0628b2764b2c48f1a717f7bdc2bd549" },
    { 15851,"bd1262f8b10ddf661acacd79ffdd072fed0cabcd4c42220b3236b7006160d6f9" },
    { 16861,"ea24eca43885136003b341d114fa55db0b9c35a76bb7df32febbc3c8d4893d76" },
    { 17871,"5c94263ee7b17750f88d09b341e2a359b84ba7ac193fe72ca31efcb168cb5482" },
    { 18881,"7666f8d4cfbbc58fecbd77101bf3c21c846329f2b60edb12ae8d1774e6f9cb44" },
    { 20802,"e859c98bb2c728e4329e9fae25754521088187012b1dce75d815ce3ddd1e67e6" },
    { 24842,"53e57d05edfc97ce7abd78cd3962847653ee449aec88527d85285dadcc89dad8" },
    { 26862,"81f0e11ac16597991aa4b366d335705832297f1d3d3a97cc7a9ee524ce671b11" },
    { 28882,"227b8209f2d41ff4d7a815dd8bd9132c6cd81421dbc099fb3bd800aef1812e5c" },
    { 30803,"1c6b62afaff3acecabb12bc7babac9708a5e5676c726a0bd0e030e9911e2753b" },
    { 33833,"c0a68bb337d84f528e81ca42244dfeb893fdf9c0ceae042951d975c62ad29e45" },
    { 35853,"732df381a5afff75535d6e35a7281e445d9bb61db231b5b49af32e32303334e6" },
    { 50805,"9744eceadf5f7f23b5ee3f19e9ccf74a252e6c0015bcd8a123cc07e849d3a98f" },
    {108801,"6637b108a8cbd47bcbf135db5a527a15e32013e4c11c517bd67708dfae3b5c1e" },
    {155551,"cd952093d7dbba38fa2298aa960396e312cd911313cf35c457c559f1dcdebe31" },
    {190091,"839f2bb5cba75c819d21531a9587bf9beed0295ec85d9aff8a863636ba11eaac" },
    {208802,"cfa840115e922cc8902d20f7e3a9871d3aa53f4614955194e3beaf20b94587b6" },

};

} // CryptoNote
