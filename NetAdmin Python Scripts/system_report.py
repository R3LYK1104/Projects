#!/usr/bin/env python3
#Kyler Ferguson     10/3/23
import os
import subprocess, platform, socket, fcntl, struct, ipaddress
from subprocess import Popen, PIPE, STDOUT, check_output
from datetime import date
def main():
    
    subprocess.run("clear", shell = True, check = True)
    today = date.today()
    fqdn = socket.getfqdn().split('.')
    f = open(fqdn[0]+"_system_report.log","w")
    ipaddr = socket.gethostbyname(socket.getfqdn())
    f.write('========================================\n')
    f.write('\tSystem Report '+ str(today)+'\n')
    f.write('========================================\n\n')
    f.write('Device Information \n')
    f.write('Hostname:\t\t'+ fqdn[0]+'\n')
    f.write('Domain:  \t\t'+ fqdn[1]+'.'+fqdn[2]+'\n')
    f.write('\nNetwork Information\n')
    f.write('IP Address:\t\t'+ ipaddr+'\n')
    dfltgtwy = subprocess.check_output(["route -n | grep 'UG[ \t]' | awk '{print $2}'"], shell=True).decode('ascii')
    f.write('Default Gateway:    \t'+dfltgtwy)
    snm = socket.inet_ntoa(fcntl.ioctl(socket.socket(socket.AF_INET, socket.SOCK_DGRAM), 35099, struct.pack('256s', 'ens192'.encode()))[20:24])
    f.write('Subnet Mask: \t\t' + snm+'\n')
    dns1 = subprocess.check_output(["cat /etc/resolv.conf | grep nameserver | head -n 1 | awk '{print $2}'"], shell = True).decode('ascii')
    f.write('DNS1:   \t\t' + dns1)
    dns2 = subprocess.check_output(["cat /etc/resolv.conf | grep nameserver | tail -n 1 | awk '{print $2}'"], shell = True).decode('ascii')
    f.write('DNS2:   \t\t' + dns2)
    f.write('\nOS Information\n')
    os = subprocess.check_output(["cat /etc/*release | grep 'NAME='"], shell = True).decode('ascii').split('"')
    f.write('Operating System:\t' + os[1]+'\n')
    osv = subprocess.check_output(["cat /etc/*release | grep 'VERSION_ID='"], shell = True).decode('ascii').split('"')
    f.write('OS Version: \t\t' + osv[1]+'\n')
    kv = subprocess.check_output(["cat /proc/version"], shell = True).decode('ascii').split(' ')
    f.write('Kernal Version: \t' + kv[2]+'\n\n')
    f.write('Storage Information\n')
    disk = subprocess.check_output(["df -h | grep '/dev/mapper/rl-root'"], shell = True).decode('ascii').split(' ')
    f.write('Hard Drive Capacity: \t'+disk[3]+'\n')
    f.write('Available Space: \t'+disk[8]+'\n\n')
    f.write('Processor Information \n')
    cpum = subprocess.check_output(["cat /proc/cpuinfo | grep 'model name' | head -1"], shell = True).decode('ascii').split(': ')
    f.write('CPU Model: \t\t'+cpum[1])
    numpross = subprocess.check_output(["cat /proc/cpuinfo | grep 'siblings' | head -1"], shell = True).decode('ascii').split(': ')
    f.write('Number of Processors: \t'+str(int(numpross[1])+1))
    cores = subprocess.check_output(["cat /proc/cpuinfo | grep 'cpu cores' | head -1"], shell = True).decode('ascii').split(': ')
    f.write('Number of Cores: \t' + cores[1] + '\n')
    mem = subprocess.check_output(["cat /proc/meminfo | grep 'MemTotal:'"], shell = True).decode('ascii').split('        ')
    mem2 = subprocess.check_output(["cat /proc/meminfo | grep 'MemFree:'"], shell = True).decode('ascii').split('         ')
    f.write('Memory Information\n')
    f.write('Total RAM: \t\t' + mem[1])
    f.write('Available RAM: \t\t' + mem2[1])
    







    print('========================================\n')
    print('\tSystem Report '+ str(today)+'\n')
    print('========================================\n\n')
    print('Device Information ')
    print('Hostname:\t\t'+ fqdn[0])
    print('Domain:  \t\t'+ fqdn[1]+'.'+fqdn[2])
    print('\nNetwork Information')
    print('IP Address:\t\t'+ ipaddr)
    print('Default Gateway:    \t'+dfltgtwy)
    print('Subnet Mask: \t\t' + snm)
    print('DNS1:   \t\t' + dns1.strip())
    print('DNS2:   \t\t' + dns2.strip())
    print('\nOS Information')
    print('Operating System:\t' + os[1])
    print('OS Version: \t\t' + osv[1])
    print('Kernal Version: \t' + kv[2])
    print('\nStorage Information')
    print('Hard Drive Capacity: \t'+disk[3])
    print('Available Space: \t'+disk[8])
    print('\nProcessor Information')
    print('CPU Model: \t\t'+cpum[1].strip())
    print('Number of Processors: \t'+str(int(numpross[1])+1))
    print('Number of Cores: \t' + cores[1].strip())
    print('\nMemory Information')
    print('Total RAM: \t\t' + mem[1].strip())
    print('Available RAM\t\t' + mem2[1].strip())
if __name__ == "__main__":
    main()

