/*
 * wpa_supplicant/hostapd / Debug prints
 * Copyright (c) 2002-2007, Jouni Malinen <j@w1.fi>
 *
 * This software may be distributed under the terms of the BSD license.
 * See README for more details.
 */

#include "includes.h"

#include "common.h"

#ifdef CONFIG_DEBUG_SYSLOG
#include <syslog.h>

static int wpa_debug_syslog = 0;
#endif /* CONFIG_DEBUG_SYSLOG */

#ifdef CONFIG_DEBUG_LINUX_TRACING
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

static FILE *wpa_debug_tracing_file = NULL;

#define WPAS_TRACE_PFX "wpas <%d>: "
#endif /* CONFIG_DEBUG_LINUX_TRACING */


int wpa_debug_level = MSG_EXCESSIVE;
int wpa_debug_show_keys = 0;
int wpa_debug_timestamp = 0;




/**
 * wpa_printf - conditional printf
 * @level: priority level (MSG_*) of the message
 * @fmt: printf format string, followed by optional arguments
 *
 * This function is used to print conditional debugging and error messages. The
 * output may be directed to stdout, stderr, and/or syslog based on
 * configuration.
 *
 * Note: New line '\n' is added to the end of the text when printing to stdout.
 */
void wpa_printf(int level, const char *fmt, ...)
{
	va_list ap;

	va_start(ap, fmt);
	if (level >= wpa_debug_level) {
		vprintf(fmt, ap);
		printf("\n");
	}
	va_end(ap);
}

