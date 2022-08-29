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

/* [functions] */
void print_dash_banner(void);
void print_separator(void);
void print_ascii_map(void);
void print_dashboard(void);
void print_padding(void);
void pulse(void);
void show_service_details(char *service_id);
int get_service_id(void);

// admin functions
void register_service(void);

/* Information about a single service */
struct Service
{
    int service_id;
    int health;
};

typedef struct Service *Services;
