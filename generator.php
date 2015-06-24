#!/usr/bin/env php
<?php

set_time_limit(0);

$f = fopen(__DIR__ . '/input.dat', 'w');
for ($i = 0; $i < 1000000; $i++) {
    $str = sprintf(
        "%s%s%s\n",
        mt_rand(1, 9),
        substr(mt_rand(0, 9999) . mt_rand(0, 9999) . mt_rand(0, 9999) . mt_rand(0, 9999), 0, 4),
        substr(mt_rand(0, 9999) . mt_rand(0, 9999) . mt_rand(0, 9999) . mt_rand(0, 9999), 0, 4)
    );
    fwrite($f, $str);
}
fclose($f);
