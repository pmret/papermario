.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel CopyStatusEffects
/* 1AC59C 8027DCBC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 1AC5A0 8027DCC0 AFB20018 */  sw        $s2, 0x18($sp)
/* 1AC5A4 8027DCC4 0080902D */  daddu     $s2, $a0, $zero
/* 1AC5A8 8027DCC8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 1AC5AC 8027DCCC AFB3001C */  sw        $s3, 0x1c($sp)
/* 1AC5B0 8027DCD0 AFB10014 */  sw        $s1, 0x14($sp)
/* 1AC5B4 8027DCD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 1AC5B8 8027DCD8 8E50000C */  lw        $s0, 0xc($s2)
/* 1AC5BC 8027DCDC 8E050000 */  lw        $a1, ($s0)
/* 1AC5C0 8027DCE0 0C0B1EAF */  jal       get_variable
/* 1AC5C4 8027DCE4 26100004 */   addiu    $s0, $s0, 4
/* 1AC5C8 8027DCE8 2413FF81 */  addiu     $s3, $zero, -0x7f
/* 1AC5CC 8027DCEC 14530002 */  bne       $v0, $s3, .L8027DCF8
/* 1AC5D0 8027DCF0 00000000 */   nop      
/* 1AC5D4 8027DCF4 8E420148 */  lw        $v0, 0x148($s2)
.L8027DCF8:
/* 1AC5D8 8027DCF8 0C09A75B */  jal       get_actor
/* 1AC5DC 8027DCFC 0040202D */   daddu    $a0, $v0, $zero
/* 1AC5E0 8027DD00 0240202D */  daddu     $a0, $s2, $zero
/* 1AC5E4 8027DD04 8E050000 */  lw        $a1, ($s0)
/* 1AC5E8 8027DD08 0C0B1EAF */  jal       get_variable
/* 1AC5EC 8027DD0C 0040882D */   daddu    $s1, $v0, $zero
/* 1AC5F0 8027DD10 14530002 */  bne       $v0, $s3, .L8027DD1C
/* 1AC5F4 8027DD14 00000000 */   nop      
/* 1AC5F8 8027DD18 8E420148 */  lw        $v0, 0x148($s2)
.L8027DD1C:
/* 1AC5FC 8027DD1C 0C09A75B */  jal       get_actor
/* 1AC600 8027DD20 0040202D */   daddu    $a0, $v0, $zero
/* 1AC604 8027DD24 0040802D */  daddu     $s0, $v0, $zero
/* 1AC608 8027DD28 82250210 */  lb        $a1, 0x210($s1)
/* 1AC60C 8027DD2C 82260211 */  lb        $a2, 0x211($s1)
/* 1AC610 8027DD30 0C0997D0 */  jal       inflict_status
/* 1AC614 8027DD34 0200202D */   daddu    $a0, $s0, $zero
/* 1AC618 8027DD38 82250212 */  lb        $a1, 0x212($s1)
/* 1AC61C 8027DD3C 82260213 */  lb        $a2, 0x213($s1)
/* 1AC620 8027DD40 0C0997D0 */  jal       inflict_status
/* 1AC624 8027DD44 0200202D */   daddu    $a0, $s0, $zero
/* 1AC628 8027DD48 82250214 */  lb        $a1, 0x214($s1)
/* 1AC62C 8027DD4C 82260215 */  lb        $a2, 0x215($s1)
/* 1AC630 8027DD50 0C0997D0 */  jal       inflict_status
/* 1AC634 8027DD54 0200202D */   daddu    $a0, $s0, $zero
/* 1AC638 8027DD58 82250216 */  lb        $a1, 0x216($s1)
/* 1AC63C 8027DD5C 82260217 */  lb        $a2, 0x217($s1)
/* 1AC640 8027DD60 0C0997D0 */  jal       inflict_status
/* 1AC644 8027DD64 0200202D */   daddu    $a0, $s0, $zero
/* 1AC648 8027DD68 82250218 */  lb        $a1, 0x218($s1)
/* 1AC64C 8027DD6C 82260219 */  lb        $a2, 0x219($s1)
/* 1AC650 8027DD70 0C0997D0 */  jal       inflict_status
/* 1AC654 8027DD74 0200202D */   daddu    $a0, $s0, $zero
/* 1AC658 8027DD78 A220021C */  sb        $zero, 0x21c($s1)
/* 1AC65C 8027DD7C A200021C */  sb        $zero, 0x21c($s0)
/* 1AC660 8027DD80 8FBF0020 */  lw        $ra, 0x20($sp)
/* 1AC664 8027DD84 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1AC668 8027DD88 8FB20018 */  lw        $s2, 0x18($sp)
/* 1AC66C 8027DD8C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1AC670 8027DD90 8FB00010 */  lw        $s0, 0x10($sp)
/* 1AC674 8027DD94 24020002 */  addiu     $v0, $zero, 2
/* 1AC678 8027DD98 03E00008 */  jr        $ra
/* 1AC67C 8027DD9C 27BD0028 */   addiu    $sp, $sp, 0x28
