.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_831DEC
/* 831DEC 802405EC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 831DF0 802405F0 AFB10024 */  sw        $s1, 0x24($sp)
/* 831DF4 802405F4 0080882D */  daddu     $s1, $a0, $zero
/* 831DF8 802405F8 3C05F840 */  lui       $a1, 0xf840
/* 831DFC 802405FC AFBF0044 */  sw        $ra, 0x44($sp)
/* 831E00 80240600 AFBE0040 */  sw        $fp, 0x40($sp)
/* 831E04 80240604 AFB7003C */  sw        $s7, 0x3c($sp)
/* 831E08 80240608 AFB60038 */  sw        $s6, 0x38($sp)
/* 831E0C 8024060C AFB50034 */  sw        $s5, 0x34($sp)
/* 831E10 80240610 AFB40030 */  sw        $s4, 0x30($sp)
/* 831E14 80240614 AFB3002C */  sw        $s3, 0x2c($sp)
/* 831E18 80240618 AFB20028 */  sw        $s2, 0x28($sp)
/* 831E1C 8024061C AFB00020 */  sw        $s0, 0x20($sp)
/* 831E20 80240620 8E3E0148 */  lw        $fp, 0x148($s1)
/* 831E24 80240624 0C0B1EAF */  jal       get_variable
/* 831E28 80240628 34A56268 */   ori      $a1, $a1, 0x6268
/* 831E2C 8024062C 0040802D */  daddu     $s0, $v0, $zero
/* 831E30 80240630 0220202D */  daddu     $a0, $s1, $zero
/* 831E34 80240634 3C05F840 */  lui       $a1, 0xf840
/* 831E38 80240638 0C0B1EAF */  jal       get_variable
/* 831E3C 8024063C 34A56269 */   ori      $a1, $a1, 0x6269
/* 831E40 80240640 0040B82D */  daddu     $s7, $v0, $zero
/* 831E44 80240644 0220202D */  daddu     $a0, $s1, $zero
/* 831E48 80240648 3C05F5DE */  lui       $a1, 0xf5de
/* 831E4C 8024064C 0C0B1EAF */  jal       get_variable
/* 831E50 80240650 34A502DE */   ori      $a1, $a1, 0x2de
/* 831E54 80240654 0040B02D */  daddu     $s6, $v0, $zero
/* 831E58 80240658 0220202D */  daddu     $a0, $s1, $zero
/* 831E5C 8024065C 3C05F5DE */  lui       $a1, 0xf5de
/* 831E60 80240660 0C0B1EAF */  jal       get_variable
/* 831E64 80240664 34A502DF */   ori      $a1, $a1, 0x2df
/* 831E68 80240668 0040A82D */  daddu     $s5, $v0, $zero
/* 831E6C 8024066C 93D3006D */  lbu       $s3, 0x6d($fp)
/* 831E70 80240670 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 831E74 80240674 A7B30010 */  sh        $s3, 0x10($sp)
/* 831E78 80240678 93D2006E */  lbu       $s2, 0x6e($fp)
/* 831E7C 8024067C 93C7006F */  lbu       $a3, 0x6f($fp)
/* 831E80 80240680 3274FFFF */  andi      $s4, $s3, 0xffff
/* 831E84 80240684 12820003 */  beq       $s4, $v0, .L80240694
/* 831E88 80240688 A7A7001E */   sh       $a3, 0x1e($sp)
/* 831E8C 8024068C 0000B82D */  daddu     $s7, $zero, $zero
/* 831E90 80240690 02E0802D */  daddu     $s0, $s7, $zero
.L80240694:
/* 831E94 80240694 3202FFFF */  andi      $v0, $s0, 0xffff
/* 831E98 80240698 14400016 */  bnez      $v0, .L802406F4
/* 831E9C 8024069C 0220202D */   daddu    $a0, $s1, $zero
/* 831EA0 802406A0 0C00A67F */  jal       rand_int
/* 831EA4 802406A4 24040064 */   addiu    $a0, $zero, 0x64
/* 831EA8 802406A8 2842001E */  slti      $v0, $v0, 0x1e
/* 831EAC 802406AC 10400011 */  beqz      $v0, .L802406F4
/* 831EB0 802406B0 0220202D */   daddu    $a0, $s1, $zero
/* 831EB4 802406B4 0C00A67F */  jal       rand_int
/* 831EB8 802406B8 2644FFFF */   addiu    $a0, $s2, -1
/* 831EBC 802406BC 0040A82D */  daddu     $s5, $v0, $zero
/* 831EC0 802406C0 0260B02D */  daddu     $s6, $s3, $zero
/* 831EC4 802406C4 0220202D */  daddu     $a0, $s1, $zero
/* 831EC8 802406C8 3C05F5DE */  lui       $a1, 0xf5de
/* 831ECC 802406CC 34A502DE */  ori       $a1, $a1, 0x2de
/* 831ED0 802406D0 0C0B2026 */  jal       set_variable
/* 831ED4 802406D4 0280302D */   daddu    $a2, $s4, $zero
/* 831ED8 802406D8 0220202D */  daddu     $a0, $s1, $zero
/* 831EDC 802406DC 3C05F5DE */  lui       $a1, 0xf5de
/* 831EE0 802406E0 34A502DF */  ori       $a1, $a1, 0x2df
/* 831EE4 802406E4 0C0B2026 */  jal       set_variable
/* 831EE8 802406E8 32A6FFFF */   andi     $a2, $s5, 0xffff
/* 831EEC 802406EC 24100001 */  addiu     $s0, $zero, 1
/* 831EF0 802406F0 0220202D */  daddu     $a0, $s1, $zero
.L802406F4:
/* 831EF4 802406F4 3C05F840 */  lui       $a1, 0xf840
/* 831EF8 802406F8 34A56268 */  ori       $a1, $a1, 0x6268
/* 831EFC 802406FC 0C0B2026 */  jal       set_variable
/* 831F00 80240700 3206FFFF */   andi     $a2, $s0, 0xffff
/* 831F04 80240704 0220202D */  daddu     $a0, $s1, $zero
/* 831F08 80240708 3C05F840 */  lui       $a1, 0xf840
/* 831F0C 8024070C 34A56269 */  ori       $a1, $a1, 0x6269
/* 831F10 80240710 0C0B2026 */  jal       set_variable
/* 831F14 80240714 32E6FFFF */   andi     $a2, $s7, 0xffff
/* 831F18 80240718 0000202D */  daddu     $a0, $zero, $zero
/* 831F1C 8024071C 3C05F5DE */  lui       $a1, 0xf5de
/* 831F20 80240720 0C0B1EAF */  jal       get_variable
/* 831F24 80240724 34A502E0 */   ori      $a1, $a1, 0x2e0
/* 831F28 80240728 0000202D */  daddu     $a0, $zero, $zero
/* 831F2C 8024072C 3C05F5DE */  lui       $a1, 0xf5de
/* 831F30 80240730 34A50180 */  ori       $a1, $a1, 0x180
/* 831F34 80240734 0C0B1EAF */  jal       get_variable
/* 831F38 80240738 0040802D */   daddu    $s0, $v0, $zero
/* 831F3C 8024073C 0040282D */  daddu     $a1, $v0, $zero
/* 831F40 80240740 0000182D */  daddu     $v1, $zero, $zero
/* 831F44 80240744 3C068024 */  lui       $a2, 0x8024
/* 831F48 80240748 24C666E8 */  addiu     $a2, $a2, 0x66e8
/* 831F4C 8024074C 00C0202D */  daddu     $a0, $a2, $zero
.L80240750:
/* 831F50 80240750 8C820000 */  lw        $v0, ($a0)
/* 831F54 80240754 00A2102A */  slt       $v0, $a1, $v0
/* 831F58 80240758 14400006 */  bnez      $v0, .L80240774
/* 831F5C 8024075C 000310C0 */   sll      $v0, $v1, 3
/* 831F60 80240760 24630001 */  addiu     $v1, $v1, 1
/* 831F64 80240764 28620008 */  slti      $v0, $v1, 8
/* 831F68 80240768 1440FFF9 */  bnez      $v0, .L80240750
/* 831F6C 8024076C 24840008 */   addiu    $a0, $a0, 8
/* 831F70 80240770 000310C0 */  sll       $v0, $v1, 3
.L80240774:
/* 831F74 80240774 00461021 */  addu      $v0, $v0, $a2
/* 831F78 80240778 8C420004 */  lw        $v0, 4($v0)
/* 831F7C 8024077C 97A30010 */  lhu       $v1, 0x10($sp)
/* 831F80 80240780 0202202A */  slt       $a0, $s0, $v0
/* 831F84 80240784 32C2FFFF */  andi      $v0, $s6, 0xffff
/* 831F88 80240788 14620008 */  bne       $v1, $v0, .L802407AC
/* 831F8C 8024078C 32A2FFFF */   andi     $v0, $s5, 0xffff
/* 831F90 80240790 97A7001E */  lhu       $a3, 0x1e($sp)
/* 831F94 80240794 14E20005 */  bne       $a3, $v0, .L802407AC
/* 831F98 80240798 32E2FFFF */   andi     $v0, $s7, 0xffff
/* 831F9C 8024079C 14400003 */  bnez      $v0, .L802407AC
/* 831FA0 802407A0 00000000 */   nop      
/* 831FA4 802407A4 14800008 */  bnez      $a0, .L802407C8
/* 831FA8 802407A8 24020001 */   addiu    $v0, $zero, 1
.L802407AC:
/* 831FAC 802407AC 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 831FB0 802407B0 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 831FB4 802407B4 80420075 */  lb        $v0, 0x75($v0)
/* 831FB8 802407B8 10400005 */  beqz      $v0, .L802407D0
/* 831FBC 802407BC 00000000 */   nop      
/* 831FC0 802407C0 10800003 */  beqz      $a0, .L802407D0
/* 831FC4 802407C4 24020001 */   addiu    $v0, $zero, 1
.L802407C8:
/* 831FC8 802407C8 080901F7 */  j         .L802407DC
/* 831FCC 802407CC AE220084 */   sw       $v0, 0x84($s1)
.L802407D0:
/* 831FD0 802407D0 0C00F9EB */  jal       kill_enemy
/* 831FD4 802407D4 03C0202D */   daddu    $a0, $fp, $zero
/* 831FD8 802407D8 AE200084 */  sw        $zero, 0x84($s1)
.L802407DC:
/* 831FDC 802407DC 8FBF0044 */  lw        $ra, 0x44($sp)
/* 831FE0 802407E0 8FBE0040 */  lw        $fp, 0x40($sp)
/* 831FE4 802407E4 8FB7003C */  lw        $s7, 0x3c($sp)
/* 831FE8 802407E8 8FB60038 */  lw        $s6, 0x38($sp)
/* 831FEC 802407EC 8FB50034 */  lw        $s5, 0x34($sp)
/* 831FF0 802407F0 8FB40030 */  lw        $s4, 0x30($sp)
/* 831FF4 802407F4 8FB3002C */  lw        $s3, 0x2c($sp)
/* 831FF8 802407F8 8FB20028 */  lw        $s2, 0x28($sp)
/* 831FFC 802407FC 8FB10024 */  lw        $s1, 0x24($sp)
/* 832000 80240800 8FB00020 */  lw        $s0, 0x20($sp)
/* 832004 80240804 24020002 */  addiu     $v0, $zero, 2
/* 832008 80240808 03E00008 */  jr        $ra
/* 83200C 8024080C 27BD0048 */   addiu    $sp, $sp, 0x48
