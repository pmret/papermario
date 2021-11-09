.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DE780
/* 101870 802DE780 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 101874 802DE784 AFB40030 */  sw        $s4, 0x30($sp)
/* 101878 802DE788 00A0A02D */  daddu     $s4, $a1, $zero
/* 10187C 802DE78C AFB50034 */  sw        $s5, 0x34($sp)
/* 101880 802DE790 00041080 */  sll       $v0, $a0, 2
/* 101884 802DE794 00441021 */  addu      $v0, $v0, $a0
/* 101888 802DE798 00021080 */  sll       $v0, $v0, 2
/* 10188C 802DE79C AFBF0044 */  sw        $ra, 0x44($sp)
/* 101890 802DE7A0 AFBE0040 */  sw        $fp, 0x40($sp)
/* 101894 802DE7A4 AFB7003C */  sw        $s7, 0x3c($sp)
/* 101898 802DE7A8 AFB60038 */  sw        $s6, 0x38($sp)
/* 10189C 802DE7AC AFB3002C */  sw        $s3, 0x2c($sp)
/* 1018A0 802DE7B0 AFB20028 */  sw        $s2, 0x28($sp)
/* 1018A4 802DE7B4 AFB10024 */  sw        $s1, 0x24($sp)
/* 1018A8 802DE7B8 AFB00020 */  sw        $s0, 0x20($sp)
/* 1018AC 802DE7BC AFA70054 */  sw        $a3, 0x54($sp)
/* 1018B0 802DE7C0 3C01802E */  lui       $at, %hi(D_802DFA4C)
/* 1018B4 802DE7C4 00220821 */  addu      $at, $at, $v0
/* 1018B8 802DE7C8 8C22FA4C */  lw        $v0, %lo(D_802DFA4C)($at)
/* 1018BC 802DE7CC 8FBE0064 */  lw        $fp, 0x64($sp)
/* 1018C0 802DE7D0 10400024 */  beqz      $v0, .L802DE864
/* 1018C4 802DE7D4 00C0A82D */   daddu    $s5, $a2, $zero
/* 1018C8 802DE7D8 0040882D */  daddu     $s1, $v0, $zero
/* 1018CC 802DE7DC 8E230000 */  lw        $v1, ($s1)
/* 1018D0 802DE7E0 2402FFFF */  addiu     $v0, $zero, -1
/* 1018D4 802DE7E4 1062001F */  beq       $v1, $v0, .L802DE864
/* 1018D8 802DE7E8 0000902D */   daddu    $s2, $zero, $zero
/* 1018DC 802DE7EC 0040982D */  daddu     $s3, $v0, $zero
/* 1018E0 802DE7F0 3C171000 */  lui       $s7, 0x1000
/* 1018E4 802DE7F4 3C160FFF */  lui       $s6, 0xfff
/* 1018E8 802DE7F8 36D6FFFF */  ori       $s6, $s6, 0xffff
.L802DE7FC:
/* 1018EC 802DE7FC 12930003 */  beq       $s4, $s3, .L802DE80C
/* 1018F0 802DE800 8E300000 */   lw       $s0, ($s1)
/* 1018F4 802DE804 56540014 */  bnel      $s2, $s4, .L802DE858
/* 1018F8 802DE808 26310004 */   addiu    $s1, $s1, 4
.L802DE80C:
/* 1018FC 802DE80C 8FA8005C */  lw        $t0, 0x5c($sp)
/* 101900 802DE810 9204004F */  lbu       $a0, 0x4f($s0)
/* 101904 802DE814 8FA60054 */  lw        $a2, 0x54($sp)
/* 101908 802DE818 8FA70058 */  lw        $a3, 0x58($sp)
/* 10190C 802DE81C AFA80010 */  sw        $t0, 0x10($sp)
/* 101910 802DE820 8FA80060 */  lw        $t0, 0x60($sp)
/* 101914 802DE824 02A0282D */  daddu     $a1, $s5, $zero
/* 101918 802DE828 AFBE0018 */  sw        $fp, 0x18($sp)
/* 10191C 802DE82C 0C04EAA7 */  jal       sprfx_update
/* 101920 802DE830 AFA80014 */   sw       $t0, 0x14($sp)
/* 101924 802DE834 12A00004 */  beqz      $s5, .L802DE848
/* 101928 802DE838 00000000 */   nop
/* 10192C 802DE83C 8E02004C */  lw        $v0, 0x4c($s0)
/* 101930 802DE840 080B7A14 */  j         .L802DE850
/* 101934 802DE844 00571025 */   or       $v0, $v0, $s7
.L802DE848:
/* 101938 802DE848 8E02004C */  lw        $v0, 0x4c($s0)
/* 10193C 802DE84C 00561024 */  and       $v0, $v0, $s6
.L802DE850:
/* 101940 802DE850 AE02004C */  sw        $v0, 0x4c($s0)
/* 101944 802DE854 26310004 */  addiu     $s1, $s1, 4
.L802DE858:
/* 101948 802DE858 8E220000 */  lw        $v0, ($s1)
/* 10194C 802DE85C 1453FFE7 */  bne       $v0, $s3, .L802DE7FC
/* 101950 802DE860 26520001 */   addiu    $s2, $s2, 1
.L802DE864:
/* 101954 802DE864 8FBF0044 */  lw        $ra, 0x44($sp)
/* 101958 802DE868 8FBE0040 */  lw        $fp, 0x40($sp)
/* 10195C 802DE86C 8FB7003C */  lw        $s7, 0x3c($sp)
/* 101960 802DE870 8FB60038 */  lw        $s6, 0x38($sp)
/* 101964 802DE874 8FB50034 */  lw        $s5, 0x34($sp)
/* 101968 802DE878 8FB40030 */  lw        $s4, 0x30($sp)
/* 10196C 802DE87C 8FB3002C */  lw        $s3, 0x2c($sp)
/* 101970 802DE880 8FB20028 */  lw        $s2, 0x28($sp)
/* 101974 802DE884 8FB10024 */  lw        $s1, 0x24($sp)
/* 101978 802DE888 8FB00020 */  lw        $s0, 0x20($sp)
/* 10197C 802DE88C 03E00008 */  jr        $ra
/* 101980 802DE890 27BD0048 */   addiu    $sp, $sp, 0x48
