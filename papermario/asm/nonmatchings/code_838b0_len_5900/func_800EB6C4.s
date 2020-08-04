.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800EB6C4
/* 084B74 800EB6C4 3C028011 */  lui   $v0, 0x8011
/* 084B78 800EB6C8 8C42CFD8 */  lw    $v0, -0x3028($v0)
/* 084B7C 800EB6CC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 084B80 800EB6D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 084B84 800EB6D4 3C118011 */  lui   $s1, 0x8011
/* 084B88 800EB6D8 2631EBB0 */  addiu $s1, $s1, -0x1450
/* 084B8C 800EB6DC AFBF0018 */  sw    $ra, 0x18($sp)
/* 084B90 800EB6E0 10400035 */  beqz  $v0, .L800EB7B8
/* 084B94 800EB6E4 AFB00010 */   sw    $s0, 0x10($sp)
/* 084B98 800EB6E8 3C108011 */  lui   $s0, 0x8011
/* 084B9C 800EB6EC 2610CFDC */  addiu $s0, $s0, -0x3024
/* 084BA0 800EB6F0 0C0B1059 */  jal   does_script_exist
/* 084BA4 800EB6F4 8E040000 */   lw    $a0, ($s0)
/* 084BA8 800EB6F8 10400003 */  beqz  $v0, .L800EB708
/* 084BAC 800EB6FC 00000000 */   nop   
/* 084BB0 800EB700 0C0B102B */  jal   kill_script_by_ID
/* 084BB4 800EB704 8E040000 */   lw    $a0, ($s0)
.L800EB708:
/* 084BB8 800EB708 3C028011 */  lui   $v0, 0x8011
/* 084BBC 800EB70C 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 084BC0 800EB710 24050014 */  addiu $a1, $zero, 0x14
/* 084BC4 800EB714 8C440018 */  lw    $a0, 0x18($v0)
/* 084BC8 800EB718 0C0B0CF8 */  jal   start_script
/* 084BCC 800EB71C 24060020 */   addiu $a2, $zero, 0x20
/* 084BD0 800EB720 3C038011 */  lui   $v1, 0x8011
/* 084BD4 800EB724 8C63C930 */  lw    $v1, -0x36d0($v1)
/* 084BD8 800EB728 8C440144 */  lw    $a0, 0x144($v0)
/* 084BDC 800EB72C 3C018011 */  lui   $at, 0x8011
/* 084BE0 800EB730 AC22CFD4 */  sw    $v0, -0x302c($at)
/* 084BE4 800EB734 AC43014C */  sw    $v1, 0x14c($v0)
/* 084BE8 800EB738 2403000A */  addiu $v1, $zero, 0xa
/* 084BEC 800EB73C AE040000 */  sw    $a0, ($s0)
/* 084BF0 800EB740 A0430004 */  sb    $v1, 4($v0)
/* 084BF4 800EB744 24020001 */  addiu $v0, $zero, 1
/* 084BF8 800EB748 3C018011 */  lui   $at, 0x8011
/* 084BFC 800EB74C AC22CFE8 */  sw    $v0, -0x3018($at)
/* 084C00 800EB750 3C028011 */  lui   $v0, 0x8011
/* 084C04 800EB754 2442F290 */  addiu $v0, $v0, -0xd70
/* 084C08 800EB758 80420012 */  lb    $v0, 0x12($v0)
/* 084C0C 800EB75C 24030006 */  addiu $v1, $zero, 6
/* 084C10 800EB760 1043000C */  beq   $v0, $v1, .L800EB794
/* 084C14 800EB764 00000000 */   nop   
/* 084C18 800EB768 82220003 */  lb    $v0, 3($s1)
/* 084C1C 800EB76C 14430009 */  bne   $v0, $v1, .L800EB794
/* 084C20 800EB770 2403FFFE */   addiu $v1, $zero, -2
/* 084C24 800EB774 3C04800F */  lui   $a0, 0x800f
/* 084C28 800EB778 8C847B30 */  lw    $a0, 0x7b30($a0)
/* 084C2C 800EB77C 8C820004 */  lw    $v0, 4($a0)
/* 084C30 800EB780 00431024 */  and   $v0, $v0, $v1
/* 084C34 800EB784 2403FFFD */  addiu $v1, $zero, -3
/* 084C38 800EB788 00431024 */  and   $v0, $v0, $v1
/* 084C3C 800EB78C AC820004 */  sw    $v0, 4($a0)
/* 084C40 800EB790 A2200003 */  sb    $zero, 3($s1)
.L800EB794:
/* 084C44 800EB794 3C028011 */  lui   $v0, 0x8011
/* 084C48 800EB798 8C42CFEC */  lw    $v0, -0x3014($v0)
/* 084C4C 800EB79C 8C420038 */  lw    $v0, 0x38($v0)
/* 084C50 800EB7A0 10400005 */  beqz  $v0, .L800EB7B8
/* 084C54 800EB7A4 00000000 */   nop   
/* 084C58 800EB7A8 3C048011 */  lui   $a0, 0x8011
/* 084C5C 800EB7AC 8C84C930 */  lw    $a0, -0x36d0($a0)
/* 084C60 800EB7B0 0040F809 */  jalr  $v0
/* 084C64 800EB7B4 00000000 */  nop   
.L800EB7B8:
/* 084C68 800EB7B8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 084C6C 800EB7BC 8FB10014 */  lw    $s1, 0x14($sp)
/* 084C70 800EB7C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 084C74 800EB7C4 03E00008 */  jr    $ra
/* 084C78 800EB7C8 27BD0020 */   addiu $sp, $sp, 0x20

/* 084C7C 800EB7CC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 084C80 800EB7D0 AFB00010 */  sw    $s0, 0x10($sp)
/* 084C84 800EB7D4 3C108011 */  lui   $s0, 0x8011
/* 084C88 800EB7D8 2610CFDC */  addiu $s0, $s0, -0x3024
/* 084C8C 800EB7DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 084C90 800EB7E0 8E040000 */  lw    $a0, ($s0)
/* 084C94 800EB7E4 2402000A */  addiu $v0, $zero, 0xa
/* 084C98 800EB7E8 3C018011 */  lui   $at, 0x8011
/* 084C9C 800EB7EC AC22CFE8 */  sw    $v0, -0x3018($at)
/* 084CA0 800EB7F0 0C0B1059 */  jal   does_script_exist
/* 084CA4 800EB7F4 00000000 */   nop   
/* 084CA8 800EB7F8 10400003 */  beqz  $v0, .L800EB808
/* 084CAC 800EB7FC 00000000 */   nop   
/* 084CB0 800EB800 0C0B102B */  jal   kill_script_by_ID
/* 084CB4 800EB804 8E040000 */   lw    $a0, ($s0)
.L800EB808:
/* 084CB8 800EB808 8FBF0014 */  lw    $ra, 0x14($sp)
/* 084CBC 800EB80C 8FB00010 */  lw    $s0, 0x10($sp)
/* 084CC0 800EB810 03E00008 */  jr    $ra
/* 084CC4 800EB814 27BD0018 */   addiu $sp, $sp, 0x18

/* 084CC8 800EB818 3C028011 */  lui   $v0, 0x8011
/* 084CCC 800EB81C 8C42CFD8 */  lw    $v0, -0x3028($v0)
/* 084CD0 800EB820 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 084CD4 800EB824 AFBF0014 */  sw    $ra, 0x14($sp)
/* 084CD8 800EB828 10400009 */  beqz  $v0, .L800EB850
/* 084CDC 800EB82C AFB00010 */   sw    $s0, 0x10($sp)
/* 084CE0 800EB830 3C108011 */  lui   $s0, 0x8011
/* 084CE4 800EB834 2610CFDC */  addiu $s0, $s0, -0x3024
/* 084CE8 800EB838 0C0B1059 */  jal   does_script_exist
/* 084CEC 800EB83C 8E040000 */   lw    $a0, ($s0)
/* 084CF0 800EB840 10400003 */  beqz  $v0, .L800EB850
/* 084CF4 800EB844 00000000 */   nop   
/* 084CF8 800EB848 0C0B1108 */  jal   suspend_all_script
/* 084CFC 800EB84C 8E040000 */   lw    $a0, ($s0)
.L800EB850:
/* 084D00 800EB850 8FBF0014 */  lw    $ra, 0x14($sp)
/* 084D04 800EB854 8FB00010 */  lw    $s0, 0x10($sp)
/* 084D08 800EB858 03E00008 */  jr    $ra
/* 084D0C 800EB85C 27BD0018 */   addiu $sp, $sp, 0x18

/* 084D10 800EB860 3C028011 */  lui   $v0, 0x8011
/* 084D14 800EB864 8C42CFD8 */  lw    $v0, -0x3028($v0)
/* 084D18 800EB868 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 084D1C 800EB86C AFBF0014 */  sw    $ra, 0x14($sp)
/* 084D20 800EB870 10400009 */  beqz  $v0, .L800EB898
/* 084D24 800EB874 AFB00010 */   sw    $s0, 0x10($sp)
/* 084D28 800EB878 3C108011 */  lui   $s0, 0x8011
/* 084D2C 800EB87C 2610CFDC */  addiu $s0, $s0, -0x3024
/* 084D30 800EB880 0C0B1059 */  jal   does_script_exist
/* 084D34 800EB884 8E040000 */   lw    $a0, ($s0)
/* 084D38 800EB888 10400003 */  beqz  $v0, .L800EB898
/* 084D3C 800EB88C 00000000 */   nop   
/* 084D40 800EB890 0C0B1123 */  jal   resume_all_script
/* 084D44 800EB894 8E040000 */   lw    $a0, ($s0)
.L800EB898:
/* 084D48 800EB898 8FBF0014 */  lw    $ra, 0x14($sp)
/* 084D4C 800EB89C 8FB00010 */  lw    $s0, 0x10($sp)
/* 084D50 800EB8A0 03E00008 */  jr    $ra
/* 084D54 800EB8A4 27BD0018 */   addiu $sp, $sp, 0x18

