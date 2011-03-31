#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdint.h>
#include <NetServer.h>
 
class WiFlyServer : public NetServer {
 public:
  WiFlyServer (uint16_t port);
  WiFlyClient& available();
  
  virtual void begin();

 private:
  uint16_t _port;  
  WiFlyClient activeClient;
};

#endif
