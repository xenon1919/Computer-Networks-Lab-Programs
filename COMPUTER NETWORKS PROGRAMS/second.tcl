set ns [new Simulator]
set nf [open first.nam w] 
$ns namtrace-all $nf
proc finish {} {
 global ns nf
$ns flush-trace
close $nf
exec nam first.nam &
exit 0
}
set n0 [$ns node]
$n0 label "s"
set n1 [$ns node]
$n1 label "d"
$ns duplex-link $n0 $n1 10Mb 2ms DropTail
set tcp0 [new Agent/TCP] 
$ns attach-agent $n0 $tcp0
 set sink0 [new Agent/TCPSink] 
 $ns attach-agent $n1 $sink0
set ftp0 [new Application/FTP] 
$ftp0 attach-agent $tcp0
$ns connect $tcp0 $sink0
$ns at 0.5 "$ftp0 start" 
$ns at 2.5 "finish"
$ns run
