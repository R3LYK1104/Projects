#!/usr/bin/python3
#Kyler Ferguson
#11/8/23
from geoip import geolite2
import subprocess, os, re
def main():
    subprocess.run("clear", shell = True, check = True)
    print("please enter the path to your log file:\n")
    path = input(":")
    parseLog(path)
def parseLog(log):
    subprocess.run("clear", shell = True, check = True)
    x = {}
    pat = re.compile(r'(\d{1,3}\.\d{1,3}\.\d{1,3}.\d{1,3})')

    #try to open given file
    if not os.path.isfile(log):
        print("File DNE")
        return(x)

    #try to read the opend file
    try:
        with open(log, 'r') as LOG:
            DATA = LOG.readlines()
            LOG.close()
    except:
        print("Could not read File")
        LOG.close()
        return(x)

    #iterate and stripl lines to find ip addresses for authentication failures and failed password attempts
    for line in DATA: 
        entry = line.strip()
        if entry.find('authentication failure:')>=0 or entry.find('Failed password for') >=0:
            aip = pat.search(entry)[0]
            i = 0
            for ip in x:
                if aip == ip:
                    x[aip]+=1
                    break
                i+=1
            if i == len(x):
                x.update({aip : 1})

    #remove insignificant attempt #<10
    for ip in list(x):
        if x[ip]<10:
            del(x[ip])
    #sort and put in lists

    dic = dict(sorted(x.items(), key = lambda item: item[1]))
    ips = list(dic.keys())
    attempts = list(dic.values())

    #loop for elemnts in list and prind data
    print("Attacker Report ",subprocess.check_output(["date"], shell = True).decode('ascii'))
    print("IP\t\t","ATTEMPTS\t","COUNTRY\n"+"==========================================")
    for i in range(0,len(ips)-1):
        print(ips[i],'\t',attempts[i],'\t\t',geolite2.lookup(ips[i]).country)
if __name__ == "__main__":
    main()
