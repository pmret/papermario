.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80048BBC
/* 23FBC 80048BBC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 23FC0 80048BC0 AFB50024 */  sw        $s5, 0x24($sp)
/* 23FC4 80048BC4 3C15800B */  lui       $s5, %hi(D_800B0EF0)
/* 23FC8 80048BC8 26B50EF0 */  addiu     $s5, $s5, %lo(D_800B0EF0)
/* 23FCC 80048BCC AFBF0028 */  sw        $ra, 0x28($sp)
/* 23FD0 80048BD0 AFB40020 */  sw        $s4, 0x20($sp)
/* 23FD4 80048BD4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 23FD8 80048BD8 AFB20018 */  sw        $s2, 0x18($sp)
/* 23FDC 80048BDC AFB10014 */  sw        $s1, 0x14($sp)
/* 23FE0 80048BE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 23FE4 80048BE4 82A2001C */  lb        $v0, 0x1c($s5)
/* 23FE8 80048BE8 1840001C */  blez      $v0, .L80048C5C
/* 23FEC 80048BEC 0000982D */   daddu    $s3, $zero, $zero
/* 23FF0 80048BF0 02A0A02D */  daddu     $s4, $s5, $zero
.L80048BF4:
/* 23FF4 80048BF4 8E920028 */  lw        $s2, 0x28($s4)
/* 23FF8 80048BF8 12400013 */  beqz      $s2, .L80048C48
/* 23FFC 80048BFC 00000000 */   nop
/* 24000 80048C00 8E420000 */  lw        $v0, ($s2)
/* 24004 80048C04 18400010 */  blez      $v0, .L80048C48
/* 24008 80048C08 0000802D */   daddu    $s0, $zero, $zero
/* 2400C 80048C0C 0240882D */  daddu     $s1, $s2, $zero
.L80048C10:
/* 24010 80048C10 8E230004 */  lw        $v1, 4($s1)
/* 24014 80048C14 10600007 */  beqz      $v1, .L80048C34
/* 24018 80048C18 00000000 */   nop
/* 2401C 80048C1C 8C620000 */  lw        $v0, ($v1)
/* 24020 80048C20 30420020 */  andi      $v0, $v0, 0x20
/* 24024 80048C24 14400003 */  bnez      $v0, .L80048C34
/* 24028 80048C28 00000000 */   nop
/* 2402C 80048C2C 0C00E9EB */  jal       func_8003A7AC
/* 24030 80048C30 84640008 */   lh       $a0, 8($v1)
.L80048C34:
/* 24034 80048C34 8E420000 */  lw        $v0, ($s2)
/* 24038 80048C38 26100001 */  addiu     $s0, $s0, 1
/* 2403C 80048C3C 0202102A */  slt       $v0, $s0, $v0
/* 24040 80048C40 1440FFF3 */  bnez      $v0, .L80048C10
/* 24044 80048C44 26310004 */   addiu    $s1, $s1, 4
.L80048C48:
/* 24048 80048C48 82A2001C */  lb        $v0, 0x1c($s5)
/* 2404C 80048C4C 26730001 */  addiu     $s3, $s3, 1
/* 24050 80048C50 0262102A */  slt       $v0, $s3, $v0
/* 24054 80048C54 1440FFE7 */  bnez      $v0, .L80048BF4
/* 24058 80048C58 26940004 */   addiu    $s4, $s4, 4
.L80048C5C:
/* 2405C 80048C5C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 24060 80048C60 8FB50024 */  lw        $s5, 0x24($sp)
/* 24064 80048C64 8FB40020 */  lw        $s4, 0x20($sp)
/* 24068 80048C68 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2406C 80048C6C 8FB20018 */  lw        $s2, 0x18($sp)
/* 24070 80048C70 8FB10014 */  lw        $s1, 0x14($sp)
/* 24074 80048C74 8FB00010 */  lw        $s0, 0x10($sp)
/* 24078 80048C78 0000102D */  daddu     $v0, $zero, $zero
/* 2407C 80048C7C 03E00008 */  jr        $ra
/* 24080 80048C80 27BD0030 */   addiu    $sp, $sp, 0x30
