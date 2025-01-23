#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_git_repo_volume_source.h"



v1_git_repo_volume_source_t *v1_git_repo_volume_source_create(
    char *directory,
    char *repository,
    char *revision
    ) {
    v1_git_repo_volume_source_t *v1_git_repo_volume_source_local_var = malloc(sizeof(v1_git_repo_volume_source_t));
    if (!v1_git_repo_volume_source_local_var) {
        return NULL;
    }
    v1_git_repo_volume_source_local_var->directory = directory;
    v1_git_repo_volume_source_local_var->repository = repository;
    v1_git_repo_volume_source_local_var->revision = revision;

    return v1_git_repo_volume_source_local_var;
}


void v1_git_repo_volume_source_free(v1_git_repo_volume_source_t *v1_git_repo_volume_source) {
    if(NULL == v1_git_repo_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_git_repo_volume_source->directory) {
        free(v1_git_repo_volume_source->directory);
        v1_git_repo_volume_source->directory = NULL;
    }
    if (v1_git_repo_volume_source->repository) {
        free(v1_git_repo_volume_source->repository);
        v1_git_repo_volume_source->repository = NULL;
    }
    if (v1_git_repo_volume_source->revision) {
        free(v1_git_repo_volume_source->revision);
        v1_git_repo_volume_source->revision = NULL;
    }
    free(v1_git_repo_volume_source);
}

mazu_cJSON *v1_git_repo_volume_source_convertToJSON(v1_git_repo_volume_source_t *v1_git_repo_volume_source) {
    mazu_cJSON *item = mazu_cJSON_CreateObject();

    // v1_git_repo_volume_source->directory
    if(v1_git_repo_volume_source->directory) {
    if(mazu_cJSON_AddStringToObject(item, "directory", v1_git_repo_volume_source->directory) == NULL) {
    goto fail; //String
    }
    }


    // v1_git_repo_volume_source->repository
    if (!v1_git_repo_volume_source->repository) {
        goto fail;
    }
    if(mazu_cJSON_AddStringToObject(item, "repository", v1_git_repo_volume_source->repository) == NULL) {
    goto fail; //String
    }


    // v1_git_repo_volume_source->revision
    if(v1_git_repo_volume_source->revision) {
    if(mazu_cJSON_AddStringToObject(item, "revision", v1_git_repo_volume_source->revision) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        mazu_cJSON_Delete(item);
    }
    return NULL;
}

v1_git_repo_volume_source_t *v1_git_repo_volume_source_parseFromJSON(mazu_cJSON *v1_git_repo_volume_sourceJSON){

    v1_git_repo_volume_source_t *v1_git_repo_volume_source_local_var = NULL;

    // v1_git_repo_volume_source->directory
    mazu_cJSON *directory = mazu_cJSON_GetObjectItemCaseSensitive(v1_git_repo_volume_sourceJSON, "directory");
    if (directory) { 
    if(!mazu_cJSON_IsString(directory) && !mazu_cJSON_IsNull(directory))
    {
    goto end; //String
    }
    }

    // v1_git_repo_volume_source->repository
    mazu_cJSON *repository = mazu_cJSON_GetObjectItemCaseSensitive(v1_git_repo_volume_sourceJSON, "repository");
    if (!repository) {
        goto end;
    }

    
    if(!mazu_cJSON_IsString(repository))
    {
    goto end; //String
    }

    // v1_git_repo_volume_source->revision
    mazu_cJSON *revision = mazu_cJSON_GetObjectItemCaseSensitive(v1_git_repo_volume_sourceJSON, "revision");
    if (revision) { 
    if(!mazu_cJSON_IsString(revision) && !mazu_cJSON_IsNull(revision))
    {
    goto end; //String
    }
    }


    v1_git_repo_volume_source_local_var = v1_git_repo_volume_source_create (
        directory && !mazu_cJSON_IsNull(directory) ? strdup(directory->valuestring) : NULL,
        strdup(repository->valuestring),
        revision && !mazu_cJSON_IsNull(revision) ? strdup(revision->valuestring) : NULL
        );

    return v1_git_repo_volume_source_local_var;
end:
    return NULL;

}
