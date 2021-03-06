/*
 *  Copyright (c) 2014, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include <thrift/lib/cpp/transport/TSSLSocket.h> // PasswordCollector

namespace proxygen {

class PasswordInFile: public apache::thrift::transport::PasswordCollector {
 public:
  explicit PasswordInFile(const std::string& file);
  ~PasswordInFile();

  void getPassword(std::string& password, int size) override {
    password = password_;
  }

  const char* getPasswordStr() const {
    return password_.c_str();
  }

  std::string describe() const override {
    return fileName_;
  }

 protected:
  std::string fileName_;
  std::string password_;
};

}
