## DNS
# Very simple dns-proxy server with support for blacklist

usage:
make r

`dig @127.0.0.1 test.com -p 5555`
or 
`nslookup -port=5555 test.com 127.0.0.1`
