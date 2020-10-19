.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A4_AACCD4
/* AACCD4 802404A4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* AACCD8 802404A8 AFB10034 */  sw        $s1, 0x34($sp)
/* AACCDC 802404AC 0080882D */  daddu     $s1, $a0, $zero
/* AACCE0 802404B0 AFBF0054 */  sw        $ra, 0x54($sp)
/* AACCE4 802404B4 AFBE0050 */  sw        $fp, 0x50($sp)
/* AACCE8 802404B8 AFB7004C */  sw        $s7, 0x4c($sp)
/* AACCEC 802404BC AFB60048 */  sw        $s6, 0x48($sp)
/* AACCF0 802404C0 AFB50044 */  sw        $s5, 0x44($sp)
/* AACCF4 802404C4 AFB40040 */  sw        $s4, 0x40($sp)
/* AACCF8 802404C8 AFB3003C */  sw        $s3, 0x3c($sp)
/* AACCFC 802404CC AFB20038 */  sw        $s2, 0x38($sp)
/* AACD00 802404D0 AFB00030 */  sw        $s0, 0x30($sp)
/* AACD04 802404D4 8E30000C */  lw        $s0, 0xc($s1)
/* AACD08 802404D8 8E050000 */  lw        $a1, ($s0)
/* AACD0C 802404DC 0C0B1EAF */  jal       get_variable
/* AACD10 802404E0 26100004 */   addiu    $s0, $s0, 4
/* AACD14 802404E4 8E050000 */  lw        $a1, ($s0)
/* AACD18 802404E8 26100004 */  addiu     $s0, $s0, 4
/* AACD1C 802404EC 0220202D */  daddu     $a0, $s1, $zero
/* AACD20 802404F0 0C0B1EAF */  jal       get_variable
/* AACD24 802404F4 0040982D */   daddu    $s3, $v0, $zero
/* AACD28 802404F8 8E050000 */  lw        $a1, ($s0)
/* AACD2C 802404FC 26100004 */  addiu     $s0, $s0, 4
/* AACD30 80240500 0220202D */  daddu     $a0, $s1, $zero
/* AACD34 80240504 0C0B1EAF */  jal       get_variable
/* AACD38 80240508 0040B02D */   daddu    $s6, $v0, $zero
/* AACD3C 8024050C 8E050000 */  lw        $a1, ($s0)
/* AACD40 80240510 26100004 */  addiu     $s0, $s0, 4
/* AACD44 80240514 0220202D */  daddu     $a0, $s1, $zero
/* AACD48 80240518 0C0B1EAF */  jal       get_variable
/* AACD4C 8024051C 0040A82D */   daddu    $s5, $v0, $zero
/* AACD50 80240520 8E050000 */  lw        $a1, ($s0)
/* AACD54 80240524 26100004 */  addiu     $s0, $s0, 4
/* AACD58 80240528 0220202D */  daddu     $a0, $s1, $zero
/* AACD5C 8024052C 0C0B1EAF */  jal       get_variable
/* AACD60 80240530 0040A02D */   daddu    $s4, $v0, $zero
/* AACD64 80240534 8E050000 */  lw        $a1, ($s0)
/* AACD68 80240538 26100004 */  addiu     $s0, $s0, 4
/* AACD6C 8024053C 0220202D */  daddu     $a0, $s1, $zero
/* AACD70 80240540 0C0B1EAF */  jal       get_variable
/* AACD74 80240544 0040902D */   daddu    $s2, $v0, $zero
/* AACD78 80240548 8E050000 */  lw        $a1, ($s0)
/* AACD7C 8024054C 26100004 */  addiu     $s0, $s0, 4
/* AACD80 80240550 0220202D */  daddu     $a0, $s1, $zero
/* AACD84 80240554 0C0B1EAF */  jal       get_variable
/* AACD88 80240558 AFA20028 */   sw       $v0, 0x28($sp)
/* AACD8C 8024055C 8E050000 */  lw        $a1, ($s0)
/* AACD90 80240560 26100004 */  addiu     $s0, $s0, 4
/* AACD94 80240564 0220202D */  daddu     $a0, $s1, $zero
/* AACD98 80240568 0C0B1EAF */  jal       get_variable
/* AACD9C 8024056C 0040F02D */   daddu    $fp, $v0, $zero
/* AACDA0 80240570 8E050000 */  lw        $a1, ($s0)
/* AACDA4 80240574 26100004 */  addiu     $s0, $s0, 4
/* AACDA8 80240578 0220202D */  daddu     $a0, $s1, $zero
/* AACDAC 8024057C 0C0B1EAF */  jal       get_variable
/* AACDB0 80240580 0040B82D */   daddu    $s7, $v0, $zero
/* AACDB4 80240584 0220202D */  daddu     $a0, $s1, $zero
/* AACDB8 80240588 8E050000 */  lw        $a1, ($s0)
/* AACDBC 8024058C 0C0B1EAF */  jal       get_variable
/* AACDC0 80240590 0040802D */   daddu    $s0, $v0, $zero
/* AACDC4 80240594 0040182D */  daddu     $v1, $v0, $zero
/* AACDC8 80240598 24020002 */  addiu     $v0, $zero, 2
/* AACDCC 8024059C 12620012 */  beq       $s3, $v0, .L802405E8
/* AACDD0 802405A0 2A620003 */   slti     $v0, $s3, 3
/* AACDD4 802405A4 10400005 */  beqz      $v0, .L802405BC
/* AACDD8 802405A8 24020001 */   addiu    $v0, $zero, 1
/* AACDDC 802405AC 12620008 */  beq       $s3, $v0, .L802405D0
/* AACDE0 802405B0 32C400FF */   andi     $a0, $s6, 0xff
/* AACDE4 802405B4 08090191 */  j         .L80240644
/* AACDE8 802405B8 00000000 */   nop      
.L802405BC:
/* AACDEC 802405BC 24020003 */  addiu     $v0, $zero, 3
/* AACDF0 802405C0 12620018 */  beq       $s3, $v0, .L80240624
/* AACDF4 802405C4 32C400FF */   andi     $a0, $s6, 0xff
/* AACDF8 802405C8 08090191 */  j         .L80240644
/* AACDFC 802405CC 00000000 */   nop      
.L802405D0:
/* AACE00 802405D0 32A500FF */  andi      $a1, $s5, 0xff
/* AACE04 802405D4 328600FF */  andi      $a2, $s4, 0xff
/* AACE08 802405D8 0C046F97 */  jal       set_background_color_blend
/* AACE0C 802405DC 324700FF */   andi     $a3, $s2, 0xff
/* AACE10 802405E0 08090191 */  j         .L80240644
/* AACE14 802405E4 00000000 */   nop      
.L802405E8:
/* AACE18 802405E8 32C400FF */  andi      $a0, $s6, 0xff
/* AACE1C 802405EC 32A500FF */  andi      $a1, $s5, 0xff
/* AACE20 802405F0 328600FF */  andi      $a2, $s4, 0xff
/* AACE24 802405F4 324700FF */  andi      $a3, $s2, 0xff
/* AACE28 802405F8 93A2002B */  lbu       $v0, 0x2b($sp)
/* AACE2C 802405FC AFB0001C */  sw        $s0, 0x1c($sp)
/* AACE30 80240600 AFA30020 */  sw        $v1, 0x20($sp)
/* AACE34 80240604 AFA20010 */  sw        $v0, 0x10($sp)
/* AACE38 80240608 33C200FF */  andi      $v0, $fp, 0xff
/* AACE3C 8024060C AFA20014 */  sw        $v0, 0x14($sp)
/* AACE40 80240610 32E200FF */  andi      $v0, $s7, 0xff
/* AACE44 80240614 0C046FAD */  jal       func_8011BEB4
/* AACE48 80240618 AFA20018 */   sw       $v0, 0x18($sp)
/* AACE4C 8024061C 08090191 */  j         .L80240644
/* AACE50 80240620 00000000 */   nop      
.L80240624:
/* AACE54 80240624 32A500FF */  andi      $a1, $s5, 0xff
/* AACE58 80240628 328600FF */  andi      $a2, $s4, 0xff
/* AACE5C 8024062C 324700FF */  andi      $a3, $s2, 0xff
/* AACE60 80240630 93A2002B */  lbu       $v0, 0x2b($sp)
/* AACE64 80240634 AFA20010 */  sw        $v0, 0x10($sp)
/* AACE68 80240638 33C200FF */  andi      $v0, $fp, 0xff
/* AACE6C 8024063C 0C046FE6 */  jal       func_8011BF98
/* AACE70 80240640 AFA20014 */   sw       $v0, 0x14($sp)
.L80240644:
/* AACE74 80240644 8FBF0054 */  lw        $ra, 0x54($sp)
/* AACE78 80240648 8FBE0050 */  lw        $fp, 0x50($sp)
/* AACE7C 8024064C 8FB7004C */  lw        $s7, 0x4c($sp)
/* AACE80 80240650 8FB60048 */  lw        $s6, 0x48($sp)
/* AACE84 80240654 8FB50044 */  lw        $s5, 0x44($sp)
/* AACE88 80240658 8FB40040 */  lw        $s4, 0x40($sp)
/* AACE8C 8024065C 8FB3003C */  lw        $s3, 0x3c($sp)
/* AACE90 80240660 8FB20038 */  lw        $s2, 0x38($sp)
/* AACE94 80240664 8FB10034 */  lw        $s1, 0x34($sp)
/* AACE98 80240668 8FB00030 */  lw        $s0, 0x30($sp)
/* AACE9C 8024066C 24020002 */  addiu     $v0, $zero, 2
/* AACEA0 80240670 03E00008 */  jr        $ra
/* AACEA4 80240674 27BD0058 */   addiu    $sp, $sp, 0x58
