#ifndef LIBDOU_GLOBAL_H
#define LIBDOU_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBDOU_LIBRARY)
#  define LIBDOUSHARED_EXPORT Q_DECL_EXPORT
#else
#  define LIBDOUSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBDOU_GLOBAL_H
