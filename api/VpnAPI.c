#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "VpnAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


void
VpnAPI_startLetheand(apiClient_t *apiClient, char * data_dir , int version )
{
    list_t    *localVarQueryParameters = list_create();
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = NULL;
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/letheand/start")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/letheand/start");




    // query parameters
    char *keyQuery_version = NULL;
    char * valueQuery_version = NULL;
    keyValuePair_t *keyPairQuery_version = 0;
    if (version)
    {
        keyQuery_version = strdup("version");
        valueQuery_version = calloc(1,MAX_NUMBER_LENGTH);
        snprintf(valueQuery_version, MAX_NUMBER_LENGTH, "%d", version);
        keyPairQuery_version = keyValuePair_create(keyQuery_version, valueQuery_version);
        list_addElement(localVarQueryParameters,keyPairQuery_version);
    }

    // query parameters
    char *keyQuery_data_dir = NULL;
    char * valueQuery_data_dir = NULL;
    keyValuePair_t *keyPairQuery_data_dir = 0;
    if (data_dir)
    {
        keyQuery_data_dir = strdup("data_dir");
        valueQuery_data_dir = strdup((data_dir));
        keyPairQuery_data_dir = keyValuePair_create(keyQuery_data_dir, valueQuery_data_dir);
        list_addElement(localVarQueryParameters,keyPairQuery_data_dir);
    }
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    if (apiClient->response_code == 200) {
        printf("%s\n","");
    }
    //No return type
end:
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    list_free(localVarQueryParameters);
    
    
    
    
    free(localVarPath);
    if(keyQuery_data_dir){
        free(keyQuery_data_dir);
        keyQuery_data_dir = NULL;
    }
    if(valueQuery_data_dir){
        free(valueQuery_data_dir);
        valueQuery_data_dir = NULL;
    }
    if(keyPairQuery_data_dir){
        keyValuePair_free(keyPairQuery_data_dir);
        keyPairQuery_data_dir = NULL;
    }
    if(keyQuery_data_dir){
        free(keyQuery_data_dir);
        keyQuery_data_dir = NULL;
    }
    if(keyPairQuery_data_dir){
        keyValuePair_free(keyPairQuery_data_dir);
        keyPairQuery_data_dir = NULL;
    }

}

