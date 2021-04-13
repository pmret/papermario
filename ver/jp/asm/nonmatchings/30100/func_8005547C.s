.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005547C
/* 3087C 8005547C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30880 80055480 AFB10014 */  sw        $s1, 0x14($sp)
/* 30884 80055484 0080882D */  daddu     $s1, $a0, $zero
/* 30888 80055488 AFB20018 */  sw        $s2, 0x18($sp)
/* 3088C 8005548C 24120004 */  addiu     $s2, $zero, 4
/* 30890 80055490 AFB00010 */  sw        $s0, 0x10($sp)
/* 30894 80055494 0000802D */  daddu     $s0, $zero, $zero
/* 30898 80055498 AFBF001C */  sw        $ra, 0x1c($sp)
.L8005549C:
/* 3089C 8005549C 3C028008 */  lui       $v0, %hi(D_80078D86)
/* 308A0 800554A0 94428D86 */  lhu       $v0, %lo(D_80078D86)($v0)
/* 308A4 800554A4 16020005 */  bne       $s0, $v0, .L800554BC
/* 308A8 800554A8 0200202D */   daddu    $a0, $s0, $zero
/* 308AC 800554AC 0C015466 */  jal       func_80055198
/* 308B0 800554B0 0220282D */   daddu    $a1, $s1, $zero
/* 308B4 800554B4 08015532 */  j         .L800554C8
/* 308B8 800554B8 0040182D */   daddu    $v1, $v0, $zero
.L800554BC:
/* 308BC 800554BC 0C015455 */  jal       func_80055154
/* 308C0 800554C0 0200202D */   daddu    $a0, $s0, $zero
/* 308C4 800554C4 0040182D */  daddu     $v1, $v0, $zero
.L800554C8:
/* 308C8 800554C8 14600004 */  bnez      $v1, .L800554DC
/* 308CC 800554CC 26100001 */   addiu    $s0, $s0, 1
/* 308D0 800554D0 0212102B */  sltu      $v0, $s0, $s2
/* 308D4 800554D4 1440FFF1 */  bnez      $v0, .L8005549C
/* 308D8 800554D8 00000000 */   nop
.L800554DC:
/* 308DC 800554DC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 308E0 800554E0 8FB20018 */  lw        $s2, 0x18($sp)
/* 308E4 800554E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 308E8 800554E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 308EC 800554EC 0060102D */  daddu     $v0, $v1, $zero
/* 308F0 800554F0 03E00008 */  jr        $ra
/* 308F4 800554F4 27BD0020 */   addiu    $sp, $sp, 0x20
