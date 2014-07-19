#include "ofMain.h"

#include <Poco/Net/DatagramSocket.h>

#ifndef PING_PORT
#define PING_PORT 14000
#endif

class PingSender
{
	Poco::Net::DatagramSocket sock;
	int tick;
public:
	
	
	PingSender() { ofAddListener(ofEvents().update, this, &PingSender::onUpdate); }
	
	void onUpdate(ofEventArgs&)
	{
		int t = ofGetElapsedTimef();
		if (t != tick)
		{
			tick = t;
			char data[] = { 0x2F, 0x70, 0x69, 0x6E, 0x67, 0x00, 0x00, 0x00, 0x2C, 0x00, 0x00, 0x00 };
			sock.sendTo(data, sizeof(data), Poco::Net::SocketAddress("localhost", 14000));
		}
	}
};

static PingSender __PING_SENDER__;

#undef PING_PORT