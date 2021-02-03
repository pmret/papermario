.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425A0_A2C7E0
/* A2C7E0 802425A0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A2C7E4 802425A4 0000202D */  daddu     $a0, $zero, $zero
/* A2C7E8 802425A8 AFB20020 */  sw        $s2, 0x20($sp)
/* A2C7EC 802425AC 3C128025 */  lui       $s2, %hi(D_80249A90_A33CD0)
/* A2C7F0 802425B0 26529A90 */  addiu     $s2, $s2, %lo(D_80249A90_A33CD0)
/* A2C7F4 802425B4 AFBF002C */  sw        $ra, 0x2c($sp)
/* A2C7F8 802425B8 AFB40028 */  sw        $s4, 0x28($sp)
/* A2C7FC 802425BC AFB30024 */  sw        $s3, 0x24($sp)
/* A2C800 802425C0 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2C804 802425C4 AFB00018 */  sw        $s0, 0x18($sp)
/* A2C808 802425C8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* A2C80C 802425CC C6400000 */  lwc1      $f0, ($s2)
/* A2C810 802425D0 46800020 */  cvt.s.w   $f0, $f0
/* A2C814 802425D4 3C148025 */  lui       $s4, %hi(D_80249A84_A33CC4)
/* A2C818 802425D8 26949A84 */  addiu     $s4, $s4, %lo(D_80249A84_A33CC4)
/* A2C81C 802425DC 3C054220 */  lui       $a1, 0x4220
/* A2C820 802425E0 3C06C302 */  lui       $a2, 0xc302
/* A2C824 802425E4 44070000 */  mfc1      $a3, $f0
/* A2C828 802425E8 3C01432A */  lui       $at, 0x432a
/* A2C82C 802425EC 4481A000 */  mtc1      $at, $f20
/* A2C830 802425F0 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* A2C834 802425F4 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* A2C838 802425F8 3C03800B */  lui       $v1, %hi(gCameras)
/* A2C83C 802425FC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A2C840 80242600 AFB40014 */  sw        $s4, 0x14($sp)
/* A2C844 80242604 00028080 */  sll       $s0, $v0, 2
/* A2C848 80242608 02028021 */  addu      $s0, $s0, $v0
/* A2C84C 8024260C 00108080 */  sll       $s0, $s0, 2
/* A2C850 80242610 02028023 */  subu      $s0, $s0, $v0
/* A2C854 80242614 001010C0 */  sll       $v0, $s0, 3
/* A2C858 80242618 02028021 */  addu      $s0, $s0, $v0
/* A2C85C 8024261C 001080C0 */  sll       $s0, $s0, 3
/* A2C860 80242620 02038021 */  addu      $s0, $s0, $v1
/* A2C864 80242624 0C090439 */  jal       func_802410E4_A2B324
/* A2C868 80242628 E7B40010 */   swc1     $f20, 0x10($sp)
/* A2C86C 8024262C C6400000 */  lwc1      $f0, ($s2)
/* A2C870 80242630 46800020 */  cvt.s.w   $f0, $f0
/* A2C874 80242634 0000202D */  daddu     $a0, $zero, $zero
/* A2C878 80242638 3C05C220 */  lui       $a1, 0xc220
/* A2C87C 8024263C 3C064302 */  lui       $a2, 0x4302
/* A2C880 80242640 44070000 */  mfc1      $a3, $f0
/* A2C884 80242644 3C138025 */  lui       $s3, %hi(D_80249A88_A33CC8)
/* A2C888 80242648 26739A88 */  addiu     $s3, $s3, %lo(D_80249A88_A33CC8)
/* A2C88C 8024264C E7B40010 */  swc1      $f20, 0x10($sp)
/* A2C890 80242650 0C090439 */  jal       func_802410E4_A2B324
/* A2C894 80242654 AFB30014 */   sw       $s3, 0x14($sp)
/* A2C898 80242658 C6400000 */  lwc1      $f0, ($s2)
/* A2C89C 8024265C 46800020 */  cvt.s.w   $f0, $f0
/* A2C8A0 80242660 24040003 */  addiu     $a0, $zero, 3
/* A2C8A4 80242664 3C054234 */  lui       $a1, 0x4234
/* A2C8A8 80242668 3C0641C8 */  lui       $a2, 0x41c8
/* A2C8AC 8024266C 44070000 */  mfc1      $a3, $f0
/* A2C8B0 80242670 3C118025 */  lui       $s1, %hi(D_80249A8C_A33CCC)
/* A2C8B4 80242674 26319A8C */  addiu     $s1, $s1, %lo(D_80249A8C_A33CCC)
/* A2C8B8 80242678 E7B40010 */  swc1      $f20, 0x10($sp)
/* A2C8BC 8024267C 0C090439 */  jal       func_802410E4_A2B324
/* A2C8C0 80242680 AFB10014 */   sw       $s1, 0x14($sp)
/* A2C8C4 80242684 C62C0000 */  lwc1      $f12, ($s1)
/* A2C8C8 80242688 C6800000 */  lwc1      $f0, ($s4)
/* A2C8CC 8024268C C6620000 */  lwc1      $f2, ($s3)
/* A2C8D0 80242690 3C0143FA */  lui       $at, 0x43fa
/* A2C8D4 80242694 4481A000 */  mtc1      $at, $f20
/* A2C8D8 80242698 24020001 */  addiu     $v0, $zero, 1
/* A2C8DC 8024269C A6020506 */  sh        $v0, 0x506($s0)
/* A2C8E0 802426A0 E60004B0 */  swc1      $f0, 0x4b0($s0)
/* A2C8E4 802426A4 0C00A8BB */  jal       sin_deg
/* A2C8E8 802426A8 E60204B8 */   swc1     $f2, 0x4b8($s0)
/* A2C8EC 802426AC 46140002 */  mul.s     $f0, $f0, $f20
/* A2C8F0 802426B0 00000000 */  nop
/* A2C8F4 802426B4 C62C0000 */  lwc1      $f12, ($s1)
/* A2C8F8 802426B8 0C00A8D4 */  jal       cos_deg
/* A2C8FC 802426BC E60004F0 */   swc1     $f0, 0x4f0($s0)
/* A2C900 802426C0 46140002 */  mul.s     $f0, $f0, $f20
/* A2C904 802426C4 00000000 */  nop
/* A2C908 802426C8 8E420000 */  lw        $v0, ($s2)
/* A2C90C 802426CC 24420001 */  addiu     $v0, $v0, 1
/* A2C910 802426D0 AE420000 */  sw        $v0, ($s2)
/* A2C914 802426D4 384200AA */  xori      $v0, $v0, 0xaa
/* A2C918 802426D8 E60004F8 */  swc1      $f0, 0x4f8($s0)
/* A2C91C 802426DC 8FBF002C */  lw        $ra, 0x2c($sp)
/* A2C920 802426E0 8FB40028 */  lw        $s4, 0x28($sp)
/* A2C924 802426E4 8FB30024 */  lw        $s3, 0x24($sp)
/* A2C928 802426E8 8FB20020 */  lw        $s2, 0x20($sp)
/* A2C92C 802426EC 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2C930 802426F0 8FB00018 */  lw        $s0, 0x18($sp)
/* A2C934 802426F4 D7B40030 */  ldc1      $f20, 0x30($sp)
/* A2C938 802426F8 2C420001 */  sltiu     $v0, $v0, 1
/* A2C93C 802426FC 03E00008 */  jr        $ra
/* A2C940 80242700 27BD0038 */   addiu    $sp, $sp, 0x38
