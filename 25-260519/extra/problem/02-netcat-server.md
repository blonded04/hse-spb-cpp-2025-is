1. Execute either of two following:
    * `nc -l 127.0.0.1 -p 12345` for GNU version of Netcat.
    * `nc -l 127.0.0.1 12345` for `ncat` or BSD versions of Netcat.
    * Be careful: your antivirus/Firewall may try to block inbound connections, allow it.
    * Do not wait for termination.
2. Navigate to http://localhost:12345 in your browser.
   * May be `http://127.0.0.1:12345` if `localhost` is IPv6 (`[::1]`).
3. Ensure the terminal says something starting with `GET / HTTP/1.1` and `Host: localhost:12345`.
4. Stop the app in the terminal.

Should look [like this](https://asciinema.org/a/bJ2jE7QemnEjsN5O0C82jrXig), see `asciinema play 02-netcat-server.asciinema`
(browser window was not recorded).
