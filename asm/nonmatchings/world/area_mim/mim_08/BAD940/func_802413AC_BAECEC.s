.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413AC_BAECEC
/* BAECEC 802413AC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BAECF0 802413B0 AFB40040 */  sw        $s4, 0x40($sp)
/* BAECF4 802413B4 0080A02D */  daddu     $s4, $a0, $zero
/* BAECF8 802413B8 AFBF0048 */  sw        $ra, 0x48($sp)
/* BAECFC 802413BC AFB50044 */  sw        $s5, 0x44($sp)
/* BAED00 802413C0 AFB3003C */  sw        $s3, 0x3c($sp)
/* BAED04 802413C4 AFB20038 */  sw        $s2, 0x38($sp)
/* BAED08 802413C8 AFB10034 */  sw        $s1, 0x34($sp)
/* BAED0C 802413CC AFB00030 */  sw        $s0, 0x30($sp)
/* BAED10 802413D0 8E920148 */  lw        $s2, 0x148($s4)
/* BAED14 802413D4 86440008 */  lh        $a0, 8($s2)
/* BAED18 802413D8 8E90000C */  lw        $s0, 0xc($s4)
/* BAED1C 802413DC 0C00EABB */  jal       get_npc_unsafe
/* BAED20 802413E0 00A0882D */   daddu    $s1, $a1, $zero
/* BAED24 802413E4 0280202D */  daddu     $a0, $s4, $zero
/* BAED28 802413E8 8E050000 */  lw        $a1, ($s0)
/* BAED2C 802413EC 0C0B1EAF */  jal       get_variable
/* BAED30 802413F0 0040A82D */   daddu    $s5, $v0, $zero
/* BAED34 802413F4 AFA00010 */  sw        $zero, 0x10($sp)
/* BAED38 802413F8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BAED3C 802413FC 8C630030 */  lw        $v1, 0x30($v1)
/* BAED40 80241400 AFA30014 */  sw        $v1, 0x14($sp)
/* BAED44 80241404 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BAED48 80241408 8C63001C */  lw        $v1, 0x1c($v1)
/* BAED4C 8024140C AFA30018 */  sw        $v1, 0x18($sp)
/* BAED50 80241410 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BAED54 80241414 8C630024 */  lw        $v1, 0x24($v1)
/* BAED58 80241418 AFA3001C */  sw        $v1, 0x1c($sp)
/* BAED5C 8024141C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BAED60 80241420 8C630028 */  lw        $v1, 0x28($v1)
/* BAED64 80241424 27B30010 */  addiu     $s3, $sp, 0x10
/* BAED68 80241428 AFA30020 */  sw        $v1, 0x20($sp)
/* BAED6C 8024142C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BAED70 80241430 3C0142F0 */  lui       $at, 0x42f0
/* BAED74 80241434 44810000 */  mtc1      $at, $f0
/* BAED78 80241438 8C63002C */  lw        $v1, 0x2c($v1)
/* BAED7C 8024143C 0040802D */  daddu     $s0, $v0, $zero
/* BAED80 80241440 E7A00028 */  swc1      $f0, 0x28($sp)
/* BAED84 80241444 A7A0002C */  sh        $zero, 0x2c($sp)
/* BAED88 80241448 12200006 */  beqz      $s1, .L80241464
/* BAED8C 8024144C AFA30024 */   sw       $v1, 0x24($sp)
/* BAED90 80241450 02A0202D */  daddu     $a0, $s5, $zero
/* BAED94 80241454 0240282D */  daddu     $a1, $s2, $zero
/* BAED98 80241458 0280302D */  daddu     $a2, $s4, $zero
/* BAED9C 8024145C 0C0904A2 */  jal       func_80241288_BAEBC8
/* BAEDA0 80241460 0200382D */   daddu    $a3, $s0, $zero
.L80241464:
/* BAEDA4 80241464 2402FFFE */  addiu     $v0, $zero, -2
/* BAEDA8 80241468 A2A200AB */  sb        $v0, 0xab($s5)
/* BAEDAC 8024146C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BAEDB0 80241470 30620004 */  andi      $v0, $v1, 4
/* BAEDB4 80241474 10400007 */  beqz      $v0, .L80241494
/* BAEDB8 80241478 00000000 */   nop      
/* BAEDBC 8024147C 824200B4 */  lb        $v0, 0xb4($s2)
/* BAEDC0 80241480 1440003C */  bnez      $v0, .L80241574
/* BAEDC4 80241484 0000102D */   daddu    $v0, $zero, $zero
/* BAEDC8 80241488 2402FFFB */  addiu     $v0, $zero, -5
/* BAEDCC 8024148C 00621024 */  and       $v0, $v1, $v0
/* BAEDD0 80241490 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241494:
/* BAEDD4 80241494 8E830070 */  lw        $v1, 0x70($s4)
/* BAEDD8 80241498 2C62000F */  sltiu     $v0, $v1, 0xf
/* BAEDDC 8024149C 10400034 */  beqz      $v0, .L80241570
/* BAEDE0 802414A0 00031080 */   sll      $v0, $v1, 2
/* BAEDE4 802414A4 3C018024 */  lui       $at, %hi(D_802452B8)
/* BAEDE8 802414A8 00220821 */  addu      $at, $at, $v0
/* BAEDEC 802414AC 8C2252B8 */  lw        $v0, %lo(D_802452B8)($at)
/* BAEDF0 802414B0 00400008 */  jr        $v0
/* BAEDF4 802414B4 00000000 */   nop      
/* BAEDF8 802414B8 0280202D */  daddu     $a0, $s4, $zero
/* BAEDFC 802414BC 0200282D */  daddu     $a1, $s0, $zero
/* BAEE00 802414C0 0C090028 */  jal       func_802400A0_BAD9E0
/* BAEE04 802414C4 0260302D */   daddu    $a2, $s3, $zero
/* BAEE08 802414C8 0280202D */  daddu     $a0, $s4, $zero
/* BAEE0C 802414CC 0200282D */  daddu     $a1, $s0, $zero
/* BAEE10 802414D0 0C090094 */  jal       func_80240250_BADB90
/* BAEE14 802414D4 0260302D */   daddu    $a2, $s3, $zero
/* BAEE18 802414D8 0809055D */  j         .L80241574
/* BAEE1C 802414DC 0000102D */   daddu    $v0, $zero, $zero
/* BAEE20 802414E0 0280202D */  daddu     $a0, $s4, $zero
/* BAEE24 802414E4 0200282D */  daddu     $a1, $s0, $zero
/* BAEE28 802414E8 0C09021E */  jal       func_80240878_BAE1B8
/* BAEE2C 802414EC 0260302D */   daddu    $a2, $s3, $zero
/* BAEE30 802414F0 0280202D */  daddu     $a0, $s4, $zero
/* BAEE34 802414F4 0200282D */  daddu     $a1, $s0, $zero
/* BAEE38 802414F8 0C09024E */  jal       func_80240938_BAE278
/* BAEE3C 802414FC 0260302D */   daddu    $a2, $s3, $zero
/* BAEE40 80241500 0809055D */  j         .L80241574
/* BAEE44 80241504 0000102D */   daddu    $v0, $zero, $zero
/* BAEE48 80241508 0280202D */  daddu     $a0, $s4, $zero
/* BAEE4C 8024150C 0200282D */  daddu     $a1, $s0, $zero
/* BAEE50 80241510 0C09031F */  jal       func_80240C7C_BAE5BC
/* BAEE54 80241514 0260302D */   daddu    $a2, $s3, $zero
/* BAEE58 80241518 0280202D */  daddu     $a0, $s4, $zero
/* BAEE5C 8024151C 0200282D */  daddu     $a1, $s0, $zero
/* BAEE60 80241520 0C09033D */  jal       func_80240CF4_BAE634
/* BAEE64 80241524 0260302D */   daddu    $a2, $s3, $zero
/* BAEE68 80241528 0809055D */  j         .L80241574
/* BAEE6C 8024152C 0000102D */   daddu    $v0, $zero, $zero
/* BAEE70 80241530 0280202D */  daddu     $a0, $s4, $zero
/* BAEE74 80241534 0200282D */  daddu     $a1, $s0, $zero
/* BAEE78 80241538 0C090358 */  jal       func_80240D60_BAE6A0
/* BAEE7C 8024153C 0260302D */   daddu    $a2, $s3, $zero
/* BAEE80 80241540 0809055D */  j         .L80241574
/* BAEE84 80241544 0000102D */   daddu    $v0, $zero, $zero
/* BAEE88 80241548 0280202D */  daddu     $a0, $s4, $zero
/* BAEE8C 8024154C 0200282D */  daddu     $a1, $s0, $zero
/* BAEE90 80241550 0C0903A5 */  jal       func_80240E94_BAE7D4
/* BAEE94 80241554 0260302D */   daddu    $a2, $s3, $zero
/* BAEE98 80241558 0809055D */  j         .L80241574
/* BAEE9C 8024155C 0000102D */   daddu    $v0, $zero, $zero
/* BAEEA0 80241560 0280202D */  daddu     $a0, $s4, $zero
/* BAEEA4 80241564 0200282D */  daddu     $a1, $s0, $zero
/* BAEEA8 80241568 0C0903BE */  jal       func_80240EF8_BAE838
/* BAEEAC 8024156C 0260302D */   daddu    $a2, $s3, $zero
.L80241570:
/* BAEEB0 80241570 0000102D */  daddu     $v0, $zero, $zero
.L80241574:
/* BAEEB4 80241574 8FBF0048 */  lw        $ra, 0x48($sp)
/* BAEEB8 80241578 8FB50044 */  lw        $s5, 0x44($sp)
/* BAEEBC 8024157C 8FB40040 */  lw        $s4, 0x40($sp)
/* BAEEC0 80241580 8FB3003C */  lw        $s3, 0x3c($sp)
/* BAEEC4 80241584 8FB20038 */  lw        $s2, 0x38($sp)
/* BAEEC8 80241588 8FB10034 */  lw        $s1, 0x34($sp)
/* BAEECC 8024158C 8FB00030 */  lw        $s0, 0x30($sp)
/* BAEED0 80241590 03E00008 */  jr        $ra
/* BAEED4 80241594 27BD0050 */   addiu    $sp, $sp, 0x50
