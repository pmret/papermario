.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024247C_BA6BFC
/* BA6BFC 8024247C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BA6C00 80242480 AFB3001C */  sw        $s3, 0x1c($sp)
/* BA6C04 80242484 0080982D */  daddu     $s3, $a0, $zero
/* BA6C08 80242488 AFBF0020 */  sw        $ra, 0x20($sp)
/* BA6C0C 8024248C AFB20018 */  sw        $s2, 0x18($sp)
/* BA6C10 80242490 AFB10014 */  sw        $s1, 0x14($sp)
/* BA6C14 80242494 AFB00010 */  sw        $s0, 0x10($sp)
/* BA6C18 80242498 8E720148 */  lw        $s2, 0x148($s3)
/* BA6C1C 8024249C 86440008 */  lh        $a0, 8($s2)
/* BA6C20 802424A0 0C00EABB */  jal       get_npc_unsafe
/* BA6C24 802424A4 00A0882D */   daddu    $s1, $a1, $zero
/* BA6C28 802424A8 8E240008 */  lw        $a0, 8($s1)
/* BA6C2C 802424AC 0040802D */  daddu     $s0, $v0, $zero
/* BA6C30 802424B0 00041FC2 */  srl       $v1, $a0, 0x1f
/* BA6C34 802424B4 00832021 */  addu      $a0, $a0, $v1
/* BA6C38 802424B8 00042043 */  sra       $a0, $a0, 1
/* BA6C3C 802424BC 0C00A67F */  jal       rand_int
/* BA6C40 802424C0 24840001 */   addiu    $a0, $a0, 1
/* BA6C44 802424C4 8E230008 */  lw        $v1, 8($s1)
/* BA6C48 802424C8 240400B4 */  addiu     $a0, $zero, 0xb4
/* BA6C4C 802424CC 00032FC2 */  srl       $a1, $v1, 0x1f
/* BA6C50 802424D0 00651821 */  addu      $v1, $v1, $a1
/* BA6C54 802424D4 00031843 */  sra       $v1, $v1, 1
/* BA6C58 802424D8 00621821 */  addu      $v1, $v1, $v0
/* BA6C5C 802424DC 0C00A67F */  jal       rand_int
/* BA6C60 802424E0 A603008E */   sh       $v1, 0x8e($s0)
/* BA6C64 802424E4 C60C000C */  lwc1      $f12, 0xc($s0)
/* BA6C68 802424E8 44820000 */  mtc1      $v0, $f0
/* BA6C6C 802424EC 00000000 */  nop       
/* BA6C70 802424F0 46800020 */  cvt.s.w   $f0, $f0
/* BA6C74 802424F4 46006300 */  add.s     $f12, $f12, $f0
/* BA6C78 802424F8 3C0142B4 */  lui       $at, 0x42b4
/* BA6C7C 802424FC 44810000 */  mtc1      $at, $f0
/* BA6C80 80242500 0C00A6C9 */  jal       clamp_angle
/* BA6C84 80242504 46006301 */   sub.s    $f12, $f12, $f0
/* BA6C88 80242508 E600000C */  swc1      $f0, 0xc($s0)
/* BA6C8C 8024250C 8E4200CC */  lw        $v0, 0xcc($s2)
/* BA6C90 80242510 8C420000 */  lw        $v0, ($v0)
/* BA6C94 80242514 AE020028 */  sw        $v0, 0x28($s0)
/* BA6C98 80242518 24020003 */  addiu     $v0, $zero, 3
/* BA6C9C 8024251C AE620070 */  sw        $v0, 0x70($s3)
/* BA6CA0 80242520 8FBF0020 */  lw        $ra, 0x20($sp)
/* BA6CA4 80242524 8FB3001C */  lw        $s3, 0x1c($sp)
/* BA6CA8 80242528 8FB20018 */  lw        $s2, 0x18($sp)
/* BA6CAC 8024252C 8FB10014 */  lw        $s1, 0x14($sp)
/* BA6CB0 80242530 8FB00010 */  lw        $s0, 0x10($sp)
/* BA6CB4 80242534 03E00008 */  jr        $ra
/* BA6CB8 80242538 27BD0028 */   addiu    $sp, $sp, 0x28
