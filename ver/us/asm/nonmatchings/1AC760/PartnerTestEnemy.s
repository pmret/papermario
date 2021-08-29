.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PartnerTestEnemy
/* 1AEDB0 802804D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AEDB4 802804D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AEDB8 802804D8 0080902D */  daddu     $s2, $a0, $zero
/* 1AEDBC 802804DC AFBF0024 */  sw        $ra, 0x24($sp)
/* 1AEDC0 802804E0 AFB40020 */  sw        $s4, 0x20($sp)
/* 1AEDC4 802804E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AEDC8 802804E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AEDCC 802804EC AFB00010 */  sw        $s0, 0x10($sp)
/* 1AEDD0 802804F0 8E440148 */  lw        $a0, 0x148($s2)
/* 1AEDD4 802804F4 0C09A75B */  jal       get_actor
/* 1AEDD8 802804F8 8E50000C */   lw       $s0, 0xc($s2)
/* 1AEDDC 802804FC 8E140000 */  lw        $s4, ($s0)
/* 1AEDE0 80280500 26100004 */  addiu     $s0, $s0, 4
/* 1AEDE4 80280504 8E030000 */  lw        $v1, ($s0)
/* 1AEDE8 80280508 26100004 */  addiu     $s0, $s0, 4
/* 1AEDEC 8028050C 0240202D */  daddu     $a0, $s2, $zero
/* 1AEDF0 80280510 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1AEDF4 80280514 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1AEDF8 80280518 0040982D */  daddu     $s3, $v0, $zero
/* 1AEDFC 8028051C AE230188 */  sw        $v1, 0x188($s1)
/* 1AEE00 80280520 8E030000 */  lw        $v1, ($s0)
/* 1AEE04 80280524 26100004 */  addiu     $s0, $s0, 4
/* 1AEE08 80280528 AE23018C */  sw        $v1, 0x18c($s1)
/* 1AEE0C 8028052C 8E030000 */  lw        $v1, ($s0)
/* 1AEE10 80280530 26100004 */  addiu     $s0, $s0, 4
/* 1AEE14 80280534 AE230190 */  sw        $v1, 0x190($s1)
/* 1AEE18 80280538 8E050000 */  lw        $a1, ($s0)
/* 1AEE1C 8028053C 0C0B1EAF */  jal       get_variable
/* 1AEE20 80280540 26100004 */   addiu    $s0, $s0, 4
/* 1AEE24 80280544 A622017E */  sh        $v0, 0x17e($s1)
/* 1AEE28 80280548 A2200198 */  sb        $zero, 0x198($s1)
/* 1AEE2C 8028054C 8E100000 */  lw        $s0, ($s0)
/* 1AEE30 80280550 24020030 */  addiu     $v0, $zero, 0x30
/* 1AEE34 80280554 32030030 */  andi      $v1, $s0, 0x30
/* 1AEE38 80280558 54620004 */  bnel      $v1, $v0, .L8028056C
/* 1AEE3C 8028055C 32020010 */   andi     $v0, $s0, 0x10
/* 1AEE40 80280560 8E220000 */  lw        $v0, ($s1)
/* 1AEE44 80280564 080A016B */  j         .L802805AC
/* 1AEE48 80280568 34420030 */   ori      $v0, $v0, 0x30
.L8028056C:
/* 1AEE4C 8028056C 10400004 */  beqz      $v0, .L80280580
/* 1AEE50 80280570 2403FFDF */   addiu    $v1, $zero, -0x21
/* 1AEE54 80280574 8E220000 */  lw        $v0, ($s1)
/* 1AEE58 80280578 080A016A */  j         .L802805A8
/* 1AEE5C 8028057C 34420010 */   ori      $v0, $v0, 0x10
.L80280580:
/* 1AEE60 80280580 32020020 */  andi      $v0, $s0, 0x20
/* 1AEE64 80280584 10400005 */  beqz      $v0, .L8028059C
/* 1AEE68 80280588 2403FFEF */   addiu    $v1, $zero, -0x11
/* 1AEE6C 8028058C 8E220000 */  lw        $v0, ($s1)
/* 1AEE70 80280590 00431024 */  and       $v0, $v0, $v1
/* 1AEE74 80280594 080A016B */  j         .L802805AC
/* 1AEE78 80280598 34420020 */   ori      $v0, $v0, 0x20
.L8028059C:
/* 1AEE7C 8028059C 8E220000 */  lw        $v0, ($s1)
/* 1AEE80 802805A0 00431024 */  and       $v0, $v0, $v1
/* 1AEE84 802805A4 2403FFDF */  addiu     $v1, $zero, -0x21
.L802805A8:
/* 1AEE88 802805A8 00431024 */  and       $v0, $v0, $v1
.L802805AC:
/* 1AEE8C 802805AC AE220000 */  sw        $v0, ($s1)
/* 1AEE90 802805B0 32020040 */  andi      $v0, $s0, 0x40
/* 1AEE94 802805B4 10400007 */  beqz      $v0, .L802805D4
/* 1AEE98 802805B8 2404FFBF */   addiu    $a0, $zero, -0x41
/* 1AEE9C 802805BC 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AEEA0 802805C0 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AEEA4 802805C4 8C620000 */  lw        $v0, ($v1)
/* 1AEEA8 802805C8 34420040 */  ori       $v0, $v0, 0x40
/* 1AEEAC 802805CC 080A017A */  j         .L802805E8
/* 1AEEB0 802805D0 AC620000 */   sw       $v0, ($v1)
.L802805D4:
/* 1AEEB4 802805D4 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEEB8 802805D8 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEEBC 802805DC 8C430000 */  lw        $v1, ($v0)
/* 1AEEC0 802805E0 00641824 */  and       $v1, $v1, $a0
/* 1AEEC4 802805E4 AC430000 */  sw        $v1, ($v0)
.L802805E8:
/* 1AEEC8 802805E8 32020200 */  andi      $v0, $s0, 0x200
/* 1AEECC 802805EC 10400007 */  beqz      $v0, .L8028060C
/* 1AEED0 802805F0 2404FDFF */   addiu    $a0, $zero, -0x201
/* 1AEED4 802805F4 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AEED8 802805F8 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AEEDC 802805FC 8C620000 */  lw        $v0, ($v1)
/* 1AEEE0 80280600 34420200 */  ori       $v0, $v0, 0x200
/* 1AEEE4 80280604 080A0188 */  j         .L80280620
/* 1AEEE8 80280608 AC620000 */   sw       $v0, ($v1)
.L8028060C:
/* 1AEEEC 8028060C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEEF0 80280610 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEEF4 80280614 8C430000 */  lw        $v1, ($v0)
/* 1AEEF8 80280618 00641824 */  and       $v1, $v1, $a0
/* 1AEEFC 8028061C AC430000 */  sw        $v1, ($v0)
.L80280620:
/* 1AEF00 80280620 32020080 */  andi      $v0, $s0, 0x80
/* 1AEF04 80280624 10400007 */  beqz      $v0, .L80280644
/* 1AEF08 80280628 2404FF7F */   addiu    $a0, $zero, -0x81
/* 1AEF0C 8028062C 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AEF10 80280630 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AEF14 80280634 8C620000 */  lw        $v0, ($v1)
/* 1AEF18 80280638 34420080 */  ori       $v0, $v0, 0x80
/* 1AEF1C 8028063C 080A0196 */  j         .L80280658
/* 1AEF20 80280640 AC620000 */   sw       $v0, ($v1)
.L80280644:
/* 1AEF24 80280644 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEF28 80280648 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEF2C 8028064C 8C430000 */  lw        $v1, ($v0)
/* 1AEF30 80280650 00641824 */  and       $v1, $v1, $a0
/* 1AEF34 80280654 AC430000 */  sw        $v1, ($v0)
.L80280658:
/* 1AEF38 80280658 32020800 */  andi      $v0, $s0, 0x800
/* 1AEF3C 8028065C 10400007 */  beqz      $v0, .L8028067C
/* 1AEF40 80280660 2404F7FF */   addiu    $a0, $zero, -0x801
/* 1AEF44 80280664 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AEF48 80280668 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AEF4C 8028066C 8C620000 */  lw        $v0, ($v1)
/* 1AEF50 80280670 34420800 */  ori       $v0, $v0, 0x800
/* 1AEF54 80280674 080A01A4 */  j         .L80280690
/* 1AEF58 80280678 AC620000 */   sw       $v0, ($v1)
.L8028067C:
/* 1AEF5C 8028067C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AEF60 80280680 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AEF64 80280684 8C430000 */  lw        $v1, ($v0)
/* 1AEF68 80280688 00641824 */  and       $v1, $v1, $a0
/* 1AEF6C 8028068C AC430000 */  sw        $v1, ($v0)
.L80280690:
/* 1AEF70 80280690 96620428 */  lhu       $v0, 0x428($s3)
/* 1AEF74 80280694 92230193 */  lbu       $v1, 0x193($s1)
/* 1AEF78 80280698 A62201A0 */  sh        $v0, 0x1a0($s1)
/* 1AEF7C 8028069C 92620426 */  lbu       $v0, 0x426($s3)
/* 1AEF80 802806A0 A2230194 */  sb        $v1, 0x194($s1)
/* 1AEF84 802806A4 306300FF */  andi      $v1, $v1, 0xff
/* 1AEF88 802806A8 A22201A2 */  sb        $v0, 0x1a2($s1)
/* 1AEF8C 802806AC 240200FF */  addiu     $v0, $zero, 0xff
/* 1AEF90 802806B0 50620001 */  beql      $v1, $v0, .L802806B8
/* 1AEF94 802806B4 A2200194 */   sb       $zero, 0x194($s1)
.L802806B8:
/* 1AEF98 802806B8 8E220190 */  lw        $v0, 0x190($s1)
/* 1AEF9C 802806BC 30420F00 */  andi      $v0, $v0, 0xf00
/* 1AEFA0 802806C0 00021203 */  sra       $v0, $v0, 8
/* 1AEFA4 802806C4 0C09F7DF */  jal       calc_partner_test_enemy
/* 1AEFA8 802806C8 A2220195 */   sb       $v0, 0x195($s1)
/* 1AEFAC 802806CC 04400006 */  bltz      $v0, .L802806E8
/* 1AEFB0 802806D0 0240202D */   daddu    $a0, $s2, $zero
/* 1AEFB4 802806D4 0280282D */  daddu     $a1, $s4, $zero
/* 1AEFB8 802806D8 0C0B2026 */  jal       evt_set_variable
/* 1AEFBC 802806DC 0040302D */   daddu    $a2, $v0, $zero
/* 1AEFC0 802806E0 080A01BB */  j         .L802806EC
/* 1AEFC4 802806E4 24020002 */   addiu    $v0, $zero, 2
.L802806E8:
/* 1AEFC8 802806E8 240200FF */  addiu     $v0, $zero, 0xff
.L802806EC:
/* 1AEFCC 802806EC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1AEFD0 802806F0 8FB40020 */  lw        $s4, 0x20($sp)
/* 1AEFD4 802806F4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AEFD8 802806F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AEFDC 802806FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AEFE0 80280700 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AEFE4 80280704 03E00008 */  jr        $ra
/* 1AEFE8 80280708 27BD0028 */   addiu    $sp, $sp, 0x28
