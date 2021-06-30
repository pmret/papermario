.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_05
/* 2840C 8004D00C 8CA20000 */  lw        $v0, ($a1)
/* 28410 8004D010 80430000 */  lb        $v1, ($v0)
/* 28414 8004D014 24420001 */  addiu     $v0, $v0, 1
/* 28418 8004D018 ACA20000 */  sw        $v0, ($a1)
/* 2841C 8004D01C 00031040 */  sll       $v0, $v1, 1
/* 28420 8004D020 00431021 */  addu      $v0, $v0, $v1
/* 28424 8004D024 000210C0 */  sll       $v0, $v0, 3
/* 28428 8004D028 00431021 */  addu      $v0, $v0, $v1
/* 2842C 8004D02C 00021080 */  sll       $v0, $v0, 2
/* 28430 8004D030 03E00008 */  jr        $ra
/* 28434 8004D034 A4A20092 */   sh       $v0, 0x92($a1)
