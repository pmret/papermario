.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80059BA4
/* 34FA4 80059BA4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 34FA8 80059BA8 AFB10014 */  sw        $s1, 0x14($sp)
/* 34FAC 80059BAC 0000882D */  daddu     $s1, $zero, $zero
/* 34FB0 80059BB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 34FB4 80059BB4 3C10800B */  lui       $s0, %hi(D_800B4378)
/* 34FB8 80059BB8 26104378 */  addiu     $s0, $s0, %lo(D_800B4378)
/* 34FBC 80059BBC AFBF0018 */  sw        $ra, 0x18($sp)
.L80059BC0:
/* 34FC0 80059BC0 8E040000 */  lw        $a0, ($s0)
/* 34FC4 80059BC4 50800017 */  beql      $a0, $zero, .L80059C24
/* 34FC8 80059BC8 26310001 */   addiu    $s1, $s1, 1
/* 34FCC 80059BCC 8C830000 */  lw        $v1, ($a0)
/* 34FD0 80059BD0 30620001 */  andi      $v0, $v1, 1
/* 34FD4 80059BD4 50400013 */  beql      $v0, $zero, .L80059C24
/* 34FD8 80059BD8 26310001 */   addiu    $s1, $s1, 1
/* 34FDC 80059BDC 30620008 */  andi      $v0, $v1, 8
/* 34FE0 80059BE0 50400010 */  beql      $v0, $zero, .L80059C24
/* 34FE4 80059BE4 26310001 */   addiu    $s1, $s1, 1
/* 34FE8 80059BE8 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 34FEC 80059BEC 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 34FF0 80059BF0 80420070 */  lb        $v0, 0x70($v0)
/* 34FF4 80059BF4 10400005 */  beqz      $v0, .L80059C0C
/* 34FF8 80059BF8 30620004 */   andi     $v0, $v1, 4
/* 34FFC 80059BFC 50400009 */  beql      $v0, $zero, .L80059C24
/* 35000 80059C00 26310001 */   addiu    $s1, $s1, 1
/* 35004 80059C04 08016705 */  j         .L80059C14
/* 35008 80059C08 00000000 */   nop
.L80059C0C:
/* 3500C 80059C0C 54400005 */  bnel      $v0, $zero, .L80059C24
/* 35010 80059C10 26310001 */   addiu    $s1, $s1, 1
.L80059C14:
/* 35014 80059C14 8C820010 */  lw        $v0, 0x10($a0)
/* 35018 80059C18 8C420014 */  lw        $v0, 0x14($v0)
/* 3501C 80059C1C 0040F809 */  jalr      $v0
/* 35020 80059C20 26310001 */   addiu    $s1, $s1, 1
.L80059C24:
/* 35024 80059C24 2A220060 */  slti      $v0, $s1, 0x60
/* 35028 80059C28 1440FFE5 */  bnez      $v0, .L80059BC0
/* 3502C 80059C2C 26100004 */   addiu    $s0, $s0, 4
/* 35030 80059C30 8FBF0018 */  lw        $ra, 0x18($sp)
/* 35034 80059C34 8FB10014 */  lw        $s1, 0x14($sp)
/* 35038 80059C38 8FB00010 */  lw        $s0, 0x10($sp)
/* 3503C 80059C3C 03E00008 */  jr        $ra
/* 35040 80059C40 27BD0020 */   addiu    $sp, $sp, 0x20
