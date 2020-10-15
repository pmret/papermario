.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PartnerDamageEnemy
/* 1AE694 8027FDB4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AE698 8027FDB8 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AE69C 8027FDBC 0080902D */  daddu     $s2, $a0, $zero
/* 1AE6A0 8027FDC0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1AE6A4 8027FDC4 AFB40020 */  sw        $s4, 0x20($sp)
/* 1AE6A8 8027FDC8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AE6AC 8027FDCC AFB10014 */  sw        $s1, 0x14($sp)
/* 1AE6B0 8027FDD0 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AE6B4 8027FDD4 8E440148 */  lw        $a0, 0x148($s2)
/* 1AE6B8 8027FDD8 0C09A75B */  jal       get_actor
/* 1AE6BC 8027FDDC 8E50000C */   lw       $s0, 0xc($s2)
/* 1AE6C0 8027FDE0 8E140000 */  lw        $s4, ($s0)
/* 1AE6C4 8027FDE4 26100004 */  addiu     $s0, $s0, 4
/* 1AE6C8 8027FDE8 8E030000 */  lw        $v1, ($s0)
/* 1AE6CC 8027FDEC 26100004 */  addiu     $s0, $s0, 4
/* 1AE6D0 8027FDF0 0240202D */  daddu     $a0, $s2, $zero
/* 1AE6D4 8027FDF4 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 1AE6D8 8027FDF8 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 1AE6DC 8027FDFC 0040982D */  daddu     $s3, $v0, $zero
/* 1AE6E0 8027FE00 AE230188 */  sw        $v1, 0x188($s1)
/* 1AE6E4 8027FE04 8E030000 */  lw        $v1, ($s0)
/* 1AE6E8 8027FE08 26100004 */  addiu     $s0, $s0, 4
/* 1AE6EC 8027FE0C AE23018C */  sw        $v1, 0x18c($s1)
/* 1AE6F0 8027FE10 8E030000 */  lw        $v1, ($s0)
/* 1AE6F4 8027FE14 26100004 */  addiu     $s0, $s0, 4
/* 1AE6F8 8027FE18 AE230190 */  sw        $v1, 0x190($s1)
/* 1AE6FC 8027FE1C 8E050000 */  lw        $a1, ($s0)
/* 1AE700 8027FE20 0C0B1EAF */  jal       get_variable
/* 1AE704 8027FE24 26100004 */   addiu    $s0, $s0, 4
/* 1AE708 8027FE28 A622017E */  sh        $v0, 0x17e($s1)
/* 1AE70C 8027FE2C A2200198 */  sb        $zero, 0x198($s1)
/* 1AE710 8027FE30 8E100000 */  lw        $s0, ($s0)
/* 1AE714 8027FE34 24020030 */  addiu     $v0, $zero, 0x30
/* 1AE718 8027FE38 32030030 */  andi      $v1, $s0, 0x30
/* 1AE71C 8027FE3C 54620004 */  bnel      $v1, $v0, .L8027FE50
/* 1AE720 8027FE40 32020010 */   andi     $v0, $s0, 0x10
/* 1AE724 8027FE44 8E220000 */  lw        $v0, ($s1)
/* 1AE728 8027FE48 0809FFA4 */  j         .L8027FE90
/* 1AE72C 8027FE4C 34420030 */   ori      $v0, $v0, 0x30
.L8027FE50:
/* 1AE730 8027FE50 10400004 */  beqz      $v0, .L8027FE64
/* 1AE734 8027FE54 2403FFDF */   addiu    $v1, $zero, -0x21
/* 1AE738 8027FE58 8E220000 */  lw        $v0, ($s1)
/* 1AE73C 8027FE5C 0809FFA3 */  j         .L8027FE8C
/* 1AE740 8027FE60 34420010 */   ori      $v0, $v0, 0x10
.L8027FE64:
/* 1AE744 8027FE64 32020020 */  andi      $v0, $s0, 0x20
/* 1AE748 8027FE68 10400005 */  beqz      $v0, .L8027FE80
/* 1AE74C 8027FE6C 2403FFEF */   addiu    $v1, $zero, -0x11
/* 1AE750 8027FE70 8E220000 */  lw        $v0, ($s1)
/* 1AE754 8027FE74 00431024 */  and       $v0, $v0, $v1
/* 1AE758 8027FE78 0809FFA4 */  j         .L8027FE90
/* 1AE75C 8027FE7C 34420020 */   ori      $v0, $v0, 0x20
.L8027FE80:
/* 1AE760 8027FE80 8E220000 */  lw        $v0, ($s1)
/* 1AE764 8027FE84 00431024 */  and       $v0, $v0, $v1
/* 1AE768 8027FE88 2403FFDF */  addiu     $v1, $zero, -0x21
.L8027FE8C:
/* 1AE76C 8027FE8C 00431024 */  and       $v0, $v0, $v1
.L8027FE90:
/* 1AE770 8027FE90 AE220000 */  sw        $v0, ($s1)
/* 1AE774 8027FE94 32020040 */  andi      $v0, $s0, 0x40
/* 1AE778 8027FE98 10400007 */  beqz      $v0, .L8027FEB8
/* 1AE77C 8027FE9C 2404FFBF */   addiu    $a0, $zero, -0x41
/* 1AE780 8027FEA0 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AE784 8027FEA4 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AE788 8027FEA8 8C620000 */  lw        $v0, ($v1)
/* 1AE78C 8027FEAC 34420040 */  ori       $v0, $v0, 0x40
/* 1AE790 8027FEB0 0809FFB3 */  j         .L8027FECC
/* 1AE794 8027FEB4 AC620000 */   sw       $v0, ($v1)
.L8027FEB8:
/* 1AE798 8027FEB8 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AE79C 8027FEBC 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AE7A0 8027FEC0 8C430000 */  lw        $v1, ($v0)
/* 1AE7A4 8027FEC4 00641824 */  and       $v1, $v1, $a0
/* 1AE7A8 8027FEC8 AC430000 */  sw        $v1, ($v0)
.L8027FECC:
/* 1AE7AC 8027FECC 32020200 */  andi      $v0, $s0, 0x200
/* 1AE7B0 8027FED0 10400007 */  beqz      $v0, .L8027FEF0
/* 1AE7B4 8027FED4 2404FDFF */   addiu    $a0, $zero, -0x201
/* 1AE7B8 8027FED8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AE7BC 8027FEDC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AE7C0 8027FEE0 8C620000 */  lw        $v0, ($v1)
/* 1AE7C4 8027FEE4 34420200 */  ori       $v0, $v0, 0x200
/* 1AE7C8 8027FEE8 0809FFC1 */  j         .L8027FF04
/* 1AE7CC 8027FEEC AC620000 */   sw       $v0, ($v1)
.L8027FEF0:
/* 1AE7D0 8027FEF0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AE7D4 8027FEF4 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AE7D8 8027FEF8 8C430000 */  lw        $v1, ($v0)
/* 1AE7DC 8027FEFC 00641824 */  and       $v1, $v1, $a0
/* 1AE7E0 8027FF00 AC430000 */  sw        $v1, ($v0)
.L8027FF04:
/* 1AE7E4 8027FF04 32020080 */  andi      $v0, $s0, 0x80
/* 1AE7E8 8027FF08 10400007 */  beqz      $v0, .L8027FF28
/* 1AE7EC 8027FF0C 2404FF7F */   addiu    $a0, $zero, -0x81
/* 1AE7F0 8027FF10 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AE7F4 8027FF14 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AE7F8 8027FF18 8C620000 */  lw        $v0, ($v1)
/* 1AE7FC 8027FF1C 34420080 */  ori       $v0, $v0, 0x80
/* 1AE800 8027FF20 0809FFCF */  j         .L8027FF3C
/* 1AE804 8027FF24 AC620000 */   sw       $v0, ($v1)
.L8027FF28:
/* 1AE808 8027FF28 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AE80C 8027FF2C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AE810 8027FF30 8C430000 */  lw        $v1, ($v0)
/* 1AE814 8027FF34 00641824 */  and       $v1, $v1, $a0
/* 1AE818 8027FF38 AC430000 */  sw        $v1, ($v0)
.L8027FF3C:
/* 1AE81C 8027FF3C 32020800 */  andi      $v0, $s0, 0x800
/* 1AE820 8027FF40 10400007 */  beqz      $v0, .L8027FF60
/* 1AE824 8027FF44 2404F7FF */   addiu    $a0, $zero, -0x801
/* 1AE828 8027FF48 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AE82C 8027FF4C 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AE830 8027FF50 8C620000 */  lw        $v0, ($v1)
/* 1AE834 8027FF54 34420800 */  ori       $v0, $v0, 0x800
/* 1AE838 8027FF58 0809FFDD */  j         .L8027FF74
/* 1AE83C 8027FF5C AC620000 */   sw       $v0, ($v1)
.L8027FF60:
/* 1AE840 8027FF60 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AE844 8027FF64 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1AE848 8027FF68 8C430000 */  lw        $v1, ($v0)
/* 1AE84C 8027FF6C 00641824 */  and       $v1, $v1, $a0
/* 1AE850 8027FF70 AC430000 */  sw        $v1, ($v0)
.L8027FF74:
/* 1AE854 8027FF74 96620428 */  lhu       $v0, 0x428($s3)
/* 1AE858 8027FF78 92230193 */  lbu       $v1, 0x193($s1)
/* 1AE85C 8027FF7C A62201A0 */  sh        $v0, 0x1a0($s1)
/* 1AE860 8027FF80 92620426 */  lbu       $v0, 0x426($s3)
/* 1AE864 8027FF84 A2230194 */  sb        $v1, 0x194($s1)
/* 1AE868 8027FF88 306300FF */  andi      $v1, $v1, 0xff
/* 1AE86C 8027FF8C A22201A2 */  sb        $v0, 0x1a2($s1)
/* 1AE870 8027FF90 240200FF */  addiu     $v0, $zero, 0xff
/* 1AE874 8027FF94 50620001 */  beql      $v1, $v0, .L8027FF9C
/* 1AE878 8027FF98 A2200194 */   sb       $zero, 0x194($s1)
.L8027FF9C:
/* 1AE87C 8027FF9C 8E220190 */  lw        $v0, 0x190($s1)
/* 1AE880 8027FFA0 30420F00 */  andi      $v0, $v0, 0xf00
/* 1AE884 8027FFA4 00021203 */  sra       $v0, $v0, 8
/* 1AE888 8027FFA8 0C09F8CA */  jal       calc_partner_damage_enemy
/* 1AE88C 8027FFAC A2220195 */   sb       $v0, 0x195($s1)
/* 1AE890 8027FFB0 0440000B */  bltz      $v0, .L8027FFE0
/* 1AE894 8027FFB4 0240202D */   daddu    $a0, $s2, $zero
/* 1AE898 8027FFB8 0280282D */  daddu     $a1, $s4, $zero
/* 1AE89C 8027FFBC 0C0B2026 */  jal       set_variable
/* 1AE8A0 8027FFC0 0040302D */   daddu    $a2, $v0, $zero
/* 1AE8A4 8027FFC4 0C0B1069 */  jal       does_script_exist_by_ref
/* 1AE8A8 8027FFC8 0240202D */   daddu    $a0, $s2, $zero
/* 1AE8AC 8027FFCC 0040182D */  daddu     $v1, $v0, $zero
/* 1AE8B0 8027FFD0 10600004 */  beqz      $v1, .L8027FFE4
/* 1AE8B4 8027FFD4 240200FF */   addiu    $v0, $zero, 0xff
/* 1AE8B8 8027FFD8 0809FFF9 */  j         .L8027FFE4
/* 1AE8BC 8027FFDC 24020002 */   addiu    $v0, $zero, 2
.L8027FFE0:
/* 1AE8C0 8027FFE0 240200FF */  addiu     $v0, $zero, 0xff
.L8027FFE4:
/* 1AE8C4 8027FFE4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1AE8C8 8027FFE8 8FB40020 */  lw        $s4, 0x20($sp)
/* 1AE8CC 8027FFEC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AE8D0 8027FFF0 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AE8D4 8027FFF4 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AE8D8 8027FFF8 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AE8DC 8027FFFC 03E00008 */  jr        $ra
/* 1AE8E0 80280000 27BD0028 */   addiu    $sp, $sp, 0x28
