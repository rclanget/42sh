/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:03:38 by rclanget          #+#    #+#             */
/*   Updated: 2016/11/14 15:19:17 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <stdlib.h>

const						t_error g_error_tab[] =
{
	{EPERM, "Operation not permitted"},
	{ENOENT, "No such file or directory"},
	{ESRCH, "No such process"},
	{EINTR, "Interrupted system call"},
	{EIO, "Input/output error"},
	{ENXIO, "Device not configured"},
	{E2BIG, "Argument list too long"},
	{ENOEXEC, "Exec format error"},
	{EBADF, "Bad file descriptor"},
	{ECHILD, "No child processes"},
	{EDEADLK, "Resource deadlock avoided"},
	{ENOMEM, "Cannot allocate memory"},
	{EACCES, "Permission denied"},
	{EFAULT, "Bad address"},
	{ENOTBLK, "Block device required"},
	{EBUSY, "Device / Resource busy"},
	{EEXIST, "File exists"},
	{EXDEV, "Cross-device link"},
	{ENODEV, "Operation not supported by device"},
	{ENOTDIR, "Not a directory"},
	{EISDIR, "Is a directory"},
	{EINVAL, "Invalid argument"},
	{ENFILE, "Too many open files in system"},
	{EMFILE, "Too many open files"},
	{ENOTTY, "Inappropriate ioctl for device"},
	{ETXTBSY, "Text file busy"},
	{EFBIG, "File too large"},
	{ENOSPC, "No space left on device"},
	{ESPIPE, "Illegal seek"},
	{EROFS, "Read-only file system"},
	{EMLINK, "Too many links"},
	{EPIPE, "Broken pipe"},
	{EDOM, "Numerical argument out of domain"},
	{ERANGE, "Result too large"},
	{EAGAIN, "Resource temporarily unavailable"},
	{EINPROGRESS, "Operation now in progress"},
	{EALREADY, "Operation already in progress"},
	{ENOTSOCK, "Socket operation on non-socket"},
	{EDESTADDRREQ, "Destination address required"},
	{EMSGSIZE, "Message too long"},
	{EPROTOTYPE, "Protocol wrong type for socket"},
	{ENOPROTOOPT, "Protocol not available"},
	{EPROTONOSUPPORT, "Protocol not supported"},
	{ESOCKTNOSUPPORT, "Socket type not supported"},
	{ENOTSUP, "Operation not supported"},
	{EPFNOSUPPORT, "Protocol family not supported"},
	{EAFNOSUPPORT, "Address family not supported by protocol family"},
	{EADDRINUSE, "Address already in use"},
	{EADDRNOTAVAIL, "Can't assign requested address"},
	{ENETDOWN, "Network is down"},
	{ENETUNREACH, "Network is unreachable"},
	{ENETRESET, "Network dropped connection on reset"},
	{ECONNABORTED, "Software caused connection abort"},
	{ECONNRESET, "Connection reset by peer"},
	{ENOBUFS, "No buffer space available"},
	{EISCONN, "Socket is already connected"},
	{ENOTCONN, "Socket is not connected"},
	{ESHUTDOWN, "Can't send after socket shutdown"},
	{ETOOMANYREFS, "Too many references: can't splice"},
	{ETIMEDOUT, "Operation timed out"},
	{ECONNREFUSED, "Connection refused"},
	{ELOOP, "Too many levels of symbolic links"},
	{ENAMETOOLONG, "File name too long"},
	{EHOSTDOWN, "Host is down"},
	{EHOSTUNREACH, "No route to host"},
	{ENOTEMPTY, "Directory not empty"},
	{EPROCLIM, "Too many processes"},
	{EUSERS, "Too many users"},
	{EDQUOT, "Disc quota exceeded"},
	{ESTALE, "Stale NFS file handle"},
	{EREMOTE, "Too many levels of remote in path"},
	{EBADRPC, "RPC struct is bad"},
	{ERPCMISMATCH, "RPC version wrong"},
	{EPROGUNAVAIL, "RPC prog. not avail"},
	{EPROGMISMATCH, "Program version wrong"},
	{EPROCUNAVAIL, "Bad procedure for program"},
	{ENOLCK, "No locks available"},
	{ENOSYS, "Function not implemented"},
	{EFTYPE, "Inappropriate file type or format"},
	{EAUTH, "Authentication error"},
	{ENEEDAUTH, "Need authenticator"},
	{EPWROFF, "Device power is off"},
	{EDEVERR, "Device error, e.g. paper out"},
	{EOVERFLOW, "Value too large to be stored in data type"},
	{EBADEXEC, "Bad executable"},
	{EBADARCH, "Bad CPU type in executable"},
	{ESHLIBVERS, "Shared library version mismatch"},
	{EBADMACHO, "Malformed Macho file"},
	{ECANCELED, "Operation canceled"},
	{EIDRM, "Identifier removed"},
	{ENOMSG, "No message of desired type"},
	{EILSEQ, "Illegal byte sequence"},
	{ENOATTR, "Attribute not found"},
	{EBADMSG, "Bad message"},
	{EMULTIHOP, "Reserved"},
	{ENODATA, "No message available on STREAM"},
	{ENOLINK, "Reserved"},
	{ENOSR, "No STREAM resources"},
	{ENOSTR, "Not a STREAM"},
	{EPROTO, "Protocol error"},
	{ETIME, "STREAM ioctl timeout"},
	{EOPNOTSUPP, "Operation not supported on socket"},
	{ENOPOLICY, "No such policy registered"}
};

char	*ft_strerror(int error_value)
{
	return ((error_value-- > 0 && error_value < ERROR_TAB_LEN) ?
		g_error_tab[error_value].msg : NULL);
}
