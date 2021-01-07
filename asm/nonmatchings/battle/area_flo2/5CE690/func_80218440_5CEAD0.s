.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218440_5CEAD0
/* 5CEAD0 80218440 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 5CEAD4 80218444 AFB1003C */  sw        $s1, 0x3c($sp)
/* 5CEAD8 80218448 0080882D */  daddu     $s1, $a0, $zero
/* 5CEADC 8021844C AFBF0040 */  sw        $ra, 0x40($sp)
/* 5CEAE0 80218450 AFB00038 */  sw        $s0, 0x38($sp)
/* 5CEAE4 80218454 8E30000C */  lw        $s0, 0xc($s1)
/* 5CEAE8 80218458 8E050000 */  lw        $a1, ($s0)
/* 5CEAEC 8021845C 0C0B1EAF */  jal       get_variable
/* 5CEAF0 80218460 26100004 */   addiu    $s0, $s0, 4
/* 5CEAF4 80218464 0040282D */  daddu     $a1, $v0, $zero
/* 5CEAF8 80218468 30A20002 */  andi      $v0, $a1, 2
/* 5CEAFC 8021846C 14400004 */  bnez      $v0, .L80218480
/* 5CEB00 80218470 0000202D */   daddu    $a0, $zero, $zero
/* 5CEB04 80218474 24020002 */  addiu     $v0, $zero, 2
/* 5CEB08 80218478 AFA20010 */  sw        $v0, 0x10($sp)
/* 5CEB0C 8021847C 24040001 */  addiu     $a0, $zero, 1
.L80218480:
/* 5CEB10 80218480 30A20008 */  andi      $v0, $a1, 8
/* 5CEB14 80218484 14400007 */  bnez      $v0, .L802184A4
/* 5CEB18 80218488 30A20020 */   andi     $v0, $a1, 0x20
/* 5CEB1C 8021848C 00041080 */  sll       $v0, $a0, 2
/* 5CEB20 80218490 03A21821 */  addu      $v1, $sp, $v0
/* 5CEB24 80218494 24020008 */  addiu     $v0, $zero, 8
/* 5CEB28 80218498 AC620010 */  sw        $v0, 0x10($v1)
/* 5CEB2C 8021849C 24840001 */  addiu     $a0, $a0, 1
/* 5CEB30 802184A0 30A20020 */  andi      $v0, $a1, 0x20
.L802184A4:
/* 5CEB34 802184A4 14400007 */  bnez      $v0, .L802184C4
/* 5CEB38 802184A8 30A20080 */   andi     $v0, $a1, 0x80
/* 5CEB3C 802184AC 00041080 */  sll       $v0, $a0, 2
/* 5CEB40 802184B0 03A21821 */  addu      $v1, $sp, $v0
/* 5CEB44 802184B4 24020020 */  addiu     $v0, $zero, 0x20
/* 5CEB48 802184B8 AC620010 */  sw        $v0, 0x10($v1)
/* 5CEB4C 802184BC 24840001 */  addiu     $a0, $a0, 1
/* 5CEB50 802184C0 30A20080 */  andi      $v0, $a1, 0x80
.L802184C4:
/* 5CEB54 802184C4 14400007 */  bnez      $v0, .L802184E4
/* 5CEB58 802184C8 30A20200 */   andi     $v0, $a1, 0x200
/* 5CEB5C 802184CC 00041080 */  sll       $v0, $a0, 2
/* 5CEB60 802184D0 03A21821 */  addu      $v1, $sp, $v0
/* 5CEB64 802184D4 24020080 */  addiu     $v0, $zero, 0x80
/* 5CEB68 802184D8 AC620010 */  sw        $v0, 0x10($v1)
/* 5CEB6C 802184DC 24840001 */  addiu     $a0, $a0, 1
/* 5CEB70 802184E0 30A20200 */  andi      $v0, $a1, 0x200
.L802184E4:
/* 5CEB74 802184E4 14400007 */  bnez      $v0, .L80218504
/* 5CEB78 802184E8 30A20001 */   andi     $v0, $a1, 1
/* 5CEB7C 802184EC 00041080 */  sll       $v0, $a0, 2
/* 5CEB80 802184F0 03A21821 */  addu      $v1, $sp, $v0
/* 5CEB84 802184F4 24020200 */  addiu     $v0, $zero, 0x200
/* 5CEB88 802184F8 AC620010 */  sw        $v0, 0x10($v1)
/* 5CEB8C 802184FC 24840001 */  addiu     $a0, $a0, 1
/* 5CEB90 80218500 30A20001 */  andi      $v0, $a1, 1
.L80218504:
/* 5CEB94 80218504 14400007 */  bnez      $v0, .L80218524
/* 5CEB98 80218508 30A20004 */   andi     $v0, $a1, 4
/* 5CEB9C 8021850C 00041080 */  sll       $v0, $a0, 2
/* 5CEBA0 80218510 03A21821 */  addu      $v1, $sp, $v0
/* 5CEBA4 80218514 24020001 */  addiu     $v0, $zero, 1
/* 5CEBA8 80218518 AC620010 */  sw        $v0, 0x10($v1)
/* 5CEBAC 8021851C 00822021 */  addu      $a0, $a0, $v0
/* 5CEBB0 80218520 30A20004 */  andi      $v0, $a1, 4
.L80218524:
/* 5CEBB4 80218524 14400007 */  bnez      $v0, .L80218544
/* 5CEBB8 80218528 30A20010 */   andi     $v0, $a1, 0x10
/* 5CEBBC 8021852C 00041080 */  sll       $v0, $a0, 2
/* 5CEBC0 80218530 03A21821 */  addu      $v1, $sp, $v0
/* 5CEBC4 80218534 24020004 */  addiu     $v0, $zero, 4
/* 5CEBC8 80218538 AC620010 */  sw        $v0, 0x10($v1)
/* 5CEBCC 8021853C 24840001 */  addiu     $a0, $a0, 1
/* 5CEBD0 80218540 30A20010 */  andi      $v0, $a1, 0x10
.L80218544:
/* 5CEBD4 80218544 14400005 */  bnez      $v0, .L8021855C
/* 5CEBD8 80218548 00041080 */   sll      $v0, $a0, 2
/* 5CEBDC 8021854C 03A21821 */  addu      $v1, $sp, $v0
/* 5CEBE0 80218550 24020010 */  addiu     $v0, $zero, 0x10
/* 5CEBE4 80218554 AC620010 */  sw        $v0, 0x10($v1)
/* 5CEBE8 80218558 24840001 */  addiu     $a0, $a0, 1
.L8021855C:
/* 5CEBEC 8021855C 1480000F */  bnez      $a0, .L8021859C
/* 5CEBF0 80218560 30A20100 */   andi     $v0, $a1, 0x100
/* 5CEBF4 80218564 14400005 */  bnez      $v0, .L8021857C
/* 5CEBF8 80218568 30A20040 */   andi     $v0, $a1, 0x40
/* 5CEBFC 8021856C 24020100 */  addiu     $v0, $zero, 0x100
/* 5CEC00 80218570 AFA20010 */  sw        $v0, 0x10($sp)
/* 5CEC04 80218574 24040001 */  addiu     $a0, $zero, 1
/* 5CEC08 80218578 30A20040 */  andi      $v0, $a1, 0x40
.L8021857C:
/* 5CEC0C 8021857C 14400005 */  bnez      $v0, .L80218594
/* 5CEC10 80218580 00041080 */   sll      $v0, $a0, 2
/* 5CEC14 80218584 03A21821 */  addu      $v1, $sp, $v0
/* 5CEC18 80218588 24020040 */  addiu     $v0, $zero, 0x40
/* 5CEC1C 8021858C AC620010 */  sw        $v0, 0x10($v1)
/* 5CEC20 80218590 24840001 */  addiu     $a0, $a0, 1
.L80218594:
/* 5CEC24 80218594 10800006 */  beqz      $a0, .L802185B0
/* 5CEC28 80218598 2406FFFF */   addiu    $a2, $zero, -1
.L8021859C:
/* 5CEC2C 8021859C 0C00A67F */  jal       rand_int
/* 5CEC30 802185A0 2484FFFF */   addiu    $a0, $a0, -1
/* 5CEC34 802185A4 00021080 */  sll       $v0, $v0, 2
/* 5CEC38 802185A8 03A21021 */  addu      $v0, $sp, $v0
/* 5CEC3C 802185AC 8C460010 */  lw        $a2, 0x10($v0)
.L802185B0:
/* 5CEC40 802185B0 8E050000 */  lw        $a1, ($s0)
/* 5CEC44 802185B4 0C0B2026 */  jal       set_variable
/* 5CEC48 802185B8 0220202D */   daddu    $a0, $s1, $zero
/* 5CEC4C 802185BC 8FBF0040 */  lw        $ra, 0x40($sp)
/* 5CEC50 802185C0 8FB1003C */  lw        $s1, 0x3c($sp)
/* 5CEC54 802185C4 8FB00038 */  lw        $s0, 0x38($sp)
/* 5CEC58 802185C8 24020002 */  addiu     $v0, $zero, 2
/* 5CEC5C 802185CC 03E00008 */  jr        $ra
/* 5CEC60 802185D0 27BD0048 */   addiu    $sp, $sp, 0x48
