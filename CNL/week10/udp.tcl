set ns [new Simulator]

$ns color 1 Blue
$ns color 2 Red

set nf [open N160k.nam w]
$ns namtrace-all $nf

set f [open N160k.tr w]
$ns trace-all $f

proc finish {} {
	global ns nf f
	$ns flush-trace

	close $nf
	close $f

	exec nam N160k.nam &
	exit 0
}

set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n1 $n2 1Mb 50ms DropTail
$ns duplex-link $n2 $n3 100Kb 5ms DropTail

$ns queue-limit $n2 $n3 10

$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link-op $n2 $n3 orient right

$ns duplex-link-op $n2 $n3 queuePos 0.5

set udp [new Agent/UDP]
$ns attach-agent $n1 $udp

set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp $null
$udp set fid_ 2

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 160Kb
$cbr set random_ false

#schedule

$ns at 0.1 "$cbr start"

$ns at 10.0 "$cbr stop"
$ns at 11.0 "finish"

$ns run