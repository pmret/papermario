.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CE0C
/* 2820C 8004CE0C 94A20090 */  lhu       $v0, 0x90($a1)
/* 28210 8004CE10 10400005 */  beqz      $v0, .L8004CE28
/* 28214 8004CE14 24030003 */   addiu    $v1, $zero, 3
/* 28218 8004CE18 8CA20000 */  lw        $v0, ($a1)
/* 2821C 8004CE1C A4A3008E */  sh        $v1, 0x8e($a1)
/* 28220 8004CE20 2442FFFF */  addiu     $v0, $v0, -1
/* 28224 8004CE24 ACA20000 */  sw        $v0, ($a1)
.L8004CE28:
/* 28228 8004CE28 03E00008 */  jr        $ra
/* 2822C 8004CE2C 00000000 */   nop
