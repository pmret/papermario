.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BE8_DBDE98
/* DBDE98 80240BE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DBDE9C 80240BEC AFB10014 */  sw        $s1, 0x14($sp)
/* DBDEA0 80240BF0 0080882D */  daddu     $s1, $a0, $zero
/* DBDEA4 80240BF4 AFBF001C */  sw        $ra, 0x1c($sp)
/* DBDEA8 80240BF8 AFB20018 */  sw        $s2, 0x18($sp)
/* DBDEAC 80240BFC AFB00010 */  sw        $s0, 0x10($sp)
/* DBDEB0 80240C00 8E300148 */  lw        $s0, 0x148($s1)
/* DBDEB4 80240C04 86040008 */  lh        $a0, 8($s0)
/* DBDEB8 80240C08 0C00EABB */  jal       get_npc_unsafe
/* DBDEBC 80240C0C 00A0902D */   daddu    $s2, $a1, $zero
/* DBDEC0 80240C10 8E230078 */  lw        $v1, 0x78($s1)
/* DBDEC4 80240C14 24630001 */  addiu     $v1, $v1, 1
/* DBDEC8 80240C18 AE230078 */  sw        $v1, 0x78($s1)
/* DBDECC 80240C1C 8E0400D0 */  lw        $a0, 0xd0($s0)
/* DBDED0 80240C20 8C840000 */  lw        $a0, ($a0)
/* DBDED4 80240C24 0064182A */  slt       $v1, $v1, $a0
/* DBDED8 80240C28 14600002 */  bnez      $v1, .L80240C34
/* DBDEDC 80240C2C 0040282D */   daddu    $a1, $v0, $zero
/* DBDEE0 80240C30 AE200078 */  sw        $zero, 0x78($s1)
.L80240C34:
/* DBDEE4 80240C34 8E0200CC */  lw        $v0, 0xcc($s0)
/* DBDEE8 80240C38 8C420004 */  lw        $v0, 4($v0)
/* DBDEEC 80240C3C ACA20028 */  sw        $v0, 0x28($a1)
/* DBDEF0 80240C40 8E0200D0 */  lw        $v0, 0xd0($s0)
/* DBDEF4 80240C44 8C42007C */  lw        $v0, 0x7c($v0)
/* DBDEF8 80240C48 04410004 */  bgez      $v0, .L80240C5C
/* DBDEFC 80240C4C 00000000 */   nop
/* DBDF00 80240C50 C6400000 */  lwc1      $f0, ($s2)
/* DBDF04 80240C54 0809031F */  j         .L80240C7C
/* DBDF08 80240C58 E4A00018 */   swc1     $f0, 0x18($a1)
.L80240C5C:
/* DBDF0C 80240C5C 3C018024 */  lui       $at, %hi(D_80246D78_DC4028)
/* DBDF10 80240C60 D4226D78 */  ldc1      $f2, %lo(D_80246D78_DC4028)($at)
/* DBDF14 80240C64 44820000 */  mtc1      $v0, $f0
/* DBDF18 80240C68 00000000 */  nop
/* DBDF1C 80240C6C 46800021 */  cvt.d.w   $f0, $f0
/* DBDF20 80240C70 46220003 */  div.d     $f0, $f0, $f2
/* DBDF24 80240C74 46200020 */  cvt.s.d   $f0, $f0
/* DBDF28 80240C78 E4A00018 */  swc1      $f0, 0x18($a1)
.L80240C7C:
/* DBDF2C 80240C7C 24020001 */  addiu     $v0, $zero, 1
/* DBDF30 80240C80 AE220070 */  sw        $v0, 0x70($s1)
/* DBDF34 80240C84 8FBF001C */  lw        $ra, 0x1c($sp)
/* DBDF38 80240C88 8FB20018 */  lw        $s2, 0x18($sp)
/* DBDF3C 80240C8C 8FB10014 */  lw        $s1, 0x14($sp)
/* DBDF40 80240C90 8FB00010 */  lw        $s0, 0x10($sp)
/* DBDF44 80240C94 03E00008 */  jr        $ra
/* DBDF48 80240C98 27BD0020 */   addiu    $sp, $sp, 0x20
