--- components/os_crypt/async/browser/secret_portal_key_provider.cc.orig	2024-11-04 08:56:03 UTC
+++ components/os_crypt/async/browser/secret_portal_key_provider.cc
@@ -5,7 +5,9 @@
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
 
 #include <fcntl.h>
+#if BUILDFLAG(IS_LINUX)
 #include <linux/limits.h>
+#endif
 
 #include <array>
 #include <utility>
