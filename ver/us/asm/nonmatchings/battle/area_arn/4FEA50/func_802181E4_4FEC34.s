.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802181E4_4FEC34
/* 4FEC34 802181E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4FEC38 802181E8 AFB40020 */  sw        $s4, 0x20($sp)
/* 4FEC3C 802181EC 0080A02D */  daddu     $s4, $a0, $zero
/* 4FEC40 802181F0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4FEC44 802181F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4FEC48 802181F8 AFB20018 */  sw        $s2, 0x18($sp)
/* 4FEC4C 802181FC AFB10014 */  sw        $s1, 0x14($sp)
/* 4FEC50 80218200 AFB00010 */  sw        $s0, 0x10($sp)
/* 4FEC54 80218204 8E92000C */  lw        $s2, 0xc($s4)
/* 4FEC58 80218208 8E450000 */  lw        $a1, ($s2)
/* 4FEC5C 8021820C 0C0B1EAF */  jal       get_variable
/* 4FEC60 80218210 26520004 */   addiu    $s2, $s2, 4
/* 4FEC64 80218214 8E450000 */  lw        $a1, ($s2)
/* 4FEC68 80218218 26520004 */  addiu     $s2, $s2, 4
/* 4FEC6C 8021821C 0280202D */  daddu     $a0, $s4, $zero
/* 4FEC70 80218220 0C0B1EAF */  jal       get_variable
/* 4FEC74 80218224 0040802D */   daddu    $s0, $v0, $zero
/* 4FEC78 80218228 8E450000 */  lw        $a1, ($s2)
/* 4FEC7C 8021822C 26520004 */  addiu     $s2, $s2, 4
/* 4FEC80 80218230 0280202D */  daddu     $a0, $s4, $zero
/* 4FEC84 80218234 0C0B1EAF */  jal       get_variable
/* 4FEC88 80218238 0040882D */   daddu    $s1, $v0, $zero
/* 4FEC8C 8021823C 0040982D */  daddu     $s3, $v0, $zero
/* 4FEC90 80218240 8E450000 */  lw        $a1, ($s2)
/* 4FEC94 80218244 26520004 */  addiu     $s2, $s2, 4
/* 4FEC98 80218248 0280202D */  daddu     $a0, $s4, $zero
/* 4FEC9C 8021824C 0C0B1EAF */  jal       get_variable
/* 4FECA0 80218250 02709823 */   subu     $s3, $s3, $s0
/* 4FECA4 80218254 0040802D */  daddu     $s0, $v0, $zero
/* 4FECA8 80218258 0280202D */  daddu     $a0, $s4, $zero
/* 4FECAC 8021825C 8E450000 */  lw        $a1, ($s2)
/* 4FECB0 80218260 0C0B1EAF */  jal       get_variable
/* 4FECB4 80218264 02118023 */   subu     $s0, $s0, $s1
/* 4FECB8 80218268 16600006 */  bnez      $s3, .L80218284
/* 4FECBC 8021826C 00000000 */   nop
/* 4FECC0 80218270 16000004 */  bnez      $s0, .L80218284
/* 4FECC4 80218274 0280202D */   daddu    $a0, $s4, $zero
/* 4FECC8 80218278 8E450000 */  lw        $a1, ($s2)
/* 4FECCC 8021827C 080860AB */  j         .L802182AC
/* 4FECD0 80218280 0040302D */   daddu    $a2, $v0, $zero
.L80218284:
/* 4FECD4 80218284 44936000 */  mtc1      $s3, $f12
/* 4FECD8 80218288 00000000 */  nop
/* 4FECDC 8021828C 46806320 */  cvt.s.w   $f12, $f12
/* 4FECE0 80218290 44907000 */  mtc1      $s0, $f14
/* 4FECE4 80218294 00000000 */  nop
/* 4FECE8 80218298 0C086016 */  jal       func_80218058_4FEAA8
/* 4FECEC 8021829C 468073A0 */   cvt.s.w  $f14, $f14
/* 4FECF0 802182A0 0280202D */  daddu     $a0, $s4, $zero
/* 4FECF4 802182A4 8E450000 */  lw        $a1, ($s2)
/* 4FECF8 802182A8 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L802182AC:
/* 4FECFC 802182AC 0C0B2026 */  jal       set_variable
/* 4FED00 802182B0 00000000 */   nop
/* 4FED04 802182B4 24020002 */  addiu     $v0, $zero, 2
/* 4FED08 802182B8 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4FED0C 802182BC 8FB40020 */  lw        $s4, 0x20($sp)
/* 4FED10 802182C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4FED14 802182C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 4FED18 802182C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 4FED1C 802182CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 4FED20 802182D0 03E00008 */  jr        $ra
/* 4FED24 802182D4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4FED28 802182D8 00000000 */  nop
/* 4FED2C 802182DC 00000000 */  nop
