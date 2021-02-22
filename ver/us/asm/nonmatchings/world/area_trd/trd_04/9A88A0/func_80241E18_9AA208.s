.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E18_9AA208
/* 9AA208 80241E18 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9AA20C 80241E1C AFB3002C */  sw        $s3, 0x2c($sp)
/* 9AA210 80241E20 0080982D */  daddu     $s3, $a0, $zero
/* 9AA214 80241E24 AFBF0030 */  sw        $ra, 0x30($sp)
/* 9AA218 80241E28 AFB20028 */  sw        $s2, 0x28($sp)
/* 9AA21C 80241E2C AFB10024 */  sw        $s1, 0x24($sp)
/* 9AA220 80241E30 AFB00020 */  sw        $s0, 0x20($sp)
/* 9AA224 80241E34 8E710148 */  lw        $s1, 0x148($s3)
/* 9AA228 80241E38 86240008 */  lh        $a0, 8($s1)
/* 9AA22C 80241E3C 0C00EABB */  jal       get_npc_unsafe
/* 9AA230 80241E40 00A0902D */   daddu    $s2, $a1, $zero
/* 9AA234 80241E44 8E440004 */  lw        $a0, 4($s2)
/* 9AA238 80241E48 0040802D */  daddu     $s0, $v0, $zero
/* 9AA23C 80241E4C 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9AA240 80241E50 00832021 */  addu      $a0, $a0, $v1
/* 9AA244 80241E54 00042043 */  sra       $a0, $a0, 1
/* 9AA248 80241E58 0C00A67F */  jal       rand_int
/* 9AA24C 80241E5C 24840001 */   addiu    $a0, $a0, 1
/* 9AA250 80241E60 8E430004 */  lw        $v1, 4($s2)
/* 9AA254 80241E64 000327C2 */  srl       $a0, $v1, 0x1f
/* 9AA258 80241E68 00641821 */  addu      $v1, $v1, $a0
/* 9AA25C 80241E6C 00031843 */  sra       $v1, $v1, 1
/* 9AA260 80241E70 00621821 */  addu      $v1, $v1, $v0
/* 9AA264 80241E74 A603008E */  sh        $v1, 0x8e($s0)
/* 9AA268 80241E78 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9AA26C 80241E7C C6000040 */  lwc1      $f0, 0x40($s0)
/* 9AA270 80241E80 C4640000 */  lwc1      $f4, ($v1)
/* 9AA274 80241E84 46802120 */  cvt.s.w   $f4, $f4
/* 9AA278 80241E88 C4620008 */  lwc1      $f2, 8($v1)
/* 9AA27C 80241E8C 468010A0 */  cvt.s.w   $f2, $f2
/* 9AA280 80241E90 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9AA284 80241E94 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9AA288 80241E98 44061000 */  mfc1      $a2, $f2
/* 9AA28C 80241E9C C440000C */  lwc1      $f0, 0xc($v0)
/* 9AA290 80241EA0 46800020 */  cvt.s.w   $f0, $f0
/* 9AA294 80241EA4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 9AA298 80241EA8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9AA29C 80241EAC 44052000 */  mfc1      $a1, $f4
/* 9AA2A0 80241EB0 C4400010 */  lwc1      $f0, 0x10($v0)
/* 9AA2A4 80241EB4 46800020 */  cvt.s.w   $f0, $f0
/* 9AA2A8 80241EB8 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9AA2AC 80241EBC 8C640018 */  lw        $a0, 0x18($v1)
/* 9AA2B0 80241EC0 0C0123F5 */  jal       is_point_within_region
/* 9AA2B4 80241EC4 8E070038 */   lw       $a3, 0x38($s0)
/* 9AA2B8 80241EC8 1040000E */  beqz      $v0, .L80241F04
/* 9AA2BC 80241ECC 00000000 */   nop
/* 9AA2C0 80241ED0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9AA2C4 80241ED4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9AA2C8 80241ED8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9AA2CC 80241EDC C4460000 */  lwc1      $f6, ($v0)
/* 9AA2D0 80241EE0 468031A0 */  cvt.s.w   $f6, $f6
/* 9AA2D4 80241EE4 44063000 */  mfc1      $a2, $f6
/* 9AA2D8 80241EE8 C4460008 */  lwc1      $f6, 8($v0)
/* 9AA2DC 80241EEC 468031A0 */  cvt.s.w   $f6, $f6
/* 9AA2E0 80241EF0 44073000 */  mfc1      $a3, $f6
/* 9AA2E4 80241EF4 0C00A720 */  jal       atan2
/* 9AA2E8 80241EF8 00000000 */   nop
/* 9AA2EC 80241EFC 080907CD */  j         .L80241F34
/* 9AA2F0 80241F00 E600000C */   swc1     $f0, 0xc($s0)
.L80241F04:
/* 9AA2F4 80241F04 0C00A67F */  jal       rand_int
/* 9AA2F8 80241F08 2404003C */   addiu    $a0, $zero, 0x3c
/* 9AA2FC 80241F0C C60C000C */  lwc1      $f12, 0xc($s0)
/* 9AA300 80241F10 44820000 */  mtc1      $v0, $f0
/* 9AA304 80241F14 00000000 */  nop
/* 9AA308 80241F18 46800020 */  cvt.s.w   $f0, $f0
/* 9AA30C 80241F1C 46006300 */  add.s     $f12, $f12, $f0
/* 9AA310 80241F20 3C0141F0 */  lui       $at, 0x41f0
/* 9AA314 80241F24 44810000 */  mtc1      $at, $f0
/* 9AA318 80241F28 0C00A6C9 */  jal       clamp_angle
/* 9AA31C 80241F2C 46006301 */   sub.s    $f12, $f12, $f0
/* 9AA320 80241F30 E600000C */  swc1      $f0, 0xc($s0)
.L80241F34:
/* 9AA324 80241F34 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9AA328 80241F38 8C420004 */  lw        $v0, 4($v0)
/* 9AA32C 80241F3C AE020028 */  sw        $v0, 0x28($s0)
/* 9AA330 80241F40 AE600074 */  sw        $zero, 0x74($s3)
/* 9AA334 80241F44 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9AA338 80241F48 8C420014 */  lw        $v0, 0x14($v0)
/* 9AA33C 80241F4C 04410004 */  bgez      $v0, .L80241F60
/* 9AA340 80241F50 00000000 */   nop
/* 9AA344 80241F54 C6400000 */  lwc1      $f0, ($s2)
/* 9AA348 80241F58 080907E0 */  j         .L80241F80
/* 9AA34C 80241F5C E6000018 */   swc1     $f0, 0x18($s0)
.L80241F60:
/* 9AA350 80241F60 3C018024 */  lui       $at, %hi(D_80246270_9AE660)
/* 9AA354 80241F64 D4226270 */  ldc1      $f2, %lo(D_80246270_9AE660)($at)
/* 9AA358 80241F68 44820000 */  mtc1      $v0, $f0
/* 9AA35C 80241F6C 00000000 */  nop
/* 9AA360 80241F70 46800021 */  cvt.d.w   $f0, $f0
/* 9AA364 80241F74 46220003 */  div.d     $f0, $f0, $f2
/* 9AA368 80241F78 46200020 */  cvt.s.d   $f0, $f0
/* 9AA36C 80241F7C E6000018 */  swc1      $f0, 0x18($s0)
.L80241F80:
/* 9AA370 80241F80 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AA374 80241F84 3C014059 */  lui       $at, 0x4059
/* 9AA378 80241F88 44811800 */  mtc1      $at, $f3
/* 9AA37C 80241F8C 44801000 */  mtc1      $zero, $f2
/* 9AA380 80241F90 46000021 */  cvt.d.s   $f0, $f0
/* 9AA384 80241F94 46220002 */  mul.d     $f0, $f0, $f2
/* 9AA388 80241F98 00000000 */  nop
/* 9AA38C 80241F9C 24020001 */  addiu     $v0, $zero, 1
/* 9AA390 80241FA0 4620018D */  trunc.w.d $f6, $f0
/* 9AA394 80241FA4 E626007C */  swc1      $f6, 0x7c($s1)
/* 9AA398 80241FA8 AE620070 */  sw        $v0, 0x70($s3)
/* 9AA39C 80241FAC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 9AA3A0 80241FB0 8FB3002C */  lw        $s3, 0x2c($sp)
/* 9AA3A4 80241FB4 8FB20028 */  lw        $s2, 0x28($sp)
/* 9AA3A8 80241FB8 8FB10024 */  lw        $s1, 0x24($sp)
/* 9AA3AC 80241FBC 8FB00020 */  lw        $s0, 0x20($sp)
/* 9AA3B0 80241FC0 03E00008 */  jr        $ra
/* 9AA3B4 80241FC4 27BD0038 */   addiu    $sp, $sp, 0x38
