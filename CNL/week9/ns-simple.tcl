#!/usr/bin/tclsh

#create a simulator object
set ns [new simulator]

#define different colors for data flows
set nf [open out.nam w]
$ns namtrace-all $nf

#open the trace file
set f [open simple.tr w]
$ns trace-all $f

#Define a 'finish' procedure

proc finish {} {
    global ns nf f
    $ns flush-trace

    #Close the NAM trace file
    close $nf
    close $f

    #Execute NAM on the trace file
    exec nam out.nam &
    exit 0
}

#Create four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail

#Set queue size of link (n2 - n3) to 10
$ns queue-limit $n2 $n3 10

#Give node position (for NAM)
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n0 $n2 orient right-up
$ns duplex-link-op $n0 $n2 orient right

#Monitor the queue for link (n2-n3) (for NAM)
$ns duplex-link-op $n2 $n3  queuePos 0.5

#Setup a TCP connection
set tcp [tcp Agent/TCP]
$tcp set class_2
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$tcp set fid_ 1

#setup a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

#setup a UDP connection
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp $null
$udp set fid_ 2

#setup a CBR over UDP connection (1000B every 10ms)
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set interval
