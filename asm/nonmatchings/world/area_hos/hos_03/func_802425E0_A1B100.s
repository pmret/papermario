.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425E0_A1D6E0
/* A1D6E0 802425E0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A1D6E4 802425E4 AFB10024 */  sw        $s1, 0x24($sp)
/* A1D6E8 802425E8 0080882D */  daddu     $s1, $a0, $zero
/* A1D6EC 802425EC 3C05F840 */  lui       $a1, 0xf840
/* A1D6F0 802425F0 AFBF0044 */  sw        $ra, 0x44($sp)
/* A1D6F4 802425F4 AFBE0040 */  sw        $fp, 0x40($sp)
/* A1D6F8 802425F8 AFB7003C */  sw        $s7, 0x3c($sp)
/* A1D6FC 802425FC AFB60038 */  sw        $s6, 0x38($sp)
/* A1D700 80242600 AFB50034 */  sw        $s5, 0x34($sp)
/* A1D704 80242604 AFB40030 */  sw        $s4, 0x30($sp)
/* A1D708 80242608 AFB3002C */  sw        $s3, 0x2c($sp)
/* A1D70C 8024260C AFB20028 */  sw        $s2, 0x28($sp)
/* A1D710 80242610 AFB00020 */  sw        $s0, 0x20($sp)
/* A1D714 80242614 8E3E0148 */  lw        $fp, 0x148($s1)
/* A1D718 80242618 0C0B1EAF */  jal       get_variable
/* A1D71C 8024261C 34A56268 */   ori      $a1, $a1, 0x6268
/* A1D720 80242620 0040802D */  daddu     $s0, $v0, $zero
/* A1D724 80242624 0220202D */  daddu     $a0, $s1, $zero
/* A1D728 80242628 3C05F840 */  lui       $a1, 0xf840
/* A1D72C 8024262C 0C0B1EAF */  jal       get_variable
/* A1D730 80242630 34A56269 */   ori      $a1, $a1, 0x6269
/* A1D734 80242634 0040B82D */  daddu     $s7, $v0, $zero
/* A1D738 80242638 0220202D */  daddu     $a0, $s1, $zero
/* A1D73C 8024263C 3C05F5DE */  lui       $a1, 0xf5de
/* A1D740 80242640 0C0B1EAF */  jal       get_variable
/* A1D744 80242644 34A502DE */   ori      $a1, $a1, 0x2de
/* A1D748 80242648 0040B02D */  daddu     $s6, $v0, $zero
/* A1D74C 8024264C 0220202D */  daddu     $a0, $s1, $zero
/* A1D750 80242650 3C05F5DE */  lui       $a1, 0xf5de
/* A1D754 80242654 0C0B1EAF */  jal       get_variable
/* A1D758 80242658 34A502DF */   ori      $a1, $a1, 0x2df
/* A1D75C 8024265C 0040A82D */  daddu     $s5, $v0, $zero
/* A1D760 80242660 93D3006D */  lbu       $s3, 0x6d($fp)
/* A1D764 80242664 32C2FFFF */  andi      $v0, $s6, 0xffff
/* A1D768 80242668 A7B30010 */  sh        $s3, 0x10($sp)
/* A1D76C 8024266C 93D2006E */  lbu       $s2, 0x6e($fp)
/* A1D770 80242670 93C7006F */  lbu       $a3, 0x6f($fp)
/* A1D774 80242674 3274FFFF */  andi      $s4, $s3, 0xffff
/* A1D778 80242678 12820003 */  beq       $s4, $v0, .L80242688
/* A1D77C 8024267C A7A7001E */   sh       $a3, 0x1e($sp)
/* A1D780 80242680 0000B82D */  daddu     $s7, $zero, $zero
/* A1D784 80242684 02E0802D */  daddu     $s0, $s7, $zero
.L80242688:
/* A1D788 80242688 3202FFFF */  andi      $v0, $s0, 0xffff
/* A1D78C 8024268C 14400016 */  bnez      $v0, .L802426E8
/* A1D790 80242690 0220202D */   daddu    $a0, $s1, $zero
/* A1D794 80242694 0C00A67F */  jal       rand_int
/* A1D798 80242698 24040064 */   addiu    $a0, $zero, 0x64
/* A1D79C 8024269C 2842001E */  slti      $v0, $v0, 0x1e
/* A1D7A0 802426A0 10400011 */  beqz      $v0, .L802426E8
/* A1D7A4 802426A4 0220202D */   daddu    $a0, $s1, $zero
/* A1D7A8 802426A8 0C00A67F */  jal       rand_int
/* A1D7AC 802426AC 2644FFFF */   addiu    $a0, $s2, -1
/* A1D7B0 802426B0 0040A82D */  daddu     $s5, $v0, $zero
/* A1D7B4 802426B4 0260B02D */  daddu     $s6, $s3, $zero
/* A1D7B8 802426B8 0220202D */  daddu     $a0, $s1, $zero
/* A1D7BC 802426BC 3C05F5DE */  lui       $a1, 0xf5de
/* A1D7C0 802426C0 34A502DE */  ori       $a1, $a1, 0x2de
/* A1D7C4 802426C4 0C0B2026 */  jal       set_variable
/* A1D7C8 802426C8 0280302D */   daddu    $a2, $s4, $zero
/* A1D7CC 802426CC 0220202D */  daddu     $a0, $s1, $zero
/* A1D7D0 802426D0 3C05F5DE */  lui       $a1, 0xf5de
/* A1D7D4 802426D4 34A502DF */  ori       $a1, $a1, 0x2df
/* A1D7D8 802426D8 0C0B2026 */  jal       set_variable
/* A1D7DC 802426DC 32A6FFFF */   andi     $a2, $s5, 0xffff
/* A1D7E0 802426E0 24100001 */  addiu     $s0, $zero, 1
/* A1D7E4 802426E4 0220202D */  daddu     $a0, $s1, $zero
.L802426E8:
/* A1D7E8 802426E8 3C05F840 */  lui       $a1, 0xf840
/* A1D7EC 802426EC 34A56268 */  ori       $a1, $a1, 0x6268
/* A1D7F0 802426F0 0C0B2026 */  jal       set_variable
/* A1D7F4 802426F4 3206FFFF */   andi     $a2, $s0, 0xffff
/* A1D7F8 802426F8 0220202D */  daddu     $a0, $s1, $zero
/* A1D7FC 802426FC 3C05F840 */  lui       $a1, 0xf840
/* A1D800 80242700 34A56269 */  ori       $a1, $a1, 0x6269
/* A1D804 80242704 0C0B2026 */  jal       set_variable
/* A1D808 80242708 32E6FFFF */   andi     $a2, $s7, 0xffff
/* A1D80C 8024270C 0000202D */  daddu     $a0, $zero, $zero
/* A1D810 80242710 3C05F5DE */  lui       $a1, 0xf5de
/* A1D814 80242714 0C0B1EAF */  jal       get_variable
/* A1D818 80242718 34A502E0 */   ori      $a1, $a1, 0x2e0
/* A1D81C 8024271C 0000202D */  daddu     $a0, $zero, $zero
/* A1D820 80242720 3C05F5DE */  lui       $a1, 0xf5de
/* A1D824 80242724 34A50180 */  ori       $a1, $a1, 0x180
/* A1D828 80242728 0C0B1EAF */  jal       get_variable
/* A1D82C 8024272C 0040802D */   daddu    $s0, $v0, $zero
/* A1D830 80242730 0040282D */  daddu     $a1, $v0, $zero
/* A1D834 80242734 0000182D */  daddu     $v1, $zero, $zero
/* A1D838 80242738 3C068025 */  lui       $a2, 0x8025
/* A1D83C 8024273C 24C680C0 */  addiu     $a2, $a2, -0x7f40
/* A1D840 80242740 00C0202D */  daddu     $a0, $a2, $zero
.L80242744:
/* A1D844 80242744 8C820000 */  lw        $v0, ($a0)
/* A1D848 80242748 00A2102A */  slt       $v0, $a1, $v0
/* A1D84C 8024274C 14400006 */  bnez      $v0, .L80242768
/* A1D850 80242750 000310C0 */   sll      $v0, $v1, 3
/* A1D854 80242754 24630001 */  addiu     $v1, $v1, 1
/* A1D858 80242758 28620008 */  slti      $v0, $v1, 8
/* A1D85C 8024275C 1440FFF9 */  bnez      $v0, .L80242744
/* A1D860 80242760 24840008 */   addiu    $a0, $a0, 8
/* A1D864 80242764 000310C0 */  sll       $v0, $v1, 3
.L80242768:
/* A1D868 80242768 00461021 */  addu      $v0, $v0, $a2
/* A1D86C 8024276C 8C420004 */  lw        $v0, 4($v0)
/* A1D870 80242770 97A30010 */  lhu       $v1, 0x10($sp)
/* A1D874 80242774 0202202A */  slt       $a0, $s0, $v0
/* A1D878 80242778 32C2FFFF */  andi      $v0, $s6, 0xffff
/* A1D87C 8024277C 14620008 */  bne       $v1, $v0, .L802427A0
/* A1D880 80242780 32A2FFFF */   andi     $v0, $s5, 0xffff
/* A1D884 80242784 97A7001E */  lhu       $a3, 0x1e($sp)
/* A1D888 80242788 14E20005 */  bne       $a3, $v0, .L802427A0
/* A1D88C 8024278C 32E2FFFF */   andi     $v0, $s7, 0xffff
/* A1D890 80242790 14400003 */  bnez      $v0, .L802427A0
/* A1D894 80242794 00000000 */   nop      
/* A1D898 80242798 14800008 */  bnez      $a0, .L802427BC
/* A1D89C 8024279C 24020001 */   addiu    $v0, $zero, 1
.L802427A0:
/* A1D8A0 802427A0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A1D8A4 802427A4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A1D8A8 802427A8 80420075 */  lb        $v0, 0x75($v0)
/* A1D8AC 802427AC 10400005 */  beqz      $v0, .L802427C4
/* A1D8B0 802427B0 00000000 */   nop      
/* A1D8B4 802427B4 10800003 */  beqz      $a0, .L802427C4
/* A1D8B8 802427B8 24020001 */   addiu    $v0, $zero, 1
.L802427BC:
/* A1D8BC 802427BC 080909F4 */  j         .L802427D0
/* A1D8C0 802427C0 AE220084 */   sw       $v0, 0x84($s1)
.L802427C4:
/* A1D8C4 802427C4 0C00F9EB */  jal       kill_enemy
/* A1D8C8 802427C8 03C0202D */   daddu    $a0, $fp, $zero
/* A1D8CC 802427CC AE200084 */  sw        $zero, 0x84($s1)
.L802427D0:
/* A1D8D0 802427D0 8FBF0044 */  lw        $ra, 0x44($sp)
/* A1D8D4 802427D4 8FBE0040 */  lw        $fp, 0x40($sp)
/* A1D8D8 802427D8 8FB7003C */  lw        $s7, 0x3c($sp)
/* A1D8DC 802427DC 8FB60038 */  lw        $s6, 0x38($sp)
/* A1D8E0 802427E0 8FB50034 */  lw        $s5, 0x34($sp)
/* A1D8E4 802427E4 8FB40030 */  lw        $s4, 0x30($sp)
/* A1D8E8 802427E8 8FB3002C */  lw        $s3, 0x2c($sp)
/* A1D8EC 802427EC 8FB20028 */  lw        $s2, 0x28($sp)
/* A1D8F0 802427F0 8FB10024 */  lw        $s1, 0x24($sp)
/* A1D8F4 802427F4 8FB00020 */  lw        $s0, 0x20($sp)
/* A1D8F8 802427F8 24020002 */  addiu     $v0, $zero, 2
/* A1D8FC 802427FC 03E00008 */  jr        $ra
/* A1D900 80242800 27BD0048 */   addiu    $sp, $sp, 0x48
