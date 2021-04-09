.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hos_05_UnkFunc26
/* A2A364 80240124 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A2A368 80240128 AFB10034 */  sw        $s1, 0x34($sp)
/* A2A36C 8024012C 0080882D */  daddu     $s1, $a0, $zero
/* A2A370 80240130 AFBF0054 */  sw        $ra, 0x54($sp)
/* A2A374 80240134 AFBE0050 */  sw        $fp, 0x50($sp)
/* A2A378 80240138 AFB7004C */  sw        $s7, 0x4c($sp)
/* A2A37C 8024013C AFB60048 */  sw        $s6, 0x48($sp)
/* A2A380 80240140 AFB50044 */  sw        $s5, 0x44($sp)
/* A2A384 80240144 AFB40040 */  sw        $s4, 0x40($sp)
/* A2A388 80240148 AFB3003C */  sw        $s3, 0x3c($sp)
/* A2A38C 8024014C AFB20038 */  sw        $s2, 0x38($sp)
/* A2A390 80240150 AFB00030 */  sw        $s0, 0x30($sp)
/* A2A394 80240154 8E30000C */  lw        $s0, 0xc($s1)
/* A2A398 80240158 8E050000 */  lw        $a1, ($s0)
/* A2A39C 8024015C 0C0B1EAF */  jal       get_variable
/* A2A3A0 80240160 26100004 */   addiu    $s0, $s0, 4
/* A2A3A4 80240164 8E050000 */  lw        $a1, ($s0)
/* A2A3A8 80240168 26100004 */  addiu     $s0, $s0, 4
/* A2A3AC 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* A2A3B0 80240170 0C0B1EAF */  jal       get_variable
/* A2A3B4 80240174 0040982D */   daddu    $s3, $v0, $zero
/* A2A3B8 80240178 8E050000 */  lw        $a1, ($s0)
/* A2A3BC 8024017C 26100004 */  addiu     $s0, $s0, 4
/* A2A3C0 80240180 0220202D */  daddu     $a0, $s1, $zero
/* A2A3C4 80240184 0C0B1EAF */  jal       get_variable
/* A2A3C8 80240188 0040B02D */   daddu    $s6, $v0, $zero
/* A2A3CC 8024018C 8E050000 */  lw        $a1, ($s0)
/* A2A3D0 80240190 26100004 */  addiu     $s0, $s0, 4
/* A2A3D4 80240194 0220202D */  daddu     $a0, $s1, $zero
/* A2A3D8 80240198 0C0B1EAF */  jal       get_variable
/* A2A3DC 8024019C 0040A82D */   daddu    $s5, $v0, $zero
/* A2A3E0 802401A0 8E050000 */  lw        $a1, ($s0)
/* A2A3E4 802401A4 26100004 */  addiu     $s0, $s0, 4
/* A2A3E8 802401A8 0220202D */  daddu     $a0, $s1, $zero
/* A2A3EC 802401AC 0C0B1EAF */  jal       get_variable
/* A2A3F0 802401B0 0040A02D */   daddu    $s4, $v0, $zero
/* A2A3F4 802401B4 8E050000 */  lw        $a1, ($s0)
/* A2A3F8 802401B8 26100004 */  addiu     $s0, $s0, 4
/* A2A3FC 802401BC 0220202D */  daddu     $a0, $s1, $zero
/* A2A400 802401C0 0C0B1EAF */  jal       get_variable
/* A2A404 802401C4 0040902D */   daddu    $s2, $v0, $zero
/* A2A408 802401C8 8E050000 */  lw        $a1, ($s0)
/* A2A40C 802401CC 26100004 */  addiu     $s0, $s0, 4
/* A2A410 802401D0 0220202D */  daddu     $a0, $s1, $zero
/* A2A414 802401D4 0C0B1EAF */  jal       get_variable
/* A2A418 802401D8 AFA20028 */   sw       $v0, 0x28($sp)
/* A2A41C 802401DC 8E050000 */  lw        $a1, ($s0)
/* A2A420 802401E0 26100004 */  addiu     $s0, $s0, 4
/* A2A424 802401E4 0220202D */  daddu     $a0, $s1, $zero
/* A2A428 802401E8 0C0B1EAF */  jal       get_variable
/* A2A42C 802401EC 0040F02D */   daddu    $fp, $v0, $zero
/* A2A430 802401F0 8E050000 */  lw        $a1, ($s0)
/* A2A434 802401F4 26100004 */  addiu     $s0, $s0, 4
/* A2A438 802401F8 0220202D */  daddu     $a0, $s1, $zero
/* A2A43C 802401FC 0C0B1EAF */  jal       get_variable
/* A2A440 80240200 0040B82D */   daddu    $s7, $v0, $zero
/* A2A444 80240204 0220202D */  daddu     $a0, $s1, $zero
/* A2A448 80240208 8E050000 */  lw        $a1, ($s0)
/* A2A44C 8024020C 0C0B1EAF */  jal       get_variable
/* A2A450 80240210 0040802D */   daddu    $s0, $v0, $zero
/* A2A454 80240214 0040182D */  daddu     $v1, $v0, $zero
/* A2A458 80240218 24020002 */  addiu     $v0, $zero, 2
/* A2A45C 8024021C 12620012 */  beq       $s3, $v0, .L80240268
/* A2A460 80240220 2A620003 */   slti     $v0, $s3, 3
/* A2A464 80240224 10400005 */  beqz      $v0, .L8024023C
/* A2A468 80240228 24020001 */   addiu    $v0, $zero, 1
/* A2A46C 8024022C 12620008 */  beq       $s3, $v0, .L80240250
/* A2A470 80240230 32C400FF */   andi     $a0, $s6, 0xff
/* A2A474 80240234 080900B1 */  j         .L802402C4
/* A2A478 80240238 00000000 */   nop
.L8024023C:
/* A2A47C 8024023C 24020003 */  addiu     $v0, $zero, 3
/* A2A480 80240240 12620018 */  beq       $s3, $v0, .L802402A4
/* A2A484 80240244 32C400FF */   andi     $a0, $s6, 0xff
/* A2A488 80240248 080900B1 */  j         .L802402C4
/* A2A48C 8024024C 00000000 */   nop
.L80240250:
/* A2A490 80240250 32A500FF */  andi      $a1, $s5, 0xff
/* A2A494 80240254 328600FF */  andi      $a2, $s4, 0xff
/* A2A498 80240258 0C046F97 */  jal       set_background_color_blend
/* A2A49C 8024025C 324700FF */   andi     $a3, $s2, 0xff
/* A2A4A0 80240260 080900B1 */  j         .L802402C4
/* A2A4A4 80240264 00000000 */   nop
.L80240268:
/* A2A4A8 80240268 32C400FF */  andi      $a0, $s6, 0xff
/* A2A4AC 8024026C 32A500FF */  andi      $a1, $s5, 0xff
/* A2A4B0 80240270 328600FF */  andi      $a2, $s4, 0xff
/* A2A4B4 80240274 324700FF */  andi      $a3, $s2, 0xff
/* A2A4B8 80240278 93A2002B */  lbu       $v0, 0x2b($sp)
/* A2A4BC 8024027C AFB0001C */  sw        $s0, 0x1c($sp)
/* A2A4C0 80240280 AFA30020 */  sw        $v1, 0x20($sp)
/* A2A4C4 80240284 AFA20010 */  sw        $v0, 0x10($sp)
/* A2A4C8 80240288 33C200FF */  andi      $v0, $fp, 0xff
/* A2A4CC 8024028C AFA20014 */  sw        $v0, 0x14($sp)
/* A2A4D0 80240290 32E200FF */  andi      $v0, $s7, 0xff
/* A2A4D4 80240294 0C046FAD */  jal       func_8011BEB4
/* A2A4D8 80240298 AFA20018 */   sw       $v0, 0x18($sp)
/* A2A4DC 8024029C 080900B1 */  j         .L802402C4
/* A2A4E0 802402A0 00000000 */   nop
.L802402A4:
/* A2A4E4 802402A4 32A500FF */  andi      $a1, $s5, 0xff
/* A2A4E8 802402A8 328600FF */  andi      $a2, $s4, 0xff
/* A2A4EC 802402AC 324700FF */  andi      $a3, $s2, 0xff
/* A2A4F0 802402B0 93A2002B */  lbu       $v0, 0x2b($sp)
/* A2A4F4 802402B4 AFA20010 */  sw        $v0, 0x10($sp)
/* A2A4F8 802402B8 33C200FF */  andi      $v0, $fp, 0xff
/* A2A4FC 802402BC 0C046FE6 */  jal       func_8011BF98
/* A2A500 802402C0 AFA20014 */   sw       $v0, 0x14($sp)
.L802402C4:
/* A2A504 802402C4 8FBF0054 */  lw        $ra, 0x54($sp)
/* A2A508 802402C8 8FBE0050 */  lw        $fp, 0x50($sp)
/* A2A50C 802402CC 8FB7004C */  lw        $s7, 0x4c($sp)
/* A2A510 802402D0 8FB60048 */  lw        $s6, 0x48($sp)
/* A2A514 802402D4 8FB50044 */  lw        $s5, 0x44($sp)
/* A2A518 802402D8 8FB40040 */  lw        $s4, 0x40($sp)
/* A2A51C 802402DC 8FB3003C */  lw        $s3, 0x3c($sp)
/* A2A520 802402E0 8FB20038 */  lw        $s2, 0x38($sp)
/* A2A524 802402E4 8FB10034 */  lw        $s1, 0x34($sp)
/* A2A528 802402E8 8FB00030 */  lw        $s0, 0x30($sp)
/* A2A52C 802402EC 24020002 */  addiu     $v0, $zero, 2
/* A2A530 802402F0 03E00008 */  jr        $ra
/* A2A534 802402F4 27BD0058 */   addiu    $sp, $sp, 0x58
