[comment]: <> (test this step!)
Our home directory is empty. Try find credentials for flag01 in `/etc/passwd` file:

    grep 'flag01' /etc/passwd

![](./img/etc_passwd.png)

We see hashed password for this user. Let's try to crack the password, using `john`.
First, download the `/etc/passwd` on our local machine:

    scp -p 4242 [comment]: <> (try it!)

Start `john` with downloaded file:

    john -user=flag01 ./passwd

[comment]: <> (add john output)

We get password for flag01