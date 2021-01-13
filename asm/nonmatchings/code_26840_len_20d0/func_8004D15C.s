.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D15C
/* 2855C 8004D15C 94A20090 */  lhu       $v0, 0x90($a1)
/* 28560 8004D160 10400005 */  beqz      $v0, .L8004D178
/* 28564 8004D164 24030003 */   addiu    $v1, $zero, 3
/* 28568 8004D168 8CA20000 */  lw        $v0, ($a1)
/* 2856C 8004D16C A4A3008E */  sh        $v1, 0x8e($a1)
/* 28570 8004D170 2442FFFF */  addiu     $v0, $v0, -1
/* 28574 8004D174 ACA20000 */  sw        $v0, ($a1)
.L8004D178:
/* 28578 8004D178 03E00008 */  jr        $ra
/* 2857C 8004D17C 00000000 */   nop
