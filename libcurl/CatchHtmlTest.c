
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i = 0;

	CURL *psCurlHandle = NULL;
	CURLcode ret = 0;

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

	curl_easy_setopt(psCurlHandle, CURLOPT_URL, argv[1]);

	ret = curl_easy_perform(psCurlHandle);

	curl_easy_cleanup(psCurlHandle);

	return 0;
}
