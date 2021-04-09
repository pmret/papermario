.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_16_UnkFunc26
/* B80124 80240124 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* B80128 80240128 AFB10034 */  sw        $s1, 0x34($sp)
/* B8012C 8024012C 0080882D */  daddu     $s1, $a0, $zero
/* B80130 80240130 AFBF0054 */  sw        $ra, 0x54($sp)
/* B80134 80240134 AFBE0050 */  sw        $fp, 0x50($sp)
/* B80138 80240138 AFB7004C */  sw        $s7, 0x4c($sp)
/* B8013C 8024013C AFB60048 */  sw        $s6, 0x48($sp)
/* B80140 80240140 AFB50044 */  sw        $s5, 0x44($sp)
/* B80144 80240144 AFB40040 */  sw        $s4, 0x40($sp)
/* B80148 80240148 AFB3003C */  sw        $s3, 0x3c($sp)
/* B8014C 8024014C AFB20038 */  sw        $s2, 0x38($sp)
/* B80150 80240150 AFB00030 */  sw        $s0, 0x30($sp)
/* B80154 80240154 8E30000C */  lw        $s0, 0xc($s1)
/* B80158 80240158 8E050000 */  lw        $a1, ($s0)
/* B8015C 8024015C 0C0B1EAF */  jal       get_variable
/* B80160 80240160 26100004 */   addiu    $s0, $s0, 4
/* B80164 80240164 8E050000 */  lw        $a1, ($s0)
/* B80168 80240168 26100004 */  addiu     $s0, $s0, 4
/* B8016C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* B80170 80240170 0C0B1EAF */  jal       get_variable
/* B80174 80240174 0040982D */   daddu    $s3, $v0, $zero
/* B80178 80240178 8E050000 */  lw        $a1, ($s0)
/* B8017C 8024017C 26100004 */  addiu     $s0, $s0, 4
/* B80180 80240180 0220202D */  daddu     $a0, $s1, $zero
/* B80184 80240184 0C0B1EAF */  jal       get_variable
/* B80188 80240188 0040B02D */   daddu    $s6, $v0, $zero
/* B8018C 8024018C 8E050000 */  lw        $a1, ($s0)
/* B80190 80240190 26100004 */  addiu     $s0, $s0, 4
/* B80194 80240194 0220202D */  daddu     $a0, $s1, $zero
/* B80198 80240198 0C0B1EAF */  jal       get_variable
/* B8019C 8024019C 0040A82D */   daddu    $s5, $v0, $zero
/* B801A0 802401A0 8E050000 */  lw        $a1, ($s0)
/* B801A4 802401A4 26100004 */  addiu     $s0, $s0, 4
/* B801A8 802401A8 0220202D */  daddu     $a0, $s1, $zero
/* B801AC 802401AC 0C0B1EAF */  jal       get_variable
/* B801B0 802401B0 0040A02D */   daddu    $s4, $v0, $zero
/* B801B4 802401B4 8E050000 */  lw        $a1, ($s0)
/* B801B8 802401B8 26100004 */  addiu     $s0, $s0, 4
/* B801BC 802401BC 0220202D */  daddu     $a0, $s1, $zero
/* B801C0 802401C0 0C0B1EAF */  jal       get_variable
/* B801C4 802401C4 0040902D */   daddu    $s2, $v0, $zero
/* B801C8 802401C8 8E050000 */  lw        $a1, ($s0)
/* B801CC 802401CC 26100004 */  addiu     $s0, $s0, 4
/* B801D0 802401D0 0220202D */  daddu     $a0, $s1, $zero
/* B801D4 802401D4 0C0B1EAF */  jal       get_variable
/* B801D8 802401D8 AFA20028 */   sw       $v0, 0x28($sp)
/* B801DC 802401DC 8E050000 */  lw        $a1, ($s0)
/* B801E0 802401E0 26100004 */  addiu     $s0, $s0, 4
/* B801E4 802401E4 0220202D */  daddu     $a0, $s1, $zero
/* B801E8 802401E8 0C0B1EAF */  jal       get_variable
/* B801EC 802401EC 0040F02D */   daddu    $fp, $v0, $zero
/* B801F0 802401F0 8E050000 */  lw        $a1, ($s0)
/* B801F4 802401F4 26100004 */  addiu     $s0, $s0, 4
/* B801F8 802401F8 0220202D */  daddu     $a0, $s1, $zero
/* B801FC 802401FC 0C0B1EAF */  jal       get_variable
/* B80200 80240200 0040B82D */   daddu    $s7, $v0, $zero
/* B80204 80240204 0220202D */  daddu     $a0, $s1, $zero
/* B80208 80240208 8E050000 */  lw        $a1, ($s0)
/* B8020C 8024020C 0C0B1EAF */  jal       get_variable
/* B80210 80240210 0040802D */   daddu    $s0, $v0, $zero
/* B80214 80240214 0040182D */  daddu     $v1, $v0, $zero
/* B80218 80240218 24020002 */  addiu     $v0, $zero, 2
/* B8021C 8024021C 12620012 */  beq       $s3, $v0, .L80240268
/* B80220 80240220 2A620003 */   slti     $v0, $s3, 3
/* B80224 80240224 10400005 */  beqz      $v0, .L8024023C
/* B80228 80240228 24020001 */   addiu    $v0, $zero, 1
/* B8022C 8024022C 12620008 */  beq       $s3, $v0, .L80240250
/* B80230 80240230 32C400FF */   andi     $a0, $s6, 0xff
/* B80234 80240234 080900B1 */  j         .L802402C4
/* B80238 80240238 00000000 */   nop
.L8024023C:
/* B8023C 8024023C 24020003 */  addiu     $v0, $zero, 3
/* B80240 80240240 12620018 */  beq       $s3, $v0, .L802402A4
/* B80244 80240244 32C400FF */   andi     $a0, $s6, 0xff
/* B80248 80240248 080900B1 */  j         .L802402C4
/* B8024C 8024024C 00000000 */   nop
.L80240250:
/* B80250 80240250 32A500FF */  andi      $a1, $s5, 0xff
/* B80254 80240254 328600FF */  andi      $a2, $s4, 0xff
/* B80258 80240258 0C046F97 */  jal       set_background_color_blend
/* B8025C 8024025C 324700FF */   andi     $a3, $s2, 0xff
/* B80260 80240260 080900B1 */  j         .L802402C4
/* B80264 80240264 00000000 */   nop
.L80240268:
/* B80268 80240268 32C400FF */  andi      $a0, $s6, 0xff
/* B8026C 8024026C 32A500FF */  andi      $a1, $s5, 0xff
/* B80270 80240270 328600FF */  andi      $a2, $s4, 0xff
/* B80274 80240274 324700FF */  andi      $a3, $s2, 0xff
/* B80278 80240278 93A2002B */  lbu       $v0, 0x2b($sp)
/* B8027C 8024027C AFB0001C */  sw        $s0, 0x1c($sp)
/* B80280 80240280 AFA30020 */  sw        $v1, 0x20($sp)
/* B80284 80240284 AFA20010 */  sw        $v0, 0x10($sp)
/* B80288 80240288 33C200FF */  andi      $v0, $fp, 0xff
/* B8028C 8024028C AFA20014 */  sw        $v0, 0x14($sp)
/* B80290 80240290 32E200FF */  andi      $v0, $s7, 0xff
/* B80294 80240294 0C046FAD */  jal       func_8011BEB4
/* B80298 80240298 AFA20018 */   sw       $v0, 0x18($sp)
/* B8029C 8024029C 080900B1 */  j         .L802402C4
/* B802A0 802402A0 00000000 */   nop
.L802402A4:
/* B802A4 802402A4 32A500FF */  andi      $a1, $s5, 0xff
/* B802A8 802402A8 328600FF */  andi      $a2, $s4, 0xff
/* B802AC 802402AC 324700FF */  andi      $a3, $s2, 0xff
/* B802B0 802402B0 93A2002B */  lbu       $v0, 0x2b($sp)
/* B802B4 802402B4 AFA20010 */  sw        $v0, 0x10($sp)
/* B802B8 802402B8 33C200FF */  andi      $v0, $fp, 0xff
/* B802BC 802402BC 0C046FE6 */  jal       func_8011BF98
/* B802C0 802402C0 AFA20014 */   sw       $v0, 0x14($sp)
.L802402C4:
/* B802C4 802402C4 8FBF0054 */  lw        $ra, 0x54($sp)
/* B802C8 802402C8 8FBE0050 */  lw        $fp, 0x50($sp)
/* B802CC 802402CC 8FB7004C */  lw        $s7, 0x4c($sp)
/* B802D0 802402D0 8FB60048 */  lw        $s6, 0x48($sp)
/* B802D4 802402D4 8FB50044 */  lw        $s5, 0x44($sp)
/* B802D8 802402D8 8FB40040 */  lw        $s4, 0x40($sp)
/* B802DC 802402DC 8FB3003C */  lw        $s3, 0x3c($sp)
/* B802E0 802402E0 8FB20038 */  lw        $s2, 0x38($sp)
/* B802E4 802402E4 8FB10034 */  lw        $s1, 0x34($sp)
/* B802E8 802402E8 8FB00030 */  lw        $s0, 0x30($sp)
/* B802EC 802402EC 24020002 */  addiu     $v0, $zero, 2
/* B802F0 802402F0 03E00008 */  jr        $ra
/* B802F4 802402F4 27BD0058 */   addiu    $sp, $sp, 0x58
/* B802F8 802402F8 00000000 */  nop
/* B802FC 802402FC 00000000 */  nop
