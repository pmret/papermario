.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240164_93F714
/* 93F714 80240164 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 93F718 80240168 AFB10034 */  sw        $s1, 0x34($sp)
/* 93F71C 8024016C 0080882D */  daddu     $s1, $a0, $zero
/* 93F720 80240170 AFBF0054 */  sw        $ra, 0x54($sp)
/* 93F724 80240174 AFBE0050 */  sw        $fp, 0x50($sp)
/* 93F728 80240178 AFB7004C */  sw        $s7, 0x4c($sp)
/* 93F72C 8024017C AFB60048 */  sw        $s6, 0x48($sp)
/* 93F730 80240180 AFB50044 */  sw        $s5, 0x44($sp)
/* 93F734 80240184 AFB40040 */  sw        $s4, 0x40($sp)
/* 93F738 80240188 AFB3003C */  sw        $s3, 0x3c($sp)
/* 93F73C 8024018C AFB20038 */  sw        $s2, 0x38($sp)
/* 93F740 80240190 AFB00030 */  sw        $s0, 0x30($sp)
/* 93F744 80240194 8E30000C */  lw        $s0, 0xc($s1)
/* 93F748 80240198 8E050000 */  lw        $a1, ($s0)
/* 93F74C 8024019C 0C0B1EAF */  jal       get_variable
/* 93F750 802401A0 26100004 */   addiu    $s0, $s0, 4
/* 93F754 802401A4 8E050000 */  lw        $a1, ($s0)
/* 93F758 802401A8 26100004 */  addiu     $s0, $s0, 4
/* 93F75C 802401AC 0220202D */  daddu     $a0, $s1, $zero
/* 93F760 802401B0 0C0B1EAF */  jal       get_variable
/* 93F764 802401B4 0040982D */   daddu    $s3, $v0, $zero
/* 93F768 802401B8 8E050000 */  lw        $a1, ($s0)
/* 93F76C 802401BC 26100004 */  addiu     $s0, $s0, 4
/* 93F770 802401C0 0220202D */  daddu     $a0, $s1, $zero
/* 93F774 802401C4 0C0B1EAF */  jal       get_variable
/* 93F778 802401C8 0040B02D */   daddu    $s6, $v0, $zero
/* 93F77C 802401CC 8E050000 */  lw        $a1, ($s0)
/* 93F780 802401D0 26100004 */  addiu     $s0, $s0, 4
/* 93F784 802401D4 0220202D */  daddu     $a0, $s1, $zero
/* 93F788 802401D8 0C0B1EAF */  jal       get_variable
/* 93F78C 802401DC 0040A82D */   daddu    $s5, $v0, $zero
/* 93F790 802401E0 8E050000 */  lw        $a1, ($s0)
/* 93F794 802401E4 26100004 */  addiu     $s0, $s0, 4
/* 93F798 802401E8 0220202D */  daddu     $a0, $s1, $zero
/* 93F79C 802401EC 0C0B1EAF */  jal       get_variable
/* 93F7A0 802401F0 0040A02D */   daddu    $s4, $v0, $zero
/* 93F7A4 802401F4 8E050000 */  lw        $a1, ($s0)
/* 93F7A8 802401F8 26100004 */  addiu     $s0, $s0, 4
/* 93F7AC 802401FC 0220202D */  daddu     $a0, $s1, $zero
/* 93F7B0 80240200 0C0B1EAF */  jal       get_variable
/* 93F7B4 80240204 0040902D */   daddu    $s2, $v0, $zero
/* 93F7B8 80240208 8E050000 */  lw        $a1, ($s0)
/* 93F7BC 8024020C 26100004 */  addiu     $s0, $s0, 4
/* 93F7C0 80240210 0220202D */  daddu     $a0, $s1, $zero
/* 93F7C4 80240214 0C0B1EAF */  jal       get_variable
/* 93F7C8 80240218 AFA20028 */   sw       $v0, 0x28($sp)
/* 93F7CC 8024021C 8E050000 */  lw        $a1, ($s0)
/* 93F7D0 80240220 26100004 */  addiu     $s0, $s0, 4
/* 93F7D4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* 93F7D8 80240228 0C0B1EAF */  jal       get_variable
/* 93F7DC 8024022C 0040F02D */   daddu    $fp, $v0, $zero
/* 93F7E0 80240230 8E050000 */  lw        $a1, ($s0)
/* 93F7E4 80240234 26100004 */  addiu     $s0, $s0, 4
/* 93F7E8 80240238 0220202D */  daddu     $a0, $s1, $zero
/* 93F7EC 8024023C 0C0B1EAF */  jal       get_variable
/* 93F7F0 80240240 0040B82D */   daddu    $s7, $v0, $zero
/* 93F7F4 80240244 0220202D */  daddu     $a0, $s1, $zero
/* 93F7F8 80240248 8E050000 */  lw        $a1, ($s0)
/* 93F7FC 8024024C 0C0B1EAF */  jal       get_variable
/* 93F800 80240250 0040802D */   daddu    $s0, $v0, $zero
/* 93F804 80240254 0040182D */  daddu     $v1, $v0, $zero
/* 93F808 80240258 24020002 */  addiu     $v0, $zero, 2
/* 93F80C 8024025C 12620012 */  beq       $s3, $v0, .L802402A8
/* 93F810 80240260 2A620003 */   slti     $v0, $s3, 3
/* 93F814 80240264 10400005 */  beqz      $v0, .L8024027C
/* 93F818 80240268 24020001 */   addiu    $v0, $zero, 1
/* 93F81C 8024026C 12620008 */  beq       $s3, $v0, .L80240290
/* 93F820 80240270 32C400FF */   andi     $a0, $s6, 0xff
/* 93F824 80240274 080900C1 */  j         .L80240304
/* 93F828 80240278 00000000 */   nop
.L8024027C:
/* 93F82C 8024027C 24020003 */  addiu     $v0, $zero, 3
/* 93F830 80240280 12620018 */  beq       $s3, $v0, .L802402E4
/* 93F834 80240284 32C400FF */   andi     $a0, $s6, 0xff
/* 93F838 80240288 080900C1 */  j         .L80240304
/* 93F83C 8024028C 00000000 */   nop
.L80240290:
/* 93F840 80240290 32A500FF */  andi      $a1, $s5, 0xff
/* 93F844 80240294 328600FF */  andi      $a2, $s4, 0xff
/* 93F848 80240298 0C046F97 */  jal       set_background_color_blend
/* 93F84C 8024029C 324700FF */   andi     $a3, $s2, 0xff
/* 93F850 802402A0 080900C1 */  j         .L80240304
/* 93F854 802402A4 00000000 */   nop
.L802402A8:
/* 93F858 802402A8 32C400FF */  andi      $a0, $s6, 0xff
/* 93F85C 802402AC 32A500FF */  andi      $a1, $s5, 0xff
/* 93F860 802402B0 328600FF */  andi      $a2, $s4, 0xff
/* 93F864 802402B4 324700FF */  andi      $a3, $s2, 0xff
/* 93F868 802402B8 93A2002B */  lbu       $v0, 0x2b($sp)
/* 93F86C 802402BC AFB0001C */  sw        $s0, 0x1c($sp)
/* 93F870 802402C0 AFA30020 */  sw        $v1, 0x20($sp)
/* 93F874 802402C4 AFA20010 */  sw        $v0, 0x10($sp)
/* 93F878 802402C8 33C200FF */  andi      $v0, $fp, 0xff
/* 93F87C 802402CC AFA20014 */  sw        $v0, 0x14($sp)
/* 93F880 802402D0 32E200FF */  andi      $v0, $s7, 0xff
/* 93F884 802402D4 0C046FAD */  jal       func_8011BEB4
/* 93F888 802402D8 AFA20018 */   sw       $v0, 0x18($sp)
/* 93F88C 802402DC 080900C1 */  j         .L80240304
/* 93F890 802402E0 00000000 */   nop
.L802402E4:
/* 93F894 802402E4 32A500FF */  andi      $a1, $s5, 0xff
/* 93F898 802402E8 328600FF */  andi      $a2, $s4, 0xff
/* 93F89C 802402EC 324700FF */  andi      $a3, $s2, 0xff
/* 93F8A0 802402F0 93A2002B */  lbu       $v0, 0x2b($sp)
/* 93F8A4 802402F4 AFA20010 */  sw        $v0, 0x10($sp)
/* 93F8A8 802402F8 33C200FF */  andi      $v0, $fp, 0xff
/* 93F8AC 802402FC 0C046FE6 */  jal       func_8011BF98
/* 93F8B0 80240300 AFA20014 */   sw       $v0, 0x14($sp)
.L80240304:
/* 93F8B4 80240304 8FBF0054 */  lw        $ra, 0x54($sp)
/* 93F8B8 80240308 8FBE0050 */  lw        $fp, 0x50($sp)
/* 93F8BC 8024030C 8FB7004C */  lw        $s7, 0x4c($sp)
/* 93F8C0 80240310 8FB60048 */  lw        $s6, 0x48($sp)
/* 93F8C4 80240314 8FB50044 */  lw        $s5, 0x44($sp)
/* 93F8C8 80240318 8FB40040 */  lw        $s4, 0x40($sp)
/* 93F8CC 8024031C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 93F8D0 80240320 8FB20038 */  lw        $s2, 0x38($sp)
/* 93F8D4 80240324 8FB10034 */  lw        $s1, 0x34($sp)
/* 93F8D8 80240328 8FB00030 */  lw        $s0, 0x30($sp)
/* 93F8DC 8024032C 24020002 */  addiu     $v0, $zero, 2
/* 93F8E0 80240330 03E00008 */  jr        $ra
/* 93F8E4 80240334 27BD0058 */   addiu    $sp, $sp, 0x58
