.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_4F7BE0
/* 4F7BE0 80218000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4F7BE4 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7BE8 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 4F7BEC 8021800C AFBF0020 */  sw        $ra, 0x20($sp)
/* 4F7BF0 80218010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7BF4 80218014 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7BF8 80218018 AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7BFC 8021801C 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7C00 80218020 8E050000 */  lw        $a1, ($s0)
/* 4F7C04 80218024 0C0B1EAF */  jal       get_variable
/* 4F7C08 80218028 26100004 */   addiu    $s0, $s0, 4
/* 4F7C0C 8021802C 8E050000 */  lw        $a1, ($s0)
/* 4F7C10 80218030 26100004 */  addiu     $s0, $s0, 4
/* 4F7C14 80218034 0220202D */  daddu     $a0, $s1, $zero
/* 4F7C18 80218038 0C0B1EAF */  jal       get_variable
/* 4F7C1C 8021803C 0040982D */   daddu    $s3, $v0, $zero
/* 4F7C20 80218040 8E050000 */  lw        $a1, ($s0)
/* 4F7C24 80218044 26100004 */  addiu     $s0, $s0, 4
/* 4F7C28 80218048 0220202D */  daddu     $a0, $s1, $zero
/* 4F7C2C 8021804C 0C0B1EAF */  jal       get_variable
/* 4F7C30 80218050 0040902D */   daddu    $s2, $v0, $zero
/* 4F7C34 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 4F7C38 80218058 8E050000 */  lw        $a1, ($s0)
/* 4F7C3C 8021805C 0C0B1EAF */  jal       get_variable
/* 4F7C40 80218060 0040802D */   daddu    $s0, $v0, $zero
/* 4F7C44 80218064 44936000 */  mtc1      $s3, $f12
/* 4F7C48 80218068 00000000 */  nop       
/* 4F7C4C 8021806C 46806320 */  cvt.s.w   $f12, $f12
/* 4F7C50 80218070 44927000 */  mtc1      $s2, $f14
/* 4F7C54 80218074 00000000 */  nop       
/* 4F7C58 80218078 468073A0 */  cvt.s.w   $f14, $f14
/* 4F7C5C 8021807C 44900000 */  mtc1      $s0, $f0
/* 4F7C60 80218080 00000000 */  nop       
/* 4F7C64 80218084 46800020 */  cvt.s.w   $f0, $f0
/* 4F7C68 80218088 44060000 */  mfc1      $a2, $f0
/* 4F7C6C 8021808C 0C0B5D18 */  jal       func_802D7460
/* 4F7C70 80218090 0040382D */   daddu    $a3, $v0, $zero
/* 4F7C74 80218094 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4F7C78 80218098 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7C7C 8021809C 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7C80 802180A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7C84 802180A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7C88 802180A8 24020002 */  addiu     $v0, $zero, 2
/* 4F7C8C 802180AC 03E00008 */  jr        $ra
/* 4F7C90 802180B0 27BD0028 */   addiu    $sp, $sp, 0x28
