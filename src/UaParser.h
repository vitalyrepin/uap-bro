/*
  
The MIT License (MIT)
Copyright (c) 2014 Alex Şuhan

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <string>

struct Generic {
  std::string family;
};

struct Device : Generic {
  std::string model;
  std::string brand;
};

struct Agent : Generic {
  std::string major;
  std::string minor;
  std::string patch;
  std::string patch_minor;

  std::string toString() const { return family + " " + toVersionString(); }

  std::string toVersionString() const {
    return (major.empty() ? "0" : major) + "." + (minor.empty() ? "0" : minor) + "." + (patch.empty() ? "0" : patch);
  }
};

struct UserAgent {
  Device device;

  Agent os;
  Agent browser;

  std::string toFullString() const { return browser.toString() + "/" + os.toString(); }

  bool isSpider() const { return device.family == "Spider"; }
};

class UserAgentParser {
 public:
  explicit UserAgentParser(const std::string& regexes_file_path);

  UserAgent parse(const std::string&) const;

  ~UserAgentParser();

 private:
  const std::string regexes_file_path_;
  const void* ua_store_;
};

