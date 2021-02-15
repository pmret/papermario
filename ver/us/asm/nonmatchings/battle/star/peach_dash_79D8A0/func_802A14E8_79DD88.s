.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A14E8_79DD88
/* 79DD88 802A14E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 79DD8C 802A14EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 79DD90 802A14F0 0C00EABB */  jal       get_npc_unsafe
/* 79DD94 802A14F4 24040064 */   addiu    $a0, $zero, 0x64
/* 79DD98 802A14F8 0040202D */  daddu     $a0, $v0, $zero
/* 79DD9C 802A14FC 24030020 */  addiu     $v1, $zero, 0x20
/* 79DDA0 802A1500 A48300A8 */  sh        $v1, 0xa8($a0)
/* 79DDA4 802A1504 A48300A6 */  sh        $v1, 0xa6($a0)
/* 79DDA8 802A1508 8FBF0010 */  lw        $ra, 0x10($sp)
/* 79DDAC 802A150C 24020002 */  addiu     $v0, $zero, 2
/* 79DDB0 802A1510 03E00008 */  jr        $ra
/* 79DDB4 802A1514 27BD0018 */   addiu    $sp, $sp, 0x18
