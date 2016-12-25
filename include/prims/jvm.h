/* Dummy file to allow for compilation of sources without coupling with RI */
#pragma once

/* Use definitions from Apache Harmony project */
#include "jni_types.h"

// There are a few new types in RI that DRLVM has no understanding of
typedef void JVM_ExceptionTableEntryType;
typedef void jvm_version_info;
