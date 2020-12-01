.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BEC_7ED8FC
/* 7ED8FC 80242BEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7ED900 80242BF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 7ED904 80242BF4 0080882D */  daddu     $s1, $a0, $zero
/* 7ED908 80242BF8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7ED90C 80242BFC AFB20018 */  sw        $s2, 0x18($sp)
/* 7ED910 80242C00 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ED914 80242C04 8E300148 */  lw        $s0, 0x148($s1)
/* 7ED918 80242C08 86040008 */  lh        $a0, 8($s0)
/* 7ED91C 80242C0C 0C00EABB */  jal       get_npc_unsafe
/* 7ED920 80242C10 00A0902D */   daddu    $s2, $a1, $zero
/* 7ED924 80242C14 8E230078 */  lw        $v1, 0x78($s1)
/* 7ED928 80242C18 24630001 */  addiu     $v1, $v1, 1
/* 7ED92C 80242C1C AE230078 */  sw        $v1, 0x78($s1)
/* 7ED930 80242C20 8E0400D0 */  lw        $a0, 0xd0($s0)
/* 7ED934 80242C24 8C840000 */  lw        $a0, ($a0)
/* 7ED938 80242C28 0064182A */  slt       $v1, $v1, $a0
/* 7ED93C 80242C2C 14600002 */  bnez      $v1, .L80242C38
/* 7ED940 80242C30 0040282D */   daddu    $a1, $v0, $zero
/* 7ED944 80242C34 AE200078 */  sw        $zero, 0x78($s1)
.L80242C38:
/* 7ED948 80242C38 8E0200CC */  lw        $v0, 0xcc($s0)
/* 7ED94C 80242C3C 8C420004 */  lw        $v0, 4($v0)
/* 7ED950 80242C40 ACA20028 */  sw        $v0, 0x28($a1)
/* 7ED954 80242C44 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 7ED958 80242C48 8C42007C */  lw        $v0, 0x7c($v0)
/* 7ED95C 80242C4C 04410004 */  bgez      $v0, .L80242C60
/* 7ED960 80242C50 00000000 */   nop      
/* 7ED964 80242C54 C6400000 */  lwc1      $f0, ($s2)
/* 7ED968 80242C58 08090B20 */  j         .L80242C80
/* 7ED96C 80242C5C E4A00018 */   swc1     $f0, 0x18($a1)
.L80242C60:
/* 7ED970 80242C60 3C018025 */  lui       $at, %hi(D_802559C8)
/* 7ED974 80242C64 D42259C8 */  ldc1      $f2, %lo(D_802559C8)($at)
/* 7ED978 80242C68 44820000 */  mtc1      $v0, $f0
/* 7ED97C 80242C6C 00000000 */  nop       
/* 7ED980 80242C70 46800021 */  cvt.d.w   $f0, $f0
/* 7ED984 80242C74 46220003 */  div.d     $f0, $f0, $f2
/* 7ED988 80242C78 46200020 */  cvt.s.d   $f0, $f0
/* 7ED98C 80242C7C E4A00018 */  swc1      $f0, 0x18($a1)
.L80242C80:
/* 7ED990 80242C80 24020001 */  addiu     $v0, $zero, 1
/* 7ED994 80242C84 AE220070 */  sw        $v0, 0x70($s1)
/* 7ED998 80242C88 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7ED99C 80242C8C 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ED9A0 80242C90 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ED9A4 80242C94 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ED9A8 80242C98 03E00008 */  jr        $ra
/* 7ED9AC 80242C9C 27BD0020 */   addiu    $sp, $sp, 0x20
