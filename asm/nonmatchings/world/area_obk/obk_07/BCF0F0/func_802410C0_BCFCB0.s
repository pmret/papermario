.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410C0_BCFCB0
/* BCFCB0 802410C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BCFCB4 802410C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* BCFCB8 802410C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* BCFCBC 802410CC 0C090150 */  jal       func_80240540_BCF130
/* BCFCC0 802410D0 AFB00018 */   sw       $s0, 0x18($sp)
/* BCFCC4 802410D4 0040882D */  daddu     $s1, $v0, $zero
/* BCFCC8 802410D8 0C0511EA */  jal       draw_icon_0
/* BCFCCC 802410DC 8E24003C */   lw       $a0, 0x3c($s1)
/* BCFCD0 802410E0 8E300040 */  lw        $s0, 0x40($s1)
/* BCFCD4 802410E4 0C0511EA */  jal       draw_icon_0
/* BCFCD8 802410E8 0200202D */   daddu    $a0, $s0, $zero
/* BCFCDC 802410EC 0200202D */  daddu     $a0, $s0, $zero
/* BCFCE0 802410F0 27A50010 */  addiu     $a1, $sp, 0x10
/* BCFCE4 802410F4 0C05126B */  jal       get_icon_render_pos
/* BCFCE8 802410F8 27A60014 */   addiu    $a2, $sp, 0x14
/* BCFCEC 802410FC 8FA40010 */  lw        $a0, 0x10($sp)
/* BCFCF0 80241100 8FA50014 */  lw        $a1, 0x14($sp)
/* BCFCF4 80241104 8E260004 */  lw        $a2, 4($s1)
/* BCFCF8 80241108 0C090284 */  jal       func_80240A10_BCF600
/* BCFCFC 8024110C 24070002 */   addiu    $a3, $zero, 2
/* BCFD00 80241110 8E240044 */  lw        $a0, 0x44($s1)
/* BCFD04 80241114 0C0511EA */  jal       draw_icon_0
/* BCFD08 80241118 00000000 */   nop
/* BCFD0C 8024111C 8FBF0020 */  lw        $ra, 0x20($sp)
/* BCFD10 80241120 8FB1001C */  lw        $s1, 0x1c($sp)
/* BCFD14 80241124 8FB00018 */  lw        $s0, 0x18($sp)
/* BCFD18 80241128 03E00008 */  jr        $ra
/* BCFD1C 8024112C 27BD0028 */   addiu    $sp, $sp, 0x28
