override
========

Portmaster password recovery.

<http://portmasters.com/override.html>
 
    Login: !root
    Password: override

Enter provided sixteen character challenge string into this program:

    % gcc -ooverride -lbsd override.c
    % ./override 
    Enter User Challenge: <CHALLENGE>
    Response: <RESPONSE>

    Login: !root
    Password: <RESPONSE>

Set a new password:

    Command> set password <NEW PASSWORD>

