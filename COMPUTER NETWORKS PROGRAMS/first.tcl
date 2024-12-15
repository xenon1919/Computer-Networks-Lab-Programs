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
set udp0 [new Agent/UDP] 
$ns attach-agent $n0 $udp0
 set null0 [new Agent/Null] 
 $ns attach-agent $n1 $null0
set cbr0 [new Application/Traffic/CBR] 
$cbr0 attach-agent $udp0
$ns connect $udp0 $null0
$ns at 0.5 "$cbr0 start" 
$ns at 2.5 "finish"
$ns run
