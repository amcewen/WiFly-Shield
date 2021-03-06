#include "WiFly.h"

// NOTE: Arbitrary cast to avoid constructor ambiguity.
// TODO: Handle this a different way so we're not using
//       NULL pointers all over the place?
#define NO_CLIENT WiFlyClient ((uint8_t*) NULL, 0)

WiFlyServer::WiFlyServer(uint16_t port) {
  /*
   */
  _port = port;

  // TODO: Handle this better.
  // NOTE: This only works if the server object was created globally.
  WiFly.serverPort = port;
}

void WiFlyServer::begin() {
  /*
   */
  // TODO: Send command to enable server functionality.
}

#define TOKEN_MATCH_OPEN "*OPEN*"

WiFlyClient& WiFlyServer::available() {
  /*
   */

  // TODO: Ensure no active non-server client connection.

  if (!WiFly.serverConnectionActive) {
    activeClient._port = 0;
  }

  // TODO: Ensure begin() has been called.

  // Return active server connection if present
  if (!activeClient) {
    // TODO: Handle this better
    if (WiFly.uart.available() >= strlen(TOKEN_MATCH_OPEN)) {
      if (WiFly.responseMatched(TOKEN_MATCH_OPEN)) {
	// The following values indicate that the connection was
	// created when acting as a server.

	// TODO: Work out why this alternate instantiation code doesn't work:
	//activeClient = Client((uint8_t*) NULL, _port);

	activeClient.connect(_port);
	WiFly.serverConnectionActive = true;
      } else {
	// Ignore other feedback from the WiFly module.
	// TODO: Should we check we're not ditching a connect accidentally?
	//WiFly.skipRemainderOfResponse();
	WiFly.uart.flush();
      }
    }
  }

  return activeClient;
}

