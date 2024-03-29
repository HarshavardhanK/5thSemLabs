
set ns [new Simulator]


$ns color 1 Blue
$ns color 2 Red


set nf [open out2.nam w]
$ns namtrace-all $nf

set f [open simple2.tr w]
$ns trace-all $f


proc finish {} {
	global ns nf f
	$ns flush-trace
	
	close $nf
	close $f
	
	exec nam out2.nam &
	exit 0
}


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]


$ns duplex-link $n0 $n2 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 2Mb 10ms DropTail
$ns duplex-link $n3 $n4 2Mb 10ms DropTail


$ns queue-limit $n2 $n3 5

$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n3 $n4 orient right 


$ns duplex-link-op $n2 $n3 queuePos 0.5


set tcp [ new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n1 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1


set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP


set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
set null [new Agent/Null]
$ns attach-agent $n4 $null
$ns connect $udp $null
$udp set fid_ 2

set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 500
$cbr set rate_ 1Mb
$cbr set random_ false


$ns at 0.5 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 3.5 "$ftp stop"
$ns at 3.5 "$cbr stop"
$ns at 4.0 "finish"

$ns run



















