.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C4C390
/* C4C390 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C4C394 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* C4C398 80240008 0080882D */  daddu     $s1, $a0, $zero
/* C4C39C 8024000C AFB00010 */  sw        $s0, 0x10($sp)
/* C4C3A0 80240010 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* C4C3A4 80240014 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* C4C3A8 80240018 AFBF0018 */  sw        $ra, 0x18($sp)
/* C4C3AC 8024001C 8E22013C */  lw        $v0, 0x13c($s1)
/* C4C3B0 80240020 C60C0028 */  lwc1      $f12, 0x28($s0)
/* C4C3B4 80240024 C60E0030 */  lwc1      $f14, 0x30($s0)
/* C4C3B8 80240028 C4440008 */  lwc1      $f4, 8($v0)
/* C4C3BC 8024002C 46802120 */  cvt.s.w   $f4, $f4
/* C4C3C0 80240030 44062000 */  mfc1      $a2, $f4
/* C4C3C4 80240034 C444000C */  lwc1      $f4, 0xc($v0)
/* C4C3C8 80240038 46802120 */  cvt.s.w   $f4, $f4
/* C4C3CC 8024003C 44072000 */  mfc1      $a3, $f4
/* C4C3D0 80240040 0C00A7B5 */  jal       dist2D
/* C4C3D4 80240044 00000000 */   nop
/* C4C3D8 80240048 24020001 */  addiu     $v0, $zero, 1
/* C4C3DC 8024004C AE220084 */  sw        $v0, 0x84($s1)
/* C4C3E0 80240050 820300B4 */  lb        $v1, 0xb4($s0)
/* C4C3E4 80240054 2402000E */  addiu     $v0, $zero, 0xe
/* C4C3E8 80240058 10620004 */  beq       $v1, $v0, .L8024006C
/* C4C3EC 8024005C 46000086 */   mov.s    $f2, $f0
/* C4C3F0 80240060 24020010 */  addiu     $v0, $zero, 0x10
/* C4C3F4 80240064 54620001 */  bnel      $v1, $v0, .L8024006C
/* C4C3F8 80240068 AE200084 */   sw       $zero, 0x84($s1)
.L8024006C:
/* C4C3FC 8024006C 8E22013C */  lw        $v0, 0x13c($s1)
/* C4C400 80240070 C4400010 */  lwc1      $f0, 0x10($v0)
/* C4C404 80240074 46800020 */  cvt.s.w   $f0, $f0
/* C4C408 80240078 4602003E */  c.le.s    $f0, $f2
/* C4C40C 8024007C 00000000 */  nop
/* C4C410 80240080 45030001 */  bc1tl     .L80240088
/* C4C414 80240084 AE200084 */   sw       $zero, 0x84($s1)
.L80240088:
/* C4C418 80240088 8FBF0018 */  lw        $ra, 0x18($sp)
/* C4C41C 8024008C 8FB10014 */  lw        $s1, 0x14($sp)
/* C4C420 80240090 8FB00010 */  lw        $s0, 0x10($sp)
/* C4C424 80240094 24020002 */  addiu     $v0, $zero, 2
/* C4C428 80240098 03E00008 */  jr        $ra
/* C4C42C 8024009C 27BD0020 */   addiu    $sp, $sp, 0x20
