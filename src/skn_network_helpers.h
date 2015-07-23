/**
 * skn_network_helpers.h
 *
 *
 */


#ifndef SKN_NETWORK_HELPERS_H__
#define SKN_NETWORK_HELPERS_H__

#include "skn_common_headers.h"

//extern PDisplayLine skn_display_manager_add_line(PDisplayManager pdmx, char * client_request_message);


/*
 * Globals defined in skn_network_helpers.c
*/
extern sig_atomic_t gi_exit_flag;
extern char *gd_pch_message;
extern signed int gd_i_debug;
extern int gd_i_socket;
extern char gd_ch_program_name[SZ_LINE_BUFF];
extern char gd_ch_program_desc[SZ_LINE_BUFF];
extern char *gd_pch_effective_userid;
extern char gd_ch_ipAddress[NI_MAXHOST];
extern char gd_ch_intfName[SZ_CHAR_BUFF];


/*
 * General Utilities
*/
extern uid_t skn_get_userids();
extern void skn_program_name_and_description_set(const char *name, const char *desc);
extern char * skn_strip(char * alpha);
extern int skn_logger(const char *level, const char *format, ...);
extern int skn_handle_locator_command_line(int argc, char **argv);
extern void signals_init();
extern void signals_cleanup(int sig);

/*
 * Server/Client Communication Routines
*/
extern int host_socket_init(int port, int rcvTimeout);
extern int skn_display_manager_message_consumer_startup(PDisplayManager pdm);
extern void skn_display_manager_message_consumer_shutdown(PDisplayManager pdm);

extern int get_default_interface_name(char *pchDefaultInterfaceName);
extern int get_broadcast_ip_array(PIPBroadcastArray paB);
extern void log_response_message(const char * response);
extern void get_default_interface_name_and_ipv4_address(char * intf, char * ipv4);

/*
 * Service Registry Public Routines
 */
extern int service_registry_valiadate_response_format(const char *response);
extern int service_registry_provider(int i_socket, char *response);
extern PServiceRegistry service_registry_get_via_udp_broadcast(int i_socket, char *request);
extern int service_registry_entry_count(PServiceRegistry psr);
extern int service_registry_list_entries(PServiceRegistry psr);
extern PRegistryEntry service_registry_find_entry(PServiceRegistry psreg, char *serviceName);
extern void * service_registry_get_entry_ref(PRegistryEntry prent, char *field);
extern void service_registry_destroy(PServiceRegistry psreg);

#endif // SKN_NETWORK_HELPERS_H__
