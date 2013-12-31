
#include<stdio.h> 			/* perror */
#include<stdlib.h>			/* exit	*/
#include<sys/types.h>		/* WNOHANG */
#include<sys/wait.h>		/* waitpid */
#include<string.h>			/* memset */

#include"driver.h"
extern struct wpa_driver_ops *wpa_drivers[];
/*
 * 模仿hostapd调用driver
 * 注意call-down和driver call-up
 * call-down至少包括nl80211_global_init/nl80211_global_deinit,i802_init/i802_deinit
 * call-up至少包括wpa_supplicant_event,wpa_scan_results_free
 */
int main() 
{
    int i = 0;
	for (i = 0; wpa_drivers[i]; i++) 
	{
		if (wpa_drivers[i]->global_init) 
		{
			void * p = wpa_drivers[i]->global_init();
			if (p == NULL) {
				printf("Failed to initialize\n");
				return -1;
			}
		}
	}
	printf("NL80211 initialized\n");
    return 0;
}

void wpa_supplicant_event(void *ctx, enum wpa_event_type event,
			  union wpa_event_data *data)
{
    return;
}

void wpa_scan_results_free(struct wpa_scan_results *res)
{
    return;   
}