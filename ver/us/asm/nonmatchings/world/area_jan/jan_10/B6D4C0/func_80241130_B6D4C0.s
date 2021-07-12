.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241130_B6D4C0
/* B6D4C0 80241130 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B6D4C4 80241134 AFB10034 */  sw        $s1, 0x34($sp)
/* B6D4C8 80241138 0080882D */  daddu     $s1, $a0, $zero
/* B6D4CC 8024113C AFBF0038 */  sw        $ra, 0x38($sp)
/* B6D4D0 80241140 AFB00030 */  sw        $s0, 0x30($sp)
/* B6D4D4 80241144 10A00016 */  beqz      $a1, .L802411A0
/* B6D4D8 80241148 8E30000C */   lw       $s0, 0xc($s1)
/* B6D4DC 8024114C 8E050000 */  lw        $a1, ($s0)
/* B6D4E0 80241150 0C0B1EAF */  jal       get_variable
/* B6D4E4 80241154 26100004 */   addiu    $s0, $s0, 4
/* B6D4E8 80241158 8E030000 */  lw        $v1, ($s0)
/* B6D4EC 8024115C 0040202D */  daddu     $a0, $v0, $zero
/* B6D4F0 80241160 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B6D4F4 80241164 AE23007C */   sw       $v1, 0x7c($s1)
/* B6D4F8 80241168 0C046B4C */  jal       get_model_from_list_index
/* B6D4FC 8024116C 0040202D */   daddu    $a0, $v0, $zero
/* B6D500 80241170 0040802D */  daddu     $s0, $v0, $zero
/* B6D504 80241174 0000202D */  daddu     $a0, $zero, $zero
/* B6D508 80241178 AE300074 */  sw        $s0, 0x74($s1)
/* B6D50C 8024117C 8E050098 */  lw        $a1, 0x98($s0)
/* B6D510 80241180 8E0700A0 */  lw        $a3, 0xa0($s0)
/* B6D514 80241184 0C044898 */  jal       create_shadow_type
/* B6D518 80241188 0000302D */   daddu    $a2, $zero, $zero
/* B6D51C 8024118C 0220202D */  daddu     $a0, $s1, $zero
/* B6D520 80241190 8E25007C */  lw        $a1, 0x7c($s1)
/* B6D524 80241194 0000302D */  daddu     $a2, $zero, $zero
/* B6D528 80241198 0C0B2026 */  jal       set_variable
/* B6D52C 8024119C AE220078 */   sw       $v0, 0x78($s1)
.L802411A0:
/* B6D530 802411A0 8E25007C */  lw        $a1, 0x7c($s1)
/* B6D534 802411A4 0C0B1EAF */  jal       get_variable
/* B6D538 802411A8 0220202D */   daddu    $a0, $s1, $zero
/* B6D53C 802411AC 1440002A */  bnez      $v0, .L80241258
/* B6D540 802411B0 00000000 */   nop
/* B6D544 802411B4 8E240078 */  lw        $a0, 0x78($s1)
/* B6D548 802411B8 0C044181 */  jal       get_shadow_by_index
/* B6D54C 802411BC 8E300074 */   lw       $s0, 0x74($s1)
/* B6D550 802411C0 27A40018 */  addiu     $a0, $sp, 0x18
/* B6D554 802411C4 27A5001C */  addiu     $a1, $sp, 0x1c
/* B6D558 802411C8 27A60020 */  addiu     $a2, $sp, 0x20
/* B6D55C 802411CC 27A70024 */  addiu     $a3, $sp, 0x24
/* B6D560 802411D0 27A30028 */  addiu     $v1, $sp, 0x28
/* B6D564 802411D4 C6000098 */  lwc1      $f0, 0x98($s0)
/* B6D568 802411D8 C602009C */  lwc1      $f2, 0x9c($s0)
/* B6D56C 802411DC C60400A0 */  lwc1      $f4, 0xa0($s0)
/* B6D570 802411E0 0040802D */  daddu     $s0, $v0, $zero
/* B6D574 802411E4 E7A00018 */  swc1      $f0, 0x18($sp)
/* B6D578 802411E8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* B6D57C 802411EC E7A40020 */  swc1      $f4, 0x20($sp)
/* B6D580 802411F0 AFA30010 */  sw        $v1, 0x10($sp)
/* B6D584 802411F4 27A3002C */  addiu     $v1, $sp, 0x2c
/* B6D588 802411F8 0C04497A */  jal       entity_raycast_down
/* B6D58C 802411FC AFA30014 */   sw       $v1, 0x14($sp)
/* B6D590 80241200 8FA5002C */  lw        $a1, 0x2c($sp)
/* B6D594 80241204 0C044A17 */  jal       set_standard_shadow_scale
/* B6D598 80241208 0200202D */   daddu    $a0, $s0, $zero
/* B6D59C 8024120C C7A00018 */  lwc1      $f0, 0x18($sp)
/* B6D5A0 80241210 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* B6D5A4 80241214 C7A60020 */  lwc1      $f6, 0x20($sp)
/* B6D5A8 80241218 C7A80024 */  lwc1      $f8, 0x24($sp)
/* B6D5AC 8024121C C604001C */  lwc1      $f4, 0x1c($s0)
/* B6D5B0 80241220 0000102D */  daddu     $v0, $zero, $zero
/* B6D5B4 80241224 AE00002C */  sw        $zero, 0x2c($s0)
/* B6D5B8 80241228 E6000010 */  swc1      $f0, 0x10($s0)
/* B6D5BC 8024122C C6000024 */  lwc1      $f0, 0x24($s0)
/* B6D5C0 80241230 46042100 */  add.s     $f4, $f4, $f4
/* B6D5C4 80241234 E6020014 */  swc1      $f2, 0x14($s0)
/* B6D5C8 80241238 E6060018 */  swc1      $f6, 0x18($s0)
/* B6D5CC 8024123C E6080028 */  swc1      $f8, 0x28($s0)
/* B6D5D0 80241240 C7A20028 */  lwc1      $f2, 0x28($sp)
/* B6D5D4 80241244 46000000 */  add.s     $f0, $f0, $f0
/* B6D5D8 80241248 E6020030 */  swc1      $f2, 0x30($s0)
/* B6D5DC 8024124C E604001C */  swc1      $f4, 0x1c($s0)
/* B6D5E0 80241250 0809049A */  j         .L80241268
/* B6D5E4 80241254 E6000024 */   swc1     $f0, 0x24($s0)
.L80241258:
/* B6D5E8 80241258 8E240078 */  lw        $a0, 0x78($s1)
/* B6D5EC 8024125C 0C0448CA */  jal       delete_shadow
/* B6D5F0 80241260 00000000 */   nop
/* B6D5F4 80241264 24020002 */  addiu     $v0, $zero, 2
.L80241268:
/* B6D5F8 80241268 8FBF0038 */  lw        $ra, 0x38($sp)
/* B6D5FC 8024126C 8FB10034 */  lw        $s1, 0x34($sp)
/* B6D600 80241270 8FB00030 */  lw        $s0, 0x30($sp)
/* B6D604 80241274 03E00008 */  jr        $ra
/* B6D608 80241278 27BD0040 */   addiu    $sp, $sp, 0x40
/* B6D60C 8024127C 00000000 */  nop
