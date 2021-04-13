.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80044738
/* 1FB38 80044738 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1FB3C 8004473C AFB00010 */  sw        $s0, 0x10($sp)
/* 1FB40 80044740 0080802D */  daddu     $s0, $a0, $zero
/* 1FB44 80044744 AFB50024 */  sw        $s5, 0x24($sp)
/* 1FB48 80044748 24150002 */  addiu     $s5, $zero, 2
/* 1FB4C 8004474C AFBF0028 */  sw        $ra, 0x28($sp)
/* 1FB50 80044750 AFB40020 */  sw        $s4, 0x20($sp)
/* 1FB54 80044754 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1FB58 80044758 AFB20018 */  sw        $s2, 0x18($sp)
/* 1FB5C 8004475C AFB10014 */  sw        $s1, 0x14($sp)
/* 1FB60 80044760 8E11000C */  lw        $s1, 0xc($s0)
/* 1FB64 80044764 8E120148 */  lw        $s2, 0x148($s0)
/* 1FB68 80044768 8E250000 */  lw        $a1, ($s1)
/* 1FB6C 8004476C 0C0B1EAF */  jal       func_802C7ABC
/* 1FB70 80044770 26310004 */   addiu    $s1, $s1, 4
/* 1FB74 80044774 0040982D */  daddu     $s3, $v0, $zero
/* 1FB78 80044778 8E250000 */  lw        $a1, ($s1)
/* 1FB7C 8004477C 0C0B1EAF */  jal       func_802C7ABC
/* 1FB80 80044780 0200202D */   daddu    $a0, $s0, $zero
/* 1FB84 80044784 0040A02D */  daddu     $s4, $v0, $zero
/* 1FB88 80044788 2402FFFF */  addiu     $v0, $zero, -1
/* 1FB8C 8004478C 12420011 */  beq       $s2, $v0, .L800447D4
/* 1FB90 80044790 00000000 */   nop
/* 1FB94 80044794 12620004 */  beq       $s3, $v0, .L800447A8
/* 1FB98 80044798 00000000 */   nop
/* 1FB9C 8004479C 86420008 */  lh        $v0, 8($s2)
/* 1FBA0 800447A0 1453000C */  bne       $v0, $s3, .L800447D4
/* 1FBA4 800447A4 00000000 */   nop
.L800447A8:
/* 1FBA8 800447A8 86530008 */  lh        $s3, 8($s2)
.L800447AC:
/* 1FBAC 800447AC 8E020064 */  lw        $v0, 0x64($s0)
/* 1FBB0 800447B0 10400003 */  beqz      $v0, .L800447C0
/* 1FBB4 800447B4 00000000 */   nop
/* 1FBB8 800447B8 080111EB */  j         .L800447AC
/* 1FBBC 800447BC 0040802D */   daddu    $s0, $v0, $zero
.L800447C0:
/* 1FBC0 800447C0 8E42003C */  lw        $v0, 0x3c($s2)
/* 1FBC4 800447C4 52020006 */  beql      $s0, $v0, .L800447E0
/* 1FBC8 800447C8 241500FF */   addiu    $s5, $zero, 0xff
/* 1FBCC 800447CC 080111F8 */  j         .L800447E0
/* 1FBD0 800447D0 00000000 */   nop
.L800447D4:
/* 1FBD4 800447D4 0C00FA6A */  jal       func_8003E9A8
/* 1FBD8 800447D8 0260202D */   daddu    $a0, $s3, $zero
/* 1FBDC 800447DC 0040902D */  daddu     $s2, $v0, $zero
.L800447E0:
/* 1FBE0 800447E0 8E420000 */  lw        $v0, ($s2)
/* 1FBE4 800447E4 30420001 */  andi      $v0, $v0, 1
/* 1FBE8 800447E8 10400002 */  beqz      $v0, .L800447F4
/* 1FBEC 800447EC 2411000B */   addiu    $s1, $zero, 0xb
/* 1FBF0 800447F0 2411000A */  addiu     $s1, $zero, 0xa
.L800447F4:
/* 1FBF4 800447F4 8E42003C */  lw        $v0, 0x3c($s2)
/* 1FBF8 800447F8 10400005 */  beqz      $v0, .L80044810
/* 1FBFC 800447FC 0280202D */   daddu    $a0, $s4, $zero
/* 1FC00 80044800 8E440054 */  lw        $a0, 0x54($s2)
/* 1FC04 80044804 0C0B102B */  jal       func_802C40AC
/* 1FC08 80044808 90510004 */   lbu      $s1, 4($v0)
/* 1FC0C 8004480C 0280202D */  daddu     $a0, $s4, $zero
.L80044810:
/* 1FC10 80044810 2405000A */  addiu     $a1, $zero, 0xa
/* 1FC14 80044814 24020064 */  addiu     $v0, $zero, 0x64
/* 1FC18 80044818 0000302D */  daddu     $a2, $zero, $zero
/* 1FC1C 8004481C AE4200C8 */  sw        $v0, 0xc8($s2)
/* 1FC20 80044820 0C0B0CF8 */  jal       func_802C33E0
/* 1FC24 80044824 AE440024 */   sw       $a0, 0x24($s2)
/* 1FC28 80044828 0040802D */  daddu     $s0, $v0, $zero
/* 1FC2C 8004482C AE50003C */  sw        $s0, 0x3c($s2)
/* 1FC30 80044830 8E030144 */  lw        $v1, 0x144($s0)
/* 1FC34 80044834 02A0102D */  daddu     $v0, $s5, $zero
/* 1FC38 80044838 AE430054 */  sw        $v1, 0x54($s2)
/* 1FC3C 8004483C AE120148 */  sw        $s2, 0x148($s0)
/* 1FC40 80044840 AE13014C */  sw        $s3, 0x14c($s0)
/* 1FC44 80044844 A2110004 */  sb        $s1, 4($s0)
/* 1FC48 80044848 8FBF0028 */  lw        $ra, 0x28($sp)
/* 1FC4C 8004484C 8FB50024 */  lw        $s5, 0x24($sp)
/* 1FC50 80044850 8FB40020 */  lw        $s4, 0x20($sp)
/* 1FC54 80044854 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1FC58 80044858 8FB20018 */  lw        $s2, 0x18($sp)
/* 1FC5C 8004485C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1FC60 80044860 8FB00010 */  lw        $s0, 0x10($sp)
/* 1FC64 80044864 03E00008 */  jr        $ra
/* 1FC68 80044868 27BD0030 */   addiu    $sp, $sp, 0x30
