// 0KN Realtime Packet Monitor
// CWD SYSTEMS & 0KN

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <ncurses.h>

#define MAX_PACKET_SIZE 65535  
#define GRAPH_HEIGHT 10

WINDOW *graph_win;

void init_ncurses() {
    initscr();           
    clear();              
    noecho();            
    cbreak();             
    curs_set(0);         
    refresh();           
    graph_win = newwin(GRAPH_HEIGHT + 2, 60, 0, 0);  
    box(graph_win, 0, 0); 
    mvwprintw(graph_win, 0, 2, "Packet Sizes (Bytes)");
    wrefresh(graph_win);  
}

void draw_graph(int value) {
    int graph_width = 50;  
    int bar_width = (value * graph_width) / MAX_PACKET_SIZE;
    werase(graph_win);  
    box(graph_win, 0, 0); 
    mvwprintw(graph_win, 0, 2, "Packet Sizes (Bytes)");

    mvwprintw(graph_win, 1, 1, "[");
    for (int i = 0; i < bar_width; ++i) {
        wprintw(graph_win, "=");
    }
    wprintw(graph_win, "]");
    
    mvwprintw(graph_win, 2, 2, "Current Packet Size: %d bytes", value);

    wrefresh(graph_win);  
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {

    int packet_size = header->len;
    draw_graph(packet_size); 
}

int main() {
    char errbuf[PCAP_ERRBUF_SIZE]; 
    pcap_t *handle;                

    handle = pcap_open_live("any", MAX_PACKET_SIZE, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        return 1;
    }

    init_ncurses();

    printf("Capturing network packets... Press Ctrl+C to stop.\n");
    pcap_loop(handle, 0, packet_handler, NULL);

    pcap_close(handle);

    endwin();

    return 0;
}
