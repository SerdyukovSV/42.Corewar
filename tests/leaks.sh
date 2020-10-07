#!/bin/bash

list=$2

for champion in ~/apft_checker_corewar/champs/bytecode/*
do
    # $1 $champion
    valgrind --log-file=tests/log.txt $1 $champion
    definitely=`echo $(grep -E 'definitely' tests/log.txt) | cut -d' ' -f4`
    indirectly=`echo $(grep -E 'indirectly' tests/log.txt) | cut -d' ' -f4`
    ERROR=`echo $(grep -E 'ERROR SUMMARY' tests/log.txt) | cut -d' ' -f4`
    # printf "\e[92m$defin\n\e[0m"
    if [ "$definitely" == "0" ]
    then
        printf "definitely = $definitely : \e[92mSUCCESS\n\e[0m"
    else
        printf "definitely = $definitely : \e[91mFAIL\n\e[0m"
    fi
    
    if [ "$indirectly" == "0" ]
    then
        printf "indirectly = $indirectly : \e[92mSUCCESS\n\e[0m"
    else
        printf "indirectly = $indirectly : \e[91mFAIL\n\e[0m"
    fi
    
    if [ "$ERROR" == "0" ]
    then
        printf "ERROR      = $ERROR : \e[92mSUCCESS\n\e[0m"
    else
        printf "ERROR      = $ERROR : \e[91mFAIL\n\e[0m"
    fi
    printf "\n"
    # sleep 1
done
