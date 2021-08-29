.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240274_907CA4
/* 907CA4 80240274 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 907CA8 80240278 AFB20018 */  sw        $s2, 0x18($sp)
/* 907CAC 8024027C 0080902D */  daddu     $s2, $a0, $zero
/* 907CB0 80240280 AFB00010 */  sw        $s0, 0x10($sp)
/* 907CB4 80240284 00A0802D */  daddu     $s0, $a1, $zero
/* 907CB8 80240288 3C05FD05 */  lui       $a1, 0xfd05
/* 907CBC 8024028C AFBF0020 */  sw        $ra, 0x20($sp)
/* 907CC0 80240290 AFB3001C */  sw        $s3, 0x1c($sp)
/* 907CC4 80240294 AFB10014 */  sw        $s1, 0x14($sp)
/* 907CC8 80240298 8E53000C */  lw        $s3, 0xc($s2)
/* 907CCC 8024029C 0C0B1EAF */  jal       evt_get_variable
/* 907CD0 802402A0 34A50F80 */   ori      $a1, $a1, 0xf80
/* 907CD4 802402A4 12000006 */  beqz      $s0, .L802402C0
/* 907CD8 802402A8 0040882D */   daddu    $s1, $v0, $zero
/* 907CDC 802402AC A6200020 */  sh        $zero, 0x20($s1)
/* 907CE0 802402B0 8E650000 */  lw        $a1, ($s3)
/* 907CE4 802402B4 0C0B210B */  jal       evt_get_float_variable
/* 907CE8 802402B8 0240202D */   daddu    $a0, $s2, $zero
/* 907CEC 802402BC E6200014 */  swc1      $f0, 0x14($s1)
.L802402C0:
/* 907CF0 802402C0 86220020 */  lh        $v0, 0x20($s1)
/* 907CF4 802402C4 14400007 */  bnez      $v0, .L802402E4
/* 907CF8 802402C8 24020002 */   addiu    $v0, $zero, 2
/* 907CFC 802402CC C6200010 */  lwc1      $f0, 0x10($s1)
/* 907D00 802402D0 C62C0014 */  lwc1      $f12, 0x14($s1)
/* 907D04 802402D4 0C00A6C9 */  jal       clamp_angle
/* 907D08 802402D8 460C0300 */   add.s    $f12, $f0, $f12
/* 907D0C 802402DC 0000102D */  daddu     $v0, $zero, $zero
/* 907D10 802402E0 E6200010 */  swc1      $f0, 0x10($s1)
.L802402E4:
/* 907D14 802402E4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 907D18 802402E8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 907D1C 802402EC 8FB20018 */  lw        $s2, 0x18($sp)
/* 907D20 802402F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 907D24 802402F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 907D28 802402F8 03E00008 */  jr        $ra
/* 907D2C 802402FC 27BD0028 */   addiu    $sp, $sp, 0x28
