.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EnableGroup
/* EE548 802C9B98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE54C 802C9B9C AFB20018 */  sw        $s2, 0x18($sp)
/* EE550 802C9BA0 0080902D */  daddu     $s2, $a0, $zero
/* EE554 802C9BA4 AFBF001C */  sw        $ra, 0x1c($sp)
/* EE558 802C9BA8 AFB10014 */  sw        $s1, 0x14($sp)
/* EE55C 802C9BAC AFB00010 */  sw        $s0, 0x10($sp)
/* EE560 802C9BB0 8E51000C */  lw        $s1, 0xc($s2)
/* EE564 802C9BB4 0C0B1EAF */  jal       get_variable
/* EE568 802C9BB8 8E250000 */   lw       $a1, ($s1)
/* EE56C 802C9BBC 0C046C24 */  jal       func_8011B090
/* EE570 802C9BC0 0040202D */   daddu    $a0, $v0, $zero
/* EE574 802C9BC4 0040802D */  daddu     $s0, $v0, $zero
/* EE578 802C9BC8 2402FFFF */  addiu     $v0, $zero, -1
/* EE57C 802C9BCC 16020007 */  bne       $s0, $v0, .L802C9BEC
/* EE580 802C9BD0 00000000 */   nop
/* EE584 802C9BD4 3C04802D */  lui       $a0, %hi(EnableModel)
/* EE588 802C9BD8 24849288 */  addiu     $a0, $a0, %lo(EnableModel)
/* EE58C 802C9BDC 0C0B2568 */  jal       func_802C95A0
/* EE590 802C9BE0 0240282D */   daddu    $a1, $s2, $zero
/* EE594 802C9BE4 080B2716 */  j         .L802C9C58
/* EE598 802C9BE8 24020002 */   addiu    $v0, $zero, 2
.L802C9BEC:
/* EE59C 802C9BEC 8E250004 */  lw        $a1, 4($s1)
/* EE5A0 802C9BF0 0C0B1EAF */  jal       get_variable
/* EE5A4 802C9BF4 0240202D */   daddu    $a0, $s2, $zero
/* EE5A8 802C9BF8 0200202D */  daddu     $a0, $s0, $zero
/* EE5AC 802C9BFC 0C046C70 */  jal       func_8011B1C0
/* EE5B0 802C9C00 0040902D */   daddu    $s2, $v0, $zero
/* EE5B4 802C9C04 0040882D */  daddu     $s1, $v0, $zero
/* EE5B8 802C9C08 9230009C */  lbu       $s0, 0x9c($s1)
/* EE5BC 802C9C0C 9222009D */  lbu       $v0, 0x9d($s1)
/* EE5C0 802C9C10 0050102A */  slt       $v0, $v0, $s0
/* EE5C4 802C9C14 14400010 */  bnez      $v0, .L802C9C58
/* EE5C8 802C9C18 24020002 */   addiu    $v0, $zero, 2
.L802C9C1C:
/* EE5CC 802C9C1C 0C046B4C */  jal       get_model_from_list_index
/* EE5D0 802C9C20 0200202D */   daddu    $a0, $s0, $zero
/* EE5D4 802C9C24 12400004 */  beqz      $s2, .L802C9C38
/* EE5D8 802C9C28 0040182D */   daddu    $v1, $v0, $zero
/* EE5DC 802C9C2C 94620000 */  lhu       $v0, ($v1)
/* EE5E0 802C9C30 080B2710 */  j         .L802C9C40
/* EE5E4 802C9C34 3042FFFD */   andi     $v0, $v0, 0xfffd
.L802C9C38:
/* EE5E8 802C9C38 94620000 */  lhu       $v0, ($v1)
/* EE5EC 802C9C3C 34420002 */  ori       $v0, $v0, 2
.L802C9C40:
/* EE5F0 802C9C40 A4620000 */  sh        $v0, ($v1)
/* EE5F4 802C9C44 9222009D */  lbu       $v0, 0x9d($s1)
/* EE5F8 802C9C48 26100001 */  addiu     $s0, $s0, 1
/* EE5FC 802C9C4C 0050102A */  slt       $v0, $v0, $s0
/* EE600 802C9C50 1040FFF2 */  beqz      $v0, .L802C9C1C
/* EE604 802C9C54 24020002 */   addiu    $v0, $zero, 2
.L802C9C58:
/* EE608 802C9C58 8FBF001C */  lw        $ra, 0x1c($sp)
/* EE60C 802C9C5C 8FB20018 */  lw        $s2, 0x18($sp)
/* EE610 802C9C60 8FB10014 */  lw        $s1, 0x14($sp)
/* EE614 802C9C64 8FB00010 */  lw        $s0, 0x10($sp)
/* EE618 802C9C68 03E00008 */  jr        $ra
/* EE61C 802C9C6C 27BD0020 */   addiu    $sp, $sp, 0x20
