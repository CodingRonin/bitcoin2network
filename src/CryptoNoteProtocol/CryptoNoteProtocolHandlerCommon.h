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

#include <CryptoNoteProtocol/ICryptoNoteProtocolQuery.h>
#include <CryptoNote.h>

#include <vector>

namespace CryptoNote
{
  struct NOTIFY_NEW_BLOCK_request;

  /************************************************************************/
  /*                                                                      */
  /************************************************************************/
  struct ICryptoNoteProtocol {
    virtual void relayBlock(NOTIFY_NEW_BLOCK_request& arg) = 0;
    virtual void relayTransactions(const std::vector<BinaryArray>& transactions) = 0;
  };
  
  struct ICryptoNoteProtocolHandler : ICryptoNoteProtocol, public ICryptoNoteProtocolQuery {
  };
}
