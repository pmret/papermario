.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C0
/* 9BD720 802400C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9BD724 802400C4 3C048024 */  lui       $a0, 0x8024
/* 9BD728 802400C8 24845234 */  addiu     $a0, $a0, 0x5234
/* 9BD72C 802400CC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9BD730 802400D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9BD734 802400D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9BD738 802400D8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9BD73C 802400DC 8C830000 */  lw        $v1, ($a0)
/* 9BD740 802400E0 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 9BD744 802400E4 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 9BD748 802400E8 28620003 */  slti      $v0, $v1, 3
/* 9BD74C 802400EC 50400007 */  beql      $v0, $zero, .L8024010C
/* 9BD750 802400F0 24020003 */   addiu    $v0, $zero, 3
/* 9BD754 802400F4 1C60000C */  bgtz      $v1, .L80240128
/* 9BD758 802400F8 24620001 */   addiu    $v0, $v1, 1
/* 9BD75C 802400FC 10600007 */  beqz      $v1, .L8024011C
/* 9BD760 80240100 0000102D */   daddu    $v0, $zero, $zero
/* 9BD764 80240104 0809006E */  j         .L802401B8
/* 9BD768 80240108 00000000 */   nop      
.L8024010C:
/* 9BD76C 8024010C 10620008 */  beq       $v1, $v0, .L80240130
/* 9BD770 80240110 0000102D */   daddu    $v0, $zero, $zero
/* 9BD774 80240114 0809006E */  j         .L802401B8
/* 9BD778 80240118 00000000 */   nop      
.L8024011C:
/* 9BD77C 8024011C 24020001 */  addiu     $v0, $zero, 1
/* 9BD780 80240120 0809006D */  j         .L802401B4
/* 9BD784 80240124 AC820000 */   sw       $v0, ($a0)
.L80240128:
/* 9BD788 80240128 0809006D */  j         .L802401B4
/* 9BD78C 8024012C AC820000 */   sw       $v0, ($a0)
.L80240130:
/* 9BD790 80240130 C6200028 */  lwc1      $f0, 0x28($s1)
/* 9BD794 80240134 3C0141F0 */  lui       $at, 0x41f0
/* 9BD798 80240138 44811000 */  mtc1      $at, $f2
/* 9BD79C 8024013C 3C108011 */  lui       $s0, 0x8011
/* 9BD7A0 80240140 2610C930 */  addiu     $s0, $s0, -0x36d0
/* 9BD7A4 80240144 46020001 */  sub.s     $f0, $f0, $f2
/* 9BD7A8 80240148 8E040000 */  lw        $a0, ($s0)
/* 9BD7AC 8024014C E4800038 */  swc1      $f0, 0x38($a0)
/* 9BD7B0 80240150 C6200030 */  lwc1      $f0, 0x30($s1)
/* 9BD7B4 80240154 46020000 */  add.s     $f0, $f0, $f2
/* 9BD7B8 80240158 0C03BD17 */  jal       clear_partner_move_history
/* 9BD7BC 8024015C E4800040 */   swc1     $f0, 0x40($a0)
/* 9BD7C0 80240160 C6200028 */  lwc1      $f0, 0x28($s1)
/* 9BD7C4 80240164 C6220030 */  lwc1      $f2, 0x30($s1)
/* 9BD7C8 80240168 4600010D */  trunc.w.s $f4, $f0
/* 9BD7CC 8024016C 44042000 */  mfc1      $a0, $f4
/* 9BD7D0 80240170 4600110D */  trunc.w.s $f4, $f2
/* 9BD7D4 80240174 44052000 */  mfc1      $a1, $f4
/* 9BD7D8 80240178 0C03BCF0 */  jal       func_800EF3C0
/* 9BD7DC 8024017C 00000000 */   nop      
/* 9BD7E0 80240180 0C03BCF5 */  jal       func_800EF3D4
/* 9BD7E4 80240184 0000202D */   daddu    $a0, $zero, $zero
/* 9BD7E8 80240188 3C0142B4 */  lui       $at, 0x42b4
/* 9BD7EC 8024018C 4481A000 */  mtc1      $at, $f20
/* 9BD7F0 80240190 8E040000 */  lw        $a0, ($s0)
/* 9BD7F4 80240194 4405A000 */  mfc1      $a1, $f20
/* 9BD7F8 80240198 0C00ECD0 */  jal       set_npc_yaw
/* 9BD7FC 8024019C 00000000 */   nop      
/* 9BD800 802401A0 24020002 */  addiu     $v0, $zero, 2
/* 9BD804 802401A4 E6340080 */  swc1      $f20, 0x80($s1)
/* 9BD808 802401A8 E6340084 */  swc1      $f20, 0x84($s1)
/* 9BD80C 802401AC 0809006E */  j         .L802401B8
/* 9BD810 802401B0 AE2000A8 */   sw       $zero, 0xa8($s1)
.L802401B4:
/* 9BD814 802401B4 0000102D */  daddu     $v0, $zero, $zero
.L802401B8:
/* 9BD818 802401B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9BD81C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9BD820 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9BD824 802401C4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9BD828 802401C8 03E00008 */  jr        $ra
/* 9BD82C 802401CC 27BD0028 */   addiu    $sp, $sp, 0x28
