.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80266EE8
/* 1957C8 80266EE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1957CC 80266EEC AFBF001C */  sw        $ra, 0x1c($sp)
/* 1957D0 80266EF0 AFB20018 */  sw        $s2, 0x18($sp)
/* 1957D4 80266EF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 1957D8 80266EF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 1957DC 80266EFC 8C9001F4 */  lw        $s0, 0x1f4($a0)
/* 1957E0 80266F00 12000011 */  beqz      $s0, .L80266F48
/* 1957E4 80266F04 00A0902D */   daddu    $s2, $a1, $zero
/* 1957E8 80266F08 3C110010 */  lui       $s1, 0x10
/* 1957EC 80266F0C 36310001 */  ori       $s1, $s1, 1
.L80266F10:
/* 1957F0 80266F10 8E030000 */  lw        $v1, ($s0)
/* 1957F4 80266F14 00711024 */  and       $v0, $v1, $s1
/* 1957F8 80266F18 14400008 */  bnez      $v0, .L80266F3C
/* 1957FC 80266F1C 00000000 */   nop
/* 195800 80266F20 8E020094 */  lw        $v0, 0x94($s0)
/* 195804 80266F24 10400005 */  beqz      $v0, .L80266F3C
/* 195808 80266F28 30620002 */   andi     $v0, $v1, 2
/* 19580C 80266F2C 14400003 */  bnez      $v0, .L80266F3C
/* 195810 80266F30 0200202D */   daddu    $a0, $s0, $zero
/* 195814 80266F34 0C099BAA */  jal       func_80266EA8
/* 195818 80266F38 0240282D */   daddu    $a1, $s2, $zero
.L80266F3C:
/* 19581C 80266F3C 8E10000C */  lw        $s0, 0xc($s0)
/* 195820 80266F40 1600FFF3 */  bnez      $s0, .L80266F10
/* 195824 80266F44 00000000 */   nop
.L80266F48:
/* 195828 80266F48 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19582C 80266F4C 8FB20018 */  lw        $s2, 0x18($sp)
/* 195830 80266F50 8FB10014 */  lw        $s1, 0x14($sp)
/* 195834 80266F54 8FB00010 */  lw        $s0, 0x10($sp)
/* 195838 80266F58 03E00008 */  jr        $ra
/* 19583C 80266F5C 27BD0020 */   addiu    $sp, $sp, 0x20
