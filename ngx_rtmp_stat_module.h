#ifndef NGX_RTMP_STAT_MODULE_H
#define NGX_RTMP_STAT_MODULE_H

void ngx_rtmp_stat_output(ngx_http_request_t *r, ngx_chain_t ***lll,
        void *data, size_t len, ngx_uint_t escape);

/* These shortcuts assume 2 variables exist in current context:
 *   ngx_http_request_t    *r
 *   ngx_chain_t         ***lll */

/* plain data */
#define NGX_RTMP_STAT(data, len)    ngx_rtmp_stat_output(r, lll, data, len, 0)

/* escaped data */
#define NGX_RTMP_STAT_E(data, len)  ngx_rtmp_stat_output(r, lll, data, len, 1)

/* literal */
#define NGX_RTMP_STAT_L(s)          NGX_RTMP_STAT((s), sizeof(s) - 1)

/* ngx_str_t */
#define NGX_RTMP_STAT_S(s)          NGX_RTMP_STAT((s)->data, (s)->len)

/* escaped ngx_str_t */
#define NGX_RTMP_STAT_ES(s)         NGX_RTMP_STAT_E((s)->data, (s)->len)

/* C string */
#define NGX_RTMP_STAT_CS(s)         NGX_RTMP_STAT((s), ngx_strlen(s))

/* escaped C string */
#define NGX_RTMP_STAT_ECS(s)        NGX_RTMP_STAT_E((s), ngx_strlen(s))

#endif // NGX_RTMP_STAT_MODULE_H
