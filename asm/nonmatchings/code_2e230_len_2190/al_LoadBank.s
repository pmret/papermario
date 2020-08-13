.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel al_LoadBank
/* 02FBC8 800547C8 27BDFF80 */  addiu $sp, $sp, -0x80
/* 02FBCC 800547CC AFB5006C */  sw    $s5, 0x6c($sp)
/* 02FBD0 800547D0 0080A82D */  daddu $s5, $a0, $zero
/* 02FBD4 800547D4 AFB40068 */  sw    $s4, 0x68($sp)
/* 02FBD8 800547D8 00A0A02D */  daddu $s4, $a1, $zero
/* 02FBDC 800547DC AFB70074 */  sw    $s7, 0x74($sp)
/* 02FBE0 800547E0 00C0B82D */  daddu $s7, $a2, $zero
/* 02FBE4 800547E4 AFBE0078 */  sw    $fp, 0x78($sp)
/* 02FBE8 800547E8 00E0F02D */  daddu $fp, $a3, $zero
/* 02FBEC 800547EC AFB1005C */  sw    $s1, 0x5c($sp)
/* 02FBF0 800547F0 27B10018 */  addiu $s1, $sp, 0x18
/* 02FBF4 800547F4 0220282D */  daddu $a1, $s1, $zero
/* 02FBF8 800547F8 3C028008 */  lui   $v0, 0x8008
/* 02FBFC 800547FC 8C428E54 */  lw    $v0, -0x71ac($v0)
/* 02FC00 80054800 24060040 */  addiu $a2, $zero, 0x40
/* 02FC04 80054804 AFB30064 */  sw    $s3, 0x64($sp)
/* 02FC08 80054808 2413000B */  addiu $s3, $zero, 0xb
/* 02FC0C 8005480C AFB20060 */  sw    $s2, 0x60($sp)
/* 02FC10 80054810 AFBF007C */  sw    $ra, 0x7c($sp)
/* 02FC14 80054814 AFB60070 */  sw    $s6, 0x70($sp)
/* 02FC18 80054818 AFB00058 */  sw    $s0, 0x58($sp)
/* 02FC1C 8005481C 8C560018 */  lw    $s6, 0x18($v0)
/* 02FC20 80054820 0C015380 */  jal   al_DmaCopy
/* 02FC24 80054824 24120001 */   addiu $s2, $zero, 1
/* 02FC28 80054828 3263FFFF */  andi  $v1, $s3, 0xffff
.L8005482C:
/* 02FC2C 8005482C 2402006F */  addiu $v0, $zero, 0x6f
/* 02FC30 80054830 10620057 */  beq   $v1, $v0, .L80054990
/* 02FC34 80054834 28620070 */   slti  $v0, $v1, 0x70
/* 02FC38 80054838 1040005E */  beqz  $v0, .L800549B4
/* 02FC3C 8005483C 2402000B */   addiu $v0, $zero, 0xb
/* 02FC40 80054840 1062000A */  beq   $v1, $v0, .L8005486C
/* 02FC44 80054844 2862000C */   slti  $v0, $v1, 0xc
/* 02FC48 80054848 5440005B */  bnel  $v0, $zero, .L800549B8
/* 02FC4C 8005484C 0000902D */   daddu $s2, $zero, $zero
/* 02FC50 80054850 24020015 */  addiu $v0, $zero, 0x15
/* 02FC54 80054854 1062000E */  beq   $v1, $v0, .L80054890
/* 02FC58 80054858 24020065 */   addiu $v0, $zero, 0x65
/* 02FC5C 8005485C 1062001A */  beq   $v1, $v0, .L800548C8
/* 02FC60 80054860 00000000 */   nop   
/* 02FC64 80054864 0801526E */  j     .L800549B8
/* 02FC68 80054868 0000902D */   daddu $s2, $zero, $zero

.L8005486C:
/* 02FC6C 8005486C 96230000 */  lhu   $v1, ($s1)
/* 02FC70 80054870 2402424B */  addiu $v0, $zero, 0x424b
/* 02FC74 80054874 54620050 */  bnel  $v1, $v0, .L800549B8
/* 02FC78 80054878 0000902D */   daddu $s2, $zero, $zero
/* 02FC7C 8005487C 8E220004 */  lw    $v0, 4($s1)
/* 02FC80 80054880 5040004D */  beql  $v0, $zero, .L800549B8
/* 02FC84 80054884 0000902D */   daddu $s2, $zero, $zero
/* 02FC88 80054888 0801526E */  j     .L800549B8
/* 02FC8C 8005488C 24130015 */   addiu $s3, $zero, 0x15

.L80054890:
/* 02FC90 80054890 9623000C */  lhu   $v1, 0xc($s1)
/* 02FC94 80054894 24024352 */  addiu $v0, $zero, 0x4352
/* 02FC98 80054898 14620003 */  bne   $v1, $v0, .L800548A8
/* 02FC9C 8005489C 24024452 */   addiu $v0, $zero, 0x4452
/* 02FCA0 800548A0 0801526E */  j     .L800549B8
/* 02FCA4 800548A4 24130065 */   addiu $s3, $zero, 0x65

.L800548A8:
/* 02FCA8 800548A8 14620003 */  bne   $v1, $v0, .L800548B8
/* 02FCAC 800548AC 24025352 */   addiu $v0, $zero, 0x5352
/* 02FCB0 800548B0 0801526E */  j     .L800549B8
/* 02FCB4 800548B4 241300C9 */   addiu $s3, $zero, 0xc9

.L800548B8:
/* 02FCB8 800548B8 5462003F */  bnel  $v1, $v0, .L800549B8
/* 02FCBC 800548BC 0000902D */   daddu $s2, $zero, $zero
/* 02FCC0 800548C0 0801526E */  j     .L800549B8
/* 02FCC4 800548C4 2413012D */   addiu $s3, $zero, 0x12d

.L800548C8:
/* 02FCC8 800548C8 96240032 */  lhu   $a0, 0x32($s1)
/* 02FCCC 800548CC 96220036 */  lhu   $v0, 0x36($s1)
/* 02FCD0 800548D0 9623003A */  lhu   $v1, 0x3a($s1)
/* 02FCD4 800548D4 2484000F */  addiu $a0, $a0, 0xf
/* 02FCD8 800548D8 3084FFF0 */  andi  $a0, $a0, 0xfff0
/* 02FCDC 800548DC 2442000F */  addiu $v0, $v0, 0xf
/* 02FCE0 800548E0 3042FFF0 */  andi  $v0, $v0, 0xfff0
/* 02FCE4 800548E4 00822021 */  addu  $a0, $a0, $v0
/* 02FCE8 800548E8 2463000F */  addiu $v1, $v1, 0xf
/* 02FCEC 800548EC 3063FFF0 */  andi  $v1, $v1, 0xfff0
/* 02FCF0 800548F0 9622003E */  lhu   $v0, 0x3e($s1)
/* 02FCF4 800548F4 00832021 */  addu  $a0, $a0, $v1
/* 02FCF8 800548F8 2442000F */  addiu $v0, $v0, 0xf
/* 02FCFC 800548FC 3042FFF0 */  andi  $v0, $v0, 0xfff0
/* 02FD00 80054900 00822021 */  addu  $a0, $a0, $v0
/* 02FD04 80054904 16800006 */  bnez  $s4, .L80054920
/* 02FD08 80054908 24900040 */   addiu $s0, $a0, 0x40
/* 02FD0C 8005490C 02C0202D */  daddu $a0, $s6, $zero
/* 02FD10 80054910 24050001 */  addiu $a1, $zero, 1
/* 02FD14 80054914 0C015FE4 */  jal   alHeapAlloc
/* 02FD18 80054918 0200302D */   daddu $a2, $s0, $zero
/* 02FD1C 8005491C 0040A02D */  daddu $s4, $v0, $zero
.L80054920:
/* 02FD20 80054920 02A0202D */  daddu $a0, $s5, $zero
/* 02FD24 80054924 0280282D */  daddu $a1, $s4, $zero
/* 02FD28 80054928 0C015380 */  jal   al_DmaCopy
/* 02FD2C 8005492C 0200302D */   daddu $a2, $s0, $zero
/* 02FD30 80054930 03C0202D */  daddu $a0, $fp, $zero
/* 02FD34 80054934 0C0151D1 */  jal   func_80054744
/* 02FD38 80054938 02E0282D */   daddu $a1, $s7, $zero
/* 02FD3C 8005493C 0040802D */  daddu $s0, $v0, $zero
/* 02FD40 80054940 0200182D */  daddu $v1, $s0, $zero
/* 02FD44 80054944 0000302D */  daddu $a2, $zero, $zero
/* 02FD48 80054948 00C0282D */  daddu $a1, $a2, $zero
/* 02FD4C 8005494C 0220202D */  daddu $a0, $s1, $zero
.L80054950:
/* 02FD50 80054950 94820012 */  lhu   $v0, 0x12($a0)
/* 02FD54 80054954 10400004 */  beqz  $v0, .L80054968
/* 02FD58 80054958 00541021 */   addu  $v0, $v0, $s4
/* 02FD5C 8005495C 24C60001 */  addiu $a2, $a2, 1
/* 02FD60 80054960 0801525B */  j     .L8005496C
/* 02FD64 80054964 AC620000 */   sw    $v0, ($v1)

.L80054968:
/* 02FD68 80054968 AC600000 */  sw    $zero, ($v1)
.L8005496C:
/* 02FD6C 8005496C 24630004 */  addiu $v1, $v1, 4
/* 02FD70 80054970 24A50001 */  addiu $a1, $a1, 1
/* 02FD74 80054974 2CA20010 */  sltiu $v0, $a1, 0x10
/* 02FD78 80054978 1440FFF5 */  bnez  $v0, .L80054950
/* 02FD7C 8005497C 24840002 */   addiu $a0, $a0, 2
/* 02FD80 80054980 50C0000D */  beql  $a2, $zero, .L800549B8
/* 02FD84 80054984 0000902D */   daddu $s2, $zero, $zero
/* 02FD88 80054988 0801526E */  j     .L800549B8
/* 02FD8C 8005498C 2413006F */   addiu $s3, $zero, 0x6f

.L80054990:
/* 02FD90 80054990 24020001 */  addiu $v0, $zero, 1
/* 02FD94 80054994 AFA20010 */  sw    $v0, 0x10($sp)
/* 02FD98 80054998 02A0202D */  daddu $a0, $s5, $zero
/* 02FD9C 8005499C 0280282D */  daddu $a1, $s4, $zero
/* 02FDA0 800549A0 0200302D */  daddu $a2, $s0, $zero
/* 02FDA4 800549A4 0C01527E */  jal   func_800549F8
/* 02FDA8 800549A8 24070010 */   addiu $a3, $zero, 0x10
/* 02FDAC 800549AC 0801526E */  j     .L800549B8
/* 02FDB0 800549B0 0000982D */   daddu $s3, $zero, $zero

.L800549B4:
/* 02FDB4 800549B4 0000902D */  daddu $s2, $zero, $zero
.L800549B8:
/* 02FDB8 800549B8 3242FFFF */  andi  $v0, $s2, 0xffff
/* 02FDBC 800549BC 1440FF9B */  bnez  $v0, .L8005482C
/* 02FDC0 800549C0 3263FFFF */   andi  $v1, $s3, 0xffff
/* 02FDC4 800549C4 0280102D */  daddu $v0, $s4, $zero
/* 02FDC8 800549C8 8FBF007C */  lw    $ra, 0x7c($sp)
/* 02FDCC 800549CC 8FBE0078 */  lw    $fp, 0x78($sp)
/* 02FDD0 800549D0 8FB70074 */  lw    $s7, 0x74($sp)
/* 02FDD4 800549D4 8FB60070 */  lw    $s6, 0x70($sp)
/* 02FDD8 800549D8 8FB5006C */  lw    $s5, 0x6c($sp)
/* 02FDDC 800549DC 8FB40068 */  lw    $s4, 0x68($sp)
/* 02FDE0 800549E0 8FB30064 */  lw    $s3, 0x64($sp)
/* 02FDE4 800549E4 8FB20060 */  lw    $s2, 0x60($sp)
/* 02FDE8 800549E8 8FB1005C */  lw    $s1, 0x5c($sp)
/* 02FDEC 800549EC 8FB00058 */  lw    $s0, 0x58($sp)
/* 02FDF0 800549F0 03E00008 */  jr    $ra
/* 02FDF4 800549F4 27BD0080 */   addiu $sp, $sp, 0x80

