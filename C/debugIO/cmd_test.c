#include <string.h>
#include <stdio.h>


#define test_debug 1

static char cmd_main[][128] = 
{
    "/*********CA TEST MENU**********/",
    "0:CA ERROR CODE TEST",
    "1:OSD DISBPALY TEST",
    "2:FINGER DISPLAY TEST",
    "3:SC UPGRADE TEST",
    "4:EMAIL NOTIFY TEST",
    "5:STB ACTION NOTIFY TEST",
    "6:CURTAIN DISPLAY TEST",
    "7:CA SERVICE LOCK TEST",
	"/*********CA TEST MENU**********/",
};

static char cmd_errorcode[][128] = 
{
    "/*********CA ERROR CODE TEST MENU**********/",
    "0:CA_BUYMESSGE_DISPLAY(auto, fre=0, tsid=0, serid=0, errorcode increase one each 5 sec)",
    "1:CA_BUYMESSGE_DISPLAY/HIDE(manul)",
    "2:CA_BUYMESSGE_HIDE(fre=0, tsid=0, serid=0)",
    "3:exit to up menu",
    "/*********CA ERROR CODE TEST MENU**********/",
};

static char cmd_errorcode_manul[][128] = 
{
    "/*********ERROR MANUL TEST MENU**********/",
    "display:<the whole json message>",
    "hide:<the whole json message>",
    "exit",
    "/*********ERROR MANUL TEST MENU**********/",
};

static char cmd_osd_menu[][128] = 
{
    "/*********CA OSD TEST MENU**********/",
    "display:<the whole json message>",
    "hide:<the whole json message>",
    "exit",
    "/*********CA OSD TEST MENU**********/",
};

static char cmd_finger_menu[][128] = 
{
    "/*********CA FINGER TEST MENU**********/",
    "display:<the whole json message>",
    "hide:<the whole json message>",
    "exit",
    "/*********CA FINGER TEST MENU**********/",
};

static char cmd_scupgrade_menu[][128] = 
{
    "/*********CA SC UPGRADE TEST MENU**********/",
    "0:receiving patch test",
    "1:patching",
    "2:exit",
    "/*********CA SC UPGRADE TEST MENU**********/",
};

static char cmd_email_menu[][128] = 
{
    "/*********CA EMAIL TEST MENU**********/",
    "0:new email notify",
    "1:email box fall",
    "2:hide email icon",
    "3:exit",
    "/*********CA EMAIL TEST MENU**********/",
};

static char cmd_action_menu[][128] = 
{
    "/*********CA ACTION TEST MENU**********/",
    "0:restart stb",
    "1:freeze stb",
    "2:search channel",
    "3:stb upgrade",
    "4:cancel freeze stb",
    "5:initialize stb",
    "6:display system information",
    "7:exit",
    "/*********CA ACTION TEST MENU**********/",
};

static char cmd_curtain_menu[][128] = 
{
    "/*********CA CURTAIN TEST MENU**********/",
    "0:start curtain with",
    "1:start curtain with errorcode",
    "2:stop curtain(erase pic & errorcode)",
    "3:exit",
    "/*********CA CURTAIN TEST MENU**********/",
};

static char cmd_servicelock_menu[][128] = 
{
    "/*********CA CURTAIN TEST MENU**********/",
    "lock:<the whole json message>",
    "unlock:<the whole json message>",
    "exit",
    "/*********CA CURTAIN TEST MENU**********/",
};

void printf_cmd_main(void)
{	
	int i = 0;
    while(i < sizeof(cmd_main)/sizeof(cmd_main[0]))
    {
		printf("%s\n", cmd_main[i++]);
    }
}

void printf_cmd_errorcode(void)
{	
	int i = 0;
    while(i < sizeof(cmd_errorcode)/sizeof(cmd_errorcode[0]))
    {
		printf("%s\n", cmd_errorcode[i++]);
    }
}
void printf_cmd_osd(void)
{	
	int i = 0;
    while(i < sizeof(cmd_finger_menu)/sizeof(cmd_finger_menu[0]))
    {
		printf("%s\n", cmd_finger_menu[i++]);
    }
}
void printf_cmd_finger(void)
{	
	int i = 0;
    while(i < sizeof(cmd_finger_menu)/sizeof(cmd_finger_menu[0]))
    {
		printf("%s\n", cmd_finger_menu[i++]);
    }
}

void printf_cmd_errorcode_manul(void)
{	
	int i = 0;
    while(i < sizeof(cmd_errorcode_manul)/sizeof(cmd_errorcode_manul[0]))
    {
		printf("%s\n", cmd_errorcode_manul[i++]);
    }
}

void printf_cmd_scupgrade(void)
{	
	int i = 0;
    while(i < sizeof(cmd_scupgrade_menu)/sizeof(cmd_scupgrade_menu[0]))
    {
		printf("%s\n", cmd_scupgrade_menu[i++]);
    }
}

void printf_cmd_email(void)
{	
	int i = 0;
    while(i < sizeof(cmd_email_menu)/sizeof(cmd_email_menu[0]))
    {
		printf("%s\n", cmd_email_menu[i++]);
    }
}

void printf_cmd_action(void)
{	
	int i = 0;
    while(i < sizeof(cmd_action_menu)/sizeof(cmd_action_menu[0]))
    {
		printf("%s\n", cmd_action_menu[i++]);
    }
}

void printf_cmd_curtain(void)
{	
	int i = 0;
    while(i < sizeof(cmd_curtain_menu)/sizeof(cmd_curtain_menu[0]))
    {
		printf("%s\n", cmd_curtain_menu[i++]);
    }
}

void printf_cmd_servicelock(void)
{	
	int i = 0;
    while(i < sizeof(cmd_servicelock_menu)/sizeof(cmd_servicelock_menu[0]))
    {
		printf("%s\n", cmd_servicelock_menu[i++]);
    }
}

void display_errorcode_auto(void)
{
    int i = 0;
    while(++i < 0x26+1)
    {
    #if(test_debug)
        printf("errorcode=%d\n", i);        
        usleep(50);
    #else
        STB_ShowBuyMessage(0, i);
        sleep(5);
    #endif
    }
}

void hide_errorcode_auto(void)
{
#if(test_debug)
    printf("errorcode=%d\n", 0);        
#else
    STB_ShowBuyMessage(0, 0);
#endif
}

void sc_upgrade_receiving(void)
{
    int i = 0;

    while(i<102)
    {
        usleep(500);
#if(test_debug)
        printf("receive process precent=%d\n", i++);        
#else
        STB_ShowProgressStrip(STBSCALE_RECEIVEPATCH, i++);
#endif
    }
}

void sc_upgrade_patching(void)
{
    int i = 0;

    while(i<102)
    {
        usleep(500);
#if(test_debug)
        printf("patch process precent=%d\n", i++);        
#else
        STB_ShowProgressStrip(STBSCALE_PATCHING, i++);
#endif
    }
}

void email_process(int flag)
{
#if(test_debug)
    printf("email flag=%d\n", flag);        
#else
    switch(flag)
    {
        case 0 : STB_EmailNotifyIcon(STBEmail_New, 0x1234); break;
        case 1 : STB_EmailNotifyIcon(STBEmail_SpaceExhaust, 0x1234); break;
        case 2 : STB_EmailNotifyIcon(STBEmail_IconHide, 0x1234); break;
        default : break;
    }
#endif

}

void action_process(int flag)
{
#if(test_debug)
    printf("action flag=%d\n", flag);        
#else
    switch(flag)
    {
        case 0 : STB_ActionRequest(1, STBACTIONREQUEST_RESTARTSTB); break;
        case 1 : STB_ActionRequest(1, STBACTIONREQUEST_FREEZESTB); break;
        case 2 : STB_ActionRequest(1, STBACTIONREQUEST_SEARCHCHANNEL); break;
        case 3 : STB_ActionRequest(1, STBACTIONREQUEST_STBUPGRADE); break;
        case 4 : STB_ActionRequest(1, STBACTIONREQUEST_UNFREEZESTB); break;
        case 5 : STB_ActionRequest(1, STBACTIONREQUEST_INITIALIZESTB); break;
        case 6 : STB_ActionRequest(1, STBACTIONREQUEST_SHOWSYSTEMINFO); break;
        default : break;
    }
#endif
}

void curtain_process(int flag)
{
#if(test_debug)
    printf("curtain flag=%d\n", flag);        
#else
    switch(flag)
    {
        case 0 : STB_ShowCurtainNotify(0, 1); break;
        case 1 : 
        {
            STB_ActionRequest(0, 1); 
            STB_ShowBuyMessage(0, STBMESSAGE_CURTAIN_TYPE);
        }
        break;
        case 2 : 
        {
            STB_ActionRequest(0, 0); 
            STB_ShowBuyMessage(0, 0);
        }
        break;
        default : break;
    }
#endif
}

void PLUGIN_CA_TEST_CMD(void)
{    
    printf_cmd_main();
    while(1)
    {
        usleep(10);
        int c = getchar();

        if(isdigit(c) || c=='\n')
        {
            printf("c=%c\n", c);
        }
        else
            continue;
        ca_menu:
        switch(c)
        {
            case '0' :
            {
                while(1)
                {
                    int c1 = getchar();
                    ca_errorcode_menu:
                    switch(c1)
                    {
                        case '0' :
                        {
                            display_errorcode_auto();
                        }
                        break;
                        case '1' :
                        {
                            char str[256] = {0};
                            while(1)
                            {
								memset(str, 0, sizeof(str));
								printf_cmd_errorcode_manul();
                                while(!fgets(str, sizeof(str)-1, stdin))
                                    usleep(10);
                                printf("str1=%s\n", str);
                                char* tmp=strchr(str, '\n');
                                *tmp = '\0';
                                if(!strncmp(str, "exit", strlen("exit")))
                                {
                                    c1 = '\n';
                                    goto ca_errorcode_menu;
                                }
                                else if(!strncmp(str, "display", strlen("dispaly")))
                                {
                                    char* msg = strchr(str, ':');
                                #if(test_debug)
                                    if(msg) printf("dis msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_DISPLAY, msg, strlen(msg) + 1);  
                                #else
                                    msg++;//skip ':'
                                    if(msg) PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_DISPLAY, msg, strlen(msg) + 1);  
                                #endif
                                }
                                else if(!strncmp(str, "hide", strlen("hide")))
                                {
                                    char* msg = strchr(str, ':');
                                #if(test_debug)
                                    if(msg) printf("hide msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_HIDE, msg, strlen(msg) + 1);  
                                #else
                                    msg++;//skip ':'
                                    if(msg) PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_HIDE, msg, strlen(msg) + 1);  
                                #endif
                                }
                                else
                                {
                                    //do nothing
                                }

                                usleep(10);
                            }
                        }
                        break;
                        case '2' :
                        {
                            hide_errorcode_auto();
                        }
                        break;
                        case '3' :
                        {
                            c = '\n';
                            goto ca_menu;
                        }
                        break;
                        case '\n' :
                        {
                            printf_cmd_errorcode();
                        }
                        break;
                        default : break;
                    }

                    usleep(10);
                }
            }
            break;
            case '1' :
            {
                while(1)
                {
                    char str[1024] = {0};
                    while(1)
                    {
                    	memset(str, 0, sizeof(str));
                    	printf_cmd_osd();
                        while(!fgets(str, sizeof(str)-1, stdin))
                            usleep(10);
                        printf("str=%s\n", str);
                        char* tmp=strchr(str, '\n');
                        *tmp = '\0';
                        if(!strncmp(str, "exit", strlen("exit")))
                        {
                            c = '\n';
                            goto ca_menu;
                        }
                        else if(!strncmp(str, "display", strlen("dispaly")))
                        {
                            char* msg = strchr(str, ':');
#if(test_debug)
                            if(msg) printf("dis msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_DISPLAY, msg, strlen(msg) + 1);  
#else
                            msg++;//skip ':'
                            if(msg) PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_OSD_DISPLAY, msg, strlen(msg) + 1);  
#endif
                        }
                        else if(!strncmp(str, "hide", strlen("hide")))
                        {
                            char* msg = strchr(str, ':');
#if(test_debug)
                            if(msg) printf("hide msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_HIDE, msg, strlen(msg) + 1);  
#else
                            msg++;//skip ':'
                            if(msg) PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_OSD_HIDE, msg, strlen(msg) + 1);  
#endif
                        }
                        else
                        {
                            //do nothing
                        }

                        usleep(10);

                    }
                }

            }
            break;
            case '2' :
            {
                char str[1024] = {0};
                while(1)
                {
                    memset(str, 0, sizeof(str));
                    printf_cmd_finger();
                    while(!fgets(str, sizeof(str)-1, stdin))
                        usleep(10);
                    printf("str=%s\n", str);
                    char* tmp=strchr(str, '\n');
                    *tmp = '\0';
                    if(!strncmp(str, "exit", strlen("exit")))
                    {
                        c = '\n';
                        goto ca_menu;
                    }
                    else if(!strncmp(str, "display", strlen("dispaly")))
                    {
                        char* msg = strchr(str, ':');
#if(test_debug)
                        if(msg) printf("dis msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_DISPLAY, msg, strlen(msg) + 1);  
#else
                        msg++;//skip ':'
                        if(msg) PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_FINGER_DISPLAY, msg, strlen(msg) + 1);  
#endif
                    }
                    else if(!strncmp(str, "hide", strlen("hide")))
                    {
                        char* msg = strchr(str, ':');
#if(test_debug)
                        if(msg) printf("hide msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_HIDE, msg, strlen(msg) + 1);  
#else
                        msg++;//skip ':'
                        if(msg) PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_FINGER_HIDE, msg, strlen(msg) + 1);  
#endif
                    }
                    else
                    {
                        //do nothing
                    }

                    usleep(10);

                }
            }
            break;
            case '3' :
            {
                while(1)
                {
                    int c1 = getchar();
                    switch(c1)
                    {
                        case '0' :
                        {
                            sc_upgrade_receiving();
                        }
                        break;
                        case '1' :
                        {
                            sc_upgrade_patching();
                        }
                        break;
                        case '2' :
                        {
                            c = '\n';
                            goto ca_menu;
                        }
                        break;
                        case '\n' :
                        {
                            printf_cmd_scupgrade();
                        }
                        break;
                        default : break;
                    }

                    usleep(10);
                }
            }
            break;
            case '4' :
            {
                while(1)
                {
                    int c1 = getchar();
                    switch(c1)
                    {
                        case '0' :
                        {
                            email_process(0);
                        }
                        break;
                        case '1' :
                        {
                            email_process(1);
                        }
                        break;
                        case '2' :
                        {
                            email_process(2);
                        }
                        break;
                        case '3' :
                        {
                            c = '\n';
                            goto ca_menu;
                        }
                        break;
                        case '\n' :
                        {
                            printf_cmd_email();
                        }
                        break;
                        default : break;
                    }

                    usleep(10);
                }
            }
            break;
            case '5' :
            {
                while(1)
                {
                    int c1 = getchar();
                    switch(c1)
                    {
                        case '0' :
                        {
                            action_process(0);
                        }
                        break;
                        case '1' :
                        {
                            action_process(1);
                        }
                        break;
                        case '2' :
                        {
                            action_process(2);
                        }
                        break;
                        case '3' :
                        {
                            action_process(3);
                        }
                        break;
                        case '4' :
                        {
                            action_process(4);
                        }
                        break;
                        case '5' :
                        {
                            action_process(5);
                        }
                        break;
                        case '6' :
                        {
                            action_process(6);
                        }
                        break;
                        case '7' :
                        {
                            c = '\n';
                            goto ca_menu;
                        }
                        break;
                        case '\n' :
                        {
                            printf_cmd_action();
                        }
                        break;
                        default : break;
                    }

                    usleep(10);
                }
            }
            break;
            case '6' :
            {
                while(1)
                {
                    int c1 = getchar();
                    switch(c1)
                    {
                        case '0' :
                        {
                            curtain_process(0);
                        }
                        break;
                        case '1' :
                        {
                            curtain_process(1);
                        }
                        break;
                        case '2' :
                        {
                            curtain_process(2);
                        }
                        break;
                        case '3' :
                        {
                            c = '\n';
                            goto ca_menu;
                        }
                        break;
                        case '\n' :
                        {
                            printf_cmd_curtain();
                        }
                        break;
                        default : break;
                    }

                    usleep(10);
                }
            }
            break;
            case '7' :
            {
                char str[1024] = {0};
                while(1)
                {
                    memset(str, 0, sizeof(str));
                    printf_cmd_servicelock();
                    while(!fgets(str, sizeof(str)-1, stdin))
                        usleep(10);
                    printf("str=%s\n", str);
                    char* tmp=strchr(str, '\n');
                    *tmp = '\0';
                    if(!strncmp(str, "exit", strlen("exit")))
                    {
                        c = '\n';
                        goto ca_menu;
                    }
                    else if(!strncmp(str, "lock", strlen("lock")))
                    {
                        char* msg = strchr(str, ':');
#if(test_debug)
                        if(msg) printf("lock msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_DISPLAY, msg, strlen(msg) + 1);  
#else
                        msg++;//skip ':'
                        if(msg) iSTB_API_Event_Report(EVENT_PLUGIN_CA_SERVICE_LOCK, msg, strlen(msg) + 1);  
#endif
                    }
                    else if(!strncmp(str, "unlock", strlen("unlock")))
                    {
                        char* msg = strchr(str, ':');
#if(test_debug)
                        if(msg) printf("unlock msg=%s\n", msg);//PLUGIN_CA_Event_Report(EVENT_PLUGIN_CA_BUYMESSGE_HIDE, msg, strlen(msg) + 1);  
#else
                        msg++;//skip ':'
                        if(msg) iSTB_API_Event_Report(EVENT_PLUGIN_CA_SERVICE_UNLOCK, msg, strlen(msg) + 1);  
#endif
                    }
                    else
                    {
                        //do nothing
                    }

                    usleep(10);
                }
            }
            break;
            case '\n' :
            {
				printf_cmd_main();
            }
            break;
            default : break;
        }
    }
}


int main(int argc, char* argv[])
{
	PLUGIN_CA_TEST_CMD();
}
