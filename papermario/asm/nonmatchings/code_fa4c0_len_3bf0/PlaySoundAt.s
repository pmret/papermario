.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlaySoundAt
/* 0FAB8C 802D61DC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0FAB90 802D61E0 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0FAB94 802D61E4 0080882D */  daddu $s1, $a0, $zero
/* 0FAB98 802D61E8 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0FAB9C 802D61EC AFB40028 */  sw    $s4, 0x28($sp)
/* 0FABA0 802D61F0 AFB30024 */  sw    $s3, 0x24($sp)
/* 0FABA4 802D61F4 AFB20020 */  sw    $s2, 0x20($sp)
/* 0FABA8 802D61F8 AFB00018 */  sw    $s0, 0x18($sp)
/* 0FABAC 802D61FC 8E30000C */  lw    $s0, 0xc($s1)
/* 0FABB0 802D6200 8E050000 */  lw    $a1, ($s0)
/* 0FABB4 802D6204 0C0B1EAF */  jal   get_variable
/* 0FABB8 802D6208 26100004 */   addiu $s0, $s0, 4
/* 0FABBC 802D620C 8E050000 */  lw    $a1, ($s0)
/* 0FABC0 802D6210 26100004 */  addiu $s0, $s0, 4
/* 0FABC4 802D6214 0220202D */  daddu $a0, $s1, $zero
/* 0FABC8 802D6218 0C0B1EAF */  jal   get_variable
/* 0FABCC 802D621C 0040A02D */   daddu $s4, $v0, $zero
/* 0FABD0 802D6220 8E050000 */  lw    $a1, ($s0)
/* 0FABD4 802D6224 26100004 */  addiu $s0, $s0, 4
/* 0FABD8 802D6228 0220202D */  daddu $a0, $s1, $zero
/* 0FABDC 802D622C 0C0B1EAF */  jal   get_variable
/* 0FABE0 802D6230 0040982D */   daddu $s3, $v0, $zero
/* 0FABE4 802D6234 8E050000 */  lw    $a1, ($s0)
/* 0FABE8 802D6238 26100004 */  addiu $s0, $s0, 4
/* 0FABEC 802D623C 0220202D */  daddu $a0, $s1, $zero
/* 0FABF0 802D6240 0C0B1EAF */  jal   get_variable
/* 0FABF4 802D6244 0040902D */   daddu $s2, $v0, $zero
/* 0FABF8 802D6248 0220202D */  daddu $a0, $s1, $zero
/* 0FABFC 802D624C 8E050000 */  lw    $a1, ($s0)
/* 0FAC00 802D6250 0C0B1EAF */  jal   get_variable
/* 0FAC04 802D6254 0040802D */   daddu $s0, $v0, $zero
/* 0FAC08 802D6258 0280202D */  daddu $a0, $s4, $zero
/* 0FAC0C 802D625C 0260282D */  daddu $a1, $s3, $zero
/* 0FAC10 802D6260 44921000 */  mtc1  $s2, $f2
/* 0FAC14 802D6264 00000000 */  nop   
/* 0FAC18 802D6268 468010A0 */  cvt.s.w $f2, $f2
/* 0FAC1C 802D626C 44061000 */  mfc1  $a2, $f2
/* 0FAC20 802D6270 44901000 */  mtc1  $s0, $f2
/* 0FAC24 802D6274 00000000 */  nop   
/* 0FAC28 802D6278 468010A0 */  cvt.s.w $f2, $f2
/* 0FAC2C 802D627C 44071000 */  mfc1  $a3, $f2
/* 0FAC30 802D6280 44820000 */  mtc1  $v0, $f0
/* 0FAC34 802D6284 00000000 */  nop   
/* 0FAC38 802D6288 46800020 */  cvt.s.w $f0, $f0
/* 0FAC3C 802D628C 0C052757 */  jal   play_sound_at_position
/* 0FAC40 802D6290 E7A00010 */   swc1  $f0, 0x10($sp)
/* 0FAC44 802D6294 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0FAC48 802D6298 8FB40028 */  lw    $s4, 0x28($sp)
/* 0FAC4C 802D629C 8FB30024 */  lw    $s3, 0x24($sp)
/* 0FAC50 802D62A0 8FB20020 */  lw    $s2, 0x20($sp)
/* 0FAC54 802D62A4 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0FAC58 802D62A8 8FB00018 */  lw    $s0, 0x18($sp)
/* 0FAC5C 802D62AC 24020002 */  addiu $v0, $zero, 2
/* 0FAC60 802D62B0 03E00008 */  jr    $ra
/* 0FAC64 802D62B4 27BD0030 */   addiu $sp, $sp, 0x30

