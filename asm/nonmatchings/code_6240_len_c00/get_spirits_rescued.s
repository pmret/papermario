.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_spirits_rescued
/* 6240 8002AE40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6244 8002AE44 0000202D */  daddu     $a0, $zero, $zero
/* 6248 8002AE48 3C05F5DE */  lui       $a1, 0xf5de
/* 624C 8002AE4C 34A50180 */  ori       $a1, $a1, 0x180
/* 6250 8002AE50 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6254 8002AE54 AFB10014 */  sw        $s1, 0x14($sp)
/* 6258 8002AE58 0C0B1EAF */  jal       get_variable
/* 625C 8002AE5C AFB00010 */   sw       $s0, 0x10($sp)
/* 6260 8002AE60 24110007 */  addiu     $s1, $zero, 7
/* 6264 8002AE64 0000202D */  daddu     $a0, $zero, $zero
/* 6268 8002AE68 2405FFB3 */  addiu     $a1, $zero, -0x4d
/* 626C 8002AE6C 0C0B1EAF */  jal       get_variable
/* 6270 8002AE70 0040802D */   daddu    $s0, $v0, $zero
/* 6274 8002AE74 0202102A */  slt       $v0, $s0, $v0
/* 6278 8002AE78 10400003 */  beqz      $v0, .L8002AE88
/* 627C 8002AE7C 0000202D */   daddu    $a0, $zero, $zero
/* 6280 8002AE80 0800ABCA */  j         .L8002AF28
/* 6284 8002AE84 0000882D */   daddu    $s1, $zero, $zero
.L8002AE88:
/* 6288 8002AE88 0C0B1EAF */  jal       get_variable
/* 628C 8002AE8C 2405FFC9 */   addiu    $a1, $zero, -0x37
/* 6290 8002AE90 0202102A */  slt       $v0, $s0, $v0
/* 6294 8002AE94 10400003 */  beqz      $v0, .L8002AEA4
/* 6298 8002AE98 0000202D */   daddu    $a0, $zero, $zero
/* 629C 8002AE9C 0800ABCA */  j         .L8002AF28
/* 62A0 8002AEA0 24110001 */   addiu    $s1, $zero, 1
.L8002AEA4:
/* 62A4 8002AEA4 0C0B1EAF */  jal       get_variable
/* 62A8 8002AEA8 2405FFF1 */   addiu    $a1, $zero, -0xf
/* 62AC 8002AEAC 0202102A */  slt       $v0, $s0, $v0
/* 62B0 8002AEB0 10400003 */  beqz      $v0, .L8002AEC0
/* 62B4 8002AEB4 0000202D */   daddu    $a0, $zero, $zero
/* 62B8 8002AEB8 0800ABCA */  j         .L8002AF28
/* 62BC 8002AEBC 24110002 */   addiu    $s1, $zero, 2
.L8002AEC0:
/* 62C0 8002AEC0 0C0B1EAF */  jal       get_variable
/* 62C4 8002AEC4 24050005 */   addiu    $a1, $zero, 5
/* 62C8 8002AEC8 0202102A */  slt       $v0, $s0, $v0
/* 62CC 8002AECC 10400003 */  beqz      $v0, .L8002AEDC
/* 62D0 8002AED0 0000202D */   daddu    $a0, $zero, $zero
/* 62D4 8002AED4 0800ABCA */  j         .L8002AF28
/* 62D8 8002AED8 24110003 */   addiu    $s1, $zero, 3
.L8002AEDC:
/* 62DC 8002AEDC 0C0B1EAF */  jal       get_variable
/* 62E0 8002AEE0 24050025 */   addiu    $a1, $zero, 0x25
/* 62E4 8002AEE4 0202102A */  slt       $v0, $s0, $v0
/* 62E8 8002AEE8 10400003 */  beqz      $v0, .L8002AEF8
/* 62EC 8002AEEC 0000202D */   daddu    $a0, $zero, $zero
/* 62F0 8002AEF0 0800ABCA */  j         .L8002AF28
/* 62F4 8002AEF4 24110004 */   addiu    $s1, $zero, 4
.L8002AEF8:
/* 62F8 8002AEF8 0C0B1EAF */  jal       get_variable
/* 62FC 8002AEFC 24050039 */   addiu    $a1, $zero, 0x39
/* 6300 8002AF00 0202102A */  slt       $v0, $s0, $v0
/* 6304 8002AF04 10400003 */  beqz      $v0, .L8002AF14
/* 6308 8002AF08 0000202D */   daddu    $a0, $zero, $zero
/* 630C 8002AF0C 0800ABCA */  j         .L8002AF28
/* 6310 8002AF10 24110005 */   addiu    $s1, $zero, 5
.L8002AF14:
/* 6314 8002AF14 0C0B1EAF */  jal       get_variable
/* 6318 8002AF18 24050057 */   addiu    $a1, $zero, 0x57
/* 631C 8002AF1C 0202102A */  slt       $v0, $s0, $v0
/* 6320 8002AF20 54400001 */  bnel      $v0, $zero, .L8002AF28
/* 6324 8002AF24 24110006 */   addiu    $s1, $zero, 6
.L8002AF28:
/* 6328 8002AF28 0220102D */  daddu     $v0, $s1, $zero
/* 632C 8002AF2C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6330 8002AF30 8FB10014 */  lw        $s1, 0x14($sp)
/* 6334 8002AF34 8FB00010 */  lw        $s0, 0x10($sp)
/* 6338 8002AF38 03E00008 */  jr        $ra
/* 633C 8002AF3C 27BD0020 */   addiu    $sp, $sp, 0x20
