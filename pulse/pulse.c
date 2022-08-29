#include "pulse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*
██████╗░██╗░░░██╗██╗░░░░░░██████╗███████╗
██╔══██╗██║░░░██║██║░░░░░██╔════╝██╔════╝
██████╔╝██║░░░██║██║░░░░░╚█████╗░█████╗░░
██╔═══╝░██║░░░██║██║░░░░░░╚═══██╗██╔══╝░░
██║░░░░░╚██████╔╝███████╗██████╔╝███████╗
╚═╝░░░░░░╚═════╝░╚══════╝╚═════╝░╚══════╝

@author - Duloc Inc

tags [wip]

# [Overview]

A health monitoring dashboard for your
infrastructure.

*/

/* [CONFIG] */
int BANNER_LENGTH = 80;
int PADDING_LENGTH = 20;
int SERVICE_COUNT = 2;
int MAX_SERVICE_ID_LENGTH = 400;

void print_separator()
{
    for (int i = 0; i < BANNER_LENGTH; i++)
    {
        printf(":");
    }
    printf("\n");
}

void print_padding()
{
    for (int i = 0; i < PADDING_LENGTH; i++)
    {
        printf(" ");
    }
}

void print_dash_banner()
{
    print_separator();
    print_padding();
    printf("██████╗░██╗░░░██╗██╗░░░░░░██████╗███████╗\n");
    print_padding();
    printf("██╔══██╗██║░░░██║██║░░░░░██╔════╝██╔════╝\n");
    print_padding();
    printf("██████╔╝██║░░░██║██║░░░░░╚█████╗░█████╗░░\n");
    print_padding();
    printf("██╔═══╝░██║░░░██║██║░░░░░░╚═══██╗██╔══╝░░\n");
    print_padding();
    printf("██║░░░░░╚██████╔╝███████╗██████╔╝███████╗\n");
    print_padding();
    printf("╚═╝░░░░░░╚═════╝░╚══════╝╚═════╝░╚══════╝\n");
    print_separator();
}

void print_ascii_map()
{
    printf("               ,_   .  ._. _.  .\n");
    printf("          , _-\','|~\\~      ~/      ;-'_   _-'     ,;_;_,    ~~-           \n");
    printf("  /~~-\\_/-'~'--' \\~~| ',    ,'      /  / ~|-_\\_/~/~      ~~--~~~~'--_    \n");
    printf("  /              ,/'-/~ '\\ ,' _  , '|,'|~                   ._/-, /~       \n");
    printf("  ~/-'~\\_,       '-,| '|. '   ~  ,\\ /'~                /    /_  /~        \n");
    printf(".-~      '|        '',\\~|\\       _\\~     ,_  ,               /|          \n");
    printf(".-~      '|        '',\\~|\\       _\\~     ,_  ,               /|          \n");
    printf("          '\\        /'~          |_/~\\,-,~  \\           ,_,/ |           \n");
    printf("           |       /            ._-~'\\_ _~|              \\ ) /            \n");
    printf("            \\   __-\\           '/      ~ |\\  \\_          /  ~           \n");
    printf("  .,         '\\ |,  ~-_      - |          \\_' ~|  /\\  \\~ ,_             \n");
    printf("               ~-_'  _;       '\\           '-,   \\,' /\\/  |              \n");
    printf("                 '\\_,~'\\_       \\_ _,       /'    '  |, /|'              \n");
    printf("                   /     \\_       ~ |      /         \\  ~'; -,_.          \n");
    printf("                   |       ~\\        |    |  ,        '-_, ,; ~ ~\\        \n");
    printf("                    \\,      /        \\    / /|            ,-, ,   -,      \n");
    printf("                     |    ,/          |  |' |/          ,-   ~ \\   '.      \n");
    printf("                    ,|   ,/           \\ ,/              \\       |         \n");
    printf("                    /    |             ~                 -~~-, /   _        \n");
    printf("                    |  ,-'                                    ~    /        \n");
    printf("                    / ,'                                      ~             \n");
    printf("                    ',|  ~\n");
    printf("                      ~'\n");
    printf("\n");

    /* start status table display animation */
}

/*
Renders a table displaying the status of registered services. The table
has the following structure.

┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━┓
┃ Service ID   ┃ Service Name                      ┃         Status ┃
┡━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━┩
│ 1db7hy124yuz │ Frontier Reverse Proxy OCE        │  Online 🟢     │
└──────────────┴───────────────────────────────────┴────────────────┴
*/
void render_status_table()
{
    char *online_status = "Online 🟢";
    char *offline_status = "Offline 🔴";

    printf("┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━┓\n");
    printf("┃ Service ID   ┃ Service Name                     ┃         Status ┃\n");
    printf("┡━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╇━━━━━━━━━━━━━━━━┩\n");

    /**
     * @todo
     *   - iterate through services_health array and print out each
     *     service's stats
     *   - display online or offline status based on service's health
     *   - pad each service's stats to fit the table width
     *
     */
    for (int row = 0; row < SERVICE_COUNT; row++)
    {
        printf("│ 123456794321 │ Blockade servers (1-2)           │ %s      │\n", online_status);
    }
    for (int row = 0; row < SERVICE_COUNT; row++)
    {
        printf("│ 1hk7df668125 │ Ark Servers (1-2)                │ %s     │\n", offline_status);
    }

    /* print table footer */
    printf("└──────────────┴──────────────────────────────────┴────────────────┘\n");
}

void print_dashboard()
{
    print_dash_banner();
    print_ascii_map();
    printf("Loading status ... \n");
    /* @NOTE -> for debugging */
    printf("DEBUG: register service is up @%p\n\n", register_service);
    sleep(1);
    render_status_table();
}

void show_service_details(char *service_id)
{
    printf("\nService ID:     (%s) \n", service_id);
    printf("Service Name:   (%s) \n", service_id);
    printf("Service Status: (%s) \n", service_id);
}

/**
 * @brief Get the service id
 *
 */
int get_service_id()
{

    char service_id[50];
    setbuf(stdout, NULL);
    printf("<service ID> ::    ");
    fgets(service_id, MAX_SERVICE_ID_LENGTH, stdin);

    /* remove trailing newline */
    service_id[strcspn(service_id, "\n")] = 0;

    if (!strlen(service_id))
    {
        printf("\n[**] Error: service id is required\n");
        return 1;
    }

    /* show the service details */
    show_service_details(service_id);

    fflush(stdout);
    return 0;
}

void pulse()
{
    print_dashboard();
    sleep(1);

    printf("\n\n=== [Get Service Details] ===\n\n");

    /* prompt for service details */
    get_service_id();
}

/**
 * ========== [ ADMIN FUNCTIONS ] ==========
 * */

/*
 * @brief Admin route to register a new service
 * only called from an internal admin console
 * for safety reasons. This function is not exposed.
 */
void register_service()
{
    /* @NOTE - expose flag on remote */
    printf("\n[🏁] FLAG{DUMMY_FLAG!}\n\n");

    // dummy service registration
    printf("=== [Enter Service Details] ===\n");
    printf("Service ID :: ");

    char service_id[100];
    char service_name[300];
    // read service id from stdin with fgets()
    fgets(service_id, sizeof(service_id), stdin);
    printf("Service Name :: ");
    // read service name from stdin with fgets()
    fgets(service_name, sizeof(service_name), stdin);
    exit(0);
}