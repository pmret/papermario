.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241668_A3AB48
/* A3AB48 80241668 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A3AB4C 8024166C AFBE0030 */  sw        $fp, 0x30($sp)
/* A3AB50 80241670 0080F02D */  daddu     $fp, $a0, $zero
/* A3AB54 80241674 0000202D */  daddu     $a0, $zero, $zero
/* A3AB58 80241678 3C05F5DE */  lui       $a1, 0xf5de
/* A3AB5C 8024167C 34A50180 */  ori       $a1, $a1, 0x180
/* A3AB60 80241680 AFBF0034 */  sw        $ra, 0x34($sp)
/* A3AB64 80241684 AFB7002C */  sw        $s7, 0x2c($sp)
/* A3AB68 80241688 AFB60028 */  sw        $s6, 0x28($sp)
/* A3AB6C 8024168C AFB50024 */  sw        $s5, 0x24($sp)
/* A3AB70 80241690 AFB40020 */  sw        $s4, 0x20($sp)
/* A3AB74 80241694 AFB3001C */  sw        $s3, 0x1c($sp)
/* A3AB78 80241698 AFB20018 */  sw        $s2, 0x18($sp)
/* A3AB7C 8024169C AFB10014 */  sw        $s1, 0x14($sp)
/* A3AB80 802416A0 0C0B1EAF */  jal       get_variable
/* A3AB84 802416A4 AFB00010 */   sw       $s0, 0x10($sp)
/* A3AB88 802416A8 0040A82D */  daddu     $s5, $v0, $zero
/* A3AB8C 802416AC 0000A02D */  daddu     $s4, $zero, $zero
/* A3AB90 802416B0 0280802D */  daddu     $s0, $s4, $zero
/* A3AB94 802416B4 3C12F971 */  lui       $s2, 0xf971
/* A3AB98 802416B8 365288F4 */  ori       $s2, $s2, 0x88f4
/* A3AB9C 802416BC 3C118024 */  lui       $s1, %hi(D_80244C4C_A3E12C)
/* A3ABA0 802416C0 26314C4C */  addiu     $s1, $s1, %lo(D_80244C4C_A3E12C)
/* A3ABA4 802416C4 AFC00088 */  sw        $zero, 0x88($fp)
.L802416C8:
/* A3ABA8 802416C8 8E220004 */  lw        $v0, 4($s1)
/* A3ABAC 802416CC 02A2102A */  slt       $v0, $s5, $v0
/* A3ABB0 802416D0 5440000C */  bnel      $v0, $zero, .L80241704
/* A3ABB4 802416D4 26100001 */   addiu    $s0, $s0, 1
/* A3ABB8 802416D8 8E250000 */  lw        $a1, ($s1)
/* A3ABBC 802416DC 0C0B1EAF */  jal       get_variable
/* A3ABC0 802416E0 0000202D */   daddu    $a0, $zero, $zero
/* A3ABC4 802416E4 54400007 */  bnel      $v0, $zero, .L80241704
/* A3ABC8 802416E8 26100001 */   addiu    $s0, $s0, 1
/* A3ABCC 802416EC 0000202D */  daddu     $a0, $zero, $zero
/* A3ABD0 802416F0 0C0B1EAF */  jal       get_variable
/* A3ABD4 802416F4 02122821 */   addu     $a1, $s0, $s2
/* A3ABD8 802416F8 50400001 */  beql      $v0, $zero, .L80241700
/* A3ABDC 802416FC 26940001 */   addiu    $s4, $s4, 1
.L80241700:
/* A3ABE0 80241700 26100001 */  addiu     $s0, $s0, 1
.L80241704:
/* A3ABE4 80241704 2E02003F */  sltiu     $v0, $s0, 0x3f
/* A3ABE8 80241708 1440FFEF */  bnez      $v0, .L802416C8
/* A3ABEC 8024170C 2631000C */   addiu    $s1, $s1, 0xc
/* A3ABF0 80241710 12800029 */  beqz      $s4, .L802417B8
/* A3ABF4 80241714 00000000 */   nop
/* A3ABF8 80241718 0C00A67F */  jal       rand_int
/* A3ABFC 8024171C 2684FFFF */   addiu    $a0, $s4, -1
/* A3AC00 80241720 0040B82D */  daddu     $s7, $v0, $zero
/* A3AC04 80241724 3C138024 */  lui       $s3, %hi(D_80244C48_A3E128)
/* A3AC08 80241728 26734C48 */  addiu     $s3, $s3, %lo(D_80244C48_A3E128)
/* A3AC0C 8024172C 0000A02D */  daddu     $s4, $zero, $zero
/* A3AC10 80241730 0280802D */  daddu     $s0, $s4, $zero
/* A3AC14 80241734 3C16F971 */  lui       $s6, 0xf971
/* A3AC18 80241738 36D688F4 */  ori       $s6, $s6, 0x88f4
/* A3AC1C 8024173C 26720004 */  addiu     $s2, $s3, 4
.L80241740:
/* A3AC20 80241740 8E420004 */  lw        $v0, 4($s2)
/* A3AC24 80241744 02A2102A */  slt       $v0, $s5, $v0
/* A3AC28 80241748 54400017 */  bnel      $v0, $zero, .L802417A8
/* A3AC2C 8024174C 26100001 */   addiu    $s0, $s0, 1
/* A3AC30 80241750 8E450000 */  lw        $a1, ($s2)
/* A3AC34 80241754 0C0B1EAF */  jal       get_variable
/* A3AC38 80241758 0000202D */   daddu    $a0, $zero, $zero
/* A3AC3C 8024175C 54400012 */  bnel      $v0, $zero, .L802417A8
/* A3AC40 80241760 26100001 */   addiu    $s0, $s0, 1
/* A3AC44 80241764 0000202D */  daddu     $a0, $zero, $zero
/* A3AC48 80241768 02168821 */  addu      $s1, $s0, $s6
/* A3AC4C 8024176C 0C0B1EAF */  jal       get_variable
/* A3AC50 80241770 0220282D */   daddu    $a1, $s1, $zero
/* A3AC54 80241774 5440000C */  bnel      $v0, $zero, .L802417A8
/* A3AC58 80241778 26100001 */   addiu    $s0, $s0, 1
/* A3AC5C 8024177C 16970009 */  bne       $s4, $s7, .L802417A4
/* A3AC60 80241780 26940001 */   addiu    $s4, $s4, 1
/* A3AC64 80241784 0000202D */  daddu     $a0, $zero, $zero
/* A3AC68 80241788 0220282D */  daddu     $a1, $s1, $zero
/* A3AC6C 8024178C 8E620000 */  lw        $v0, ($s3)
/* A3AC70 80241790 24060001 */  addiu     $a2, $zero, 1
/* A3AC74 80241794 0C0B2026 */  jal       evt_set_variable
/* A3AC78 80241798 AFC20088 */   sw       $v0, 0x88($fp)
/* A3AC7C 8024179C 080905EE */  j         .L802417B8
/* A3AC80 802417A0 00000000 */   nop
.L802417A4:
/* A3AC84 802417A4 26100001 */  addiu     $s0, $s0, 1
.L802417A8:
/* A3AC88 802417A8 2652000C */  addiu     $s2, $s2, 0xc
/* A3AC8C 802417AC 2E02003F */  sltiu     $v0, $s0, 0x3f
/* A3AC90 802417B0 1440FFE3 */  bnez      $v0, .L80241740
/* A3AC94 802417B4 2673000C */   addiu    $s3, $s3, 0xc
.L802417B8:
/* A3AC98 802417B8 8FBF0034 */  lw        $ra, 0x34($sp)
/* A3AC9C 802417BC 8FBE0030 */  lw        $fp, 0x30($sp)
/* A3ACA0 802417C0 8FB7002C */  lw        $s7, 0x2c($sp)
/* A3ACA4 802417C4 8FB60028 */  lw        $s6, 0x28($sp)
/* A3ACA8 802417C8 8FB50024 */  lw        $s5, 0x24($sp)
/* A3ACAC 802417CC 8FB40020 */  lw        $s4, 0x20($sp)
/* A3ACB0 802417D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* A3ACB4 802417D4 8FB20018 */  lw        $s2, 0x18($sp)
/* A3ACB8 802417D8 8FB10014 */  lw        $s1, 0x14($sp)
/* A3ACBC 802417DC 8FB00010 */  lw        $s0, 0x10($sp)
/* A3ACC0 802417E0 24020002 */  addiu     $v0, $zero, 2
/* A3ACC4 802417E4 03E00008 */  jr        $ra
/* A3ACC8 802417E8 27BD0038 */   addiu    $sp, $sp, 0x38
