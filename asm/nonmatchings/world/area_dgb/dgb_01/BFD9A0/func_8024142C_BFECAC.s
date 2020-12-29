.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024142C_BFECAC
/* BFECAC 8024142C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BFECB0 80241430 AFB40040 */  sw        $s4, 0x40($sp)
/* BFECB4 80241434 0080A02D */  daddu     $s4, $a0, $zero
/* BFECB8 80241438 AFBF0048 */  sw        $ra, 0x48($sp)
/* BFECBC 8024143C AFB50044 */  sw        $s5, 0x44($sp)
/* BFECC0 80241440 AFB3003C */  sw        $s3, 0x3c($sp)
/* BFECC4 80241444 AFB20038 */  sw        $s2, 0x38($sp)
/* BFECC8 80241448 AFB10034 */  sw        $s1, 0x34($sp)
/* BFECCC 8024144C AFB00030 */  sw        $s0, 0x30($sp)
/* BFECD0 80241450 8E920148 */  lw        $s2, 0x148($s4)
/* BFECD4 80241454 86440008 */  lh        $a0, 8($s2)
/* BFECD8 80241458 8E90000C */  lw        $s0, 0xc($s4)
/* BFECDC 8024145C 0C00EABB */  jal       get_npc_unsafe
/* BFECE0 80241460 00A0882D */   daddu    $s1, $a1, $zero
/* BFECE4 80241464 0280202D */  daddu     $a0, $s4, $zero
/* BFECE8 80241468 8E050000 */  lw        $a1, ($s0)
/* BFECEC 8024146C 0C0B1EAF */  jal       get_variable
/* BFECF0 80241470 0040A82D */   daddu    $s5, $v0, $zero
/* BFECF4 80241474 AFA00010 */  sw        $zero, 0x10($sp)
/* BFECF8 80241478 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFECFC 8024147C 8C630030 */  lw        $v1, 0x30($v1)
/* BFED00 80241480 AFA30014 */  sw        $v1, 0x14($sp)
/* BFED04 80241484 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFED08 80241488 8C63001C */  lw        $v1, 0x1c($v1)
/* BFED0C 8024148C AFA30018 */  sw        $v1, 0x18($sp)
/* BFED10 80241490 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFED14 80241494 8C630024 */  lw        $v1, 0x24($v1)
/* BFED18 80241498 AFA3001C */  sw        $v1, 0x1c($sp)
/* BFED1C 8024149C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFED20 802414A0 8C630028 */  lw        $v1, 0x28($v1)
/* BFED24 802414A4 27B30010 */  addiu     $s3, $sp, 0x10
/* BFED28 802414A8 AFA30020 */  sw        $v1, 0x20($sp)
/* BFED2C 802414AC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* BFED30 802414B0 3C0142F0 */  lui       $at, 0x42f0
/* BFED34 802414B4 44810000 */  mtc1      $at, $f0
/* BFED38 802414B8 8C63002C */  lw        $v1, 0x2c($v1)
/* BFED3C 802414BC 0040802D */  daddu     $s0, $v0, $zero
/* BFED40 802414C0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BFED44 802414C4 A7A0002C */  sh        $zero, 0x2c($sp)
/* BFED48 802414C8 12200006 */  beqz      $s1, .L802414E4
/* BFED4C 802414CC AFA30024 */   sw       $v1, 0x24($sp)
/* BFED50 802414D0 02A0202D */  daddu     $a0, $s5, $zero
/* BFED54 802414D4 0240282D */  daddu     $a1, $s2, $zero
/* BFED58 802414D8 0280302D */  daddu     $a2, $s4, $zero
/* BFED5C 802414DC 0C0904C2 */  jal       func_80241308_BFEB88
/* BFED60 802414E0 0200382D */   daddu    $a3, $s0, $zero
.L802414E4:
/* BFED64 802414E4 2402FFFE */  addiu     $v0, $zero, -2
/* BFED68 802414E8 A2A200AB */  sb        $v0, 0xab($s5)
/* BFED6C 802414EC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BFED70 802414F0 30620004 */  andi      $v0, $v1, 4
/* BFED74 802414F4 10400007 */  beqz      $v0, .L80241514
/* BFED78 802414F8 00000000 */   nop      
/* BFED7C 802414FC 824200B4 */  lb        $v0, 0xb4($s2)
/* BFED80 80241500 1440003C */  bnez      $v0, .L802415F4
/* BFED84 80241504 0000102D */   daddu    $v0, $zero, $zero
/* BFED88 80241508 2402FFFB */  addiu     $v0, $zero, -5
/* BFED8C 8024150C 00621024 */  and       $v0, $v1, $v0
/* BFED90 80241510 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241514:
/* BFED94 80241514 8E830070 */  lw        $v1, 0x70($s4)
/* BFED98 80241518 2C62000F */  sltiu     $v0, $v1, 0xf
/* BFED9C 8024151C 10400034 */  beqz      $v0, .L802415F0
/* BFEDA0 80241520 00031080 */   sll      $v0, $v1, 2
/* BFEDA4 80241524 3C018026 */  lui       $at, %hi(D_80263438)
/* BFEDA8 80241528 00220821 */  addu      $at, $at, $v0
/* BFEDAC 8024152C 8C223438 */  lw        $v0, %lo(D_80263438)($at)
/* BFEDB0 80241530 00400008 */  jr        $v0
/* BFEDB4 80241534 00000000 */   nop      
/* BFEDB8 80241538 0280202D */  daddu     $a0, $s4, $zero
/* BFEDBC 8024153C 0200282D */  daddu     $a1, $s0, $zero
/* BFEDC0 80241540 0C090048 */  jal       func_80240120_BFD9A0
/* BFEDC4 80241544 0260302D */   daddu    $a2, $s3, $zero
/* BFEDC8 80241548 0280202D */  daddu     $a0, $s4, $zero
/* BFEDCC 8024154C 0200282D */  daddu     $a1, $s0, $zero
/* BFEDD0 80241550 0C0900B4 */  jal       func_802402D0_BFDB50
/* BFEDD4 80241554 0260302D */   daddu    $a2, $s3, $zero
/* BFEDD8 80241558 0809057D */  j         .L802415F4
/* BFEDDC 8024155C 0000102D */   daddu    $v0, $zero, $zero
/* BFEDE0 80241560 0280202D */  daddu     $a0, $s4, $zero
/* BFEDE4 80241564 0200282D */  daddu     $a1, $s0, $zero
/* BFEDE8 80241568 0C09023E */  jal       dgb_01_UnkNpcAIFunc1
/* BFEDEC 8024156C 0260302D */   daddu    $a2, $s3, $zero
/* BFEDF0 80241570 0280202D */  daddu     $a0, $s4, $zero
/* BFEDF4 80241574 0200282D */  daddu     $a1, $s0, $zero
/* BFEDF8 80241578 0C09026E */  jal       func_802409B8_BFE238
/* BFEDFC 8024157C 0260302D */   daddu    $a2, $s3, $zero
/* BFEE00 80241580 0809057D */  j         .L802415F4
/* BFEE04 80241584 0000102D */   daddu    $v0, $zero, $zero
/* BFEE08 80241588 0280202D */  daddu     $a0, $s4, $zero
/* BFEE0C 8024158C 0200282D */  daddu     $a1, $s0, $zero
/* BFEE10 80241590 0C09033F */  jal       dgb_01_UnkNpcAIFunc2
/* BFEE14 80241594 0260302D */   daddu    $a2, $s3, $zero
/* BFEE18 80241598 0280202D */  daddu     $a0, $s4, $zero
/* BFEE1C 8024159C 0200282D */  daddu     $a1, $s0, $zero
/* BFEE20 802415A0 0C09035D */  jal       func_80240D74_BFE5F4
/* BFEE24 802415A4 0260302D */   daddu    $a2, $s3, $zero
/* BFEE28 802415A8 0809057D */  j         .L802415F4
/* BFEE2C 802415AC 0000102D */   daddu    $v0, $zero, $zero
/* BFEE30 802415B0 0280202D */  daddu     $a0, $s4, $zero
/* BFEE34 802415B4 0200282D */  daddu     $a1, $s0, $zero
/* BFEE38 802415B8 0C090378 */  jal       func_80240DE0_BFE660
/* BFEE3C 802415BC 0260302D */   daddu    $a2, $s3, $zero
/* BFEE40 802415C0 0809057D */  j         .L802415F4
/* BFEE44 802415C4 0000102D */   daddu    $v0, $zero, $zero
/* BFEE48 802415C8 0280202D */  daddu     $a0, $s4, $zero
/* BFEE4C 802415CC 0200282D */  daddu     $a1, $s0, $zero
/* BFEE50 802415D0 0C0903C5 */  jal       dgb_01_UnkNpcAIFunc3
/* BFEE54 802415D4 0260302D */   daddu    $a2, $s3, $zero
/* BFEE58 802415D8 0809057D */  j         .L802415F4
/* BFEE5C 802415DC 0000102D */   daddu    $v0, $zero, $zero
/* BFEE60 802415E0 0280202D */  daddu     $a0, $s4, $zero
/* BFEE64 802415E4 0200282D */  daddu     $a1, $s0, $zero
/* BFEE68 802415E8 0C0903DE */  jal       func_80240F78_BFE7F8
/* BFEE6C 802415EC 0260302D */   daddu    $a2, $s3, $zero
.L802415F0:
/* BFEE70 802415F0 0000102D */  daddu     $v0, $zero, $zero
.L802415F4:
/* BFEE74 802415F4 8FBF0048 */  lw        $ra, 0x48($sp)
/* BFEE78 802415F8 8FB50044 */  lw        $s5, 0x44($sp)
/* BFEE7C 802415FC 8FB40040 */  lw        $s4, 0x40($sp)
/* BFEE80 80241600 8FB3003C */  lw        $s3, 0x3c($sp)
/* BFEE84 80241604 8FB20038 */  lw        $s2, 0x38($sp)
/* BFEE88 80241608 8FB10034 */  lw        $s1, 0x34($sp)
/* BFEE8C 8024160C 8FB00030 */  lw        $s0, 0x30($sp)
/* BFEE90 80241610 03E00008 */  jr        $ra
/* BFEE94 80241614 27BD0050 */   addiu    $sp, $sp, 0x50
