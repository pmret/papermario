.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D4C4C
/* F95FC 802D4C4C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F9600 802D4C50 AFBF0010 */  sw        $ra, 0x10($sp)
/* F9604 802D4C54 10A00004 */  beqz      $a1, .L802D4C68
/* F9608 802D4C58 0080182D */   daddu    $v1, $a0, $zero
/* F960C 802D4C5C 240200FF */  addiu     $v0, $zero, 0xff
/* F9610 802D4C60 AC600070 */  sw        $zero, 0x70($v1)
/* F9614 802D4C64 AC620074 */  sw        $v0, 0x74($v1)
.L802D4C68:
/* F9618 802D4C68 8C620070 */  lw        $v0, 0x70($v1)
/* F961C 802D4C6C 14400012 */  bnez      $v0, .L802D4CB8
/* F9620 802D4C70 0000102D */   daddu    $v0, $zero, $zero
/* F9624 802D4C74 8C620074 */  lw        $v0, 0x74($v1)
/* F9628 802D4C78 14400006 */  bnez      $v0, .L802D4C94
/* F962C 802D4C7C 2442FFF6 */   addiu    $v0, $v0, -0xa
/* F9630 802D4C80 3C05BF80 */  lui       $a1, 0xbf80
/* F9634 802D4C84 0C04DF69 */  jal       func_80137DA4
/* F9638 802D4C88 240400FF */   addiu    $a0, $zero, 0xff
/* F963C 802D4C8C 080B532E */  j         .L802D4CB8
/* F9640 802D4C90 24020002 */   addiu    $v0, $zero, 2
.L802D4C94:
/* F9644 802D4C94 04410002 */  bgez      $v0, .L802D4CA0
/* F9648 802D4C98 AC620074 */   sw       $v0, 0x74($v1)
/* F964C 802D4C9C AC600074 */  sw        $zero, 0x74($v1)
.L802D4CA0:
/* F9650 802D4CA0 C4600074 */  lwc1      $f0, 0x74($v1)
/* F9654 802D4CA4 46800020 */  cvt.s.w   $f0, $f0
/* F9658 802D4CA8 44050000 */  mfc1      $a1, $f0
/* F965C 802D4CAC 0C04DF69 */  jal       func_80137DA4
/* F9660 802D4CB0 2404000A */   addiu    $a0, $zero, 0xa
/* F9664 802D4CB4 0000102D */  daddu     $v0, $zero, $zero
.L802D4CB8:
/* F9668 802D4CB8 8FBF0010 */  lw        $ra, 0x10($sp)
/* F966C 802D4CBC 03E00008 */  jr        $ra
/* F9670 802D4CC0 27BD0018 */   addiu    $sp, $sp, 0x18
