.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B64_8DAC64
/* 8DAC64 80240B64 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 8DAC68 80240B68 AFB40040 */  sw        $s4, 0x40($sp)
/* 8DAC6C 80240B6C 0080A02D */  daddu     $s4, $a0, $zero
/* 8DAC70 80240B70 AFBF0048 */  sw        $ra, 0x48($sp)
/* 8DAC74 80240B74 AFB50044 */  sw        $s5, 0x44($sp)
/* 8DAC78 80240B78 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8DAC7C 80240B7C AFB20038 */  sw        $s2, 0x38($sp)
/* 8DAC80 80240B80 AFB10034 */  sw        $s1, 0x34($sp)
/* 8DAC84 80240B84 AFB00030 */  sw        $s0, 0x30($sp)
/* 8DAC88 80240B88 8E920148 */  lw        $s2, 0x148($s4)
/* 8DAC8C 80240B8C 86440008 */  lh        $a0, 8($s2)
/* 8DAC90 80240B90 8E90000C */  lw        $s0, 0xc($s4)
/* 8DAC94 80240B94 0C00EABB */  jal       get_npc_unsafe
/* 8DAC98 80240B98 00A0882D */   daddu    $s1, $a1, $zero
/* 8DAC9C 80240B9C 0280202D */  daddu     $a0, $s4, $zero
/* 8DACA0 80240BA0 8E050000 */  lw        $a1, ($s0)
/* 8DACA4 80240BA4 0C0B1EAF */  jal       get_variable
/* 8DACA8 80240BA8 0040802D */   daddu    $s0, $v0, $zero
/* 8DACAC 80240BAC AFA00010 */  sw        $zero, 0x10($sp)
/* 8DACB0 80240BB0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8DACB4 80240BB4 8C630030 */  lw        $v1, 0x30($v1)
/* 8DACB8 80240BB8 AFA30014 */  sw        $v1, 0x14($sp)
/* 8DACBC 80240BBC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8DACC0 80240BC0 8C63001C */  lw        $v1, 0x1c($v1)
/* 8DACC4 80240BC4 AFA30018 */  sw        $v1, 0x18($sp)
/* 8DACC8 80240BC8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8DACCC 80240BCC 8C630024 */  lw        $v1, 0x24($v1)
/* 8DACD0 80240BD0 AFA3001C */  sw        $v1, 0x1c($sp)
/* 8DACD4 80240BD4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8DACD8 80240BD8 8C630028 */  lw        $v1, 0x28($v1)
/* 8DACDC 80240BDC 27B50010 */  addiu     $s5, $sp, 0x10
/* 8DACE0 80240BE0 AFA30020 */  sw        $v1, 0x20($sp)
/* 8DACE4 80240BE4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* 8DACE8 80240BE8 3C014282 */  lui       $at, 0x4282
/* 8DACEC 80240BEC 44810000 */  mtc1      $at, $f0
/* 8DACF0 80240BF0 8C63002C */  lw        $v1, 0x2c($v1)
/* 8DACF4 80240BF4 0040982D */  daddu     $s3, $v0, $zero
/* 8DACF8 80240BF8 E7A00028 */  swc1      $f0, 0x28($sp)
/* 8DACFC 80240BFC A7A0002C */  sh        $zero, 0x2c($sp)
/* 8DAD00 80240C00 16200005 */  bnez      $s1, .L80240C18
/* 8DAD04 80240C04 AFA30024 */   sw       $v1, 0x24($sp)
/* 8DAD08 80240C08 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 8DAD0C 80240C0C 30420004 */  andi      $v0, $v0, 4
/* 8DAD10 80240C10 1040002F */  beqz      $v0, .L80240CD0
/* 8DAD14 80240C14 00000000 */   nop      
.L80240C18:
/* 8DAD18 80240C18 AE800070 */  sw        $zero, 0x70($s4)
/* 8DAD1C 80240C1C C600000C */  lwc1      $f0, 0xc($s0)
/* 8DAD20 80240C20 A600008E */  sh        $zero, 0x8e($s0)
/* 8DAD24 80240C24 8E4200CC */  lw        $v0, 0xcc($s2)
/* 8DAD28 80240C28 4600008D */  trunc.w.s $f2, $f0
/* 8DAD2C 80240C2C E642006C */  swc1      $f2, 0x6c($s2)
/* 8DAD30 80240C30 8C420000 */  lw        $v0, ($v0)
/* 8DAD34 80240C34 8E030000 */  lw        $v1, ($s0)
/* 8DAD38 80240C38 AE020028 */  sw        $v0, 0x28($s0)
/* 8DAD3C 80240C3C 2402F7FF */  addiu     $v0, $zero, -0x801
/* 8DAD40 80240C40 00621824 */  and       $v1, $v1, $v0
/* 8DAD44 80240C44 AE030000 */  sw        $v1, ($s0)
/* 8DAD48 80240C48 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 8DAD4C 80240C4C 8C420034 */  lw        $v0, 0x34($v0)
/* 8DAD50 80240C50 54400005 */  bnel      $v0, $zero, .L80240C68
/* 8DAD54 80240C54 2402FDFF */   addiu    $v0, $zero, -0x201
/* 8DAD58 80240C58 34620200 */  ori       $v0, $v1, 0x200
/* 8DAD5C 80240C5C 2403FFF7 */  addiu     $v1, $zero, -9
/* 8DAD60 80240C60 0809031C */  j         .L80240C70
/* 8DAD64 80240C64 00431024 */   and      $v0, $v0, $v1
.L80240C68:
/* 8DAD68 80240C68 00621024 */  and       $v0, $v1, $v0
/* 8DAD6C 80240C6C 34420008 */  ori       $v0, $v0, 8
.L80240C70:
/* 8DAD70 80240C70 AE020000 */  sw        $v0, ($s0)
/* 8DAD74 80240C74 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 8DAD78 80240C78 30420004 */  andi      $v0, $v0, 4
/* 8DAD7C 80240C7C 10400009 */  beqz      $v0, .L80240CA4
/* 8DAD80 80240C80 24020063 */   addiu    $v0, $zero, 0x63
/* 8DAD84 80240C84 AE820070 */  sw        $v0, 0x70($s4)
/* 8DAD88 80240C88 2402000F */  addiu     $v0, $zero, 0xf
/* 8DAD8C 80240C8C AE820074 */  sw        $v0, 0x74($s4)
/* 8DAD90 80240C90 8E4200B0 */  lw        $v0, 0xb0($s2)
/* 8DAD94 80240C94 2403FFFB */  addiu     $v1, $zero, -5
/* 8DAD98 80240C98 00431024 */  and       $v0, $v0, $v1
/* 8DAD9C 80240C9C 08090334 */  j         .L80240CD0
/* 8DADA0 80240CA0 AE4200B0 */   sw       $v0, 0xb0($s2)
.L80240CA4:
/* 8DADA4 80240CA4 8E420000 */  lw        $v0, ($s2)
/* 8DADA8 80240CA8 3C034000 */  lui       $v1, 0x4000
/* 8DADAC 80240CAC 00431024 */  and       $v0, $v0, $v1
/* 8DADB0 80240CB0 10400007 */  beqz      $v0, .L80240CD0
/* 8DADB4 80240CB4 3C03BFFF */   lui      $v1, 0xbfff
/* 8DADB8 80240CB8 2402000C */  addiu     $v0, $zero, 0xc
/* 8DADBC 80240CBC AE820070 */  sw        $v0, 0x70($s4)
/* 8DADC0 80240CC0 8E420000 */  lw        $v0, ($s2)
/* 8DADC4 80240CC4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 8DADC8 80240CC8 00431024 */  and       $v0, $v0, $v1
/* 8DADCC 80240CCC AE420000 */  sw        $v0, ($s2)
.L80240CD0:
/* 8DADD0 80240CD0 8E830070 */  lw        $v1, 0x70($s4)
/* 8DADD4 80240CD4 2C620064 */  sltiu     $v0, $v1, 0x64
/* 8DADD8 80240CD8 10400036 */  beqz      $v0, .L80240DB4
/* 8DADDC 80240CDC 00031080 */   sll      $v0, $v1, 2
/* 8DADE0 80240CE0 3C018025 */  lui       $at, %hi(D_802510C8)
/* 8DADE4 80240CE4 00220821 */  addu      $at, $at, $v0
/* 8DADE8 80240CE8 8C2210C8 */  lw        $v0, %lo(D_802510C8)($at)
/* 8DADEC 80240CEC 00400008 */  jr        $v0
/* 8DADF0 80240CF0 00000000 */   nop      
/* 8DADF4 80240CF4 0280202D */  daddu     $a0, $s4, $zero
/* 8DADF8 80240CF8 0260282D */  daddu     $a1, $s3, $zero
/* 8DADFC 80240CFC 0C0900DC */  jal       func_80240370_8DA470
/* 8DAE00 80240D00 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE04 80240D04 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE08 80240D08 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE0C 80240D0C 0C090109 */  jal       func_80240424_8DA524
/* 8DAE10 80240D10 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE14 80240D14 0809036D */  j         .L80240DB4
/* 8DAE18 80240D18 00000000 */   nop      
/* 8DAE1C 80240D1C 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE20 80240D20 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE24 80240D24 0C090151 */  jal       func_80240544_8DA644
/* 8DAE28 80240D28 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE2C 80240D2C 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE30 80240D30 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE34 80240D34 0C090169 */  jal       func_802405A4_8DA6A4
/* 8DAE38 80240D38 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE3C 80240D3C 0809036D */  j         .L80240DB4
/* 8DAE40 80240D40 00000000 */   nop      
/* 8DAE44 80240D44 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE48 80240D48 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE4C 80240D4C 0C090187 */  jal       func_8024061C_8DA71C
/* 8DAE50 80240D50 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE54 80240D54 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE58 80240D58 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE5C 80240D5C 0C0901D3 */  jal       func_8024074C_8DA84C
/* 8DAE60 80240D60 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE64 80240D64 0809036D */  j         .L80240DB4
/* 8DAE68 80240D68 00000000 */   nop      
/* 8DAE6C 80240D6C 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE70 80240D70 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE74 80240D74 0C09021A */  jal       func_80240868_8DA968
/* 8DAE78 80240D78 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE7C 80240D7C 0809036D */  j         .L80240DB4
/* 8DAE80 80240D80 00000000 */   nop      
/* 8DAE84 80240D84 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE88 80240D88 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE8C 80240D8C 0C09022C */  jal       func_802408B0_8DA9B0
/* 8DAE90 80240D90 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAE94 80240D94 0280202D */  daddu     $a0, $s4, $zero
/* 8DAE98 80240D98 0260282D */  daddu     $a1, $s3, $zero
/* 8DAE9C 80240D9C 0C090257 */  jal       func_8024095C_8DAA5C
/* 8DAEA0 80240DA0 02A0302D */   daddu    $a2, $s5, $zero
/* 8DAEA4 80240DA4 0809036D */  j         .L80240DB4
/* 8DAEA8 80240DA8 00000000 */   nop      
/* 8DAEAC 80240DAC 0C0129CF */  jal       func_8004A73C
/* 8DAEB0 80240DB0 0280202D */   daddu    $a0, $s4, $zero
.L80240DB4:
/* 8DAEB4 80240DB4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 8DAEB8 80240DB8 8FB50044 */  lw        $s5, 0x44($sp)
/* 8DAEBC 80240DBC 8FB40040 */  lw        $s4, 0x40($sp)
/* 8DAEC0 80240DC0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8DAEC4 80240DC4 8FB20038 */  lw        $s2, 0x38($sp)
/* 8DAEC8 80240DC8 8FB10034 */  lw        $s1, 0x34($sp)
/* 8DAECC 80240DCC 8FB00030 */  lw        $s0, 0x30($sp)
/* 8DAED0 80240DD0 0000102D */  daddu     $v0, $zero, $zero
/* 8DAED4 80240DD4 03E00008 */  jr        $ra
/* 8DAED8 80240DD8 27BD0050 */   addiu    $sp, $sp, 0x50
