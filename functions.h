//
// Created by mohammad on 5/21/19.
//
#include "frozen.h"
#include <string.h>

#ifndef UNTITLED_FUNCTIONS_H
#define UNTITLED_FUNCTIONS_H

#endif //UNTITLED_FUNCTIONS_H

split(const char *str1, char sep)
{
    //char str1[100];
    char newString[150][150];
    int i,j,ctr;
    //printf("\n\n Split string by space into words :\n");
    //printf("---------------------------------------\n");



    j=0; ctr=0;
    for(int i=0;i<=(strlen(str1));i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(str1[i]==' '||str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }

    }
    char time[100],session_id[100],log_level[100];


    for(i=0;i < ctr;i++)
    {   //char *time,*session_id,*log_level = malloc(10000 * sizeof(char));
        char *total = malloc(100000 * sizeof(char));
        char *total_str = malloc(2000 * sizeof(char));
        strcpy(total_str,"");
        strcpy(total,"");

        switch ( i ) {

            case 0:
                //printf("time: %s\n",newString[i]);
                strcpy(time,newString[i]);
                break;
            case 1:
                //printf("session_id: %s\n",newString[i]);
                strcpy(session_id,newString[i]);
                break;
            case 2:
                //printf("\nlog_level: %s\n",newString[i]);
                strcpy(log_level,newString[i]);
                break;

            case 3:

                if (strcmp(newString[i] ,"InnoDB:")==0)
                {

                    for(int j=i+1 ;j<ctr;j++) {
                        strcat(total_str, newString[j]);
                        strcat(total_str," ");
                        if(j = ctr-1)
                            strcat(total_str, "\"},");
                        else
                            strcat(total_str," ");
                    }
                    //strcat(total_str, "\"}");
                    strcpy(total,"{\"time\": \"");
                    strcat(total,time);
                    strcat(total,"\"");
                    strcat(total, ",\"session_id\": \"");
                    strcat(total,session_id);
                    strcat(total,"\"");
                    strcat(total, ",\"log_level\": \"");
                    strcat(total,log_level);
                    strcat(total,"\"");
                    strcat(total,",\"sender\": \"");
                    strcat(total, "InnoDB\"");
                    strcat(total, ",\"details\": \"");
                    strcat(total,total_str);

                }

                else if (strcmp(newString[i] ,"Aborted")==0)
                {

                    for(int j=i+10 ;j<ctr;j++) {
                        strcat(total_str, newString[j]);
                        strcat(total_str," ");
                        if(j = ctr-1)
                            strcat(total_str, "\"},");
                        else
                        strcat(total_str," ");
                    }
                    //strcat(total_str, "\"}");
                    strcpy(total,"{\"time\": \"");
                    strcat(total,time);
                    strcat(total,"\"");
                    strcat(total, ",\"session_id\": \"");
                    strcat(total,session_id);
                    strcat(total,"\"");
                    strcat(total, ",\"log_level\": \"");
                    strcat(total,log_level);
                    strcat(total,"\"");
                    strcat(total, ",\"message\": \"");
                    strcat(total,newString[i]);
                    strcat(total," ");
                    strcat(total,newString[i+1]);
                    strcat(total,"\"");
                    strcat(total, ",\"aborted_session_id\": \"");
                    strcat(total,newString[i+2]);
                    strcat(total,"\"");
                    strcat(total, ",\"database\": \"");
                    strcat(total,newString[i+5]);
                    strcat(total,"\"");
                    strcat(total, ",\"user\": \"");
                    strcat(total,newString[i+7]);
                    strcat(total,"\"");
                    strcat(total, ",\"host\": \"");
                    strcat(total,newString[i+9]);
                    strcat(total,"\"");
                    strcat(total, ",\"details\": \"");
                    strcat(total,total_str);


                }
                else if (strcmp(newString[i] ,"Access")==0)
                {

                    for(int j=i+5 ;j<ctr;j++) {
                        strcat(total_str, newString[j]);
                        strcat(total_str," ");
                        if(j = ctr-1)
                            strcat(total_str, "\"},");
                        else
                            strcat(total_str," ");
                    }
                    //strcat(total_str, "\"}");
                    strcpy(total,"{\"time\": \"");
                    strcat(total,time);
                    strcat(total,"\"");
                    strcat(total, ",\"session_id\": \"");
                    strcat(total,session_id);
                    strcat(total,"\"");
                    strcat(total, ",\"log_level\": \"");
                    strcat(total,log_level);
                    strcat(total,"\"");
                    strcat(total, ",\"message\": \"");
                    strcat(total,newString[i]);
                    strcat(total," ");
                    strcat(total,newString[i+1]);
                    strcat(total,"\"");
                    strcat(total, ",\"user\": \"");
                    strcat(total,newString[i+4]);
                    strcat(total,"\"");
                    strcat(total, ",\"details\": \"");
                    strcat(total,total_str);


                }
                else
                {

                    for(int j=i ;j<ctr;j++) {
                        strcat(total_str, newString[j]);
                        strcat(total_str," ");
                        if(j = ctr-1)
                            strcat(total_str, "\"},");
                        else
                            strcat(total_str," ");
                    }
                    strcpy(total,"{\"time\": \"");
                    strcat(total,time);
                    strcat(total,"\"");
                    strcat(total, ",\"session_id\": \"");
                    strcat(total,session_id);
                    strcat(total,"\"");
                    strcat(total, ",\"log_level\": \"");
                    strcat(total,log_level);
                    strcat(total,"\"");
                    strcat(total, ",\"details\": \"");
                    strcat(total,total_str);


                }

                break;
            default:
                /* Code */
                break;
        }
        FILE *out = fopen("settings.json", "a");
        fprintf(out, "%s", total);
        fclose(out);
        //printf("mamad");

        free(total);
        free(total_str);
        //free(time);
        //free(session_id);
        //free(log_level);
        //if(i == 0)

        //printf(" %s\n",newString[i]);
    }
    //return 0;
    //return newString;
}