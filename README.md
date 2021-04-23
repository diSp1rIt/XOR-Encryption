# XOR-Encryption
Simple cryptor for messages using xor bool function
# **Warning**
Don't use this script to encrypt any important files
# Installing
You can compile program from source code:
```bash
g++ main.cpp libs/xorcrypt.cpp libs/argparser.cpp -Wall -o crypt
```
### Version of compiler:
```bash
g++ --version
g++ (Debian 10.2.1-6) 10.2.1 20210110
Copyright (C) 2020 Free Software Foundation, Inc.
```
> `make` script will be added to project.
# Usage
Before start using script you have to create `<key file>`.
Example:
```bash
echo "some text with length under 1024 symbols" > xor.key
```
____
To encrypt some text execute:
```bash
crypt -t <text> -o <output file> -k <key file>
```
To encrypt file:
```bash
crypt -i <input file> -o <output file> -k <key file>
```
> Output of encrypted data can be store to file only!
___
To decrypt use same command to crypt file:
```bash
crypt -i <input file> -o <output file> -k <key file>
```
