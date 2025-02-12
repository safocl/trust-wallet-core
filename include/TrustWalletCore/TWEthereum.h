// Copyright © 2017-2023 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "TWBase.h"
#include "TWData.h"
#include "TWString.h"

TW_EXTERN_C_BEGIN

TW_EXPORT_STRUCT
struct TWEthereum;

/// EIP-1014: Skinny CREATE2 (guess smart contract create2 address)
///
/// \param fromEthAddress valid eth address
/// \param salt always 32 bytes stack item
/// \param initCodeHash The init_code is the code that, when executed, produces the runtime bytecode that will be placed into the state, and which typically is used by high level languages to implement a ‘constructor’. Need to be provided hashed with keccak256
/// \return Ethereum resulting address
TW_EXPORT_STATIC_METHOD
TWString* _Nonnull TWEthereumEip1014AddressCreate2(TWString* _Nonnull fromEthAddress, TWData* _Nonnull salt, TWData* _Nonnull initCodeHash);

/// Generate a layer 2 eip2645 derivation path from eth address, layer, application and given index.
///
/// \param wallet non-null TWHDWallet
/// \param ethAddress non-null Ethereum address
/// \param layer  non-null layer 2 name (E.G starkex)
/// \param application non-null layer 2 application (E.G immutablex)
/// \param index non-null layer 2 index (E.G 1)
/// \return a valid eip2645 layer 2 derivation path as a string
TW_EXPORT_STATIC_METHOD
TWString* _Nonnull TWEthereumEip2645GetPath(TWString* _Nonnull ethAddress, TWString* _Nonnull layer,  TWString* _Nonnull application,  TWString* _Nonnull index);

TW_EXTERN_C_END
