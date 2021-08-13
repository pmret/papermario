.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9110_4256A0
/* 4256A0 802A9110 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4256A4 802A9114 AFB20018 */  sw        $s2, 0x18($sp)
/* 4256A8 802A9118 0080902D */  daddu     $s2, $a0, $zero
/* 4256AC 802A911C AFB10014 */  sw        $s1, 0x14($sp)
/* 4256B0 802A9120 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 4256B4 802A9124 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 4256B8 802A9128 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4256BC 802A912C 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 4256C0 802A9130 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 4256C4 802A9134 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4256C8 802A9138 AFB00010 */  sw        $s0, 0x10($sp)
/* 4256CC 802A913C 82620083 */  lb        $v0, 0x83($s3)
/* 4256D0 802A9140 8E50000C */  lw        $s0, 0xc($s2)
/* 4256D4 802A9144 10400023 */  beqz      $v0, .L802A91D4
/* 4256D8 802A9148 0260182D */   daddu    $v1, $s3, $zero
/* 4256DC 802A914C 0C09A216 */  jal       func_80268858
/* 4256E0 802A9150 00000000 */   nop
/* 4256E4 802A9154 8E050000 */  lw        $a1, ($s0)
/* 4256E8 802A9158 26100004 */  addiu     $s0, $s0, 4
/* 4256EC 802A915C 0C0B1EAF */  jal       get_variable
/* 4256F0 802A9160 0240202D */   daddu    $a0, $s2, $zero
/* 4256F4 802A9164 A622004E */  sh        $v0, 0x4e($s1)
/* 4256F8 802A9168 8E050000 */  lw        $a1, ($s0)
/* 4256FC 802A916C 26100004 */  addiu     $s0, $s0, 4
/* 425700 802A9170 0C0B1EAF */  jal       get_variable
/* 425704 802A9174 0240202D */   daddu    $a0, $s2, $zero
/* 425708 802A9178 A6220052 */  sh        $v0, 0x52($s1)
/* 42570C 802A917C 8E050000 */  lw        $a1, ($s0)
/* 425710 802A9180 0C0B1EAF */  jal       get_variable
/* 425714 802A9184 0240202D */   daddu    $a0, $s2, $zero
/* 425718 802A9188 00022400 */  sll       $a0, $v0, 0x10
/* 42571C 802A918C 00042403 */  sra       $a0, $a0, 0x10
/* 425720 802A9190 0C09A089 */  jal       func_80268224
/* 425724 802A9194 A6220050 */   sh       $v0, 0x50($s1)
/* 425728 802A9198 3C05FFFF */  lui       $a1, 0xffff
/* 42572C 802A919C 34A57FFF */  ori       $a1, $a1, 0x7fff
/* 425730 802A91A0 A6220050 */  sh        $v0, 0x50($s1)
/* 425734 802A91A4 24020002 */  addiu     $v0, $zero, 2
/* 425738 802A91A8 A2200060 */  sb        $zero, 0x60($s1)
/* 42573C 802A91AC A6200044 */  sh        $zero, 0x44($s1)
/* 425740 802A91B0 A6200048 */  sh        $zero, 0x48($s1)
/* 425744 802A91B4 8E630000 */  lw        $v1, ($s3)
/* 425748 802A91B8 2404000A */  addiu     $a0, $zero, 0xa
/* 42574C 802A91BC A2600081 */  sb        $zero, 0x81($s3)
/* 425750 802A91C0 A2600086 */  sb        $zero, 0x86($s3)
/* 425754 802A91C4 A624004C */  sh        $a0, 0x4c($s1)
/* 425758 802A91C8 00651824 */  and       $v1, $v1, $a1
/* 42575C 802A91CC 080AA477 */  j         .L802A91DC
/* 425760 802A91D0 AE630000 */   sw       $v1, ($s3)
.L802A91D4:
/* 425764 802A91D4 A0600081 */  sb        $zero, 0x81($v1)
/* 425768 802A91D8 24020002 */  addiu     $v0, $zero, 2
.L802A91DC:
/* 42576C 802A91DC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 425770 802A91E0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 425774 802A91E4 8FB20018 */  lw        $s2, 0x18($sp)
/* 425778 802A91E8 8FB10014 */  lw        $s1, 0x14($sp)
/* 42577C 802A91EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 425780 802A91F0 03E00008 */  jr        $ra
/* 425784 802A91F4 27BD0028 */   addiu    $sp, $sp, 0x28
