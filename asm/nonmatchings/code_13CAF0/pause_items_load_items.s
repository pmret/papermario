.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_load_items
/* 13D81C 8024A4DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13D820 8024A4E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 13D824 8024A4E4 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 13D828 8024A4E8 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 13D82C 8024A4EC 24020001 */  addiu     $v0, $zero, 1
/* 13D830 8024A4F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 13D834 8024A4F4 3C018027 */  lui       $at, 0x8027
/* 13D838 8024A4F8 AC2005D0 */  sw        $zero, 0x5d0($at)
/* 13D83C 8024A4FC 14820011 */  bne       $a0, $v0, .L8024A544
/* 13D840 8024A500 0000802D */   daddu    $s0, $zero, $zero
/* 13D844 8024A504 0200202D */  daddu     $a0, $s0, $zero
/* 13D848 8024A508 0060302D */  daddu     $a2, $v1, $zero
/* 13D84C 8024A50C 3C058027 */  lui       $a1, 0x8027
/* 13D850 8024A510 24A50400 */  addiu     $a1, $a1, 0x400
.L8024A514:
/* 13D854 8024A514 84C201B4 */  lh        $v0, 0x1b4($a2)
/* 13D858 8024A518 94C301B4 */  lhu       $v1, 0x1b4($a2)
/* 13D85C 8024A51C 10400004 */  beqz      $v0, .L8024A530
/* 13D860 8024A520 24840001 */   addiu    $a0, $a0, 1
/* 13D864 8024A524 A4A30000 */  sh        $v1, ($a1)
/* 13D868 8024A528 24A50002 */  addiu     $a1, $a1, 2
/* 13D86C 8024A52C 26100001 */  addiu     $s0, $s0, 1
.L8024A530:
/* 13D870 8024A530 2882000A */  slti      $v0, $a0, 0xa
/* 13D874 8024A534 1440FFF7 */  bnez      $v0, .L8024A514
/* 13D878 8024A538 24C60002 */   addiu    $a2, $a2, 2
/* 13D87C 8024A53C 0809295F */  j         .L8024A57C
/* 13D880 8024A540 00000000 */   nop      
.L8024A544:
/* 13D884 8024A544 0000202D */  daddu     $a0, $zero, $zero
/* 13D888 8024A548 0060302D */  daddu     $a2, $v1, $zero
/* 13D88C 8024A54C 3C058027 */  lui       $a1, 0x8027
/* 13D890 8024A550 24A50400 */  addiu     $a1, $a1, 0x400
.L8024A554:
/* 13D894 8024A554 84C20074 */  lh        $v0, 0x74($a2)
/* 13D898 8024A558 94C30074 */  lhu       $v1, 0x74($a2)
/* 13D89C 8024A55C 10400004 */  beqz      $v0, .L8024A570
/* 13D8A0 8024A560 24840001 */   addiu    $a0, $a0, 1
/* 13D8A4 8024A564 A4A30000 */  sh        $v1, ($a1)
/* 13D8A8 8024A568 24A50002 */  addiu     $a1, $a1, 2
/* 13D8AC 8024A56C 26100001 */  addiu     $s0, $s0, 1
.L8024A570:
/* 13D8B0 8024A570 28820020 */  slti      $v0, $a0, 0x20
/* 13D8B4 8024A574 1440FFF7 */  bnez      $v0, .L8024A554
/* 13D8B8 8024A578 24C60002 */   addiu    $a2, $a2, 2
.L8024A57C:
/* 13D8BC 8024A57C 16000005 */  bnez      $s0, .L8024A594
/* 13D8C0 8024A580 24027FFE */   addiu    $v0, $zero, 0x7ffe
/* 13D8C4 8024A584 3C018027 */  lui       $at, 0x8027
/* 13D8C8 8024A588 A4220400 */  sh        $v0, 0x400($at)
/* 13D8CC 8024A58C 0809296B */  j         .L8024A5AC
/* 13D8D0 8024A590 24100001 */   addiu    $s0, $zero, 1
.L8024A594:
/* 13D8D4 8024A594 3C048027 */  lui       $a0, 0x8027
/* 13D8D8 8024A598 24840400 */  addiu     $a0, $a0, 0x400
/* 13D8DC 8024A59C 3C068025 */  lui       $a2, 0x8025
/* 13D8E0 8024A5A0 24C697B0 */  addiu     $a2, $a2, -0x6850
/* 13D8E4 8024A5A4 0C091293 */  jal       pause_sort_item_list
/* 13D8E8 8024A5A8 0200282D */   daddu    $a1, $s0, $zero
.L8024A5AC:
/* 13D8EC 8024A5AC 3C018027 */  lui       $at, 0x8027
/* 13D8F0 8024A5B0 A43005CC */  sh        $s0, 0x5cc($at)
/* 13D8F4 8024A5B4 0200202D */  daddu     $a0, $s0, $zero
/* 13D8F8 8024A5B8 28820064 */  slti      $v0, $a0, 0x64
/* 13D8FC 8024A5BC 1040000A */  beqz      $v0, .L8024A5E8
/* 13D900 8024A5C0 24057FFF */   addiu    $a1, $zero, 0x7fff
/* 13D904 8024A5C4 3C038027 */  lui       $v1, 0x8027
/* 13D908 8024A5C8 24630400 */  addiu     $v1, $v1, 0x400
/* 13D90C 8024A5CC 00041040 */  sll       $v0, $a0, 1
/* 13D910 8024A5D0 00431821 */  addu      $v1, $v0, $v1
.L8024A5D4:
/* 13D914 8024A5D4 A4650000 */  sh        $a1, ($v1)
/* 13D918 8024A5D8 24840001 */  addiu     $a0, $a0, 1
/* 13D91C 8024A5DC 28820064 */  slti      $v0, $a0, 0x64
/* 13D920 8024A5E0 1440FFFC */  bnez      $v0, .L8024A5D4
/* 13D924 8024A5E4 24630002 */   addiu    $v1, $v1, 2
.L8024A5E8:
/* 13D928 8024A5E8 3C058027 */  lui       $a1, 0x8027
/* 13D92C 8024A5EC 24A504D0 */  addiu     $a1, $a1, 0x4d0
/* 13D930 8024A5F0 0000202D */  daddu     $a0, $zero, $zero
/* 13D934 8024A5F4 3C078027 */  lui       $a3, 0x8027
/* 13D938 8024A5F8 24E705CC */  addiu     $a3, $a3, 0x5cc
/* 13D93C 8024A5FC 24060001 */  addiu     $a2, $zero, 1
/* 13D940 8024A600 24090008 */  addiu     $t1, $zero, 8
/* 13D944 8024A604 24080008 */  addiu     $t0, $zero, 8
/* 13D948 8024A608 00A81821 */  addu      $v1, $a1, $t0
/* 13D94C 8024A60C 3C018027 */  lui       $at, 0x8027
/* 13D950 8024A610 AC2005C0 */  sw        $zero, 0x5c0($at)
/* 13D954 8024A614 3C018027 */  lui       $at, 0x8027
/* 13D958 8024A618 AC2005C8 */  sw        $zero, 0x5c8($at)
/* 13D95C 8024A61C 3C018027 */  lui       $at, 0x8027
/* 13D960 8024A620 AC2005C4 */  sw        $zero, 0x5c4($at)
/* 13D964 8024A624 3C018027 */  lui       $at, 0x8027
/* 13D968 8024A628 AC2005DC */  sw        $zero, 0x5dc($at)
/* 13D96C 8024A62C 3C018027 */  lui       $at, 0x8027
/* 13D970 8024A630 AC2004C8 */  sw        $zero, 0x4c8($at)
.L8024A634:
/* 13D974 8024A634 84E20000 */  lh        $v0, ($a3)
/* 13D978 8024A638 04420001 */  bltzl     $v0, .L8024A640
/* 13D97C 8024A63C 24420007 */   addiu    $v0, $v0, 7
.L8024A640:
/* 13D980 8024A640 000210C3 */  sra       $v0, $v0, 3
/* 13D984 8024A644 0082102A */  slt       $v0, $a0, $v0
/* 13D988 8024A648 1040000B */  beqz      $v0, .L8024A678
/* 13D98C 8024A64C 000410C0 */   sll      $v0, $a0, 3
/* 13D990 8024A650 24840001 */  addiu     $a0, $a0, 1
/* 13D994 8024A654 A062FFF9 */  sb        $v0, -7($v1)
/* 13D998 8024A658 A066FFFA */  sb        $a2, -6($v1)
/* 13D99C 8024A65C A069FFFB */  sb        $t1, -5($v1)
/* 13D9A0 8024A660 A0A60000 */  sb        $a2, ($a1)
/* 13D9A4 8024A664 AC62FFFC */  sw        $v0, -4($v1)
/* 13D9A8 8024A668 AC680000 */  sw        $t0, ($v1)
/* 13D9AC 8024A66C 2463000C */  addiu     $v1, $v1, 0xc
/* 13D9B0 8024A670 0809298D */  j         .L8024A634
/* 13D9B4 8024A674 24A5000C */   addiu    $a1, $a1, 0xc
.L8024A678:
/* 13D9B8 8024A678 94E20000 */  lhu       $v0, ($a3)
/* 13D9BC 8024A67C 30420007 */  andi      $v0, $v0, 7
/* 13D9C0 8024A680 10400016 */  beqz      $v0, .L8024A6DC
/* 13D9C4 8024A684 000418C0 */   sll      $v1, $a0, 3
/* 13D9C8 8024A688 24020001 */  addiu     $v0, $zero, 1
/* 13D9CC 8024A68C A0A30001 */  sb        $v1, 1($a1)
/* 13D9D0 8024A690 A0A20002 */  sb        $v0, 2($a1)
/* 13D9D4 8024A694 A0A20000 */  sb        $v0, ($a1)
/* 13D9D8 8024A698 84E60000 */  lh        $a2, ($a3)
/* 13D9DC 8024A69C ACA30004 */  sw        $v1, 4($a1)
/* 13D9E0 8024A6A0 04C10002 */  bgez      $a2, .L8024A6AC
/* 13D9E4 8024A6A4 00C0102D */   daddu    $v0, $a2, $zero
/* 13D9E8 8024A6A8 24C20007 */  addiu     $v0, $a2, 7
.L8024A6AC:
/* 13D9EC 8024A6AC 000210C3 */  sra       $v0, $v0, 3
/* 13D9F0 8024A6B0 000210C0 */  sll       $v0, $v0, 3
/* 13D9F4 8024A6B4 00C21023 */  subu      $v0, $a2, $v0
/* 13D9F8 8024A6B8 00021400 */  sll       $v0, $v0, 0x10
/* 13D9FC 8024A6BC 00021403 */  sra       $v0, $v0, 0x10
/* 13DA00 8024A6C0 ACA20008 */  sw        $v0, 8($a1)
/* 13DA04 8024A6C4 90A2000B */  lbu       $v0, 0xb($a1)
/* 13DA08 8024A6C8 24840001 */  addiu     $a0, $a0, 1
/* 13DA0C 8024A6CC 080929B6 */  j         .L8024A6D8
/* 13DA10 8024A6D0 A0A20003 */   sb       $v0, 3($a1)
.L8024A6D4:
/* 13DA14 8024A6D4 24840001 */  addiu     $a0, $a0, 1
.L8024A6D8:
/* 13DA18 8024A6D8 24A5000C */  addiu     $a1, $a1, 0xc
.L8024A6DC:
/* 13DA1C 8024A6DC 28820014 */  slti      $v0, $a0, 0x14
/* 13DA20 8024A6E0 5440FFFC */  bnel      $v0, $zero, .L8024A6D4
/* 13DA24 8024A6E4 A0A00000 */   sb       $zero, ($a1)
/* 13DA28 8024A6E8 0000202D */  daddu     $a0, $zero, $zero
/* 13DA2C 8024A6EC 0C09260A */  jal       pause_items_get_pos_y
/* 13DA30 8024A6F0 0080282D */   daddu    $a1, $a0, $zero
/* 13DA34 8024A6F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 13DA38 8024A6F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 13DA3C 8024A6FC 3C018027 */  lui       $at, 0x8027
/* 13DA40 8024A700 AC2205D4 */  sw        $v0, 0x5d4($at)
/* 13DA44 8024A704 3C018027 */  lui       $at, 0x8027
/* 13DA48 8024A708 AC2205D8 */  sw        $v0, 0x5d8($at)
/* 13DA4C 8024A70C 03E00008 */  jr        $ra
/* 13DA50 8024A710 27BD0018 */   addiu    $sp, $sp, 0x18
