/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _FILESYSTEM_H_RPCGEN
#define _FILESYSTEM_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif


typedef char *stream;

typedef char *filename;

struct read_request {
	filename name;
	int offset;
	int size;
};
typedef struct read_request read_request;

struct read_response {
	int size;
	stream buffer;
};
typedef struct read_response read_response;

struct write_request {
	filename name;
	int size;
	stream buffer;
};
typedef struct write_request write_request;

#define FS_PROG 555553555
#define FS_VERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define read 1
extern  enum clnt_stat read_1(read_request , read_response *, CLIENT *);
extern  bool_t read_1_svc(read_request , read_response *, struct svc_req *);
#define write 2
extern  enum clnt_stat write_1(write_request , int *, CLIENT *);
extern  bool_t write_1_svc(write_request , int *, struct svc_req *);
extern int fs_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define read 1
extern  enum clnt_stat read_1();
extern  bool_t read_1_svc();
#define write 2
extern  enum clnt_stat write_1();
extern  bool_t write_1_svc();
extern int fs_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_stream (XDR *, stream*);
extern  bool_t xdr_filename (XDR *, filename*);
extern  bool_t xdr_read_request (XDR *, read_request*);
extern  bool_t xdr_read_response (XDR *, read_response*);
extern  bool_t xdr_write_request (XDR *, write_request*);

#else /* K&R C */
extern bool_t xdr_stream ();
extern bool_t xdr_filename ();
extern bool_t xdr_read_request ();
extern bool_t xdr_read_response ();
extern bool_t xdr_write_request ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_FILESYSTEM_H_RPCGEN */
