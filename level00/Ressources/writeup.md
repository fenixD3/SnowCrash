We are looking for files belonging to the user flag00
and redirect the error output to /dev /null

    find / -user flag00 2>/dev/null

![img.png](img/find.png)

And check the contents of the files

    cat /usr/sbin/john /usr/sbin/john

![img_1.png](img/cat.png)

This text is not suitable as a password.  
It is probably encrypted.  
Trying different decoding options and find that the password is encoded in ROT11.  
This can be checked on the website: http://theblob.org/rot.cgi

![img.png](img/rot.png)

We see a meaningful word and try it as a password: 
    
    nottoohardhere

![img_1.png](img/setpass.png)

token: `x24ti5gi3x0ol2eh4esiuxias`