.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240208_926BF8
/* 926BF8 80240208 3C01C019 */  lui       $at, 0xc019
/* 926BFC 8024020C 3421999A */  ori       $at, $at, 0x999a
/* 926C00 80240210 44810000 */  mtc1      $at, $f0
/* 926C04 80240214 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 926C08 80240218 AFB00010 */  sw        $s0, 0x10($sp)
/* 926C0C 8024021C 0080802D */  daddu     $s0, $a0, $zero
/* 926C10 80240220 AFBF0014 */  sw        $ra, 0x14($sp)
/* 926C14 80240224 C60C008C */  lwc1      $f12, 0x8c($s0)
/* 926C18 80240228 46806320 */  cvt.s.w   $f12, $f12
/* 926C1C 8024022C 46006302 */  mul.s     $f12, $f12, $f0
/* 926C20 80240230 00000000 */  nop
/* 926C24 80240234 3C013F19 */  lui       $at, 0x3f19
/* 926C28 80240238 3421999A */  ori       $at, $at, 0x999a
/* 926C2C 8024023C 44810000 */  mtc1      $at, $f0
/* 926C30 80240240 00000000 */  nop
/* 926C34 80240244 46006302 */  mul.s     $f12, $f12, $f0
/* 926C38 80240248 0C00A6C9 */  jal       clamp_angle
/* 926C3C 8024024C 00000000 */   nop
/* 926C40 80240250 3C05FE36 */  lui       $a1, 0xfe36
/* 926C44 80240254 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 926C48 80240258 44060000 */  mfc1      $a2, $f0
/* 926C4C 8024025C 0C0B2190 */  jal       set_float_variable
/* 926C50 80240260 0200202D */   daddu    $a0, $s0, $zero
/* 926C54 80240264 8FBF0014 */  lw        $ra, 0x14($sp)
/* 926C58 80240268 8FB00010 */  lw        $s0, 0x10($sp)
/* 926C5C 8024026C 24020002 */  addiu     $v0, $zero, 2
/* 926C60 80240270 03E00008 */  jr        $ra
/* 926C64 80240274 27BD0018 */   addiu    $sp, $sp, 0x18
/* 926C68 80240278 00000000 */  nop
/* 926C6C 8024027C 00000000 */  nop
