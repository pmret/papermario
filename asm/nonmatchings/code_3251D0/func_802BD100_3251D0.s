.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_3251D0
/* 3251D0 802BD100 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3251D4 802BD104 AFB1001C */  sw        $s1, 0x1c($sp)
/* 3251D8 802BD108 0080882D */  daddu     $s1, $a0, $zero
/* 3251DC 802BD10C AFBF0024 */  sw        $ra, 0x24($sp)
/* 3251E0 802BD110 AFB20020 */  sw        $s2, 0x20($sp)
/* 3251E4 802BD114 AFB00018 */  sw        $s0, 0x18($sp)
/* 3251E8 802BD118 8E30000C */  lw        $s0, 0xc($s1)
/* 3251EC 802BD11C 8E050000 */  lw        $a1, ($s0)
/* 3251F0 802BD120 0C0B1EAF */  jal       get_variable
/* 3251F4 802BD124 26100004 */   addiu    $s0, $s0, 4
/* 3251F8 802BD128 8E050000 */  lw        $a1, ($s0)
/* 3251FC 802BD12C 26100004 */  addiu     $s0, $s0, 4
/* 325200 802BD130 0220202D */  daddu     $a0, $s1, $zero
/* 325204 802BD134 0C0B1EAF */  jal       get_variable
/* 325208 802BD138 0040902D */   daddu    $s2, $v0, $zero
/* 32520C 802BD13C 0220202D */  daddu     $a0, $s1, $zero
/* 325210 802BD140 8E050000 */  lw        $a1, ($s0)
/* 325214 802BD144 0C0B1EAF */  jal       get_variable
/* 325218 802BD148 0040802D */   daddu    $s0, $v0, $zero
/* 32521C 802BD14C 44921000 */  mtc1      $s2, $f2
/* 325220 802BD150 00000000 */  nop       
/* 325224 802BD154 468010A0 */  cvt.s.w   $f2, $f2
/* 325228 802BD158 44051000 */  mfc1      $a1, $f2
/* 32522C 802BD15C 44901000 */  mtc1      $s0, $f2
/* 325230 802BD160 00000000 */  nop       
/* 325234 802BD164 468010A0 */  cvt.s.w   $f2, $f2
/* 325238 802BD168 44061000 */  mfc1      $a2, $f2
/* 32523C 802BD16C 44821000 */  mtc1      $v0, $f2
/* 325240 802BD170 00000000 */  nop       
/* 325244 802BD174 468010A0 */  cvt.s.w   $f2, $f2
/* 325248 802BD178 3C014270 */  lui       $at, 0x4270
/* 32524C 802BD17C 44810000 */  mtc1      $at, $f0
/* 325250 802BD180 44071000 */  mfc1      $a3, $f2
/* 325254 802BD184 0000202D */  daddu     $a0, $zero, $zero
/* 325258 802BD188 0C01BFBC */  jal       func_8006FEF0
/* 32525C 802BD18C E7A00010 */   swc1     $f0, 0x10($sp)
/* 325260 802BD190 8FBF0024 */  lw        $ra, 0x24($sp)
/* 325264 802BD194 8FB20020 */  lw        $s2, 0x20($sp)
/* 325268 802BD198 8FB1001C */  lw        $s1, 0x1c($sp)
/* 32526C 802BD19C 8FB00018 */  lw        $s0, 0x18($sp)
/* 325270 802BD1A0 24020002 */  addiu     $v0, $zero, 2
/* 325274 802BD1A4 03E00008 */  jr        $ra
/* 325278 802BD1A8 27BD0028 */   addiu    $sp, $sp, 0x28
