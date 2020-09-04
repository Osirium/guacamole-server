#ifndef GUAC_LIBFREERDP_H
#define GUAC_LIBFREERDP_H

/*
 * This file is cobbled together from the various headers in libfreerdp/core/...
 *
 * Any field that we are not interested in has been set to a void pointer
 */

#include <openssl/ssl.h>

typedef enum
{
	TRANSPORT_LAYER_TCP,
	TRANSPORT_LAYER_TLS,
	TRANSPORT_LAYER_TSG,
	TRANSPORT_LAYER_TSG_TLS,
	TRANSPORT_LAYER_CLOSED
} TRANSPORT_LAYER;

typedef struct rdp_tls rdpTls;

struct rdp_tls
{
	SSL* ssl;
	void* bio;
	void* tsg;
	void* ctx;
	void* PublicKey;
	DWORD PublicKeyLength;
	void* settings;
	void* Bindings;
	void* certificate_store;
	void* underlying;
	void* hostname;
	int port;
	int alertLevel;
	int alertDescription;
	BOOL isGatewayTransport;
};

struct rdp_transport
{
	TRANSPORT_LAYER layer;
	void* frontBio;
	void* rdg;
	void* tsg;
	rdpTls* tls;
	void* context;
	void* nla;
	void* settings;
	void* ReceiveExtra;
	void* ReceiveBuffer;
	void* ReceiveCallback;
	void* ReceivePool;
	HANDLE connectedEvent;
	BOOL NlaMode;
	BOOL blocking;
	BOOL GatewayEnabled;
	CRITICAL_SECTION ReadLock;
	CRITICAL_SECTION WriteLock;
	ULONG written;
	HANDLE rereadEvent;
	BOOL haveMoreBytesToRead;
	void* log;
};

typedef struct rdp_transport rdpTransport;

struct rdp_rdp
{
	int state;
	void* instance;
	void* context;
	void* nla;
	void* mcs;
	void* nego;
	void* bulk;
	void* input;
	void* update;
	void* fastpath;
	void* license;
	void* redirection;
	void* settings;
	rdpTransport* transport;
	void* autodetect;
	void* heartbeat;
	void* multitransport;
	void* rc4_decrypt_key;
	int decrypt_use_count;
	int decrypt_checksum_use_count;
	void* rc4_encrypt_key;
	int encrypt_use_count;
	int encrypt_checksum_use_count;
	void* fips_encrypt;
	void* fips_decrypt;
	UINT32 sec_flags;
	BOOL do_crypt;
	BOOL do_crypt_license;
	BOOL do_secure_checksum;
	BYTE sign_key[16];
	BYTE decrypt_key[16];
	BYTE encrypt_key[16];
	BYTE decrypt_update_key[16];
	BYTE encrypt_update_key[16];
	int rc4_key_len;
	BYTE fips_sign_key[20];
	BYTE fips_encrypt_key[24];
	BYTE fips_decrypt_key[24];
	UINT32 errorInfo;
	UINT32 finalize_sc_pdus;
	BOOL resendFocus;
	BOOL deactivation_reactivation;
	BOOL AwaitCapabilities;
};

typedef struct rdp_rdp rdpRdp;

#endif
