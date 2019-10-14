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

$ns duplex-link $n0 $n1 2Mb 20ms DropTail

set tcp0 [new Agent/TCP]
$tcp0 set class_ 2
$ns attach-agent $n0 $tcp0
$tcp0 set fid_ 2

set null0 [new Agent/TCPSink]
$ns attach-agent $n1 $null0

$ns connect $tcp0 $null0

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
$ftp0 set type_ FTP

set n2 [$ns node]
set n3 [$ns node]

$ns duplex-link $n2 $n3 1Mb 10ms DropTail

set tcp1 [new Agent/TCP]
$tcp1 set class_ 2
$ns attach-agent $n2 $tcp1
$tcp1 set fid_ 1

set null1 [new Agent/TCPSink]
$ns attach-agent $n3 $null1

$ns connect $tcp1 $null1

set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP

$ns at 0.5 "$ftp0 start"
$ns at 4.5 "$ftp0 stop"
$ns at 1.0 "$ftp1 start"
$ns at 4.0 "$ftp1 stop"

$ns at 5.0 "finish"
$ns run