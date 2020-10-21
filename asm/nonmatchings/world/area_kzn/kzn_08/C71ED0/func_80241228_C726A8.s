.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241228_C726A8
/* C726A8 80241228 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C726AC 8024122C AFB3001C */  sw        $s3, 0x1c($sp)
/* C726B0 80241230 0080982D */  daddu     $s3, $a0, $zero
/* C726B4 80241234 AFBF0020 */  sw        $ra, 0x20($sp)
/* C726B8 80241238 AFB20018 */  sw        $s2, 0x18($sp)
/* C726BC 8024123C AFB10014 */  sw        $s1, 0x14($sp)
/* C726C0 80241240 AFB00010 */  sw        $s0, 0x10($sp)
/* C726C4 80241244 8E720148 */  lw        $s2, 0x148($s3)
/* C726C8 80241248 86440008 */  lh        $a0, 8($s2)
/* C726CC 8024124C 0C00EABB */  jal       get_npc_unsafe
/* C726D0 80241250 00A0882D */   daddu    $s1, $a1, $zero
/* C726D4 80241254 8E240008 */  lw        $a0, 8($s1)
/* C726D8 80241258 0040802D */  daddu     $s0, $v0, $zero
/* C726DC 8024125C 00041FC2 */  srl       $v1, $a0, 0x1f
/* C726E0 80241260 00832021 */  addu      $a0, $a0, $v1
/* C726E4 80241264 00042043 */  sra       $a0, $a0, 1
/* C726E8 80241268 0C00A67F */  jal       rand_int
/* C726EC 8024126C 24840001 */   addiu    $a0, $a0, 1
/* C726F0 80241270 8E230008 */  lw        $v1, 8($s1)
/* C726F4 80241274 240400B4 */  addiu     $a0, $zero, 0xb4
/* C726F8 80241278 00032FC2 */  srl       $a1, $v1, 0x1f
/* C726FC 8024127C 00651821 */  addu      $v1, $v1, $a1
/* C72700 80241280 00031843 */  sra       $v1, $v1, 1
/* C72704 80241284 00621821 */  addu      $v1, $v1, $v0
/* C72708 80241288 0C00A67F */  jal       rand_int
/* C7270C 8024128C A603008E */   sh       $v1, 0x8e($s0)
/* C72710 80241290 C60C000C */  lwc1      $f12, 0xc($s0)
/* C72714 80241294 44820000 */  mtc1      $v0, $f0
/* C72718 80241298 00000000 */  nop       
/* C7271C 8024129C 46800020 */  cvt.s.w   $f0, $f0
/* C72720 802412A0 46006300 */  add.s     $f12, $f12, $f0
/* C72724 802412A4 3C0142B4 */  lui       $at, 0x42b4
/* C72728 802412A8 44810000 */  mtc1      $at, $f0
/* C7272C 802412AC 0C00A6C9 */  jal       clamp_angle
/* C72730 802412B0 46006301 */   sub.s    $f12, $f12, $f0
/* C72734 802412B4 E600000C */  swc1      $f0, 0xc($s0)
/* C72738 802412B8 8E4200CC */  lw        $v0, 0xcc($s2)
/* C7273C 802412BC 8C420000 */  lw        $v0, ($v0)
/* C72740 802412C0 AE020028 */  sw        $v0, 0x28($s0)
/* C72744 802412C4 24020003 */  addiu     $v0, $zero, 3
/* C72748 802412C8 AE620070 */  sw        $v0, 0x70($s3)
/* C7274C 802412CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C72750 802412D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C72754 802412D4 8FB20018 */  lw        $s2, 0x18($sp)
/* C72758 802412D8 8FB10014 */  lw        $s1, 0x14($sp)
/* C7275C 802412DC 8FB00010 */  lw        $s0, 0x10($sp)
/* C72760 802412E0 03E00008 */  jr        $ra
/* C72764 802412E4 27BD0028 */   addiu    $sp, $sp, 0x28
