.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BDDF0_324740
/* 324740 802BDDF0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 324744 802BDDF4 AFB10024 */  sw        $s1, 0x24($sp)
/* 324748 802BDDF8 0080882D */  daddu     $s1, $a0, $zero
/* 32474C 802BDDFC AFB00020 */  sw        $s0, 0x20($sp)
/* 324750 802BDE00 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 324754 802BDE04 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 324758 802BDE08 240200FF */  addiu     $v0, $zero, 0xff
/* 32475C 802BDE0C 0000282D */  daddu     $a1, $zero, $zero
/* 324760 802BDE10 00A0302D */  daddu     $a2, $a1, $zero
/* 324764 802BDE14 00A0382D */  daddu     $a3, $a1, $zero
/* 324768 802BDE18 AFBF0034 */  sw        $ra, 0x34($sp)
/* 32476C 802BDE1C AFB40030 */  sw        $s4, 0x30($sp)
/* 324770 802BDE20 AFB3002C */  sw        $s3, 0x2c($sp)
/* 324774 802BDE24 AFB20028 */  sw        $s2, 0x28($sp)
/* 324778 802BDE28 A202000E */  sb        $v0, 0xe($s0)
/* 32477C 802BDE2C AFA00010 */  sw        $zero, 0x10($sp)
/* 324780 802BDE30 AFA00014 */  sw        $zero, 0x14($sp)
/* 324784 802BDE34 0C00F589 */  jal       func_8003D624
/* 324788 802BDE38 AFA00018 */   sw       $zero, 0x18($sp)
/* 32478C 802BDE3C 8E240078 */  lw        $a0, 0x78($s1)
/* 324790 802BDE40 24020011 */  addiu     $v0, $zero, 0x11
/* 324794 802BDE44 0C044181 */  jal       get_shadow_by_index
/* 324798 802BDE48 A22200AA */   sb       $v0, 0xaa($s1)
/* 32479C 802BDE4C 9203000E */  lbu       $v1, 0xe($s0)
/* 3247A0 802BDE50 3C12802C */  lui       $s2, %hi(D_802BE0C4)
/* 3247A4 802BDE54 2652E0C4 */  addiu     $s2, $s2, %lo(D_802BE0C4)
/* 3247A8 802BDE58 00031842 */  srl       $v1, $v1, 1
/* 3247AC 802BDE5C A0430005 */  sb        $v1, 5($v0)
/* 3247B0 802BDE60 8E420000 */  lw        $v0, ($s2)
/* 3247B4 802BDE64 3C138011 */  lui       $s3, %hi(gPartnerActionStatus)
/* 3247B8 802BDE68 2673EBB0 */  addiu     $s3, $s3, %lo(gPartnerActionStatus)
/* 3247BC 802BDE6C 10400003 */  beqz      $v0, .L802BDE7C
/* 3247C0 802BDE70 0200A02D */   daddu    $s4, $s0, $zero
/* 3247C4 802BDE74 0C038069 */  jal       enable_player_input
/* 3247C8 802BDE78 00000000 */   nop
.L802BDE7C:
/* 3247CC 802BDE7C 3C03FFFF */  lui       $v1, 0xffff
/* 3247D0 802BDE80 8E020000 */  lw        $v0, ($s0)
/* 3247D4 802BDE84 34637FFD */  ori       $v1, $v1, 0x7ffd
/* 3247D8 802BDE88 00431024 */  and       $v0, $v0, $v1
/* 3247DC 802BDE8C AE020000 */  sw        $v0, ($s0)
/* 3247E0 802BDE90 8E220000 */  lw        $v0, ($s1)
/* 3247E4 802BDE94 2403FFBD */  addiu     $v1, $zero, -0x43
/* 3247E8 802BDE98 00431024 */  and       $v0, $v0, $v1
/* 3247EC 802BDE9C AE220000 */  sw        $v0, ($s1)
/* 3247F0 802BDEA0 8E020000 */  lw        $v0, ($s0)
/* 3247F4 802BDEA4 0000202D */  daddu     $a0, $zero, $zero
/* 3247F8 802BDEA8 30420800 */  andi      $v0, $v0, 0x800
/* 3247FC 802BDEAC 10400002 */  beqz      $v0, .L802BDEB8
/* 324800 802BDEB0 AE400000 */   sw       $zero, ($s2)
/* 324804 802BDEB4 24040017 */  addiu     $a0, $zero, 0x17
.L802BDEB8:
/* 324808 802BDEB8 0C039769 */  jal       set_action_state
/* 32480C 802BDEBC 00000000 */   nop
/* 324810 802BDEC0 0220202D */  daddu     $a0, $s1, $zero
/* 324814 802BDEC4 A2600000 */  sb        $zero, ($s3)
/* 324818 802BDEC8 A2600003 */  sb        $zero, 3($s3)
/* 32481C 802BDECC 8E820000 */  lw        $v0, ($s4)
/* 324820 802BDED0 2403FEFF */  addiu     $v1, $zero, -0x101
/* 324824 802BDED4 00431024 */  and       $v0, $v0, $v1
/* 324828 802BDED8 0C03BD17 */  jal       partner_clear_player_tracking
/* 32482C 802BDEDC AE820000 */   sw       $v0, ($s4)
/* 324830 802BDEE0 8FBF0034 */  lw        $ra, 0x34($sp)
/* 324834 802BDEE4 8FB40030 */  lw        $s4, 0x30($sp)
/* 324838 802BDEE8 8FB3002C */  lw        $s3, 0x2c($sp)
/* 32483C 802BDEEC 8FB20028 */  lw        $s2, 0x28($sp)
/* 324840 802BDEF0 8FB10024 */  lw        $s1, 0x24($sp)
/* 324844 802BDEF4 8FB00020 */  lw        $s0, 0x20($sp)
/* 324848 802BDEF8 3C01802C */  lui       $at, %hi(D_802BE0C0)
/* 32484C 802BDEFC AC20E0C0 */  sw        $zero, %lo(D_802BE0C0)($at)
/* 324850 802BDF00 03E00008 */  jr        $ra
/* 324854 802BDF04 27BD0038 */   addiu    $sp, $sp, 0x38
