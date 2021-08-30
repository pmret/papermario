.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A3C_8EE85C
/* 8EE85C 80242A3C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8EE860 80242A40 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8EE864 80242A44 0080982D */  daddu     $s3, $a0, $zero
/* 8EE868 80242A48 AFB10014 */  sw        $s1, 0x14($sp)
/* 8EE86C 80242A4C 0000882D */  daddu     $s1, $zero, $zero
/* 8EE870 80242A50 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EE874 80242A54 0220802D */  daddu     $s0, $s1, $zero
/* 8EE878 80242A58 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 8EE87C 80242A5C 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 8EE880 80242A60 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8EE884 80242A64 AFB20018 */  sw        $s2, 0x18($sp)
.L80242A68:
/* 8EE888 80242A68 846200B4 */  lh        $v0, 0xb4($v1)
/* 8EE88C 80242A6C 54400001 */  bnel      $v0, $zero, .L80242A74
/* 8EE890 80242A70 26310001 */   addiu    $s1, $s1, 1
.L80242A74:
/* 8EE894 80242A74 26100001 */  addiu     $s0, $s0, 1
/* 8EE898 80242A78 2A020080 */  slti      $v0, $s0, 0x80
/* 8EE89C 80242A7C 1440FFFA */  bnez      $v0, .L80242A68
/* 8EE8A0 80242A80 24630002 */   addiu    $v1, $v1, 2
/* 8EE8A4 80242A84 A6710024 */  sh        $s1, 0x24($s3)
/* 8EE8A8 80242A88 0000882D */  daddu     $s1, $zero, $zero
/* 8EE8AC 80242A8C 0220802D */  daddu     $s0, $s1, $zero
/* 8EE8B0 80242A90 3C128025 */  lui       $s2, %hi(D_80252DC0_8FEBE0)
/* 8EE8B4 80242A94 26522DC0 */  addiu     $s2, $s2, %lo(D_80252DC0_8FEBE0)
.L80242A98:
/* 8EE8B8 80242A98 8E450000 */  lw        $a1, ($s2)
/* 8EE8BC 80242A9C 10A00008 */  beqz      $a1, .L80242AC0
/* 8EE8C0 80242AA0 00111400 */   sll      $v0, $s1, 0x10
/* 8EE8C4 80242AA4 0C0B1EAF */  jal       evt_get_variable
/* 8EE8C8 80242AA8 0000202D */   daddu    $a0, $zero, $zero
/* 8EE8CC 80242AAC 54400001 */  bnel      $v0, $zero, .L80242AB4
/* 8EE8D0 80242AB0 26310001 */   addiu    $s1, $s1, 1
.L80242AB4:
/* 8EE8D4 80242AB4 26520004 */  addiu     $s2, $s2, 4
/* 8EE8D8 80242AB8 08090AA6 */  j         .L80242A98
/* 8EE8DC 80242ABC 26100001 */   addiu    $s0, $s0, 1
.L80242AC0:
/* 8EE8E0 80242AC0 A6700028 */  sh        $s0, 0x28($s3)
/* 8EE8E4 80242AC4 14400008 */  bnez      $v0, .L80242AE8
/* 8EE8E8 80242AC8 A6710026 */   sh       $s1, 0x26($s3)
/* 8EE8EC 80242ACC 0000202D */  daddu     $a0, $zero, $zero
/* 8EE8F0 80242AD0 3C05F840 */  lui       $a1, 0xf840
/* 8EE8F4 80242AD4 0C0B1EAF */  jal       evt_get_variable
/* 8EE8F8 80242AD8 34A55CC8 */   ori      $a1, $a1, 0x5cc8
/* 8EE8FC 80242ADC 10400002 */  beqz      $v0, .L80242AE8
/* 8EE900 80242AE0 2402FFFF */   addiu    $v0, $zero, -1
/* 8EE904 80242AE4 A6620026 */  sh        $v0, 0x26($s3)
.L80242AE8:
/* 8EE908 80242AE8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8EE90C 80242AEC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8EE910 80242AF0 8FB20018 */  lw        $s2, 0x18($sp)
/* 8EE914 80242AF4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8EE918 80242AF8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EE91C 80242AFC 03E00008 */  jr        $ra
/* 8EE920 80242B00 27BD0028 */   addiu    $sp, $sp, 0x28
