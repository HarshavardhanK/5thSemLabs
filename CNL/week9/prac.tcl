

set ns [new Simulator]
$ns color 1 Blue
$ns color 2 Red

set nf [open out.nam w]
$ns namtrace-all $nf

proc finish {} {

    global ns nf

    $ns flush-trace

    close $nf

    exec nam out.nam &
    exit 0
}

#two nodes one link
set n0 [$ns node]
set n1 [$ns node]

#create link
$ns duplex-link $n0 $n1 1Mb 10ms DropTail

#sending data
set cbr0 [new Agent/CBR]
$ns attach-agent $n0 $cbr0
$cbr0 set packet_size_ 500
$cbr0 set interval_ 0.005

#create traffic sink
set null0 [new Agent/Null]
$ns attach-agent $n1 $null0

$ns connect $cbr0 $null0

$ns at 0.5 "$cbr0 start"
$ns at 2.5 "$cbr0 stop"


$ns at 3.0 "finish"
$ns run