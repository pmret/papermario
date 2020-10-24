.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD0_C501E0
/* C501E0 80240CD0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C501E4 80240CD4 AFB3001C */  sw        $s3, 0x1c($sp)
/* C501E8 80240CD8 0080982D */  daddu     $s3, $a0, $zero
/* C501EC 80240CDC AFBF0020 */  sw        $ra, 0x20($sp)
/* C501F0 80240CE0 AFB20018 */  sw        $s2, 0x18($sp)
/* C501F4 80240CE4 AFB10014 */  sw        $s1, 0x14($sp)
/* C501F8 80240CE8 AFB00010 */  sw        $s0, 0x10($sp)
/* C501FC 80240CEC 8E720148 */  lw        $s2, 0x148($s3)
/* C50200 80240CF0 86440008 */  lh        $a0, 8($s2)
/* C50204 80240CF4 0C00EABB */  jal       get_npc_unsafe
/* C50208 80240CF8 00A0882D */   daddu    $s1, $a1, $zero
/* C5020C 80240CFC 8E240008 */  lw        $a0, 8($s1)
/* C50210 80240D00 0040802D */  daddu     $s0, $v0, $zero
/* C50214 80240D04 00041FC2 */  srl       $v1, $a0, 0x1f
/* C50218 80240D08 00832021 */  addu      $a0, $a0, $v1
/* C5021C 80240D0C 00042043 */  sra       $a0, $a0, 1
/* C50220 80240D10 0C00A67F */  jal       rand_int
/* C50224 80240D14 24840001 */   addiu    $a0, $a0, 1
/* C50228 80240D18 8E230008 */  lw        $v1, 8($s1)
/* C5022C 80240D1C 240400B4 */  addiu     $a0, $zero, 0xb4
/* C50230 80240D20 00032FC2 */  srl       $a1, $v1, 0x1f
/* C50234 80240D24 00651821 */  addu      $v1, $v1, $a1
/* C50238 80240D28 00031843 */  sra       $v1, $v1, 1
/* C5023C 80240D2C 00621821 */  addu      $v1, $v1, $v0
/* C50240 80240D30 0C00A67F */  jal       rand_int
/* C50244 80240D34 A603008E */   sh       $v1, 0x8e($s0)
/* C50248 80240D38 C60C000C */  lwc1      $f12, 0xc($s0)
/* C5024C 80240D3C 44820000 */  mtc1      $v0, $f0
/* C50250 80240D40 00000000 */  nop       
/* C50254 80240D44 46800020 */  cvt.s.w   $f0, $f0
/* C50258 80240D48 46006300 */  add.s     $f12, $f12, $f0
/* C5025C 80240D4C 3C0142B4 */  lui       $at, 0x42b4
/* C50260 80240D50 44810000 */  mtc1      $at, $f0
/* C50264 80240D54 0C00A6C9 */  jal       clamp_angle
/* C50268 80240D58 46006301 */   sub.s    $f12, $f12, $f0
/* C5026C 80240D5C E600000C */  swc1      $f0, 0xc($s0)
/* C50270 80240D60 8E4200CC */  lw        $v0, 0xcc($s2)
/* C50274 80240D64 8C420000 */  lw        $v0, ($v0)
/* C50278 80240D68 AE020028 */  sw        $v0, 0x28($s0)
/* C5027C 80240D6C 24020003 */  addiu     $v0, $zero, 3
/* C50280 80240D70 AE620070 */  sw        $v0, 0x70($s3)
/* C50284 80240D74 8FBF0020 */  lw        $ra, 0x20($sp)
/* C50288 80240D78 8FB3001C */  lw        $s3, 0x1c($sp)
/* C5028C 80240D7C 8FB20018 */  lw        $s2, 0x18($sp)
/* C50290 80240D80 8FB10014 */  lw        $s1, 0x14($sp)
/* C50294 80240D84 8FB00010 */  lw        $s0, 0x10($sp)
/* C50298 80240D88 03E00008 */  jr        $ra
/* C5029C 80240D8C 27BD0028 */   addiu    $sp, $sp, 0x28
