.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044E00
/* 20200 80044E00 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 20204 80044E04 AFB10014 */  sw        $s1, 0x14($sp)
/* 20208 80044E08 0080882D */  daddu     $s1, $a0, $zero
/* 2020C 80044E0C AFBF0020 */  sw        $ra, 0x20($sp)
/* 20210 80044E10 AFB3001C */  sw        $s3, 0x1c($sp)
/* 20214 80044E14 AFB20018 */  sw        $s2, 0x18($sp)
/* 20218 80044E18 AFB00010 */  sw        $s0, 0x10($sp)
/* 2021C 80044E1C 8E30000C */  lw        $s0, 0xc($s1)
/* 20220 80044E20 8E330148 */  lw        $s3, 0x148($s1)
/* 20224 80044E24 8E050000 */  lw        $a1, ($s0)
/* 20228 80044E28 0C0B1EAF */  jal       func_802C7ABC
/* 2022C 80044E2C 26100004 */   addiu    $s0, $s0, 4
/* 20230 80044E30 0040902D */  daddu     $s2, $v0, $zero
/* 20234 80044E34 8E050000 */  lw        $a1, ($s0)
/* 20238 80044E38 0C0B1EAF */  jal       func_802C7ABC
/* 2023C 80044E3C 0220202D */   daddu    $a0, $s1, $zero
/* 20240 80044E40 0040802D */  daddu     $s0, $v0, $zero
/* 20244 80044E44 2402FFFF */  addiu     $v0, $zero, -1
/* 20248 80044E48 16420002 */  bne       $s2, $v0, .L80044E54
/* 2024C 80044E4C 00000000 */   nop
/* 20250 80044E50 86720008 */  lh        $s2, 8($s3)
.L80044E54:
/* 20254 80044E54 0C00FA6A */  jal       func_8003E9A8
/* 20258 80044E58 0240202D */   daddu    $a0, $s2, $zero
/* 2025C 80044E5C 0040982D */  daddu     $s3, $v0, $zero
/* 20260 80044E60 8E620040 */  lw        $v0, 0x40($s3)
/* 20264 80044E64 50400005 */  beql      $v0, $zero, .L80044E7C
/* 20268 80044E68 AE700028 */   sw       $s0, 0x28($s3)
/* 2026C 80044E6C 8E640058 */  lw        $a0, 0x58($s3)
/* 20270 80044E70 0C0B102B */  jal       func_802C40AC
/* 20274 80044E74 00000000 */   nop
/* 20278 80044E78 AE700028 */  sw        $s0, 0x28($s3)
.L80044E7C:
/* 2027C 80044E7C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 20280 80044E80 8FB3001C */  lw        $s3, 0x1c($sp)
/* 20284 80044E84 8FB20018 */  lw        $s2, 0x18($sp)
/* 20288 80044E88 8FB10014 */  lw        $s1, 0x14($sp)
/* 2028C 80044E8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 20290 80044E90 24020002 */  addiu     $v0, $zero, 2
/* 20294 80044E94 03E00008 */  jr        $ra
/* 20298 80044E98 27BD0028 */   addiu    $sp, $sp, 0x28
