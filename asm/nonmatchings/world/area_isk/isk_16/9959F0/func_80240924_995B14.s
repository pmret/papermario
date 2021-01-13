.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240924_995B14
/* 995B14 80240924 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 995B18 80240928 AFB10034 */  sw        $s1, 0x34($sp)
/* 995B1C 8024092C 0080882D */  daddu     $s1, $a0, $zero
/* 995B20 80240930 AFBF0054 */  sw        $ra, 0x54($sp)
/* 995B24 80240934 AFBE0050 */  sw        $fp, 0x50($sp)
/* 995B28 80240938 AFB7004C */  sw        $s7, 0x4c($sp)
/* 995B2C 8024093C AFB60048 */  sw        $s6, 0x48($sp)
/* 995B30 80240940 AFB50044 */  sw        $s5, 0x44($sp)
/* 995B34 80240944 AFB40040 */  sw        $s4, 0x40($sp)
/* 995B38 80240948 AFB3003C */  sw        $s3, 0x3c($sp)
/* 995B3C 8024094C AFB20038 */  sw        $s2, 0x38($sp)
/* 995B40 80240950 AFB00030 */  sw        $s0, 0x30($sp)
/* 995B44 80240954 8E30000C */  lw        $s0, 0xc($s1)
/* 995B48 80240958 8E050000 */  lw        $a1, ($s0)
/* 995B4C 8024095C 0C0B1EAF */  jal       get_variable
/* 995B50 80240960 26100004 */   addiu    $s0, $s0, 4
/* 995B54 80240964 8E050000 */  lw        $a1, ($s0)
/* 995B58 80240968 26100004 */  addiu     $s0, $s0, 4
/* 995B5C 8024096C 0220202D */  daddu     $a0, $s1, $zero
/* 995B60 80240970 0C0B1EAF */  jal       get_variable
/* 995B64 80240974 0040982D */   daddu    $s3, $v0, $zero
/* 995B68 80240978 8E050000 */  lw        $a1, ($s0)
/* 995B6C 8024097C 26100004 */  addiu     $s0, $s0, 4
/* 995B70 80240980 0220202D */  daddu     $a0, $s1, $zero
/* 995B74 80240984 0C0B1EAF */  jal       get_variable
/* 995B78 80240988 0040B02D */   daddu    $s6, $v0, $zero
/* 995B7C 8024098C 8E050000 */  lw        $a1, ($s0)
/* 995B80 80240990 26100004 */  addiu     $s0, $s0, 4
/* 995B84 80240994 0220202D */  daddu     $a0, $s1, $zero
/* 995B88 80240998 0C0B1EAF */  jal       get_variable
/* 995B8C 8024099C 0040A82D */   daddu    $s5, $v0, $zero
/* 995B90 802409A0 8E050000 */  lw        $a1, ($s0)
/* 995B94 802409A4 26100004 */  addiu     $s0, $s0, 4
/* 995B98 802409A8 0220202D */  daddu     $a0, $s1, $zero
/* 995B9C 802409AC 0C0B1EAF */  jal       get_variable
/* 995BA0 802409B0 0040A02D */   daddu    $s4, $v0, $zero
/* 995BA4 802409B4 8E050000 */  lw        $a1, ($s0)
/* 995BA8 802409B8 26100004 */  addiu     $s0, $s0, 4
/* 995BAC 802409BC 0220202D */  daddu     $a0, $s1, $zero
/* 995BB0 802409C0 0C0B1EAF */  jal       get_variable
/* 995BB4 802409C4 0040902D */   daddu    $s2, $v0, $zero
/* 995BB8 802409C8 8E050000 */  lw        $a1, ($s0)
/* 995BBC 802409CC 26100004 */  addiu     $s0, $s0, 4
/* 995BC0 802409D0 0220202D */  daddu     $a0, $s1, $zero
/* 995BC4 802409D4 0C0B1EAF */  jal       get_variable
/* 995BC8 802409D8 AFA20028 */   sw       $v0, 0x28($sp)
/* 995BCC 802409DC 8E050000 */  lw        $a1, ($s0)
/* 995BD0 802409E0 26100004 */  addiu     $s0, $s0, 4
/* 995BD4 802409E4 0220202D */  daddu     $a0, $s1, $zero
/* 995BD8 802409E8 0C0B1EAF */  jal       get_variable
/* 995BDC 802409EC 0040F02D */   daddu    $fp, $v0, $zero
/* 995BE0 802409F0 8E050000 */  lw        $a1, ($s0)
/* 995BE4 802409F4 26100004 */  addiu     $s0, $s0, 4
/* 995BE8 802409F8 0220202D */  daddu     $a0, $s1, $zero
/* 995BEC 802409FC 0C0B1EAF */  jal       get_variable
/* 995BF0 80240A00 0040B82D */   daddu    $s7, $v0, $zero
/* 995BF4 80240A04 0220202D */  daddu     $a0, $s1, $zero
/* 995BF8 80240A08 8E050000 */  lw        $a1, ($s0)
/* 995BFC 80240A0C 0C0B1EAF */  jal       get_variable
/* 995C00 80240A10 0040802D */   daddu    $s0, $v0, $zero
/* 995C04 80240A14 0040182D */  daddu     $v1, $v0, $zero
/* 995C08 80240A18 24020002 */  addiu     $v0, $zero, 2
/* 995C0C 80240A1C 12620012 */  beq       $s3, $v0, .L80240A68
/* 995C10 80240A20 2A620003 */   slti     $v0, $s3, 3
/* 995C14 80240A24 10400005 */  beqz      $v0, .L80240A3C
/* 995C18 80240A28 24020001 */   addiu    $v0, $zero, 1
/* 995C1C 80240A2C 12620008 */  beq       $s3, $v0, .L80240A50
/* 995C20 80240A30 32C400FF */   andi     $a0, $s6, 0xff
/* 995C24 80240A34 080902B1 */  j         .L80240AC4
/* 995C28 80240A38 00000000 */   nop
.L80240A3C:
/* 995C2C 80240A3C 24020003 */  addiu     $v0, $zero, 3
/* 995C30 80240A40 12620018 */  beq       $s3, $v0, .L80240AA4
/* 995C34 80240A44 32C400FF */   andi     $a0, $s6, 0xff
/* 995C38 80240A48 080902B1 */  j         .L80240AC4
/* 995C3C 80240A4C 00000000 */   nop
.L80240A50:
/* 995C40 80240A50 32A500FF */  andi      $a1, $s5, 0xff
/* 995C44 80240A54 328600FF */  andi      $a2, $s4, 0xff
/* 995C48 80240A58 0C046F97 */  jal       set_background_color_blend
/* 995C4C 80240A5C 324700FF */   andi     $a3, $s2, 0xff
/* 995C50 80240A60 080902B1 */  j         .L80240AC4
/* 995C54 80240A64 00000000 */   nop
.L80240A68:
/* 995C58 80240A68 32C400FF */  andi      $a0, $s6, 0xff
/* 995C5C 80240A6C 32A500FF */  andi      $a1, $s5, 0xff
/* 995C60 80240A70 328600FF */  andi      $a2, $s4, 0xff
/* 995C64 80240A74 324700FF */  andi      $a3, $s2, 0xff
/* 995C68 80240A78 93A2002B */  lbu       $v0, 0x2b($sp)
/* 995C6C 80240A7C AFB0001C */  sw        $s0, 0x1c($sp)
/* 995C70 80240A80 AFA30020 */  sw        $v1, 0x20($sp)
/* 995C74 80240A84 AFA20010 */  sw        $v0, 0x10($sp)
/* 995C78 80240A88 33C200FF */  andi      $v0, $fp, 0xff
/* 995C7C 80240A8C AFA20014 */  sw        $v0, 0x14($sp)
/* 995C80 80240A90 32E200FF */  andi      $v0, $s7, 0xff
/* 995C84 80240A94 0C046FAD */  jal       func_8011BEB4
/* 995C88 80240A98 AFA20018 */   sw       $v0, 0x18($sp)
/* 995C8C 80240A9C 080902B1 */  j         .L80240AC4
/* 995C90 80240AA0 00000000 */   nop
.L80240AA4:
/* 995C94 80240AA4 32A500FF */  andi      $a1, $s5, 0xff
/* 995C98 80240AA8 328600FF */  andi      $a2, $s4, 0xff
/* 995C9C 80240AAC 324700FF */  andi      $a3, $s2, 0xff
/* 995CA0 80240AB0 93A2002B */  lbu       $v0, 0x2b($sp)
/* 995CA4 80240AB4 AFA20010 */  sw        $v0, 0x10($sp)
/* 995CA8 80240AB8 33C200FF */  andi      $v0, $fp, 0xff
/* 995CAC 80240ABC 0C046FE6 */  jal       func_8011BF98
/* 995CB0 80240AC0 AFA20014 */   sw       $v0, 0x14($sp)
.L80240AC4:
/* 995CB4 80240AC4 8FBF0054 */  lw        $ra, 0x54($sp)
/* 995CB8 80240AC8 8FBE0050 */  lw        $fp, 0x50($sp)
/* 995CBC 80240ACC 8FB7004C */  lw        $s7, 0x4c($sp)
/* 995CC0 80240AD0 8FB60048 */  lw        $s6, 0x48($sp)
/* 995CC4 80240AD4 8FB50044 */  lw        $s5, 0x44($sp)
/* 995CC8 80240AD8 8FB40040 */  lw        $s4, 0x40($sp)
/* 995CCC 80240ADC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 995CD0 80240AE0 8FB20038 */  lw        $s2, 0x38($sp)
/* 995CD4 80240AE4 8FB10034 */  lw        $s1, 0x34($sp)
/* 995CD8 80240AE8 8FB00030 */  lw        $s0, 0x30($sp)
/* 995CDC 80240AEC 24020002 */  addiu     $v0, $zero, 2
/* 995CE0 80240AF0 03E00008 */  jr        $ra
/* 995CE4 80240AF4 27BD0058 */   addiu    $sp, $sp, 0x58
/* 995CE8 80240AF8 00000000 */  nop
/* 995CEC 80240AFC 00000000 */  nop
