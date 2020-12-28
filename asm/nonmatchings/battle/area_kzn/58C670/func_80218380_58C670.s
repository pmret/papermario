.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218380_58C670
/* 58C670 80218380 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 58C674 80218384 AFB10014 */  sw        $s1, 0x14($sp)
/* 58C678 80218388 0080882D */  daddu     $s1, $a0, $zero
/* 58C67C 8021838C AFBF0020 */  sw        $ra, 0x20($sp)
/* 58C680 80218390 AFB3001C */  sw        $s3, 0x1c($sp)
/* 58C684 80218394 AFB20018 */  sw        $s2, 0x18($sp)
/* 58C688 80218398 AFB00010 */  sw        $s0, 0x10($sp)
/* 58C68C 8021839C 8E30000C */  lw        $s0, 0xc($s1)
/* 58C690 802183A0 8E050000 */  lw        $a1, ($s0)
/* 58C694 802183A4 0C0B1EAF */  jal       get_variable
/* 58C698 802183A8 26100004 */   addiu    $s0, $s0, 4
/* 58C69C 802183AC 8E050000 */  lw        $a1, ($s0)
/* 58C6A0 802183B0 26100004 */  addiu     $s0, $s0, 4
/* 58C6A4 802183B4 0220202D */  daddu     $a0, $s1, $zero
/* 58C6A8 802183B8 0C0B1EAF */  jal       get_variable
/* 58C6AC 802183BC 0040982D */   daddu    $s3, $v0, $zero
/* 58C6B0 802183C0 8E050000 */  lw        $a1, ($s0)
/* 58C6B4 802183C4 26100004 */  addiu     $s0, $s0, 4
/* 58C6B8 802183C8 0220202D */  daddu     $a0, $s1, $zero
/* 58C6BC 802183CC 0C0B1EAF */  jal       get_variable
/* 58C6C0 802183D0 0040902D */   daddu    $s2, $v0, $zero
/* 58C6C4 802183D4 0220202D */  daddu     $a0, $s1, $zero
/* 58C6C8 802183D8 8E050000 */  lw        $a1, ($s0)
/* 58C6CC 802183DC 0C0B1EAF */  jal       get_variable
/* 58C6D0 802183E0 0040802D */   daddu    $s0, $v0, $zero
/* 58C6D4 802183E4 8E240148 */  lw        $a0, 0x148($s1)
/* 58C6D8 802183E8 0C09A75B */  jal       get_actor
/* 58C6DC 802183EC 0040882D */   daddu    $s1, $v0, $zero
/* 58C6E0 802183F0 0040182D */  daddu     $v1, $v0, $zero
/* 58C6E4 802183F4 8C620008 */  lw        $v0, 8($v1)
/* 58C6E8 802183F8 90420024 */  lbu       $v0, 0x24($v0)
/* 58C6EC 802183FC 8C640008 */  lw        $a0, 8($v1)
/* 58C6F0 80218400 02629823 */  subu      $s3, $s3, $v0
/* 58C6F4 80218404 A0730194 */  sb        $s3, 0x194($v1)
/* 58C6F8 80218408 90820025 */  lbu       $v0, 0x25($a0)
/* 58C6FC 8021840C 02429023 */  subu      $s2, $s2, $v0
/* 58C700 80218410 A0720195 */  sb        $s2, 0x195($v1)
/* 58C704 80218414 90820026 */  lbu       $v0, 0x26($a0)
/* 58C708 80218418 02028023 */  subu      $s0, $s0, $v0
/* 58C70C 8021841C A0700196 */  sb        $s0, 0x196($v1)
/* 58C710 80218420 90840027 */  lbu       $a0, 0x27($a0)
/* 58C714 80218424 02248823 */  subu      $s1, $s1, $a0
/* 58C718 80218428 A0710197 */  sb        $s1, 0x197($v1)
/* 58C71C 8021842C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 58C720 80218430 8FB3001C */  lw        $s3, 0x1c($sp)
/* 58C724 80218434 8FB20018 */  lw        $s2, 0x18($sp)
/* 58C728 80218438 8FB10014 */  lw        $s1, 0x14($sp)
/* 58C72C 8021843C 8FB00010 */  lw        $s0, 0x10($sp)
/* 58C730 80218440 24020002 */  addiu     $v0, $zero, 2
/* 58C734 80218444 03E00008 */  jr        $ra
/* 58C738 80218448 27BD0028 */   addiu    $sp, $sp, 0x28
/* 58C73C 8021844C 00000000 */  nop       
