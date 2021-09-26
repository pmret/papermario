.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_update_begin_player_turn
/* 170904 80242024 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 170908 80242028 AFB30024 */  sw        $s3, 0x24($sp)
/* 17090C 8024202C 3C13800E */  lui       $s3, %hi(gBattleStatus)
/* 170910 80242030 2673C070 */  addiu     $s3, $s3, %lo(gBattleStatus)
/* 170914 80242034 AFB60030 */  sw        $s6, 0x30($sp)
/* 170918 80242038 3C168011 */  lui       $s6, %hi(gPlayerData)
/* 17091C 8024203C 26D6F290 */  addiu     $s6, $s6, %lo(gPlayerData)
/* 170920 80242040 AFB20020 */  sw        $s2, 0x20($sp)
/* 170924 80242044 3C12800E */  lui       $s2, %hi(gBattleState2)
/* 170928 80242048 2652C4DC */  addiu     $s2, $s2, %lo(gBattleState2)
/* 17092C 8024204C AFBF0034 */  sw        $ra, 0x34($sp)
/* 170930 80242050 AFB5002C */  sw        $s5, 0x2c($sp)
/* 170934 80242054 AFB40028 */  sw        $s4, 0x28($sp)
/* 170938 80242058 AFB1001C */  sw        $s1, 0x1c($sp)
/* 17093C 8024205C AFB00018 */  sw        $s0, 0x18($sp)
/* 170940 80242060 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 170944 80242064 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 170948 80242068 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 17094C 8024206C 8E7100D8 */  lw        $s1, 0xd8($s3)
/* 170950 80242070 8E7000DC */  lw        $s0, 0xdc($s3)
/* 170954 80242074 8E420000 */  lw        $v0, ($s2)
/* 170958 80242078 14400007 */  bnez      $v0, .L80242098
/* 17095C 8024207C 8E3401F4 */   lw       $s4, 0x1f4($s1)
/* 170960 80242080 0C093903 */  jal       func_8024E40C
/* 170964 80242084 24040002 */   addiu    $a0, $zero, 2
/* 170968 80242088 0C093936 */  jal       btl_cam_move
/* 17096C 8024208C 24040005 */   addiu    $a0, $zero, 5
/* 170970 80242090 24020064 */  addiu     $v0, $zero, 0x64
/* 170974 80242094 AE420000 */  sw        $v0, ($s2)
.L80242098:
/* 170978 80242098 8E430000 */  lw        $v1, ($s2)
/* 17097C 8024209C 24150014 */  addiu     $s5, $zero, 0x14
/* 170980 802420A0 10750039 */  beq       $v1, $s5, .L80242188
/* 170984 802420A4 24020064 */   addiu    $v0, $zero, 0x64
/* 170988 802420A8 14620041 */  bne       $v1, $v0, .L802421B0
/* 17098C 802420AC 00000000 */   nop
/* 170990 802420B0 0C093961 */  jal       func_8024E584
/* 170994 802420B4 00000000 */   nop
/* 170998 802420B8 1040003D */  beqz      $v0, .L802421B0
/* 17099C 802420BC 3C03FFF7 */   lui      $v1, 0xfff7
/* 1709A0 802420C0 8E620000 */  lw        $v0, ($s3)
/* 1709A4 802420C4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 1709A8 802420C8 00431024 */  and       $v0, $v0, $v1
/* 1709AC 802420CC 0C098F18 */  jal       reset_actor_turn_info
/* 1709B0 802420D0 AE620000 */   sw       $v0, ($s3)
/* 1709B4 802420D4 3C04FEFF */  lui       $a0, 0xfeff
/* 1709B8 802420D8 2402007F */  addiu     $v0, $zero, 0x7f
/* 1709BC 802420DC A2620086 */  sb        $v0, 0x86($s3)
/* 1709C0 802420E0 A2620087 */  sb        $v0, 0x87($s3)
/* 1709C4 802420E4 8E620000 */  lw        $v0, ($s3)
/* 1709C8 802420E8 8E630004 */  lw        $v1, 4($s3)
/* 1709CC 802420EC 3484FFFF */  ori       $a0, $a0, 0xffff
/* 1709D0 802420F0 A660017C */  sh        $zero, 0x17c($s3)
/* 1709D4 802420F4 34420008 */  ori       $v0, $v0, 8
/* 1709D8 802420F8 00641824 */  and       $v1, $v1, $a0
/* 1709DC 802420FC AE620000 */  sw        $v0, ($s3)
/* 1709E0 80242100 AE630004 */  sw        $v1, 4($s3)
/* 1709E4 80242104 8E220000 */  lw        $v0, ($s1)
/* 1709E8 80242108 3C030C00 */  lui       $v1, 0xc00
/* 1709EC 8024210C A220021D */  sb        $zero, 0x21d($s1)
/* 1709F0 80242110 00431025 */  or        $v0, $v0, $v1
/* 1709F4 80242114 12000004 */  beqz      $s0, .L80242128
/* 1709F8 80242118 AE220000 */   sw       $v0, ($s1)
/* 1709FC 8024211C 00431025 */  or        $v0, $v0, $v1
/* 170A00 80242120 AE220000 */  sw        $v0, ($s1)
/* 170A04 80242124 A200021D */  sb        $zero, 0x21d($s0)
.L80242128:
/* 170A08 80242128 8262009A */  lb        $v0, 0x9a($s3)
/* 170A0C 8024212C A260008C */  sb        $zero, 0x8c($s3)
/* 170A10 80242130 3C01802A */  lui       $at, %hi(D_8029F254)
/* 170A14 80242134 AC20F254 */  sw        $zero, %lo(D_8029F254)($at)
/* 170A18 80242138 3C01802A */  lui       $at, %hi(D_8029F258)
/* 170A1C 8024213C AC20F258 */  sw        $zero, %lo(D_8029F258)($at)
/* 170A20 80242140 14400004 */  bnez      $v0, .L80242154
/* 170A24 80242144 2405000A */   addiu    $a1, $zero, 0xa
/* 170A28 80242148 2402000A */  addiu     $v0, $zero, 0xa
/* 170A2C 8024214C 0809086C */  j         .L802421B0
/* 170A30 80242150 AE420000 */   sw       $v0, ($s2)
.L80242154:
/* 170A34 80242154 2402000C */  addiu     $v0, $zero, 0xc
/* 170A38 80242158 A26201A7 */  sb        $v0, 0x1a7($s3)
/* 170A3C 8024215C 8E0401CC */  lw        $a0, 0x1cc($s0)
/* 170A40 80242160 0C0B0CF8 */  jal       start_script
/* 170A44 80242164 0000302D */   daddu    $a2, $zero, $zero
/* 170A48 80242168 0040182D */  daddu     $v1, $v0, $zero
/* 170A4C 8024216C AE0301DC */  sw        $v1, 0x1dc($s0)
/* 170A50 80242170 8C620144 */  lw        $v0, 0x144($v1)
/* 170A54 80242174 AE550000 */  sw        $s5, ($s2)
/* 170A58 80242178 AE0201EC */  sw        $v0, 0x1ec($s0)
/* 170A5C 8024217C 24020100 */  addiu     $v0, $zero, 0x100
/* 170A60 80242180 0809086C */  j         .L802421B0
/* 170A64 80242184 AC620148 */   sw       $v0, 0x148($v1)
.L80242188:
/* 170A68 80242188 8E0401EC */  lw        $a0, 0x1ec($s0)
/* 170A6C 8024218C 0C0B1059 */  jal       does_script_exist
/* 170A70 80242190 00000000 */   nop
/* 170A74 80242194 14400006 */  bnez      $v0, .L802421B0
/* 170A78 80242198 2403000A */   addiu    $v1, $zero, 0xa
/* 170A7C 8024219C 8E620004 */  lw        $v0, 4($s3)
/* 170A80 802421A0 A260009A */  sb        $zero, 0x9a($s3)
/* 170A84 802421A4 AE430000 */  sw        $v1, ($s2)
/* 170A88 802421A8 34420004 */  ori       $v0, $v0, 4
/* 170A8C 802421AC AE620004 */  sw        $v0, 4($s3)
.L802421B0:
/* 170A90 802421B0 3C12800E */  lui       $s2, %hi(gBattleState2)
/* 170A94 802421B4 2652C4DC */  addiu     $s2, $s2, %lo(gBattleState2)
/* 170A98 802421B8 8E440000 */  lw        $a0, ($s2)
/* 170A9C 802421BC 24150002 */  addiu     $s5, $zero, 2
/* 170AA0 802421C0 10950066 */  beq       $a0, $s5, .L8024235C
/* 170AA4 802421C4 2402000A */   addiu    $v0, $zero, 0xa
/* 170AA8 802421C8 1482006A */  bne       $a0, $v0, .L80242374
/* 170AAC 802421CC 00000000 */   nop
/* 170AB0 802421D0 8262008C */  lb        $v0, 0x8c($s3)
/* 170AB4 802421D4 14400067 */  bnez      $v0, .L80242374
/* 170AB8 802421D8 00000000 */   nop
/* 170ABC 802421DC 8262009D */  lb        $v0, 0x9d($s3)
/* 170AC0 802421E0 9263009D */  lbu       $v1, 0x9d($s3)
/* 170AC4 802421E4 10400061 */  beqz      $v0, .L8024236C
/* 170AC8 802421E8 2462FFFF */   addiu    $v0, $v1, -1
/* 170ACC 802421EC 8E63043C */  lw        $v1, 0x43c($s3)
/* 170AD0 802421F0 A262009D */  sb        $v0, 0x9d($s3)
/* 170AD4 802421F4 00021600 */  sll       $v0, $v0, 0x18
/* 170AD8 802421F8 8C63000C */  lw        $v1, 0xc($v1)
/* 170ADC 802421FC 00021603 */  sra       $v0, $v0, 0x18
/* 170AE0 80242200 A4620010 */  sh        $v0, 0x10($v1)
/* 170AE4 80242204 8262009D */  lb        $v0, 0x9d($s3)
/* 170AE8 80242208 1C400059 */  bgtz      $v0, .L80242370
/* 170AEC 8024220C 2402000B */   addiu    $v0, $zero, 0xb
/* 170AF0 80242210 8E6300A0 */  lw        $v1, 0xa0($s3)
/* 170AF4 80242214 3C014190 */  lui       $at, 0x4190
/* 170AF8 80242218 44811000 */  mtc1      $at, $f2
/* 170AFC 8024221C 3C0140A0 */  lui       $at, 0x40a0
/* 170B00 80242220 4481B000 */  mtc1      $at, $f22
/* 170B04 80242224 8C620000 */  lw        $v0, ($v1)
/* 170B08 80242228 3C013FC0 */  lui       $at, 0x3fc0
/* 170B0C 8024222C 44810000 */  mtc1      $at, $f0
/* 170B10 80242230 34420010 */  ori       $v0, $v0, 0x10
/* 170B14 80242234 AC620000 */  sw        $v0, ($v1)
/* 170B18 80242238 C6240148 */  lwc1      $f4, 0x148($s1)
/* 170B1C 8024223C C626014C */  lwc1      $f6, 0x14c($s1)
/* 170B20 80242240 46022100 */  add.s     $f4, $f4, $f2
/* 170B24 80242244 E7A00010 */  swc1      $f0, 0x10($sp)
/* 170B28 80242248 AFA40014 */  sw        $a0, 0x14($sp)
/* 170B2C 8024224C 46163180 */  add.s     $f6, $f6, $f22
/* 170B30 80242250 8E250144 */  lw        $a1, 0x144($s1)
/* 170B34 80242254 44062000 */  mfc1      $a2, $f4
/* 170B38 80242258 44073000 */  mfc1      $a3, $f6
/* 170B3C 8024225C 0C01C694 */  jal       playFX_5A
/* 170B40 80242260 24040001 */   addiu    $a0, $zero, 1
/* 170B44 80242264 C6220144 */  lwc1      $f2, 0x144($s1)
/* 170B48 80242268 3C014120 */  lui       $at, 0x4120
/* 170B4C 8024226C 44810000 */  mtc1      $at, $f0
/* 170B50 80242270 00000000 */  nop
/* 170B54 80242274 46001081 */  sub.s     $f2, $f2, $f0
/* 170B58 80242278 C6200148 */  lwc1      $f0, 0x148($s1)
/* 170B5C 8024227C 46160000 */  add.s     $f0, $f0, $f22
/* 170B60 80242280 44060000 */  mfc1      $a2, $f0
/* 170B64 80242284 C620014C */  lwc1      $f0, 0x14c($s1)
/* 170B68 80242288 0000202D */  daddu     $a0, $zero, $zero
/* 170B6C 8024228C 46160000 */  add.s     $f0, $f0, $f22
/* 170B70 80242290 3C013F80 */  lui       $at, 0x3f80
/* 170B74 80242294 4481A000 */  mtc1      $at, $f20
/* 170B78 80242298 44051000 */  mfc1      $a1, $f2
/* 170B7C 8024229C 44070000 */  mfc1      $a3, $f0
/* 170B80 802422A0 24100018 */  addiu     $s0, $zero, 0x18
/* 170B84 802422A4 E7B40010 */  swc1      $f20, 0x10($sp)
/* 170B88 802422A8 0C01C70C */  jal       playFX_5F
/* 170B8C 802422AC AFB00014 */   sw       $s0, 0x14($sp)
/* 170B90 802422B0 C6200144 */  lwc1      $f0, 0x144($s1)
/* 170B94 802422B4 3C014170 */  lui       $at, 0x4170
/* 170B98 802422B8 4481C000 */  mtc1      $at, $f24
/* 170B9C 802422BC 00000000 */  nop
/* 170BA0 802422C0 46180001 */  sub.s     $f0, $f0, $f24
/* 170BA4 802422C4 C6220148 */  lwc1      $f2, 0x148($s1)
/* 170BA8 802422C8 44050000 */  mfc1      $a1, $f0
/* 170BAC 802422CC 3C014200 */  lui       $at, 0x4200
/* 170BB0 802422D0 44810000 */  mtc1      $at, $f0
/* 170BB4 802422D4 00000000 */  nop
/* 170BB8 802422D8 46001080 */  add.s     $f2, $f2, $f0
/* 170BBC 802422DC C620014C */  lwc1      $f0, 0x14c($s1)
/* 170BC0 802422E0 46160000 */  add.s     $f0, $f0, $f22
/* 170BC4 802422E4 44061000 */  mfc1      $a2, $f2
/* 170BC8 802422E8 44070000 */  mfc1      $a3, $f0
/* 170BCC 802422EC 0000202D */  daddu     $a0, $zero, $zero
/* 170BD0 802422F0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 170BD4 802422F4 0C01C70C */  jal       playFX_5F
/* 170BD8 802422F8 AFB00014 */   sw       $s0, 0x14($sp)
/* 170BDC 802422FC C6200144 */  lwc1      $f0, 0x144($s1)
/* 170BE0 80242300 46180000 */  add.s     $f0, $f0, $f24
/* 170BE4 80242304 C6220148 */  lwc1      $f2, 0x148($s1)
/* 170BE8 80242308 44050000 */  mfc1      $a1, $f0
/* 170BEC 8024230C 3C0141B0 */  lui       $at, 0x41b0
/* 170BF0 80242310 44810000 */  mtc1      $at, $f0
/* 170BF4 80242314 00000000 */  nop
/* 170BF8 80242318 46001080 */  add.s     $f2, $f2, $f0
/* 170BFC 8024231C C620014C */  lwc1      $f0, 0x14c($s1)
/* 170C00 80242320 46160000 */  add.s     $f0, $f0, $f22
/* 170C04 80242324 44061000 */  mfc1      $a2, $f2
/* 170C08 80242328 44070000 */  mfc1      $a3, $f0
/* 170C0C 8024232C 24040001 */  addiu     $a0, $zero, 1
/* 170C10 80242330 E7B40010 */  swc1      $f20, 0x10($sp)
/* 170C14 80242334 0C01C70C */  jal       playFX_5F
/* 170C18 80242338 AFB00014 */   sw       $s0, 0x14($sp)
/* 170C1C 8024233C 24040299 */  addiu     $a0, $zero, 0x299
/* 170C20 80242340 0C05272D */  jal       sfx_play_sound
/* 170C24 80242344 AE6000A0 */   sw       $zero, 0xa0($s3)
/* 170C28 80242348 24040027 */  addiu     $a0, $zero, 0x27
/* 170C2C 8024234C 0C093E58 */  jal       btl_show_battle_message
/* 170C30 80242350 2405003C */   addiu    $a1, $zero, 0x3c
/* 170C34 80242354 080908DD */  j         .L80242374
/* 170C38 80242358 AE550000 */   sw       $s5, ($s2)
.L8024235C:
/* 170C3C 8024235C 0C093EAD */  jal       btl_is_popup_displayed
/* 170C40 80242360 00000000 */   nop
/* 170C44 80242364 14400003 */  bnez      $v0, .L80242374
/* 170C48 80242368 00000000 */   nop
.L8024236C:
/* 170C4C 8024236C 2402000B */  addiu     $v0, $zero, 0xb
.L80242370:
/* 170C50 80242370 AE420000 */  sw        $v0, ($s2)
.L80242374:
/* 170C54 80242374 3C10800E */  lui       $s0, %hi(gBattleState2)
/* 170C58 80242378 2610C4DC */  addiu     $s0, $s0, %lo(gBattleState2)
/* 170C5C 8024237C 8E030000 */  lw        $v1, ($s0)
/* 170C60 80242380 2402000B */  addiu     $v0, $zero, 0xb
/* 170C64 80242384 10620005 */  beq       $v1, $v0, .L8024239C
/* 170C68 80242388 2402000C */   addiu    $v0, $zero, 0xc
/* 170C6C 8024238C 10620019 */  beq       $v1, $v0, .L802423F4
/* 170C70 80242390 2402000F */   addiu    $v0, $zero, 0xf
/* 170C74 80242394 08090907 */  j         .L8024241C
/* 170C78 80242398 00000000 */   nop
.L8024239C:
/* 170C7C 8024239C 826200A4 */  lb        $v0, 0xa4($s3)
/* 170C80 802423A0 926300A4 */  lbu       $v1, 0xa4($s3)
/* 170C84 802423A4 10400017 */  beqz      $v0, .L80242404
/* 170C88 802423A8 2462FFFF */   addiu    $v0, $v1, -1
/* 170C8C 802423AC 8E63043C */  lw        $v1, 0x43c($s3)
/* 170C90 802423B0 A26200A4 */  sb        $v0, 0xa4($s3)
/* 170C94 802423B4 00021600 */  sll       $v0, $v0, 0x18
/* 170C98 802423B8 8C63000C */  lw        $v1, 0xc($v1)
/* 170C9C 802423BC 00021603 */  sra       $v0, $v0, 0x18
/* 170CA0 802423C0 A462001A */  sh        $v0, 0x1a($v1)
/* 170CA4 802423C4 826200A4 */  lb        $v0, 0xa4($s3)
/* 170CA8 802423C8 1C40000F */  bgtz      $v0, .L80242408
/* 170CAC 802423CC 2402000F */   addiu    $v0, $zero, 0xf
/* 170CB0 802423D0 8E6400A8 */  lw        $a0, 0xa8($s3)
/* 170CB4 802423D4 0C016914 */  jal       remove_effect
/* 170CB8 802423D8 00000000 */   nop
/* 170CBC 802423DC 24040029 */  addiu     $a0, $zero, 0x29
/* 170CC0 802423E0 2405003C */  addiu     $a1, $zero, 0x3c
/* 170CC4 802423E4 0C093E58 */  jal       btl_show_battle_message
/* 170CC8 802423E8 AE6000A8 */   sw       $zero, 0xa8($s3)
/* 170CCC 802423EC 08090902 */  j         .L80242408
/* 170CD0 802423F0 2402000C */   addiu    $v0, $zero, 0xc
.L802423F4:
/* 170CD4 802423F4 0C093EAD */  jal       btl_is_popup_displayed
/* 170CD8 802423F8 00000000 */   nop
/* 170CDC 802423FC 14400003 */  bnez      $v0, .L8024240C
/* 170CE0 80242400 00000000 */   nop
.L80242404:
/* 170CE4 80242404 2402000F */  addiu     $v0, $zero, 0xf
.L80242408:
/* 170CE8 80242408 AE020000 */  sw        $v0, ($s0)
.L8024240C:
/* 170CEC 8024240C 3C10800E */  lui       $s0, %hi(gBattleState2)
/* 170CF0 80242410 2610C4DC */  addiu     $s0, $s0, %lo(gBattleState2)
/* 170CF4 80242414 8E030000 */  lw        $v1, ($s0)
/* 170CF8 80242418 2402000F */  addiu     $v0, $zero, 0xf
.L8024241C:
/* 170CFC 8024241C 10620005 */  beq       $v1, $v0, .L80242434
/* 170D00 80242420 24020010 */   addiu    $v0, $zero, 0x10
/* 170D04 80242424 10620025 */  beq       $v1, $v0, .L802424BC
/* 170D08 80242428 00000000 */   nop
/* 170D0C 8024242C 08090935 */  j         .L802424D4
/* 170D10 80242430 00000000 */   nop
.L80242434:
/* 170D14 80242434 8262009B */  lb        $v0, 0x9b($s3)
/* 170D18 80242438 9264009B */  lbu       $a0, 0x9b($s3)
/* 170D1C 8024243C 10400024 */  beqz      $v0, .L802424D0
/* 170D20 80242440 24020015 */   addiu    $v0, $zero, 0x15
/* 170D24 80242444 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 170D28 80242448 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 170D2C 8024244C 8CA30004 */  lw        $v1, 4($a1)
/* 170D30 80242450 30620100 */  andi      $v0, $v1, 0x100
/* 170D34 80242454 10400004 */  beqz      $v0, .L80242468
/* 170D38 80242458 2402FEFF */   addiu    $v0, $zero, -0x101
/* 170D3C 8024245C 00621024 */  and       $v0, $v1, $v0
/* 170D40 80242460 08090933 */  j         .L802424CC
/* 170D44 80242464 ACA20004 */   sw       $v0, 4($a1)
.L80242468:
/* 170D48 80242468 8E63043C */  lw        $v1, 0x43c($s3)
/* 170D4C 8024246C 2482FFFF */  addiu     $v0, $a0, -1
/* 170D50 80242470 A262009B */  sb        $v0, 0x9b($s3)
/* 170D54 80242474 00021600 */  sll       $v0, $v0, 0x18
/* 170D58 80242478 8C63000C */  lw        $v1, 0xc($v1)
/* 170D5C 8024247C 00021603 */  sra       $v0, $v0, 0x18
/* 170D60 80242480 A4620024 */  sh        $v0, 0x24($v1)
/* 170D64 80242484 8262009B */  lb        $v0, 0x9b($s3)
/* 170D68 80242488 1C400011 */  bgtz      $v0, .L802424D0
/* 170D6C 8024248C 24020015 */   addiu    $v0, $zero, 0x15
/* 170D70 80242490 2404002B */  addiu     $a0, $zero, 0x2b
/* 170D74 80242494 0C093E58 */  jal       btl_show_battle_message
/* 170D78 80242498 2405003C */   addiu    $a1, $zero, 0x3c
/* 170D7C 8024249C 08090934 */  j         .L802424D0
/* 170D80 802424A0 24020010 */   addiu    $v0, $zero, 0x10
.L802424A4:
/* 170D84 802424A4 8E230440 */  lw        $v1, 0x440($s1)
/* 170D88 802424A8 A2220216 */  sb        $v0, 0x216($s1)
/* 170D8C 802424AC 82220217 */  lb        $v0, 0x217($s1)
/* 170D90 802424B0 8C63000C */  lw        $v1, 0xc($v1)
/* 170D94 802424B4 08090A05 */  j         .L80242814
/* 170D98 802424B8 AC62003C */   sw       $v0, 0x3c($v1)
.L802424BC:
/* 170D9C 802424BC 0C093EAD */  jal       btl_is_popup_displayed
/* 170DA0 802424C0 00000000 */   nop
/* 170DA4 802424C4 14400003 */  bnez      $v0, .L802424D4
/* 170DA8 802424C8 00000000 */   nop
.L802424CC:
/* 170DAC 802424CC 24020015 */  addiu     $v0, $zero, 0x15
.L802424D0:
/* 170DB0 802424D0 AE020000 */  sw        $v0, ($s0)
.L802424D4:
/* 170DB4 802424D4 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 170DB8 802424D8 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 170DBC 802424DC 24020015 */  addiu     $v0, $zero, 0x15
/* 170DC0 802424E0 14620042 */  bne       $v1, $v0, .L802425EC
/* 170DC4 802424E4 24020016 */   addiu    $v0, $zero, 0x16
/* 170DC8 802424E8 82230210 */  lb        $v1, 0x210($s1)
/* 170DCC 802424EC 24020009 */  addiu     $v0, $zero, 9
/* 170DD0 802424F0 1462000C */  bne       $v1, $v0, .L80242524
/* 170DD4 802424F4 3C03F7FF */   lui      $v1, 0xf7ff
/* 170DD8 802424F8 82220214 */  lb        $v0, 0x214($s1)
/* 170DDC 802424FC 14400009 */  bnez      $v0, .L80242524
/* 170DE0 80242500 24040001 */   addiu    $a0, $zero, 1
/* 170DE4 80242504 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 170DE8 80242508 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 170DEC 8024250C 8C620000 */  lw        $v0, ($v1)
/* 170DF0 80242510 2405000A */  addiu     $a1, $zero, 0xa
/* 170DF4 80242514 34420020 */  ori       $v0, $v0, 0x20
/* 170DF8 80242518 0C09CCDF */  jal       dispatch_damage_event_player_0
/* 170DFC 8024251C AC620000 */   sw       $v0, ($v1)
/* 170E00 80242520 3C03F7FF */  lui       $v1, 0xf7ff
.L80242524:
/* 170E04 80242524 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 170E08 80242528 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 170E0C 8024252C 8E020004 */  lw        $v0, 4($s0)
/* 170E10 80242530 3463FFFF */  ori       $v1, $v1, 0xffff
/* 170E14 80242534 A2600099 */  sb        $zero, 0x99($s3)
/* 170E18 80242538 00431824 */  and       $v1, $v0, $v1
/* 170E1C 8024253C 30420040 */  andi      $v0, $v0, 0x40
/* 170E20 80242540 14400024 */  bnez      $v0, .L802425D4
/* 170E24 80242544 AE030004 */   sw       $v1, 4($s0)
/* 170E28 80242548 82C20002 */  lb        $v0, 2($s6)
/* 170E2C 8024254C 28420002 */  slti      $v0, $v0, 2
/* 170E30 80242550 1040000B */  beqz      $v0, .L80242580
/* 170E34 80242554 00000000 */   nop
/* 170E38 80242558 0C03A752 */  jal       is_ability_active
/* 170E3C 8024255C 24040014 */   addiu    $a0, $zero, 0x14
/* 170E40 80242560 10400007 */  beqz      $v0, .L80242580
/* 170E44 80242564 3C020800 */   lui      $v0, 0x800
/* 170E48 80242568 8E030004 */  lw        $v1, 4($s0)
/* 170E4C 8024256C 92640099 */  lbu       $a0, 0x99($s3)
/* 170E50 80242570 00621825 */  or        $v1, $v1, $v0
/* 170E54 80242574 34840001 */  ori       $a0, $a0, 1
/* 170E58 80242578 AE030004 */  sw        $v1, 4($s0)
/* 170E5C 8024257C A2640099 */  sb        $a0, 0x99($s3)
.L80242580:
/* 170E60 80242580 82C20002 */  lb        $v0, 2($s6)
/* 170E64 80242584 28420006 */  slti      $v0, $v0, 6
/* 170E68 80242588 10400013 */  beqz      $v0, .L802425D8
/* 170E6C 8024258C 24020016 */   addiu    $v0, $zero, 0x16
/* 170E70 80242590 0C03A752 */  jal       is_ability_active
/* 170E74 80242594 2404001E */   addiu    $a0, $zero, 0x1e
/* 170E78 80242598 1040000F */  beqz      $v0, .L802425D8
/* 170E7C 8024259C 24020016 */   addiu    $v0, $zero, 0x16
/* 170E80 802425A0 92620099 */  lbu       $v0, 0x99($s3)
/* 170E84 802425A4 30420001 */  andi      $v0, $v0, 1
/* 170E88 802425A8 1440000B */  bnez      $v0, .L802425D8
/* 170E8C 802425AC 24020016 */   addiu    $v0, $zero, 0x16
/* 170E90 802425B0 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 170E94 802425B4 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 170E98 802425B8 3C040800 */  lui       $a0, 0x800
/* 170E9C 802425BC 8CA20004 */  lw        $v0, 4($a1)
/* 170EA0 802425C0 92630099 */  lbu       $v1, 0x99($s3)
/* 170EA4 802425C4 00441025 */  or        $v0, $v0, $a0
/* 170EA8 802425C8 34630002 */  ori       $v1, $v1, 2
/* 170EAC 802425CC ACA20004 */  sw        $v0, 4($a1)
/* 170EB0 802425D0 A2630099 */  sb        $v1, 0x99($s3)
.L802425D4:
/* 170EB4 802425D4 24020016 */  addiu     $v0, $zero, 0x16
.L802425D8:
/* 170EB8 802425D8 3C01800E */  lui       $at, %hi(gBattleState2)
/* 170EBC 802425DC AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
/* 170EC0 802425E0 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 170EC4 802425E4 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 170EC8 802425E8 24020016 */  addiu     $v0, $zero, 0x16
.L802425EC:
/* 170ECC 802425EC 146200A8 */  bne       $v1, $v0, .L80242890
/* 170ED0 802425F0 00000000 */   nop
/* 170ED4 802425F4 8E2201D8 */  lw        $v0, 0x1d8($s1)
/* 170ED8 802425F8 10400005 */  beqz      $v0, .L80242610
/* 170EDC 802425FC 00000000 */   nop
/* 170EE0 80242600 0C0B1059 */  jal       does_script_exist
/* 170EE4 80242604 8E2401E8 */   lw       $a0, 0x1e8($s1)
/* 170EE8 80242608 144000A1 */  bnez      $v0, .L80242890
/* 170EEC 8024260C 00000000 */   nop
.L80242610:
/* 170EF0 80242610 0C098D19 */  jal       btl_check_player_defeated
/* 170EF4 80242614 AE2001D8 */   sw       $zero, 0x1d8($s1)
/* 170EF8 80242618 1440011C */  bnez      $v0, .L80242A8C
/* 170EFC 8024261C 3C030C00 */   lui      $v1, 0xc00
/* 170F00 80242620 2404000E */  addiu     $a0, $zero, 0xe
/* 170F04 80242624 8E220000 */  lw        $v0, ($s1)
/* 170F08 80242628 3C01802A */  lui       $at, %hi(D_8029F254)
/* 170F0C 8024262C AC20F254 */  sw        $zero, %lo(D_8029F254)($at)
/* 170F10 80242630 A220021D */  sb        $zero, 0x21d($s1)
/* 170F14 80242634 00431025 */  or        $v0, $v0, $v1
/* 170F18 80242638 0C03A752 */  jal       is_ability_active
/* 170F1C 8024263C AE220000 */   sw       $v0, ($s1)
/* 170F20 80242640 10400015 */  beqz      $v0, .L80242698
/* 170F24 80242644 00000000 */   nop
/* 170F28 80242648 82220210 */  lb        $v0, 0x210($s1)
/* 170F2C 8024264C 10400002 */  beqz      $v0, .L80242658
/* 170F30 80242650 24020001 */   addiu    $v0, $zero, 1
/* 170F34 80242654 A2220211 */  sb        $v0, 0x211($s1)
.L80242658:
/* 170F38 80242658 82220212 */  lb        $v0, 0x212($s1)
/* 170F3C 8024265C 10400002 */  beqz      $v0, .L80242668
/* 170F40 80242660 24020001 */   addiu    $v0, $zero, 1
/* 170F44 80242664 A2220213 */  sb        $v0, 0x213($s1)
.L80242668:
/* 170F48 80242668 82220214 */  lb        $v0, 0x214($s1)
/* 170F4C 8024266C 10400002 */  beqz      $v0, .L80242678
/* 170F50 80242670 24020001 */   addiu    $v0, $zero, 1
/* 170F54 80242674 A2220215 */  sb        $v0, 0x215($s1)
.L80242678:
/* 170F58 80242678 82220216 */  lb        $v0, 0x216($s1)
/* 170F5C 8024267C 10400002 */  beqz      $v0, .L80242688
/* 170F60 80242680 24020001 */   addiu    $v0, $zero, 1
/* 170F64 80242684 A2220217 */  sb        $v0, 0x217($s1)
.L80242688:
/* 170F68 80242688 82220218 */  lb        $v0, 0x218($s1)
/* 170F6C 8024268C 10400002 */  beqz      $v0, .L80242698
/* 170F70 80242690 24020001 */   addiu    $v0, $zero, 1
/* 170F74 80242694 A2220219 */  sb        $v0, 0x219($s1)
.L80242698:
/* 170F78 80242698 82220214 */  lb        $v0, 0x214($s1)
/* 170F7C 8024269C 1040000C */  beqz      $v0, .L802426D0
/* 170F80 802426A0 00000000 */   nop
/* 170F84 802426A4 92220215 */  lbu       $v0, 0x215($s1)
/* 170F88 802426A8 2442FFFF */  addiu     $v0, $v0, -1
/* 170F8C 802426AC A2220215 */  sb        $v0, 0x215($s1)
/* 170F90 802426B0 00021600 */  sll       $v0, $v0, 0x18
/* 170F94 802426B4 1C400058 */  bgtz      $v0, .L80242818
/* 170F98 802426B8 0000902D */   daddu    $s2, $zero, $zero
/* 170F9C 802426BC A2200214 */  sb        $zero, 0x214($s1)
/* 170FA0 802426C0 0C09C596 */  jal       dispatch_event_player
/* 170FA4 802426C4 24040031 */   addiu    $a0, $zero, 0x31
/* 170FA8 802426C8 08090A06 */  j         .L80242818
/* 170FAC 802426CC 0000902D */   daddu    $s2, $zero, $zero
.L802426D0:
/* 170FB0 802426D0 0C03A752 */  jal       is_ability_active
/* 170FB4 802426D4 24040013 */   addiu    $a0, $zero, 0x13
/* 170FB8 802426D8 1440000D */  bnez      $v0, .L80242710
/* 170FBC 802426DC 00000000 */   nop
/* 170FC0 802426E0 82220212 */  lb        $v0, 0x212($s1)
/* 170FC4 802426E4 1040000A */  beqz      $v0, .L80242710
/* 170FC8 802426E8 00000000 */   nop
/* 170FCC 802426EC 92220213 */  lbu       $v0, 0x213($s1)
/* 170FD0 802426F0 2442FFFF */  addiu     $v0, $v0, -1
/* 170FD4 802426F4 A2220213 */  sb        $v0, 0x213($s1)
/* 170FD8 802426F8 00021600 */  sll       $v0, $v0, 0x18
/* 170FDC 802426FC 1C400004 */  bgtz      $v0, .L80242710
/* 170FE0 80242700 00000000 */   nop
/* 170FE4 80242704 86240436 */  lh        $a0, 0x436($s1)
/* 170FE8 80242708 0C011E68 */  jal       remove_status_icon_static
/* 170FEC 8024270C A2200212 */   sb       $zero, 0x212($s1)
.L80242710:
/* 170FF0 80242710 82220218 */  lb        $v0, 0x218($s1)
/* 170FF4 80242714 10400010 */  beqz      $v0, .L80242758
/* 170FF8 80242718 00000000 */   nop
/* 170FFC 8024271C 92220219 */  lbu       $v0, 0x219($s1)
/* 171000 80242720 2442FFFF */  addiu     $v0, $v0, -1
/* 171004 80242724 A2220219 */  sb        $v0, 0x219($s1)
/* 171008 80242728 8E820000 */  lw        $v0, ($s4)
/* 17100C 8024272C 34420100 */  ori       $v0, $v0, 0x100
/* 171010 80242730 AE820000 */  sw        $v0, ($s4)
/* 171014 80242734 82220219 */  lb        $v0, 0x219($s1)
/* 171018 80242738 1C400007 */  bgtz      $v0, .L80242758
/* 17101C 8024273C 2403FEFF */   addiu    $v1, $zero, -0x101
/* 171020 80242740 A2200218 */  sb        $zero, 0x218($s1)
/* 171024 80242744 8E820000 */  lw        $v0, ($s4)
/* 171028 80242748 00431024 */  and       $v0, $v0, $v1
/* 17102C 8024274C AE820000 */  sw        $v0, ($s4)
/* 171030 80242750 0C011EAA */  jal       remove_status_icon_transparent
/* 171034 80242754 86240436 */   lh       $a0, 0x436($s1)
.L80242758:
/* 171038 80242758 82220210 */  lb        $v0, 0x210($s1)
/* 17103C 8024275C 1040001F */  beqz      $v0, .L802427DC
/* 171040 80242760 28420009 */   slti     $v0, $v0, 9
/* 171044 80242764 10400003 */  beqz      $v0, .L80242774
/* 171048 80242768 24020001 */   addiu    $v0, $zero, 1
/* 17104C 8024276C 3C01802A */  lui       $at, %hi(D_8029F254)
/* 171050 80242770 AC22F254 */  sw        $v0, %lo(D_8029F254)($at)
.L80242774:
/* 171054 80242774 24020014 */  addiu     $v0, $zero, 0x14
/* 171058 80242778 3C01802A */  lui       $at, %hi(D_8029F258)
/* 17105C 8024277C AC22F258 */  sw        $v0, %lo(D_8029F258)($at)
/* 171060 80242780 92220211 */  lbu       $v0, 0x211($s1)
/* 171064 80242784 2442FFFF */  addiu     $v0, $v0, -1
/* 171068 80242788 A2220211 */  sb        $v0, 0x211($s1)
/* 17106C 8024278C 00021600 */  sll       $v0, $v0, 0x18
/* 171070 80242790 1C400012 */  bgtz      $v0, .L802427DC
/* 171074 80242794 24020007 */   addiu    $v0, $zero, 7
/* 171078 80242798 82230210 */  lb        $v1, 0x210($s1)
/* 17107C 8024279C 14620009 */  bne       $v1, $v0, .L802427C4
/* 171080 802427A0 24040031 */   addiu    $a0, $zero, 0x31
/* 171084 802427A4 0C05272D */  jal       sfx_play_sound
/* 171088 802427A8 240400E7 */   addiu    $a0, $zero, 0xe7
/* 17108C 802427AC 8E230228 */  lw        $v1, 0x228($s1)
/* 171090 802427B0 8C620000 */  lw        $v0, ($v1)
/* 171094 802427B4 24040032 */  addiu     $a0, $zero, 0x32
/* 171098 802427B8 34420010 */  ori       $v0, $v0, 0x10
/* 17109C 802427BC AC620000 */  sw        $v0, ($v1)
/* 1710A0 802427C0 AE200228 */  sw        $zero, 0x228($s1)
.L802427C4:
/* 1710A4 802427C4 0C09C596 */  jal       dispatch_event_player
/* 1710A8 802427C8 00000000 */   nop
/* 1710AC 802427CC 86240436 */  lh        $a0, 0x436($s1)
/* 1710B0 802427D0 A2200210 */  sb        $zero, 0x210($s1)
/* 1710B4 802427D4 0C011E26 */  jal       remove_status_icon_debuff
/* 1710B8 802427D8 A2200211 */   sb       $zero, 0x211($s1)
.L802427DC:
/* 1710BC 802427DC 92220211 */  lbu       $v0, 0x211($s1)
/* 1710C0 802427E0 82300217 */  lb        $s0, 0x217($s1)
/* 1710C4 802427E4 A2220217 */  sb        $v0, 0x217($s1)
/* 1710C8 802427E8 00021600 */  sll       $v0, $v0, 0x18
/* 1710CC 802427EC 00021603 */  sra       $v0, $v0, 0x18
/* 1710D0 802427F0 5C40FF2C */  bgtzl     $v0, .L802424A4
/* 1710D4 802427F4 2402000D */   addiu    $v0, $zero, 0xd
/* 1710D8 802427F8 12020007 */  beq       $s0, $v0, .L80242818
/* 1710DC 802427FC 0000902D */   daddu    $s2, $zero, $zero
/* 1710E0 80242800 8E220440 */  lw        $v0, 0x440($s1)
/* 1710E4 80242804 A2200216 */  sb        $zero, 0x216($s1)
/* 1710E8 80242808 A2200217 */  sb        $zero, 0x217($s1)
/* 1710EC 8024280C 8C42000C */  lw        $v0, 0xc($v0)
/* 1710F0 80242810 AC40003C */  sw        $zero, 0x3c($v0)
.L80242814:
/* 1710F4 80242814 0000902D */  daddu     $s2, $zero, $zero
.L80242818:
/* 1710F8 80242818 3C150C00 */  lui       $s5, 0xc00
/* 1710FC 8024281C 24140014 */  addiu     $s4, $zero, 0x14
/* 171100 80242820 0260802D */  daddu     $s0, $s3, $zero
.L80242824:
/* 171104 80242824 8E0300E0 */  lw        $v1, 0xe0($s0)
/* 171108 80242828 50600013 */  beql      $v1, $zero, .L80242878
/* 17110C 8024282C 26520001 */   addiu    $s2, $s2, 1
/* 171110 80242830 8C620000 */  lw        $v0, ($v1)
/* 171114 80242834 00551025 */  or        $v0, $v0, $s5
/* 171118 80242838 AC620000 */  sw        $v0, ($v1)
/* 17111C 8024283C 80620224 */  lb        $v0, 0x224($v1)
/* 171120 80242840 90640224 */  lbu       $a0, 0x224($v1)
/* 171124 80242844 5040000C */  beql      $v0, $zero, .L80242878
/* 171128 80242848 26520001 */   addiu    $s2, $s2, 1
/* 17112C 8024284C 2482FFFF */  addiu     $v0, $a0, -1
/* 171130 80242850 A0620224 */  sb        $v0, 0x224($v1)
/* 171134 80242854 00021600 */  sll       $v0, $v0, 0x18
/* 171138 80242858 54400007 */  bnel      $v0, $zero, .L80242878
/* 17113C 8024285C 26520001 */   addiu    $s2, $s2, 1
/* 171140 80242860 84640436 */  lh        $a0, 0x436($v1)
/* 171144 80242864 0C011EE1 */  jal       remove_status_icon_chillout
/* 171148 80242868 A0600223 */   sb       $zero, 0x223($v1)
/* 17114C 8024286C 3C01802A */  lui       $at, %hi(D_8029F258)
/* 171150 80242870 AC34F258 */  sw        $s4, %lo(D_8029F258)($at)
/* 171154 80242874 26520001 */  addiu     $s2, $s2, 1
.L80242878:
/* 171158 80242878 2A420018 */  slti      $v0, $s2, 0x18
/* 17115C 8024287C 1440FFE9 */  bnez      $v0, .L80242824
/* 171160 80242880 26100004 */   addiu    $s0, $s0, 4
/* 171164 80242884 24020001 */  addiu     $v0, $zero, 1
/* 171168 80242888 3C01800E */  lui       $at, %hi(gBattleState2)
/* 17116C 8024288C AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L80242890:
/* 171170 80242890 3C12800E */  lui       $s2, %hi(gBattleState2)
/* 171174 80242894 8E52C4DC */  lw        $s2, %lo(gBattleState2)($s2)
/* 171178 80242898 24020001 */  addiu     $v0, $zero, 1
/* 17117C 8024289C 16420051 */  bne       $s2, $v0, .L802429E4
/* 171180 802428A0 00000000 */   nop
/* 171184 802428A4 0C098D0D */  jal       btl_check_enemies_defeated
/* 171188 802428A8 00000000 */   nop
/* 17118C 802428AC 14400077 */  bnez      $v0, .L80242A8C
/* 171190 802428B0 24100001 */   addiu    $s0, $zero, 1
/* 171194 802428B4 826200AE */  lb        $v0, 0xae($s3)
/* 171198 802428B8 926300AE */  lbu       $v1, 0xae($s3)
/* 17119C 802428BC 04400015 */  bltz      $v0, .L80242914
/* 1711A0 802428C0 A260008C */   sb       $zero, 0x8c($s3)
/* 1711A4 802428C4 2462FFFF */  addiu     $v0, $v1, -1
/* 1711A8 802428C8 A26200AE */  sb        $v0, 0xae($s3)
/* 1711AC 802428CC 00021600 */  sll       $v0, $v0, 0x18
/* 1711B0 802428D0 00021603 */  sra       $v0, $v0, 0x18
/* 1711B4 802428D4 2403FFFF */  addiu     $v1, $zero, -1
/* 1711B8 802428D8 1443000E */  bne       $v0, $v1, .L80242914
/* 1711BC 802428DC 2405000A */   addiu    $a1, $zero, 0xa
/* 1711C0 802428E0 3C048029 */  lui       $a0, %hi(RegainAbility)
/* 1711C4 802428E4 24849110 */  addiu     $a0, $a0, %lo(RegainAbility)
/* 1711C8 802428E8 0C0B0CF8 */  jal       start_script
/* 1711CC 802428EC 0000302D */   daddu    $a2, $zero, $zero
/* 1711D0 802428F0 0040182D */  daddu     $v1, $v0, $zero
/* 1711D4 802428F4 AE2301D4 */  sw        $v1, 0x1d4($s1)
/* 1711D8 802428F8 8C620144 */  lw        $v0, 0x144($v1)
/* 1711DC 802428FC AE2201E4 */  sw        $v0, 0x1e4($s1)
/* 1711E0 80242900 AC700084 */  sw        $s0, 0x84($v1)
/* 1711E4 80242904 24100009 */  addiu     $s0, $zero, 9
/* 1711E8 80242908 AC600148 */  sw        $zero, 0x148($v1)
/* 1711EC 8024290C AC7200AC */  sw        $s2, 0xac($v1)
/* 1711F0 80242910 A272008C */  sb        $s2, 0x8c($s3)
.L80242914:
/* 1711F4 80242914 826200AF */  lb        $v0, 0xaf($s3)
/* 1711F8 80242918 926300AF */  lbu       $v1, 0xaf($s3)
/* 1711FC 8024291C 04400015 */  bltz      $v0, .L80242974
/* 171200 80242920 2462FFFF */   addiu    $v0, $v1, -1
/* 171204 80242924 A26200AF */  sb        $v0, 0xaf($s3)
/* 171208 80242928 00021600 */  sll       $v0, $v0, 0x18
/* 17120C 8024292C 00021603 */  sra       $v0, $v0, 0x18
/* 171210 80242930 2403FFFF */  addiu     $v1, $zero, -1
/* 171214 80242934 1443000F */  bne       $v0, $v1, .L80242974
/* 171218 80242938 2405000A */   addiu    $a1, $zero, 0xa
/* 17121C 8024293C 3C048029 */  lui       $a0, %hi(RegainAbility)
/* 171220 80242940 24849110 */  addiu     $a0, $a0, %lo(RegainAbility)
/* 171224 80242944 0C0B0CF8 */  jal       start_script
/* 171228 80242948 0000302D */   daddu    $a2, $zero, $zero
/* 17122C 8024294C 0040182D */  daddu     $v1, $v0, $zero
/* 171230 80242950 AE2301D4 */  sw        $v1, 0x1d4($s1)
/* 171234 80242954 8C620144 */  lw        $v0, 0x144($v1)
/* 171238 80242958 AE2201E4 */  sw        $v0, 0x1e4($s1)
/* 17123C 8024295C AC700084 */  sw        $s0, 0x84($v1)
/* 171240 80242960 26100008 */  addiu     $s0, $s0, 8
/* 171244 80242964 24020001 */  addiu     $v0, $zero, 1
/* 171248 80242968 AC600148 */  sw        $zero, 0x148($v1)
/* 17124C 8024296C AC6000AC */  sw        $zero, 0xac($v1)
/* 171250 80242970 A262008C */  sb        $v0, 0x8c($s3)
.L80242974:
/* 171254 80242974 826200B0 */  lb        $v0, 0xb0($s3)
/* 171258 80242978 926300B0 */  lbu       $v1, 0xb0($s3)
/* 17125C 8024297C 04400016 */  bltz      $v0, .L802429D8
/* 171260 80242980 2462FFFF */   addiu    $v0, $v1, -1
/* 171264 80242984 A26200B0 */  sb        $v0, 0xb0($s3)
/* 171268 80242988 00021600 */  sll       $v0, $v0, 0x18
/* 17126C 8024298C 00021603 */  sra       $v0, $v0, 0x18
/* 171270 80242990 2403FFFF */  addiu     $v1, $zero, -1
/* 171274 80242994 14430011 */  bne       $v0, $v1, .L802429DC
/* 171278 80242998 2402001E */   addiu    $v0, $zero, 0x1e
/* 17127C 8024299C 3C048029 */  lui       $a0, %hi(RegainAbility)
/* 171280 802429A0 24849110 */  addiu     $a0, $a0, %lo(RegainAbility)
/* 171284 802429A4 2405000A */  addiu     $a1, $zero, 0xa
/* 171288 802429A8 0C0B0CF8 */  jal       start_script
/* 17128C 802429AC 0000302D */   daddu    $a2, $zero, $zero
/* 171290 802429B0 0040182D */  daddu     $v1, $v0, $zero
/* 171294 802429B4 AE2301D4 */  sw        $v1, 0x1d4($s1)
/* 171298 802429B8 8C620144 */  lw        $v0, 0x144($v1)
/* 17129C 802429BC AE2201E4 */  sw        $v0, 0x1e4($s1)
/* 1712A0 802429C0 24020002 */  addiu     $v0, $zero, 2
/* 1712A4 802429C4 AC6200AC */  sw        $v0, 0xac($v1)
/* 1712A8 802429C8 24020001 */  addiu     $v0, $zero, 1
/* 1712AC 802429CC AC600148 */  sw        $zero, 0x148($v1)
/* 1712B0 802429D0 AC700084 */  sw        $s0, 0x84($v1)
/* 1712B4 802429D4 A262008C */  sb        $v0, 0x8c($s3)
.L802429D8:
/* 1712B8 802429D8 2402001E */  addiu     $v0, $zero, 0x1e
.L802429DC:
/* 1712BC 802429DC 3C01800E */  lui       $at, %hi(gBattleState2)
/* 1712C0 802429E0 AC22C4DC */  sw        $v0, %lo(gBattleState2)($at)
.L802429E4:
/* 1712C4 802429E4 3C03800E */  lui       $v1, %hi(gBattleState2)
/* 1712C8 802429E8 8C63C4DC */  lw        $v1, %lo(gBattleState2)($v1)
/* 1712CC 802429EC 2402001E */  addiu     $v0, $zero, 0x1e
/* 1712D0 802429F0 14620026 */  bne       $v1, $v0, .L80242A8C
/* 1712D4 802429F4 00000000 */   nop
/* 1712D8 802429F8 8E2201D8 */  lw        $v0, 0x1d8($s1)
/* 1712DC 802429FC 10400005 */  beqz      $v0, .L80242A14
/* 1712E0 80242A00 00000000 */   nop
/* 1712E4 80242A04 0C0B1059 */  jal       does_script_exist
/* 1712E8 80242A08 8E2401E8 */   lw       $a0, 0x1e8($s1)
/* 1712EC 80242A0C 1440001F */  bnez      $v0, .L80242A8C
/* 1712F0 80242A10 00000000 */   nop
.L80242A14:
/* 1712F4 80242A14 0C098D19 */  jal       btl_check_player_defeated
/* 1712F8 80242A18 AE2001D8 */   sw       $zero, 0x1d8($s1)
/* 1712FC 80242A1C 1440001B */  bnez      $v0, .L80242A8C
/* 171300 80242A20 00000000 */   nop
/* 171304 80242A24 0C098D0D */  jal       btl_check_enemies_defeated
/* 171308 80242A28 00000000 */   nop
/* 17130C 80242A2C 14400017 */  bnez      $v0, .L80242A8C
/* 171310 80242A30 00000000 */   nop
/* 171314 80242A34 3C03802A */  lui       $v1, %hi(D_8029F258)
/* 171318 80242A38 2463F258 */  addiu     $v1, $v1, %lo(D_8029F258)
/* 17131C 80242A3C 8C620000 */  lw        $v0, ($v1)
/* 171320 80242A40 10400003 */  beqz      $v0, .L80242A50
/* 171324 80242A44 2442FFFF */   addiu    $v0, $v0, -1
/* 171328 80242A48 08090AA3 */  j         .L80242A8C
/* 17132C 80242A4C AC620000 */   sw       $v0, ($v1)
.L80242A50:
/* 171330 80242A50 3C02802A */  lui       $v0, %hi(D_8029F254)
/* 171334 80242A54 8C42F254 */  lw        $v0, %lo(D_8029F254)($v0)
/* 171338 80242A58 14400005 */  bnez      $v0, .L80242A70
/* 17133C 80242A5C 00000000 */   nop
/* 171340 80242A60 0C090464 */  jal       btl_set_state
/* 171344 80242A64 2404000A */   addiu    $a0, $zero, 0xa
/* 171348 80242A68 08090AA3 */  j         .L80242A8C
/* 17134C 80242A6C 00000000 */   nop
.L80242A70:
/* 171350 80242A70 0C090464 */  jal       btl_set_state
/* 171354 80242A74 24040008 */   addiu    $a0, $zero, 8
/* 171358 80242A78 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 17135C 80242A7C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 171360 80242A80 8C620004 */  lw        $v0, 4($v1)
/* 171364 80242A84 34420002 */  ori       $v0, $v0, 2
/* 171368 80242A88 AC620004 */  sw        $v0, 4($v1)
.L80242A8C:
/* 17136C 80242A8C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 171370 80242A90 8FB60030 */  lw        $s6, 0x30($sp)
/* 171374 80242A94 8FB5002C */  lw        $s5, 0x2c($sp)
/* 171378 80242A98 8FB40028 */  lw        $s4, 0x28($sp)
/* 17137C 80242A9C 8FB30024 */  lw        $s3, 0x24($sp)
/* 171380 80242AA0 8FB20020 */  lw        $s2, 0x20($sp)
/* 171384 80242AA4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 171388 80242AA8 8FB00018 */  lw        $s0, 0x18($sp)
/* 17138C 80242AAC D7B80048 */  ldc1      $f24, 0x48($sp)
/* 171390 80242AB0 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 171394 80242AB4 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 171398 80242AB8 03E00008 */  jr        $ra
/* 17139C 80242ABC 27BD0050 */   addiu    $sp, $sp, 0x50
