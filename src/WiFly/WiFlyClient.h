
// Based on interface defined in Ethernet's Client.h

#ifndef __WIFLY_CLIENT_H__
#define __WIFLY_CLIENT_H__

#include "Print.h"

#include <NetClient.h>
#include "ParsedStream.h"

#include "WiFlyDevice.h"

// TODO: Call this 'WiFlyClient' instead?
class WiFlyClient : public NetClient {
 public:
  WiFlyClient();

  virtual int connect(IPAddress ip, uint16_t port);
  virtual int connect(const char* domain, uint16_t port);

  virtual void write(byte value);
  virtual void write(const char *str);
  virtual void write(const uint8_t *buffer, size_t size);

  virtual int available();
  virtual int read();
  virtual int read(uint8_t *buf, size_t size);
  virtual int peek();
  virtual void flush(void);

  virtual uint8_t connected();
  virtual void stop();

  virtual operator bool();

 private:
  virtual int connect(uint16_t port);

  WiFlyDevice& _WiFly;

  uint16_t _port;

  bool isOpen;

  ParsedStream stream;

  // TODO: Work out why alternate instantiation code in
  //       Server.available() doesn't work and thus requires this:
  friend class WiFlyServer;
};

#endif
