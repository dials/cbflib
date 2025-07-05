#ifdef _WIN32
#    include <windows.h>
#endif

char *
_cbf_realpath(const char *path, char *resolved_path)
{
#ifdef _WIN32
    if (path == NULL) {
        errno = EINVAL;
        return (NULL);
    }

    return (_fullpath(resolved_path, path, MAX_PATH));
#else
    errno = ENOSYS;
    return (NULL);
#endif
}
