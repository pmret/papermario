.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024292C_C001AC
/* C001AC 8024292C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C001B0 80242930 AFB3001C */  sw        $s3, 0x1c($sp)
/* C001B4 80242934 0080982D */  daddu     $s3, $a0, $zero
/* C001B8 80242938 AFBF0020 */  sw        $ra, 0x20($sp)
/* C001BC 8024293C AFB20018 */  sw        $s2, 0x18($sp)
/* C001C0 80242940 AFB10014 */  sw        $s1, 0x14($sp)
/* C001C4 80242944 AFB00010 */  sw        $s0, 0x10($sp)
/* C001C8 80242948 8E720148 */  lw        $s2, 0x148($s3)
/* C001CC 8024294C 86440008 */  lh        $a0, 8($s2)
/* C001D0 80242950 0C00EABB */  jal       get_npc_unsafe
/* C001D4 80242954 00A0882D */   daddu    $s1, $a1, $zero
/* C001D8 80242958 8E240008 */  lw        $a0, 8($s1)
/* C001DC 8024295C 0040802D */  daddu     $s0, $v0, $zero
/* C001E0 80242960 00041FC2 */  srl       $v1, $a0, 0x1f
/* C001E4 80242964 00832021 */  addu      $a0, $a0, $v1
/* C001E8 80242968 00042043 */  sra       $a0, $a0, 1
/* C001EC 8024296C 0C00A67F */  jal       rand_int
/* C001F0 80242970 24840001 */   addiu    $a0, $a0, 1
/* C001F4 80242974 8E230008 */  lw        $v1, 8($s1)
/* C001F8 80242978 240400B4 */  addiu     $a0, $zero, 0xb4
/* C001FC 8024297C 00032FC2 */  srl       $a1, $v1, 0x1f
/* C00200 80242980 00651821 */  addu      $v1, $v1, $a1
/* C00204 80242984 00031843 */  sra       $v1, $v1, 1
/* C00208 80242988 00621821 */  addu      $v1, $v1, $v0
/* C0020C 8024298C 0C00A67F */  jal       rand_int
/* C00210 80242990 A603008E */   sh       $v1, 0x8e($s0)
/* C00214 80242994 C60C000C */  lwc1      $f12, 0xc($s0)
/* C00218 80242998 44820000 */  mtc1      $v0, $f0
/* C0021C 8024299C 00000000 */  nop       
/* C00220 802429A0 46800020 */  cvt.s.w   $f0, $f0
/* C00224 802429A4 46006300 */  add.s     $f12, $f12, $f0
/* C00228 802429A8 3C0142B4 */  lui       $at, 0x42b4
/* C0022C 802429AC 44810000 */  mtc1      $at, $f0
/* C00230 802429B0 0C00A6C9 */  jal       clamp_angle
/* C00234 802429B4 46006301 */   sub.s    $f12, $f12, $f0
/* C00238 802429B8 E600000C */  swc1      $f0, 0xc($s0)
/* C0023C 802429BC 8E4200CC */  lw        $v0, 0xcc($s2)
/* C00240 802429C0 8C420000 */  lw        $v0, ($v0)
/* C00244 802429C4 AE020028 */  sw        $v0, 0x28($s0)
/* C00248 802429C8 24020003 */  addiu     $v0, $zero, 3
/* C0024C 802429CC AE620070 */  sw        $v0, 0x70($s3)
/* C00250 802429D0 8FBF0020 */  lw        $ra, 0x20($sp)
/* C00254 802429D4 8FB3001C */  lw        $s3, 0x1c($sp)
/* C00258 802429D8 8FB20018 */  lw        $s2, 0x18($sp)
/* C0025C 802429DC 8FB10014 */  lw        $s1, 0x14($sp)
/* C00260 802429E0 8FB00010 */  lw        $s0, 0x10($sp)
/* C00264 802429E4 03E00008 */  jr        $ra
/* C00268 802429E8 27BD0028 */   addiu    $sp, $sp, 0x28
