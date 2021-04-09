.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sbk_02_UnkFunc26
/* 92A414 80240164 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 92A418 80240168 AFB10034 */  sw        $s1, 0x34($sp)
/* 92A41C 8024016C 0080882D */  daddu     $s1, $a0, $zero
/* 92A420 80240170 AFBF0054 */  sw        $ra, 0x54($sp)
/* 92A424 80240174 AFBE0050 */  sw        $fp, 0x50($sp)
/* 92A428 80240178 AFB7004C */  sw        $s7, 0x4c($sp)
/* 92A42C 8024017C AFB60048 */  sw        $s6, 0x48($sp)
/* 92A430 80240180 AFB50044 */  sw        $s5, 0x44($sp)
/* 92A434 80240184 AFB40040 */  sw        $s4, 0x40($sp)
/* 92A438 80240188 AFB3003C */  sw        $s3, 0x3c($sp)
/* 92A43C 8024018C AFB20038 */  sw        $s2, 0x38($sp)
/* 92A440 80240190 AFB00030 */  sw        $s0, 0x30($sp)
/* 92A444 80240194 8E30000C */  lw        $s0, 0xc($s1)
/* 92A448 80240198 8E050000 */  lw        $a1, ($s0)
/* 92A44C 8024019C 0C0B1EAF */  jal       get_variable
/* 92A450 802401A0 26100004 */   addiu    $s0, $s0, 4
/* 92A454 802401A4 8E050000 */  lw        $a1, ($s0)
/* 92A458 802401A8 26100004 */  addiu     $s0, $s0, 4
/* 92A45C 802401AC 0220202D */  daddu     $a0, $s1, $zero
/* 92A460 802401B0 0C0B1EAF */  jal       get_variable
/* 92A464 802401B4 0040982D */   daddu    $s3, $v0, $zero
/* 92A468 802401B8 8E050000 */  lw        $a1, ($s0)
/* 92A46C 802401BC 26100004 */  addiu     $s0, $s0, 4
/* 92A470 802401C0 0220202D */  daddu     $a0, $s1, $zero
/* 92A474 802401C4 0C0B1EAF */  jal       get_variable
/* 92A478 802401C8 0040B02D */   daddu    $s6, $v0, $zero
/* 92A47C 802401CC 8E050000 */  lw        $a1, ($s0)
/* 92A480 802401D0 26100004 */  addiu     $s0, $s0, 4
/* 92A484 802401D4 0220202D */  daddu     $a0, $s1, $zero
/* 92A488 802401D8 0C0B1EAF */  jal       get_variable
/* 92A48C 802401DC 0040A82D */   daddu    $s5, $v0, $zero
/* 92A490 802401E0 8E050000 */  lw        $a1, ($s0)
/* 92A494 802401E4 26100004 */  addiu     $s0, $s0, 4
/* 92A498 802401E8 0220202D */  daddu     $a0, $s1, $zero
/* 92A49C 802401EC 0C0B1EAF */  jal       get_variable
/* 92A4A0 802401F0 0040A02D */   daddu    $s4, $v0, $zero
/* 92A4A4 802401F4 8E050000 */  lw        $a1, ($s0)
/* 92A4A8 802401F8 26100004 */  addiu     $s0, $s0, 4
/* 92A4AC 802401FC 0220202D */  daddu     $a0, $s1, $zero
/* 92A4B0 80240200 0C0B1EAF */  jal       get_variable
/* 92A4B4 80240204 0040902D */   daddu    $s2, $v0, $zero
/* 92A4B8 80240208 8E050000 */  lw        $a1, ($s0)
/* 92A4BC 8024020C 26100004 */  addiu     $s0, $s0, 4
/* 92A4C0 80240210 0220202D */  daddu     $a0, $s1, $zero
/* 92A4C4 80240214 0C0B1EAF */  jal       get_variable
/* 92A4C8 80240218 AFA20028 */   sw       $v0, 0x28($sp)
/* 92A4CC 8024021C 8E050000 */  lw        $a1, ($s0)
/* 92A4D0 80240220 26100004 */  addiu     $s0, $s0, 4
/* 92A4D4 80240224 0220202D */  daddu     $a0, $s1, $zero
/* 92A4D8 80240228 0C0B1EAF */  jal       get_variable
/* 92A4DC 8024022C 0040F02D */   daddu    $fp, $v0, $zero
/* 92A4E0 80240230 8E050000 */  lw        $a1, ($s0)
/* 92A4E4 80240234 26100004 */  addiu     $s0, $s0, 4
/* 92A4E8 80240238 0220202D */  daddu     $a0, $s1, $zero
/* 92A4EC 8024023C 0C0B1EAF */  jal       get_variable
/* 92A4F0 80240240 0040B82D */   daddu    $s7, $v0, $zero
/* 92A4F4 80240244 0220202D */  daddu     $a0, $s1, $zero
/* 92A4F8 80240248 8E050000 */  lw        $a1, ($s0)
/* 92A4FC 8024024C 0C0B1EAF */  jal       get_variable
/* 92A500 80240250 0040802D */   daddu    $s0, $v0, $zero
/* 92A504 80240254 0040182D */  daddu     $v1, $v0, $zero
/* 92A508 80240258 24020002 */  addiu     $v0, $zero, 2
/* 92A50C 8024025C 12620012 */  beq       $s3, $v0, .L802402A8
/* 92A510 80240260 2A620003 */   slti     $v0, $s3, 3
/* 92A514 80240264 10400005 */  beqz      $v0, .L8024027C
/* 92A518 80240268 24020001 */   addiu    $v0, $zero, 1
/* 92A51C 8024026C 12620008 */  beq       $s3, $v0, .L80240290
/* 92A520 80240270 32C400FF */   andi     $a0, $s6, 0xff
/* 92A524 80240274 080900C1 */  j         .L80240304
/* 92A528 80240278 00000000 */   nop
.L8024027C:
/* 92A52C 8024027C 24020003 */  addiu     $v0, $zero, 3
/* 92A530 80240280 12620018 */  beq       $s3, $v0, .L802402E4
/* 92A534 80240284 32C400FF */   andi     $a0, $s6, 0xff
/* 92A538 80240288 080900C1 */  j         .L80240304
/* 92A53C 8024028C 00000000 */   nop
.L80240290:
/* 92A540 80240290 32A500FF */  andi      $a1, $s5, 0xff
/* 92A544 80240294 328600FF */  andi      $a2, $s4, 0xff
/* 92A548 80240298 0C046F97 */  jal       set_background_color_blend
/* 92A54C 8024029C 324700FF */   andi     $a3, $s2, 0xff
/* 92A550 802402A0 080900C1 */  j         .L80240304
/* 92A554 802402A4 00000000 */   nop
.L802402A8:
/* 92A558 802402A8 32C400FF */  andi      $a0, $s6, 0xff
/* 92A55C 802402AC 32A500FF */  andi      $a1, $s5, 0xff
/* 92A560 802402B0 328600FF */  andi      $a2, $s4, 0xff
/* 92A564 802402B4 324700FF */  andi      $a3, $s2, 0xff
/* 92A568 802402B8 93A2002B */  lbu       $v0, 0x2b($sp)
/* 92A56C 802402BC AFB0001C */  sw        $s0, 0x1c($sp)
/* 92A570 802402C0 AFA30020 */  sw        $v1, 0x20($sp)
/* 92A574 802402C4 AFA20010 */  sw        $v0, 0x10($sp)
/* 92A578 802402C8 33C200FF */  andi      $v0, $fp, 0xff
/* 92A57C 802402CC AFA20014 */  sw        $v0, 0x14($sp)
/* 92A580 802402D0 32E200FF */  andi      $v0, $s7, 0xff
/* 92A584 802402D4 0C046FAD */  jal       func_8011BEB4
/* 92A588 802402D8 AFA20018 */   sw       $v0, 0x18($sp)
/* 92A58C 802402DC 080900C1 */  j         .L80240304
/* 92A590 802402E0 00000000 */   nop
.L802402E4:
/* 92A594 802402E4 32A500FF */  andi      $a1, $s5, 0xff
/* 92A598 802402E8 328600FF */  andi      $a2, $s4, 0xff
/* 92A59C 802402EC 324700FF */  andi      $a3, $s2, 0xff
/* 92A5A0 802402F0 93A2002B */  lbu       $v0, 0x2b($sp)
/* 92A5A4 802402F4 AFA20010 */  sw        $v0, 0x10($sp)
/* 92A5A8 802402F8 33C200FF */  andi      $v0, $fp, 0xff
/* 92A5AC 802402FC 0C046FE6 */  jal       func_8011BF98
/* 92A5B0 80240300 AFA20014 */   sw       $v0, 0x14($sp)
.L80240304:
/* 92A5B4 80240304 8FBF0054 */  lw        $ra, 0x54($sp)
/* 92A5B8 80240308 8FBE0050 */  lw        $fp, 0x50($sp)
/* 92A5BC 8024030C 8FB7004C */  lw        $s7, 0x4c($sp)
/* 92A5C0 80240310 8FB60048 */  lw        $s6, 0x48($sp)
/* 92A5C4 80240314 8FB50044 */  lw        $s5, 0x44($sp)
/* 92A5C8 80240318 8FB40040 */  lw        $s4, 0x40($sp)
/* 92A5CC 8024031C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 92A5D0 80240320 8FB20038 */  lw        $s2, 0x38($sp)
/* 92A5D4 80240324 8FB10034 */  lw        $s1, 0x34($sp)
/* 92A5D8 80240328 8FB00030 */  lw        $s0, 0x30($sp)
/* 92A5DC 8024032C 24020002 */  addiu     $v0, $zero, 2
/* 92A5E0 80240330 03E00008 */  jr        $ra
/* 92A5E4 80240334 27BD0058 */   addiu    $sp, $sp, 0x58
