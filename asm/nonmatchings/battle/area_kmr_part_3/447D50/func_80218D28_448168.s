.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D28_448168
/* 448168 80218D28 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 44816C 80218D2C AFB40020 */  sw        $s4, 0x20($sp)
/* 448170 80218D30 0080A02D */  daddu     $s4, $a0, $zero
/* 448174 80218D34 AFBF0024 */  sw        $ra, 0x24($sp)
/* 448178 80218D38 AFB3001C */  sw        $s3, 0x1c($sp)
/* 44817C 80218D3C AFB20018 */  sw        $s2, 0x18($sp)
/* 448180 80218D40 AFB10014 */  sw        $s1, 0x14($sp)
/* 448184 80218D44 AFB00010 */  sw        $s0, 0x10($sp)
/* 448188 80218D48 8E92000C */  lw        $s2, 0xc($s4)
/* 44818C 80218D4C 8E450000 */  lw        $a1, ($s2)
/* 448190 80218D50 0C0B1EAF */  jal       get_variable
/* 448194 80218D54 26520004 */   addiu    $s2, $s2, 4
/* 448198 80218D58 8E450000 */  lw        $a1, ($s2)
/* 44819C 80218D5C 26520004 */  addiu     $s2, $s2, 4
/* 4481A0 80218D60 0280202D */  daddu     $a0, $s4, $zero
/* 4481A4 80218D64 0C0B1EAF */  jal       get_variable
/* 4481A8 80218D68 0040802D */   daddu    $s0, $v0, $zero
/* 4481AC 80218D6C 8E450000 */  lw        $a1, ($s2)
/* 4481B0 80218D70 26520004 */  addiu     $s2, $s2, 4
/* 4481B4 80218D74 0280202D */  daddu     $a0, $s4, $zero
/* 4481B8 80218D78 0C0B1EAF */  jal       get_variable
/* 4481BC 80218D7C 0040882D */   daddu    $s1, $v0, $zero
/* 4481C0 80218D80 0040982D */  daddu     $s3, $v0, $zero
/* 4481C4 80218D84 8E450000 */  lw        $a1, ($s2)
/* 4481C8 80218D88 26520004 */  addiu     $s2, $s2, 4
/* 4481CC 80218D8C 0280202D */  daddu     $a0, $s4, $zero
/* 4481D0 80218D90 0C0B1EAF */  jal       get_variable
/* 4481D4 80218D94 02709823 */   subu     $s3, $s3, $s0
/* 4481D8 80218D98 0040802D */  daddu     $s0, $v0, $zero
/* 4481DC 80218D9C 0280202D */  daddu     $a0, $s4, $zero
/* 4481E0 80218DA0 8E450000 */  lw        $a1, ($s2)
/* 4481E4 80218DA4 0C0B1EAF */  jal       get_variable
/* 4481E8 80218DA8 02118023 */   subu     $s0, $s0, $s1
/* 4481EC 80218DAC 16600006 */  bnez      $s3, .L80218DC8
/* 4481F0 80218DB0 00000000 */   nop      
/* 4481F4 80218DB4 16000004 */  bnez      $s0, .L80218DC8
/* 4481F8 80218DB8 0280202D */   daddu    $a0, $s4, $zero
/* 4481FC 80218DBC 8E450000 */  lw        $a1, ($s2)
/* 448200 80218DC0 0808637C */  j         .L80218DF0
/* 448204 80218DC4 0040302D */   daddu    $a2, $v0, $zero
.L80218DC8:
/* 448208 80218DC8 44936000 */  mtc1      $s3, $f12
/* 44820C 80218DCC 00000000 */  nop       
/* 448210 80218DD0 46806320 */  cvt.s.w   $f12, $f12
/* 448214 80218DD4 44907000 */  mtc1      $s0, $f14
/* 448218 80218DD8 00000000 */  nop       
/* 44821C 80218DDC 0C0862E7 */  jal       func_80218B9C_447FDC
/* 448220 80218DE0 468073A0 */   cvt.s.w  $f14, $f14
/* 448224 80218DE4 0280202D */  daddu     $a0, $s4, $zero
/* 448228 80218DE8 8E450000 */  lw        $a1, ($s2)
/* 44822C 80218DEC 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218DF0:
/* 448230 80218DF0 0C0B2026 */  jal       set_variable
/* 448234 80218DF4 00000000 */   nop      
/* 448238 80218DF8 24020002 */  addiu     $v0, $zero, 2
/* 44823C 80218DFC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 448240 80218E00 8FB40020 */  lw        $s4, 0x20($sp)
/* 448244 80218E04 8FB3001C */  lw        $s3, 0x1c($sp)
/* 448248 80218E08 8FB20018 */  lw        $s2, 0x18($sp)
/* 44824C 80218E0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 448250 80218E10 8FB00010 */  lw        $s0, 0x10($sp)
/* 448254 80218E14 03E00008 */  jr        $ra
/* 448258 80218E18 27BD0028 */   addiu    $sp, $sp, 0x28
