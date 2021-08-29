.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E04_7ECB14
/* 7ECB14 80241E04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7ECB18 80241E08 AFB20018 */  sw        $s2, 0x18($sp)
/* 7ECB1C 80241E0C 0080902D */  daddu     $s2, $a0, $zero
/* 7ECB20 80241E10 AFB10014 */  sw        $s1, 0x14($sp)
/* 7ECB24 80241E14 0000882D */  daddu     $s1, $zero, $zero
/* 7ECB28 80241E18 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECB2C 80241E1C 3C108025 */  lui       $s0, %hi(D_80248F20_7F3C30)
/* 7ECB30 80241E20 26108F20 */  addiu     $s0, $s0, %lo(D_80248F20_7F3C30)
/* 7ECB34 80241E24 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7ECB38 80241E28 0240202D */  daddu     $a0, $s2, $zero
.L80241E2C:
/* 7ECB3C 80241E2C 3C05F5DE */  lui       $a1, 0xf5de
/* 7ECB40 80241E30 0C0B1EAF */  jal       get_variable
/* 7ECB44 80241E34 34A50180 */   ori      $a1, $a1, 0x180
/* 7ECB48 80241E38 0240202D */  daddu     $a0, $s2, $zero
/* 7ECB4C 80241E3C 26310001 */  addiu     $s1, $s1, 1
/* 7ECB50 80241E40 8E050000 */  lw        $a1, ($s0)
/* 7ECB54 80241E44 8E03FFFC */  lw        $v1, -4($s0)
/* 7ECB58 80241E48 26100014 */  addiu     $s0, $s0, 0x14
/* 7ECB5C 80241E4C 0043102A */  slt       $v0, $v0, $v1
/* 7ECB60 80241E50 0C0B2026 */  jal       evt_set_variable
/* 7ECB64 80241E54 38460001 */   xori     $a2, $v0, 1
/* 7ECB68 80241E58 2E220024 */  sltiu     $v0, $s1, 0x24
/* 7ECB6C 80241E5C 1440FFF3 */  bnez      $v0, .L80241E2C
/* 7ECB70 80241E60 0240202D */   daddu    $a0, $s2, $zero
/* 7ECB74 80241E64 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7ECB78 80241E68 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ECB7C 80241E6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ECB80 80241E70 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECB84 80241E74 24020002 */  addiu     $v0, $zero, 2
/* 7ECB88 80241E78 03E00008 */  jr        $ra
/* 7ECB8C 80241E7C 27BD0020 */   addiu    $sp, $sp, 0x20
