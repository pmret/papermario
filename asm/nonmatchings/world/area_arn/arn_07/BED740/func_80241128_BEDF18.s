.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241128_BEDF18
/* BEDF18 80241128 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BEDF1C 8024112C AFB3001C */  sw        $s3, 0x1c($sp)
/* BEDF20 80241130 0080982D */  daddu     $s3, $a0, $zero
/* BEDF24 80241134 AFBF0020 */  sw        $ra, 0x20($sp)
/* BEDF28 80241138 AFB20018 */  sw        $s2, 0x18($sp)
/* BEDF2C 8024113C AFB10014 */  sw        $s1, 0x14($sp)
/* BEDF30 80241140 AFB00010 */  sw        $s0, 0x10($sp)
/* BEDF34 80241144 8E720148 */  lw        $s2, 0x148($s3)
/* BEDF38 80241148 86440008 */  lh        $a0, 8($s2)
/* BEDF3C 8024114C 0C00EABB */  jal       get_npc_unsafe
/* BEDF40 80241150 00A0882D */   daddu    $s1, $a1, $zero
/* BEDF44 80241154 8E240008 */  lw        $a0, 8($s1)
/* BEDF48 80241158 0040802D */  daddu     $s0, $v0, $zero
/* BEDF4C 8024115C 00041FC2 */  srl       $v1, $a0, 0x1f
/* BEDF50 80241160 00832021 */  addu      $a0, $a0, $v1
/* BEDF54 80241164 00042043 */  sra       $a0, $a0, 1
/* BEDF58 80241168 0C00A67F */  jal       rand_int
/* BEDF5C 8024116C 24840001 */   addiu    $a0, $a0, 1
/* BEDF60 80241170 8E230008 */  lw        $v1, 8($s1)
/* BEDF64 80241174 240400B4 */  addiu     $a0, $zero, 0xb4
/* BEDF68 80241178 00032FC2 */  srl       $a1, $v1, 0x1f
/* BEDF6C 8024117C 00651821 */  addu      $v1, $v1, $a1
/* BEDF70 80241180 00031843 */  sra       $v1, $v1, 1
/* BEDF74 80241184 00621821 */  addu      $v1, $v1, $v0
/* BEDF78 80241188 0C00A67F */  jal       rand_int
/* BEDF7C 8024118C A603008E */   sh       $v1, 0x8e($s0)
/* BEDF80 80241190 C60C000C */  lwc1      $f12, 0xc($s0)
/* BEDF84 80241194 44820000 */  mtc1      $v0, $f0
/* BEDF88 80241198 00000000 */  nop       
/* BEDF8C 8024119C 46800020 */  cvt.s.w   $f0, $f0
/* BEDF90 802411A0 46006300 */  add.s     $f12, $f12, $f0
/* BEDF94 802411A4 3C0142B4 */  lui       $at, 0x42b4
/* BEDF98 802411A8 44810000 */  mtc1      $at, $f0
/* BEDF9C 802411AC 0C00A6C9 */  jal       clamp_angle
/* BEDFA0 802411B0 46006301 */   sub.s    $f12, $f12, $f0
/* BEDFA4 802411B4 E600000C */  swc1      $f0, 0xc($s0)
/* BEDFA8 802411B8 8E4200CC */  lw        $v0, 0xcc($s2)
/* BEDFAC 802411BC 8C420000 */  lw        $v0, ($v0)
/* BEDFB0 802411C0 AE020028 */  sw        $v0, 0x28($s0)
/* BEDFB4 802411C4 24020003 */  addiu     $v0, $zero, 3
/* BEDFB8 802411C8 AE620070 */  sw        $v0, 0x70($s3)
/* BEDFBC 802411CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* BEDFC0 802411D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* BEDFC4 802411D4 8FB20018 */  lw        $s2, 0x18($sp)
/* BEDFC8 802411D8 8FB10014 */  lw        $s1, 0x14($sp)
/* BEDFCC 802411DC 8FB00010 */  lw        $s0, 0x10($sp)
/* BEDFD0 802411E0 03E00008 */  jr        $ra
/* BEDFD4 802411E4 27BD0028 */   addiu    $sp, $sp, 0x28
