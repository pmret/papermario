.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021818C_430B2C
/* 430B2C 8021818C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 430B30 80218190 AFB40020 */  sw        $s4, 0x20($sp)
/* 430B34 80218194 0080A02D */  daddu     $s4, $a0, $zero
/* 430B38 80218198 AFBF0024 */  sw        $ra, 0x24($sp)
/* 430B3C 8021819C AFB3001C */  sw        $s3, 0x1c($sp)
/* 430B40 802181A0 AFB20018 */  sw        $s2, 0x18($sp)
/* 430B44 802181A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 430B48 802181A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 430B4C 802181AC 8E92000C */  lw        $s2, 0xc($s4)
/* 430B50 802181B0 8E450000 */  lw        $a1, ($s2)
/* 430B54 802181B4 0C0B1EAF */  jal       get_variable
/* 430B58 802181B8 26520004 */   addiu    $s2, $s2, 4
/* 430B5C 802181BC 8E450000 */  lw        $a1, ($s2)
/* 430B60 802181C0 26520004 */  addiu     $s2, $s2, 4
/* 430B64 802181C4 0280202D */  daddu     $a0, $s4, $zero
/* 430B68 802181C8 0C0B1EAF */  jal       get_variable
/* 430B6C 802181CC 0040802D */   daddu    $s0, $v0, $zero
/* 430B70 802181D0 8E450000 */  lw        $a1, ($s2)
/* 430B74 802181D4 26520004 */  addiu     $s2, $s2, 4
/* 430B78 802181D8 0280202D */  daddu     $a0, $s4, $zero
/* 430B7C 802181DC 0C0B1EAF */  jal       get_variable
/* 430B80 802181E0 0040882D */   daddu    $s1, $v0, $zero
/* 430B84 802181E4 0040982D */  daddu     $s3, $v0, $zero
/* 430B88 802181E8 8E450000 */  lw        $a1, ($s2)
/* 430B8C 802181EC 26520004 */  addiu     $s2, $s2, 4
/* 430B90 802181F0 0280202D */  daddu     $a0, $s4, $zero
/* 430B94 802181F4 0C0B1EAF */  jal       get_variable
/* 430B98 802181F8 02709823 */   subu     $s3, $s3, $s0
/* 430B9C 802181FC 0040802D */  daddu     $s0, $v0, $zero
/* 430BA0 80218200 0280202D */  daddu     $a0, $s4, $zero
/* 430BA4 80218204 8E450000 */  lw        $a1, ($s2)
/* 430BA8 80218208 0C0B1EAF */  jal       get_variable
/* 430BAC 8021820C 02118023 */   subu     $s0, $s0, $s1
/* 430BB0 80218210 16600006 */  bnez      $s3, .L8021822C
/* 430BB4 80218214 00000000 */   nop
/* 430BB8 80218218 16000004 */  bnez      $s0, .L8021822C
/* 430BBC 8021821C 0280202D */   daddu    $a0, $s4, $zero
/* 430BC0 80218220 8E450000 */  lw        $a1, ($s2)
/* 430BC4 80218224 08086095 */  j         .L80218254
/* 430BC8 80218228 0040302D */   daddu    $a2, $v0, $zero
.L8021822C:
/* 430BCC 8021822C 44936000 */  mtc1      $s3, $f12
/* 430BD0 80218230 00000000 */  nop
/* 430BD4 80218234 46806320 */  cvt.s.w   $f12, $f12
/* 430BD8 80218238 44907000 */  mtc1      $s0, $f14
/* 430BDC 8021823C 00000000 */  nop
/* 430BE0 80218240 0C086000 */  jal       func_80218000_4309A0
/* 430BE4 80218244 468073A0 */   cvt.s.w  $f14, $f14
/* 430BE8 80218248 0280202D */  daddu     $a0, $s4, $zero
/* 430BEC 8021824C 8E450000 */  lw        $a1, ($s2)
/* 430BF0 80218250 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L80218254:
/* 430BF4 80218254 0C0B2026 */  jal       set_variable
/* 430BF8 80218258 00000000 */   nop
/* 430BFC 8021825C 24020002 */  addiu     $v0, $zero, 2
/* 430C00 80218260 8FBF0024 */  lw        $ra, 0x24($sp)
/* 430C04 80218264 8FB40020 */  lw        $s4, 0x20($sp)
/* 430C08 80218268 8FB3001C */  lw        $s3, 0x1c($sp)
/* 430C0C 8021826C 8FB20018 */  lw        $s2, 0x18($sp)
/* 430C10 80218270 8FB10014 */  lw        $s1, 0x14($sp)
/* 430C14 80218274 8FB00010 */  lw        $s0, 0x10($sp)
/* 430C18 80218278 03E00008 */  jr        $ra
/* 430C1C 8021827C 27BD0028 */   addiu    $sp, $sp, 0x28
