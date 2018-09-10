# README
## About
* Name      : AddUser
* Author    : Abel Gancsos
* Version   : v. 1.0.0

## Synopsis
This utility is meant to creat a new account on a macOS machine.  Due to there being several steps involved on the Unix side, this utility makes it simpler to create a user account with only one simple command.

## Implementation Description
The utility uses a combination of dscl commands to perform all the operations needed when creating a new user account.  General operations include, creating the home directory, setting the password, and adding the user account to specific groups.

## Assumptions

## Flags
* -username  : Username for the new account
* -password  : Password for the new account
* -first     : First name of the new account
* -last      : Last name of the new account
* -admin     : Switch to identify the account as an administrator

## PREREQUISITES
### G++ compiler
#### Windows
Should come with Visual Studio 2017 in the form of devenv, but you can also try using Bloodshed Dev C++
#### Mac
Should come with XCode command-line tools
#### Linux
Should be installable using internal package installer
### CMake
#### Windows
Should come with Visual Studio 2017
#### Mac
Can be installed from https://cmake.org/download/
#### Linux
Can be installed from https://cmake.org/download/
## Build
This can be built either using one of the run scripts or manually using the following instructions
