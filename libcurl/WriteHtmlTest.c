
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

size_t WriteHeader(char *buffer,   size_t size,   size_t nitems,   void *userdata)
{
	fwrite(buffer, size, nitems, (FILE*)userdata);
	
	return size*nitems;
}

size_t WriteBody(char *buffer,   size_t size,   size_t nitems,   void *userdata)
{
	fwrite(buffer, size, nitems, (FILE*)userdata);
	
	return size*nitems;
}

int main(int argc, char *argv[])
{
	int i = 0;

	CURL *psCurlHandle = NULL;
	CURLcode ret = 0;
	
	FILE *psHeaderHandle = NULL;
	FILE *psContent = NULL;
	
	char acPath[128] = {0};

	for(i=0; i<argc; i++)
	{
		printf("--------->argv[%d] = %s\n", i, argv[i]);	
	}

	psCurlHandle = curl_easy_init();

	if(psCurlHandle == NULL)
	{
		printf("---------->return error\n");

		return -1;
	}
	
	sprintf(acPath, "./%s", argv[2]);
	
	psHeaderHandle = fopen(acPath, "w+a");
	
	memset(acPath, 0, sizeof(acPath));
	
	sprintf(acPath, "./%s", argv[3]);
	
	psContent = fopen(acPath, "w+a");
	
	curl_easy_setopt(psCurlHandle, CURLOPT_URL, argv[1]);
	
	curl_easy_setopt(psCurlHandle, CURLOPT_HEADERFUNCTION, WriteHeader); 

	curl_easy_setopt(psCurlHandle, CURLOPT_WRITEHEADER, (void*)psHeaderHandle);

	curl_easy_setopt(psCurlHandle, CURLOPT_WRITEFUNCTION, WriteBody);

	curl_easy_setopt(psCurlHandle, CURLOPT_WRITEDATA, (void*)psContent);

	ret = curl_easy_perform(psCurlHandle);

	fclose(psHeaderHandle);
	
	fclose(psContent);
	
	curl_easy_cleanup(psCurlHandle);

	return 0;
}
