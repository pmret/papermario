.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BFAB8_320828
/* 320828 802BFAB8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 32082C 802BFABC AFB30024 */  sw        $s3, 0x24($sp)
/* 320830 802BFAC0 0080982D */  daddu     $s3, $a0, $zero
/* 320834 802BFAC4 AFB00018 */  sw        $s0, 0x18($sp)
/* 320838 802BFAC8 00A0802D */  daddu     $s0, $a1, $zero
/* 32083C 802BFACC AFBF0028 */  sw        $ra, 0x28($sp)
/* 320840 802BFAD0 AFB20020 */  sw        $s2, 0x20($sp)
/* 320844 802BFAD4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 320848 802BFAD8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 32084C 802BFADC 0C00EABB */  jal       get_npc_unsafe
/* 320850 802BFAE0 2404FFFC */   addiu    $a0, $zero, -4
/* 320854 802BFAE4 0040882D */  daddu     $s1, $v0, $zero
/* 320858 802BFAE8 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 32085C 802BFAEC 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 320860 802BFAF0 12000005 */  beqz      $s0, .L802BFB08
/* 320864 802BFAF4 0040902D */   daddu    $s2, $v0, $zero
/* 320868 802BFAF8 AE600070 */  sw        $zero, 0x70($s3)
/* 32086C 802BFAFC C440002C */  lwc1      $f0, 0x2c($v0)
/* 320870 802BFB00 3C01802C */  lui       $at, %hi(D_802BFEE0)
/* 320874 802BFB04 E420FEE0 */  swc1      $f0, %lo(D_802BFEE0)($at)
.L802BFB08:
/* 320878 802BFB08 8E700070 */  lw        $s0, 0x70($s3)
/* 32087C 802BFB0C 12000005 */  beqz      $s0, .L802BFB24
/* 320880 802BFB10 24020001 */   addiu    $v0, $zero, 1
/* 320884 802BFB14 1202006D */  beq       $s0, $v0, .L802BFCCC
/* 320888 802BFB18 0000102D */   daddu    $v0, $zero, $zero
/* 32088C 802BFB1C 080AFF61 */  j         .L802BFD84
/* 320890 802BFB20 00000000 */   nop
.L802BFB24:
/* 320894 802BFB24 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 320898 802BFB28 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 32089C 802BFB2C 24020001 */  addiu     $v0, $zero, 1
/* 3208A0 802BFB30 0C038045 */  jal       disable_player_static_collisions
/* 3208A4 802BFB34 A062007D */   sb       $v0, 0x7d($v1)
/* 3208A8 802BFB38 0C03805E */  jal       disable_player_input
/* 3208AC 802BFB3C 00000000 */   nop
/* 3208B0 802BFB40 C6400028 */  lwc1      $f0, 0x28($s2)
/* 3208B4 802BFB44 C622000C */  lwc1      $f2, 0xc($s1)
/* 3208B8 802BFB48 E6200038 */  swc1      $f0, 0x38($s1)
/* 3208BC 802BFB4C C6400030 */  lwc1      $f0, 0x30($s2)
/* 3208C0 802BFB50 E6200040 */  swc1      $f0, 0x40($s1)
/* 3208C4 802BFB54 C640002C */  lwc1      $f0, 0x2c($s2)
/* 3208C8 802BFB58 E620003C */  swc1      $f0, 0x3c($s1)
/* 3208CC 802BFB5C E7A20010 */  swc1      $f2, 0x10($sp)
/* 3208D0 802BFB60 862200A6 */  lh        $v0, 0xa6($s1)
/* 3208D4 802BFB64 3C013F00 */  lui       $at, 0x3f00
/* 3208D8 802BFB68 4481A000 */  mtc1      $at, $f20
/* 3208DC 802BFB6C 44820000 */  mtc1      $v0, $f0
/* 3208E0 802BFB70 00000000 */  nop
/* 3208E4 802BFB74 46800020 */  cvt.s.w   $f0, $f0
/* 3208E8 802BFB78 46140002 */  mul.s     $f0, $f0, $f20
/* 3208EC 802BFB7C 00000000 */  nop
/* 3208F0 802BFB80 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3208F4 802BFB84 8E240080 */  lw        $a0, 0x80($s1)
/* 3208F8 802BFB88 8E250038 */  lw        $a1, 0x38($s1)
/* 3208FC 802BFB8C 8E26003C */  lw        $a2, 0x3c($s1)
/* 320900 802BFB90 0C0AF4DA */  jal       func_802BD368_31E0D8
/* 320904 802BFB94 8E270040 */   lw       $a3, 0x40($s1)
/* 320908 802BFB98 862200A8 */  lh        $v0, 0xa8($s1)
/* 32090C 802BFB9C 44821000 */  mtc1      $v0, $f2
/* 320910 802BFBA0 00000000 */  nop
/* 320914 802BFBA4 468010A0 */  cvt.s.w   $f2, $f2
/* 320918 802BFBA8 46141082 */  mul.s     $f2, $f2, $f20
/* 32091C 802BFBAC 00000000 */  nop
/* 320920 802BFBB0 3C01802C */  lui       $at, %hi(D_802BFEE0)
/* 320924 802BFBB4 C420FEE0 */  lwc1      $f0, %lo(D_802BFEE0)($at)
/* 320928 802BFBB8 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 32092C 802BFBBC 46020001 */  sub.s     $f0, $f0, $f2
/* 320930 802BFBC0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 320934 802BFBC4 E620003C */  swc1      $f0, 0x3c($s1)
/* 320938 802BFBC8 C66A0088 */  lwc1      $f10, 0x88($s3)
/* 32093C 802BFBCC 468052A0 */  cvt.s.w   $f10, $f10
/* 320940 802BFBD0 44065000 */  mfc1      $a2, $f10
/* 320944 802BFBD4 C66A0090 */  lwc1      $f10, 0x90($s3)
/* 320948 802BFBD8 468052A0 */  cvt.s.w   $f10, $f10
/* 32094C 802BFBDC 44075000 */  mfc1      $a3, $f10
/* 320950 802BFBE0 0C00A720 */  jal       atan2
/* 320954 802BFBE4 00000000 */   nop
/* 320958 802BFBE8 3C020007 */  lui       $v0, 7
/* 32095C 802BFBEC 3442000A */  ori       $v0, $v0, 0xa
/* 320960 802BFBF0 3C014040 */  lui       $at, 0x4040
/* 320964 802BFBF4 44811000 */  mtc1      $at, $f2
/* 320968 802BFBF8 C6240038 */  lwc1      $f4, 0x38($s1)
/* 32096C 802BFBFC C626003C */  lwc1      $f6, 0x3c($s1)
/* 320970 802BFC00 C6280040 */  lwc1      $f8, 0x40($s1)
/* 320974 802BFC04 8E230000 */  lw        $v1, ($s1)
/* 320978 802BFC08 0220202D */  daddu     $a0, $s1, $zero
/* 32097C 802BFC0C AE220028 */  sw        $v0, 0x28($s1)
/* 320980 802BFC10 2402FDFF */  addiu     $v0, $zero, -0x201
/* 320984 802BFC14 E620000C */  swc1      $f0, 0xc($s1)
/* 320988 802BFC18 AE200014 */  sw        $zero, 0x14($s1)
/* 32098C 802BFC1C 34630108 */  ori       $v1, $v1, 0x108
/* 320990 802BFC20 00621824 */  and       $v1, $v1, $v0
/* 320994 802BFC24 E6220018 */  swc1      $f2, 0x18($s1)
/* 320998 802BFC28 E6240060 */  swc1      $f4, 0x60($s1)
/* 32099C 802BFC2C E6260064 */  swc1      $f6, 0x64($s1)
/* 3209A0 802BFC30 E6280068 */  swc1      $f8, 0x68($s1)
/* 3209A4 802BFC34 0C00EAFF */  jal       disable_npc_shadow
/* 3209A8 802BFC38 AE230000 */   sw       $v1, ($s1)
/* 3209AC 802BFC3C 0C038039 */  jal       disable_player_shadow
/* 3209B0 802BFC40 00000000 */   nop
/* 3209B4 802BFC44 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 3209B8 802BFC48 14400005 */  bnez      $v0, .L802BFC60
/* 3209BC 802BFC4C 3C040008 */   lui      $a0, 8
/* 3209C0 802BFC50 0C03ADF3 */  jal       partner_kill_ability_script
/* 3209C4 802BFC54 00000000 */   nop
/* 3209C8 802BFC58 080AFF2F */  j         .L802BFCBC
/* 3209CC 802BFC5C 24020019 */   addiu    $v0, $zero, 0x19
.L802BFC60:
/* 3209D0 802BFC60 0C037FDE */  jal       func_800DFF78
/* 3209D4 802BFC64 3484000F */   ori      $a0, $a0, 0xf
/* 3209D8 802BFC68 C622000C */  lwc1      $f2, 0xc($s1)
/* 3209DC 802BFC6C 44800000 */  mtc1      $zero, $f0
/* 3209E0 802BFC70 00000000 */  nop
/* 3209E4 802BFC74 4602003E */  c.le.s    $f0, $f2
/* 3209E8 802BFC78 00000000 */  nop
/* 3209EC 802BFC7C 4500000F */  bc1f      .L802BFCBC
/* 3209F0 802BFC80 24020019 */   addiu    $v0, $zero, 0x19
/* 3209F4 802BFC84 3C014334 */  lui       $at, 0x4334
/* 3209F8 802BFC88 44810000 */  mtc1      $at, $f0
/* 3209FC 802BFC8C 00000000 */  nop
/* 320A00 802BFC90 4600103E */  c.le.s    $f2, $f0
/* 320A04 802BFC94 00000000 */  nop
/* 320A08 802BFC98 45020009 */  bc1fl     .L802BFCC0
/* 320A0C 802BFC9C AE620074 */   sw       $v0, 0x74($s3)
/* 320A10 802BFCA0 4600128D */  trunc.w.s $f10, $f2
/* 320A14 802BFCA4 44025000 */  mfc1      $v0, $f10
/* 320A18 802BFCA8 00000000 */  nop
/* 320A1C 802BFCAC A622008A */  sh        $v0, 0x8a($s1)
/* 320A20 802BFCB0 24020001 */  addiu     $v0, $zero, 1
/* 320A24 802BFCB4 A6220088 */  sh        $v0, 0x88($s1)
/* 320A28 802BFCB8 24020019 */  addiu     $v0, $zero, 0x19
.L802BFCBC:
/* 320A2C 802BFCBC AE620074 */  sw        $v0, 0x74($s3)
.L802BFCC0:
/* 320A30 802BFCC0 24020001 */  addiu     $v0, $zero, 1
/* 320A34 802BFCC4 080AFF60 */  j         .L802BFD80
/* 320A38 802BFCC8 AE620070 */   sw       $v0, 0x70($s3)
.L802BFCCC:
/* 320A3C 802BFCCC 8E250018 */  lw        $a1, 0x18($s1)
/* 320A40 802BFCD0 8E26000C */  lw        $a2, 0xc($s1)
/* 320A44 802BFCD4 0C00EA95 */  jal       npc_move_heading
/* 320A48 802BFCD8 0220202D */   daddu    $a0, $s1, $zero
/* 320A4C 802BFCDC 0C0AF440 */  jal       func_802BD100_31DE70
/* 320A50 802BFCE0 00000000 */   nop
/* 320A54 802BFCE4 8E620074 */  lw        $v0, 0x74($s3)
/* 320A58 802BFCE8 30420003 */  andi      $v0, $v0, 3
/* 320A5C 802BFCEC 14400011 */  bnez      $v0, .L802BFD34
/* 320A60 802BFCF0 00000000 */   nop
/* 320A64 802BFCF4 862200A8 */  lh        $v0, 0xa8($s1)
/* 320A68 802BFCF8 3C013F00 */  lui       $at, 0x3f00
/* 320A6C 802BFCFC 44811000 */  mtc1      $at, $f2
/* 320A70 802BFD00 44820000 */  mtc1      $v0, $f0
/* 320A74 802BFD04 00000000 */  nop
/* 320A78 802BFD08 46800020 */  cvt.s.w   $f0, $f0
/* 320A7C 802BFD0C 46020002 */  mul.s     $f0, $f0, $f2
/* 320A80 802BFD10 00000000 */  nop
/* 320A84 802BFD14 C6220064 */  lwc1      $f2, 0x64($s1)
/* 320A88 802BFD18 AFA00010 */  sw        $zero, 0x10($sp)
/* 320A8C 802BFD1C 46001080 */  add.s     $f2, $f2, $f0
/* 320A90 802BFD20 8E250038 */  lw        $a1, 0x38($s1)
/* 320A94 802BFD24 8E270040 */  lw        $a3, 0x40($s1)
/* 320A98 802BFD28 44061000 */  mfc1      $a2, $f2
/* 320A9C 802BFD2C 0C01C16C */  jal       func_800705B0
/* 320AA0 802BFD30 0000202D */   daddu    $a0, $zero, $zero
.L802BFD34:
/* 320AA4 802BFD34 8E620074 */  lw        $v0, 0x74($s3)
/* 320AA8 802BFD38 2442FFFF */  addiu     $v0, $v0, -1
/* 320AAC 802BFD3C 14400010 */  bnez      $v0, .L802BFD80
/* 320AB0 802BFD40 AE620074 */   sw       $v0, 0x74($s3)
/* 320AB4 802BFD44 8E6200B4 */  lw        $v0, 0xb4($s3)
/* 320AB8 802BFD48 14500007 */  bne       $v0, $s0, .L802BFD68
/* 320ABC 802BFD4C 00000000 */   nop
/* 320AC0 802BFD50 0C039769 */  jal       set_action_state
/* 320AC4 802BFD54 24040021 */   addiu    $a0, $zero, 0x21
/* 320AC8 802BFD58 0C03ACC5 */  jal       partner_use_ability
/* 320ACC 802BFD5C 00000000 */   nop
/* 320AD0 802BFD60 080AFF61 */  j         .L802BFD84
/* 320AD4 802BFD64 24020002 */   addiu    $v0, $zero, 2
.L802BFD68:
/* 320AD8 802BFD68 0C038050 */  jal       enable_player_static_collisions
/* 320ADC 802BFD6C 00000000 */   nop
/* 320AE0 802BFD70 0C038069 */  jal       enable_player_input
/* 320AE4 802BFD74 00000000 */   nop
/* 320AE8 802BFD78 080AFF61 */  j         .L802BFD84
/* 320AEC 802BFD7C 24020002 */   addiu    $v0, $zero, 2
.L802BFD80:
/* 320AF0 802BFD80 0000102D */  daddu     $v0, $zero, $zero
.L802BFD84:
/* 320AF4 802BFD84 8FBF0028 */  lw        $ra, 0x28($sp)
/* 320AF8 802BFD88 8FB30024 */  lw        $s3, 0x24($sp)
/* 320AFC 802BFD8C 8FB20020 */  lw        $s2, 0x20($sp)
/* 320B00 802BFD90 8FB1001C */  lw        $s1, 0x1c($sp)
/* 320B04 802BFD94 8FB00018 */  lw        $s0, 0x18($sp)
/* 320B08 802BFD98 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 320B0C 802BFD9C 03E00008 */  jr        $ra
/* 320B10 802BFDA0 27BD0038 */   addiu    $sp, $sp, 0x38
/* 320B14 802BFDA4 00000000 */  nop
/* 320B18 802BFDA8 00000000 */  nop
/* 320B1C 802BFDAC 00000000 */  nop
