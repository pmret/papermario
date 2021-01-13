.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BF47A0
/* BF47A0 80240000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BF47A4 80240004 AFB00018 */  sw        $s0, 0x18($sp)
/* BF47A8 80240008 AFBF001C */  sw        $ra, 0x1c($sp)
/* BF47AC 8024000C F7B40020 */  sdc1      $f20, 0x20($sp)
/* BF47B0 80240010 10A00005 */  beqz      $a1, .L80240028
/* BF47B4 80240014 0080802D */   daddu    $s0, $a0, $zero
/* BF47B8 80240018 AE000070 */  sw        $zero, 0x70($s0)
/* BF47BC 8024001C 3C040001 */  lui       $a0, 1
/* BF47C0 80240020 0C037FBF */  jal       func_800DFEFC
/* BF47C4 80240024 34840007 */   ori      $a0, $a0, 7
.L80240028:
/* BF47C8 80240028 0C038D36 */  jal       func_800E34D8
/* BF47CC 8024002C 00000000 */   nop
/* BF47D0 80240030 46000506 */  mov.s     $f20, $f0
/* BF47D4 80240034 4600A306 */  mov.s     $f12, $f20
/* BF47D8 80240038 0C038D45 */  jal       func_800E3514
/* BF47DC 8024003C 27A50010 */   addiu    $a1, $sp, 0x10
/* BF47E0 80240040 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* BF47E4 80240044 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* BF47E8 80240048 E440002C */  swc1      $f0, 0x2c($v0)
/* BF47EC 8024004C C6000070 */  lwc1      $f0, 0x70($s0)
/* BF47F0 80240050 46800020 */  cvt.s.w   $f0, $f0
/* BF47F4 80240054 4600A505 */  abs.s     $f20, $f20
/* BF47F8 80240058 46140000 */  add.s     $f0, $f0, $f20
/* BF47FC 8024005C 4600008D */  trunc.w.s $f2, $f0
/* BF4800 80240060 44021000 */  mfc1      $v0, $f2
/* BF4804 80240064 00000000 */  nop
/* BF4808 80240068 AE020070 */  sw        $v0, 0x70($s0)
/* BF480C 8024006C 28420033 */  slti      $v0, $v0, 0x33
/* BF4810 80240070 38420001 */  xori      $v0, $v0, 1
/* BF4814 80240074 8FBF001C */  lw        $ra, 0x1c($sp)
/* BF4818 80240078 8FB00018 */  lw        $s0, 0x18($sp)
/* BF481C 8024007C D7B40020 */  ldc1      $f20, 0x20($sp)
/* BF4820 80240080 00021040 */  sll       $v0, $v0, 1
/* BF4824 80240084 03E00008 */  jr        $ra
/* BF4828 80240088 27BD0028 */   addiu    $sp, $sp, 0x28
