.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AE00
/* 6200 8002AE00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6204 8002AE04 0000202D */  daddu     $a0, $zero, $zero
/* 6208 8002AE08 3C05F5DE */  lui       $a1, 0xf5de
/* 620C 8002AE0C 34A50180 */  ori       $a1, $a1, 0x180
/* 6210 8002AE10 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6214 8002AE14 AFB10014 */  sw        $s1, 0x14($sp)
/* 6218 8002AE18 0C0B1EAF */  jal       func_802C7ABC
/* 621C 8002AE1C AFB00010 */   sw       $s0, 0x10($sp)
/* 6220 8002AE20 24110007 */  addiu     $s1, $zero, 7
/* 6224 8002AE24 0000202D */  daddu     $a0, $zero, $zero
/* 6228 8002AE28 2405FFB3 */  addiu     $a1, $zero, -0x4d
/* 622C 8002AE2C 0C0B1EAF */  jal       func_802C7ABC
/* 6230 8002AE30 0040802D */   daddu    $s0, $v0, $zero
/* 6234 8002AE34 0202102A */  slt       $v0, $s0, $v0
/* 6238 8002AE38 10400003 */  beqz      $v0, .L8002AE48
/* 623C 8002AE3C 0000202D */   daddu    $a0, $zero, $zero
/* 6240 8002AE40 0800ABBA */  j         .L8002AEE8
/* 6244 8002AE44 0000882D */   daddu    $s1, $zero, $zero
.L8002AE48:
/* 6248 8002AE48 0C0B1EAF */  jal       func_802C7ABC
/* 624C 8002AE4C 2405FFC9 */   addiu    $a1, $zero, -0x37
/* 6250 8002AE50 0202102A */  slt       $v0, $s0, $v0
/* 6254 8002AE54 10400003 */  beqz      $v0, .L8002AE64
/* 6258 8002AE58 0000202D */   daddu    $a0, $zero, $zero
/* 625C 8002AE5C 0800ABBA */  j         .L8002AEE8
/* 6260 8002AE60 24110001 */   addiu    $s1, $zero, 1
.L8002AE64:
/* 6264 8002AE64 0C0B1EAF */  jal       func_802C7ABC
/* 6268 8002AE68 2405FFF1 */   addiu    $a1, $zero, -0xf
/* 626C 8002AE6C 0202102A */  slt       $v0, $s0, $v0
/* 6270 8002AE70 10400003 */  beqz      $v0, .L8002AE80
/* 6274 8002AE74 0000202D */   daddu    $a0, $zero, $zero
/* 6278 8002AE78 0800ABBA */  j         .L8002AEE8
/* 627C 8002AE7C 24110002 */   addiu    $s1, $zero, 2
.L8002AE80:
/* 6280 8002AE80 0C0B1EAF */  jal       func_802C7ABC
/* 6284 8002AE84 24050005 */   addiu    $a1, $zero, 5
/* 6288 8002AE88 0202102A */  slt       $v0, $s0, $v0
/* 628C 8002AE8C 10400003 */  beqz      $v0, .L8002AE9C
/* 6290 8002AE90 0000202D */   daddu    $a0, $zero, $zero
/* 6294 8002AE94 0800ABBA */  j         .L8002AEE8
/* 6298 8002AE98 24110003 */   addiu    $s1, $zero, 3
.L8002AE9C:
/* 629C 8002AE9C 0C0B1EAF */  jal       func_802C7ABC
/* 62A0 8002AEA0 24050025 */   addiu    $a1, $zero, 0x25
/* 62A4 8002AEA4 0202102A */  slt       $v0, $s0, $v0
/* 62A8 8002AEA8 10400003 */  beqz      $v0, .L8002AEB8
/* 62AC 8002AEAC 0000202D */   daddu    $a0, $zero, $zero
/* 62B0 8002AEB0 0800ABBA */  j         .L8002AEE8
/* 62B4 8002AEB4 24110004 */   addiu    $s1, $zero, 4
.L8002AEB8:
/* 62B8 8002AEB8 0C0B1EAF */  jal       func_802C7ABC
/* 62BC 8002AEBC 24050039 */   addiu    $a1, $zero, 0x39
/* 62C0 8002AEC0 0202102A */  slt       $v0, $s0, $v0
/* 62C4 8002AEC4 10400003 */  beqz      $v0, .L8002AED4
/* 62C8 8002AEC8 0000202D */   daddu    $a0, $zero, $zero
/* 62CC 8002AECC 0800ABBA */  j         .L8002AEE8
/* 62D0 8002AED0 24110005 */   addiu    $s1, $zero, 5
.L8002AED4:
/* 62D4 8002AED4 0C0B1EAF */  jal       func_802C7ABC
/* 62D8 8002AED8 24050057 */   addiu    $a1, $zero, 0x57
/* 62DC 8002AEDC 0202102A */  slt       $v0, $s0, $v0
/* 62E0 8002AEE0 54400001 */  bnel      $v0, $zero, .L8002AEE8
/* 62E4 8002AEE4 24110006 */   addiu    $s1, $zero, 6
.L8002AEE8:
/* 62E8 8002AEE8 0220102D */  daddu     $v0, $s1, $zero
/* 62EC 8002AEEC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 62F0 8002AEF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 62F4 8002AEF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 62F8 8002AEF8 03E00008 */  jr        $ra
/* 62FC 8002AEFC 27BD0020 */   addiu    $sp, $sp, 0x20
