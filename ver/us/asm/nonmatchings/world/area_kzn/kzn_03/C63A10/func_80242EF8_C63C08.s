.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_draw_begin_partner_turn_C63C08
/* C63C08 80242EF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C63C0C 80242EFC AFB10014 */  sw        $s1, 0x14($sp)
/* C63C10 80242F00 0080882D */  daddu     $s1, $a0, $zero
/* C63C14 80242F04 AFBF001C */  sw        $ra, 0x1c($sp)
/* C63C18 80242F08 AFB20018 */  sw        $s2, 0x18($sp)
/* C63C1C 80242F0C AFB00010 */  sw        $s0, 0x10($sp)
/* C63C20 80242F10 8E22000C */  lw        $v0, 0xc($s1)
/* C63C24 80242F14 0C0B1EAF */  jal       get_variable
/* C63C28 80242F18 8C450000 */   lw       $a1, ($v0)
/* C63C2C 80242F1C 8E23013C */  lw        $v1, 0x13c($s1)
/* C63C30 80242F20 8C720000 */  lw        $s2, ($v1)
/* C63C34 80242F24 C646000C */  lwc1      $f6, 0xc($s2)
/* C63C38 80242F28 C6400000 */  lwc1      $f0, ($s2)
/* C63C3C 80242F2C 46003181 */  sub.s     $f6, $f6, $f0
/* C63C40 80242F30 3C01447A */  lui       $at, 0x447a
/* C63C44 80242F34 44814000 */  mtc1      $at, $f8
/* C63C48 80242F38 C6200084 */  lwc1      $f0, 0x84($s1)
/* C63C4C 80242F3C 46800020 */  cvt.s.w   $f0, $f0
/* C63C50 80242F40 46083183 */  div.s     $f6, $f6, $f8
/* C63C54 80242F44 46003182 */  mul.s     $f6, $f6, $f0
/* C63C58 80242F48 00000000 */  nop
/* C63C5C 80242F4C C6440010 */  lwc1      $f4, 0x10($s2)
/* C63C60 80242F50 C6420004 */  lwc1      $f2, 4($s2)
/* C63C64 80242F54 46022101 */  sub.s     $f4, $f4, $f2
/* C63C68 80242F58 C6420008 */  lwc1      $f2, 8($s2)
/* C63C6C 80242F5C C6400014 */  lwc1      $f0, 0x14($s2)
/* C63C70 80242F60 46020001 */  sub.s     $f0, $f0, $f2
/* C63C74 80242F64 46082103 */  div.s     $f4, $f4, $f8
/* C63C78 80242F68 C6220084 */  lwc1      $f2, 0x84($s1)
/* C63C7C 80242F6C 468010A0 */  cvt.s.w   $f2, $f2
/* C63C80 80242F70 46022102 */  mul.s     $f4, $f4, $f2
/* C63C84 80242F74 00000000 */  nop
/* C63C88 80242F78 46080003 */  div.s     $f0, $f0, $f8
/* C63C8C 80242F7C 46020002 */  mul.s     $f0, $f0, $f2
/* C63C90 80242F80 00000000 */  nop
/* C63C94 80242F84 4600328D */  trunc.w.s $f10, $f6
/* C63C98 80242F88 E62A0098 */  swc1      $f10, 0x98($s1)
/* C63C9C 80242F8C 4600228D */  trunc.w.s $f10, $f4
/* C63CA0 80242F90 E62A009C */  swc1      $f10, 0x9c($s1)
/* C63CA4 80242F94 4600028D */  trunc.w.s $f10, $f0
/* C63CA8 80242F98 1440002E */  bnez      $v0, .L80243054
/* C63CAC 80242F9C E62A00A0 */   swc1     $f10, 0xa0($s1)
/* C63CB0 80242FA0 0C00EAD2 */  jal       get_npc_safe
/* C63CB4 80242FA4 2404FFFC */   addiu    $a0, $zero, -4
/* C63CB8 80242FA8 8E23008C */  lw        $v1, 0x8c($s1)
/* C63CBC 80242FAC 8E240098 */  lw        $a0, 0x98($s1)
/* C63CC0 80242FB0 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* C63CC4 80242FB4 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* C63CC8 80242FB8 00641821 */  addu      $v1, $v1, $a0
/* C63CCC 80242FBC 44830000 */  mtc1      $v1, $f0
/* C63CD0 80242FC0 00000000 */  nop
/* C63CD4 80242FC4 46800020 */  cvt.s.w   $f0, $f0
/* C63CD8 80242FC8 E6000028 */  swc1      $f0, 0x28($s0)
/* C63CDC 80242FCC 8E230090 */  lw        $v1, 0x90($s1)
/* C63CE0 80242FD0 8E24009C */  lw        $a0, 0x9c($s1)
/* C63CE4 80242FD4 00641821 */  addu      $v1, $v1, $a0
/* C63CE8 80242FD8 44830000 */  mtc1      $v1, $f0
/* C63CEC 80242FDC 00000000 */  nop
/* C63CF0 80242FE0 46800020 */  cvt.s.w   $f0, $f0
/* C63CF4 80242FE4 E600002C */  swc1      $f0, 0x2c($s0)
/* C63CF8 80242FE8 8E230094 */  lw        $v1, 0x94($s1)
/* C63CFC 80242FEC 8E2400A0 */  lw        $a0, 0xa0($s1)
/* C63D00 80242FF0 00641821 */  addu      $v1, $v1, $a0
/* C63D04 80242FF4 44830000 */  mtc1      $v1, $f0
/* C63D08 80242FF8 00000000 */  nop
/* C63D0C 80242FFC 46800020 */  cvt.s.w   $f0, $f0
/* C63D10 80243000 E6000030 */  swc1      $f0, 0x30($s0)
/* C63D14 80243004 C64C0000 */  lwc1      $f12, ($s2)
/* C63D18 80243008 C64E0008 */  lwc1      $f14, 8($s2)
/* C63D1C 8024300C 8E46000C */  lw        $a2, 0xc($s2)
/* C63D20 80243010 8E470014 */  lw        $a3, 0x14($s2)
/* C63D24 80243014 0C00A720 */  jal       atan2
/* C63D28 80243018 0040882D */   daddu    $s1, $v0, $zero
/* C63D2C 8024301C C6020028 */  lwc1      $f2, 0x28($s0)
/* C63D30 80243020 E6000080 */  swc1      $f0, 0x80($s0)
/* C63D34 80243024 E6220038 */  swc1      $f2, 0x38($s1)
/* C63D38 80243028 C600002C */  lwc1      $f0, 0x2c($s0)
/* C63D3C 8024302C 3C014120 */  lui       $at, 0x4120
/* C63D40 80243030 44811000 */  mtc1      $at, $f2
/* C63D44 80243034 00000000 */  nop
/* C63D48 80243038 46020001 */  sub.s     $f0, $f0, $f2
/* C63D4C 8024303C 3C0140A0 */  lui       $at, 0x40a0
/* C63D50 80243040 44811000 */  mtc1      $at, $f2
/* C63D54 80243044 E620003C */  swc1      $f0, 0x3c($s1)
/* C63D58 80243048 C6000030 */  lwc1      $f0, 0x30($s0)
/* C63D5C 8024304C 46020001 */  sub.s     $f0, $f0, $f2
/* C63D60 80243050 E6200040 */  swc1      $f0, 0x40($s1)
.L80243054:
/* C63D64 80243054 8FBF001C */  lw        $ra, 0x1c($sp)
/* C63D68 80243058 8FB20018 */  lw        $s2, 0x18($sp)
/* C63D6C 8024305C 8FB10014 */  lw        $s1, 0x14($sp)
/* C63D70 80243060 8FB00010 */  lw        $s0, 0x10($sp)
/* C63D74 80243064 24020002 */  addiu     $v0, $zero, 2
/* C63D78 80243068 03E00008 */  jr        $ra
/* C63D7C 8024306C 27BD0020 */   addiu    $sp, $sp, 0x20
