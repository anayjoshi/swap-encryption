# Swap Encryption

A handy tool to encrypt a file by the nibbles of every byte

usage:
```
$ ./swap source dst
```

The nibbles of every byte contained in *source* are swapped and the result is stored in the *dst*. Example,

```
./swap example.txt encrypted.txt
./swap encrypted.txt example_2.txt
```

After executing the commands shown above, example.txt and example_2.txt would be exactly the same. Happy encrypting :)
