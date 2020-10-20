.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E88
/* C77B68 80240E88 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C77B6C 80240E8C AFB10014 */  sw        $s1, 0x14($sp)
/* C77B70 80240E90 0080882D */  daddu     $s1, $a0, $zero
/* C77B74 80240E94 AFBF001C */  sw        $ra, 0x1c($sp)
/* C77B78 80240E98 AFB20018 */  sw        $s2, 0x18($sp)
/* C77B7C 80240E9C AFB00010 */  sw        $s0, 0x10($sp)
/* C77B80 80240EA0 8E22000C */  lw        $v0, 0xc($s1)
/* C77B84 80240EA4 0C0B1EAF */  jal       get_variable
/* C77B88 80240EA8 8C450000 */   lw       $a1, ($v0)
/* C77B8C 80240EAC 8E23013C */  lw        $v1, 0x13c($s1)
/* C77B90 80240EB0 8C720000 */  lw        $s2, ($v1)
/* C77B94 80240EB4 C646000C */  lwc1      $f6, 0xc($s2)
/* C77B98 80240EB8 C6400000 */  lwc1      $f0, ($s2)
/* C77B9C 80240EBC 46003181 */  sub.s     $f6, $f6, $f0
/* C77BA0 80240EC0 3C01447A */  lui       $at, 0x447a
/* C77BA4 80240EC4 44814000 */  mtc1      $at, $f8
/* C77BA8 80240EC8 C6200084 */  lwc1      $f0, 0x84($s1)
/* C77BAC 80240ECC 46800020 */  cvt.s.w   $f0, $f0
/* C77BB0 80240ED0 46083183 */  div.s     $f6, $f6, $f8
/* C77BB4 80240ED4 46003182 */  mul.s     $f6, $f6, $f0
/* C77BB8 80240ED8 00000000 */  nop       
/* C77BBC 80240EDC C6440010 */  lwc1      $f4, 0x10($s2)
/* C77BC0 80240EE0 C6420004 */  lwc1      $f2, 4($s2)
/* C77BC4 80240EE4 46022101 */  sub.s     $f4, $f4, $f2
/* C77BC8 80240EE8 C6420008 */  lwc1      $f2, 8($s2)
/* C77BCC 80240EEC C6400014 */  lwc1      $f0, 0x14($s2)
/* C77BD0 80240EF0 46020001 */  sub.s     $f0, $f0, $f2
/* C77BD4 80240EF4 46082103 */  div.s     $f4, $f4, $f8
/* C77BD8 80240EF8 C6220084 */  lwc1      $f2, 0x84($s1)
/* C77BDC 80240EFC 468010A0 */  cvt.s.w   $f2, $f2
/* C77BE0 80240F00 46022102 */  mul.s     $f4, $f4, $f2
/* C77BE4 80240F04 00000000 */  nop       
/* C77BE8 80240F08 46080003 */  div.s     $f0, $f0, $f8
/* C77BEC 80240F0C 46020002 */  mul.s     $f0, $f0, $f2
/* C77BF0 80240F10 00000000 */  nop       
/* C77BF4 80240F14 4600328D */  trunc.w.s $f10, $f6
/* C77BF8 80240F18 E62A0098 */  swc1      $f10, 0x98($s1)
/* C77BFC 80240F1C 4600228D */  trunc.w.s $f10, $f4
/* C77C00 80240F20 E62A009C */  swc1      $f10, 0x9c($s1)
/* C77C04 80240F24 4600028D */  trunc.w.s $f10, $f0
/* C77C08 80240F28 1440002E */  bnez      $v0, .L80240FE4
/* C77C0C 80240F2C E62A00A0 */   swc1     $f10, 0xa0($s1)
/* C77C10 80240F30 0C00EAD2 */  jal       get_npc_safe
/* C77C14 80240F34 2404FFFC */   addiu    $a0, $zero, -4
/* C77C18 80240F38 8E23008C */  lw        $v1, 0x8c($s1)
/* C77C1C 80240F3C 8E240098 */  lw        $a0, 0x98($s1)
/* C77C20 80240F40 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* C77C24 80240F44 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* C77C28 80240F48 00641821 */  addu      $v1, $v1, $a0
/* C77C2C 80240F4C 44830000 */  mtc1      $v1, $f0
/* C77C30 80240F50 00000000 */  nop       
/* C77C34 80240F54 46800020 */  cvt.s.w   $f0, $f0
/* C77C38 80240F58 E6000028 */  swc1      $f0, 0x28($s0)
/* C77C3C 80240F5C 8E230090 */  lw        $v1, 0x90($s1)
/* C77C40 80240F60 8E24009C */  lw        $a0, 0x9c($s1)
/* C77C44 80240F64 00641821 */  addu      $v1, $v1, $a0
/* C77C48 80240F68 44830000 */  mtc1      $v1, $f0
/* C77C4C 80240F6C 00000000 */  nop       
/* C77C50 80240F70 46800020 */  cvt.s.w   $f0, $f0
/* C77C54 80240F74 E600002C */  swc1      $f0, 0x2c($s0)
/* C77C58 80240F78 8E230094 */  lw        $v1, 0x94($s1)
/* C77C5C 80240F7C 8E2400A0 */  lw        $a0, 0xa0($s1)
/* C77C60 80240F80 00641821 */  addu      $v1, $v1, $a0
/* C77C64 80240F84 44830000 */  mtc1      $v1, $f0
/* C77C68 80240F88 00000000 */  nop       
/* C77C6C 80240F8C 46800020 */  cvt.s.w   $f0, $f0
/* C77C70 80240F90 E6000030 */  swc1      $f0, 0x30($s0)
/* C77C74 80240F94 C64C0000 */  lwc1      $f12, ($s2)
/* C77C78 80240F98 C64E0008 */  lwc1      $f14, 8($s2)
/* C77C7C 80240F9C 8E46000C */  lw        $a2, 0xc($s2)
/* C77C80 80240FA0 8E470014 */  lw        $a3, 0x14($s2)
/* C77C84 80240FA4 0C00A720 */  jal       atan2
/* C77C88 80240FA8 0040882D */   daddu    $s1, $v0, $zero
/* C77C8C 80240FAC C6020028 */  lwc1      $f2, 0x28($s0)
/* C77C90 80240FB0 E6000080 */  swc1      $f0, 0x80($s0)
/* C77C94 80240FB4 E6220038 */  swc1      $f2, 0x38($s1)
/* C77C98 80240FB8 C600002C */  lwc1      $f0, 0x2c($s0)
/* C77C9C 80240FBC 3C014120 */  lui       $at, 0x4120
/* C77CA0 80240FC0 44811000 */  mtc1      $at, $f2
/* C77CA4 80240FC4 00000000 */  nop       
/* C77CA8 80240FC8 46020001 */  sub.s     $f0, $f0, $f2
/* C77CAC 80240FCC 3C0140A0 */  lui       $at, 0x40a0
/* C77CB0 80240FD0 44811000 */  mtc1      $at, $f2
/* C77CB4 80240FD4 E620003C */  swc1      $f0, 0x3c($s1)
/* C77CB8 80240FD8 C6000030 */  lwc1      $f0, 0x30($s0)
/* C77CBC 80240FDC 46020001 */  sub.s     $f0, $f0, $f2
/* C77CC0 80240FE0 E6200040 */  swc1      $f0, 0x40($s1)
.L80240FE4:
/* C77CC4 80240FE4 8FBF001C */  lw        $ra, 0x1c($sp)
/* C77CC8 80240FE8 8FB20018 */  lw        $s2, 0x18($sp)
/* C77CCC 80240FEC 8FB10014 */  lw        $s1, 0x14($sp)
/* C77CD0 80240FF0 8FB00010 */  lw        $s0, 0x10($sp)
/* C77CD4 80240FF4 24020002 */  addiu     $v0, $zero, 2
/* C77CD8 80240FF8 03E00008 */  jr        $ra
/* C77CDC 80240FFC 27BD0020 */   addiu    $sp, $sp, 0x20
