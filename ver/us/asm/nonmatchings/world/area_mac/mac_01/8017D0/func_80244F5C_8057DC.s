.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244F5C_8057DC
/* 8057DC 80244F5C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8057E0 80244F60 AFB50024 */  sw        $s5, 0x24($sp)
/* 8057E4 80244F64 0080A82D */  daddu     $s5, $a0, $zero
/* 8057E8 80244F68 AFB10014 */  sw        $s1, 0x14($sp)
/* 8057EC 80244F6C 0000882D */  daddu     $s1, $zero, $zero
/* 8057F0 80244F70 AFB00010 */  sw        $s0, 0x10($sp)
/* 8057F4 80244F74 0220802D */  daddu     $s0, $s1, $zero
/* 8057F8 80244F78 AFB40020 */  sw        $s4, 0x20($sp)
/* 8057FC 80244F7C 3C14F840 */  lui       $s4, 0xf840
/* 805800 80244F80 36945C19 */  ori       $s4, $s4, 0x5c19
/* 805804 80244F84 AFB3001C */  sw        $s3, 0x1c($sp)
/* 805808 80244F88 3C13F840 */  lui       $s3, 0xf840
/* 80580C 80244F8C 36735C2C */  ori       $s3, $s3, 0x5c2c
/* 805810 80244F90 AFB20018 */  sw        $s2, 0x18($sp)
/* 805814 80244F94 3C128025 */  lui       $s2, %hi(D_80256ADC_81735C)
/* 805818 80244F98 26526ADC */  addiu     $s2, $s2, %lo(D_80256ADC_81735C)
/* 80581C 80244F9C AFBF0028 */  sw        $ra, 0x28($sp)
.L80244FA0:
/* 805820 80244FA0 8E420000 */  lw        $v0, ($s2)
/* 805824 80244FA4 5455000F */  bnel      $v0, $s5, .L80244FE4
/* 805828 80244FA8 26100001 */   addiu    $s0, $s0, 1
/* 80582C 80244FAC 0000202D */  daddu     $a0, $zero, $zero
/* 805830 80244FB0 0C0B1EAF */  jal       get_variable
/* 805834 80244FB4 02142821 */   addu     $a1, $s0, $s4
/* 805838 80244FB8 5040000A */  beql      $v0, $zero, .L80244FE4
/* 80583C 80244FBC 26100001 */   addiu    $s0, $s0, 1
/* 805840 80244FC0 52200001 */  beql      $s1, $zero, .L80244FC8
/* 805844 80244FC4 24110001 */   addiu    $s1, $zero, 1
.L80244FC8:
/* 805848 80244FC8 0000202D */  daddu     $a0, $zero, $zero
/* 80584C 80244FCC 0C0B1EAF */  jal       get_variable
/* 805850 80244FD0 02132821 */   addu     $a1, $s0, $s3
/* 805854 80244FD4 14400003 */  bnez      $v0, .L80244FE4
/* 805858 80244FD8 26100001 */   addiu    $s0, $s0, 1
/* 80585C 80244FDC 080913FC */  j         .L80244FF0
/* 805860 80244FE0 24110002 */   addiu    $s1, $zero, 2
.L80244FE4:
/* 805864 80244FE4 2E020013 */  sltiu     $v0, $s0, 0x13
/* 805868 80244FE8 1440FFED */  bnez      $v0, .L80244FA0
/* 80586C 80244FEC 26520014 */   addiu    $s2, $s2, 0x14
.L80244FF0:
/* 805870 80244FF0 0220102D */  daddu     $v0, $s1, $zero
/* 805874 80244FF4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 805878 80244FF8 8FB50024 */  lw        $s5, 0x24($sp)
/* 80587C 80244FFC 8FB40020 */  lw        $s4, 0x20($sp)
/* 805880 80245000 8FB3001C */  lw        $s3, 0x1c($sp)
/* 805884 80245004 8FB20018 */  lw        $s2, 0x18($sp)
/* 805888 80245008 8FB10014 */  lw        $s1, 0x14($sp)
/* 80588C 8024500C 8FB00010 */  lw        $s0, 0x10($sp)
/* 805890 80245010 03E00008 */  jr        $ra
/* 805894 80245014 27BD0030 */   addiu    $sp, $sp, 0x30
