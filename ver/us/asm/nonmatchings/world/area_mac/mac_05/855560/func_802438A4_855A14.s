.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802438A4_855A14
/* 855A14 802438A4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 855A18 802438A8 24040002 */  addiu     $a0, $zero, 2
/* 855A1C 802438AC 27A50010 */  addiu     $a1, $sp, 0x10
/* 855A20 802438B0 27A60014 */  addiu     $a2, $sp, 0x14
/* 855A24 802438B4 27A70018 */  addiu     $a3, $sp, 0x18
/* 855A28 802438B8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 855A2C 802438BC AFB10024 */  sw        $s1, 0x24($sp)
/* 855A30 802438C0 0C0470AC */  jal       mdl_get_copied_vertices
/* 855A34 802438C4 AFB00020 */   sw       $s0, 0x20($sp)
/* 855A38 802438C8 3C118025 */  lui       $s1, %hi(D_80250A58_862BC8)
/* 855A3C 802438CC 26310A58 */  addiu     $s1, $s1, %lo(D_80250A58_862BC8)
/* 855A40 802438D0 8FA40010 */  lw        $a0, 0x10($sp)
/* 855A44 802438D4 8FA50014 */  lw        $a1, 0x14($sp)
/* 855A48 802438D8 8FA60018 */  lw        $a2, 0x18($sp)
/* 855A4C 802438DC 0C090D62 */  jal       func_80243588_8556F8
/* 855A50 802438E0 0220382D */   daddu    $a3, $s1, $zero
/* 855A54 802438E4 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 855A58 802438E8 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 855A5C 802438EC 8C620000 */  lw        $v0, ($v1)
/* 855A60 802438F0 24040002 */  addiu     $a0, $zero, 2
/* 855A64 802438F4 0040802D */  daddu     $s0, $v0, $zero
/* 855A68 802438F8 24420008 */  addiu     $v0, $v0, 8
/* 855A6C 802438FC AC620000 */  sw        $v0, ($v1)
/* 855A70 80243900 3C02DE00 */  lui       $v0, 0xde00
/* 855A74 80243904 0C0470BB */  jal       mdl_get_copied_gfx
/* 855A78 80243908 AE020000 */   sw       $v0, ($s0)
/* 855A7C 8024390C 8E230000 */  lw        $v1, ($s1)
/* 855A80 80243910 04600003 */  bltz      $v1, .L80243920
/* 855A84 80243914 AE020004 */   sw       $v0, 4($s0)
/* 855A88 80243918 24620004 */  addiu     $v0, $v1, 4
/* 855A8C 8024391C AE220000 */  sw        $v0, ($s1)
.L80243920:
/* 855A90 80243920 8E220000 */  lw        $v0, ($s1)
/* 855A94 80243924 28420168 */  slti      $v0, $v0, 0x168
/* 855A98 80243928 14400002 */  bnez      $v0, .L80243934
/* 855A9C 8024392C 2402FFFF */   addiu    $v0, $zero, -1
/* 855AA0 80243930 AE220000 */  sw        $v0, ($s1)
.L80243934:
/* 855AA4 80243934 8FBF0028 */  lw        $ra, 0x28($sp)
/* 855AA8 80243938 8FB10024 */  lw        $s1, 0x24($sp)
/* 855AAC 8024393C 8FB00020 */  lw        $s0, 0x20($sp)
/* 855AB0 80243940 03E00008 */  jr        $ra
/* 855AB4 80243944 27BD0030 */   addiu    $sp, $sp, 0x30
