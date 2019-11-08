#!/bin/bash

factorial() {

    if [ $1 -gt 1 ]; then

        f1 = factorial $(($1-1))
        res=$((curr * f1))

        echo $res

    else
        echo 1

    fi

}

echo "Num:"
read num


fact() {

    res=$1
    num=$1

    while [ $num -gt 1 ]; do
        n=$(($num-1))
        res=$((res*n))
        num=$(($num - 1))
    done

    echo $res

}

factorial $num
