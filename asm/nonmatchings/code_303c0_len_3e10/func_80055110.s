.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055110
/* 30510 80055110 24030007 */  addiu     $v1, $zero, 7
/* 30514 80055114 2482001C */  addiu     $v0, $a0, 0x1c
.L80055118:
/* 30518 80055118 AC400238 */  sw        $zero, 0x238($v0)
/* 3051C 8005511C 2463FFFF */  addiu     $v1, $v1, -1
/* 30520 80055120 0461FFFD */  bgez      $v1, .L80055118
/* 30524 80055124 2442FFFC */   addiu    $v0, $v0, -4
/* 30528 80055128 A080025B */  sb        $zero, 0x25b($a0)
/* 3052C 8005512C A080025A */  sb        $zero, 0x25a($a0)
/* 30530 80055130 A0800259 */  sb        $zero, 0x259($a0)
/* 30534 80055134 03E00008 */  jr        $ra
/* 30538 80055138 A0800258 */   sb       $zero, 0x258($a0)
