.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800299BC
/* 4DBC 800299BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4DC0 800299C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4DC4 800299C4 04820001 */  bltzl     $a0, .L800299CC
/* 4DC8 800299C8 00042023 */   negu     $a0, $a0
.L800299CC:
/* 4DCC 800299CC 10800018 */  beqz      $a0, .L80029A30
/* 4DD0 800299D0 0000102D */   daddu    $v0, $zero, $zero
/* 4DD4 800299D4 24020001 */  addiu     $v0, $zero, 1
/* 4DD8 800299D8 54820006 */  bnel      $a0, $v0, .L800299F4
/* 4DDC 800299DC 24020064 */   addiu    $v0, $zero, 0x64
/* 4DE0 800299E0 0C00A655 */  jal       func_80029954
/* 4DE4 800299E4 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 4DE8 800299E8 284201F5 */  slti      $v0, $v0, 0x1f5
/* 4DEC 800299EC 0800A68C */  j         .L80029A30
/* 4DF0 800299F0 38420001 */   xori     $v0, $v0, 1
.L800299F4:
/* 4DF4 800299F4 10820005 */  beq       $a0, $v0, .L80029A0C
/* 4DF8 800299F8 00000000 */   nop
/* 4DFC 800299FC 0C00A655 */  jal       func_80029954
/* 4E00 80029A00 00000000 */   nop
/* 4E04 80029A04 0800A68C */  j         .L80029A30
/* 4E08 80029A08 00000000 */   nop
.L80029A0C:
/* 4E0C 80029A0C 0C00A655 */  jal       func_80029954
/* 4E10 80029A10 240403F1 */   addiu    $a0, $zero, 0x3f1
/* 4E14 80029A14 3C036666 */  lui       $v1, 0x6666
/* 4E18 80029A18 34636667 */  ori       $v1, $v1, 0x6667
/* 4E1C 80029A1C 00430018 */  mult      $v0, $v1
/* 4E20 80029A20 000217C3 */  sra       $v0, $v0, 0x1f
/* 4E24 80029A24 00002810 */  mfhi      $a1
/* 4E28 80029A28 00051883 */  sra       $v1, $a1, 2
/* 4E2C 80029A2C 00621023 */  subu      $v0, $v1, $v0
.L80029A30:
/* 4E30 80029A30 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E34 80029A34 03E00008 */  jr        $ra
/* 4E38 80029A38 27BD0018 */   addiu    $sp, $sp, 0x18
