/*
 * Author: Philipp Aeschlimann - September 2009
 * Version 1.0
 * tcpserver.c - A simple TCP-Server
 *
 * tcpserver.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

//Fehler sauber ausgeben
void error(char *msg) {
    perror(msg);
	exit(0);
}

//void main routine
int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "ERROR, kein Port angegeben\n");
		exit(0);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR, konnte Socket nicht öffnen\n");
		exit(0);
	}
    bzero((char *) & serv_addr, sizeof (serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) & serv_addr,sizeof (serv_addr)) < 0){
        error("ERROR, konnte Socket nicht anbinden\n");
		exit(0);
	}
    listen(sockfd, 5);
    clilen = sizeof (cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) & cli_addr, &clilen);
    if (newsockfd < 0){
        error("ERROR, konnte Client nicht anbinden");
		exit(0);
	}
    printf("Erstellter Client-Socket hat Deskriptor Nr. %d.\n",newsockfd);

   char buffer2[8]="test   ";
   int i=0;
   i = recv(newsockfd,buffer,sizeof(buffer),0);
   int j=0;
   j = write(newsockfd,buffer2,5);
   printf("Nachricht\n%s \n",buffer);

    return 0;
}

