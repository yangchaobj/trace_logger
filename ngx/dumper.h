/*
 * headers of commn nginx data structure dumper
 */

#ifndef __DUMPER_H__
#define __DUMPER_H__

#include <ngx_cycle.h>
#include <ngx_config.h>
#include <ngx_core.h>

void dump_conf(const ngx_core_conf_t *conf);
void dump_ngx_array(const ngx_array_t *arr);
void dump_ngx_conf(const ngx_conf_t *conf);
void dump_ngx_core_conf(const ngx_core_conf_t *conf);
void dump_ngx_module(const ngx_module_t *module);
void dump_ngx_core_module(const ngx_core_module_t *module);

const char* ngx_str_cstr(const ngx_str_t *ngx_str);

#define dump_conf(conf) \
    trace_log("dumping ngx_core_conf_t:\n" \
            "\tdaemon = %ld\n" \
            "\tmaster = %ld\n"\
            "\tworker_processes = %ld\n" \
            "\tusername = %s\n" \
            "\tworking directory = %s\n" \
            "\tlock file = %s\n" \
            "\tpid = %s\n", \
            conf->daemon, \
            conf->master, \
            conf->worker_processes, \
            conf->username, \
            conf->working_directory.data, \
            conf->lock_file.data, \
            conf->pid.data \
    )


#define dump_ev(ev) \
    trace_log("dumping ngx_event_t:\n" \
            "\taccept = %d\n" \
            "\twrite = %d\n" \
            "\tavailable = %d\n" \
            "\tinstance = %d\n" \
            "\tactive = %d\n" \
            "\tready = %d\n" \
            "\toneshot = %d\n" \
            "\tcomplete = %d\n" \
            , \
            ev->accept, \
            ev->write, \
            ev->available, \
            ev->instance, \
            ev->active, \
            ev->ready, \
            ev->oneshot, \
            ev->complete \
    )

#endif

