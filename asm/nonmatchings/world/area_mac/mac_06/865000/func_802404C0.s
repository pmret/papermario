.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404C0
/* 865000 802404C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 865004 802404C4 0080182D */  daddu     $v1, $a0, $zero
/* 865008 802404C8 00A0202D */  daddu     $a0, $a1, $zero
/* 86500C 802404CC 2402FFFF */  addiu     $v0, $zero, -1
/* 865010 802404D0 14820004 */  bne       $a0, $v0, .L802404E4
/* 865014 802404D4 AFBF0010 */   sw       $ra, 0x10($sp)
/* 865018 802404D8 8C64014C */  lw        $a0, 0x14c($v1)
/* 86501C 802404DC 0809013E */  j         .L802404F8
/* 865020 802404E0 00000000 */   nop      
.L802404E4:
/* 865024 802404E4 3C02EFE8 */  lui       $v0, 0xefe8
/* 865028 802404E8 34422080 */  ori       $v0, $v0, 0x2080
/* 86502C 802404EC 0082102A */  slt       $v0, $a0, $v0
/* 865030 802404F0 14400003 */  bnez      $v0, .L80240500
/* 865034 802404F4 0080102D */   daddu    $v0, $a0, $zero
.L802404F8:
/* 865038 802404F8 0C00EAD2 */  jal       get_npc_safe
/* 86503C 802404FC 00000000 */   nop      
.L80240500:
/* 865040 80240500 8FBF0010 */  lw        $ra, 0x10($sp)
/* 865044 80240504 03E00008 */  jr        $ra
/* 865048 80240508 27BD0018 */   addiu    $sp, $sp, 0x18
