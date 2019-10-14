set ns [new Simulator]

set nf [open out.nam w]
$ns namtrace-all $nf

proc finish {} {

	global ns nf
	$ns flush-trace
	close $nf
	exec nam out.nam &
	exit 0
}

set n0 [$ns node]
set n1 [$ns node]

$ns duplex-link $n0 $n1 10Mb 10ms DropTail

set tcp0 [new Agent/TCP]
$tcp0 set class_ 2
$ns attach-agent $n0 $tcp0

set null0 [new Agent/TCPSink]
$ns attach-agent $n1 $null0

$ns connect $tcp0 $null0

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set type_ FTP

$ns at 0.5 "$ftp0 start"
$ns at 4.5 "$ftp0 stop"

$ns at 5.0 "finish"
$ns run