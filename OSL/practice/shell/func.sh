#!/bin/bash

hello_func() {

    echo $1
}

echo "Enter name:"
read name

hello_func $name