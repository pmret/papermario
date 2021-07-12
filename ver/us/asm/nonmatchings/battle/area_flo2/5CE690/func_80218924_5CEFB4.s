.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218924_5CEFB4
/* 5CEFB4 80218924 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5CEFB8 80218928 AFB1001C */  sw        $s1, 0x1c($sp)
/* 5CEFBC 8021892C 0080882D */  daddu     $s1, $a0, $zero
/* 5CEFC0 80218930 AFBF0028 */  sw        $ra, 0x28($sp)
/* 5CEFC4 80218934 AFB30024 */  sw        $s3, 0x24($sp)
/* 5CEFC8 80218938 AFB20020 */  sw        $s2, 0x20($sp)
/* 5CEFCC 8021893C AFB00018 */  sw        $s0, 0x18($sp)
/* 5CEFD0 80218940 8E30000C */  lw        $s0, 0xc($s1)
/* 5CEFD4 80218944 8E050000 */  lw        $a1, ($s0)
/* 5CEFD8 80218948 0C0B1EAF */  jal       get_variable
/* 5CEFDC 8021894C 26100004 */   addiu    $s0, $s0, 4
/* 5CEFE0 80218950 8E050000 */  lw        $a1, ($s0)
/* 5CEFE4 80218954 26100004 */  addiu     $s0, $s0, 4
/* 5CEFE8 80218958 0220202D */  daddu     $a0, $s1, $zero
/* 5CEFEC 8021895C 0C0B1EAF */  jal       get_variable
/* 5CEFF0 80218960 0040982D */   daddu    $s3, $v0, $zero
/* 5CEFF4 80218964 8E050000 */  lw        $a1, ($s0)
/* 5CEFF8 80218968 26100004 */  addiu     $s0, $s0, 4
/* 5CEFFC 8021896C 0220202D */  daddu     $a0, $s1, $zero
/* 5CF000 80218970 0C0B1EAF */  jal       get_variable
/* 5CF004 80218974 0040902D */   daddu    $s2, $v0, $zero
/* 5CF008 80218978 0220202D */  daddu     $a0, $s1, $zero
/* 5CF00C 8021897C 8E050000 */  lw        $a1, ($s0)
/* 5CF010 80218980 0C0B210B */  jal       get_float_variable
/* 5CF014 80218984 0040802D */   daddu    $s0, $v0, $zero
/* 5CF018 80218988 44932000 */  mtc1      $s3, $f4
/* 5CF01C 8021898C 00000000 */  nop
/* 5CF020 80218990 46802120 */  cvt.s.w   $f4, $f4
/* 5CF024 80218994 44052000 */  mfc1      $a1, $f4
/* 5CF028 80218998 44922000 */  mtc1      $s2, $f4
/* 5CF02C 8021899C 00000000 */  nop
/* 5CF030 802189A0 46802120 */  cvt.s.w   $f4, $f4
/* 5CF034 802189A4 3C014020 */  lui       $at, 0x4020
/* 5CF038 802189A8 44811000 */  mtc1      $at, $f2
/* 5CF03C 802189AC 44062000 */  mfc1      $a2, $f4
/* 5CF040 802189B0 46020002 */  mul.s     $f0, $f0, $f2
/* 5CF044 802189B4 00000000 */  nop
/* 5CF048 802189B8 44902000 */  mtc1      $s0, $f4
/* 5CF04C 802189BC 00000000 */  nop
/* 5CF050 802189C0 46802120 */  cvt.s.w   $f4, $f4
/* 5CF054 802189C4 44072000 */  mfc1      $a3, $f4
/* 5CF058 802189C8 0000202D */  daddu     $a0, $zero, $zero
/* 5CF05C 802189CC AFA00014 */  sw        $zero, 0x14($sp)
/* 5CF060 802189D0 0C01C64C */  jal       playFX_57
/* 5CF064 802189D4 E7A00010 */   swc1     $f0, 0x10($sp)
/* 5CF068 802189D8 AE220084 */  sw        $v0, 0x84($s1)
/* 5CF06C 802189DC 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5CF070 802189E0 8FB30024 */  lw        $s3, 0x24($sp)
/* 5CF074 802189E4 8FB20020 */  lw        $s2, 0x20($sp)
/* 5CF078 802189E8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5CF07C 802189EC 8FB00018 */  lw        $s0, 0x18($sp)
/* 5CF080 802189F0 24020002 */  addiu     $v0, $zero, 2
/* 5CF084 802189F4 03E00008 */  jr        $ra
/* 5CF088 802189F8 27BD0030 */   addiu    $sp, $sp, 0x30
