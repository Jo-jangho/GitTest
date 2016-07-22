#ifndef __PACKET_H__
#define __PACKET_H__

/**/
pthread_t tid;

int socket_desc;
struct sockaddr_in server;
static char read_buffer[2000];

/**/
typedef struct _S_PACKET_BASE
{
    unsigned short header;
    unsigned short req_type;
}_S_PACKET_BASE;

typedef struct _S_PACKET_REQ_SETPOS
{
    _S_PACKET_BASE m_base;
    unsigned short index;
    float m_fxpos;
    float m_fypos;
    unsigned char extra[2];
}_S_PACKET_REQ_SETPOS;

typedef struct _S_PACKET_REQ_GETPOS 
{
	_S_PACKET_BASE m_base;
	unsigned int m_nIndex;
} _S_PACKET_REQ_GETPOS;

typedef struct _S_PACKET_RCV_POS 
{
	unsigned short header;
    unsigned short req_type;
	float m_fxpos;
	float m_fypos;

} _S_PACKET_RCV_POS;

typedef struct _S_PACKET_RECV_POS
{
	unsigned short header;
	unsigned short type;
	float m_afXpos[2];
	float m_afYpos[2];
}_S_PACKET_RECV_POS;

#endif