.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241654_B21B94
/* B21B94 80241654 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B21B98 80241658 24040002 */  addiu     $a0, $zero, 2
/* B21B9C 8024165C 27A50010 */  addiu     $a1, $sp, 0x10
/* B21BA0 80241660 27A60014 */  addiu     $a2, $sp, 0x14
/* B21BA4 80241664 27A70018 */  addiu     $a3, $sp, 0x18
/* B21BA8 80241668 AFBF0028 */  sw        $ra, 0x28($sp)
/* B21BAC 8024166C AFB10024 */  sw        $s1, 0x24($sp)
/* B21BB0 80241670 0C0470AC */  jal       func_8011C2B0
/* B21BB4 80241674 AFB00020 */   sw       $s0, 0x20($sp)
/* B21BB8 80241678 3C118024 */  lui       $s1, %hi(D_80245958)
/* B21BBC 8024167C 26315958 */  addiu     $s1, $s1, %lo(D_80245958)
/* B21BC0 80241680 8FA40010 */  lw        $a0, 0x10($sp)
/* B21BC4 80241684 8FA50014 */  lw        $a1, 0x14($sp)
/* B21BC8 80241688 8FA60018 */  lw        $a2, 0x18($sp)
/* B21BCC 8024168C 0C0904CE */  jal       func_80241338_B21878
/* B21BD0 80241690 0220382D */   daddu    $a3, $s1, $zero
/* B21BD4 80241694 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* B21BD8 80241698 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* B21BDC 8024169C 8C620000 */  lw        $v0, ($v1)
/* B21BE0 802416A0 24040002 */  addiu     $a0, $zero, 2
/* B21BE4 802416A4 0040802D */  daddu     $s0, $v0, $zero
/* B21BE8 802416A8 24420008 */  addiu     $v0, $v0, 8
/* B21BEC 802416AC AC620000 */  sw        $v0, ($v1)
/* B21BF0 802416B0 3C02DE00 */  lui       $v0, 0xde00
/* B21BF4 802416B4 0C0470BB */  jal       func_8011C2EC
/* B21BF8 802416B8 AE020000 */   sw       $v0, ($s0)
/* B21BFC 802416BC 8E230000 */  lw        $v1, ($s1)
/* B21C00 802416C0 04600003 */  bltz      $v1, .L802416D0
/* B21C04 802416C4 AE020004 */   sw       $v0, 4($s0)
/* B21C08 802416C8 24620004 */  addiu     $v0, $v1, 4
/* B21C0C 802416CC AE220000 */  sw        $v0, ($s1)
.L802416D0:
/* B21C10 802416D0 8E220000 */  lw        $v0, ($s1)
/* B21C14 802416D4 28420168 */  slti      $v0, $v0, 0x168
/* B21C18 802416D8 14400002 */  bnez      $v0, .L802416E4
/* B21C1C 802416DC 2402FFFF */   addiu    $v0, $zero, -1
/* B21C20 802416E0 AE220000 */  sw        $v0, ($s1)
.L802416E4:
/* B21C24 802416E4 8FBF0028 */  lw        $ra, 0x28($sp)
/* B21C28 802416E8 8FB10024 */  lw        $s1, 0x24($sp)
/* B21C2C 802416EC 8FB00020 */  lw        $s0, 0x20($sp)
/* B21C30 802416F0 03E00008 */  jr        $ra
/* B21C34 802416F4 27BD0030 */   addiu    $sp, $sp, 0x30
