.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8011C164
/* 0B2864 8011C164 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0B2868 8011C168 AFB00028 */  sw    $s0, 0x28($sp)
/* 0B286C 8011C16C 0080802D */  daddu $s0, $a0, $zero
/* 0B2870 8011C170 30A4FFFF */  andi  $a0, $a1, 0xffff
/* 0B2874 8011C174 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0B2878 8011C178 00C0882D */  daddu $s1, $a2, $zero
/* 0B287C 8011C17C AFBF003C */  sw    $ra, 0x3c($sp)
/* 0B2880 8011C180 AFB40038 */  sw    $s4, 0x38($sp)
/* 0B2884 8011C184 AFB30034 */  sw    $s3, 0x34($sp)
/* 0B2888 8011C188 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 0B288C 8011C18C AFB20030 */   sw    $s2, 0x30($sp)
/* 0B2890 8011C190 0C046B4C */  jal   get_model_from_list_index
/* 0B2894 8011C194 0040202D */   daddu $a0, $v0, $zero
/* 0B2898 8011C198 0040A02D */  daddu $s4, $v0, $zero
/* 0B289C 8011C19C 8E820008 */  lw    $v0, 8($s4)
/* 0B28A0 8011C1A0 27A50018 */  addiu $a1, $sp, 0x18
/* 0B28A4 8011C1A4 8C420004 */  lw    $v0, 4($v0)
/* 0B28A8 8011C1A8 27A6001C */  addiu $a2, $sp, 0x1c
/* 0B28AC 8011C1AC 8C530000 */  lw    $s3, ($v0)
/* 0B28B0 8011C1B0 27A70020 */  addiu $a3, $sp, 0x20
/* 0B28B4 8011C1B4 AFA00010 */  sw    $zero, 0x10($sp)
/* 0B28B8 8011C1B8 0C04700A */  jal   func_8011C028
/* 0B28BC 8011C1BC 0260202D */   daddu $a0, $s3, $zero
/* 0B28C0 8011C1C0 0C00AB39 */  jal   heap_malloc
/* 0B28C4 8011C1C4 2404001C */   addiu $a0, $zero, 0x1c
/* 0B28C8 8011C1C8 00108080 */  sll   $s0, $s0, 2
/* 0B28CC 8011C1CC 3C038015 */  lui   $v1, 0x8015
/* 0B28D0 8011C1D0 8C632210 */  lw    $v1, 0x2210($v1)
/* 0B28D4 8011C1D4 0040902D */  daddu $s2, $v0, $zero
/* 0B28D8 8011C1D8 02038021 */  addu  $s0, $s0, $v1
/* 0B28DC 8011C1DC 1220001C */  beqz  $s1, .L8011C250
/* 0B28E0 8011C1E0 AE020000 */   sw    $v0, ($s0)
/* 0B28E4 8011C1E4 0000882D */  daddu $s1, $zero, $zero
/* 0B28E8 8011C1E8 0240802D */  daddu $s0, $s2, $zero
.L8011C1EC:
/* 0B28EC 8011C1EC 8FA40020 */  lw    $a0, 0x20($sp)
/* 0B28F0 8011C1F0 0C00AB39 */  jal   heap_malloc
/* 0B28F4 8011C1F4 000420C0 */   sll   $a0, $a0, 3
/* 0B28F8 8011C1F8 8FA40018 */  lw    $a0, 0x18($sp)
/* 0B28FC 8011C1FC 26310001 */  addiu $s1, $s1, 1
/* 0B2900 8011C200 AE020008 */  sw    $v0, 8($s0)
/* 0B2904 8011C204 0C00AB39 */  jal   heap_malloc
/* 0B2908 8011C208 00042100 */   sll   $a0, $a0, 4
/* 0B290C 8011C20C 0260202D */  daddu $a0, $s3, $zero
/* 0B2910 8011C210 8FA5001C */  lw    $a1, 0x1c($sp)
/* 0B2914 8011C214 8E060008 */  lw    $a2, 8($s0)
/* 0B2918 8011C218 0040382D */  daddu $a3, $v0, $zero
/* 0B291C 8011C21C 0C047037 */  jal   func_8011C0DC
/* 0B2920 8011C220 AE070010 */   sw    $a3, 0x10($s0)
/* 0B2924 8011C224 8FA4001C */  lw    $a0, 0x1c($sp)
/* 0B2928 8011C228 8FA50018 */  lw    $a1, 0x18($sp)
/* 0B292C 8011C22C 8E060010 */  lw    $a2, 0x10($s0)
/* 0B2930 8011C230 0C04704C */  jal   func_8011C130
/* 0B2934 8011C234 26100004 */   addiu $s0, $s0, 4
/* 0B2938 8011C238 2A220002 */  slti  $v0, $s1, 2
/* 0B293C 8011C23C 1440FFEB */  bnez  $v0, .L8011C1EC
/* 0B2940 8011C240 00000000 */   nop   
/* 0B2944 8011C244 96820000 */  lhu   $v0, ($s4)
/* 0B2948 8011C248 0804709E */  j     .L8011C278
/* 0B294C 8011C24C 34420080 */   ori   $v0, $v0, 0x80

.L8011C250:
/* 0B2950 8011C250 0000882D */  daddu $s1, $zero, $zero
/* 0B2954 8011C254 0240182D */  daddu $v1, $s2, $zero
.L8011C258:
/* 0B2958 8011C258 AC600008 */  sw    $zero, 8($v1)
/* 0B295C 8011C25C AC600010 */  sw    $zero, 0x10($v1)
/* 0B2960 8011C260 26310001 */  addiu $s1, $s1, 1
/* 0B2964 8011C264 2A220002 */  slti  $v0, $s1, 2
/* 0B2968 8011C268 1440FFFB */  bnez  $v0, .L8011C258
/* 0B296C 8011C26C 24630004 */   addiu $v1, $v1, 4
/* 0B2970 8011C270 96820000 */  lhu   $v0, ($s4)
/* 0B2974 8011C274 34420002 */  ori   $v0, $v0, 2
.L8011C278:
/* 0B2978 8011C278 A6820000 */  sh    $v0, ($s4)
/* 0B297C 8011C27C 8FA20018 */  lw    $v0, 0x18($sp)
/* 0B2980 8011C280 8FA3001C */  lw    $v1, 0x1c($sp)
/* 0B2984 8011C284 AE400018 */  sw    $zero, 0x18($s2)
/* 0B2988 8011C288 AE420000 */  sw    $v0, ($s2)
/* 0B298C 8011C28C AE430004 */  sw    $v1, 4($s2)
/* 0B2990 8011C290 8FBF003C */  lw    $ra, 0x3c($sp)
/* 0B2994 8011C294 8FB40038 */  lw    $s4, 0x38($sp)
/* 0B2998 8011C298 8FB30034 */  lw    $s3, 0x34($sp)
/* 0B299C 8011C29C 8FB20030 */  lw    $s2, 0x30($sp)
/* 0B29A0 8011C2A0 8FB1002C */  lw    $s1, 0x2c($sp)
/* 0B29A4 8011C2A4 8FB00028 */  lw    $s0, 0x28($sp)
/* 0B29A8 8011C2A8 03E00008 */  jr    $ra
/* 0B29AC 8011C2AC 27BD0040 */   addiu $sp, $sp, 0x40

/* 0B29B0 8011C2B0 3C028015 */  lui   $v0, 0x8015
/* 0B29B4 8011C2B4 8C422210 */  lw    $v0, 0x2210($v0)
/* 0B29B8 8011C2B8 00042080 */  sll   $a0, $a0, 2
/* 0B29BC 8011C2BC 00822021 */  addu  $a0, $a0, $v0
/* 0B29C0 8011C2C0 8C830000 */  lw    $v1, ($a0)
/* 0B29C4 8011C2C4 8C620018 */  lw    $v0, 0x18($v1)
/* 0B29C8 8011C2C8 8C640004 */  lw    $a0, 4($v1)
/* 0B29CC 8011C2CC 00021080 */  sll   $v0, $v0, 2
/* 0B29D0 8011C2D0 00621021 */  addu  $v0, $v1, $v0
/* 0B29D4 8011C2D4 ACA40000 */  sw    $a0, ($a1)
/* 0B29D8 8011C2D8 8C420010 */  lw    $v0, 0x10($v0)
/* 0B29DC 8011C2DC ACC20000 */  sw    $v0, ($a2)
/* 0B29E0 8011C2E0 8C620000 */  lw    $v0, ($v1)
/* 0B29E4 8011C2E4 03E00008 */  jr    $ra
/* 0B29E8 8011C2E8 ACE20000 */   sw    $v0, ($a3)

/* 0B29EC 8011C2EC 3C028015 */  lui   $v0, 0x8015
/* 0B29F0 8011C2F0 8C422210 */  lw    $v0, 0x2210($v0)
/* 0B29F4 8011C2F4 00042080 */  sll   $a0, $a0, 2
/* 0B29F8 8011C2F8 00822021 */  addu  $a0, $a0, $v0
/* 0B29FC 8011C2FC 8C840000 */  lw    $a0, ($a0)
/* 0B2A00 8011C300 8C830018 */  lw    $v1, 0x18($a0)
/* 0B2A04 8011C304 00031080 */  sll   $v0, $v1, 2
/* 0B2A08 8011C308 00821021 */  addu  $v0, $a0, $v0
/* 0B2A0C 8011C30C 8C420008 */  lw    $v0, 8($v0)
/* 0B2A10 8011C310 24630001 */  addiu $v1, $v1, 1
/* 0B2A14 8011C314 AC830018 */  sw    $v1, 0x18($a0)
/* 0B2A18 8011C318 28630002 */  slti  $v1, $v1, 2
/* 0B2A1C 8011C31C 50600001 */  beql  $v1, $zero, .L8011C324
/* 0B2A20 8011C320 AC800018 */   sw    $zero, 0x18($a0)
.L8011C324:
/* 0B2A24 8011C324 03E00008 */  jr    $ra
/* 0B2A28 8011C328 00000000 */   nop   

