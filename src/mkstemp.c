#ifdef _WIN32
#    include <sys/stat.h>
#    include <fcntl.h>
#    include <io.h>
#    include <windows.h>
#endif

int
_cbf_mkstemp(char *templ)
{
#ifdef _WIN32
    char path[MAX_PATH + 1];
    int errno_save, fd;
    unsigned i;

    errno_save = errno;
    strncpy(path, templ, MAX_PATH);
    path[MAX_PATH] = '\0';
    for (i = 0; i < 65536; i++) {
        strncpy(templ, path, MAX_PATH + 1);
        if (_mktemp(templ) == NULL) {
            if (errno == EEXIST)
                continue;
            return (-1);
        }
        fd = open(templ, _O_CREAT | _O_EXCL | _O_RDWR,  _S_IREAD | _S_IWRITE);
        if (fd >= 0) {
            errno = errno_save;
            return (fd);
        }
        if (errno != EEXIST)
            return (-1);
    }

    errno = EEXIST;
    return (-1);
#else
    errno = ENOSYS;
    return (-1);
#endif
}
