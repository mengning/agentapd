#include "includes.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <net/if.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#include <linux/rtnetlink.h>
#include <netpacket/packet.h>
#include <linux/filter.h>
#include <linux/errqueue.h>
#include "nl80211_copy.h"

#include "common.h"
#include "eloop.h"
#include "utils/list.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "utils/l2_packet.h"
#include "netlink.h"
#include "linux_80211_wrapper.h"

static int process_event(struct nl_msg *msg, void *arg)
{
    wpa_printf(MSG_INFO, "nl80211: process_event "); 
    return 0;      
}

static void nl80211_event_receive(int sock, void *eloop_ctx,
					     void *handle)
{
	struct nl_cb *cb = eloop_ctx;
	wpa_printf(MSG_DEBUG, "nl80211: Event message available");

	nl_recv_wrapper(handle, cb);
}

static void nl80211_event_rtm_newlink(void *ctx,
                         struct ifinfomsg *ifi,
                         u8 *buf, size_t len)
{
    wpa_printf(MSG_INFO, "nl80211: nl80211_event_rtm_newlink "); 
    return;        
}
static void nl80211_event_rtm_dellink(void *ctx,
                         struct ifinfomsg *ifi,
                         u8 *buf, size_t len)
{
    wpa_printf(MSG_INFO, "nl80211: nl80211_event_rtm_dellink "); 
    return;        
}


int main() 
{
    int ret;
    struct nl_cb * nl_cb;
    struct nl_handle * nl_handle;
    struct netlink_data * netlink;
    int ioctl_sock = -1;
    struct dl_list interfaces;
	int if_add_ifindex = -1;
    dl_list_init(&interfaces);
/*
 * global_init
 */
    ret = netlink_init_nl80211_event_rtm(&netlink,NULL,nl80211_event_rtm_newlink,nl80211_event_rtm_dellink);
    if (ret == -1 || netlink == NULL) 
    {
        goto err;
    }
    
    ret = nl80211_init_event(&nl_cb, &nl_handle);
    if (ret == -1) 
    {
        wpa_printf(MSG_DEBUG, "nl80211: Init failure ");
        goto err;
    } 
    wpa_printf(MSG_INFO, "nl80211: wait for event... ");
    nl_cb_set(nl_cb, NL_CB_SEQ_CHECK, NL_CB_CUSTOM,
          no_seq_check, NULL);
    nl_cb_set(nl_cb, NL_CB_VALID, NL_CB_CUSTOM,
          process_event, NULL); 
    eloop_register_wrapper(nl_socket_get_fd(nl_handle),
				 nl80211_event_receive,
				 nl_cb, nl_handle);

    ioctl_sock = init_ioctl_sock();
    if (ioctl_sock < 0) 
	{
        perror("socket(PF_INET,SOCK_DGRAM)");
        goto err;
	}
/*
 * hapd_init
 */
    
	eloop_run();
    return 0;
err:
    netlink_deinit(netlink);
    nl_destroy_handles(&nl_handle);
    nl_cb_put(nl_cb);
    if (ioctl_sock >= 0)
    {
        close(ioctl_sock);
    }
    return -1;
}

