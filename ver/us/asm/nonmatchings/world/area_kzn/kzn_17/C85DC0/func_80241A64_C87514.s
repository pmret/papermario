.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A64_C87514
/* C87514 80241A64 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C87518 80241A68 AFB20038 */  sw        $s2, 0x38($sp)
/* C8751C 80241A6C 0080902D */  daddu     $s2, $a0, $zero
/* C87520 80241A70 AFBF0048 */  sw        $ra, 0x48($sp)
/* C87524 80241A74 AFB50044 */  sw        $s5, 0x44($sp)
/* C87528 80241A78 AFB40040 */  sw        $s4, 0x40($sp)
/* C8752C 80241A7C AFB3003C */  sw        $s3, 0x3c($sp)
/* C87530 80241A80 AFB10034 */  sw        $s1, 0x34($sp)
/* C87534 80241A84 AFB00030 */  sw        $s0, 0x30($sp)
/* C87538 80241A88 8E510148 */  lw        $s1, 0x148($s2)
/* C8753C 80241A8C 86240008 */  lh        $a0, 8($s1)
/* C87540 80241A90 0C00EABB */  jal       get_npc_unsafe
/* C87544 80241A94 00A0802D */   daddu    $s0, $a1, $zero
/* C87548 80241A98 8E43000C */  lw        $v1, 0xc($s2)
/* C8754C 80241A9C 0240202D */  daddu     $a0, $s2, $zero
/* C87550 80241AA0 8C650000 */  lw        $a1, ($v1)
/* C87554 80241AA4 0C0B1EAF */  jal       get_variable
/* C87558 80241AA8 0040A82D */   daddu    $s5, $v0, $zero
/* C8755C 80241AAC AFA00010 */  sw        $zero, 0x10($sp)
/* C87560 80241AB0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C87564 80241AB4 8C630030 */  lw        $v1, 0x30($v1)
/* C87568 80241AB8 AFA30014 */  sw        $v1, 0x14($sp)
/* C8756C 80241ABC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C87570 80241AC0 8C63001C */  lw        $v1, 0x1c($v1)
/* C87574 80241AC4 AFA30018 */  sw        $v1, 0x18($sp)
/* C87578 80241AC8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C8757C 80241ACC 8C630024 */  lw        $v1, 0x24($v1)
/* C87580 80241AD0 AFA3001C */  sw        $v1, 0x1c($sp)
/* C87584 80241AD4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C87588 80241AD8 8C630028 */  lw        $v1, 0x28($v1)
/* C8758C 80241ADC 27B40010 */  addiu     $s4, $sp, 0x10
/* C87590 80241AE0 AFA30020 */  sw        $v1, 0x20($sp)
/* C87594 80241AE4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C87598 80241AE8 3C014348 */  lui       $at, 0x4348
/* C8759C 80241AEC 44810000 */  mtc1      $at, $f0
/* C875A0 80241AF0 8C63002C */  lw        $v1, 0x2c($v1)
/* C875A4 80241AF4 0040982D */  daddu     $s3, $v0, $zero
/* C875A8 80241AF8 E7A00028 */  swc1      $f0, 0x28($sp)
/* C875AC 80241AFC A7A0002C */  sh        $zero, 0x2c($sp)
/* C875B0 80241B00 16000005 */  bnez      $s0, .L80241B18
/* C875B4 80241B04 AFA30024 */   sw       $v1, 0x24($sp)
/* C875B8 80241B08 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C875BC 80241B0C 30420004 */  andi      $v0, $v0, 4
/* C875C0 80241B10 10400011 */  beqz      $v0, .L80241B58
/* C875C4 80241B14 00000000 */   nop
.L80241B18:
/* C875C8 80241B18 AE400070 */  sw        $zero, 0x70($s2)
/* C875CC 80241B1C A6A0008E */  sh        $zero, 0x8e($s5)
/* C875D0 80241B20 8E2200CC */  lw        $v0, 0xcc($s1)
/* C875D4 80241B24 8C420000 */  lw        $v0, ($v0)
/* C875D8 80241B28 AEA20028 */  sw        $v0, 0x28($s5)
/* C875DC 80241B2C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C875E0 80241B30 30420004 */  andi      $v0, $v0, 4
/* C875E4 80241B34 10400008 */  beqz      $v0, .L80241B58
/* C875E8 80241B38 AE20006C */   sw       $zero, 0x6c($s1)
/* C875EC 80241B3C 24020063 */  addiu     $v0, $zero, 0x63
/* C875F0 80241B40 AE420070 */  sw        $v0, 0x70($s2)
/* C875F4 80241B44 AE400074 */  sw        $zero, 0x74($s2)
/* C875F8 80241B48 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C875FC 80241B4C 2403FFFB */  addiu     $v1, $zero, -5
/* C87600 80241B50 00431024 */  and       $v0, $v0, $v1
/* C87604 80241B54 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241B58:
/* C87608 80241B58 8E430070 */  lw        $v1, 0x70($s2)
/* C8760C 80241B5C 2410000B */  addiu     $s0, $zero, 0xb
/* C87610 80241B60 1070002A */  beq       $v1, $s0, .L80241C0C
/* C87614 80241B64 2862000C */   slti     $v0, $v1, 0xc
/* C87618 80241B68 1040000D */  beqz      $v0, .L80241BA0
/* C8761C 80241B6C 24020001 */   addiu    $v0, $zero, 1
/* C87620 80241B70 1062001A */  beq       $v1, $v0, .L80241BDC
/* C87624 80241B74 28620002 */   slti     $v0, $v1, 2
/* C87628 80241B78 10400005 */  beqz      $v0, .L80241B90
/* C8762C 80241B7C 2402000A */   addiu    $v0, $zero, 0xa
/* C87630 80241B80 10600013 */  beqz      $v1, .L80241BD0
/* C87634 80241B84 0240202D */   daddu    $a0, $s2, $zero
/* C87638 80241B88 08090723 */  j         .L80241C8C
/* C8763C 80241B8C 00000000 */   nop
.L80241B90:
/* C87640 80241B90 10620018 */  beq       $v1, $v0, .L80241BF4
/* C87644 80241B94 0240202D */   daddu    $a0, $s2, $zero
/* C87648 80241B98 08090723 */  j         .L80241C8C
/* C8764C 80241B9C 00000000 */   nop
.L80241BA0:
/* C87650 80241BA0 2402000D */  addiu     $v0, $zero, 0xd
/* C87654 80241BA4 10620029 */  beq       $v1, $v0, .L80241C4C
/* C87658 80241BA8 0062102A */   slt      $v0, $v1, $v0
/* C8765C 80241BAC 14400020 */  bnez      $v0, .L80241C30
/* C87660 80241BB0 0240202D */   daddu    $a0, $s2, $zero
/* C87664 80241BB4 2402000E */  addiu     $v0, $zero, 0xe
/* C87668 80241BB8 1062002D */  beq       $v1, $v0, .L80241C70
/* C8766C 80241BBC 24020063 */   addiu    $v0, $zero, 0x63
/* C87670 80241BC0 10620030 */  beq       $v1, $v0, .L80241C84
/* C87674 80241BC4 00000000 */   nop
/* C87678 80241BC8 08090723 */  j         .L80241C8C
/* C8767C 80241BCC 00000000 */   nop
.L80241BD0:
/* C87680 80241BD0 0260282D */  daddu     $a1, $s3, $zero
/* C87684 80241BD4 0C0902F8 */  jal       func_80240BE0_C86690
/* C87688 80241BD8 0280302D */   daddu    $a2, $s4, $zero
.L80241BDC:
/* C8768C 80241BDC 0240202D */  daddu     $a0, $s2, $zero
/* C87690 80241BE0 0260282D */  daddu     $a1, $s3, $zero
/* C87694 80241BE4 0C090313 */  jal       func_80240C4C_C866FC
/* C87698 80241BE8 0280302D */   daddu    $a2, $s4, $zero
/* C8769C 80241BEC 08090723 */  j         .L80241C8C
/* C876A0 80241BF0 00000000 */   nop
.L80241BF4:
/* C876A4 80241BF4 0260282D */  daddu     $a1, $s3, $zero
/* C876A8 80241BF8 0C090352 */  jal       func_80240D48_C867F8
/* C876AC 80241BFC 0280302D */   daddu    $a2, $s4, $zero
/* C876B0 80241C00 8E420070 */  lw        $v0, 0x70($s2)
/* C876B4 80241C04 14500021 */  bne       $v0, $s0, .L80241C8C
/* C876B8 80241C08 00000000 */   nop
.L80241C0C:
/* C876BC 80241C0C 0240202D */  daddu     $a0, $s2, $zero
/* C876C0 80241C10 0260282D */  daddu     $a1, $s3, $zero
/* C876C4 80241C14 0C0905E2 */  jal       kzn_17_UnkNpcDurationFlagFunc3
/* C876C8 80241C18 0280302D */   daddu    $a2, $s4, $zero
/* C876CC 80241C1C 8E430070 */  lw        $v1, 0x70($s2)
/* C876D0 80241C20 2402000C */  addiu     $v0, $zero, 0xc
/* C876D4 80241C24 14620019 */  bne       $v1, $v0, .L80241C8C
/* C876D8 80241C28 00000000 */   nop
/* C876DC 80241C2C 0240202D */  daddu     $a0, $s2, $zero
.L80241C30:
/* C876E0 80241C30 0260282D */  daddu     $a1, $s3, $zero
/* C876E4 80241C34 0C090606 */  jal       func_80241818_C872C8
/* C876E8 80241C38 0280302D */   daddu    $a2, $s4, $zero
/* C876EC 80241C3C 8E430070 */  lw        $v1, 0x70($s2)
/* C876F0 80241C40 2402000D */  addiu     $v0, $zero, 0xd
/* C876F4 80241C44 14620011 */  bne       $v1, $v0, .L80241C8C
/* C876F8 80241C48 00000000 */   nop
.L80241C4C:
/* C876FC 80241C4C 0240202D */  daddu     $a0, $s2, $zero
/* C87700 80241C50 0260282D */  daddu     $a1, $s3, $zero
/* C87704 80241C54 0C090646 */  jal       kzn_17_UnkNpcDurationFlagFunc2
/* C87708 80241C58 0280302D */   daddu    $a2, $s4, $zero
/* C8770C 80241C5C 8E430070 */  lw        $v1, 0x70($s2)
/* C87710 80241C60 2402000E */  addiu     $v0, $zero, 0xe
/* C87714 80241C64 14620009 */  bne       $v1, $v0, .L80241C8C
/* C87718 80241C68 00000000 */   nop
/* C8771C 80241C6C 0240202D */  daddu     $a0, $s2, $zero
.L80241C70:
/* C87720 80241C70 0260282D */  daddu     $a1, $s3, $zero
/* C87724 80241C74 0C09065E */  jal       kzn_17_UnkNpcAIFunc30
/* C87728 80241C78 0280302D */   daddu    $a2, $s4, $zero
/* C8772C 80241C7C 08090723 */  j         .L80241C8C
/* C87730 80241C80 00000000 */   nop
.L80241C84:
/* C87734 80241C84 0C0129CF */  jal       func_8004A73C
/* C87738 80241C88 0240202D */   daddu    $a0, $s2, $zero
.L80241C8C:
/* C8773C 80241C8C 8FBF0048 */  lw        $ra, 0x48($sp)
/* C87740 80241C90 8FB50044 */  lw        $s5, 0x44($sp)
/* C87744 80241C94 8FB40040 */  lw        $s4, 0x40($sp)
/* C87748 80241C98 8FB3003C */  lw        $s3, 0x3c($sp)
/* C8774C 80241C9C 8FB20038 */  lw        $s2, 0x38($sp)
/* C87750 80241CA0 8FB10034 */  lw        $s1, 0x34($sp)
/* C87754 80241CA4 8FB00030 */  lw        $s0, 0x30($sp)
/* C87758 80241CA8 0000102D */  daddu     $v0, $zero, $zero
/* C8775C 80241CAC 03E00008 */  jr        $ra
/* C87760 80241CB0 27BD0050 */   addiu    $sp, $sp, 0x50
