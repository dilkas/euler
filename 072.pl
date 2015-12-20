use strict;
use warnings;

use constant MIN_D => 2;
use constant MAX_D => 1000000;

my @phi = (0 .. MAX_D);
my @prime = (1) x scalar(@phi);

for my $p (2 .. $#phi) {
    next if (!$prime[$p]);
    for (my $n = $p; $n <= $#phi; $n += $p) {
        $phi[$n] *= 1 - 1 / $p;
        $prime[$n] = 0;
    }
}

my $sum = -1;
$sum += $_ for @phi;
print $sum . "\n";
