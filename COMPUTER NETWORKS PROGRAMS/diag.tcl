proc Diag {a b}  {
set c [expr sqrt($a * $a+$b * $b)]
return $c }
puts "Diagonal of a 3,4 right triangle is [Diag 3 4]"