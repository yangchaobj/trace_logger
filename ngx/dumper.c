/*
 * implementations of dumpers of common nginx data structure
 */

#include <ngx_config.h>
#include <ngx_core.h>

const char* ngx_str_cstr(const ngx_str_t *ngx_str) {
    static __thread char output[512];
    size_t len = ngx_min(sizeof(output) - 1, ngx_str->len);
    strncpy(output, (char*)ngx_str->data, len);
    output[len] = '\0';
    return output;
}

void dump_ngx_array(const ngx_array_t *arr) {
    printf("dumping ngx_array, nelts = %ld\n", arr->nelts);
    for (uint i = 0; i < arr->nelts; i++) {
        ngx_str_t *word = (ngx_str_t*)((char*)arr->elts + arr->size * i);
        printf("\t%s\n", ngx_str_cstr(word));
    }
    printf("---\n");
}


void dump_ngx_conf(const ngx_conf_t *conf) {
    printf("\tname = %s\n",         conf->name);
    printf("\tmodule_type = 0x%lx\n", conf->module_type);
    printf("\targs = \n");
    dump_ngx_array(conf->args);

    printf("\tcycle = 0x%lx\n",     (long)conf->cycle);
    printf("\tconf_file = 0x%lx\n", (long)conf->conf_file);
    printf("\thandler = 0x%lx\n",   (long)conf->handler);
}

void dump_ngx_core_conf(const ngx_core_conf_t *conf) {
    printf("\tdaemon = %ld\n",           conf->daemon);
    printf("\tmaster = %ld\n",           conf->master);
    printf("\tworker_processes = %ld\n", conf->worker_processes);
    printf("\tpriority = %d\n",          conf->priority);
    printf("\tusername = %s\n",          conf->username);
    printf("\tuser = %d\n",              conf->user);
    printf("\tgroup = %d\n",             conf->group);
    printf("\tworking_directory = %s\n", ngx_str_cstr(&conf->working_directory));
    printf("\tlock_file = %s\n",         ngx_str_cstr(&conf->lock_file));
    printf("\tpid = %s\n",               ngx_str_cstr(&conf->pid));

}

void dump_ngx_module(const ngx_module_t *module)
{
    printf("dump ngx module %s:\n", module->name);
    printf("\tctx_index = %ld\n",   module->ctx_index);
    printf("\tindex = %ld\n",       module->index);
    printf("\tname = %s\n",         module->name);
    printf("\tversion = %ld\n",     module->version);
    printf("\ttype = %ld\n",        module->type);
}

void dump_ngx_core_module(const ngx_core_module_t *module)
{
    printf("dump ngx_core_module %s:\n", ngx_str_cstr(&module->name));
    printf("\tname = %s\n", ngx_str_cstr(&module->name));
}

