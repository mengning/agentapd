####################################################################
# Copyright (C) SSE-USTC, 2010                                     #
#                                                                  #
#  FILE NAME             :  make.h                                 #
#  PRINCIPAL AUTHOR      :  Mengning                               #
#  LANGUAGE              :  Shell Script                           #
#  TARGET ENVIRONMENT    :  Unix-like System                       #
#  DATE OF FIRST RELEASE :  2010/10/18                             #
#  DESCRIPTION           :  Definitions for whole building system. #
####################################################################
.SILENT:

##############################################################
# Set the BASEDIR as the directory where you untar the files #
##############################################################
# TARGET_OS, can be OS_PTHREADS
TARGET_OS                    = OS_PTHREADS


ifeq (${TARGET_OS}, OS_PTHREADS)
BASE_DIR                     = ${PROJECT_BASE_DIR}
endif

##########################
# Directories.           #
##########################

# Common header files/include directories and dependencies
UTILS_DIR	= ${BASE_DIR}/utils
COMMON_DIR	= ${BASE_DIR}/common

COMMON_INCLUDE_DIRS 		= 	-I${BASE_DIR}		\
								-I$(UTILS_DIR)	    \
								-I$(COMMON_DIR)
											

# Common libs Definitions
UTILS_LIB = utils.a
COMMON_LIB = common.a

##########################
# Compilation FlagS.     #
##########################

ifeq (${TARGET_OS}, OS_PTHREADS)
CC_DEBUG_FLAGS               = -g
CC_OPTIMIZATION_FLAGS         = -O2
CC_WARNING_FLAGS             = #-ansi                         \
                               -Wall                         \
                               -Wunused                      \
                               -Wmissing-declarations        \
                               -Wimplicit                    \
                               -Wswitch                      \
                               -Wcast-qual                   \
                               -Wcast-align                  \
                               -Wshadow                      \
                               -Waggregate-return            \
                               -Wnested-externs              \
                               -Wmissing-prototypes          \
                               -fno-common                   \
                               -W
CC_PTHREAD_FLAGS			 = -lpthread
CC_FLAGS                     = -c ${CC_DEBUG_FLAGS}          \
                                  ${CC_OPTIMIZATION_FLAGS}   \
                                  ${CC_WARNING_FLAGS}
CC_OUTPUT_FLAGS				 = -o
CC                           = echo $(notdir $<); gcc
LD                           = ld
LD_FLAGS                     = -r
AR                           = ar
AR_FLAGS                     = -r
MKDIR                        = mkdir
MKDIR_FLAGS                  = -p
RM                           = rm
RM_FLAGS                     = -f
CP							 = cp
GENERAL_COMPILATION_SWITCHES = -DINCLUDE_IN_OSS              \
                               -DGNU_CC                      \
                               -DPACK_REQUIRED               \
                               -DOS=1
endif

# end of section for compilation flags

