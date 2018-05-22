/*
 * Copyright (c) 2018, The bitcoin2network developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of bitcoin2network.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "HttpRequest.h"

namespace CryptoNote {

  const std::string& HttpRequest::getMethod() const {
    return method;
  }

  const std::string& HttpRequest::getUrl() const {
    return url;
  }

  const HttpRequest::Headers& HttpRequest::getHeaders() const {
    return headers;
  }

  const std::string& HttpRequest::getBody() const {
    return body;
  }

  void HttpRequest::addHeader(const std::string& name, const std::string& value) {
    headers[name] = value;
  }
  void HttpRequest::setBody(const std::string& b) {
    body = b;
    if (!body.empty()) {
      headers["Content-Length"] = std::to_string(body.size());
    }
    else {
      headers.erase("Content-Length");
    }
  }

  void HttpRequest::setUrl(const std::string& u) {
    url = u;
  }

  std::ostream& HttpRequest::printHttpRequest(std::ostream& os) const {
    os << "POST " << url << " HTTP/1.1\r\n";
    auto host = headers.find("Host");
    if (host == headers.end()) {
      os << "Host: " << "127.0.0.1" << "\r\n";
    }

    for (auto pair : headers) {
      os << pair.first << ": " << pair.second << "\r\n";
    }
    
    os << "\r\n";
    if (!body.empty()) {
      os << body;
    }

    return os;
  }
}
