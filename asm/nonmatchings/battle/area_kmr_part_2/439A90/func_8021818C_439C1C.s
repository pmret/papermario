.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021818C_439C1C
/* 439C1C 8021818C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 439C20 80218190 AFB40020 */  sw        $s4, 0x20($sp)
/* 439C24 80218194 0080A02D */  daddu     $s4, $a0, $zero
/* 439C28 80218198 AFBF0024 */  sw        $ra, 0x24($sp)
/* 439C2C 8021819C AFB3001C */  sw        $s3, 0x1c($sp)
/* 439C30 802181A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 439C34 802181A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 439C38 802181A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 439C3C 802181AC 8E92000C */  lw        $s2, 0xc($s4)
/* 439C40 802181B0 8E450000 */  lw        $a1, ($s2)
/* 439C44 802181B4 0C0B1EAF */  jal       get_variable
/* 439C48 802181B8 26520004 */   addiu    $s2, $s2, 4
/* 439C4C 802181BC 8E450000 */  lw        $a1, ($s2)
/* 439C50 802181C0 26520004 */  addiu     $s2, $s2, 4
/* 439C54 802181C4 0280202D */  daddu     $a0, $s4, $zero
/* 439C58 802181C8 0C0B1EAF */  jal       get_variable
/* 439C5C 802181CC 0040802D */   daddu    $s0, $v0, $zero
/* 439C60 802181D0 8E450000 */  lw        $a1, ($s2)
/* 439C64 802181D4 26520004 */  addiu     $s2, $s2, 4
/* 439C68 802181D8 0280202D */  daddu     $a0, $s4, $zero
/* 439C6C 802181DC 0C0B1EAF */  jal       get_variable
/* 439C70 802181E0 0040882D */   daddu    $s1, $v0, $zero
/* 439C74 802181E4 0040982D */  daddu     $s3, $v0, $zero
/* 439C78 802181E8 8E450000 */  lw        $a1, ($s2)
/* 439C7C 802181EC 26520004 */  addiu     $s2, $s2, 4
/* 439C80 802181F0 0280202D */  daddu     $a0, $s4, $zero
/* 439C84 802181F4 0C0B1EAF */  jal       get_variable
/* 439C88 802181F8 02709823 */   subu     $s3, $s3, $s0
/* 439C8C 802181FC 0040802D */  daddu     $s0, $v0, $zero
/* 439C90 80218200 0280202D */  daddu     $a0, $s4, $zero
/* 439C94 80218204 8E450000 */  lw        $a1, ($s2)
/* 439C98 80218208 0C0B1EAF */  jal       get_variable
/* 439C9C 8021820C 02118023 */   subu     $s0, $s0, $s1
/* 439CA0 80218210 16600006 */  bnez      $s3, .L8021822C
/* 439CA4 80218214 00000000 */   nop      
/* 439CA8 80218218 16000004 */  bnez      $s0, .L8021822C
/* 439CAC 8021821C 0280202D */   daddu    $a0, $s4, $zero
/* 439CB0 80218220 8E450000 */  lw        $a1, ($s2)
/* 439CB4 80218224 08086095 */  j         .L80218254
/* 439CB8 80218228 0040302D */   daddu    $a2, $v0, $zero
.L8021822C:
/* 439CBC 8021822C 44936000 */  mtc1      $s3, $f12
/* 439CC0 80218230 00000000 */  nop       
/* 439CC4 80218234 46806320 */  cvt.s.w   $f12, $f12
/* 439CC8 80218238 44907000 */  mtc1      $s0, $f14
/* 439CCC 8021823C 00000000 */  nop       
/* 439CD0 80218240 0C086000 */  jal       func_80218000_439A90
/* 439CD4 80218244 468073A0 */   cvt.s.w  $f14, $f14
/* 439CD8 80218248 0280202D */  daddu     $a0, $s4, $zero
/* 439CDC 8021824C 8E450000 */  lw        $a1, ($s2)
/* 439CE0 80218250 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218254:
/* 439CE4 80218254 0C0B2026 */  jal       set_variable
/* 439CE8 80218258 00000000 */   nop      
/* 439CEC 8021825C 24020002 */  addiu     $v0, $zero, 2
/* 439CF0 80218260 8FBF0024 */  lw        $ra, 0x24($sp)
/* 439CF4 80218264 8FB40020 */  lw        $s4, 0x20($sp)
/* 439CF8 80218268 8FB3001C */  lw        $s3, 0x1c($sp)
/* 439CFC 8021826C 8FB20018 */  lw        $s2, 0x18($sp)
/* 439D00 80218270 8FB10014 */  lw        $s1, 0x14($sp)
/* 439D04 80218274 8FB00010 */  lw        $s0, 0x10($sp)
/* 439D08 80218278 03E00008 */  jr        $ra
/* 439D0C 8021827C 27BD0028 */   addiu    $sp, $sp, 0x28
