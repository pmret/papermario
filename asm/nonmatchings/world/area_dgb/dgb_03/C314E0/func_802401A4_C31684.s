.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401A4_C31684
/* C31684 802401A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C31688 802401A8 AFB20018 */  sw        $s2, 0x18($sp)
/* C3168C 802401AC 0080902D */  daddu     $s2, $a0, $zero
/* C31690 802401B0 AFBF001C */  sw        $ra, 0x1c($sp)
/* C31694 802401B4 AFB10014 */  sw        $s1, 0x14($sp)
/* C31698 802401B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C3169C 802401BC 8E50000C */  lw        $s0, 0xc($s2)
/* C316A0 802401C0 8E050000 */  lw        $a1, ($s0)
/* C316A4 802401C4 0C0B1EAF */  jal       get_variable
/* C316A8 802401C8 26100004 */   addiu    $s0, $s0, 4
/* C316AC 802401CC 0C04417A */  jal       get_entity_by_index
/* C316B0 802401D0 0040202D */   daddu    $a0, $v0, $zero
/* C316B4 802401D4 8E050000 */  lw        $a1, ($s0)
/* C316B8 802401D8 26100004 */  addiu     $s0, $s0, 4
/* C316BC 802401DC 0040882D */  daddu     $s1, $v0, $zero
/* C316C0 802401E0 C6200048 */  lwc1      $f0, 0x48($s1)
/* C316C4 802401E4 4600008D */  trunc.w.s $f2, $f0
/* C316C8 802401E8 44061000 */  mfc1      $a2, $f2
/* C316CC 802401EC 0C0B2026 */  jal       set_variable
/* C316D0 802401F0 0240202D */   daddu    $a0, $s2, $zero
/* C316D4 802401F4 8E050000 */  lw        $a1, ($s0)
/* C316D8 802401F8 26100004 */  addiu     $s0, $s0, 4
/* C316DC 802401FC C620004C */  lwc1      $f0, 0x4c($s1)
/* C316E0 80240200 4600008D */  trunc.w.s $f2, $f0
/* C316E4 80240204 44061000 */  mfc1      $a2, $f2
/* C316E8 80240208 0C0B2026 */  jal       set_variable
/* C316EC 8024020C 0240202D */   daddu    $a0, $s2, $zero
/* C316F0 80240210 C6200050 */  lwc1      $f0, 0x50($s1)
/* C316F4 80240214 8E050000 */  lw        $a1, ($s0)
/* C316F8 80240218 4600008D */  trunc.w.s $f2, $f0
/* C316FC 8024021C 44061000 */  mfc1      $a2, $f2
/* C31700 80240220 0C0B2026 */  jal       set_variable
/* C31704 80240224 0240202D */   daddu    $a0, $s2, $zero
/* C31708 80240228 8FBF001C */  lw        $ra, 0x1c($sp)
/* C3170C 8024022C 8FB20018 */  lw        $s2, 0x18($sp)
/* C31710 80240230 8FB10014 */  lw        $s1, 0x14($sp)
/* C31714 80240234 8FB00010 */  lw        $s0, 0x10($sp)
/* C31718 80240238 24020002 */  addiu     $v0, $zero, 2
/* C3171C 8024023C 03E00008 */  jr        $ra
/* C31720 80240240 27BD0020 */   addiu    $sp, $sp, 0x20
/* C31724 80240244 00000000 */  nop       
/* C31728 80240248 00000000 */  nop       
/* C3172C 8024024C 00000000 */  nop       
