.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415B0_B21AF0
/* B21AF0 802415B0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B21AF4 802415B4 24040001 */  addiu     $a0, $zero, 1
/* B21AF8 802415B8 27A50010 */  addiu     $a1, $sp, 0x10
/* B21AFC 802415BC 27A60014 */  addiu     $a2, $sp, 0x14
/* B21B00 802415C0 27A70018 */  addiu     $a3, $sp, 0x18
/* B21B04 802415C4 AFBF0028 */  sw        $ra, 0x28($sp)
/* B21B08 802415C8 AFB10024 */  sw        $s1, 0x24($sp)
/* B21B0C 802415CC 0C0470AC */  jal       func_8011C2B0
/* B21B10 802415D0 AFB00020 */   sw       $s0, 0x20($sp)
/* B21B14 802415D4 3C118024 */  lui       $s1, %hi(D_80245954)
/* B21B18 802415D8 26315954 */  addiu     $s1, $s1, %lo(D_80245954)
/* B21B1C 802415DC 8FA40010 */  lw        $a0, 0x10($sp)
/* B21B20 802415E0 8FA50014 */  lw        $a1, 0x14($sp)
/* B21B24 802415E4 8FA60018 */  lw        $a2, 0x18($sp)
/* B21B28 802415E8 0C0904CE */  jal       func_80241338_B21878
/* B21B2C 802415EC 0220382D */   daddu    $a3, $s1, $zero
/* B21B30 802415F0 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B21B34 802415F4 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B21B38 802415F8 8C620000 */  lw        $v0, ($v1)
/* B21B3C 802415FC 24040001 */  addiu     $a0, $zero, 1
/* B21B40 80241600 0040802D */  daddu     $s0, $v0, $zero
/* B21B44 80241604 24420008 */  addiu     $v0, $v0, 8
/* B21B48 80241608 AC620000 */  sw        $v0, ($v1)
/* B21B4C 8024160C 3C02DE00 */  lui       $v0, 0xde00
/* B21B50 80241610 0C0470BB */  jal       func_8011C2EC
/* B21B54 80241614 AE020000 */   sw       $v0, ($s0)
/* B21B58 80241618 8E230000 */  lw        $v1, ($s1)
/* B21B5C 8024161C 04600003 */  bltz      $v1, .L8024162C
/* B21B60 80241620 AE020004 */   sw       $v0, 4($s0)
/* B21B64 80241624 24620004 */  addiu     $v0, $v1, 4
/* B21B68 80241628 AE220000 */  sw        $v0, ($s1)
.L8024162C:
/* B21B6C 8024162C 8E220000 */  lw        $v0, ($s1)
/* B21B70 80241630 28420168 */  slti      $v0, $v0, 0x168
/* B21B74 80241634 14400002 */  bnez      $v0, .L80241640
/* B21B78 80241638 2402FFFF */   addiu    $v0, $zero, -1
/* B21B7C 8024163C AE220000 */  sw        $v0, ($s1)
.L80241640:
/* B21B80 80241640 8FBF0028 */  lw        $ra, 0x28($sp)
/* B21B84 80241644 8FB10024 */  lw        $s1, 0x24($sp)
/* B21B88 80241648 8FB00020 */  lw        $s0, 0x20($sp)
/* B21B8C 8024164C 03E00008 */  jr        $ra
/* B21B90 80241650 27BD0030 */   addiu    $sp, $sp, 0x30
