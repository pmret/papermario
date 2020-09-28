.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E1298
/* 102B18 802E1298 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102B1C 802E129C 3C04001D */  lui       $a0, 0x1d
/* 102B20 802E12A0 34840004 */  ori       $a0, $a0, 4
/* 102B24 802E12A4 3C05802F */  lui       $a1, 0x802f
/* 102B28 802E12A8 24A5B394 */  addiu     $a1, $a1, -0x4c6c
/* 102B2C 802E12AC AFB00010 */  sw        $s0, 0x10($sp)
/* 102B30 802E12B0 3C10802F */  lui       $s0, 0x802f
/* 102B34 802E12B4 2610B390 */  addiu     $s0, $s0, -0x4c70
/* 102B38 802E12B8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 102B3C 802E12BC AE000000 */  sw        $zero, ($s0)
/* 102B40 802E12C0 0C049640 */  jal       load_string
/* 102B44 802E12C4 ACA00000 */   sw       $zero, ($a1)
/* 102B48 802E12C8 3C04001E */  lui       $a0, 0x1e
/* 102B4C 802E12CC 3484000A */  ori       $a0, $a0, 0xa
/* 102B50 802E12D0 3C01802F */  lui       $at, 0x802f
/* 102B54 802E12D4 AC22B39C */  sw        $v0, -0x4c64($at)
/* 102B58 802E12D8 0C049640 */  jal       load_string
/* 102B5C 802E12DC 0200282D */   daddu    $a1, $s0, $zero
/* 102B60 802E12E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 102B64 802E12E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 102B68 802E12E8 3C01802F */  lui       $at, 0x802f
/* 102B6C 802E12EC AC22B398 */  sw        $v0, -0x4c68($at)
/* 102B70 802E12F0 03E00008 */  jr        $ra
/* 102B74 802E12F4 27BD0018 */   addiu    $sp, $sp, 0x18
