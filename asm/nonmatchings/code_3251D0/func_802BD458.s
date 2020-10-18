.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD458
/* 325528 802BD458 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32552C 802BD45C AFB00010 */  sw        $s0, 0x10($sp)
/* 325530 802BD460 0080802D */  daddu     $s0, $a0, $zero
/* 325534 802BD464 AFBF0014 */  sw        $ra, 0x14($sp)
/* 325538 802BD468 8E02000C */  lw        $v0, 0xc($s0)
/* 32553C 802BD46C 0C0B1EAF */  jal       get_variable
/* 325540 802BD470 8C450000 */   lw       $a1, ($v0)
/* 325544 802BD474 3C038008 */  lui       $v1, %hi(gItemTable)
/* 325548 802BD478 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* 32554C 802BD47C 00021140 */  sll       $v0, $v0, 5
/* 325550 802BD480 00431021 */  addu      $v0, $v0, $v1
/* 325554 802BD484 8043001B */  lb        $v1, 0x1b($v0)
/* 325558 802BD488 AE0300B0 */  sw        $v1, 0xb0($s0)
/* 32555C 802BD48C 8043001C */  lb        $v1, 0x1c($v0)
/* 325560 802BD490 AE0000B8 */  sw        $zero, 0xb8($s0)
/* 325564 802BD494 AE0300B4 */  sw        $v1, 0xb4($s0)
/* 325568 802BD498 94420018 */  lhu       $v0, 0x18($v0)
/* 32556C 802BD49C 30420100 */  andi      $v0, $v0, 0x100
/* 325570 802BD4A0 10400002 */  beqz      $v0, .L802BD4AC
/* 325574 802BD4A4 24020001 */   addiu    $v0, $zero, 1
/* 325578 802BD4A8 AE0200B8 */  sw        $v0, 0xb8($s0)
.L802BD4AC:
/* 32557C 802BD4AC 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 325580 802BD4B0 04400006 */  bltz      $v0, .L802BD4CC
/* 325584 802BD4B4 0000182D */   daddu    $v1, $zero, $zero
/* 325588 802BD4B8 5C400006 */  bgtzl     $v0, .L802BD4D4
/* 32558C 802BD4BC AE0300C0 */   sw       $v1, 0xc0($s0)
/* 325590 802BD4C0 8E0200B4 */  lw        $v0, 0xb4($s0)
/* 325594 802BD4C4 04430003 */  bgezl     $v0, .L802BD4D4
/* 325598 802BD4C8 AE0300C0 */   sw       $v1, 0xc0($s0)
.L802BD4CC:
/* 32559C 802BD4CC 24030001 */  addiu     $v1, $zero, 1
/* 3255A0 802BD4D0 AE0300C0 */  sw        $v1, 0xc0($s0)
.L802BD4D4:
/* 3255A4 802BD4D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3255A8 802BD4D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 3255AC 802BD4DC 24020002 */  addiu     $v0, $zero, 2
/* 3255B0 802BD4E0 03E00008 */  jr        $ra
/* 3255B4 802BD4E4 27BD0018 */   addiu    $sp, $sp, 0x18
