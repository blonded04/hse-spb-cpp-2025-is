1. Open two terminals.
2. First terminal: start either `nc -l 127.0.0.1 -p 12345` or `nc -l 127.0.0.1 12345` (depending on your version).
   Do not wait for termination.
3. Second terminal: start `nc localhost 12345`.
   Do not wait for termination.
4. All lines (terminated with Enter) that you type in the first terminal should be sent to the second one and vice-versa.
5. Terminate both apps.

Should look [like this](https://asciinema.org/a/TOO6wIZySiS65A2XRTT283O4E), see `asciinema play 03-netcat-client-server.asciinema`.
