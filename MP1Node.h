/**********************************
 * FILE NAME: MP1Node.cpp
 *
 * DESCRIPTION: Membership protocol run by this Node.
 * 				Header file of MP1Node class.
 **********************************/

#ifndef _MP1NODE_H_
#define _MP1NODE_H_

#include "stdincludes.h"
#include "Log.h"
#include "Params.h"
#include "Member.h"
#include "EmulNet.h"
#include "Queue.h"

/**
 * Macros
 */
#define TREMOVE 20
#define TFAIL 5

/*
 * Note: You can change/add any functions in MP1Node.{h,cpp}
 */

/**
 * Message Types
 */
enum MsgTypes{
    JOINREQ,
    JOINREP,
	HEARTBEAT,
    DUMMYLASTMSGTYPE
};

/**
 * STRUCT NAME: MessageHdr
 *
 * DESCRIPTION: Header and content of a message
 */
typedef struct MessageHdr {
	enum MsgTypes msgType;
}MessageHdr;

/**
 * CLASS NAME: MP1Node
 *
 * DESCRIPTION: Class implementing Membership protocol functionalities for failure detection
 */
class MP1Node {
private:
	EmulNet *emulNet;
	Log *log;
	Params *par;
	Member *memberNode;
	char NULLADDR[6];

public:
	MP1Node(Member *, Params *, EmulNet *, Log *, Address *);
	Member * getMemberNode() {
		return memberNode;
	}
	int recvLoop();
	static int enqueueWrapper(void *env, char *buff, int size);
	void nodeStart(char *servaddrstr, short serverport);
	int initThisNode(Address *joinaddr);
	int introduceSelfToGroup(Address *joinAddress);
	int finishUpThisNode();
	void nodeLoop();
	void checkMessages();
	bool recvCallBack(void *env, char *data, int size);
	void nodeLoopOps();
 	void cleanupNodeState();
	int isNullAddress(Address *addr);
	Address getJoinAddress();
	Address getNodeAddress(int id, short port); 
	void initMemberListTable(Member *memberNode);
	bool isAddressEqualToNodeAddress(Address *address);
	bool existsNodeInMemberListTable(int id);
	MemberListEntry* getNodeInMemberListTable(int id);
	void addNodeToMemberListTable(int id, short port, long heartbeat, long timestamp);
	void removeNodeFromMemberListTable(int id, short port);
	void sendJOINREQMessage(Address *joinaddr);
	void sendJOINREPMessage(Address *destinationAddr);
	void sendHEARTBEATMessage(Address *destinationAddr);
	void serializeMemberListTableForJOINREPMessageSending(MessageHdr *msg);
	void deserializeMemberListTableForJOINREPMessageReceiving(char *data);
	void printAddress(Address *addr);
	virtual ~MP1Node();
};

#endif /* _MP1NODE_H_ */
