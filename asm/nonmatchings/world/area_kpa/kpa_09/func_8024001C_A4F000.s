.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024001C_A4F01C
/* A4F01C 8024001C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A4F020 80240020 AFB10014 */  sw        $s1, 0x14($sp)
/* A4F024 80240024 0080882D */  daddu     $s1, $a0, $zero
/* A4F028 80240028 AFBF0018 */  sw        $ra, 0x18($sp)
/* A4F02C 8024002C AFB00010 */  sw        $s0, 0x10($sp)
/* A4F030 80240030 8E30000C */  lw        $s0, 0xc($s1)
/* A4F034 80240034 8E050000 */  lw        $a1, ($s0)
/* A4F038 80240038 0C0B1EAF */  jal       get_variable
/* A4F03C 8024003C 26100004 */   addiu    $s0, $s0, 4
/* A4F040 80240040 0220202D */  daddu     $a0, $s1, $zero
/* A4F044 80240044 8E050000 */  lw        $a1, ($s0)
/* A4F048 80240048 0C0B1EAF */  jal       get_variable
/* A4F04C 8024004C 0040802D */   daddu    $s0, $v0, $zero
/* A4F050 80240050 0040182D */  daddu     $v1, $v0, $zero
/* A4F054 80240054 3C028016 */  lui       $v0, 0x8016
/* A4F058 80240058 8442A552 */  lh        $v0, -0x5aae($v0)
/* A4F05C 8024005C 16020009 */  bne       $s0, $v0, .L80240084
/* A4F060 80240060 00000000 */   nop      
/* A4F064 80240064 8E220084 */  lw        $v0, 0x84($s1)
/* A4F068 80240068 00431021 */  addu      $v0, $v0, $v1
/* A4F06C 8024006C 44820000 */  mtc1      $v0, $f0
/* A4F070 80240070 00000000 */  nop       
/* A4F074 80240074 46800020 */  cvt.s.w   $f0, $f0
/* A4F078 80240078 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* A4F07C 8024007C 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* A4F080 80240080 E440002C */  swc1      $f0, 0x2c($v0)
.L80240084:
/* A4F084 80240084 8FBF0018 */  lw        $ra, 0x18($sp)
/* A4F088 80240088 8FB10014 */  lw        $s1, 0x14($sp)
/* A4F08C 8024008C 8FB00010 */  lw        $s0, 0x10($sp)
/* A4F090 80240090 24020002 */  addiu     $v0, $zero, 2
/* A4F094 80240094 03E00008 */  jr        $ra
/* A4F098 80240098 27BD0020 */   addiu    $sp, $sp, 0x20
/* A4F09C 8024009C 00000000 */  nop       
