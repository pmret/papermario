.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RemoveEncounter
/* 1F878 80044478 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1F87C 8004447C AFBF0020 */  sw        $ra, 0x20($sp)
/* 1F880 80044480 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1F884 80044484 AFB20018 */  sw        $s2, 0x18($sp)
/* 1F888 80044488 AFB10014 */  sw        $s1, 0x14($sp)
/* 1F88C 8004448C AFB00010 */  sw        $s0, 0x10($sp)
/* 1F890 80044490 8C82000C */  lw        $v0, 0xc($a0)
/* 1F894 80044494 8C450000 */  lw        $a1, ($v0)
/* 1F898 80044498 8C900148 */  lw        $s0, 0x148($a0)
/* 1F89C 8004449C 0C0B1EAF */  jal       get_variable
/* 1F8A0 800444A0 24120001 */   addiu    $s2, $zero, 1
/* 1F8A4 800444A4 0040882D */  daddu     $s1, $v0, $zero
/* 1F8A8 800444A8 3C13800B */  lui       $s3, %hi(gCurrentEncounter)
/* 1F8AC 800444AC 26730F10 */  addiu     $s3, $s3, %lo(gCurrentEncounter)
/* 1F8B0 800444B0 2402FFFF */  addiu     $v0, $zero, -1
/* 1F8B4 800444B4 1202000D */  beq       $s0, $v0, .L800444EC
/* 1F8B8 800444B8 00000000 */   nop
/* 1F8BC 800444BC 12220004 */  beq       $s1, $v0, .L800444D0
/* 1F8C0 800444C0 00000000 */   nop
/* 1F8C4 800444C4 86020008 */  lh        $v0, 8($s0)
/* 1F8C8 800444C8 14510008 */  bne       $v0, $s1, .L800444EC
/* 1F8CC 800444CC 00000000 */   nop
.L800444D0:
/* 1F8D0 800444D0 86110008 */  lh        $s1, 8($s0)
/* 1F8D4 800444D4 0801113D */  j         .L800444F4
/* 1F8D8 800444D8 241200FF */   addiu    $s2, $zero, 0xff
.L800444DC:
/* 1F8DC 800444DC 0C00F9CC */  jal       kill_encounter
/* 1F8E0 800444E0 0200202D */   daddu    $a0, $s0, $zero
/* 1F8E4 800444E4 08011158 */  j         .L80044560
/* 1F8E8 800444E8 0240102D */   daddu    $v0, $s2, $zero
.L800444EC:
/* 1F8EC 800444EC 0C00FB3A */  jal       get_enemy
/* 1F8F0 800444F0 0220202D */   daddu    $a0, $s1, $zero
.L800444F4:
/* 1F8F4 800444F4 8262001C */  lb        $v0, 0x1c($s3)
/* 1F8F8 800444F8 18400018 */  blez      $v0, .L8004455C
/* 1F8FC 800444FC 0000282D */   daddu    $a1, $zero, $zero
/* 1F900 80044500 0040402D */  daddu     $t0, $v0, $zero
/* 1F904 80044504 0260382D */  daddu     $a3, $s3, $zero
.L80044508:
/* 1F908 80044508 8CE20028 */  lw        $v0, 0x28($a3)
/* 1F90C 8004450C 50400010 */  beql      $v0, $zero, .L80044550
/* 1F910 80044510 24A50001 */   addiu    $a1, $a1, 1
/* 1F914 80044514 8C430000 */  lw        $v1, ($v0)
/* 1F918 80044518 1860000C */  blez      $v1, .L8004454C
/* 1F91C 8004451C 0000202D */   daddu    $a0, $zero, $zero
/* 1F920 80044520 0060302D */  daddu     $a2, $v1, $zero
/* 1F924 80044524 0040182D */  daddu     $v1, $v0, $zero
.L80044528:
/* 1F928 80044528 8C700004 */  lw        $s0, 4($v1)
/* 1F92C 8004452C 12000004 */  beqz      $s0, .L80044540
/* 1F930 80044530 24840001 */   addiu    $a0, $a0, 1
/* 1F934 80044534 86020008 */  lh        $v0, 8($s0)
/* 1F938 80044538 1051FFE8 */  beq       $v0, $s1, .L800444DC
/* 1F93C 8004453C 00000000 */   nop
.L80044540:
/* 1F940 80044540 0086102A */  slt       $v0, $a0, $a2
/* 1F944 80044544 1440FFF8 */  bnez      $v0, .L80044528
/* 1F948 80044548 24630004 */   addiu    $v1, $v1, 4
.L8004454C:
/* 1F94C 8004454C 24A50001 */  addiu     $a1, $a1, 1
.L80044550:
/* 1F950 80044550 00A8102A */  slt       $v0, $a1, $t0
/* 1F954 80044554 1440FFEC */  bnez      $v0, .L80044508
/* 1F958 80044558 24E70004 */   addiu    $a3, $a3, 4
.L8004455C:
/* 1F95C 8004455C 0240102D */  daddu     $v0, $s2, $zero
.L80044560:
/* 1F960 80044560 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1F964 80044564 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1F968 80044568 8FB20018 */  lw        $s2, 0x18($sp)
/* 1F96C 8004456C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1F970 80044570 8FB00010 */  lw        $s0, 0x10($sp)
/* 1F974 80044574 03E00008 */  jr        $ra
/* 1F978 80044578 27BD0028 */   addiu    $sp, $sp, 0x28
