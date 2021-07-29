.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029D850
.word L80270B5C_19F43C, L80270BA8_19F488, L80270BF4_19F4D4, L80270C1C_19F4FC, L80270C48_19F528, 0

.section .text

glabel ElectrifyActor
/* 19F23C 8027095C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19F240 80270960 AFB20020 */  sw        $s2, 0x20($sp)
/* 19F244 80270964 0080902D */  daddu     $s2, $a0, $zero
/* 19F248 80270968 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19F24C 8027096C AFB1001C */  sw        $s1, 0x1c($sp)
/* 19F250 80270970 AFB00018 */  sw        $s0, 0x18($sp)
/* 19F254 80270974 8E51000C */  lw        $s1, 0xc($s2)
/* 19F258 80270978 54A00001 */  bnel      $a1, $zero, .L80270980
/* 19F25C 8027097C AE400070 */   sw       $zero, 0x70($s2)
.L80270980:
/* 19F260 80270980 8E420070 */  lw        $v0, 0x70($s2)
/* 19F264 80270984 1440002D */  bnez      $v0, .L80270A3C
/* 19F268 80270988 00000000 */   nop
/* 19F26C 8027098C 8E250000 */  lw        $a1, ($s1)
/* 19F270 80270990 26310004 */  addiu     $s1, $s1, 4
/* 19F274 80270994 0C0B1EAF */  jal       get_variable
/* 19F278 80270998 0240202D */   daddu    $a0, $s2, $zero
/* 19F27C 8027099C 0040802D */  daddu     $s0, $v0, $zero
/* 19F280 802709A0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19F284 802709A4 16020002 */  bne       $s0, $v0, .L802709B0
/* 19F288 802709A8 00000000 */   nop
/* 19F28C 802709AC 8E500148 */  lw        $s0, 0x148($s2)
.L802709B0:
/* 19F290 802709B0 8E250000 */  lw        $a1, ($s1)
/* 19F294 802709B4 0C0B1EAF */  jal       get_variable
/* 19F298 802709B8 0240202D */   daddu    $a0, $s2, $zero
/* 19F29C 802709BC 0040882D */  daddu     $s1, $v0, $zero
/* 19F2A0 802709C0 0C09A75B */  jal       get_actor
/* 19F2A4 802709C4 0200202D */   daddu    $a0, $s0, $zero
/* 19F2A8 802709C8 0040802D */  daddu     $s0, $v0, $zero
/* 19F2AC 802709CC 24040008 */  addiu     $a0, $zero, 8
/* 19F2B0 802709D0 AE500074 */  sw        $s0, 0x74($s2)
/* 19F2B4 802709D4 0C093903 */  jal       func_8024E40C
/* 19F2B8 802709D8 AE510078 */   sw       $s1, 0x78($s2)
/* 19F2BC 802709DC 0C093978 */  jal       btl_cam_set_zoffset
/* 19F2C0 802709E0 2404000C */   addiu    $a0, $zero, 0xc
/* 19F2C4 802709E4 86040192 */  lh        $a0, 0x192($s0)
/* 19F2C8 802709E8 0C09390F */  jal       btl_cam_target_actor
/* 19F2CC 802709EC 00000000 */   nop
/* 19F2D0 802709F0 0C093965 */  jal       btl_cam_set_zoom
/* 19F2D4 802709F4 240400FA */   addiu    $a0, $zero, 0xfa
/* 19F2D8 802709F8 0C093936 */  jal       btl_cam_move
/* 19F2DC 802709FC 2404000A */   addiu    $a0, $zero, 0xa
/* 19F2E0 80270A00 0C093983 */  jal       func_8024E60C
/* 19F2E4 80270A04 00000000 */   nop
/* 19F2E8 80270A08 8E020000 */  lw        $v0, ($s0)
/* 19F2EC 80270A0C 30420800 */  andi      $v0, $v0, 0x800
/* 19F2F0 80270A10 10400004 */  beqz      $v0, .L80270A24
/* 19F2F4 80270A14 24020001 */   addiu    $v0, $zero, 1
/* 19F2F8 80270A18 0C093978 */  jal       btl_cam_set_zoffset
/* 19F2FC 80270A1C 0000202D */   daddu    $a0, $zero, $zero
/* 19F300 80270A20 24020001 */  addiu     $v0, $zero, 1
.L80270A24:
/* 19F304 80270A24 3C01802A */  lui       $at, %hi(D_8029FBD4)
/* 19F308 80270A28 A022FBD4 */  sb        $v0, %lo(D_8029FBD4)($at)
/* 19F30C 80270A2C 24020005 */  addiu     $v0, $zero, 5
/* 19F310 80270A30 AE42007C */  sw        $v0, 0x7c($s2)
/* 19F314 80270A34 24020001 */  addiu     $v0, $zero, 1
/* 19F318 80270A38 AE420070 */  sw        $v0, 0x70($s2)
.L80270A3C:
/* 19F31C 80270A3C 0C09A75B */  jal       get_actor
/* 19F320 80270A40 8E440148 */   lw       $a0, 0x148($s2)
/* 19F324 80270A44 8E500074 */  lw        $s0, 0x74($s2)
/* 19F328 80270A48 8E510078 */  lw        $s1, 0x78($s2)
/* 19F32C 80270A4C 86020150 */  lh        $v0, 0x150($s0)
/* 19F330 80270A50 8E030000 */  lw        $v1, ($s0)
/* 19F334 80270A54 C6000144 */  lwc1      $f0, 0x144($s0)
/* 19F338 80270A58 44821000 */  mtc1      $v0, $f2
/* 19F33C 80270A5C 00000000 */  nop
/* 19F340 80270A60 468010A0 */  cvt.s.w   $f2, $f2
/* 19F344 80270A64 30620800 */  andi      $v0, $v1, 0x800
/* 19F348 80270A68 1040000E */  beqz      $v0, .L80270AA4
/* 19F34C 80270A6C 46020180 */   add.s    $f6, $f0, $f2
/* 19F350 80270A70 86020152 */  lh        $v0, 0x152($s0)
/* 19F354 80270A74 C6020148 */  lwc1      $f2, 0x148($s0)
/* 19F358 80270A78 44820000 */  mtc1      $v0, $f0
/* 19F35C 80270A7C 00000000 */  nop
/* 19F360 80270A80 46800020 */  cvt.s.w   $f0, $f0
/* 19F364 80270A84 92020191 */  lbu       $v0, 0x191($s0)
/* 19F368 80270A88 46001080 */  add.s     $f2, $f2, $f0
/* 19F36C 80270A8C 00021042 */  srl       $v0, $v0, 1
/* 19F370 80270A90 44820000 */  mtc1      $v0, $f0
/* 19F374 80270A94 00000000 */  nop
/* 19F378 80270A98 46800020 */  cvt.s.w   $f0, $f0
/* 19F37C 80270A9C 0809C2C4 */  j         .L80270B10
/* 19F380 80270AA0 46001101 */   sub.s    $f4, $f2, $f0
.L80270AA4:
/* 19F384 80270AA4 30628000 */  andi      $v0, $v1, 0x8000
/* 19F388 80270AA8 1440000E */  bnez      $v0, .L80270AE4
/* 19F38C 80270AAC 00000000 */   nop
/* 19F390 80270AB0 86020152 */  lh        $v0, 0x152($s0)
/* 19F394 80270AB4 C6020148 */  lwc1      $f2, 0x148($s0)
/* 19F398 80270AB8 44820000 */  mtc1      $v0, $f0
/* 19F39C 80270ABC 00000000 */  nop
/* 19F3A0 80270AC0 46800020 */  cvt.s.w   $f0, $f0
/* 19F3A4 80270AC4 92020191 */  lbu       $v0, 0x191($s0)
/* 19F3A8 80270AC8 46001080 */  add.s     $f2, $f2, $f0
/* 19F3AC 80270ACC 00021042 */  srl       $v0, $v0, 1
/* 19F3B0 80270AD0 44820000 */  mtc1      $v0, $f0
/* 19F3B4 80270AD4 00000000 */  nop
/* 19F3B8 80270AD8 46800020 */  cvt.s.w   $f0, $f0
/* 19F3BC 80270ADC 0809C2C4 */  j         .L80270B10
/* 19F3C0 80270AE0 46020100 */   add.s    $f4, $f0, $f2
.L80270AE4:
/* 19F3C4 80270AE4 86020152 */  lh        $v0, 0x152($s0)
/* 19F3C8 80270AE8 C6000148 */  lwc1      $f0, 0x148($s0)
/* 19F3CC 80270AEC 44821000 */  mtc1      $v0, $f2
/* 19F3D0 80270AF0 00000000 */  nop
/* 19F3D4 80270AF4 468010A0 */  cvt.s.w   $f2, $f2
/* 19F3D8 80270AF8 92020191 */  lbu       $v0, 0x191($s0)
/* 19F3DC 80270AFC 46020000 */  add.s     $f0, $f0, $f2
/* 19F3E0 80270B00 44821000 */  mtc1      $v0, $f2
/* 19F3E4 80270B04 00000000 */  nop
/* 19F3E8 80270B08 468010A0 */  cvt.s.w   $f2, $f2
/* 19F3EC 80270B0C 46020100 */  add.s     $f4, $f0, $f2
.L80270B10:
/* 19F3F0 80270B10 86020154 */  lh        $v0, 0x154($s0)
/* 19F3F4 80270B14 C600014C */  lwc1      $f0, 0x14c($s0)
/* 19F3F8 80270B18 44821000 */  mtc1      $v0, $f2
/* 19F3FC 80270B1C 00000000 */  nop
/* 19F400 80270B20 468010A0 */  cvt.s.w   $f2, $f2
/* 19F404 80270B24 46020000 */  add.s     $f0, $f0, $f2
/* 19F408 80270B28 8E420070 */  lw        $v0, 0x70($s2)
/* 19F40C 80270B2C 3C014120 */  lui       $at, 0x4120
/* 19F410 80270B30 44811000 */  mtc1      $at, $f2
/* 19F414 80270B34 2443FFFF */  addiu     $v1, $v0, -1
/* 19F418 80270B38 2C620005 */  sltiu     $v0, $v1, 5
/* 19F41C 80270B3C 10400052 */  beqz      $v0, .L80270C88
/* 19F420 80270B40 46020080 */   add.s    $f2, $f0, $f2
/* 19F424 80270B44 00031080 */  sll       $v0, $v1, 2
/* 19F428 80270B48 3C01802A */  lui       $at, %hi(jtbl_8029D850)
/* 19F42C 80270B4C 00220821 */  addu      $at, $at, $v0
/* 19F430 80270B50 8C22D850 */  lw        $v0, %lo(jtbl_8029D850)($at)
/* 19F434 80270B54 00400008 */  jr        $v0
/* 19F438 80270B58 00000000 */   nop
glabel L80270B5C_19F43C
/* 19F43C 80270B5C 8E42007C */  lw        $v0, 0x7c($s2)
/* 19F440 80270B60 1440003C */  bnez      $v0, .L80270C54
/* 19F444 80270B64 2442FFFF */   addiu    $v0, $v0, -1
/* 19F448 80270B68 24040008 */  addiu     $a0, $zero, 8
/* 19F44C 80270B6C 44053000 */  mfc1      $a1, $f6
/* 19F450 80270B70 44062000 */  mfc1      $a2, $f4
/* 19F454 80270B74 3C013F80 */  lui       $at, 0x3f80
/* 19F458 80270B78 44810000 */  mtc1      $at, $f0
/* 19F45C 80270B7C 44071000 */  mfc1      $a3, $f2
/* 19F460 80270B80 2410001E */  addiu     $s0, $zero, 0x1e
/* 19F464 80270B84 AFB00014 */  sw        $s0, 0x14($sp)
/* 19F468 80270B88 0C01C64C */  jal       playFX_57
/* 19F46C 80270B8C E7A00010 */   swc1     $f0, 0x10($sp)
/* 19F470 80270B90 0C0938F6 */  jal       func_8024E3D8
/* 19F474 80270B94 24040013 */   addiu    $a0, $zero, 0x13
/* 19F478 80270B98 24020002 */  addiu     $v0, $zero, 2
/* 19F47C 80270B9C AE50007C */  sw        $s0, 0x7c($s2)
/* 19F480 80270BA0 0809C322 */  j         .L80270C88
/* 19F484 80270BA4 AE420070 */   sw       $v0, 0x70($s2)
glabel L80270BA8_19F488
/* 19F488 80270BA8 8E42007C */  lw        $v0, 0x7c($s2)
/* 19F48C 80270BAC 14400029 */  bnez      $v0, .L80270C54
/* 19F490 80270BB0 2442FFFF */   addiu    $v0, $v0, -1
/* 19F494 80270BB4 0200202D */  daddu     $a0, $s0, $zero
/* 19F498 80270BB8 0C09DC58 */  jal       dispatch_event_actor
/* 19F49C 80270BBC 2405003F */   addiu    $a1, $zero, 0x3f
/* 19F4A0 80270BC0 0C093903 */  jal       func_8024E40C
/* 19F4A4 80270BC4 24040002 */   addiu    $a0, $zero, 2
/* 19F4A8 80270BC8 0C093936 */  jal       btl_cam_move
/* 19F4AC 80270BCC 2404000F */   addiu    $a0, $zero, 0xf
/* 19F4B0 80270BD0 0200202D */  daddu     $a0, $s0, $zero
/* 19F4B4 80270BD4 2405000B */  addiu     $a1, $zero, 0xb
/* 19F4B8 80270BD8 0C0997D0 */  jal       inflict_status
/* 19F4BC 80270BDC 0220302D */   daddu    $a2, $s1, $zero
/* 19F4C0 80270BE0 2402000F */  addiu     $v0, $zero, 0xf
/* 19F4C4 80270BE4 AE42007C */  sw        $v0, 0x7c($s2)
/* 19F4C8 80270BE8 24020003 */  addiu     $v0, $zero, 3
/* 19F4CC 80270BEC 0809C322 */  j         .L80270C88
/* 19F4D0 80270BF0 AE420070 */   sw       $v0, 0x70($s2)
glabel L80270BF4_19F4D4
/* 19F4D4 80270BF4 8E42007C */  lw        $v0, 0x7c($s2)
/* 19F4D8 80270BF8 14400016 */  bnez      $v0, .L80270C54
/* 19F4DC 80270BFC 2442FFFF */   addiu    $v0, $v0, -1
/* 19F4E0 80270C00 24040022 */  addiu     $a0, $zero, 0x22
/* 19F4E4 80270C04 2405003C */  addiu     $a1, $zero, 0x3c
/* 19F4E8 80270C08 0C093E81 */  jal       btl_show_variable_battle_message
/* 19F4EC 80270C0C 0220302D */   daddu    $a2, $s1, $zero
/* 19F4F0 80270C10 24020004 */  addiu     $v0, $zero, 4
/* 19F4F4 80270C14 0809C322 */  j         .L80270C88
/* 19F4F8 80270C18 AE420070 */   sw       $v0, 0x70($s2)
glabel L80270C1C_19F4FC
/* 19F4FC 80270C1C 0C093EAD */  jal       btl_is_popup_displayed
/* 19F500 80270C20 00000000 */   nop
/* 19F504 80270C24 14400019 */  bnez      $v0, .L80270C8C
/* 19F508 80270C28 0000102D */   daddu    $v0, $zero, $zero
/* 19F50C 80270C2C 0C093903 */  jal       func_8024E40C
/* 19F510 80270C30 24040002 */   addiu    $a0, $zero, 2
/* 19F514 80270C34 2402000A */  addiu     $v0, $zero, 0xa
/* 19F518 80270C38 AE42007C */  sw        $v0, 0x7c($s2)
/* 19F51C 80270C3C 24020005 */  addiu     $v0, $zero, 5
/* 19F520 80270C40 0809C322 */  j         .L80270C88
/* 19F524 80270C44 AE420070 */   sw       $v0, 0x70($s2)
glabel L80270C48_19F528
/* 19F528 80270C48 8E42007C */  lw        $v0, 0x7c($s2)
/* 19F52C 80270C4C 10400003 */  beqz      $v0, .L80270C5C
/* 19F530 80270C50 2442FFFF */   addiu    $v0, $v0, -1
.L80270C54:
/* 19F534 80270C54 0809C322 */  j         .L80270C88
/* 19F538 80270C58 AE42007C */   sw       $v0, 0x7c($s2)
.L80270C5C:
/* 19F53C 80270C5C 8E0201D8 */  lw        $v0, 0x1d8($s0)
/* 19F540 80270C60 10400005 */  beqz      $v0, .L80270C78
/* 19F544 80270C64 00000000 */   nop
/* 19F548 80270C68 0C0B1059 */  jal       does_script_exist
/* 19F54C 80270C6C 8E0401E8 */   lw       $a0, 0x1e8($s0)
/* 19F550 80270C70 14400006 */  bnez      $v0, .L80270C8C
/* 19F554 80270C74 0000102D */   daddu    $v0, $zero, $zero
.L80270C78:
/* 19F558 80270C78 3C01802A */  lui       $at, %hi(D_8029FBD4)
/* 19F55C 80270C7C A020FBD4 */  sb        $zero, %lo(D_8029FBD4)($at)
/* 19F560 80270C80 0809C323 */  j         .L80270C8C
/* 19F564 80270C84 24020002 */   addiu    $v0, $zero, 2
.L80270C88:
/* 19F568 80270C88 0000102D */  daddu     $v0, $zero, $zero
.L80270C8C:
/* 19F56C 80270C8C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19F570 80270C90 8FB20020 */  lw        $s2, 0x20($sp)
/* 19F574 80270C94 8FB1001C */  lw        $s1, 0x1c($sp)
/* 19F578 80270C98 8FB00018 */  lw        $s0, 0x18($sp)
/* 19F57C 80270C9C 03E00008 */  jr        $ra
/* 19F580 80270CA0 27BD0028 */   addiu    $sp, $sp, 0x28
