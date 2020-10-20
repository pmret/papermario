.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF8_BCFAE8
/* BCFAE8 80240EF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BCFAEC 80240EFC AFB10014 */  sw        $s1, 0x14($sp)
/* BCFAF0 80240F00 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCFAF4 80240F04 AFB00010 */  sw        $s0, 0x10($sp)
/* BCFAF8 80240F08 F7B40020 */  sdc1      $f20, 0x20($sp)
/* BCFAFC 80240F0C 0C090150 */  jal       func_80240540
/* BCFB00 80240F10 0080882D */   daddu    $s1, $a0, $zero
/* BCFB04 80240F14 3C041062 */  lui       $a0, 0x1062
/* BCFB08 80240F18 8E230084 */  lw        $v1, 0x84($s1)
/* BCFB0C 80240F1C 34844DD3 */  ori       $a0, $a0, 0x4dd3
/* BCFB10 80240F20 00640018 */  mult      $v1, $a0
/* BCFB14 80240F24 3C0551EB */  lui       $a1, 0x51eb
/* BCFB18 80240F28 34A5851F */  ori       $a1, $a1, 0x851f
/* BCFB1C 80240F2C 00031FC3 */  sra       $v1, $v1, 0x1f
/* BCFB20 80240F30 00003010 */  mfhi      $a2
/* BCFB24 80240F34 00062183 */  sra       $a0, $a2, 6
/* BCFB28 80240F38 00831823 */  subu      $v1, $a0, $v1
/* BCFB2C 80240F3C 00032040 */  sll       $a0, $v1, 1
/* BCFB30 80240F40 00832021 */  addu      $a0, $a0, $v1
/* BCFB34 80240F44 00041900 */  sll       $v1, $a0, 4
/* BCFB38 80240F48 00641823 */  subu      $v1, $v1, $a0
/* BCFB3C 80240F4C 00031840 */  sll       $v1, $v1, 1
/* BCFB40 80240F50 00650018 */  mult      $v1, $a1
/* BCFB44 80240F54 3C0140C9 */  lui       $at, 0x40c9
/* BCFB48 80240F58 34210FD0 */  ori       $at, $at, 0xfd0
/* BCFB4C 80240F5C 44810000 */  mtc1      $at, $f0
/* BCFB50 80240F60 00031FC3 */  sra       $v1, $v1, 0x1f
/* BCFB54 80240F64 00003010 */  mfhi      $a2
/* BCFB58 80240F68 00062103 */  sra       $a0, $a2, 4
/* BCFB5C 80240F6C 00832023 */  subu      $a0, $a0, $v1
/* BCFB60 80240F70 44846000 */  mtc1      $a0, $f12
/* BCFB64 80240F74 00000000 */  nop       
/* BCFB68 80240F78 46806320 */  cvt.s.w   $f12, $f12
/* BCFB6C 80240F7C 46006302 */  mul.s     $f12, $f12, $f0
/* BCFB70 80240F80 00000000 */  nop       
/* BCFB74 80240F84 3C0143B4 */  lui       $at, 0x43b4
/* BCFB78 80240F88 44810000 */  mtc1      $at, $f0
/* BCFB7C 80240F8C 0040802D */  daddu     $s0, $v0, $zero
/* BCFB80 80240F90 0C00A85B */  jal       sin_rad
/* BCFB84 80240F94 46006303 */   div.s    $f12, $f12, $f0
/* BCFB88 80240F98 3C014248 */  lui       $at, 0x4248
/* BCFB8C 80240F9C 44811000 */  mtc1      $at, $f2
/* BCFB90 80240FA0 00000000 */  nop       
/* BCFB94 80240FA4 46020002 */  mul.s     $f0, $f0, $f2
/* BCFB98 80240FA8 00000000 */  nop       
/* BCFB9C 80240FAC 24020064 */  addiu     $v0, $zero, 0x64
/* BCFBA0 80240FB0 3C013FD0 */  lui       $at, 0x3fd0
/* BCFBA4 80240FB4 44811800 */  mtc1      $at, $f3
/* BCFBA8 80240FB8 44801000 */  mtc1      $zero, $f2
/* BCFBAC 80240FBC 4600018D */  trunc.w.s $f6, $f0
/* BCFBB0 80240FC0 44033000 */  mfc1      $v1, $f6
/* BCFBB4 80240FC4 00000000 */  nop       
/* BCFBB8 80240FC8 00431023 */  subu      $v0, $v0, $v1
/* BCFBBC 80240FCC 44820000 */  mtc1      $v0, $f0
/* BCFBC0 80240FD0 00000000 */  nop       
/* BCFBC4 80240FD4 46800021 */  cvt.d.w   $f0, $f0
/* BCFBC8 80240FD8 46220002 */  mul.d     $f0, $f0, $f2
/* BCFBCC 80240FDC 00000000 */  nop       
/* BCFBD0 80240FE0 44831000 */  mtc1      $v1, $f2
/* BCFBD4 80240FE4 00000000 */  nop       
/* BCFBD8 80240FE8 468010A1 */  cvt.d.w   $f2, $f2
/* BCFBDC 80240FEC 46221080 */  add.d     $f2, $f2, $f2
/* BCFBE0 80240FF0 3C014059 */  lui       $at, 0x4059
/* BCFBE4 80240FF4 44812800 */  mtc1      $at, $f5
/* BCFBE8 80240FF8 44802000 */  mtc1      $zero, $f4
/* BCFBEC 80240FFC 00000000 */  nop       
/* BCFBF0 80241000 46241083 */  div.d     $f2, $f2, $f4
/* BCFBF4 80241004 46240003 */  div.d     $f0, $f0, $f4
/* BCFBF8 80241008 46220000 */  add.d     $f0, $f0, $f2
/* BCFBFC 8024100C 8E04000C */  lw        $a0, 0xc($s0)
/* BCFC00 80241010 46200020 */  cvt.s.d   $f0, $f0
/* BCFC04 80241014 44050000 */  mfc1      $a1, $f0
/* BCFC08 80241018 0C01574E */  jal       func_80055D38
/* BCFC0C 8024101C AE0501C4 */   sw       $a1, 0x1c4($s0)
/* BCFC10 80241020 8E04004C */  lw        $a0, 0x4c($s0)
/* BCFC14 80241024 0C0B11EA */  jal       get_script_by_id
/* BCFC18 80241028 00000000 */   nop      
/* BCFC1C 8024102C C60201C4 */  lwc1      $f2, 0x1c4($s0)
/* BCFC20 80241030 3C014040 */  lui       $at, 0x4040
/* BCFC24 80241034 44810000 */  mtc1      $at, $f0
/* BCFC28 80241038 00000000 */  nop       
/* BCFC2C 8024103C 46001082 */  mul.s     $f2, $f2, $f0
/* BCFC30 80241040 00000000 */  nop       
/* BCFC34 80241044 44051000 */  mfc1      $a1, $f2
/* BCFC38 80241048 0C0B1078 */  jal       set_script_timescale
/* BCFC3C 8024104C 0220202D */   daddu    $a0, $s1, $zero
/* BCFC40 80241050 8E040050 */  lw        $a0, 0x50($s0)
/* BCFC44 80241054 0C0B11EA */  jal       get_script_by_id
/* BCFC48 80241058 00000000 */   nop      
/* BCFC4C 8024105C C60001C4 */  lwc1      $f0, 0x1c4($s0)
/* BCFC50 80241060 3C0140A0 */  lui       $at, 0x40a0
/* BCFC54 80241064 4481A000 */  mtc1      $at, $f20
/* BCFC58 80241068 00000000 */  nop       
/* BCFC5C 8024106C 46140002 */  mul.s     $f0, $f0, $f20
/* BCFC60 80241070 00000000 */  nop       
/* BCFC64 80241074 44050000 */  mfc1      $a1, $f0
/* BCFC68 80241078 0C0B1078 */  jal       set_script_timescale
/* BCFC6C 8024107C 0220202D */   daddu    $a0, $s1, $zero
/* BCFC70 80241080 8E040054 */  lw        $a0, 0x54($s0)
/* BCFC74 80241084 0C0B11EA */  jal       get_script_by_id
/* BCFC78 80241088 00000000 */   nop      
/* BCFC7C 8024108C C60001C4 */  lwc1      $f0, 0x1c4($s0)
/* BCFC80 80241090 46140002 */  mul.s     $f0, $f0, $f20
/* BCFC84 80241094 00000000 */  nop       
/* BCFC88 80241098 44050000 */  mfc1      $a1, $f0
/* BCFC8C 8024109C 0C0B1078 */  jal       set_script_timescale
/* BCFC90 802410A0 0220202D */   daddu    $a0, $s1, $zero
/* BCFC94 802410A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCFC98 802410A8 8FB10014 */  lw        $s1, 0x14($sp)
/* BCFC9C 802410AC 8FB00010 */  lw        $s0, 0x10($sp)
/* BCFCA0 802410B0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* BCFCA4 802410B4 24020002 */  addiu     $v0, $zero, 2
/* BCFCA8 802410B8 03E00008 */  jr        $ra
/* BCFCAC 802410BC 27BD0028 */   addiu    $sp, $sp, 0x28
