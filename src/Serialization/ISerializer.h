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

#include <string>
#include <cstdint>

#include <Common/StringView.h>

namespace CryptoNote {

class ISerializer {
public:

  enum SerializerType {
    INPUT,
    OUTPUT
  };

  virtual ~ISerializer() {}

  virtual SerializerType type() const = 0;

  virtual bool beginObject(Common::StringView name) = 0;
  virtual void endObject() = 0;
  virtual bool beginArray(size_t& size, Common::StringView name) = 0;
  virtual void endArray() = 0;

  virtual bool operator()(uint8_t& value, Common::StringView name) = 0;
  virtual bool operator()(int16_t& value, Common::StringView name) = 0;
  virtual bool operator()(uint16_t& value, Common::StringView name) = 0;
  virtual bool operator()(int32_t& value, Common::StringView name) = 0;
  virtual bool operator()(uint32_t& value, Common::StringView name) = 0;
  virtual bool operator()(int64_t& value, Common::StringView name) = 0;
  virtual bool operator()(uint64_t& value, Common::StringView name) = 0;
  virtual bool operator()(double& value, Common::StringView name) = 0;
  virtual bool operator()(bool& value, Common::StringView name) = 0;
  virtual bool operator()(std::string& value, Common::StringView name) = 0;
  
  // read/write binary block
  virtual bool binary(void* value, size_t size, Common::StringView name) = 0;
  virtual bool binary(std::string& value, Common::StringView name) = 0;

  template<typename T>
  bool operator()(T& value, Common::StringView name);
};

template<typename T>
bool ISerializer::operator()(T& value, Common::StringView name) {
  return serialize(value, name, *this);
}

template<typename T>
bool serialize(T& value, Common::StringView name, ISerializer& serializer) {
  if (!serializer.beginObject(name)) {
    return false;
  }

  serialize(value, serializer);
  serializer.endObject();
  return true;
}

template<typename T>
void serialize(T& value, ISerializer& serializer) {
  value.serialize(serializer);
}

#ifdef __clang__
template<> inline
bool ISerializer::operator()(size_t& value, Common::StringView name) {
  return operator()(*reinterpret_cast<uint64_t*>(&value), name);
}
#endif

#define KV_MEMBER(member) s(member, #member);

}
