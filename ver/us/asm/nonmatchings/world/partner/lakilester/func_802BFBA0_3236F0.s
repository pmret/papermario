.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BFBA0_3236F0
/* 3236F0 802BFBA0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3236F4 802BFBA4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3236F8 802BFBA8 0080982D */  daddu     $s3, $a0, $zero
/* 3236FC 802BFBAC AFB00010 */  sw        $s0, 0x10($sp)
/* 323700 802BFBB0 00A0802D */  daddu     $s0, $a1, $zero
/* 323704 802BFBB4 2404FFFC */  addiu     $a0, $zero, -4
/* 323708 802BFBB8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 32370C 802BFBBC AFB40020 */  sw        $s4, 0x20($sp)
/* 323710 802BFBC0 AFB20018 */  sw        $s2, 0x18($sp)
/* 323714 802BFBC4 0C00EABB */  jal       get_npc_unsafe
/* 323718 802BFBC8 AFB10014 */   sw       $s1, 0x14($sp)
/* 32371C 802BFBCC 3C148011 */  lui       $s4, %hi(gPartnerActionStatus)
/* 323720 802BFBD0 2694EBB0 */  addiu     $s4, $s4, %lo(gPartnerActionStatus)
/* 323724 802BFBD4 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 323728 802BFBD8 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 32372C 802BFBDC 12000002 */  beqz      $s0, .L802BFBE8
/* 323730 802BFBE0 0040882D */   daddu    $s1, $v0, $zero
/* 323734 802BFBE4 AE600070 */  sw        $zero, 0x70($s3)
.L802BFBE8:
/* 323738 802BFBE8 8E700070 */  lw        $s0, 0x70($s3)
/* 32373C 802BFBEC 12000005 */  beqz      $s0, .L802BFC04
/* 323740 802BFBF0 24020001 */   addiu    $v0, $zero, 1
/* 323744 802BFBF4 1202006A */  beq       $s0, $v0, .L802BFDA0
/* 323748 802BFBF8 0000102D */   daddu    $v0, $zero, $zero
/* 32374C 802BFBFC 080AFF8D */  j         .L802BFE34
/* 323750 802BFC00 00000000 */   nop
.L802BFC04:
/* 323754 802BFC04 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 323758 802BFC08 1440000F */  bnez      $v0, .L802BFC48
/* 32375C 802BFC0C 00000000 */   nop
/* 323760 802BFC10 C6400028 */  lwc1      $f0, 0x28($s2)
/* 323764 802BFC14 3C014120 */  lui       $at, 0x4120
/* 323768 802BFC18 44811000 */  mtc1      $at, $f2
/* 32376C 802BFC1C E6200038 */  swc1      $f0, 0x38($s1)
/* 323770 802BFC20 E6200060 */  swc1      $f0, 0x60($s1)
/* 323774 802BFC24 C620003C */  lwc1      $f0, 0x3c($s1)
/* 323778 802BFC28 C6440030 */  lwc1      $f4, 0x30($s2)
/* 32377C 802BFC2C 46020000 */  add.s     $f0, $f0, $f2
/* 323780 802BFC30 E6240040 */  swc1      $f4, 0x40($s1)
/* 323784 802BFC34 E6240068 */  swc1      $f4, 0x68($s1)
/* 323788 802BFC38 0C03ADF3 */  jal       partner_kill_ability_script
/* 32378C 802BFC3C E640002C */   swc1     $f0, 0x2c($s2)
/* 323790 802BFC40 080AFF25 */  j         .L802BFC94
/* 323794 802BFC44 00000000 */   nop
.L802BFC48:
/* 323798 802BFC48 0C039769 */  jal       set_action_state
/* 32379C 802BFC4C 24040021 */   addiu    $a0, $zero, 0x21
/* 3237A0 802BFC50 0C038045 */  jal       disable_player_static_collisions
/* 3237A4 802BFC54 00000000 */   nop
/* 3237A8 802BFC58 0C03805E */  jal       disable_player_input
/* 3237AC 802BFC5C 00000000 */   nop
/* 3237B0 802BFC60 C6400028 */  lwc1      $f0, 0x28($s2)
/* 3237B4 802BFC64 3C014120 */  lui       $at, 0x4120
/* 3237B8 802BFC68 44811000 */  mtc1      $at, $f2
/* 3237BC 802BFC6C E6200038 */  swc1      $f0, 0x38($s1)
/* 3237C0 802BFC70 E6200060 */  swc1      $f0, 0x60($s1)
/* 3237C4 802BFC74 C640002C */  lwc1      $f0, 0x2c($s2)
/* 3237C8 802BFC78 E620003C */  swc1      $f0, 0x3c($s1)
/* 3237CC 802BFC7C E6200064 */  swc1      $f0, 0x64($s1)
/* 3237D0 802BFC80 C6440030 */  lwc1      $f4, 0x30($s2)
/* 3237D4 802BFC84 46020000 */  add.s     $f0, $f0, $f2
/* 3237D8 802BFC88 E6240040 */  swc1      $f4, 0x40($s1)
/* 3237DC 802BFC8C E6240068 */  swc1      $f4, 0x68($s1)
/* 3237E0 802BFC90 E640002C */  swc1      $f0, 0x2c($s2)
.L802BFC94:
/* 3237E4 802BFC94 C6660088 */  lwc1      $f6, 0x88($s3)
/* 3237E8 802BFC98 468031A0 */  cvt.s.w   $f6, $f6
/* 3237EC 802BFC9C 44063000 */  mfc1      $a2, $f6
/* 3237F0 802BFCA0 C6660090 */  lwc1      $f6, 0x90($s3)
/* 3237F4 802BFCA4 468031A0 */  cvt.s.w   $f6, $f6
/* 3237F8 802BFCA8 8E620094 */  lw        $v0, 0x94($s3)
/* 3237FC 802BFCAC 44073000 */  mfc1      $a3, $f6
/* 323800 802BFCB0 AE620074 */  sw        $v0, 0x74($s3)
/* 323804 802BFCB4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 323808 802BFCB8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 32380C 802BFCBC 0C00A720 */  jal       atan2
/* 323810 802BFCC0 26700098 */   addiu    $s0, $s3, 0x98
/* 323814 802BFCC4 46000086 */  mov.s     $f2, $f0
/* 323818 802BFCC8 E622000C */  swc1      $f2, 0xc($s1)
/* 32381C 802BFCCC 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 323820 802BFCD0 10400014 */  beqz      $v0, .L802BFD24
/* 323824 802BFCD4 24040295 */   addiu    $a0, $zero, 0x295
/* 323828 802BFCD8 44800000 */  mtc1      $zero, $f0
/* 32382C 802BFCDC 00000000 */  nop
/* 323830 802BFCE0 4602003E */  c.le.s    $f0, $f2
/* 323834 802BFCE4 00000000 */  nop
/* 323838 802BFCE8 4500000F */  bc1f      .L802BFD28
/* 32383C 802BFCEC 0000282D */   daddu    $a1, $zero, $zero
/* 323840 802BFCF0 3C014334 */  lui       $at, 0x4334
/* 323844 802BFCF4 44810000 */  mtc1      $at, $f0
/* 323848 802BFCF8 00000000 */  nop
/* 32384C 802BFCFC 4600103E */  c.le.s    $f2, $f0
/* 323850 802BFD00 00000000 */  nop
/* 323854 802BFD04 45000008 */  bc1f      .L802BFD28
/* 323858 802BFD08 00000000 */   nop
/* 32385C 802BFD0C 4600118D */  trunc.w.s $f6, $f2
/* 323860 802BFD10 44023000 */  mfc1      $v0, $f6
/* 323864 802BFD14 00000000 */  nop
/* 323868 802BFD18 A622008A */  sh        $v0, 0x8a($s1)
/* 32386C 802BFD1C 24020001 */  addiu     $v0, $zero, 1
/* 323870 802BFD20 A6220088 */  sh        $v0, 0x88($s1)
.L802BFD24:
/* 323874 802BFD24 0000282D */  daddu     $a1, $zero, $zero
.L802BFD28:
/* 323878 802BFD28 0C052742 */  jal       sfx_play_sound_at_npc
/* 32387C 802BFD2C 2406FFFC */   addiu    $a2, $zero, -4
/* 323880 802BFD30 3C020008 */  lui       $v0, 8
/* 323884 802BFD34 3C014000 */  lui       $at, 0x4000
/* 323888 802BFD38 44816000 */  mtc1      $at, $f12
/* 32388C 802BFD3C 3442000E */  ori       $v0, $v0, 0xe
/* 323890 802BFD40 AE4200B8 */  sw        $v0, 0xb8($s2)
/* 323894 802BFD44 8E420000 */  lw        $v0, ($s2)
/* 323898 802BFD48 3C031000 */  lui       $v1, 0x1000
/* 32389C 802BFD4C A64000BC */  sh        $zero, 0xbc($s2)
/* 3238A0 802BFD50 00431025 */  or        $v0, $v0, $v1
/* 3238A4 802BFD54 0C0AFED1 */  jal       func_802BFB44_323694
/* 3238A8 802BFD58 AE420000 */   sw       $v0, ($s2)
/* 3238AC 802BFD5C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 3238B0 802BFD60 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 3238B4 802BFD64 24020001 */  addiu     $v0, $zero, 1
/* 3238B8 802BFD68 A062007D */  sb        $v0, 0x7d($v1)
/* 3238BC 802BFD6C 8E220000 */  lw        $v0, ($s1)
/* 3238C0 802BFD70 34420100 */  ori       $v0, $v0, 0x100
/* 3238C4 802BFD74 AE220000 */  sw        $v0, ($s1)
/* 3238C8 802BFD78 C6000000 */  lwc1      $f0, ($s0)
/* 3238CC 802BFD7C 24020001 */  addiu     $v0, $zero, 1
/* 3238D0 802BFD80 AE200014 */  sw        $zero, 0x14($s1)
/* 3238D4 802BFD84 3C01802C */  lui       $at, %hi(D_802BFF10)
/* 3238D8 802BFD88 AC20FF10 */  sw        $zero, %lo(D_802BFF10)($at)
/* 3238DC 802BFD8C 3C01802C */  lui       $at, %hi(D_802BFF18)
/* 3238E0 802BFD90 AC20FF18 */  sw        $zero, %lo(D_802BFF18)($at)
/* 3238E4 802BFD94 E6200018 */  swc1      $f0, 0x18($s1)
/* 3238E8 802BFD98 080AFF8C */  j         .L802BFE30
/* 3238EC 802BFD9C AE620070 */   sw       $v0, 0x70($s3)
.L802BFDA0:
/* 3238F0 802BFDA0 8E250018 */  lw        $a1, 0x18($s1)
/* 3238F4 802BFDA4 8E26000C */  lw        $a2, 0xc($s1)
/* 3238F8 802BFDA8 0C00EA95 */  jal       npc_move_heading
/* 3238FC 802BFDAC 0220202D */   daddu    $a0, $s1, $zero
/* 323900 802BFDB0 C6200038 */  lwc1      $f0, 0x38($s1)
/* 323904 802BFDB4 3C014120 */  lui       $at, 0x4120
/* 323908 802BFDB8 44811000 */  mtc1      $at, $f2
/* 32390C 802BFDBC E6400028 */  swc1      $f0, 0x28($s2)
/* 323910 802BFDC0 C620003C */  lwc1      $f0, 0x3c($s1)
/* 323914 802BFDC4 46020000 */  add.s     $f0, $f0, $f2
/* 323918 802BFDC8 3C014000 */  lui       $at, 0x4000
/* 32391C 802BFDCC 44816000 */  mtc1      $at, $f12
/* 323920 802BFDD0 E640002C */  swc1      $f0, 0x2c($s2)
/* 323924 802BFDD4 C6200040 */  lwc1      $f0, 0x40($s1)
/* 323928 802BFDD8 E6400030 */  swc1      $f0, 0x30($s2)
/* 32392C 802BFDDC C620000C */  lwc1      $f0, 0xc($s1)
/* 323930 802BFDE0 0C0AFED1 */  jal       func_802BFB44_323694
/* 323934 802BFDE4 E6400080 */   swc1     $f0, 0x80($s2)
/* 323938 802BFDE8 8E620074 */  lw        $v0, 0x74($s3)
/* 32393C 802BFDEC 2442FFFF */  addiu     $v0, $v0, -1
/* 323940 802BFDF0 1440000F */  bnez      $v0, .L802BFE30
/* 323944 802BFDF4 AE620074 */   sw       $v0, 0x74($s3)
/* 323948 802BFDF8 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 32394C 802BFDFC 1040000A */  beqz      $v0, .L802BFE28
/* 323950 802BFE00 24040021 */   addiu    $a0, $zero, 0x21
/* 323954 802BFE04 0C039769 */  jal       set_action_state
/* 323958 802BFE08 A2900001 */   sb       $s0, 1($s4)
/* 32395C 802BFE0C A2800003 */  sb        $zero, 3($s4)
/* 323960 802BFE10 0C03ACC5 */  jal       partner_use_ability
/* 323964 802BFE14 A2800000 */   sb       $zero, ($s4)
/* 323968 802BFE18 0C038050 */  jal       enable_player_static_collisions
/* 32396C 802BFE1C 00000000 */   nop
/* 323970 802BFE20 0C038069 */  jal       enable_player_input
/* 323974 802BFE24 00000000 */   nop
.L802BFE28:
/* 323978 802BFE28 080AFF8D */  j         .L802BFE34
/* 32397C 802BFE2C 24020002 */   addiu    $v0, $zero, 2
.L802BFE30:
/* 323980 802BFE30 0000102D */  daddu     $v0, $zero, $zero
.L802BFE34:
/* 323984 802BFE34 8FBF0024 */  lw        $ra, 0x24($sp)
/* 323988 802BFE38 8FB40020 */  lw        $s4, 0x20($sp)
/* 32398C 802BFE3C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 323990 802BFE40 8FB20018 */  lw        $s2, 0x18($sp)
/* 323994 802BFE44 8FB10014 */  lw        $s1, 0x14($sp)
/* 323998 802BFE48 8FB00010 */  lw        $s0, 0x10($sp)
/* 32399C 802BFE4C 03E00008 */  jr        $ra
/* 3239A0 802BFE50 27BD0028 */   addiu    $sp, $sp, 0x28
/* 3239A4 802BFE54 00000000 */  nop
/* 3239A8 802BFE58 00000000 */  nop
/* 3239AC 802BFE5C 00000000 */  nop
