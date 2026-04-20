#include <localcve/internal/config.h>

int lc_impl_read_cfg_stream(FILE* stream, localcve_config** config) {
    if(stream == NULL || config == NULL)
        return LC_ERROR | LC_ERR_UNEXP_PTR_NULL;

    if(*config == NULL)
        *config = malloc(sizeof(localcve_config));

    /// @todo Error handling for `lc_impl_read_cfg_stream`
    /// @todo Write tests for `lc_impl_read_cfg_stream`

    // Go to the beginning of the file, I somehow always forget what SEEK_SET does
    fseek(stream, 0, SEEK_SET);

    // Read the data path
    fread(&((*config)->data_path_length), sizeof(uint16_t), 1, stream);
    fread(&((*config)->data_path), sizeof(char), (*config)->data_path_length, stream);

    // Read the cve git string
    fread(&((*config)->cve_git_length), sizeof(uint16_t), 1, stream);
    fread(&((*config)->cve_git), sizeof(char), (*config)->cve_git_length, stream);

    // Read the ghsa git string
    fread(&((*config)->ghsa_git_length), sizeof(uint16_t), 1, stream);
    fread(&((*config)->ghsa_git), sizeof(char), (*config)->ghsa_git_length, stream);

    return LC_OK;
}

int lc_impl_write_cfg_stream(FILE* stream, localcve_config* config) {
    if(stream == NULL || config == NULL)
        return LC_ERROR | LC_ERR_UNEXP_PTR_NULL;

    /// @todo Error handling for `lc_impl_write_cfg_stream`
    /// @todo Write tests for `lc_impl_write_cfg_stream`

    fseek(stream, 0, SEEK_SET);

    // Write the data path
    fwrite(&config->data_path_length, sizeof(uint16_t), 1, stream);
    fwrite(&config->data_path, sizeof(char), config->data_path_length, stream);

    // Write the cve git string
    fwrite(&config->cve_git_length, sizeof(uint16_t), 1, stream);
    fwrite(&config->cve_git, sizeof(char), config->cve_git_length, stream);

    // Write the ghsa git string
    fwrite(&config->ghsa_git_length, sizeof(uint16_t), 1, stream);
    fwrite(&config->ghsa_git, sizeof(char), config->ghsa_git_length, stream);

    return LC_OK;
}

int lc_impl_cfg_check(localcve_config* config) {
    if(config == NULL)
        return LC_ERROR | LC_ERR_UNEXP_PTR_NULL;

    // Things like the data path, cve git, and ghsa git strings CANNOT be empty or NULL
    if(config->data_path == NULL ||
        config->cve_git == NULL ||
        config->ghsa_git == NULL)
        return LC_ERROR | LC_ERR_UNEXP_PTR_NULL;

    if(config->data_path_length == 0 ||
        config->cve_git_length == 0 ||
        config->ghsa_git_length == 0)
        return LC_ERROR | LC_ERR_UNEXP_VALUE;

    return LC_OK;
}

int lc_impl_cfg_defaults(localcve_config* config) {
    // This sort of assumes that the memory is already allocated

    /// @todo Test that this doesn't just crash and burn

    // Can't exactly set the value for the data path, since that's user-determined

    memcpy(config->cve_git, localcve_default_cve_path, sizeof(char) * strlen(localcve_default_cve_path));
    config->cve_git_length = strlen(config->cve_git);

    memcpy(config->ghsa_git, localcve_default_ghsa_path, sizeof(char) * strlen(localcve_default_ghsa_path));
    config->ghsa_git_length = strlen(config->ghsa_git);

    return LC_OK;
}