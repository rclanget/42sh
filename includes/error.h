/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rclanget <rclanget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 14:38:49 by rclanget          #+#    #+#             */
/*   Updated: 2016/11/14 17:59:19 by ulefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef struct				s_error
{
	int						value;
	char					*msg;
}							t_error;

/*
** Operation not permitted
*/
# define EPERM 1

/*
** No such file or directory
*/
# define ENOENT 2

/*
** No such process
*/
# define ESRCH 3

/*
**  Interrupted system call
*/
# define EINTR 4

/*
**  No such policy registered
*/
# define EIO 5

/*
**  No such policy registered
*/
# define ENXIO 6

/*
**  No such policy registered
*/
# define E2BIG 7

/*
**  No such policy registered
*/
# define ENOEXEC 8

/*
**  No such policy registered
*/
# define EBADF 9

/*
**  No such policy registered
*/
# define ECHILD 10

/*
**  No such policy registered
*/
# define EDEADLK 11

/*
**  No such policy registered
*/
# define ENOMEM 12

/*
**  No such policy registered
*/
# define EACCES 13

/*
**  No such policy registered
*/
# define EFAULT 14

/*
**  No such policy registered
*/
# define ENOTBLK 15

/*
**  No such policy registered
*/
# define EBUSY 16

/*
**  No such policy registered
*/
# define EEXIST 17

/*
**  No such policy registered
*/
# define EXDEV 18

/*
**  No such policy registered
*/
# define ENODEV 19

/*
**  No such policy registered
*/
# define ENOTDIR 20

/*
**  No such policy registered
*/
# define EISDIR 21

/*
**  No such policy registered
*/
# define EINVAL 22

/*
**  No such policy registered
*/
# define ENFILE 23

/*
**  No such policy registered
*/
# define EMFILE 24

/*
**  No such policy registered
*/
# define ENOTTY 25

/*
**  No such policy registered
*/
# define ETXTBSY 26

/*
**  No such policy registered
*/
# define EFBIG 27

/*
**  No such policy registered
*/
# define ENOSPC 28

/*
**  No such policy registered
*/
# define ESPIPE 29

/*
**  No such policy registered
*/
# define EROFS 30

/*
**  No such policy registered
*/
# define EMLINK 31

/*
**  No such policy registered
*/
# define EPIPE 32

/*
**  No such policy registered
*/
# define EDOM 33

/*
**  No such policy registered
*/
# define ERANGE 34

/*
**  No such policy registered
*/
# define EAGAIN 35

/*
**  No such policy registered
*/
# define EINPROGRESS 36

/*
**  No such policy registered
*/
# define EALREADY 37

/*
**  No such policy registered
*/
# define ENOTSOCK 38

/*
**  No such policy registered
*/
# define EDESTADDRREQ 39

/*
**  No such policy registered
*/
# define EMSGSIZE 40

/*
**  No such policy registered
*/
# define EPROTOTYPE 41

/*
**  No such policy registered
*/
# define ENOPROTOOPT 42

/*
**  No such policy registered
*/
# define EPROTONOSUPPORT 43

/*
**  No such policy registered
*/
# define ESOCKTNOSUPPORT 44

/*
**  No such policy registered
*/
# define ENOTSUP 45

/*
**  No such policy registered
*/
# define EPFNOSUPPORT 46

/*
**  No such policy registered
*/
# define EAFNOSUPPORT 47

/*
**  No such policy registered
*/
# define EADDRINUSE 48

/*
**  No such policy registered
*/
# define EADDRNOTAVAIL 49

/*
**  No such policy registered
*/
# define ENETDOWN 50

/*
**  No such policy registered
*/
# define ENETUNREACH 51

/*
**  No such policy registered
*/
# define ENETRESET 52

/*
**  No such policy registered
*/
# define ECONNABORTED 53

/*
**  No such policy registered
*/
# define ECONNRESET 54

/*
**  No such policy registered
*/
# define ENOBUFS 55

/*
**  No such policy registered
*/
# define EISCONN 56

/*
**  No such policy registered
*/
# define ENOTCONN 57

/*
**  No such policy registered
*/
# define ESHUTDOWN 58

/*
**  No such policy registered
*/
# define ETOOMANYREFS 59

/*
**  No such policy registered
*/
# define ETIMEDOUT 60

/*
**  No such policy registered
*/
# define ECONNREFUSED 61

/*
**  No such policy registered
*/
# define ELOOP 62

/*
**  No such policy registered
*/
# define ENAMETOOLONG 63

/*
**  No such policy registered
*/
# define EHOSTDOWN 64

/*
**  No such policy registered
*/
# define EHOSTUNREACH 65

/*
**  No such policy registered
*/
# define ENOTEMPTY 66

/*
**  No such policy registered
*/
# define EPROCLIM 67

/*
**  No such policy registered
*/
# define EUSERS 68

/*
**  No such policy registered
*/
# define EDQUOT 69

/*
**  No such policy registered
*/
# define ESTALE 70

/*
**  No such policy registered
*/
# define EREMOTE 71

/*
**  No such policy registered
*/
# define EBADRPC 72

/*
**  No such policy registered
*/
# define ERPCMISMATCH 73

/*
**  No such policy registered
*/
# define EPROGUNAVAIL 74

/*
**  No such policy registered
*/
# define EPROGMISMATCH 75

/*
**  No such policy registered
*/
# define EPROCUNAVAIL 76

/*
**  No such policy registered
*/
# define ENOLCK 77

/*
**  No such policy registered
*/
# define ENOSYS 78

/*
**  No such policy registered
*/
# define EFTYPE 79

/*
**  No such policy registered
*/
# define EAUTH 80

/*
**  No such policy registered
*/
# define ENEEDAUTH 81

/*
**  No such policy registered
*/
# define EPWROFF 82

/*
**  No such policy registered
*/
# define EDEVERR 83

/*
**  No such policy registered
*/
# define EOVERFLOW 84

/*
**  No such policy registered
*/
# define EBADEXEC 85

/*
**  No such policy registered
*/
# define EBADARCH 86

/*
**  No such policy registered
*/
# define ESHLIBVERS 87

/*
**  No such policy registered
*/
# define EBADMACHO 88

/*
**  No such policy registered
*/
# define ECANCELED 89

/*
**  No such policy registered
*/
# define EIDRM 90

/*
**  No such policy registered
*/
# define ENOMSG 91

/*
**  No such policy registered
*/
# define EILSEQ 92

/*
**  No such policy registered
*/
# define ENOATTR 93

/*
**  No such policy registered
*/
# define EBADMSG 94

/*
**  No such policy registered
*/
# define EMULTIHOP 95

/*
**  No such policy registered
*/
# define ENODATA 96

/*
**  No such policy registered
*/
# define ENOLINK 97

/*
**  No such policy registered
*/
# define ENOSR 98

/*
**  No such policy registered
*/
# define ENOSTR 99

/*
**  No such policy registered
*/
# define EPROTO 100

/*
**  No such policy registered
*/
# define ETIME 101

/*
**  No such policy registered
*/
# define EOPNOTSUPP 102

/*
**  No such policy registered
*/
# define ENOPOLICY 103

# define ERROR_TAB_LEN 103

char						*ft_strerror(int yolo);

#endif
