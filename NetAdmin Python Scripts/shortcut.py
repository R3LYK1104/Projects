#!/usr/bin/env python3
#Kyler Ferguson 10/27/23
import os
import subprocess
from subprocess import Popen, PIPE, STDOUT

cwd = os.getcwd()

#uses the find command to find all symlinks located in the desktopp directory
def printReport():
    numSymlinks = subprocess.check_output(["find "+os.path.expanduser("~")+"/Desktop -type l -ls | wc -l"], shell = True).decode('ascii')
    symlinks = subprocess.check_output(["find "+os.path.expanduser("~")+"/Desktop -type l -ls"], shell = True).decode('ascii')
    print('Number of links: ' + numSymlinks)
    print('\n' + symlinks)

#will use the rm command on the path specified
def delete(path):
    try:
        print('attempting to remove ' + path)
        subprocess.run("rm "+ path, shell = True, check = True)
        print('\nDeletion of ' + path + ' successful')
    except:
        print('\nDeletion failed, please ensure you entered the file path correctly')

#will create a symlink for a given path which will be located on the desktop
def createShortcut(path):
    splitpath = path.split('/')
    try:
        print("\nCreating new symlink located at: " +os.path.expanduser("~")+ "/Desktop/"+splitpath[3])
        os.symlink(path, os.path.expanduser("~")+'/Desktop/'+splitpath[len(splitpath)-1], target_is_directory = True)
        print('\nShortcut created successfully!')
    except: 
        print('\nnew symlink creation failed, please ensure you entered your file name correctly')

def main():
    subprocess.run('clear', shell = True, check = True)
    inp = "";
    while(inp != "quit"):
        print('\n===============================\n\tShortcut Generator\n===============================\n')
        print('Your PWD: ' + cwd)
        print('n -  Create new symlink on the dektop')
        print('d -  Delete symlink')
        print('r -  Print report of all symlinks present in "Desktop"')
        print('Type "quit" to quit\n')
        inp = input(': ')

        #quit command case
        if inp == 'quit':
            print('Quitting application... ')
            subprocess.run('clear', shell = True, check = True)
            break

        #new symlink command case
        elif inp == 'n':
            print("please enter the path to the file you wish to creae a link for")
            path = input(': ')
            createShortcut(path)

        #delete command case
        elif inp == 'd':
            print("please enter the path to the symlink you wish to delete")
            path = input(': ')
            delete(path)

        #report command case
        elif inp == 'r':
            print('Printing symlink report... \n')
            printReport()

if __name__ == "__main__":
    main()
