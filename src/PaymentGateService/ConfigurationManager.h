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

#include "PaymentServiceConfiguration.h"
#include "P2p/NetNodeConfig.h"
#include "RpcNodeConfiguration.h"

namespace PaymentService {

class ConfigurationManager {
public:
  ConfigurationManager();
  bool init(int argc, char** argv);

  bool startInprocess;
  Configuration gateConfiguration;
  CryptoNote::NetNodeConfig netNodeConfig;
  RpcNodeConfiguration remoteNodeConfig;
  std::string dataDir;
};

} //namespace PaymentService
