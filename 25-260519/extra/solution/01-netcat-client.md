You can use either Netcat (`nc` command, both GNU and BSD versions) or `ncat` anywhere below.
Just replace `nc` with `ncat` if you need.

Warning: do not replace `127.0.0.1` with `localhost`: the latter may mean both IPv4 (`127.0.0.1`) and IPv6 (`::1`), which are not that compatible.

1. Ensure you are connected to the Internet.
2. Execute `echo Hello world | nc tcpbin.com 4242`
    * Be careful: your antivirus/Firewall may try to block outbound connection, allow it.
3. Ensure it prints `Hello world` back. Terminate the app if it did not by itself.
4. Execute `nc tcpbin.com 4242`, type something, press Enter, ensure it replies back the same, repeat for multiple lines.
   Terminate the app if it did not by itself.

Should look [like this](https://asciinema.org/a/KR3vRtzSZBwycRJGrdxutTeQN), see `asciinema play 01-netcat-client.asciinema`.
