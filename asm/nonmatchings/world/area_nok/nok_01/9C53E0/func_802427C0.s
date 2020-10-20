.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427C0
/* 9C7BA0 802427C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C7BA4 802427C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C7BA8 802427C8 8C82000C */  lw        $v0, 0xc($a0)
/* 9C7BAC 802427CC 0C0B1EAF */  jal       get_variable
/* 9C7BB0 802427D0 8C450000 */   lw       $a1, ($v0)
/* 9C7BB4 802427D4 0C015512 */  jal       func_80055448
/* 9C7BB8 802427D8 24040010 */   addiu    $a0, $zero, 0x10
/* 9C7BBC 802427DC 0C0155D8 */  jal       func_80055760
/* 9C7BC0 802427E0 24040004 */   addiu    $a0, $zero, 4
/* 9C7BC4 802427E4 0000202D */  daddu     $a0, $zero, $zero
/* 9C7BC8 802427E8 240500FA */  addiu     $a1, $zero, 0xfa
/* 9C7BCC 802427EC 0C01559B */  jal       func_8005566C
/* 9C7BD0 802427F0 24060001 */   addiu    $a2, $zero, 1
/* 9C7BD4 802427F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C7BD8 802427F8 24020002 */  addiu     $v0, $zero, 2
/* 9C7BDC 802427FC 03E00008 */  jr        $ra
/* 9C7BE0 80242800 27BD0018 */   addiu    $sp, $sp, 0x18
