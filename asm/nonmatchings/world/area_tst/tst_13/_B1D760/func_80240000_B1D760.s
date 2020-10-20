.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B1D760
/* B1D760 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B1D764 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* B1D768 80240008 0080882D */  daddu     $s1, $a0, $zero
/* B1D76C 8024000C AFB00010 */  sw        $s0, 0x10($sp)
/* B1D770 80240010 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* B1D774 80240014 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* B1D778 80240018 AFBF0018 */  sw        $ra, 0x18($sp)
/* B1D77C 8024001C 8E22013C */  lw        $v0, 0x13c($s1)
/* B1D780 80240020 C60C0028 */  lwc1      $f12, 0x28($s0)
/* B1D784 80240024 C60E0030 */  lwc1      $f14, 0x30($s0)
/* B1D788 80240028 C4440008 */  lwc1      $f4, 8($v0)
/* B1D78C 8024002C 46802120 */  cvt.s.w   $f4, $f4
/* B1D790 80240030 44062000 */  mfc1      $a2, $f4
/* B1D794 80240034 C444000C */  lwc1      $f4, 0xc($v0)
/* B1D798 80240038 46802120 */  cvt.s.w   $f4, $f4
/* B1D79C 8024003C 44072000 */  mfc1      $a3, $f4
/* B1D7A0 80240040 0C00A7B5 */  jal       dist2D
/* B1D7A4 80240044 00000000 */   nop      
/* B1D7A8 80240048 24020001 */  addiu     $v0, $zero, 1
/* B1D7AC 8024004C AE220084 */  sw        $v0, 0x84($s1)
/* B1D7B0 80240050 820300B4 */  lb        $v1, 0xb4($s0)
/* B1D7B4 80240054 2402000E */  addiu     $v0, $zero, 0xe
/* B1D7B8 80240058 10620004 */  beq       $v1, $v0, .L8024006C
/* B1D7BC 8024005C 46000086 */   mov.s    $f2, $f0
/* B1D7C0 80240060 24020010 */  addiu     $v0, $zero, 0x10
/* B1D7C4 80240064 54620001 */  bnel      $v1, $v0, .L8024006C
/* B1D7C8 80240068 AE200084 */   sw       $zero, 0x84($s1)
.L8024006C:
/* B1D7CC 8024006C 8E22013C */  lw        $v0, 0x13c($s1)
/* B1D7D0 80240070 C4400010 */  lwc1      $f0, 0x10($v0)
/* B1D7D4 80240074 46800020 */  cvt.s.w   $f0, $f0
/* B1D7D8 80240078 4602003E */  c.le.s    $f0, $f2
/* B1D7DC 8024007C 00000000 */  nop       
/* B1D7E0 80240080 45030001 */  bc1tl     .L80240088
/* B1D7E4 80240084 AE200084 */   sw       $zero, 0x84($s1)
.L80240088:
/* B1D7E8 80240088 8FBF0018 */  lw        $ra, 0x18($sp)
/* B1D7EC 8024008C 8FB10014 */  lw        $s1, 0x14($sp)
/* B1D7F0 80240090 8FB00010 */  lw        $s0, 0x10($sp)
/* B1D7F4 80240094 24020002 */  addiu     $v0, $zero, 2
/* B1D7F8 80240098 03E00008 */  jr        $ra
/* B1D7FC 8024009C 27BD0020 */   addiu    $sp, $sp, 0x20
