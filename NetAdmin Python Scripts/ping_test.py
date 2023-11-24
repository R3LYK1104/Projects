#!/usr/bin/env python3
#Kyler Ferguson
import os
import subprocess
from subprocess import Popen, PIPE, STDOUT
def testLoc(gate):
    com = f'ping -c 4 {gate}'
    print('Testing Local Network Connectivity...\n')
    test = subprocess.run(com, shell = True, stdout = subprocess.DEVNULL)   
    if test.returncode != 0:
        print('Local connectivity check failed')
    else:
        print('Local connectivity check passed')
def testExt():
    com = 'ping -c 4 129.21.3.17'
    print('Testing External Network Connectivity...\n')
    test = subprocess.run(com, shell = True, stdout = subprocess.DEVNULL)
    if test.returncode !=0:
        print('External connectivity check failed')
    else:
        print('External connectivity check passed')
def testDNS():
    com = 'dig www.google.com'
    print('\nTesting Domain Name service...\n')
    test = subprocess.run(com, shell = True, stdout = subprocess.DEVNULL)
    if test.returncode !=0:
        print('DNS check failed')
    else:
        print('DNS check passed')
def main():
    subprocess.run('clear', shell = True, check = True)
    gtwycmd = "/sbin/route -n | grep 'UG[ \t]' | awk '{print $2}'"
    GATEWAY = subprocess.check_output(gtwycmd, shell = True).decode()
    inp = 0
    while(inp != -1):
        print('\nSelect an option 1-5\n')
        print('#1) Print your current gateway')
        print('#2) Test your local connectivity')
        print('#3) Test remote connectivity')
        print('#4) Test DNS resolution')
        print('#5) Exit\n')
        inp = int(input('Enter your selection: '))
        if inp == 1:
            print('\nPrinting default gateway...\n')
            if len(GATEWAY) != 0:
                print(GATEWAY)
            else:
                print('No default gateway found ensure you are connected to the internet')
        elif inp == 2:
            testLoc(GATEWAY)
        elif inp == 3:
            testExt()
        elif inp == 4:
            testDNS()
        elif inp == 5:
            inp = -1
        else:
            print('\nplease enter a valid selection (1-5)\n')

if __name__ == "__main__":
    main()
