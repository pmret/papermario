.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054DC0
/* 301C0 80054DC0 24030007 */  addiu     $v1, $zero, 7
/* 301C4 80054DC4 2482001C */  addiu     $v0, $a0, 0x1c
.L80054DC8:
/* 301C8 80054DC8 AC400238 */  sw        $zero, 0x238($v0)
/* 301CC 80054DCC 2463FFFF */  addiu     $v1, $v1, -1
/* 301D0 80054DD0 0461FFFD */  bgez      $v1, .L80054DC8
/* 301D4 80054DD4 2442FFFC */   addiu    $v0, $v0, -4
/* 301D8 80054DD8 A080025B */  sb        $zero, 0x25b($a0)
/* 301DC 80054DDC A080025A */  sb        $zero, 0x25a($a0)
/* 301E0 80054DE0 A0800259 */  sb        $zero, 0x259($a0)
/* 301E4 80054DE4 03E00008 */  jr        $ra
/* 301E8 80054DE8 A0800258 */   sb       $zero, 0x258($a0)
