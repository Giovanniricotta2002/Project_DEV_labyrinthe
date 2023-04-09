#ifndef _DHCPCDSK_H
#define _DHCPCDSK_H
#if __GNUC__ >= 3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if (_WIN32_WINNT >= 0x0500)
#define DHCPCAPI_REGISTER_HANDLE_EVENT 0x00000001
#define DHCPCAPI_REQUEST_PERSISTENT  0x00000001
#define DHCPCAPI_REQUEST_SYNCHRONOUS 0x00000002
typedef struct _DHCPAPI_CLASSID {
	ULONG Flags;
	LPBYTE Data;
	ULONG nBytesData;
} DHCPCAPI_CLASSID,*PDHCPCAPI_CLASSID,*LPDHCPCAPI_CLASSID;
typedef struct _DHCPAPI_PARAMS {
	ULONG Flags;
	ULONG OptionId;
	BOOL IsVendor;
	LPBYTE Data;
	DWORD nBytesData;
} DHCPAPI_PARAMS,*PDHCPAPI_PARAMS,*LPDHCPAPI_PARAMS;
typedef struct _DHCPAPI_PARAMS_ARRAY {
	ULONG nParams;
	LPDHCPAPI_PARAMS Params;
} DHCPCAPI_PARAMS_ARRAY,*PDHCPCAPI_PARAMS_ARRAY,*LPDHCPCAPI_PARAMS_ARRAY;
VOID WINAPI DhcpCApiCleanup(void);
DWORD WINAPI DhcpCApiInitialize(LPDWORD);
DWORD WINAPI DhcpDeRegisterParamChange(DWORD,LPVOID,LPVOID);
DWORD WINAPI DhcpRegisterParamChange(DWORD,LPVOID,PWSTR,LPDHCPCAPI_CLASSID,DHCPCAPI_PARAMS_ARRAY,LPVOID);
DWORD WINAPI DhcpRemoveDNSRegistrations(void);
DWORD WINAPI DhcpUndoRequestParams(DWORD,LPVOID,LPWSTR,LPWSTR);
#endif /* (_WIN32_WINNT >= 0x0500) */

#ifdef __cplusplus
}
#endif
#endif
