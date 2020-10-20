.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D84
/* 8EDBA4 80241D84 3C038016 */  lui       $v1, 0x8016
/* 8EDBA8 80241D88 8463A552 */  lh        $v1, -0x5aae($v1)
/* 8EDBAC 80241D8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDBB0 80241D90 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EDBB4 80241D94 0080802D */  daddu     $s0, $a0, $zero
/* 8EDBB8 80241D98 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8EDBBC 80241D9C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 8EDBC0 80241DA0 10620003 */  beq       $v1, $v0, .L80241DB0
/* 8EDBC4 80241DA4 24020002 */   addiu    $v0, $zero, 2
/* 8EDBC8 80241DA8 0809078C */  j         .L80241E30
/* 8EDBCC 80241DAC AE000084 */   sw       $zero, 0x84($s0)
.L80241DB0:
/* 8EDBD0 80241DB0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 8EDBD4 80241DB4 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8EDBD8 80241DB8 80620040 */  lb        $v0, 0x40($v1)
/* 8EDBDC 80241DBC 80670044 */  lb        $a3, 0x44($v1)
/* 8EDBE0 80241DC0 04420001 */  bltzl     $v0, .L80241DC8
/* 8EDBE4 80241DC4 00021023 */   negu     $v0, $v0
.L80241DC8:
/* 8EDBE8 80241DC8 14400003 */  bnez      $v0, .L80241DD8
/* 8EDBEC 80241DCC 00000000 */   nop      
/* 8EDBF0 80241DD0 50E00017 */  beql      $a3, $zero, .L80241E30
/* 8EDBF4 80241DD4 0000102D */   daddu    $v0, $zero, $zero
.L80241DD8:
/* 8EDBF8 80241DD8 44822000 */  mtc1      $v0, $f4
/* 8EDBFC 80241DDC 00000000 */  nop       
/* 8EDC00 80241DE0 46802120 */  cvt.s.w   $f4, $f4
/* 8EDC04 80241DE4 44062000 */  mfc1      $a2, $f4
/* 8EDC08 80241DE8 44872000 */  mtc1      $a3, $f4
/* 8EDC0C 80241DEC 00000000 */  nop       
/* 8EDC10 80241DF0 46802120 */  cvt.s.w   $f4, $f4
/* 8EDC14 80241DF4 44806000 */  mtc1      $zero, $f12
/* 8EDC18 80241DF8 44072000 */  mfc1      $a3, $f4
/* 8EDC1C 80241DFC 0C00A720 */  jal       atan2
/* 8EDC20 80241E00 46006386 */   mov.s    $f14, $f12
/* 8EDC24 80241E04 3C014270 */  lui       $at, 0x4270
/* 8EDC28 80241E08 44811000 */  mtc1      $at, $f2
/* 8EDC2C 80241E0C 00000000 */  nop       
/* 8EDC30 80241E10 4602003C */  c.lt.s    $f0, $f2
/* 8EDC34 80241E14 00000000 */  nop       
/* 8EDC38 80241E18 45000004 */  bc1f      .L80241E2C
/* 8EDC3C 80241E1C 24020001 */   addiu    $v0, $zero, 1
/* 8EDC40 80241E20 AE020084 */  sw        $v0, 0x84($s0)
/* 8EDC44 80241E24 0809078C */  j         .L80241E30
/* 8EDC48 80241E28 24020002 */   addiu    $v0, $zero, 2
.L80241E2C:
/* 8EDC4C 80241E2C 0000102D */  daddu     $v0, $zero, $zero
.L80241E30:
/* 8EDC50 80241E30 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8EDC54 80241E34 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EDC58 80241E38 03E00008 */  jr        $ra
/* 8EDC5C 80241E3C 27BD0018 */   addiu    $sp, $sp, 0x18
