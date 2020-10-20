.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AF8_C63808
/* C63808 80242AF8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C6380C 80242AFC AFB1001C */  sw        $s1, 0x1c($sp)
/* C63810 80242B00 0080882D */  daddu     $s1, $a0, $zero
/* C63814 80242B04 AFBF0034 */  sw        $ra, 0x34($sp)
/* C63818 80242B08 AFB60030 */  sw        $s6, 0x30($sp)
/* C6381C 80242B0C AFB5002C */  sw        $s5, 0x2c($sp)
/* C63820 80242B10 AFB40028 */  sw        $s4, 0x28($sp)
/* C63824 80242B14 AFB30024 */  sw        $s3, 0x24($sp)
/* C63828 80242B18 AFB20020 */  sw        $s2, 0x20($sp)
/* C6382C 80242B1C AFB00018 */  sw        $s0, 0x18($sp)
/* C63830 80242B20 F7B60040 */  sdc1      $f22, 0x40($sp)
/* C63834 80242B24 F7B40038 */  sdc1      $f20, 0x38($sp)
/* C63838 80242B28 8E30000C */  lw        $s0, 0xc($s1)
/* C6383C 80242B2C 8E160000 */  lw        $s6, ($s0)
/* C63840 80242B30 26100004 */  addiu     $s0, $s0, 4
/* C63844 80242B34 0C0B1EAF */  jal       get_variable
/* C63848 80242B38 02C0282D */   daddu    $a1, $s6, $zero
/* C6384C 80242B3C 44820000 */  mtc1      $v0, $f0
/* C63850 80242B40 00000000 */  nop       
/* C63854 80242B44 46800020 */  cvt.s.w   $f0, $f0
/* C63858 80242B48 E7A00010 */  swc1      $f0, 0x10($sp)
/* C6385C 80242B4C 8E140000 */  lw        $s4, ($s0)
/* C63860 80242B50 26100004 */  addiu     $s0, $s0, 4
/* C63864 80242B54 0220202D */  daddu     $a0, $s1, $zero
/* C63868 80242B58 0C0B1EAF */  jal       get_variable
/* C6386C 80242B5C 0280282D */   daddu    $a1, $s4, $zero
/* C63870 80242B60 0220202D */  daddu     $a0, $s1, $zero
/* C63874 80242B64 8E150000 */  lw        $s5, ($s0)
/* C63878 80242B68 4482B000 */  mtc1      $v0, $f22
/* C6387C 80242B6C 00000000 */  nop       
/* C63880 80242B70 4680B5A0 */  cvt.s.w   $f22, $f22
/* C63884 80242B74 0C0B1EAF */  jal       get_variable
/* C63888 80242B78 02A0282D */   daddu    $a1, $s5, $zero
/* C6388C 80242B7C 2404FFFC */  addiu     $a0, $zero, -4
/* C63890 80242B80 44820000 */  mtc1      $v0, $f0
/* C63894 80242B84 00000000 */  nop       
/* C63898 80242B88 46800020 */  cvt.s.w   $f0, $f0
/* C6389C 80242B8C 0C00EABB */  jal       get_npc_unsafe
/* C638A0 80242B90 E7A00014 */   swc1     $f0, 0x14($sp)
/* C638A4 80242B94 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* C638A8 80242B98 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* C638AC 80242B9C 3C014334 */  lui       $at, 0x4334
/* C638B0 80242BA0 44816000 */  mtc1      $at, $f12
/* C638B4 80242BA4 00041880 */  sll       $v1, $a0, 2
/* C638B8 80242BA8 00641821 */  addu      $v1, $v1, $a0
/* C638BC 80242BAC 00031880 */  sll       $v1, $v1, 2
/* C638C0 80242BB0 00641823 */  subu      $v1, $v1, $a0
/* C638C4 80242BB4 000320C0 */  sll       $a0, $v1, 3
/* C638C8 80242BB8 00641821 */  addu      $v1, $v1, $a0
/* C638CC 80242BBC 000318C0 */  sll       $v1, $v1, 3
/* C638D0 80242BC0 3C01800B */  lui       $at, 0x800b
/* C638D4 80242BC4 00230821 */  addu      $at, $at, $v1
/* C638D8 80242BC8 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* C638DC 80242BCC 460C0300 */  add.s     $f12, $f0, $f12
/* C638E0 80242BD0 0C00A6C9 */  jal       clamp_angle
/* C638E4 80242BD4 0040982D */   daddu    $s3, $v0, $zero
/* C638E8 80242BD8 27B00010 */  addiu     $s0, $sp, 0x10
/* C638EC 80242BDC 0200202D */  daddu     $a0, $s0, $zero
/* C638F0 80242BE0 27B20014 */  addiu     $s2, $sp, 0x14
/* C638F4 80242BE4 0240282D */  daddu     $a1, $s2, $zero
/* C638F8 80242BE8 3C064170 */  lui       $a2, 0x4170
/* C638FC 80242BEC 8E67000C */  lw        $a3, 0xc($s3)
/* C63900 80242BF0 0C00A7E7 */  jal       add_vec2D_polar
/* C63904 80242BF4 46000506 */   mov.s    $f20, $f0
/* C63908 80242BF8 0200202D */  daddu     $a0, $s0, $zero
/* C6390C 80242BFC 3C064120 */  lui       $a2, 0x4120
/* C63910 80242C00 4407A000 */  mfc1      $a3, $f20
/* C63914 80242C04 0C00A7E7 */  jal       add_vec2D_polar
/* C63918 80242C08 0240282D */   daddu    $a1, $s2, $zero
/* C6391C 80242C0C 0220202D */  daddu     $a0, $s1, $zero
/* C63920 80242C10 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C63924 80242C14 4600008D */  trunc.w.s $f2, $f0
/* C63928 80242C18 44061000 */  mfc1      $a2, $f2
/* C6392C 80242C1C 0C0B2026 */  jal       set_variable
/* C63930 80242C20 02C0282D */   daddu    $a1, $s6, $zero
/* C63934 80242C24 0220202D */  daddu     $a0, $s1, $zero
/* C63938 80242C28 4600B08D */  trunc.w.s $f2, $f22
/* C6393C 80242C2C 44061000 */  mfc1      $a2, $f2
/* C63940 80242C30 0C0B2026 */  jal       set_variable
/* C63944 80242C34 0280282D */   daddu    $a1, $s4, $zero
/* C63948 80242C38 0220202D */  daddu     $a0, $s1, $zero
/* C6394C 80242C3C C7A00014 */  lwc1      $f0, 0x14($sp)
/* C63950 80242C40 4600008D */  trunc.w.s $f2, $f0
/* C63954 80242C44 44061000 */  mfc1      $a2, $f2
/* C63958 80242C48 0C0B2026 */  jal       set_variable
/* C6395C 80242C4C 02A0282D */   daddu    $a1, $s5, $zero
/* C63960 80242C50 8FBF0034 */  lw        $ra, 0x34($sp)
/* C63964 80242C54 8FB60030 */  lw        $s6, 0x30($sp)
/* C63968 80242C58 8FB5002C */  lw        $s5, 0x2c($sp)
/* C6396C 80242C5C 8FB40028 */  lw        $s4, 0x28($sp)
/* C63970 80242C60 8FB30024 */  lw        $s3, 0x24($sp)
/* C63974 80242C64 8FB20020 */  lw        $s2, 0x20($sp)
/* C63978 80242C68 8FB1001C */  lw        $s1, 0x1c($sp)
/* C6397C 80242C6C 8FB00018 */  lw        $s0, 0x18($sp)
/* C63980 80242C70 D7B60040 */  ldc1      $f22, 0x40($sp)
/* C63984 80242C74 D7B40038 */  ldc1      $f20, 0x38($sp)
/* C63988 80242C78 24020002 */  addiu     $v0, $zero, 2
/* C6398C 80242C7C 03E00008 */  jr        $ra
/* C63990 80242C80 27BD0048 */   addiu    $sp, $sp, 0x48
