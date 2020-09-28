.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011C164
/* B2864 8011C164 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* B2868 8011C168 AFB00028 */  sw        $s0, 0x28($sp)
/* B286C 8011C16C 0080802D */  daddu     $s0, $a0, $zero
/* B2870 8011C170 30A4FFFF */  andi      $a0, $a1, 0xffff
/* B2874 8011C174 AFB1002C */  sw        $s1, 0x2c($sp)
/* B2878 8011C178 00C0882D */  daddu     $s1, $a2, $zero
/* B287C 8011C17C AFBF003C */  sw        $ra, 0x3c($sp)
/* B2880 8011C180 AFB40038 */  sw        $s4, 0x38($sp)
/* B2884 8011C184 AFB30034 */  sw        $s3, 0x34($sp)
/* B2888 8011C188 0C046C04 */  jal       get_model_list_index_from_tree_index
/* B288C 8011C18C AFB20030 */   sw       $s2, 0x30($sp)
/* B2890 8011C190 0C046B4C */  jal       get_model_from_list_index
/* B2894 8011C194 0040202D */   daddu    $a0, $v0, $zero
/* B2898 8011C198 0040A02D */  daddu     $s4, $v0, $zero
/* B289C 8011C19C 8E820008 */  lw        $v0, 8($s4)
/* B28A0 8011C1A0 27A50018 */  addiu     $a1, $sp, 0x18
/* B28A4 8011C1A4 8C420004 */  lw        $v0, 4($v0)
/* B28A8 8011C1A8 27A6001C */  addiu     $a2, $sp, 0x1c
/* B28AC 8011C1AC 8C530000 */  lw        $s3, ($v0)
/* B28B0 8011C1B0 27A70020 */  addiu     $a3, $sp, 0x20
/* B28B4 8011C1B4 AFA00010 */  sw        $zero, 0x10($sp)
/* B28B8 8011C1B8 0C04700A */  jal       func_8011C028
/* B28BC 8011C1BC 0260202D */   daddu    $a0, $s3, $zero
/* B28C0 8011C1C0 0C00AB39 */  jal       heap_malloc
/* B28C4 8011C1C4 2404001C */   addiu    $a0, $zero, 0x1c
/* B28C8 8011C1C8 00108080 */  sll       $s0, $s0, 2
/* B28CC 8011C1CC 3C038015 */  lui       $v1, 0x8015
/* B28D0 8011C1D0 8C632210 */  lw        $v1, 0x2210($v1)
/* B28D4 8011C1D4 0040902D */  daddu     $s2, $v0, $zero
/* B28D8 8011C1D8 02038021 */  addu      $s0, $s0, $v1
/* B28DC 8011C1DC 1220001C */  beqz      $s1, .L8011C250
/* B28E0 8011C1E0 AE020000 */   sw       $v0, ($s0)
/* B28E4 8011C1E4 0000882D */  daddu     $s1, $zero, $zero
/* B28E8 8011C1E8 0240802D */  daddu     $s0, $s2, $zero
.L8011C1EC:
/* B28EC 8011C1EC 8FA40020 */  lw        $a0, 0x20($sp)
/* B28F0 8011C1F0 0C00AB39 */  jal       heap_malloc
/* B28F4 8011C1F4 000420C0 */   sll      $a0, $a0, 3
/* B28F8 8011C1F8 8FA40018 */  lw        $a0, 0x18($sp)
/* B28FC 8011C1FC 26310001 */  addiu     $s1, $s1, 1
/* B2900 8011C200 AE020008 */  sw        $v0, 8($s0)
/* B2904 8011C204 0C00AB39 */  jal       heap_malloc
/* B2908 8011C208 00042100 */   sll      $a0, $a0, 4
/* B290C 8011C20C 0260202D */  daddu     $a0, $s3, $zero
/* B2910 8011C210 8FA5001C */  lw        $a1, 0x1c($sp)
/* B2914 8011C214 8E060008 */  lw        $a2, 8($s0)
/* B2918 8011C218 0040382D */  daddu     $a3, $v0, $zero
/* B291C 8011C21C 0C047037 */  jal       func_8011C0DC
/* B2920 8011C220 AE070010 */   sw       $a3, 0x10($s0)
/* B2924 8011C224 8FA4001C */  lw        $a0, 0x1c($sp)
/* B2928 8011C228 8FA50018 */  lw        $a1, 0x18($sp)
/* B292C 8011C22C 8E060010 */  lw        $a2, 0x10($s0)
/* B2930 8011C230 0C04704C */  jal       func_8011C130
/* B2934 8011C234 26100004 */   addiu    $s0, $s0, 4
/* B2938 8011C238 2A220002 */  slti      $v0, $s1, 2
/* B293C 8011C23C 1440FFEB */  bnez      $v0, .L8011C1EC
/* B2940 8011C240 00000000 */   nop      
/* B2944 8011C244 96820000 */  lhu       $v0, ($s4)
/* B2948 8011C248 0804709E */  j         .L8011C278
/* B294C 8011C24C 34420080 */   ori      $v0, $v0, 0x80
.L8011C250:
/* B2950 8011C250 0000882D */  daddu     $s1, $zero, $zero
/* B2954 8011C254 0240182D */  daddu     $v1, $s2, $zero
.L8011C258:
/* B2958 8011C258 AC600008 */  sw        $zero, 8($v1)
/* B295C 8011C25C AC600010 */  sw        $zero, 0x10($v1)
/* B2960 8011C260 26310001 */  addiu     $s1, $s1, 1
/* B2964 8011C264 2A220002 */  slti      $v0, $s1, 2
/* B2968 8011C268 1440FFFB */  bnez      $v0, .L8011C258
/* B296C 8011C26C 24630004 */   addiu    $v1, $v1, 4
/* B2970 8011C270 96820000 */  lhu       $v0, ($s4)
/* B2974 8011C274 34420002 */  ori       $v0, $v0, 2
.L8011C278:
/* B2978 8011C278 A6820000 */  sh        $v0, ($s4)
/* B297C 8011C27C 8FA20018 */  lw        $v0, 0x18($sp)
/* B2980 8011C280 8FA3001C */  lw        $v1, 0x1c($sp)
/* B2984 8011C284 AE400018 */  sw        $zero, 0x18($s2)
/* B2988 8011C288 AE420000 */  sw        $v0, ($s2)
/* B298C 8011C28C AE430004 */  sw        $v1, 4($s2)
/* B2990 8011C290 8FBF003C */  lw        $ra, 0x3c($sp)
/* B2994 8011C294 8FB40038 */  lw        $s4, 0x38($sp)
/* B2998 8011C298 8FB30034 */  lw        $s3, 0x34($sp)
/* B299C 8011C29C 8FB20030 */  lw        $s2, 0x30($sp)
/* B29A0 8011C2A0 8FB1002C */  lw        $s1, 0x2c($sp)
/* B29A4 8011C2A4 8FB00028 */  lw        $s0, 0x28($sp)
/* B29A8 8011C2A8 03E00008 */  jr        $ra
/* B29AC 8011C2AC 27BD0040 */   addiu    $sp, $sp, 0x40
