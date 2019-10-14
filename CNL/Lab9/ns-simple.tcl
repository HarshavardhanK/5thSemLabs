#Create a simulator object
set ns [new Simulator]

#Define different colors for data flows (for NAM)
$ns color 1 Blue
$ns color 2 Red

#Open the NAM Trace File
set nf [open out.nam w]
$ns namtrace-all $nf

#Open the trace file
set f [open simple.tr w]
$ns trace-all $f

#Define a finish procedure
proc finish() {
	global ns nf f
	$ns flush-trace

	#Close the NAM trace file
	close $nf
	close $f

	#Execute NAM on the trace file
	exec name out.name &
	exit 0
}

#Create 4 Nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

#Create Links between the Nodes
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 2ms DropTail

#Set queue sizes for the links
$ns queue-limit $n2 $n3 10

#Give node positions to NAM
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right

#Monitor the queue for link (n2-n3 for NAM)
$ns duplex-link-op $n2 $n3 queuePOs 0.5

#Setup a TCP Connection
set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n0 $tcp
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp $sink
$tcp set fid_ 1

#Set up a FTP over TCP
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

#Setup a UDP Connection
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
set null [new Agent/Null]
$ns attach-agent $n3 $null
$ns connect $udp $null
$udp set fid_ 2

#Setup CBR over UDP connection (1000 bytes every 10ms)
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set interval_ 0.010
$cbr set random_ false

#Schedule events for the CBR and FTP agents
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 4.5 "$cbr stop"

#Detach TCP and Sink agents
$ns at 4.5 "$ns detach-agent $n0 $tcp ; $ns detach-agent $n3 $sink"

#Call finish procedure after 5s
$ns at 5.0 "finish"

#Print CBR Packet size and interval
puts "CBR Packet Size = [$cbr set packet_size_]"
puts "CBR interval = [$cbr set interval_]"

#Run the simulation
$ns run