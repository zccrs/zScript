#ifndef GLOBAL_H
#define GLOBAL_H

#define ENABLE_DEBUG QByteArray(getenv("ENABLE_ZDEBUG")).toInt() > 0

#define zDebug \
    if(ENABLE_DEBUG)\
        qDebug().noquote() << __FILE__ << __LINE__ << __FUNCTION__ << "[Debug]:"
#define zError qCritical().noquote() << "[Error]:"
#define zInfo qInfo().noquote() << "[Info]:"
#define zWarning qWarning().noquote() << "[Warning]:"
#define zPrint qDebug().noquote()
#define zStandardPrint std::cout
#define zExit(code) quick_exit(code)
#define zErrorQuit zExit(-1)
#define zQuit zExit(0)

#if !defined(Z_NAMESPACE) /* user namespace */

# define Z_PREPEND_NAMESPACE(name) ::name
# define Z_USE_NAMESPACE
# define Z_BEGIN_NAMESPACE
# define Z_END_NAMESPACE
# define Z_BEGIN_INCLUDE_NAMESPACE
# define Z_END_INCLUDE_NAMESPACE
#ifndef Z_BEGIN_MOC_NAMESPACE
# define Z_BEGIN_MOC_NAMESPACE
#endif
#ifndef Z_END_MOC_NAMESPACE
# define Z_END_MOC_NAMESPACE
#endif
# define Z_FORWARD_DECLARE_CLASS(name) class name;
# define Z_FORWARD_DECLARE_STRUCT(name) struct name;
# define Z_MANGLE_NAMESPACE(name) name

#else /* user namespace */

# define Z_PREPEND_NAMESPACE(name) ::Z_NAMESPACE::name
# define Z_USE_NAMESPACE using namespace ::Z_NAMESPACE;
# define Z_BEGIN_NAMESPACE namespace Z_NAMESPACE {
# define Z_END_NAMESPACE }
# define Z_BEGIN_INCLUDE_NAMESPACE }
# define Z_END_INCLUDE_NAMESPACE namespace Z_NAMESPACE {
#ifndef Z_BEGIN_MOC_NAMESPACE
# define Z_BEGIN_MOC_NAMESPACE Z_USE_NAMESPACE
#endif
#ifndef Z_END_MOC_NAMESPACE
# define Z_END_MOC_NAMESPACE
#endif
# define Z_FORWARD_DECLARE_CLASS(name) \
    Z_BEGIN_NAMESPACE class name; Z_END_NAMESPACE \
    using Z_PREPEND_NAMESPACE(name);

# define Z_FORWARD_DECLARE_STRUCT(name) \
    Z_BEGIN_NAMESPACE struct name; Z_END_NAMESPACE \
    using Z_PREPEND_NAMESPACE(name);

# define Z_MANGLE_NAMESPACE0(x) x
# define Z_MANGLE_NAMESPACE1(a, b) a##_##b
# define Z_MANGLE_NAMESPACE2(a, b) Z_MANGLE_NAMESPACE1(a,b)
# define Z_MANGLE_NAMESPACE(name) Z_MANGLE_NAMESPACE2( \
        Z_MANGLE_NAMESPACE0(name), Z_MANGLE_NAMESPACE0(Z_NAMESPACE))

namespace Z_NAMESPACE {}

# ifndef Z_BOOTSTRAPPED
# ifndef Z_NO_USING_NAMESPACE
   /*
    This expands to a "using Z_NAMESPACE" also in _header files_.
    It is the only way the feature can be used without too much
    pain, but if people _really_ do not want it they can add
    DEFINES += Z_NO_USING_NAMESPACE to their .pro files.
    */
   Z_USE_NAMESPACE
# endif
# endif

#endif /* user namespace */

#endif // GLOBAL_H
